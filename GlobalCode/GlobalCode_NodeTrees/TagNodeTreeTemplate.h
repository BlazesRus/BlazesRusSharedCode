/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef TagNodeTreeTemplate_IncludeGuard
#define TagNodeTreeTemplate_IncludeGuard

#include "LooseNodeTreeTemplate.h"

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

//Derivative of LooseNodeTree for XML style data (with TagContent etc)
//Main additions from derived code -> to TagContent related code/variables
struct DLL_API TagNodeTreeTemplateData
{
	//Send and share Data through Node optimization (less complicated detection of TagContent variable types)
	struct OptimizationData
	{
		std::string CurrentHavokClass = "";
		std::string CurrentActionDataSection_01 = "";
	};
	struct TagNodeTreeSharedData
	{
		size_t TabLevel = 0;
	};
	//Node Template for TagNodeTreeTemplateData
	class Node : public LooseNodeTreeTemplate::Node
	{
	public:
		//Internal Name of Tag Closing Tag Connected To(Used for Destroying Closing Tag when destroying NodesWithin) 
		std::string InternalNameOfTagClosed = "";
		//Detects if either Closing Tag, Closed Tag, or Neither
		//0 = Tag is not a Closing Tag
		//1 = Is Closing Tag
		//2 = Tag is Closed by Tag with InternalName of InternalNameOfTagClosed
		unsigned __int8 ClosingStatus = 0;
		std::string TagContent = "";
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
		//15:Havok Class Target List (StringVectorList)
		//20:IntegerList
		//21:DoubleList
		//22:StringVectorList
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
		unsigned __int8 TagContentType = 0;
		//Additional Tag Args
		XMLOptionList AdditionTagOptions;
		bool SelfContainedTag = false;
		bool XMLVersionTag = false;
		bool UsingAlternativeTagContentStorage = false;
		//************************************
		// Method:    CopyOtherDataFromNode
		// FullName:  TagNodeTreeTemplateData::Node::CopyOtherDataFromNode
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: Node * TargetNode
		//************************************
		inline void CopyOtherDataFromNode(Node* TargetNode)
		{
			TagContent = TargetNode->TagContent;
			SelfContainedTag = TargetNode->SelfContainedTag;
			ClosingStatus = TargetNode->ClosingStatus;
			AdditionTagOptions = TargetNode->AdditionTagOptions;
		}
		//************************************
		// Method:    DetectTagContentType
		// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentType
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		inline void DetectTagContentType()
		{
			if(TagContentType == 0 && TagContent != "")
			{
				TagContentType = StringFunctions::FindContentType(TagContent);
			}
		}
		//************************************
		// Method:    DetectTagContentTypesWithin
		// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypesWithin
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: NodeTreeType & NodeTreeTarget
		//************************************
		template <typename NodeTreeType>
		void DetectTagContentTypesWithin(NodeTreeType* NodeTreeTarget)
		{
			std::string TargetNameTemp;
			Node* TargetNode;
			DetectTagContentType();
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->DetectTagContentTypesWithin(NodeTreeTarget);
				}
			}
		}
		//************************************
		// Alternative version of DetectTagContentType designed to use extra contents from hkparam tags as part of detection of ContentType
		// Method:    DetectTagContentTypeV2
		// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypeV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void DetectTagContentTypeV2(OptimizationData& SharedData);
		//************************************
		// Alternative version of DetectTagContentTypesWithin designed to use extra contents from hkparam tags as part of detection of ContentType
		// Method:    DetectTagContentTypesWithinV2
		// FullName:  TagNodeTreeTemplateData::Node::DetectTagContentTypesWithinV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		// Parameter: NodeTreeType & NodeTreeTarget
		// Parameter: OptimizationData & SharedData
		//************************************
		template <typename NodeTreeType>
		void DetectTagContentTypesWithinV2(NodeTreeType* NodeTreeTarget, OptimizationData& SharedData)
		{
			std::string TargetNameTemp;
			Node* TargetNode;
			DetectTagContentTypeV2(&SharedData);
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->DetectTagContentTypesWithinV2(NodeTreeTarget, SharedData);
				}
			}
		}
		//************************************
		// Method:    GenerateHTMLDoc
		// FullName:  TagNodeTreeTemplateData::Node::GenerateHTMLDoc
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: StringVectorList & OutputBuffer
		// Parameter: size_t & OutputLvl
		// Parameter: const unsigned __int8 & GenerationOptions
		//************************************
		void GenerateHTMLDoc(StringVectorList& OutputBuffer, size_t& OutputLvl, const unsigned __int8& GenerationOptions=0);
		//************************************
		// Method:    GenerateHTMLDocWithin
		// FullName:  TagNodeTreeTemplateData::Node::GenerateHTMLDocWithin
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: NodeTreeType * NodeTreeTarget
		// Parameter: StringVectorList & OutputBuffer
		// Parameter: size_t & OutputLvl
		// Parameter: const unsigned __int8 & GenerationOptions
		//************************************
		template <typename NodeTreeType>
		void GenerateHTMLDocWithin(NodeTreeType* NodeTreeTarget, StringVectorList& OutputBuffer, size_t& OutputLvl, const unsigned __int8& GenerationOptions=0)
		{
			std::string TargetNameTemp;
			Node* TargetNode;
			GenerateHTMLDoc(OutputBuffer, OutputLvl, GenerationOptions);
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = NodeTreeTarget->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->GenerateHTMLDocWithin(NodeTreeTarget, OutputBuffer, OutputLvl, GenerationOptions);
				}
			}
		}
	};
	//Node Template for TagNodeTreeTemplateData(NodeType = (Templated Node here))
	template <typename NodeType>
	class NodeTree : public LooseNodeTreeTemplate::NodeTree <NodeType>
	{
	public:
		//************************************
		// Works similar to old version of OptimizeTagContentWithinTree() function but without converting the TagContent
		// Method:    DetectTagContentTypesWithin
		// FullName:  TagNodeTreeTemplateData::NodeTree<NodeType>::DetectTagContentTypesWithin
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void DetectTagContentTypesWithin()
		{
			size_t SizeTemp = RootInternalNodes.Size();
			std::string TargetNameTemp;
			NodeType* TargetNode;
			OptimizationData SharedData;
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = RootInternalNodes.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					if(TargetNode->TagContentType == 0 && TargetNode->TagContent != "")
					{
						TargetNode->DetectTagContentTypesWithin(this, SharedData) < NodeTree > ;
					}
				}
			}
			SizeTemp = this->BaseLooseNode.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = BaseLooseNode.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					if(TargetNode->TagContentType == 0 && TargetNode->TagContent != "")
					{
						TargetNode->DetectTagContentTypesWithin(this, SharedData) < NodeTree > ;
					}
				}
			}
		}
		//************************************
		// Alternative version of DetectTagContentTypesWithin designed with most of old OptimizeContentWithin code within for easier detection of hkparam content types
		// Method:    DetectTagContentTypesWithinV2
		// FullName:  TagNodeTreeTemplateData::NodeTree<NodeType>::DetectTagContentTypesWithinV2
		// Access:    public
		// Returns:   void
		// Qualifier:
		//************************************
		void DetectTagContentTypesWithinV2()
		{
			size_t SizeTemp = RootInternalNodes.Size();
			std::string TargetNameTemp;
			NodeType* TargetNode;
			OptimizationData SharedData;
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = RootInternalNodes.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					if(TargetNode->TagContentType == 0 && TargetNode->TagContent != "")
					{
						TargetNode->DetectTagContentTypesWithinV2(this, &SharedData) < NodeTree > ;
					}
				}
			}
			SizeTemp = this->BaseLooseNode.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = BaseLooseNode.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					if(TargetNode->TagContentType == 0 && TargetNode->TagContent != "")
					{
						TargetNode->DetectTagContentTypesWithinV2(this) < NodeTree > ;
					}
				}
			}
		}
		//************************************
		// Method:    LoadDataFromXML
		// FullName:  TagNodeTreeTemplateData::NodeTree<NodeType>::LoadDataFromXML
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: std::string Filename
		//************************************
		void LoadDataFromXML(std::string Filename)
		{
			unsigned __int8 CommandStage = 0;
			//First part of command;Syntax:[ScriptArg01=ScriptArg02]
			std::string ScriptArg01;
			//Command Value;Syntax:[ScriptArg01=ScriptArg02]
			std::string ScriptArg02;
			//------------------------------------------------------------------------------------
			bool TagIsClosing = false;
			bool SelfContainedTag = false;
			bool SpecialXMLVersionTag = false;
			bool ArgHasNoValue = false;
			XMLOption TagArg;
			XMLOptionList TagArgments;
			//------------------------------------------------------------------------------------
			std::string LineString;
			int LineSize;
			char LineChar;
			bool InsideParenthesis = false;
			std::string TagNameTemp = "";
			bool TagNameHasArg02 = false;
			std::string TagNameArg02 = "";
			//-----------------------------------------------------------------------------------
			StringVectorList FileData;
			FileData.LoadXMLFileWithoutComments(FileName);
			for(size_t LineNumber = 0; FileData.StreamLineData(); ++LineNumber)
			{
				LineString = FileData.CurrentStreamedLineString();
				LineSize = LineString.length();
				for(size_t i = 0; i < LineSize; ++i)
				{
					LineChar = LineString.at(i);
					if(CommandStage == 1)
					{
						if(LineChar == '/')
						{
							TagIsClosing = true;
							CommandStage = 2;
						}
						else if(LineChar == '?')
						{
							CommandStage = 2;
							SpecialXMLVersionTag = true;
						}
						else if(LineChar == ' ' || LineChar == '\t' || LineChar == '\n')
						{
							//Whitespace
						}
						else
						{
							ScriptArg01 = LineChar;
							CommandStage = 2;
						}
					}
					else if(CommandStage == 0)
					{
						if(LineChar == '<')
						{
							ScriptArg01 = "";
							CommandStage = 1;
						}
						else
						{
							FixCurrentNodeData();
							if(CurrentNode != nullptr)
							{
								CurrentNode->TagContent += LineChar;
							}
						}
					}
					else if(CommandStage > 1)
					{
						if(LineChar == '"')//Scan for " to allow for Whitespace in values
						{
							InsideParenthesis = !InsideParenthesis;//Flips value of boolean
						}
						else if(LineChar == '/' || LineChar == '?')
						{
							SelfContainedTag = true;
						}
						else if(LineChar == '>')
						{
							CommandStage = 0;
						}
						else if(LineChar == '=')
						{
							CommandStage = 3;
						}
						else if(CommandStage == 3)
						{
							if(InsideParenthesis == false && (LineChar == ' ' || LineChar == '\t' || LineChar == '\n'))
							{
								if(ScriptArg02 != "")
								{
									CommandStage = 7;
								}
							}
							else
							{
								ScriptArg02 += LineChar;
							}
						}
						else
						{
							if(InsideParenthesis == false && (LineChar == ' ' || LineChar == '\t' || LineChar == '\n'))
							{
								if(ScriptArg01 != "")
								{
									ArgHasNoValue = true;
									CommandStage = 7;
								}
							}
							else
							{
								ScriptArg01 += LineChar;
							}
						}
						if(CommandStage == 0)
						{
							//Execute Commands
							if(Size() == 0)
							{
								AddMenuItemData("(Core)", "", TagNameTemp);
							}
							else if(SelfContainedTag)
							{
								AddMenuItemData("(LastItem)", "", TagNameTemp);
								CurrentNode->SelfContainedTag = true;
							}
							else if(TagIsClosing)
							{
								AddMenuItemData("(LastItem)", "AddToParentNode", TagNameTemp);
								CurrentNode->ClosingStatus = true;
							}
							else
							{
								AddMenuItemData("(LastItem)", "AddSubItem", TagNameTemp);
							}
							CurrentNode->AdditionTagOptions = TagArgments;
							if(SpecialXMLVersionTag)
							{
								CurrentNode->XMLVersionTag = true;
							}
							//Reset Temporary Values
							TagArgments.Reset();
							SelfContainedTag = false;
							TagIsClosing = false;
							SpecialXMLVersionTag = false;
						}
						else if(CommandStage == 7)
						{
							if(TagNameTemp == "")
							{
								if(ArgHasNoValue == false)
								{
									TagNameHasArg02 = true;
								}
								else
								{
									TagNameArg02 = ScriptArg02;
								}
								TagNameTemp = ScriptArg01;
							}
							else
							{
								TagArg.OptionName = ScriptArg01;
								if(ArgHasNoValue)
								{
									TagArg.ValueType = "None";
								}
								else
								{
									TagArg.ValueString = ScriptArg02;
								}
								TagArgments.Add(TagArg);
								TagArg.ValueType = "";
								TagArg.ValueString = "";
							}
							//Look for Next Arg
							CommandStage = 2;
						}
					}
				}
			}
		}
		//************************************
		// Method:    GenerateHTMLDoc
		// FullName:  TagNodeTreeTemplateData::NodeTree<NodeType>::GenerateHTMLDoc
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: StringVectorList & FileStreamString
		// Parameter: size_t & TabLevel
		// Parameter: const unsigned __int8 GenerationOptions
		//************************************
		void GenerateHTMLDoc(StringVectorList& FileStreamString, size_t& TabLevel, const unsigned __int8 GenerationOptions=0)
		{
			std::string TempString;
			NodeType* NodePointer;
			const size_t SizeTemp = RootInternalNodes.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TempString = RootInternalNodes.ElementAt(Index);
				NodePointer = GetNodePointerFromInternalName(TempString);
				NodePointer->GenerateHTMLDocWithin(this, FileStreamString, TabLevel, GenerationOptions);
			}
		}
		//************************************
		// GenerationOptions:
		// 0 = Default
		// Method:    GenerateHTMLDoc
		// FullName:  TagNodeTreeTemplateData::NodeTree<NodeType>::GenerateHTMLDoc
		// Access:    public 
		// Returns:   void
		// Qualifier:
		// Parameter: std::string FileName
		// Parameter: bool AddHeaderInfo
		// Parameter: unsigned __int8 GenerationOptions
		//************************************
		void GenerateHTMLDoc(const std::string FileName, bool AddHeaderInfo=false, const unsigned __int8 GenerationOptions=0)
		{
			StringVectorList HTMLForm;
			if(AddHeaderInfo)
			{
				HTMLForm.Add("<HTML>");
				HTMLForm.Add("/t<HEAD>");
				HTMLForm.Add("/t/t<TITLE>HkClass Usage Data</TITLE>");
				HTMLForm.Add("/t</HEAD>");
				HTMLForm.Add("/t<BODY>");
			}
			size_t OutputLvl;
			if(AddHeaderInfo){OutputLvl = 2;}
			else { OutputLvl = 0; }
			std::string TempString;
			NodeType* NodePointer;
			const size_t SizeTemp = RootInternalNodes.Size();
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TempString = RootInternalNodes.ElementAt(Index);
				NodePointer = GetNodePointerFromInternalName(TempString);
				NodePointer->GenerateHTMLDocWithin(this, HTMLForm, OutputLvl, GenerationOptions);
			}
			if(AddHeaderInfo)
			{
				HTMLForm.Add("/t</BODY>");
				HTMLForm.Add("</HTML>");
			}
			HTMLForm.SaveDataToFileV3(FileName);
		}
	};
};
#endif
