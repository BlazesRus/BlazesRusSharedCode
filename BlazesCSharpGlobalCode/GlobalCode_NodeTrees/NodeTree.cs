using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_StringFunctions;
using CSharpGlobalCode.GlobalCode_VariableLists;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
    //Send and share Data through Node optimization (less complicated detection of TagContent variable types)
    public class OptimizationData
    {
        public string CurrentHavokClass = "";
        public string CurrentActionDataSection_01 = "";
    };

    public class TagNodeTreeSharedData
    {
        public long TabLevel = 0;
    };

    class Node<NodeTreeType, LooseNodeTreeType> : LooseNode<LooseNodeTreeType>
    {
        public List<Node<NodeTreeType, LooseNodeTreeType>> NodeLists;

        //Internal Name of Tag Closing Tag Connected To(Used for Destroying Closing Tag when destroying NodesWithin)
        public string InternalNameOfTagClosed = "";

        //Detects if either Closing Tag, Closed Tag, or Neither
        //0 = Tag is not a Closing Tag
        //1 = Is Closing Tag
        //2 = Tag is Closed by Tag with InternalName of InternalNameOfTagClosed
        public byte ClosingStatus = 0;

        public string TagContent = "";

        //Type of data stores inside Tag (Strings stored in TagContent)
        //0:Default Extracted content
        //1:Int
        //2:Bool
        //3:Double
        //4:String
        //5:Event Index(Int)
        //6:Variable Index(Int)
        //7:Havok Class index(Int)
        //8:Short
        //9:QuadVector
        //10:Event String
        //11:Variable String
        //12:Animation Path String
        //13:Condition (String)
        //14:Havok Class Target Name (String);(For HTML/XML Generation this is Internal Name of Node Linked)
        //15:Havok Class Target List (StringList)
        //20:IntegerList
        //21:DoubleList
        //22:StringList
        //23:BooleanList
        //24:QuadVectorList
        //50:flags (String)
        //51:Clip Mode (String)
        //240:Holds Havok Class info
        //241:hkobject Container
        //242:Closing Tag of Havok Class
        //250:Unknown (String)
        //251:Unknown(String) with only whitespace and
        //252:Node Link(Internal Name of Node Linking to);For use with HTML/XML generation of Tree
        //255:Other misc Tags within
        public byte TagContentType = 0;

        //Additional Tag Args
        public XMLOptionList AdditionTagOptions;

        public bool SelfContainedTag = false;
        public bool XMLVersionTag = false;
        public bool UsingAlternativeTagContentStorage = false;

        //************************************
        // Method:    CopyOtherDataFromNode
        // FullName:  TagNodeTreeTemplateData::Node::CopyOtherDataFromNode
        // Access:    public
        // Returns:   void
        // Qualifier:
        // Parameter: Node * TargetNode
        //************************************
        public void CopyOtherDataFromNode(Node<NodeTreeType, LooseNodeTreeType> TargetNode)
        {
            TagContent = TargetNode.TagContent;
            SelfContainedTag = TargetNode.SelfContainedTag;
            ClosingStatus = TargetNode.ClosingStatus;
            AdditionTagOptions = TargetNode.AdditionTagOptions;
        }

        //************************************
        // Method:    DetectTagContentType
        // FullName:  TagNodeTreeTemplateData::Node::DetectTagContentType
        // Access:    public
        // Returns:   void
        // Qualifier:
        //************************************
        public void DetectTagContentType()
        {
            if (TagContentType == 0 && TagContent != "")
            {
                TagContentType = StringFunctions.FindContentType(TagContent);
            }
        }

        ///// <summary>
        ///// Detects the tag content types within.
        ///// </summary>
        ///// <param name="NodeTreeTarget">The node tree target.</param>
        //public void DetectTagContentTypesWithin(NodeTreeType NodeTreeTarget)
        //{
        //	string TargetNameTemp;
        //	Node<NodeTreeType, LooseNodeTreeType> TargetNode;
        //	DetectTagContentType();
        //	int ChildListSize = ChildInternalNames.Count;
        //	for (int Index = 0; Index < ChildListSize; ++Index)
        //	{
        //		TargetNameTemp = ChildInternalNames.ElementAt(Index);
        //		TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
        //		if (TargetNode != nullptr)
        //		{
        //			TargetNode->DetectTagContentTypesWithin(NodeTreeTarget);
        //		}
        //	}
        //}

        ///// <summary>
        ///// Alternative version of DetectTagContentType designed to use extra contents from hkparam tags as part of detection of ContentType
        ///// </summary>
        ///// <param name="">The .</param>
        ///// <param name="">The .</param>
        //public void DetectTagContentTypeV2(OptimizationData& SharedData)
        //{
        //}

        ///// <summary>
        ///// Alternative version of DetectTagContentTypesWithin designed to use extra contents from hkparam tags as part of detection of ContentType
        ///// </summary>
        ///// <param name="NodeTreeTarget">The node tree target.</param>
        ///// <param name="">The .</param>
        ///// <param name="">The .</param>
        //public void DetectTagContentTypesWithinV2(NodeTreeType NodeTreeTarget, OptimizationData& SharedData)
        //{
        //	string TargetNameTemp;
        //	Node<NodeTreeType, LooseNodeTreeType> TargetNode;
        //	DetectTagContentTypeV2(&SharedData);
        //	const int ChildListSize = ChildInternalNames.Count;
        //	for (int Index = 0; Index < ChildListSize; ++Index)
        //	{
        //		TargetNameTemp = ChildInternalNames.ElementAt(Index);
        //		TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
        //		if (TargetNode != nullptr)
        //		{
        //			TargetNode->DetectTagContentTypesWithinV2(NodeTreeTarget, SharedData);
        //		}
        //	}
        //}

        ////************************************
        //// Method:    GenerateHTMLDoc
        //// FullName:  TagNodeTreeTemplateData::Node::GenerateHTMLDoc
        //// Access:    public
        //// Returns:   void
        //// Qualifier:
        //// Parameter: StringList & OutputBuffer
        //// Parameter: int & OutputLvl
        //// Parameter: const unsigned __int8 & GenerationOptions
        ////************************************
        //public void GenerateHTMLDoc(StringList OutputBuffer, int OutputLvl, byte GenerationOptions = 0)
        //{
        //}

        //public void GenerateHTMLDocWithin(NodeTreeType* NodeTreeTarget, StringList OutputBuffer, int OutputLvl, byte GenerationOptions = 0)
        //{
        //	string TargetNameTemp;
        //	Node<NodeTreeType, LooseNodeTreeType> TargetNode;

        //	GenerateHTMLDoc(OutputBuffer, OutputLvl, GenerationOptions);

        //	int ChildListSize = ChildInternalNames.Count;
        //	for (int Index = 0; Index < ChildListSize; ++Index)
        //	{
        //		TargetNameTemp = ChildInternalNames.ElementAt(Index);

        //		TargetNode = NodeTreeTarget->public GetNodePointerFromInternalName(NodeName);

        //		if (TargetNode != nullptr)
        //		{
        //			TargetNode->public GenerateHTMLDocWithin(NodeTreeTarget, OutputBuffer, OutputLvl, GenerationOptions);
        //		}
        //	}
        //}
    }

    class NodeTree<NodeType> : LooseNodeTree<NodeType>
    {
    }
}
