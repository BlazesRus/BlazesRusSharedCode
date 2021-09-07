// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#ifndef LooseNodeTreeTemplate_IncludeGuard
#define LooseNodeTreeTemplate_IncludeGuard

//#include <typeinfo>//Might be needed if doesn't update derived class Type name of NodeTree

#ifdef BLAZESSharedCode_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#ifdef BlazesSharedCode_LocalLayout//(Local version style layout)
#else
#include "..\VariableLists\StringVectorList.h"
#include "..\VariableLists\VariableList.h"
#include "..\VariableLists\VariableTypeLists.h"
#include "..\NodeTrees\TagPosition.h"
#include "..\QuadVector\QuadVector.h"
#include "..\VariableLists\StringVectorList.h"
#include "..\OtherFunctions\StringFunctions.h"
#include "..\NodeTrees\XMLOption.h"
#include "..\OtherFunctions\VariableConversionFunctions.h"
#endif

//Contains LooseNodeTree BaseData for templating
/// <summary>
/// Struct named LooseNodeTreeTemplate
/// </summary>
struct DLL_API LooseNodeTreeTemplate
{
	//Equals <typename NodeType>
/// <summary>
/// Class named Node.
/// </summary>
	class DLL_API Node
	{
	public:
#ifndef NodeTree_AlternativeInternalName
		//InternalName of child elements to this node
/// <summary>
/// The child internal names
/// </summary>
		StringVectorList ChildInternalNames;
		//AutoGenerate InternalName based on XMLPosition unless specified(InternalName must be unique;Required for pointer fixes)
		//Example: ParentIndexPositionString-ListPosition ("-0" for first Tag in menu)
		//Use GenerateUnusedInternalName(BaseInternalName) to ensure unique InternalName or Use AutoGenInternalNameFromNode() to generate based on TagPosition(might have conflicts if nodes removed but will auto-rename as needed) as long as doesn't reach over 18,446,744,073,709,551,615 attempts
/// <summary>
/// The internal name
/// </summary>
		std::string InternalName = "";
		//InternalName of parent(fix for pointer invalidation);"(Core)"=Connected at base of NodeTree;"(LooseNodes)"=Connected to LooseNodes (not part of main 3d NodeTree)
		//Reserve "(InvalidPointer)" for non-existing Internal names of Pointers
/// <summary>
/// The parent internal name
/// </summary>
		std::string ParentInternalName = "";
		/// <summary>
		/// Determines whether [is loose node].
		/// </summary>
		/// <returns>bool</returns>
		bool IsLooseNode()
		{
			if(ParentInternalName == "LooseNodes" || ParentInternalName == "")
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		/// <summary>
		/// Searches the name of the and build output node internal.
		/// </summary>
		/// <param name="OutputBuffer">The output buffer.</param>
		/// <param name="OutputLvl">The output level.</param>
		void SearchAndBuildOutputNodeInternalName(StringVectorList& OutputBuffer, int& OutputLvl)
		{
			std::cout << StringFunctions::CreateTabSpace(OutputLvl) << "[" << InternalName << "]\n";
		}
		/// <summary>
		/// Searches the and build output node internal name within.
		/// </summary>
		/// <param name="NodeTreeTarget">The node tree target.</param>
		/// <param name="OutputBuffer">The output buffer.</param>
		/// <param name="OutputLvl">The output level.</param>
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
//Finish Alternative InternalID code later
#elif NodeTree_AlternativeInternalName == 1
		//InternalID of child elements to this node
/// <summary>
/// The child internal names
/// </summary>
		VariableList <unsigned __int32> ChildInternalNames;
		//InternalID of Node(Must be unique inside NodeTree)
/// <summary>
/// The internal identifier
/// </summary>
		unsigned __int32 InternalID = 4294967294;
		//InternalID of ParentNode
/// <summary>
/// The parent internal identifier
/// </summary>
		unsigned __int32 ParentInternalID = 4294967294;
#elif NodeTree_AlternativeInternalName == 2
		//InternalID of child elements to this node
/// <summary>
/// The child internal names
/// </summary>
		VariableList <unsigned __int64> ChildInternalNames;
		//InternalID of Node(Must be unique inside NodeTree)
/// <summary>
/// The internal identifier
/// </summary>
		unsigned __int64 InternalID = 18446744073709551615;
		//InternalID of ParentNode
/// <summary>
/// The parent internal identifier
/// </summary>
		unsigned __int64 ParentInternalID = 18446744073709551615;
#endif
		//Note:Position data will be messed up if some nodes are destroyed in some situations(would need to recalculate position in such cases)
/// <summary>
/// The position in tree
/// </summary>
		TagPosition PositionInTree;
		//Name of Node
/// <summary>
/// The node name
/// </summary>
		std::string NodeName = "";
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
/// <summary>
/// Obtains all child node names.
/// </summary>
/// <param name="NodeTreeTarget">The node tree target.</param>
/// <param name="ListOfNodes">The list of nodes.</param>
		template <typename NodeTreeType>
		void ObtainAllChildNodeNames(NodeTreeType* NodeTreeTarget, StringVectorList& ListOfNodes)
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
		/// <summary>
		/// Resets this instance.
		/// </summary>
		void Reset()
		{
			ChildInternalNames.Reset();
			PositionInTree.ListPosition = -1;
			PositionInTree.ParentIndexPosition.Reset();
		}
		/// <summary>
		/// Initializes a new instance of the <see cref="Node"/> class.
		/// </summary>
		Node() {}
		/// <summary>
		/// Finalizes an instance of the <see cref="Node"/> class.
		/// </summary>
		~Node() {}
	};

