#pragma once
#ifndef NifNodeTreeData_IncludeGuard
#define NifNodeTreeData_IncludeGuard
//#include "LooseNodeTreeTemplate.h"
#include "NifTreeObjectRegistry.h"
#include "..\..\SharedCode\DLLAPI.h"
#include "..\..\SharedCode\SharedCode_VariableLists\VariableList.h"
#include "..\..\SharedCode\SharedCode_VariableLists\StringVectorList.h"
#include "..\..\SharedCode\SharedCode_NodeTrees\LooseNodeTreeTemplate.h"
#include "..\niflib\include\niflib.h"
#include "..\..\SharedCode\SharedCode_VariableConversionFunctions\VariableConversionFunctions.h"
#include "..\niflib\include\obj\NiAVObject.h"
#include "..\niflib\include\obj\NiObject.h"
#include "..\niflib\include\gen\Header.h"
#include "..\niflib\include\gen\Footer.h"
#include <limits>
#include <stdint.h>
#include <string>

class NifNodeTreeData;

//Separate Structure to ensure can have Multiple NifNodeTrees without needed to calculate for each one

struct DLL_API NodeTreeGlobals
{
public:
	//static const size_t SizeTMaxValueCalculation()
	//{
	//	size_t TempValue = sizeof(size_t);
	//	switch(TempValue)
	//	{
	//		case 4:
	//			TempValue = 4294967295;
	//			break;
	//		case 8:
	//			TempValue = 18446744073709551615;
	//			break;
	//		default://Shouldn't use this, but will calculate anyway. (Max size in bits = 256^Bytes-1)
	//			TempValue = pow(256, TempValue) - 1;
	//			break;
	//	}
	//	return TempValue;
	//}
	// InternalBlock number as max size(refers to no internal_block_number set)
#ifdef SUPPORTS_CONSTEXPR
	static constexpr size_t ValueNotSet()
	{
		//return (sizeof(size_t) == 8) ? 18446744073709551615 : 4294967295;
		return std::numeric_limits<size_t>::max;
	}
#else
	static size_t ValueNotSet()
	{
		return (size_t) std::numeric_limits<size_t>::max();
	}
#endif
};

