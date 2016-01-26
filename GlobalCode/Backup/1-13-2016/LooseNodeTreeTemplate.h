#pragma once

#include "VariableList.h"
#include "VariableTypeLists.h"
#include "TagPosition.h"
#include "QuadVector.h"
#include "StringVectorList.h"

class LooseNodeTreeTemplate
{
private:
	class NodeTree;
	class Node;
public:
	//Equals <typename NodeType>
	class Node
	{
	public:
		//Node connected in 3d way to NodeTree(things like ExtraData);(Alters auto-naming sense used)
		bool IsLooseNode = false;
		StringVectorList ChildInternalNames;
		//AutoGenerate InternalName based on XMLPosition unless specified(InternalName must be unique;Required for pointer fixes)
		//Example: ParentIndexPositionString-ListPosition ("-0" for first Tag in menu)
		string InternalName = "";
		//InternalName of parent(fix for pointer invalidation);"(Core)"=Connected at base of NodeTree;"(LooseNodes)"=Connected to LooseNodes (not part of main 3d NodeTree)
		//Reserve "(InvalidPointer)" for non-existing Internal names of Pointers
		string ParentInternalName = "";
		TagPosition PositionInTree;
		//Name of Bone
		string NodeName = "";
		Node() {}
		~Node() {}
	};