	//NodeType = Node (Templated Node here)
/// <summary>
/// Class named NodeTree.
/// Implements the <see cref="VariableList{NodeType}" />
/// </summary>
/// <seealso cref="VariableList{NodeType}" />
	template <typename NodeType>
	class DLL_API NodeTree : public VariableList<NodeType>
	{
	public:
		//NodeIndex shortcut(Turn off Node index shortcut if nodes added or removed)
		//This is flipped on when FixCurrentNodeData fixes the current node point if not already on1
/// <summary>
/// The current node index used
/// </summary>
		bool CurrentNodeIndexUsed = false;
		//NodeIndex of last node used (shortcut to last node in case of pointer messup if CurrentNodeIndexUsed==true)
		//This value is set automatically when FixCurrentNodeData is used to fix the pointer to the current node
		//Value also set when AddNodeToRoot or AddSubItem used
/// <summary>
/// The current node index
/// </summary>
		size_t CurrentNodeIndex = 0;
		//Current Saved XML Tag Edited/Added
/// <summary>
/// The current node
/// </summary>
		NodeType* CurrentNode = nullptr;
//use NodeTree_AlternativeInternalName if need to save extra memory by storing InternalName as integer values instead of names
#ifndef NodeTree_AlternativeInternalName
		//InternalName of CurrentNode(for fixing Pointer)
/// <summary>
/// The current node internal name
/// </summary>
		std::string CurrentNodeInternalName = "";
#elif NodeTree_AlternativeInternalName == 1
		//InternalID of CurrentNode(32 Bit Int) max value=ValueNotSet (limits Number of usable nodes to between 0 - 4,294,967,293
/// <summary>
/// The current node internal identifier
/// </summary>
		unsigned __int32 CurrentNodeInternalID = 4294967294;//(unsigned __int32) std::numeric_limits<unsigned __int32>::max();
#elif NodeTree_AlternativeInternalName == 2
		//InternalID of CurrentNode(64 Bit Int) max value=ValueNotSet (limits Number of usable nodes to between 0 - 18,446,744,073,709,551,614
/// <summary>
/// The current node internal identifier
/// </summary>
		unsigned __int64 CurrentNodeInternalID = 18446744073709551615;//(unsigned __int64) std::numeric_limits<unsigned __int64>::max();
#endif
		//Used for Nodes not part of 3d Node Tree (for things such as extra data nodes in Niflib)
/// <summary>
/// The base loose node
/// </summary>
		StringVectorList BaseLooseNode;
		//Root internal Nodes
/// <summary>
/// The root internal nodes
/// </summary>
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
/// <summary>
/// Checks if internal name used.
/// </summary>
/// <param name="InternalName">Name of the internal.</param>
/// <returns>bool</returns>
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
/// <summary>
/// Generates the name of the unused internal.
/// </summary>
/// <param name="BaseInternalName">Name of the base internal.</param>
/// <returns>std.string</returns>
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
					NameTemp += VariableConversionFunctions::XIntToStringConversion(AttemptNumber);
				}
				else
				{
					AttemptNumberTemp = AttemptNumber - 9223372036854775807;
					NameTemp += "X";
					NameTemp += VariableConversionFunctions::XIntToStringConversion(AttemptNumberTemp);
				}
			}
			return NameTemp;
		}
		/// <summary>
		/// Generates the unused internal name 32 bit.
		/// </summary>
		/// <param name="BaseInternalName">Name of the base internal.</param>
		/// <returns>std.string</returns>
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
					NameTemp += VariableConversionFunctions::IntToStringConversion(AttemptNumber);
				}
				else
				{
					AttemptNumberTemp = AttemptNumber - 2147483647;
					NameTemp += "X";
					NameTemp += VariableConversionFunctions::IntToStringConversion(AttemptNumberTemp);
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
/// <summary>
/// Automatics the gen internal name from node.
/// </summary>
/// <param name="TargetNode">The target node.</param>
/// <returns>std.string</returns>
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
/// <summary>
/// Adds the node to root.
/// </summary>
/// <param name="NodeName">Name of the node.</param>
/// <param name="InternalName">Name of the internal.</param>
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
			CurrentNodeInternalName = ElementPointer->InternalName;
		}
		/// <summary>
		/// Adds the loose node.
		/// </summary>
		/// <param name="NodeName">Name of the node.</param>
		/// <param name="InternalName">Name of the internal.</param>
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
/// <summary>
/// Resets the data.
/// </summary>
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
/// <summary>
/// Sets the current node.
/// </summary>
/// <param name="PointerTemp">The pointer temporary.</param>
		void SetCurrentNode(NodeType* PointerTemp)
		{
			CurrentNode = PointerTemp;
			CurrentNodeInternalName = CurrentNode->InternalName;
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
/// <summary>
/// Gets the name of the node pointer from internal.
/// </summary>
/// <param name="InternalName">Name of the internal.</param>
/// <returns>NodeType *</returns>
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
/// <summary>
/// Sets the name of the current node by.
/// </summary>
/// <param name="Name">The name.</param>
		void SetCurrentNodeByName(std::string Name)
		{
			CurrentNode = GetNodePointerFromInternalName(Name);
			if(CurrentNode == nullptr)
			{
				CurrentNodeInternalName = "";
			}
			else
			{
				CurrentNodeInternalName = Name;
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
/// <summary>
/// Fixes the current node data.
/// </summary>
		void FixCurrentNodeData()
		{
			if(CurrentNodeIndexUsed&&(CurrentNode == nullptr||CurrentNode->InternalName != CurrentNodeInternalName))
			{
				CurrentNode = GetElementPointerV2(CurrentNodeIndex);
				CurrentNodeInternalName = CurrentNode->InternalName;
			}
			else if((CurrentNode == nullptr&&CurrentNodeInternalName != "")||CurrentNode->InternalName != CurrentNodeInternalName)
			{
				const size_t SizeTemp = Size();
				NodeType* NodePointer = nullptr;
				NodeType* TargetNodePointer = nullptr;
				for(size_t Index=0; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
				{
					NodePointer = GetElementPointerV2(Index);
					if(NodePointer->InternalName == CurrentNodeInternalName)
					{
						TargetNodePointer = NodePointer;
						CurrentNodeIndex = Index;
					}
				}
				if(TargetNodePointer==nullptr)
				{
					CurrentNodeInternalName = "";
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
/// <summary>
/// Fixes the tree pointers.
/// </summary>
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
		/// <summary>
		/// Finds the first name of the node with matching node.
		/// </summary>
		/// <param name="TargetName">Name of the target.</param>
		/// <returns>NodeType *</returns>
		NodeType* FindFirstNodeWithMatchingNodeName(std::string TargetName)
		{
			const size_t SizeTemp = Size();
			NodeType* NodePointer = nullptr;
			NodeType* TargetNodePointer = nullptr;
			std::string CurrentInternalName;
			for(size_t Index=0; Index < SizeTemp&&TargetNodePointer==nullptr; ++Index)
			{
				NodePointer = this->GetElementPointerV2(Index);
				if(NodePointer->NodeName==TargetName)
				{
					TargetNodePointer = NodePointer;
				}
			}
			return TargetNodePointer;
		}
		/// <summary>
		/// Adds the sub item.
		/// </summary>
		/// <param name="TargetNode">The target node.</param>
		/// <param name="SpecialModifier">The special modifier.</param>
		/// <param name="ItemName">Name of the item.</param>
		/// <param name="InternalName">Name of the internal.</param>
		void AddSubItem(NodeType* TargetNode, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			//Adding SubItem to parent node of current node
			CurrentNodeIndexUsed = true;
			CurrentNodeIndex = Size();
			AddData();
			FixCurrentNodeData();
			NodeType* NextNode = GetElementPointerV2(CurrentNodeIndex);
			TagPosition PositionTemp = CurrentNode->PositionInTree;
			PositionTemp.IncreaseListPos();
			NextNode->PositionInTree = PositionTemp;
			if(ItemName != "")
			{
				NextNode->NodeName = ItemName;
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
				std::string NameTemp;
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
			NextNode->ParentInternalName = TargetNode->InternalName;
			TargetNode->ChildInternalNames.Add(NextNode->InternalName);
		}
		/// <summary>
		/// Adds the last item.
		/// </summary>
		/// <param name="SpecialModifier">The special modifier.</param>
		/// <param name="ItemName">Name of the item.</param>
		/// <param name="InternalName">Name of the internal.</param>
		void AddLastItem(std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			if(CurrentNodeInternalName == "")
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
/// <summary>
/// Adds the menu item data.
/// </summary>
/// <param name="TargetMenuMaster">The target menu master.</param>
/// <param name="SpecialModifier">The special modifier.</param>
/// <param name="ItemName">Name of the item.</param>
/// <param name="InternalName">Name of the internal.</param>
		void AddMenuItemData(std::string TargetMenuMaster, std::string SpecialModifier = "", std::string ItemName = "", std::string InternalName = "")
		{
			size_t SizeTemp = Size();
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
				if(CurrentNodeInternalName == "")
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
				if(CurrentNodeInternalName == "")
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
				if(CurrentNodeInternalName == "")
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
/// <summary>
/// Gets the name of the index of internal.
/// </summary>
/// <param name="TargetNodeInternalName">Name of the target node internal.</param>
/// <returns>size_t</returns>
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
/// <summary>
/// Destroys the target node and all its children.
/// </summary>
/// <param name="TargetNode">The target node.</param>
		void DestroyTargetNodeAndAllItsChildren(NodeType* TargetNode)
		{
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
				NodeType* ParentNode = GetNodePointerFromInternalName(ParentNodeName);
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
				TargetNode.ObtainAllChildNodeNames(this, &InternalNamesOfNodesToDestroy);//<std::typeid(NodeTree)>
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
/// <summary>
/// Destroys the node and all its children.
/// </summary>
/// <param name="TargetNodeInternalName">Name of the target node internal.</param>
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
/// <summary>
/// Moves the node.
/// </summary>
/// <param name="TargetNodeInternalName">Name of the target node internal.</param>
/// <param name="TargetNodeMoveLocationInternalName">Name of the target node move location internal.</param>
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
/// <summary>
/// Outputs the internal names tree to file.
/// </summary>
/// <param name="Filename">The filename.</param>
		void OutputInternalNamesTreeToFile(std::string Filename)
		{
			StringVectorList OutputBuffer;
			size_t OutputLvl=0;
			std::string TempString;
			NodeType* NodePointer;
			size_t SizeTemp = RootInternalNodes.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TempString = RootInternalNodes.ElementAt(Index);
				NodePointer = GetNodePointerFromInternalName(TempString);
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
					TempString = BaseLooseNode.ElementAt(Index);
					NodePointer = GetNodePointerFromInternalName(TempString);
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
/// <summary>
/// Initializes a new instance of the <see cref="NodeTree"/> class.
/// </summary>
		NodeTree() {}
		//************************************
		// Method:    ~NodeTree
		// FullName:  LooseNodeTreeTemplate::NodeTree::~NodeTree
		// Access:    public
		// Returns:
		// Qualifier:
		//************************************
/// <summary>
/// Finalizes an instance of the <see cref="NodeTree"/> class.
/// </summary>
		~NodeTree() {}
	};
};
#endif