class DLL_API NifNodeTreeData
{
private:
	class NifNode;
	class NifNodeTree;
	struct NodeTypeDestructionData
	{
		size_t NodeTypeIndex;// = TargetNode->IndexInRegistry;
		std::string NodeType;// = TargetNode->NodeType;
		size_t NumberOfNodes = 1;
		void UpdateDestructionData(size_t Index)
		{
			if(Index < NodeTypeIndex)
			{
				NodeTypeIndex = Index;
			}
			++NumberOfNodes;
		}
		NodeTypeDestructionData(std::string NodeTypeTemp, size_t Index)
		{
			NodeType = NodeTypeTemp;
			NodeTypeIndex = Index;
		}
		NodeTypeDestructionData() {}
		~NodeTypeDestructionData() = default;
	};
	struct NodeTypeDestructionDataList : public VariableList<NodeTypeDestructionData>
	{
		void UpdateDestructionData(NifNode* TargetNode)
		{
			std::string NodeType = TargetNode->NodeType;
			const size_t NodeIndex = TargetNode->IndexInRegistry;
			const size_t SizeTemp = Size();
			bool MatchingTypeData = false;
			NodeTypeDestructionData* ElementData;
			for(size_t Index = 0; Index < SizeTemp&&!MatchingTypeData; ++Index)
			{
				ElementData = GetElementPointerV2(Index);
				if(ElementData->NodeType == NodeType)
				{
					ElementData->UpdateDestructionData(NodeIndex);
					MatchingTypeData = true;
				}
			}
			if(!MatchingTypeData)
			{
				NodeTypeDestructionData NewData(NodeType, NodeIndex);
				Add(NewData);
			}
		}
	};
	static Niflib::NiObjectRef FindRoot_NodeTree(vector<Niflib::NiObjectRef> const & objects);
	static inline std::string ConvertPointerToStringAddress(Niflib::NiObjectRef obj)
	{//Based on combination of http://www.cplusplus.com/forum/beginner/114557/ and http://www.cplusplus.com/forum/general/8597/
		std::stringstream ss;
		ss << static_cast<const void*>(obj);
		return ss.str();
	}
	static inline std::string ConvertPointerToStringAddress_NiObjectRef(Niflib::Ref<Niflib::NiObject> obj)
	{//Based on combination of http://www.cplusplus.com/forum/beginner/114557/ and http://www.cplusplus.com/forum/general/8597/
		std::stringstream ss;
		ss << static_cast<const void*>(obj);
		return ss.str();
	}
public:
	//Basic NifNode Variables/Functions (Use as part of base of NifTreeObjectRegistryNodes combined with Node classes in Niflib)
	//Actual full Node Data is Stored in Object Registry VariableLists
	class NifNode : public LooseNodeTreeTemplate::Node
	{
	public:
		//0 : Not ExtraData Node
		//1 : Unspecified ExtraData Node(not connected on main NodeTree as child etc but connected to a node or more)
		unsigned __int8 IsExtraDataNode = 0;
		//Used mainly just during NifImport time (NodeTreeGlobals::ValueNotSet = blocknumber not set)
		size_t internal_block_number = NodeTreeGlobals::ValueNotSet();
		//NodeType of Actual Node stored inside Object Registry
		std::string NodeType = "";
		//Index of actual node inside VariableList with name NodeType (NodeTreeGlobals::ValueNotSet = value not set in most cases)
		size_t IndexInRegistry = NodeTreeGlobals::ValueNotSet();
		void ObtainAllChildNodeNamesForDestructionV2(NodeTypeDestructionDataList& DestructionData, NifNodeTree* NodeTreeTarget, StringVectorList& ListOfNodes)
		{
			const size_t ChildListSize = ChildInternalNames.Size();
			NifNode* TargetNode;
			std::string NodeName;
			DestructionData.UpdateDestructionData(this);
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				NodeName = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					ListOfNodes.Add(NodeName);
					TargetNode->ObtainAllChildNodeNamesForDestructionV2(DestructionData, NodeTreeTarget, ListOfNodes);
				}
			}
		}
		void DestroyNodeData(NifTreeObjectRegistry* TargetObjectRegistry);
		void ResetNode()
		{
			Reset();
			internal_block_number = NodeTreeGlobals::ValueNotSet();
			NodeType = "";
			IndexInRegistry = NodeTreeGlobals::ValueNotSet();
		}
	};
	class NifNodeTree : public LooseNodeTreeTemplate::NodeTree<NifNode>
	{
	private:
		using NiObjectList = list<Niflib::Ref<Niflib::NiObject> >;
	public:
		//NifNode Object Registry holding the actual node data
		NifTreeObjectRegistry TargetObjectRegistry;
		Niflib::NifInfo NifHeaderInfo;
		//Resets Data in NifNodeTree Etc
		void ResetData()
		{
			Reset();
			TargetObjectRegistry.Reset();
		}
		//************************************
		// Method:    ReturnPointerStringOfNodeInObjectRegistry
		// FullName:  NifNodeTreeData::NifNodeTree::ReturnPointerStringOfNodeInObjectRegistry
		// Access:    public
		// Returns:   std::string
		// Qualifier:
		// Parameter: NifNode * TargetNode
		//************************************
		std::string ReturnPointerStringOfNodeInObjectRegistry(NifNode* TargetNode);
		//************************************
		// Method:    AddNodeToTree
		// FullName:  LooseNodeTreeTemplate::NodeTree<NifNodeTreeData::NifNode>::AddNodeToTree
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string ObjectType
		// Parameter: std::string TargetMenuMaster
		// Parameter: std::string SpecialModifier
		// Parameter: std::string ItemName
		// Parameter: std::string InternalName
		//************************************
		void AddNodeToTree(std::string ObjectType, std::string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "");
		//************************************
		// Method:    CopyNodeToTree
		// FullName:  NifNodeTreeData::NifNodeTree::CopyNodeToTree
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: Niflib::NiObjectRef TargetNode
		// Parameter: std::string TargetMenuMaster
		// Parameter: std::string SpecialModifier
		// Parameter: std::string ItemName
		// Parameter: std::string InternalName
		//************************************
		void CopyNodeToTree(Niflib::NiObjectRef TargetNodeData, NifNode TargetNode);
		//************************************
		// (Unfinished Placeholder method)
		// Method:    CloneNodeByInternalNameAsOtherType
		// FullName:  NifNodeTreeData::NifNodeTree::CloneNodeByInternalNameAsOtherType
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string ObjectType
		// Parameter: std::string TargetNodeName
		//************************************
		void CloneNodeByInternalNameAsOtherType(std::string ObjectType, std::string TargetNodeName)
		{}
		//************************************
		// Method:    DestroyTargetNodeAndAllItsChildrenV2
		// FullName:  NifNodeTreeData::NifNodeTree::DestroyTargetNodeAndAllItsChildrenV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: NifNode * TargetNode
		//************************************
		void DestroyTargetNodeAndAllItsChildrenV2(NifNode* TargetNode);
		//************************************
		// Method:    DestroyNodeAndAllItsChildrenV2
		// FullName:  NifNodeTreeData::NifNodeTree::DestroyNodeAndAllItsChildrenV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string TargetNodeInternalName
		//************************************
		void DestroyNodeAndAllItsChildrenV2(std::string TargetNodeInternalName)
		{
			CurrentNodeIndexUsed = false;
			NifNode* TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);
			if(TargetNode == nullptr)
			{
				std::cout << "Target Node with internal name " << TargetNodeInternalName << " does not exist.\n";
			}
			else
			{
				DestroyTargetNodeAndAllItsChildrenV2(TargetNode);
			}
		}
		//************************************
		// Returns false if either current index is max int64 value(highly unlikely) or undetected ObjectType detected
		// Method:    CreateObject
		// FullName:  NifNodeTreeData::NifNodeTree::CreateObject
		// Access:    public
		// Returns:   bool
		// Qualifier:
		// Parameter: const std::string ObjectType
		//************************************
		bool CreateObject(const std::string ObjectType);
		//Running Read command on last loaded Node
		void ReadObjectFromStream(std::string ObjectType, istream& in, list<unsigned int> & link_stack, const Niflib::NifInfo & info);

		//Niflib::NiObjectRef ReadNifNodeTree(istream & in, Niflib::NifInfo * info = NULL)
		//{
		//	//Read object list
		//	vector<Niflib::NiObjectRef> objects = Niflib::ReadNifList(in, info);
		//	return FindRoot_NodeTree(objects);
		//}
		void ReadNifNodeTree(istream & in, NiObjectList & missing_link_stack, Niflib::NifInfo * info = NULL);
		//Temporary Method for Importing NifFile(Called from ReadNifNodeTree)
		void ReadNifNodeTree(istream & in, Niflib::NifInfo * info);
		void ReadNifNodeTree(string const & file_name, Niflib::NifInfo * info = NULL);
		void ImportNifFile(string const & FileName)
		{
			using namespace Niflib;
			NifInfo Info;
			ReadNifNodeTree(FileName, &Info);
		}
		//************************************
		// Method:    ReadNifNodeTree
		// FullName:  NifNodeTreeData::NifNodeTree::ReadNifNodeTree
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: string const & FileName
		//************************************
		void inline ReadNifNodeTree(string const & FileName)
		{//Need to create non-address based version of Niflib::ReadNifTree
			ImportNifFile(FileName);
		}
		NifNodeTree(string const & FileName)
		{
			ImportNifFile(FileName);
		}
		template <typename DataType>
		std::string GetInternalNameOfNodeData(*DataType DataNode, std::string NodeType = "");
		NifNodeTree() {}
		~NifNodeTree() {}
		/* List of Functions that don't need New Versions(Don't need to edit any NifTreeObjectRegistry Indexes,Although might need to code check later):
		MoveNode(std::string TargetNodeInternalName, std::string TargetNodeMoveLocationInternalName)//Actual NodeData doesn't move when node Moves in NodeTree
		*/
	};
};

#endif