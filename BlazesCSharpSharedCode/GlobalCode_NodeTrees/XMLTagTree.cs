// ***********************************************************************
// Assembly         : BlazesCSharpSharedCode
// Author           : BlazesRus
// Created          : 07-14-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 07-23-2018
// ***********************************************************************
// <copyright file="XMLTagTree.cs" company="">
//     Copyright ©  2018
// </copyright>
// <summary></summary>
// ***********************************************************************
using CSharpSharedCode.ExperimentalCode;
using CSharpSharedCode.StringFunctions;
using CSharpSharedCode.VariableConversionFunctions;
using CSharpSharedCode.VariableLists;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSharedCode.SharedCode_NodeTrees
{
	/// <summary>
	/// Class XMLNode.
	/// Implements the <see cref="CSharpSharedCode.SharedCode_NodeTrees.NodeV2{CSharpSharedCode.SharedCode_NodeTrees.XMLTagTree, CSharpSharedCode.SharedCode_NodeTrees.XMLNode}" />
	/// </summary>
	/// <seealso cref="CSharpSharedCode.SharedCode_NodeTrees.NodeV2{CSharpSharedCode.SharedCode_NodeTrees.XMLTagTree, CSharpSharedCode.SharedCode_NodeTrees.XMLNode}" />
	public class XMLNode : NodeV2<XMLTagTree, XMLNode>
    {
		/// <summary>
		/// The node name
		/// </summary>
		public string NodeName = "";


		/// <summary>
		/// Detects if either Closing Tag, Closed Tag, or Neither<para/>
		/// 0 = Tag is not a Closing Tag<para/>
		/// 1 = Is Closing Tag<para/>
		/// 2 = Tag is Closed by Tag with InternalName of InternalNameOfTagClosed<para/>
		/// </summary>
		public byte ClosingStatus = 0;

		/// <summary>
		/// The tag content
		/// </summary>
		public string TagContent = "";

		/// <summary>
		/// The converted tag content
		/// </summary>
		public dynamic ConvertedTagContent = null;

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
		//14:Havok Class Target Name (String)
		//20:List<int>
		//21:DoubleList
		//22:StringList
		//23:BooleanList
		//24:QuadVectorList
		//50:flags (String)
		//51:Clip Mode (String)
		//240:Holds Havok Class info
		//241:hkobject Container
		//250:Unknown (String)
		/// <summary>
		/// The tag content type
		/// </summary>
		public byte TagContentType = 0;

		//Additional Tag Args
		/// <summary>
		/// The addition tag options
		/// </summary>
		public XMLOptionList AdditionTagOptions;

		/// <summary>
		/// The self contained tag
		/// </summary>
		public bool SelfContainedTag = false;

		/// <summary>
		/// The XML version tag
		/// </summary>
		public bool XMLVersionTag = false;

		/// <summary>
		/// Detects the type of the content contained within tag
		/// </summary>
		public void DetectTagContentType()
        {
            if (TagContentType == 0 && TagContent != "")
            {
                TagContentType = StringFunctions.FindContentType(TagContent);
                switch (TagContentType)
                {
                    case 1:
                    case 5:
                    case 6:
                    case 7:
                        ConvertedTagContent = VariableConversionFunctions.ReadIntFromString(TagContent);
                        break;

                    case 8:
                        ConvertedTagContent = VariableConversionFunctions.ReadShortFromString(TagContent);
                        break;

                    case 3:
                        ConvertedTagContent = (MediumDec)TagContent;
                        break;

                    case 9:
                        ConvertedTagContent = (QuadVector)TagContent;
                        break;

                    case 20:
                        ConvertedTagContent = (IntegerList)TagContent;
                        break;

                    case 21:
                        ConvertedTagContent = (MediumDecList)TagContent;
                        break;

                    case 22:
                        ConvertedTagContent = (StringList)TagContent;
                        break;

                    case 24:
                        ConvertedTagContent = (QuadVectorList)TagContent;
                        break;
                }
            }
        }

		/// <summary>
		/// Detect Tag Content of Node and child nodes
		/// </summary>
		public void DetectTagContentTypesWithin()
        {
            DetectTagContentType();
            int ChildListSize = this.NodeLists.Count;
            for (int Index = 0; Index < ChildListSize; ++Index)
            {
                this.NodeLists[Index].DetectTagContentTypesWithin();
            }
        }

		/// <summary>
		/// Generates the HTML document.
		/// </summary>
		/// <param name="HTMLForm">The HTML form.</param>
		/// <param name="OutputLvl">The output level.</param>
		/// <returns>StringList</returns>
		private StringList GenerateHTMLDoc(StringList HTMLForm, int OutputLvl)
        {
            string TempTag;
            int SizeTemp;
            TempTag = "<code>";
            TempTag += StringFunctions.CreateTabSpace(OutputLvl);
            TempTag += "<";
            if (ClosingStatus == 1)
            {
                TempTag += "/";
            }
            TempTag += NodeName;
            //Tag Option output
            SizeTemp = AdditionTagOptions.Count;
            XMLOption OptionTemp;
            for (int Index = 0; Index < SizeTemp; ++Index)
            {
                TempTag += " ";
                OptionTemp = AdditionTagOptions.ElementAt(Index);
                if (OptionTemp.ValueType == "None")
                {
                    TempTag += OptionTemp.OptionName;
                }
                else if (OptionTemp.ValueNotInParenthesis)
                {
                    TempTag += "=";
                    TempTag += OptionTemp.ValueString;
                }
                else
                {
                    TempTag += "=\"";
                    TempTag += OptionTemp.ValueString;
                    TempTag += "\"";
                }
            }
            if (SelfContainedTag)
            {
                TempTag += "/>";
                TempTag += "<br>"; HTMLForm.Add(TempTag);
            }
            else if (ClosingStatus != 1)
            {
                TempTag += ">";
                TempTag += "</code>";
                if (!((TagContentType >= 1 && TagContentType <= 14) || TagContentType == 252))
                {//Don't Separate line for known single-line Tags
                    TempTag += "<br>"; HTMLForm.Add(TempTag);
                    TempTag = "<code>";
                    TempTag += StringFunctions.CreateTabSpace(OutputLvl + 1);
                    TempTag += "</code>";
                }
                //Output TagContent
                //StringVectorList TempList;
                switch (TagContentType)
                {
                    case 14://Generate link to Havok class
                        {
                            TempTag += "<a href=\"#\"";
                            TempTag += TagContent;
                            TempTag += "\">";
                            TempTag += TagContent;
                            TempTag += "</a>";
                            break;
                        }
                    case 15://Generate linked Havok classes
                        {
                            StringList TempList = (StringList)TagContent;
                            SizeTemp = TempList.Count;
                            //Limit 16 entries a line
                            int LineIndex = 0;
                            for (int Index = 0; Index < SizeTemp; ++Index)
                            {
                                if (LineIndex == 16)
                                {
                                    TempTag += "<br>"; HTMLForm.Add(TempTag);
                                    TempTag = "<code>";
                                    TempTag += StringFunctions.CreateTabSpace(OutputLvl + 1);
                                    TempTag += "</code>";
                                    LineIndex = 0;
                                }
                                if (LineIndex != 0)
                                {
                                    TempTag += "<code> </code>";
                                }
                                TempTag += "<a href=\"#\"";
                                TempTag += TagContent;
                                TempTag += "\">";
                                TempTag += TagContent;
                                TempTag += "</a>";
                                ++LineIndex;
                            }
                            TempTag += "<br>"; HTMLForm.Add(TempTag);
                            TempTag = "<code>";
                            TempTag += StringFunctions.CreateTabSpace(OutputLvl + 1);
                            TempTag += "</code>";
                            break;
                        }
                    //case 5://Display index to Event with alt text of EventName (link to EventName)
                    //{
                    //	 int Index = StringFunctions.ReadXIntFromString(TempTag);
                    //	 string NameTemp = SharedData.TargetBHVTreePointer->VariableData.eventNames.ElementAt(Index);
                    //	TempTag += "<a href=\"#\"";
                    //	//Link to EventName here
                    //	TempTag += "eventNames_";
                    //	TempTag += StringFunctions.DoubleToStringConversion(Index);
                    //	TempTag += "\" title=\"";
                    //	//Mouse-Over Text of EventName
                    //	TempTag += NameTemp;
                    //	TempTag += "\">";
                    //	TempTag += TagContent;
                    //	TempTag += "</a>";
                    //	break;
                    //}
                    //case 6://Display index to variable with alt text
                    //{
                    //	 int Index = StringFunctions.ReadXIntFromString(TempTag);
                    //	 string NameTemp = SharedData.TargetBHVTreePointer->VariableData.variableNames.ElementAt(Index);
                    //	TempTag += "<a href=\"#\"";
                    //	//;//Link to EventName here
                    //	TempTag += "variableNames_";
                    //	TempTag += StringFunctions.DoubleToStringConversion(Index);
                    //	TempTag += "\" title=\"";
                    //	//Mouse-Over Text of EventName
                    //	TempTag += NameTemp;
                    //	TempTag += "\">";
                    //	TempTag += TagContent;
                    //	TempTag += "</a>";
                    //	break;
                    //}
                    case 252:
                        {
                            TempTag += "<a href=\"#\"";
                            TempTag += TagContent;
                            TempTag += "\">";
                            TempTag += TagContent;
                            TempTag += "</a>";
                            break;
                        }
                    default:
                        {
                            TempTag += TagContent;
                            TempTag += "<br>"; HTMLForm.Add(TempTag);
                            break;
                        }
                }
            }
            else
            {
                if (!((TagContentType >= 1 && TagContentType <= 14) || TagContentType == 252))
                {//Don't Separate line for known single-line Tags
                    TempTag += TagContent;
                    TempTag += "<br>"; HTMLForm.Add(TempTag);
                }
            }
            //}
            return HTMLForm;
        }

		/// <summary>
		/// Generates the HTML document within.
		/// </summary>
		/// <param name="HTMLForm">The HTML form.</param>
		/// <param name="OutputLvl">The output level.</param>
		/// <returns>StringList.</returns>
		public StringList GenerateHTMLDocWithin(StringList HTMLForm, int OutputLvl)
        {
            HTMLForm = GenerateHTMLDoc(HTMLForm, OutputLvl);
            int ChildListSize = this.NodeLists.Count;
            for (int Index = 0; Index < ChildListSize; ++Index)
            {
                HTMLForm = this.NodeLists[Index].GenerateHTMLDocWithin(HTMLForm, OutputLvl);
            }
            return HTMLForm;
        }

		/// <summary>
		/// Copies the other data from node of type CurrentType
		/// </summary>
		/// <param name="TargetNode">The target node.</param>
		public void CopyOtherDataFromNode(dynamic TargetNode)
        {//(Using Dynamic to prevent compiler errors)
            TagContent = TargetNode.TagContent;
            SelfContainedTag = TargetNode.SelfContainedTag;
            ClosingStatus = TargetNode.ClosingStatus;
            AdditionTagOptions = TargetNode.AdditionTagOptions;
            ConvertedTagContent = TargetNode.ConvertedTagContent;
            TagContentType = TargetNode.TagContentType;
        }

		/// <summary>
		/// Initializes a new instance of the <see cref="XMLNode"/> class.
		/// </summary>
		public XMLNode()
        {
            NodeLists = new List<XMLNode>();
        }
    }

	/// <summary>
	/// Class XMLTagTree.
	/// Implements the <see cref="CSharpSharedCode.SharedCode_NodeTrees.NodeTreeV2{CSharpSharedCode.SharedCode_NodeTrees.XMLNode}" />
	/// </summary>
	/// <seealso cref="CSharpSharedCode.SharedCode_NodeTrees.NodeTreeV2{CSharpSharedCode.SharedCode_NodeTrees.XMLNode}" />
	public class XMLTagTree : NodeTreeV2<XMLNode>
    {
		/// <summary>
		/// Generates the HTML document.
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <param name="AddHeaderInfo">if set to <c>true</c> [add header information].</param>
		public void GenerateHTMLDoc(string FileName, bool AddHeaderInfo = false)
        {
            StringList HTMLForm = new StringList();
            if (AddHeaderInfo)
            {
                HTMLForm.Add("<HTML>");
                HTMLForm.Add("/t<HEAD>");
                HTMLForm.Add("/t/t<TITLE>XML Tag Tree</TITLE>");
                HTMLForm.Add("/t</HEAD>");
                HTMLForm.Add("/t<BODY>");
            }
            int OutputLvl = AddHeaderInfo ? 2 : 0;
            int ChildListSize = this.RootNodes.Count;
            for (int Index = 0; Index < ChildListSize; ++Index)
            {
                HTMLForm = this.RootNodes[Index].GenerateHTMLDocWithin(HTMLForm, OutputLvl);
            }
            if (AddHeaderInfo)
            {
                HTMLForm.Add("/t</BODY>");
                HTMLForm.Add("</HTML>");
            }
            HTMLForm.SaveFileData(FileName);
        }

		/// <summary>
		/// Generates the HTML document.
		/// </summary>
		/// <param name="FileName">Name of the file.</param>
		/// <param name="AddHeaderInfo">if set to <c>true</c> [add header information].</param>
		/// <returns>StringList.</returns>
		public StringList GenerateHTMLStringList(string FileName, bool AddHeaderInfo = false)
        {
            StringList HTMLForm = new StringList();
            if (AddHeaderInfo)
            {
                HTMLForm.Add("<HTML>");
                HTMLForm.Add("/t<HEAD>");
                HTMLForm.Add("/t/t<TITLE>XML Tag Tree</TITLE>");
                HTMLForm.Add("/t</HEAD>");
                HTMLForm.Add("/t<BODY>");
            }
            int OutputLvl = AddHeaderInfo ? 2 : 0;
            int ChildListSize = this.RootNodes.Count;
            for (int Index = 0; Index < ChildListSize; ++Index)
            {
                HTMLForm = this.RootNodes[Index].GenerateHTMLDocWithin(HTMLForm, OutputLvl);
            }
            if (AddHeaderInfo)
            {
                HTMLForm.Add("/t</BODY>");
                HTMLForm.Add("</HTML>");
            }
            //HTMLForm.SaveDataToFileV3(FileName);
            return HTMLForm;
        }
    }
}