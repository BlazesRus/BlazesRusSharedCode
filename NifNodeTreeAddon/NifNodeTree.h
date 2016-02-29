#pragma once
#ifndef NifNodeTreeData_IncludeGuard
#define NifNodeTreeData_IncludeGuard
//#include "LooseNodeTreeTemplate.h"
#include "NifTreeObjectRegistry.h"
#include "..\..\GlobalCode\DLLAPI.h"
#include "..\..\GlobalCode\GlobalCode_VariableLists\VariableList.h"
#include "..\..\GlobalCode\GlobalCode_VariableLists\StringVectorList.h"
#include "..\..\GlobalCode\GlobalCode_NodeTrees\LooseNodeTreeTemplate.h"
#include "..\niflib\include\niflib.h"
#include "..\..\GlobalCode\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#include "..\niflib\include\obj\NiAVObject.h"
#include "..\niflib\include\obj\NiObject.h"
#include "..\niflib\include\gen\Header.h"
#include "..\niflib\include\gen\Footer.h"
//#include "gen\Header.h"

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
		/** Notes of Altered usage of derived member variables
		When importing NifFile: InternalName => StringAddress (string version of address of node), in order to help organize the NifNodeTree during import

		*/
	public:
		/*std::string asString(bool verbose=false) const
		{
		}*/
		//NodeType of Actual Node stored inside Object Registry
		std::string NodeType = "";
		//Index of actual node inside VariableList with name NodeType
		size_t IndexInRegistry;
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
	};
	class NifNodeTree : public LooseNodeTreeTemplate::NodeTree<NifNode>
	{
	private:
		using NiObjectList = list<Niflib::Ref<Niflib::NiObject> >;
	public:
		//NifNode Object Registry holding the actual node data
		NifTreeObjectRegistry TargetObjectRegistry;
		Niflib::NifInfo NifHeaderInfo;
		void ResetData()
		{
			Reset();
			TargetObjectRegistry.Reset();
		}
			//************************************
			// Method:    AddNodeToTree
			// FullName:  LooseNodeTreeTemplate::NodeTree<NifNodeTreeData::NifNode>::AddNodeToTree
			// Access:    public
			// Returns:   void
			// Qualifier:
			// Parameter: std::string TargetNodeType
			// Parameter: std::string TargetMenuMaster
			// Parameter: std::string SpecialModifier
			// Parameter: std::string ItemName
			// Parameter: std::string InternalName
			//************************************
		void AddNodeToTree(std::string TargetNodeType, std::string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "");
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
		void CopyNodeToTree(Niflib::NiObjectRef TargetNode, std::string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "");
		//************************************
		// (Unfinished Placeholder method)
		// Method:    CloneNodeByInternalNameAsOtherType
		// FullName:  NifNodeTreeData::NifNodeTree::CloneNodeByInternalNameAsOtherType
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string TargetNodeType
		// Parameter: std::string TargetNodeName
		//************************************
		void CloneNodeByInternalNameAsOtherType(std::string TargetNodeType, std::string TargetNodeName)
		{}
		//************************************
		// Method:    DestroyTargetNodeAndAllItsChildrenV2
		// FullName:  NifNodeTreeData::NifNodeTree::DestroyTargetNodeAndAllItsChildrenV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: NifNode * TargetNode
		//************************************
		void DestroyTargetNodeAndAllItsChildrenV2(NifNode* TargetNode)
		{
			//Need to refactor IndexInRegistry for all with index for all destroyed
			NodeTypeDestructionDataList DestructionData;
			DestructionData.UpdateDestructionData(TargetNode);
			std::string const TargetNodeInternalName = TargetNode->InternalName;
			StringVectorList InternalNamesOfNodesToDestroy;
			InternalNamesOfNodesToDestroy.Add(TargetNodeInternalName);
			//Remove node from child list of parent
			std::string ParentNodeName = TargetNode->ParentInternalName;
			if(ParentNodeName == "(Core)")
			{
				RootInternalNodes.RemoveElementWithMatchingValue(TargetNodeInternalName);
			}
			else if(ParentNodeName == "(LooseNodes)")
			{
				BaseLooseNode.RemoveElementWithMatchingValue(TargetNodeInternalName);
			}
			else
			{
				NifNode* ParentNode = GetNodePointerFromInternalName(ParentNodeName);
				if(ParentNode != nullptr)
				{
					ParentNode->ChildInternalNames.RemoveElementWithMatchingValue(TargetNodeInternalName);
				}
			}
			size_t SizeTemp;
			std::string TargetNameTemp;
			TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);
			//Search children and childrens children (and add internal Names to list)
			SizeTemp = TargetNode->ChildInternalNames.Size();
			//Copying Child list to prevent pointer messups from messing up child search
			StringVectorList ChildList = TargetNode->ChildInternalNames;
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = ChildList.ElementAt(Index);
				InternalNamesOfNodesToDestroy.Add(TargetNameTemp);
				//Now search childrens...children etc
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				//Need to auto-update reference of NodeTree class type in just to ensure it updates the NodeTree reference when derived (I'll try to see if auto-updates derived class type first)
				TargetNode->ObtainAllChildNodeNamesForDestructionV2(DestructionData, this, InternalNamesOfNodesToDestroy);//<std::typeid(NodeTree)>
			}
			//Now destroy all nodes in list set to destroy
			SizeTemp = InternalNamesOfNodesToDestroy.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = InternalNamesOfNodesToDestroy.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					//First Destroy Actual Node Data
					TargetNode->DestroyNodeData(&TargetObjectRegistry);
					//----------------------------------------------
					Remove(GetIndexOfInternalName(TargetNameTemp));
				}
			}
			//Now update Registry Based on DestructionData
			SizeTemp = DestructionData.Size();
			NodeTypeDestructionData ElementData;
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				ElementData = DestructionData.ElementAt(Index);
				for(size_t Index02 = 0; Index02 < Size(); ++Index02)
				{
					TargetNode = GetElementPointerV2(Index02);
					if(TargetNode->NodeType == ElementData.NodeType)
					{
						TargetNode->IndexInRegistry -= ElementData.NumberOfNodes;
					}
				}
			}
		}
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
			using NifListElement = Ref<NiObject>;
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
		NifNodeTree() {}
		~NifNodeTree() {}
		/* List of Functions that don't need New Versions(Don't need to edit any NifTreeObjectRegistry Indexes,Although might need to code check later):
		MoveNode(std::string TargetNodeInternalName, std::string TargetNodeMoveLocationInternalName)//Actual NodeData doesn't move when node Moves in NodeTree
		*/
	};
};

#endif