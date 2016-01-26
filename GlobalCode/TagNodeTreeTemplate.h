/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagNodeTreeTemplate_IncludeGuard
#define TagNodeTreeTemplate_IncludeGuard

#include "LooseNodeTreeTemplate.h"
#include "XMLOption.h"

//Derivative of LooseNodeTree for XML style data (with TagContent etc)
namespace TagNodeTreeTemplateData
{
	//Send and share Data through Node optimization (less complicated detection of TagContent variable types)
	struct OptimizationData
	{
		std::string CurrentHavokClass = "";
		std::string CurrentActionDataSection_01 = "";
	};
	struct TagNodeFunctions
	{
		//************************************
		// Method:    FindContentType
		// FullName:  TagNodeTreeTemplateData::TagNodeFunctions::FindContentType
		// Access:    public static 
		// Returns:   size_t
		// Qualifier:
		// Parameter: std::string Content
		//************************************
		static size_t FindContentType(std::string Content);
		//************************************
		// Method:    ConvertStringToStringVectorList
		// FullName:  TagNodeTreeTemplateData::TagNodeFunctions::ConvertStringToStringVectorList
		// Access:    public static 
		// Returns:   StringVectorList
		// Qualifier:
		// Parameter: std::string Content
		//************************************
		static StringVectorList ConvertStringToStringVectorList(std::string Content);
	};
	struct TagNodeTreeSharedData
	{
		size_t TabLevel = 0;
	};
	class Node : public LooseNodeTreeTemplate::Node
	{
	public:
		//Internal Name of Tag Closing Tag Connected To
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
		//14:Havok Class Target Name (String)
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
		unsigned __int8 TagContentType = 0;
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
		void CopyOtherDataFromNode(Node* TargetNode)
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
		void DetectTagContentType()
		{
			if(TagContentType == 0 && TagContent != "")
			{
				TagContentType = TagNodeFunctions::FindContentType(TagContent);
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
		void DetectTagContentTypeV2(OptimizationData& SharedData)
		{
			if(NodeName == "hkparam"&&TagContentType != 0 && AdditionTagOptions.HasOption("name"))
			{
				std::string OptionName = AdditionTagOptions.GetOptionValue("name");
				if(OptionName == "enterEventId" || OptionName == "exitEventId"
					|| OptionName == "animationBindingIndex" //Not sure if refers to Event or Variable ID(Need to find some documentation or usage of something other than -1 to guess)
					|| OptionName == "id")//Id likely refers to Event Id but could refer to Variable ID
				{
					TagContentType = 5;//Event Index
				}
				else if(OptionName == "animationName")
				{
					TagContentType = 12;
				}
				else if(OptionName == "triggers" || OptionName == "enterNotifyEvents" || OptionName == "exitNotifyEvents" || OptionName == "transitions" || OptionName == "generator")
				{
					TagContentType = 14;
				}
				else if(OptionName == "mode")
				{
					TagContentType = 51;
				}
				else if(OptionName == "flags")
				{
					TagContentType = 50;
				}
				else if(OptionName == "cropStartAmountLocalTime" || OptionName == "cropEndAmountLocalTime"
					|| OptionName == "enterTime" || OptionName == "exitTime" || OptionName == "probability" || OptionName == "localTime"
					|| OptionName == "enforcedDuration" || OptionName == "userControlledTimeFraction" || OptionName == "duration"
					|| OptionName == "startTime" || OptionName == "playbackSpeed")
				{
					TagContentType = 3;
				}
				else if(OptionName == "stateId")
				{
					TagContentType = 1;
				}
				else if(OptionName == "up" || OptionName == "down")
				{
					TagContentType = 9;
				}
				else if(OptionName == "referenceFrameSamples")
				{
					TagContentType = 24;
				}
				else
				{
					TagContentType = TagNodeFunctions::FindContentType(TagContent);
				}
			}
			else if(NodeName == "hkobject"&&AdditionTagOptions.HasOption("signature"))//Detect if Current Node Is Havok Class
			{
				SharedData.CurrentHavokClass = AdditionTagOptions.GetOptionValue("class");
				if(TagContentType != 240) { TagContentType = 240; }
			}
			else if(NodeName == "hkobject"&&AdditionTagOptions.Size() == 0)
			{
				if(TagContentType != 241) { TagContentType = 241; }
			}
			else if(TagContentType == 0 && TagContent != "")
			{
				TagContentType = TagNodeFunctions::FindContentType(TagContent);
			}
		}
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
	};
	//NodeType = Node (Templated Node here)
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
	};
};
#endif