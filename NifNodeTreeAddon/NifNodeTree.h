#pragma once
#ifndef NifNodeTreeData_IncludeGuard
#define NifNodeTreeData_IncludeGuard
//#include "LooseNodeTreeTemplate.h"
#include "ObjectRegistryClasses.h"
#include "..\..\GlobalCode\DLLAPI.h"
#include "..\..\GlobalCode\GlobalCode_VariableLists\VariableList.h"
#include "..\..\GlobalCode\GlobalCode_VariableLists\StringVectorList.h"
#include "..\..\GlobalCode\GlobalCode_NodeTrees\LooseNodeTreeTemplate.h"
//#include "gen\Header.h"

class DLL_API NifNodeTreeData
{
private:
	class NifNodeTree;
	struct NodeTypeDestructionData;
	struct NodeTypeDestructionDataList;
public:
	//Basic NifNode Variables/Functions (Use as part of base of ObjectRegistryNodes combined with Node classes in Niflib)
	//Actual full Node Data is Stored in Object Registry VariableLists
	class NifNode : public LooseNodeTreeTemplate::Node
	{
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
					TargetNode->ObtainAllChildNodeNamesForDestructionV2(DestructionData,NodeTreeTarget, ListOfNodes);
				}
			}
		}
		void DestroyNodeData(ObjectRegistry* TargetObjectRegistry);
	};
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
	class NifNodeTree : public LooseNodeTreeTemplate::NodeTree<NifNode>
	{
	public:
		//NifNode Object Registry holding the actual node data
		ObjectRegistry TargetObjectRegistry;
		Niflib::NifInfo NifHeaderInfo;
		//************************************
		// Method:    FixCurrentNodeData
		// FullName:  LooseNodeTreeTemplate::NodeTree<NifNodeTreeData::NifNode>::FixCurrentNodeData
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
		void CloneNodeByInternalNameAsOtherType(std::string TargetNodeType, std::string TargetNodeName)
		{
		}
		void DestroyTargetNodeAndAllItsChildrenV2(NifNode* TargetNode)
		{
			//size_t const NodeTypeIndex = TargetNode->IndexInRegistry;
			//std::string const NodeType = TargetNode->NodeType;
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
				TargetNode->ObtainAllChildNodeNamesForDestructionV2(DestructionData,this, InternalNamesOfNodesToDestroy);//<std::typeid(NodeTree)>
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
					if(TargetNode->NodeType==ElementData.NodeType)
					{
						TargetNode->IndexInRegistry -= ElementData.NumberOfNodes;
					}
				}
			}
		}
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
		/* List of Functions that don't need New Versions(Don't need to edit any ObjectRegistry Indexes,Although might need to code check later):
		MoveNode(std::string TargetNodeInternalName, std::string TargetNodeMoveLocationInternalName)//Actual NodeData doesn't move when node Moves in NodeTree
		*/
		void ReadNifNodeTree(string const & FileName)
		{//Need to create non-address based version of 

		}
		NifNodeTree(string const & FileName)
		{
			ReadNifNodeTree(FileName);
		}
		NifNodeTree(){}
		~NifNodeTree() {}
	};
};
#endif