	//NodeType = Node (Templated Node here)
	template <typename NodeType = Node>
	class NodeTree : public VariableList<NodeType>
	{
	public:
		//Current Saved XML Tag Edited/Added
		NodeType* CurrentNode = nullptr;
		//InternalName of CurrentNode(for fixing Pointer)
		std::string CurrentTagInternalName = "";
		//Used for Nodes not part of 3d Node Tree (for things such as extra data nodes in Niflib)
		StringVectorList BaseLooseNode;
		//Root internal Nodes
		StringVectorList RootInternalNodes;
		//************************************
		// Method:    AutoGenInternalNameFromNode
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::AutoGenInternalNameFromNode
		// Access:    public
		// Returns:   string
		// Qualifier:
		// Parameter: NodeType * TargetNode
		//************************************
		string AutoGenInternalNameFromNode(NodeType* TargetNode)
		{
			string NameTemp;
			TagPosition PositionTemp = TargetNode->PositionInTree;
			NameTemp = PositionTemp.PositionString();
			return NameTemp;
		}
		//************************************
		// Method:    CheckIfInternalNameUsed
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::CheckIfInternalNameUsed
		// Access:    public
		// Returns:   bool
		// Qualifier:
		// Parameter: std::string InternalName
		//************************************
		bool CheckIfInternalNameUsed(std::string InternalName)
		{
			bool NameUsed = false;
			const unsigned int SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			for(unsigned int Index; Index < SizeTemp&& NameUsed == false; ++Index)
			{
				NodePointer = this->GetElementPointerV2(Index);
				if(NodePointer->InternalName == InternalName)
				{
					NameUsed = true;
				}
			}
			return NameUsed;
		}
		//************************************
		// Method:    GenerateUnusedInternalName
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::GenerateUnusedInternalName
		// Access:    public
		// Returns:   string
		// Qualifier:
		// Parameter: std::string BaseInternalName
		//************************************
		string GenerateUnusedInternalName(std::string BaseInternalName)
		{
			const std::string BaseName = BaseInternalName;
			std::string NameTemp = BaseInternalName;
			for(unsigned int AttemptNumber = 1; CheckIfInternalNameUsed(NameTemp); ++AttemptNumber)
			{
				NameTemp = BaseName;
				NameTemp += "X";
				//Might need to program in larger int type to keep track of possible conflicts but should work for now
				NameTemp += StringFunctions::IntToStringConversion(AttemptNumber);
			}
			return NameTemp;
		}
		//************************************
		// Method:    AddNodeToRoot
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::AddNodeToRoot
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: std::string NodeName
		// Parameter: std::string InternalName
		//************************************
		void AddNodeToRoot(std::string NodeName = "", std::string InternalName = "")
		{
			unsigned int Index = Size();
			AddData();
			NodeType* ElementPointer = this->GetElementPointerV2(Index);
			ElementPointer->PositionInTree.ListPosition = Index;
			if(NodeName != "")
			{
				ElementPointer->NodeName = NodeName;
			};
			if(InternalName != "")
			{
				//Check if InternalName used
				if(CheckIfInternalNameUsed(InternalName) == false)
				{
					ElementPointer->InternalName = InternalName;
				}
				else
				{
					ElementPointer->InternalName = GenerateUnusedInternalName(InternalName);
				}
			}
			else
			{
				string NameTemp;
				TagPosition PositionTemp = ElementPointer->PositionInTree;
				NameTemp = PositionTemp.PositionString();
				//Check if InternalName used
				if(CheckIfInternalNameUsed(NameTemp) == false)
				{
					ElementPointer->InternalName = NameTemp;
				}
				else
				{
					ElementPointer->InternalName = GenerateUnusedInternalName(NameTemp);
				}
			}
			ElementPointer->ParentInternalName = "(Core)";
			RootInternalNodes.Add(ElementPointer->InternalName);
			CurrentTagInternalName = ElementPointer->InternalName;
		}
		void AddLooseNode(std::string NodeName = "", std::string InternalName = "")
		{
			//Write code for this later
		}
		//************************************
		// Alias for Reset
		// Method:    ResetData
		// FullName:  LooseNodeTreeTemplate::NodeTree::ResetData
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void ResetData()
		{
			Reset();
		}
		/*
		////************************************
		//// Alias to return Size() (Fix for Strange Error when Accessing from BHVData)
		//// Method:    GetSize
		//// FullName:  LooseNodeTreeTemplate::NodeTree::GetSize
		//// Access:    public
		//// Returns:   int
		//// Qualifier:
		////************************************
		//int GetSize()
		//{
		//	return Size();
		//}
		////************************************
		//// Alias for GetElementPointerV2(index) (Fix for Strange Error when Accessing from BHVData)
		//// Method:    GetPointerData
		//// FullName:  LooseNodeTreeTemplate::NodeTree::GetPointerData
		//// Access:    public
		//// Returns:   Node*
		//// Qualifier:
		//// Parameter: int index
		////************************************
		//NodeType* GetPointerData(int index)
		//{
		//	return GetElementPointerV2(index);
		//}
		*/
		//************************************
		// Method:    SetCurrentNode
		// FullName:  LooseNodeTreeTemplate::NodeTree::SetCurrentNode
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: Node * PointerTemp
		//************************************
		void SetCurrentNode(NodeType* PointerTemp)
		{
			CurrentNode = PointerTemp;
			CurrentTagInternalName = CurrentNode->InternalName;
		}
		//************************************
		// Finds Node with Associated InternalName(Fix for Pointer invalidation);Returns nullptr if not found
		// Method:    GetNodePointerFromInternalName
		// FullName:  LooseNodeTreeTemplate::NodeTree::GetNodePointerFromInternalName
		// Access:    public
		// Returns:   Node*
		// Qualifier:
		// Parameter: string InternalName
		//************************************
		NodeType* GetNodePointerFromInternalName(string InternalName)
		{
			const unsigned int SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			NodeType* TargetNodePointer = nullptr;
			for(unsigned int Index; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
			{
				NodePointer = this->GetElementPointerV2(Index);
				if(NodePointer->InternalName == InternalName)
				{
					TargetNodePointer = NodePointer;
				}
			}
			return TargetNodePointer;
		}
		//************************************
		// Method:    SetCurrentNodeByName
		// FullName:  LooseNodeTreeTemplate::NodeTree::SetCurrentNodeByName
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: string Name
		//************************************
		void SetCurrentNodeByName(string Name)
		{
			CurrentNode = GetNodePointerFromInternalName(Name);
			if(CurrentNode == nullptr)
			{
				CurrentTagInternalName = "";
			}
			else
			{
				CurrentTagInternalName = Name;
			}
		}
		//************************************
		// Corrects pointers for CurrentNodeList and CurrentNode if invalidated
		// Method:    FixCurrentNodeData
		// FullName:  LooseNodeTreeTemplate::NodeTree::FixCurrentNodeData
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void FixCurrentNodeData()
		{
			if(CurrentNode == nullptr&&CurrentTagInternalName != "")
			{
				CurrentTagInternalName = "";
			}
			else if(CurrentNode->InternalName != CurrentTagInternalName)
			{
				CurrentNode = GetNodePointerFromInternalName(CurrentTagInternalName);
				if(CurrentNode == nullptr)
				{
					CurrentTagInternalName = "";
				}
			}
		}
		//************************************
		// Corrects all pointers for Nodes within Tree
		// Method:    FixTreePointers
		// FullName:  LooseNodeTreeTemplate::NodeTree::FixTreePointers
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void FixTreePointers();
		{
			const unsigned int SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			std::string CurrentInternalName;
			for(unsigned int Index; Index < SizeTemp; ++Index)
			{
				NodePointer = this->GetElementPointerV2(Index);
				CurrentInternalName = NodePointer->ParentInternalName;
				//Check if Internal names are valid
				if(CurrentInternalName != "(Core)"&&CurrentInternalName != "(InvalidPointer)"&&CurrentInternalName != "(LooseNodes)" && (CheckIfInternalNameUsed(CurrentInternalName) == false))
				{
					NodePointer->ParentInternalName = "(InvalidPointer)";
				}

				//Fix/finish rest of this later
			}
			//	for(int NodeListIndex = 0; NodeListIndex < SizeTemp; NodeListIndex++)
			//	{
			//		NodeListPointer = this->GetElementPointerV2(NodeListIndex);
			//		NodeListSize = NodeListPointer->Size();
			//		if(NodeListPointer->ParentNodeInternalName != NodeListPointer->ParentNode->InternalName)
			//		{
			//			NodeListPointer->ParentNode = GetNodePointerFromInternalName(NodeListPointer->ParentNodeInternalName);
			//		}
			//		for(int NodeIndex = 0; NodeIndex < NodeListSize; NodeIndex++)
			//		{
			//			NodePointer = NodeListPointer->GetElementPointerV2(NodeIndex);

			//		}
			//	}
		}
		NodeType* FindFirstNodeWithMatchingNodeName(std::string TargetName)
		{
			const unsigned int SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			NodeType* TargetNodePointer = nullptr;
			std::string CurrentInternalName;
			for(unsigned int Index; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
			{
				NodePointer = this->GetElementPointerV2(Index);
				if(NodePointer->NodeName==TargetName)
				{
					TargetNodePointer = NodePointer;
				}
			}
			return TargetNodePointer;
		}
		void AddSubItem(NodeType* TargetNode, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			//Adding SubItem to parent node of current node
			AddData();
			FixCurrentNodeData();
			NodeType* NextNode = this->GetElementPointerV2(Index);
			TagPosition PositionTemp = CurrentNode->PositionInTree;
			PositionTemp.IncreaseListPos();
			NextNode->PositionInTree = PositionTemp;
			if(ItemName != "")
			{
				NextNode->NodeName = NodeName;
			}
			if(InternalName != "")
			{
				//Check if InternalName used
				if(CheckIfInternalNameUsed(InternalName) == false)
				{
					NextNode->InternalName = InternalName;
				}
				else
				{
					NextNode->InternalName = GenerateUnusedInternalName(InternalName);
				}
			}
			else
			{
				string NameTemp;
				NameTemp = PositionTemp.PositionString();
				//Check if InternalName used
				if(CheckIfInternalNameUsed(NameTemp) == false)
				{
					NextNode->InternalName = NameTemp;
				}
				else
				{
					NextNode->InternalName = GenerateUnusedInternalName(NameTemp);
				}
			}
			NextNode->ParentInternalName = NodeTargetString;
			TargetNode->ChildInternalNames.Add(NextNode->InternalName);
		}
		void AddLastItem(std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			if(CurrentTagInternalName == "")
			{
				std::cout << "No current node selected. Adding item data to root instead.\n";
				AddNodeToRoot(ItemName, InternalName);
			}
			else
			{
				if(SpecialModifier == "AddSubItem")
				{
					AddSubItem(CurrentNode, SpecialModifier, ItemName, InternalName);
				}
				else
				{
					std::string NodeTargetString = CurrentNode->ParentInternalName;
					if(NodeTargetString == "(Core)")
					{
						AddNodeToRoot(ItemName, InternalName);
					}
					else
					{
						unsigned int Index = Size();
						NodeType* TargetNode = GetNodePointerFromInternalName(CurrentNode->ParentInternalName);
						if(TargetNode == nullptr)
						{
							std::cout << "Invalid parent node found.\nNo Node added.\n"
						}
						else
						{
							AddSubItem(TargetNode, SpecialModifier, ItemName, InternalName);
						}
					}
				}
			}
		}
		//************************************
		//Adds Node to NodeTree; NodeTree Values commands:
		//TargetMenuMaster=="(LastItem)",SpecialModifier == "AddSubItem" = Adds Node within last Node Added to Tree
		//TargetMenuMaster=="(LastItem)" = Adds Node to Current NodeList
		//TargetMenuMaster== "(Core)" = Adds Node to Core NodeList
		//TargetMenuMaster=="(LooseNode)" = Add LooseNode to NodeTree
		//TargetMenuMaster != "", SpecialModifier == "AddSubItem" = Adds Node within node with internal name of TargetMenuMaster
		//TargetMenuMaster != "" = Add item within parent node of tag with internal name of TargetMenuMaster
		//TargetMenuMaster != "", SpecialModifier == "MatchNodeName_AddSubItem" = Adds Node within node with matching NodeName of TargetMenuMaster
		//TargetMenuMaster != "", SpecialModifier == "MatchNodeName" = Add item within parent node of tag with matching NodeName of TargetMenuMaster
		// Method:    AddMenuItemData
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::AddMenuItemData
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: string TargetMenuMaster
		// Parameter: std::string SpecialModifier
		// Parameter: std::string ItemName
		// Parameter: std::string InternalName
		//************************************
		void AddMenuItemData(string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			unsigned int SizeTemp = Size();
			FixCurrentNodeData();
			//For this version directly fix pointers as needed
			if(TargetMenuMaster == "(LooseNode)")
			{
				//Create code for this later (when needed)
			}
			else if(TargetMenuMaster == "(Core)")
			{
				AddNodeToRoot(ItemName, InternalName);
			}
			else if(TargetMenuMaster == "(LastItem)")
			{
				AddLastItem(SpecialModifier, ItemName, InternalName);
			}
			else if(SpecialModifier == "MatchNodeName_AddSubItem")
			{
				CurrentNode = FindFirstNodeWithMatchingNodeName(TargetMenuMaster);
				SpecialModifier = "AddSubItem";
				SetCurrentNodeByName(TargetMenuMaster);
				if(CurrentTagInternalName == "")
				{
					std::cout << "Error:Node with NodeName of " << TargetMenuMaster << " not found.\nNo Node added.\n";
				}
				else
				{
					AddLastItem(SpecialModifier, ItemName, InternalName);
				}
			}
			else if(SpecialModifier=="MatchNodeName")
			{
				CurrentNode = FindFirstNodeWithMatchingNodeName(TargetMenuMaster);
				SpecialModifier = "";
				SetCurrentNodeByName(TargetMenuMaster);
				if(CurrentTagInternalName == "")
				{
					std::cout << "Error:Node with NodeName of " << TargetMenuMaster << " not found.\nNo Node added.\n";
				}
				else
				{
					AddLastItem(SpecialModifier, ItemName, InternalName);
				}
			}
			else if(TargetMenuMaster != "")
			{
				unsigned short TargetModifier = 0;
				if(SpecialModifier == "MatchNodeName")
				{
					CurrentNode = FindFirstNodeWithMatchingNodeName(TargetMenuMaster);
					SpecialModifier = "";
					TargetModifier = 1;
				}
				else if(SpecialModifier == "MatchNodeName_AddSubItem")
				{
					CurrentNode = FindFirstNodeWithMatchingNodeName(TargetMenuMaster);
					SpecialModifier = "AddSubItem";
					TargetModifier = 2;
				}
				if(TargetModifier==0)
				{
					SetCurrentNodeByName(TargetMenuMaster);
				}
				if(CurrentTagInternalName == "")
				{
					if(TargetModifier==2||TargetModifier==1)
					{
						std::cout << "Error:Node with NodeName of " << TargetMenuMaster << " not found.\nNo Node added.\n";
					}
					else
					{
						std::cout << "Error:Node with internalname of " << TargetMenuMaster << " not found.\nNo Node added.\n";
					}
				}
				else
				{
					AddLastItem(SpecialModifier, ItemName, InternalName);
				}
			}
			else
			{
				std::cout << "Error:No Target location set. Node not added.\n";
			}
		}
		//************************************
		// Method:    NodeTree
		// FullName:  LooseNodeTreeTemplate::NodeTree::NodeTree
		// Access:    public
		// Returns:
		// Qualifier:
		//************************************
		NodeTree() {}
		//************************************
		// Method:    ~NodeTree
		// FullName:  LooseNodeTreeTemplate::NodeTree::~NodeTree
		// Access:    public
		// Returns:
		// Qualifier:
		//************************************
		~NodeTree() {}
	};
	LooseNodeTreeTemplate() {}
	~LooseNodeTreeTemplate() {}
};