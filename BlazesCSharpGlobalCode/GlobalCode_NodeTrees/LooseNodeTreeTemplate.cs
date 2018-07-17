using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_StringFunctions;
using CSharpGlobalCode.GlobalCode_VariableLists;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
	class LooseNode<NodeTreeType>
	{
#if (!NodeTree_AlternativeInternalName && !NodeTree_AlternativeInternalNameV2)
		//InternalName of child elements to this node
		public StringList ChildInternalNames;
		//AutoGenerate InternalName based on XMLPosition unless specified(InternalName must be unique;Required for pointer fixes)
		//Example: ParentIndexPositionString-ListPosition ("-0" for first Tag in menu)
		//Use GenerateUnusedInternalName(BaseInternalName) to ensure unique InternalName or Use AutoGenInternalNameFromNode() to generate based on TagPosition(might have conflicts if nodes removed but will auto-rename as needed) as long as doesn't reach over 18,446,744,073,709,551,615 attempts
		public string InternalName = "";
		//InternalName of parent(fix for pointer invalidation);"(Core)"=Connected at base of NodeTree;"(LooseNodes)"=Connected to LooseNodes (not part of main 3d NodeTree)
		//Reserve "(InvalidPointer)" for non-existing Internal names of Pointers
		public string ParentInternalName = "";
		bool IsLooseNode()
		{
			if (ParentInternalName == "LooseNodes" || ParentInternalName == "")
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//void SearchAndBuildOutputNodeInternalName(StringList& OutputBuffer, int& OutputLvl)
		//{
		//	std::cout << StringFunctions::CreateTabSpace(OutputLvl) << "[" << InternalName << "]\n";
		//}
		//void SearchAndBuildOutputNodeInternalNameWithin(NodeTreeType NodeTreeTarget, StringList& OutputBuffer, int& OutputLvl)
		//{
		//	string TargetNameTemp;
		//	LooseNode<NodeTreeType> TargetNode;
		//	SearchAndBuildOutputNodeInternalName(OutputBuffer, OutputLvl);
		//	int ChildListSize = ChildInternalNames.Count();
		//	for (int Index = 0; Index < ChildListSize; ++Index)
		//	{
		//		TargetNameTemp = ChildInternalNames.ElementAt(Index);
		//		TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
		//		if (TargetNode != nullptr)
		//		{
		//			TargetNode->SearchAndBuildOutputNodeInternalNameWithin(NodeTreeTarget, OutputBuffer, OutputLvl);
		//		}
		//	}
		//}
		//Finish Alternative InternalID code later
#elif (NodeTree_AlternativeInternalName)
		//InternalID of child elements to this node
		List<unsigned __int32> ChildInternalNames;
		//InternalID of Node(Must be unique inside NodeTree)
		uint InternalID = 4294967294;
		//InternalID of ParentNode
		uint ParentInternalID = 4294967294;
#else
		//InternalID of child elements to this node
		List<ulong> ChildInternalNames;
		//InternalID of Node(Must be unique inside NodeTree)
		ulong InternalID = 18446744073709551615;
		//InternalID of ParentNode
		ulong ParentInternalID = 18446744073709551615;
#endif
		//Note:Position data will be messed up if some nodes are destroyed in some situations(would need to recalculate position in such cases) 
		public TagPosition PositionInTree;
		//Name of Node
		public string NodeName = "";
		//////************************************
		////// Templated Function (NodeTreeType = NodeTree)
		////// Used by NodeTree::DestroyNodeAndAllItsChildren to obtain child nodes within
		////// Method:    ObtainAllChildNodeNames
		////// FullName:  LooseNodeTreeTemplate::Node::ObtainAllChildNodeNames
		////// Access:    public 
		////// Returns:   void
		////// Qualifier:
		////// Parameter: NodeTreeType & NodeTreeTarget
		////// Parameter: StringVectorList & ListOfNodes
		//////************************************
		//void ObtainAllChildNodeNames(NodeTreeType* NodeTreeTarget, StringList& ListOfNodes)
		//{
		//	int ChildListSize = ChildInternalNames.Count;
		//	LooseNode<NodeTreeType> TargetNode;
		//	string NodeName;
		//	for (size_t Index = 0; Index < ChildListSize; ++Index)
		//	{
		//		NodeName = ChildInternalNames.ElementAt(Index);
		//		TargetNode = NodeTreeTarget.GetNodePointerFromInternalName(NodeName);
		//		if (TargetNode != nullptr)
		//		{
		//			ListOfNodes.Add(NodeName);
		//			TargetNode->ObtainAllChildNodeNames(NodeTreeTarget, ListOfNodes &);
		//		}
		//	}
		//}
		//void Reset()
		//{
		//	ChildInternalNames.Reset();
		//	PositionInTree.ListPosition = -1;
		//	PositionInTree.ParentIndexPosition.Reset();
		//}
	}
	public class LooseNodeTree<NodeType>
	{

	}
}
