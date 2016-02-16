/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagTreeData_IncludeGuard
#define TagTreeData_IncludeGuard

#include "TagNodeTreeTemplate.h"
#include "XMLOption.h"
#include "..\BlazesBehaviorFileMerger\HkBhvNodeTree.h"
#include "QuadVectorFunctions.h"

namespace TagTreeData
{
	class TagTree;
	class TagNode : public TagNodeTreeTemplateData::Node
	{
	public:
		/* loosely connected functions for HkBhvNodeData.h*/
		//void StreamDataToBHVTree(HkBhvNodeData::HkBhvNodeTree* TargetBHVTree, HkBhvNodeData::BHVTreeSharedData& SharedData)
		template <typename BHVTreeType, typename BHVTreeSharedDataType>
		void StreamDataToBHVTree(TagTree* TargetNodeTree, BHVTreeType* TargetBHVTreePointer, BHVTreeSharedDataType& SharedData)
		{
			TargetBHVTree->FixCurrentNodeData();
			std::string TemporaryInternalName;
			if(SelfContainedTag)
			{
				TargetBHVTree->AddMenuItemData("(LastItem)", "AddSubItem", NodeName);
				TargetBHVTree->CurrentNode->SelfContainedTag = true;
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += TargetBHVTree->CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = TargetBHVTree->GenerateUnusedInternalName(TemporaryInternalName);
				TargetBHVTree->CurrentNode->InternalName = TemporaryInternalName;
				TargetBHVTree->CurrentNode->AdditionTagOptions = AdditionTagOptions;
				TargetBHVTree->CurrentNode->XMLVersionTag = XMLVersionTag;
			}
			else if(ClosingStatus == 1)
			{
				TargetBHVTree->AddMenuItemData("(LastItem)", "AddToParentNode", NodeName);
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += TargetBHVTree->CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = TargetBHVTree->GenerateUnusedInternalName(TemporaryInternalName);
				TargetBHVTree->CurrentNode->InternalName = TemporaryInternalName;
				if(TargetBHVTree->CurrentNode->ParentInternalName == "(Core)")
				{
					SharedData.CurrentDataType = 0;
					TargetBHVTree->CurrentNode->InternalNameOfTagClosed = SharedData.CurrentHavokClassInternalName;
					TargetBHVTree->CurrentNode->TagContentType = 242;
				}
			}
			else
			{
				TargetBHVTree->AddMenuItemData("(LastItem)", "AddSubItem", NodeName);
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += TargetBHVTree->CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = TargetBHVTree->GenerateUnusedInternalName(TemporaryInternalName);
				TargetBHVTree->CurrentNode->InternalName = TemporaryInternalName;
				TargetBHVTree->CurrentNode->CopyOtherDataFromNode(this);
			}
		}
		////BHVTreeType = HkBhvNodeData::HkBhvNodeTree
		//void CreateBHVTree(HkBhvNodeData::HkBhvNodeTree* TargetBHVTree, HkBhvNodeData::BHVTreeSharedData& SharedData)
		//{
		template <typename BHVTreeType, typename BHVTreeSharedDataType>
		void CreateBHVTree(TagTree* TargetNodeTree, BHVTreeType* TargetBHVTreePointer, BHVTreeSharedDataType& SharedData)
		{
			TagNode* NodePointer = nullptr;
			int NodeListSize;
			if(NodeName == "hkobject"&&AdditionTagOptions.HasOption("signature"))//Detect if Current Node Is Havok Class
			{
				SharedData.CurrentHavokClass = AdditionTagOptions.GetOptionValue("class");
				if(SharedData.CurrentHavokClass == "hkbBehaviorGraphStringData")
				{
					SharedData.CurrentDataType = 1;
					SharedData.CommandStage = 0;
					TargetBHVTree->VariableData.StringDataName = AdditionTagOptions.GetOptionValue("name");
					TargetBHVTree->VariableData.StringDataSignature = AdditionTagOptions.GetOptionValue("signature");
				}
				else if(SharedData.CurrentHavokClass == "hkbVariableValueSet")
				{
					SharedData.CurrentDataType = 1;
					SharedData.CommandStage = 0;
					TargetBHVTree->VariableData.ValueDataName = AdditionTagOptions.GetOptionValue("name");
					TargetBHVTree->VariableData.ValueDataSignature = AdditionTagOptions.GetOptionValue("signature");
				}
				else if(SharedData.CurrentHavokClass == "hkbBehaviorGraphData")
				{
					SharedData.CurrentDataType = 1;
					SharedData.CommandStage = 0;
					TargetBHVTree->VariableData.TypeDataName = AdditionTagOptions.GetOptionValue("name");
					TargetBHVTree->VariableData.TypeDataSignature = AdditionTagOptions.GetOptionValue("signature");
				}
				else
				{
					SharedData.CurrentDataType = 20;
					std::string Name = AdditionTagOptions.GetOptionValue("name");
					std::string Class = SharedData.CurrentHavokClass;
					std::string Signature = AdditionTagOptions.GetOptionValue("signature");
					TargetBHVTree->AddMenuItemData("(Core)", "", "hkobject");
					TargetBHVTree->CurrentNode->InternalName = Name;
					SharedData.CurrentHavokClassInternalName = Name;
					TargetBHVTree->CurrentNode->AdditionTagOptions.AddOption("name", Name);
					TargetBHVTree->CurrentNode->AdditionTagOptions.AddOption("class", Class);
					TargetBHVTree->CurrentNode->AdditionTagOptions.AddOption("signature", Signature);
				}
			}
			else if(NodeName == "hkpackfile"&&AdditionTagOptions.Size() > 0)
			{
				if(AdditionTagOptions.HasOption("toplevelobject"))
				{
					TargetBHVTree->hkpack_toplevelobject = AdditionTagOptions.GetOptionValue("toplevelobject");
				}
				if(AdditionTagOptions.HasOption("classversion"))
				{
					TargetBHVTree->hkpack_classversion = AdditionTagOptions.GetOptionValue("classversion");
				}
				if(AdditionTagOptions.HasOption("contentsversion"))
				{
					TargetBHVTree->hkpack_contentsversion = AdditionTagOptions.GetOptionValue("contentsversion");
				}
			}
			else if(SharedData.CurrentDataType != 0)
			{
				std::string CurrentHavokClass = SharedData.CurrentHavokClass;
				if(CurrentHavokClass == "hkbBehaviorGraphStringData")
				{
					if(SharedData.CurrentDataType == 1)
					{
						if(NodeName == "hkobject"&&ClosingStatus == 1)
						{
							SharedData.CurrentDataType = 0;
						}
						else if(NodeName == "hkparam"&&AdditionTagOptions.HasOption("name"))
						{
							string ParamName = AdditionTagOptions.GetOptionValue("name");
							if(ParamName == "eventNames")
							{
								SharedData.CurrentDataType = 2;
							}
							else if(ParamName == "attributeNames")
							{
								SharedData.CurrentDataType = 3;
							}
							else if(ParamName == "variableNames")
							{
								SharedData.CurrentDataType = 4;
							}
							else if(ParamName == "characterPropertyNames")
							{
								SharedData.CurrentDataType = 5;
							}
							else
							{
								std::cout << "Error:Unknown hkparam named " << ParamName << " found. Skipping data. May encounter future errors in scan as result.\n";
							}
						}
					}
					else
					{
						if(NodeName == "hkparam"&&ClosingStatus == 1)
						{
							SharedData.CurrentDataType = 1;
						}
						else if(NodeName == "hkcstring")
						{
							if(SharedData.CurrentDataType == 2)
							{
								TargetBHVTree->VariableData.eventNames.Add(TagContent);
							}
							else if(SharedData.CurrentDataType == 4)
							{
								TargetBHVTree->VariableData.variableNames.Add(TagContent);
							}
							else if(SharedData.CurrentDataType == 3)
							{
								TargetBHVTree->VariableData.attributeNames.Add(TagContent);
							}
							else if(SharedData.CurrentDataType == 5)
							{
								TargetBHVTree->VariableData.characterPropertyNames.Add(TagContent);
							}
						}
					}
				}
				else if(CurrentHavokClass == "hkbVariableValueSet")
				{
					if(SharedData.CurrentDataType == 1)
					{
						if(NodeName == "hkobject"&&ClosingStatus == 1)
						{
							SharedData.CurrentDataType = 0;
						}
						else if(NodeName == "hkparam"&&AdditionTagOptions.HasOption("name"))
						{
							string ParamName = AdditionTagOptions.GetOptionValue("name");
							if(ParamName == "wordVariableValues")
							{
								SharedData.CurrentDataType = 6;
								SharedData.CommandStage = 0;
							}
							else if(ParamName == "quadVariableValues")
							{
								SharedData.CurrentDataType = 7;
								TargetBHVTree->VariableData.quadVariableValues = QuadVectorFunctions::ReadQuadVectorListFromString(TagContent);
							}
							else if(ParamName == "variantVariableValues")
							{
								SharedData.CurrentDataType = 8;
								TargetBHVTree->VariableData.variantVariableValues_size = StringFunctions::ReadIntFromString(AdditionTagOptions.GetOptionValue("numelements"));
								TargetBHVTree->VariableData.variantVariableValues.CreateUnknownTagNodeTree(SharedData, this);
							}
							else
							{
								std::cout << "Error:Unknown hkparam named " << ParamName << " found. Skipping data. May encounter future errors in scan as result.\n";
							}
						}
					}
					else
					{
						if(SharedData.CurrentDataType == 6)
						{
							if(SharedData.CommandStage == 0)
							{
								if(NodeName == "hkparam")
								{
									SharedData.CommandStage = 1;
								}
								else if(NodeName == "hkobject"&&ClosingStatus == 1) { SharedData.CurrentDataType = 1; }
							}
							else if(SharedData.CommandStage == 1)
							{
								if(NodeName == "hkobject"&&ClosingStatus == 1)
								{
									SharedData.CommandStage = 0;
								}
								else if(NodeName == "hkparam")//&&AdditionTagOptions.HasOption("name")
								{
									TargetBHVTree->VariableData.wordVariableValues.Add(StringFunctions::ReadIntFromString(TagContent));
									SharedData.CommandStage = 2;
								}
							}
							else if(SharedData.CommandStage == 2)
							{
								if(NodeName == "hkparam"&&ClosingStatus == 1) { SharedData.CommandStage = 1; }
							}
						}
						else if(SharedData.CurrentDataType == 7)
						{
							if(NodeName == "hkparam"&&ClosingStatus == 1) { SharedData.CurrentDataType = 1; }
						}
						else if(SharedData.CurrentDataType == 8)
						{
							TargetBHVTree->VariableData.variantVariableValues.StreamNodeDataWithin(SharedData, this);
						}
					}
				}
				else if(CurrentHavokClass == "hkbBehaviorGraphData")
				{
					if(SharedData.CurrentDataType == 1)
					{
						if(NodeName == "hkobject"&&ClosingStatus == 1)
						{
							SharedData.CurrentDataType = 0;
						}
						else if(NodeName == "hkparam"&&AdditionTagOptions.HasOption("name"))
						{
							string ParamName = AdditionTagOptions.GetOptionValue("name");
							if(ParamName == "attributeDefaults")
							{
								SharedData.CurrentDataType = 9;
								TargetBHVTree->VariableData.attributeDefaults_size = StringFunctions::ReadIntFromString(AdditionTagOptions.GetOptionValue("numelements"));
								TargetBHVTree->VariableData.attributeDefaults.CreateUnknownTagNodeTree(SharedData, this);
							}
							else if(ParamName == "variableInfos")
							{
								SharedData.CurrentDataType = 10;
								SharedData.CommandStage = 0;
							}
							else if(ParamName == "characterPropertyInfos")
							{
								SharedData.CurrentDataType = 11;
								SharedData.CommandStage = 0;
							}
							else if(ParamName == "eventInfos")
							{
								SharedData.CurrentDataType = 12;
								SharedData.CommandStage = 0;
							}
							else if(ParamName == "wordMinVariableValues")
							{
								SharedData.CurrentDataType = 13;
								TargetBHVTree->VariableData.wordMinVariableValues_size = StringFunctions::ReadIntFromString(AdditionTagOptions.GetOptionValue("numelements"));
								TargetBHVTree->VariableData.wordMinVariableValues.CreateUnknownTagNodeTree(SharedData, this);
							}
							else if(ParamName == "wordMaxVariableValues")
							{
								SharedData.CurrentDataType = 14;
								TargetBHVTree->VariableData.wordMaxVariableValues_size = StringFunctions::ReadIntFromString(AdditionTagOptions.GetOptionValue("numelements"));
								TargetBHVTree->VariableData.wordMaxVariableValues.CreateUnknownTagNodeTree(SharedData, this);
							}
							else if(ParamName == "variableInitialValues")
							{
								SharedData.CurrentDataType = 15;
								TargetBHVTree->VariableData.variableInitialValues = TagContent;
							}
							else if(ParamName == "stringData")
							{
								SharedData.CurrentDataType = 16;
								TargetBHVTree->VariableData.stringData = TagContent;
							}
							else
							{
								std::cout << "Error:Unknown hkparam named " << ParamName << " found. Skipping data. May encounter future errors in scan as result.\n";
							}
						}
					}
					else
					{
						if(SharedData.CurrentDataType == 9)
						{
							TargetBHVTree->VariableData.attributeDefaults.StreamNodeDataWithin(SharedData, this);
						}
						else if(SharedData.CurrentDataType == 10 || SharedData.CurrentDataType == 11)
						{
							if(SharedData.CommandStage == 0)
							{
								if(NodeName == "hkobject")
								{
									SharedData.CommandStage = 1;
								}
							}
							else if(SharedData.CommandStage == 1)
							{
								if(NodeName == "hkobject"&&ClosingStatus == 1)
								{
									SharedData.CommandStage = 0;
								}
								else if(NodeName == "hkparam"&&AdditionTagOptions.HasOption("name"))
								{
									string ParamName = AdditionTagOptions.GetOptionValue("name");
									if(ParamName == "role")
									{
										SharedData.CommandStage = 2;
									}
									else if(ParamName == "type")
									{
										SharedData.CommandStage = 5;
										if(SharedData.CurrentDataType == 10)
										{
											TargetBHVTree->VariableData.variableInfos_types.Add(TagContent);
										}
										else
										{
											TargetBHVTree->VariableData.characterPropertyInfos_types.Add(TagContent);
										}
									}
								}
							}
							else if(SharedData.CommandStage == 2)
							{
								if(NodeName == "hkobject")
								{
									SharedData.CommandStage = 3;
								}
								else if(NodeName == "hkparam"&&ClosingStatus == 1) { SharedData.CurrentDataType = 1; }
							}
							else if(SharedData.CommandStage == 3)
							{
								if(NodeName == "hkobject"&&ClosingStatus == 1) { SharedData.CommandStage = 3; }
								else if(NodeName == "hkparam"&&AdditionTagOptions.HasOption("name"))
								{
									string ParamName = AdditionTagOptions.GetOptionValue("name");
									if(ParamName == "role")
									{
										if(SharedData.CurrentDataType == 10)
										{
											TargetBHVTree->VariableData.variableInfos_Role.Add(TagContent);
										}
										else
										{
											TargetBHVTree->VariableData.characterPropertyInfos_Role.Add(TagContent);
										}
									}
									else if(ParamName == "flags")
									{
										if(SharedData.CurrentDataType == 10)
										{
											TargetBHVTree->VariableData.variableInfos_flags.Add(TagContent);
										}
										else
										{
											TargetBHVTree->VariableData.characterPropertyInfos_flags.Add(TagContent);
										}
									}
									else
									{
										std::cout << "Error invalid param!\n";
									}
									SharedData.CommandStage = 4;
								}
							}
							else if(SharedData.CommandStage == 4)
							{
								if(NodeName == "hkparam")
								{
									SharedData.CommandStage = 3;
								}
							}
							else if(SharedData.CommandStage == 5)
							{
								if(NodeName == "hkparam")
								{
									SharedData.CommandStage = 0;
								}
							}
						}
						else if(SharedData.CurrentDataType == 12)
						{
							if(SharedData.CommandStage == 0)
							{
								if(NodeName == "hkobject")
								{
									SharedData.CommandStage = 1;
								}
							}
							else if(SharedData.CommandStage == 1)
							{
								if(NodeName == "hkobject"&&ClosingStatus == 1) { SharedData.CommandStage = 0; }
								else if(NodeName == "hkparam")
								{
									TargetBHVTree->VariableData.eventInfos.Add(TagContent);
									SharedData.CommandStage = 2;
								}
							}
							else if(SharedData.CommandStage == 2)
							{
								if(NodeName == "hkparam"&&ClosingStatus == 1) { SharedData.CommandStage = 1; }
							}
						}
						else if(SharedData.CurrentDataType == 13)
						{
							TargetBHVTree->VariableData.wordMinVariableValues.StreamNodeDataWithin(SharedData, this);
						}
						else if(SharedData.CurrentDataType == 14)
						{
							TargetBHVTree->VariableData.wordMaxVariableValues.StreamNodeDataWithin(SharedData, this);
						}
						else if(SharedData.CurrentDataType == 15 || SharedData.CurrentDataType == 16)
						{
							if(NodeName == "hkparam"&&ClosingStatus == 1) { SharedData.CurrentDataType = 1; }
						}
					}
				}
				else
				{
					StreamDataToBHVTree(TargetBHVTree, SharedData);
				}
			}
		}
		//BHVTreeType = HkBhvNodeData::HkBhvNodeTree
		template <typename BHVTreeType, typename BHVTreeSharedDataType>
		void CreateBHVTreeWithin(TagTree* TargetNodeTree, BHVTreeType* TargetBHVTree, BHVTreeSharedDataType& SharedData)
		{
			std::string TargetNameTemp;
			TagNode* TargetNode;
			CreateBHVTree(TargetBHVTree, SharedData);
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = TargetNodeTree->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->CreateBHVTreeWithin(TargetNodeTree, TargetBHVTree, SharedData);
				}
			}
		}
		void HkConstructFileFromData(HkBhvNodeData::ConstructionData& SharedData)
		//template <typename ConstructionDataType>
		//void HkConstructFileFromData(ConstructionDataType& SharedData)
		{
			std::string TempTag = StringFunctions::CreateTabSpace(SharedData.TabLevel);
			TempTag += "<";
			size_t ListSize;
			if(ClosingStatus)
			{
				TempTag += "/";
			}
			TempTag += NodeName;
			ListSize = AdditionTagOptions.Size();
			if(ListSize > 0)
			{//separate pointer for Tag Options into its own local space so frees up memory space after
				XMLOption* TagOption = nullptr;
				for(size_t TagIndex = 0; TagIndex < ListSize; ++TagIndex)
				{
					TempTag += " ";
					TagOption = AdditionTagOptions.GetElementPointerV2(TagIndex);
					TempTag += TagOption->OptionName;
					if(TagOption->ValueType != "None" && TagOption->ValueType != "[[NULL-VALUE]]")
					{
						TempTag += "=";
						if(!TagOption->ValueNotInParenthesis)
						{
							TempTag += "\"";
						}
						TempTag += TagOption->ValueString;
						if(!TagOption->ValueNotInParenthesis)
						{
							TempTag += "\"";
						}
					}
				}
			}
			TempTag += ">";
			//if(UsingAlternativeTagContentStorage)
			//{//Need alternative TagContent Types enabled for this
			//	//if(TagContentType == 1 || TagContentType == 5 || TagContentType == 6 || TagContentType == 7)
			//	//{
			//	//	TempTag += StringFunctions::IntToStringConversion(TagContent_Int);
			//	//}
			//	//else if(TagContentType == 2)
			//	//{
			//	//	if(TagContent_Bool)
			//	//	{
			//	//		TempTag += "true";
			//	//	}
			//	//	else
			//	//	{
			//	//		TempTag += "false";
			//	//	}
			//	//}
			//	//else if(TagContentType == 3)
			//	//{
			//	//	TempTag += StringFunctions::DoubleToStringConversion(TagContent_Double);
			//	//}
			//	//else if(TagContentType == 9)
			//	//{
			//	//	TempTag += TagContent_QuadVector.ConvertToString();
			//	//}
			//	//else if(TagContentType == 24)
			//	//{
			//	//	ListSize = TagContent_QuadVectorList.Size();
			//	//	SharedData.TabLevel++;
			//	//	TempTag += "\n";
			//	//	QuadVector* ElementPointer = nullptr;
			//	//	for(size_t ListIndex = 0; ListIndex < ListSize; ++ListIndex)
			//	//	{
			//	//		TempTag += StringFunctions::CreateTabSpace(SharedData.TabLevel);
			//	//		ElementPointer = TagContent_QuadVectorList.GetElementPointerV2(ListIndex);
			//	//		TempTag += ElementPointer->ConvertToString();
			//	//		TempTag += "\n";
			//	//	}
			//	//	SharedData.TabLevel--;
			//	//}
			//	//else if(TagContentType == 22)
			//	//{
			//	//	ListSize = TagContent_StringList.Size();
			//	//	SharedData.TabLevel++;
			//	//	TempTag += "\n";
			//	//	//16 per line
			//	//	unsigned int ElementBuffer = 0;
			//	//	for(size_t ListIndex = 0; ListIndex < ListSize; ListIndex++)
			//	//	{
			//	//		TempTag += StringFunctions::CreateTabSpace(SharedData.TabLevel);
			//	//		if(ElementBuffer != 0)
			//	//		{
			//	//			TempTag += " ";
			//	//		}
			//	//		TempTag += TagContent_StringList.ElementAt(ListIndex);
			//	//		ElementBuffer++;
			//	//		if(ElementBuffer == 16)
			//	//		{
			//	//			TempTag += "\n";
			//	//			ElementBuffer = 0;
			//	//		}
			//	//	}
			//	//	if(ElementBuffer != 0)
			//	//	{
			//	//		TempTag += "\n";
			//	//	}
			//	//	SharedData.TabLevel--;
			//	//}
			//	//else if(TagContentType == 20)
			//	//{
			//	//	ListSize = TagContent_IntList.Size();
			//	//	SharedData.TabLevel++;
			//	//	TempTag += "\n";
			//	//	//16 per line
			//	//	unsigned int ElementBuffer = 0;
			//	//	for(unsigned int ListIndex = 0; ListIndex < ListSize; ListIndex++)
			//	//	{
			//	//		TempTag += StringFunctions::CreateTabSpace(SharedData.TabLevel);
			//	//		if(ElementBuffer != 0)
			//	//		{
			//	//			TempTag += " ";
			//	//		}
			//	//		TempTag += StringFunctions::IntToStringConversion(TagContent_IntList.ElementAt(ListIndex));
			//	//		ElementBuffer++;
			//	//		if(ElementBuffer == 16)
			//	//		{
			//	//			TempTag += "\n";
			//	//			ElementBuffer = 0;
			//	//		}
			//	//	}
			//	//	if(ElementBuffer != 0)
			//	//	{
			//	//		TempTag += "\n";
			//	//	}
			//	//	SharedData.TabLevel--;
			//	//}
			//	//else if(TagContentType == 21)
			//	//{
			//	//	ListSize = TagContent_DoubleList.Size();
			//	//	SharedData.TabLevel++;
			//	//	TempTag += "\n";
			//	//	//16 per line
			//	//	unsigned int ElementBuffer = 0;
			//	//	for(unsigned int ListIndex = 0; ListIndex < ListSize; ListIndex++)
			//	//	{
			//	//		TempTag += StringFunctions::CreateTabSpace(SharedData.TabLevel);
			//	//		if(ElementBuffer != 0)
			//	//		{
			//	//			TempTag += " ";
			//	//		}
			//	//		TempTag += StringFunctions::DoubleToStringConversion(TagContent_DoubleList.ElementAt(ListIndex));
			//	//		ElementBuffer++;
			//	//		if(ElementBuffer == 16)
			//	//		{
			//	//			TempTag += "\n";
			//	//			ElementBuffer = 0;
			//	//		}
			//	//	}
			//	//	if(ElementBuffer != 0)
			//	//	{
			//	//		TempTag += "\n";
			//	//	}
			//	//	SharedData.TabLevel--;
			//	//}
			//	//else if(TagContentType == 23)
			//	//{
			//	//	ListSize = TagContent_BoolList.Size();
			//	//	SharedData.TabLevel++;
			//	//	TempTag += "\n";
			//	//	//16 per line
			//	//	unsigned int ElementBuffer = 0;
			//	//	for(unsigned int ListIndex = 0; ListIndex < ListSize; ListIndex++)
			//	//	{
			//	//		TempTag += StringFunctions::CreateTabSpace(SharedData.TabLevel);
			//	//		if(ElementBuffer != 0)
			//	//		{
			//	//			TempTag += " ";
			//	//		}
			//	//		if(TagContent_BoolList.ElementAt(ListIndex))
			//	//		{
			//	//			TempTag += "true";
			//	//		}
			//	//		else
			//	//		{
			//	//			TempTag += "false";
			//	//		}
			//	//		ElementBuffer++;
			//	//		if(ElementBuffer == 16)
			//	//		{
			//	//			TempTag += "\n";
			//	//			ElementBuffer = 0;
			//	//		}
			//	//	}
			//	//	if(ElementBuffer != 0)
			//	//	{
			//	//		TempTag += "\n";
			//	//	}
			//	//	SharedData.TabLevel--;
			//	//}
			//	//else
			//	//{
			//	//	TempTag += TagContent;
			//	//}
			//}
			//else
			//{
				TempTag += TagContent;
			//}
			if(SharedData.TargetFile != "")
			{
				SharedData.TargetLineBuffer += TempTag;
			}
		}

		void HkConstructFileWithinFromData(TagTree* TargetTagTree, HkBhvNodeData::ConstructionData& SharedData)
		{
			std::string TargetNameTemp;
			TagNode* TargetNode;
			HkConstructFileFromData(SharedData);
			const size_t ChildListSize = ChildInternalNames.Size();
			for(size_t Index = 0; Index < ChildListSize; ++Index)
			{
				TargetNameTemp = ChildInternalNames.ElementAt(Index);
				TargetNode = TargetTagTree->GetNodePointerFromInternalName(NodeName);
				if(TargetNode != nullptr)
				{
					TargetNode->HkConstructFileWithinFromData(TargetTagTree, SharedData);
				}
			}
		}


		/*End of Loosely connected functions for HkBhvNodeData.h*/
	};
	class TagTree : public TagNodeTreeTemplateData::NodeTree <TagNode>
	{
	public:
		/* loosely connected functions for HkBhvNodeData.h*/
		//void CreateUnknownTagNodeTree(HkBhvNodeData::BHVTreeSharedData& SharedData, TagNode* TargetNode)
		template <typename BHVTreeSharedDataType>
		void CreateUnknownTagNodeTree(BHVTreeSharedDataType& SharedData, TagNode* TargetNode)
		{
			if(TargetNode->AdditionTagOptions.HasOption("numelements"))
			{
				std::string ElementsInfo = TargetNode->AdditionTagOptions.GetOptionValue("numberelements");
				if(ElementsInfo == "0")
				{
					SharedData.ContainsNodesWithin = false;
				}
				else
				{
					SharedData.ContainsNodesWithin = true;
				}
			}
			else
			{
				SharedData.ContainsNodesWithin = false;
			}
			//AddMenuItemData("(Core)", "", "hkparam");
			AddMenuItemData("(Core)", "", TargetNode->NodeName);
			CurrentNode->AdditionTagOptions = TargetNode->AdditionTagOptions;
			//if(TargetNode->TagContentType == 0)
			//{
			CurrentNode->TagContent = TargetNode->TagContent;
			//}
		}
		//void StreamDataToTagNodeTree(HkBhvNodeData::BHVTreeSharedData& SharedData, TagNode* TargetNode)
		template <typename BHVTreeSharedDataType>
		void StreamDataToTagNodeTree(BHVTreeSharedDataType& SharedData, TagNode* TargetNode)
		{
			FixCurrentNodeData();
			std::string TemporaryInternalName;
			if(TargetNode->SelfContainedTag)
			{
				AddMenuItemData("(LastItem)", "AddSubItem", TargetNode->NodeName);
				CurrentNode->SelfContainedTag = true;
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = GenerateUnusedInternalName(TemporaryInternalName);
				CurrentNode->InternalName = TemporaryInternalName;
				CurrentNode->AdditionTagOptions = TargetNode->AdditionTagOptions;
				CurrentNode->XMLVersionTag = TargetNode->XMLVersionTag;
			}
			else if(TargetNode->ClosingStatus == 1)
			{
				AddMenuItemData("(LastItem)", "AddToParentNode", TargetNode->NodeName);
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = GenerateUnusedInternalName(TemporaryInternalName);
				CurrentNode->InternalName = TemporaryInternalName;
			}
			else
			{
				AddMenuItemData("(LastItem)", "AddSubItem", TargetNode->NodeName);
				TemporaryInternalName = SharedData.CurrentHavokClassInternalName + "_";
				TemporaryInternalName += CurrentNode->PositionInTree.PositionString();
				TemporaryInternalName = GenerateUnusedInternalName(TemporaryInternalName);
				CurrentNode->InternalName = TemporaryInternalName;
				CurrentNode->CopyOtherDataFromNode(TargetNode);
			}
		}
		//void StreamNodeDataWithin(HkBhvNodeData::BHVTreeSharedData& SharedData, TagNode* TargetNode)
		template <typename BHVTreeSharedDataType>
		void StreamNodeDataWithin(BHVTreeSharedDataType& SharedData, TagNode* TargetNode)
		{
			if(TargetNode->NodeName == "hkparam"&&TargetNode->ClosingStatus == 1)
			{
				SharedData.CurrentDataType = 1;
				AddMenuItemData("(LastItem)", "AddToParentNode", TargetNode->NodeName);
				CurrentNode->ClosingStatus = 1;
			}
			else if(SharedData.ContainsNodesWithin)
			{
				StreamDataToTagNodeTree(SharedData, TargetNode);
			}
		}	
		void HkConstructFileFromData(HkBhvNodeData::ConstructionData& SharedData)
		//template <typename ConstructionDataType>
		//void HkConstructFileFromData(ConstructionDataType& SharedData)
		{
			size_t SizeTemp = RootInternalNodes.Size();
			std::string TargetNameTemp;
			TagNode* TargetNode;
			for(size_t Index = 0; Index < SizeTemp; ++Index)
			{
				TargetNameTemp = RootInternalNodes.ElementAt(Index);
				TargetNode = GetNodePointerFromInternalName(TargetNameTemp);
				if(TargetNode != nullptr)
				{
					TargetNode->HkConstructFileWithinFromData(this, SharedData);
				}
			}
		}
		/*End of Loosely connected functions for HkBhvNodeData.h*/
	};
};
#endif
