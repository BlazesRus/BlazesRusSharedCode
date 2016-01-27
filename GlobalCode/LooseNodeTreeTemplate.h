/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef LooseNodeTreeTemplate_IncludeGuard
#define LooseNodeTreeTemplate_IncludeGuard

#include "VariableList.h"
#include "VariableTypeLists.h"
#include "TagPosition.h"
#include "QuadVector.h"
#include "StringVectorList.h"
#include "StringFunctions.h"
//#include <typeinfo>//Might be needed if doesn't update dervived class Type name of NodeTree

//Contains LooseNodeTree BaseData for templating
namespace LooseNodeTreeTemplate
{
	//Equals <typename NodeType>
	class Node
	{
	public:
		//Node connected in 3d way to NodeTree(things like ExtraData);(Alters auto-naming sense used)
		bool IsLooseNode = false;
		StringVectorList ChildInternalNames;
		//AutoGenerate InternalName based on XMLPosition unless specified(InternalName must be unique;Required for pointer fixes)
		//Example: ParentIndexPositionString-ListPosition ("-0" for first Tag in menu)
		//Use GenerateUnusedInternalName(BaseInternalName) to ensure unique InternalName or Use AutoGenInternalNameFromNode() to generate based on TagPosition(might have conflicts if nodes removed but will auto-rename as needed) as long as doesn't reach over 18,446,744,073,709,551,615 attempts
		std::string InternalName = "";
		//InternalName of parent(fix for pointer invalidation);"(Core)"=Connected at base of NodeTree;"(LooseNodes)"=Connected to LooseNodes (not part of main 3d NodeTree)
		//Reserve "(InvalidPointer)" for non-existing Internal names of Pointers
		std::string ParentInternalName = "";
		//Note:Position data will be messed up if some nodes are destroyed in some situations(would need to recalculate position in such cases) 
		TagPosition PositionInTree;
		//Name of Bone
		std::string NodeName = "";
		//std::string TagContent="";
		//************************************
		// Templated Function (NodeTreeType = NodeTree)
		// Used by NodeTree::DestroyNodeAndAllItsChildren to obtain child nodes within
		// Method:    ObtainAllChildNodeNames
		// FullName:  LooseNodeTreeTemplate::Node::ObtainAllChildNodeNames
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: NodeTreeType & NodeTreeTarget
		// Parameter: StringVectorList & ListOfNodes
		//************************************
		template <typename NodeTreeType>
		void ObtainAllChildNodeNames(NodeTreeType& NodeTreeTarget, StringVectorList& ListOfNodes)
		{
			const size_t ChildListSize = ChildInternalNames.Size();
			Node* TargetNode;
			std::string NodeName;
			for(size_t Index=0;Index<ChildListSize;++Index)
			{
				NodeName = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget.GetNodePointerFromInternalName(NodeName);
				if(TargetNode!=nullptr)
				{
					ListOfNodes.Add(NodeName);
					TargetNode->ObtainAllChildNodeNames(NodeTreeTarget, ListOfNodes&);
				}
			}
		}
		void SearchAndBuildOutputNodeInternalName(StringVectorList& OutputBuffer, int& OutputLvl)
		{
			std::cout << StringFunctions::CreateTabSpace(OutputLvl) << "[" << InternalName << "]\n";
		}
		template <typename NodeTreeType>
		void SearchAndBuildOutputNodeInternalNameWithin(NodeTreeType* NodeTreeTarget, StringVectorList& OutputBuffer, int& OutputLvl)
		{
			std::string TargetNameTemp;
			NodeTreeType* TargetNode;
			SearchAndBuildOutputNodeInternalName(OutputBuffer, OutputLvl);
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->SearchAndBuildOutputNodeInternalNameWithin(NodeTreeTarget, OutputBuffer, OutputLvl);
				}
			}
		}
		Node() {}
		~Node() {}
	};

	//NodeType = Node (Templated Node here)
	template <typename NodeType>
	class NodeTree : public VariableList<NodeType>
	{
	public:
		//NodeIndex shortcut(Turn off Node index shortcut if nodes added or removed)
		//This is flipped on when FixCurrentNodeData fixes the current node point if not already on1
		bool CurrentNodeIndexUsed = false;
		//NodeIndex of last node used (shortcut to last node in case of pointer messup if CurrentNodeIndexUsed==true)
		//This value is set automatically when FixCurrentNodeData is used to fix the pointer to the current node
		//Value also set when AddNodeToRoot or AddSubItem used
		size_t CurrentNodeIndex=0;
		//Current Saved XML Tag Edited/Added
		NodeType* CurrentNode = nullptr;
		//InternalName of CurrentNode(for fixing Pointer)
		std::string CurrentTagInternalName = "";
		//Used for Nodes not part of 3d Node Tree (for things such as extra data nodes in Niflib)
		StringVectorList BaseLooseNode;
		//Root internal Nodes
		StringVectorList RootInternalNodes;
		//************************************
		// Returns True if Internal Name is already used
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
			const size_t SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			for(size_t Index=0; Index < SizeTemp&& NameUsed == false; ++Index)
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
		// Uses BaseInternalName to generate unused Internal Name with format BaseInternalNameX(AttempNumber) or BaseInternalNameXX(AttemptNumber) if over 9223372036854775807 
		//(Function supports 18,446,744,073,709,551,615 Attempts before it errors;But should be way more than enough in most cases in 64 Bit)
		//Use GenerateUnusedInternalName_32Bit instead for 32Bit Programs or if know will only need 4,294,967,295 attempts
		// Method:    GenerateUnusedInternalName
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::GenerateUnusedInternalName
		// Access:    public
		// Returns:   string
		// Qualifier:
		// Parameter: std::string BaseInternalName
		//************************************
		std::string GenerateUnusedInternalName(std::string BaseInternalName)
		{
			const std::string BaseName = BaseInternalName;
			std::string NameTemp = BaseInternalName;
			size_t AttemptNumberTemp;
			for(size_t AttemptNumber = 1; CheckIfInternalNameUsed(NameTemp); ++AttemptNumber)
			{
				NameTemp = BaseName;
				NameTemp += "X";
				if(AttemptNumber<=9223372036854775807)
				{
					NameTemp += StringFunctions::XIntToStringConversion(AttemptNumber);
				}
				else
				{
					AttemptNumberTemp = AttemptNumber - 9223372036854775807;
					NameTemp += "X";
					NameTemp += StringFunctions::XIntToStringConversion(AttemptNumberTemp);
				}
			}
			return NameTemp;
		}
		std::string GenerateUnusedInternalName_32Bit(std::string BaseInternalName)
		{
			const std::string BaseName = BaseInternalName;
			std::string NameTemp = BaseInternalName;
			unsigned __int32 AttemptNumberTemp;
			for(unsigned __int32 AttemptNumber = 1; CheckIfInternalNameUsed(NameTemp); ++AttemptNumber)
			{
				NameTemp = BaseName;
				NameTemp += "X";
				if(AttemptNumber<=2147483647)
				{
					NameTemp += StringFunctions::IntToStringConversion(AttemptNumber);
				}
				else
				{
					AttemptNumberTemp = AttemptNumber - 2147483647;
					NameTemp += "X";
					NameTemp += StringFunctions::IntToStringConversion(AttemptNumberTemp);
				}
			}
			return NameTemp;
		}
		//************************************
		// Method:    AutoGenInternalNameFromNode
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::AutoGenInternalNameFromNode
		// Access:    public
		// Returns:   string
		// Qualifier:
		// Parameter: NodeType * TargetNode
		//************************************
		std::string AutoGenInternalNameFromNode(NodeType* TargetNode)
		{
			std::string NameTemp;
			TagPosition PositionTemp = TargetNode->PositionInTree;
			NameTemp = PositionTemp.PositionString();
			if(CheckIfInternalNameUsed(NameTemp))
			{
				NameTemp = GenerateUnusedInternalName(NameTemp);
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
			size_t Index = Size();
			CurrentNodeIndexUsed = true;
			CurrentNodeIndex = Index;
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
				std::string NameTemp;
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
		NodeType* GetNodePointerFromInternalName(std::string InternalName)
		{
			const size_t SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			NodeType* TargetNodePointer = nullptr;
			for(size_t Index=0; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
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
		void SetCurrentNodeByName(std::string Name)
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
			if(CurrentNodeIndexUsed&&(CurrentNode == nullptr||CurrentNode->InternalName != CurrentTagInternalName))
			{
				CurrentNode = GetElementPointerV2(CurrentNodeIndex);
				CurrentTagInternalName = CurrentNode->InternalName;
			}
			else if((CurrentNode == nullptr&&CurrentTagInternalName != "")||CurrentNode->InternalName != CurrentTagInternalName)
			{
				const size_t SizeTemp = Size();
				NodeType* NodePointer = nullptr;
				NodeType* TargetNodePointer = nullptr;
				for(size_t Index=0; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
				{
					NodePointer = GetElementPointerV2(Index);
					if(NodePointer->InternalName == InternalName)
					{
						TargetNodePointer = NodePointer;
						CurrentNodeIndex = Index;
					}
				}
				if(TargetNodePointer==nullptr)
				{
					CurrentTagInternalName = "";
				}
				else
				{
					CurrentNode = TargetNodePointer;
					CurrentNodeIndexUsed = true;
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
		void FixTreePointers()
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
			CurrentNodeIndexUsed = true;
			CurrentNodeIndex = Size();
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
				else if(SpecialModifier=="AddToParentNode")
				{
					SpecialModifier = "";
					std::string NodeTargetString = CurrentNode->ParentInternalName;
					if(NodeTargetString == "(Core)"||NodeTargetString=="")
					{
						std::cout << "Parent of Parent Node does not exist.\nNo node added.\n";
					}
					else
					{
						NodeType* TargetNode = GetNodePointerFromInternalName(NodeTargetString);
						if(TargetNode == nullptr)
						{
							std::cout << "Invalid parent node found.\nNo Node added.\n";
						}
						else
						{
							NodeTargetString = TargetNode->ParentInternalName;
							if(NodeTargetString == "(Core)")
							{
								AddNodeToRoot(ItemName, InternalName);
							}
							else
							{
								TargetNode = GetNodePointerFromInternalName(CurrentNode->ParentInternalName);
								if(TargetNode == nullptr)
								{
									std::cout << "Invalid parent node found.\nNo Node added.\n";
								}
								else
								{
									AddSubItem(TargetNode, SpecialModifier, ItemName, InternalName);
								}
							}
						}
					}
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
						NodeType* TargetNode = GetNodePointerFromInternalName(CurrentNode->ParentInternalName);
						if(TargetNode == nullptr)
						{
							std::cout << "Invalid parent node found.\nNo Node added.\n";
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
		//TargetMenuMaster=="(LastItem)",SpecialModifier == "AddToParentNode" = Adds Node within last Node Added to Tree
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
		void AddMenuItemData(std::string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			unsigned int SizeTemp = Size();
			FixCurrentNodeData();
			CurrentNodeIndexUsed = false;
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
		// Method:    GetIndexOfInternalName
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::GetIndexOfInternalName
		// Access:    public 
		// Returns:   size_t
		// Qualifier:
		// Parameter: std::string TargetNodeInternalName
		//************************************
		size_t GetIndexOfInternalName(std::string TargetNodeInternalName)
		{
			bool IndexFound = false;
			size_t TargetIndex = 0;
			NodeType Element;
			const size_t SizeTemp = Size();
			for(size_t Index = 0; Index < SizeTemp&&IndexFound == false;++Index)
			{
				Element = ElementAt(Index);
				if(Element.InternalName==TargetNodeInternalName)
				{
					TargetIndex = Index;
					IndexFound = true;
				}
			}
			return TargetIndex;
		}
		//************************************
		// Method:    DestroyTargetNodeAndAllItsChildren
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::DestroyTargetNodeAndAllItsChildren
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: NodeType * TargetNode
		//************************************
		void DestroyTargetNodeAndAllItsChildren(NodeType* TargetNode)
		{
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
				NodeType* ParentNode = GetNodePointerFromInternalName(ParentNodeName);
				if(ParentNode != nullptr)
				{
					ParentNode->ChildInternalNames.RemoveElementWithMatchingValue(TargetNodeInternalName)
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
				TargetNode.ObtainAllChildNodeNames(&this, &InternalNamesOfNodesToDestroy) < NodeTree > ;//<std::typeid(NodeTree)>
			}
			//Now destroy all nodes in list set to destroy
			SizeTemp = InternalNamesOfNodesToDestroy.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = InternalNamesOfNodesToDestroy.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					Remove(GetIndexOfInternalName(TargetNameTemp));
				}
			}
		}
		//************************************
		// Method:    DestroyNodeAndAllItsChildren
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::DestroyNodeAndAllItsChildren
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: std::string TargetNodeInternalName
		//************************************
		void DestroyNodeAndAllItsChildren(std::string TargetNodeInternalName)
		{
			CurrentNodeIndexUsed = false;
			NodeType* TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);
			if(TargetNode == nullptr)
			{
				std::cout << "Target Node with internal name " << TargetNodeInternalName << " does not exist.\n";
			}
			else
			{
				DestroyTargetNodeAndAllItsChildren(TargetNode);
			}
		}
		//************************************
		// Method:    MoveNode
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::MoveNode
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: std::string TargetNodeInternalName
		// Parameter: std::string TargetNodeMoveLocationInternalName
		//************************************
		void MoveNode(std::string TargetNodeInternalName, std::string TargetNodeMoveLocationInternalName)
		{
			CurrentNodeIndexUsed = false;
			NodeType* TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);
			if(TargetNode==nullptr)
			{
				std::cout << "Target Node with internal name " << TargetNodeInternalName << " does not exist.\n";
			}
			else
			{
				//Remove node from child list of parent
				std::string ParentNodeName = TargetNode->ParentInternalName;
				if(ParentNodeName == "(Core)")
				{
					RootInternalNodes.RemoveElementWithMatchingValue(TargetNodeInternalName);
				}
				else if(ParentNodeName == "")
				{
					BaseLooseNode.RemoveElementWithMatchingValue(TargetNodeInternalName);
				}
				else
				{
					NodeType* ParentNode = GetNodePointerFromInternalName(ParentNodeName);
					if(ParentNode != nullptr)
					{
						ParentNode->ChildInternalNames.RemoveElementWithMatchingValue(TargetNodeInternalName);
					}
				}
				if(TargetNode == nullptr){TargetNode = GetNodePointerFromInternalName(TargetNodeInternalName);}
				//Now add node to Target Node Location
				if(TargetNodeMoveLocationInternalName=="(Core)"||TargetNodeMoveLocationInternalName=="(LooseNodes)")
				{
					TargetNode->ParentInternalName = TargetNodeMoveLocationInternalName;
					if(TargetNodeMoveLocationInternalName=="(Core)")
					{
						RootInternalNodes.Add(TargetNodeInternalName);
					}
					else
					{
						BaseLooseNode.Add(TargetNodeInternalName);
					}
				}
				else
				{
					NodeType* TargetLocationNode = GetNodePointerFromInternalName(TargetNodeMoveLocationInternalName);
					if(TargetLocationNode!=nullptr)
					{
						TargetNode->ParentInternalName = TargetNodeMoveLocationInternalName;
						TargetLocationNode->ChildInternalNames.Add(TargetNodeInternalName);
					}
					else
					{
						TargetNode->ParentInternalName = "";
						std::cout<<"Failed to complete move of node "<<TargetNodeInternalName<<" to node "<<TargetNodeMoveLocationInternalName<<". Node is removed from old parent now but not connected to new parent since node with internal name of "<<TargetNodeMoveLocationInternalName<<" does not exist.\n";
					}
				}
			}
		}

		//************************************
		// Method:    OutputInternalNamesTreeToFile
		// FullName:  LooseNodeTreeTemplate::NodeTree<NodeType>::OutputInternalNamesTreeToFile
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: string Filename
		//************************************
		void OutputInternalNamesTreeToFile(std::string Filename)
		{
			StringVectorList OutputBuffer;
			size_t OutputLvl=0;
			size_t SizeTemp = RootInternalNodes.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				NodePointer->SearchAndBuildOutputNodeInternalNameWithin(OutputBuffer, OutputLvl)<NodeTree>;
			}
			//Output LooseNodes data here
			SizeTemp = BaseLooseNode.Size();
			if(SizeTemp > 0)
			{
				OutputBuffer.Add("LooseNode Data:");
				OutputLvl = 0;
				for(size_t Index = 0; Index < SizeTemp; ++Index)
				{
					NodePointer->SearchAndBuildOutputNodeInternalNameWithin(OutputBuffer, OutputLvl)<NodeTree>;
				}
			}
			OutputBuffer.SaveDataToFileV3(Filename);
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
};
#endif