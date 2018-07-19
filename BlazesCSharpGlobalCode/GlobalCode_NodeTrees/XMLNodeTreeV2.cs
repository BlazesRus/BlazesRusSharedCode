using CSharpGlobalCode.GlobalCode_StringFunctions;
using CSharpGlobalCode.GlobalCode_VariableLists;
using System.Collections.Generic;
using System.Linq;

namespace CSharpGlobalCode.GlobalCode_NodeTrees
{
    ////Send and share Data through Node optimization (less complicated detection of TagContent variable types)
    //public class OptimizationData
    //{
    //	public string CurrentHavokClass = "";
    //	public string CurrentActionDataSection_01 = "";
    //};

    //public class TagNodeTreeSharedData
    //{
    //	public long TabLevel = 0;
    //};

    /// <summary>
    /// Alternative version of Node class for containing XML like node with Lists of nodes within each
    /// </summary>
    public class NodeV2<NodeTreeType>
    {
        public List<NodeV2<NodeTreeType>> NodeLists;

        //public bool UsingAlternativeTagContentStorage = false;





        //////************************************
        ////// Method:    DetectTagContentTypesWithin
        ////// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypesWithin
        ////// Access:    public
        ////// Returns:   void
        ////// Qualifier:
        ////// Parameter: NodeTreeType & NodeTreeTarget
        //////************************************
        //public void DetectTagContentTypesWithin(NodeTreeType NodeTreeTarget)
        //{
        //	string TargetNameTemp;
        //	NodeV2<NodeTreeType> TargetNode;
        //	DetectTagContentType();
        //	const int ChildListSize = ChildInternalNames.Size();
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

        ////************************************
        //// Alternative version of DetectTagContentType designed to use extra contents from hkparam tags as part of detection of ContentType
        //// Method:    DetectTagContentTypeV2
        //// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypeV2
        //// Access:    public
        //// Returns:   void
        //// Qualifier:
        ////************************************
        //public void DetectTagContentTypeV2(OptimizationData& SharedData)
        //{
        //}

        ////************************************
        //// Alternative version of DetectTagContentTypesWithin designed to use extra contents from hkparam tags as part of detection of ContentType
        //// Method:    DetectTagContentTypesWithinV2
        //// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypesWithinV2
        //// Access:    public
        //// Returns:   void
        //// Qualifier:
        //// Parameter: NodeTreeType & NodeTreeTarget
        //// Parameter: OptimizationData & SharedData
        ////************************************
        //public void DetectTagContentTypesWithinV2(NodeTreeType* NodeTreeTarget, OptimizationData& SharedData)
        //{
        //	string TargetNameTemp;
        //	NodeV2<NodeTreeType> TargetNode;
        //	DetectTagContentTypeV2(&SharedData);
        //	const int ChildListSize = ChildInternalNames.Size();
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

        ////************************************
        //// Method:    GenerateHTMLDocWithin
        //// FullName:  TagNodeTreeTemplateData::Node::GenerateHTMLDocWithin
        //// Access:    public
        //// Returns:   void
        //// Qualifier:
        //// Parameter: NodeTreeType * NodeTreeTarget
        //// Parameter: StringList & OutputBuffer
        //// Parameter: int & OutputLvl
        //// Parameter: const unsigned __int8 & GenerationOptions
        ////************************************
        //template<typename NodeTreeType>
        //public void GenerateHTMLDocWithin(NodeTreeType* NodeTreeTarget, StringList OutputBuffer, int OutputLvl, byte GenerationOptions = 0)
        //{
        //	string TargetNameTemp;
        //	NodeV2<NodeTreeType> TargetNode;

        //	GenerateHTMLDoc(OutputBuffer, OutputLvl, GenerationOptions);

        //	int ChildListSize = ChildInternalNames.Size();
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

    /// <summary>
    /// Create a NodeTree for storing xml like layout info (alternative version that contains nodes holding other node lists)
    /// </summary>
    /// <typeparam name="NodeType">Either NodeV2 or a derivative.</typeparam>
    public class NodeTreeV2<NodeType>
    {
        public List<NodeType> RootNodes;

        public void LoadXMLData(string FileName)
        {
        }

        public List<string> GenerateXMLStringList()
        {
            List<string> LineDataList = new List<string>();
            return LineDataList;
        }

        public void Clear()
        {
            RootNodes.Clear();
        }
    }
}