/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "TagNodeTreeTemplate.h"

#include "..\VariableLists\VariableVectorFunctions.h"
using std::string;

void TagNodeTreeTemplateData::Node::DetectTagContentTypeV2(OptimizationData& SharedData)
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
            TagContentType = StringFunctions::FindContentType(TagContent);
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
        TagContentType = StringFunctions::FindContentType(TagContent);
    }
}

void TagNodeTreeTemplateData::Node::GenerateHTMLDoc(StringVectorList& OutputBuffer, size_t& OutputLvl, const unsigned __int8& GenerationOptions/*=0*/)
{
    std::string TempTag;
    size_t SizeTemp;
    if(TagContentType == 240)//Havok Class Block Tag
    {
        TempTag = "<a name=\"";
        TempTag += AdditionTagOptions.GetOptionValue("name");
        TempTag += "\">";
        TempTag += "<code>";
        TempTag += StringFunctions::CreateTabSpace(OutputLvl);
        TempTag += "<hkobject name=\"";
        TempTag += AdditionTagOptions.GetOptionValue("name");
        TempTag += "\" class=\"";
        TempTag += AdditionTagOptions.GetOptionValue("class");
        TempTag += "\" signature=\"";
        TempTag += AdditionTagOptions.GetOptionValue("signature");
        TempTag += "\"></code>";
    }
    else
    {
        TempTag = "<code>";
        TempTag += StringFunctions::CreateTabSpace(OutputLvl);
        TempTag += "<";
        if(ClosingStatus == 1)
        {
            TempTag += "/";
        }
        TempTag += NodeName;
        //Tag Option output
        SizeTemp = AdditionTagOptions.Size();
        XMLOption OptionTemp;
        for(size_t Index = 0; Index < SizeTemp; ++Index)
        {
            TempTag += " ";
            OptionTemp = AdditionTagOptions.ElementAt(Index);
            if(OptionTemp.ValueType == "None")
            {
                TempTag += OptionTemp.OptionName;
            }
            else if(OptionTemp.ValueNotInParenthesis)
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
        if(SelfContainedTag)
        {
            TempTag += "/>";
            TempTag += "<br>"; OutputBuffer.Add(TempTag);
        }
        else if(ClosingStatus != 1)
        {
            TempTag += ">";
            TempTag += "</code>";
            if(!((TagContentType >= 1 && TagContentType <= 14) || TagContentType == 252))
            {//Don't Separate line for known single-line Tags
                TempTag += "<br>"; OutputBuffer.Add(TempTag);
                TempTag = "<code>";
                TempTag += StringFunctions::CreateTabSpace(OutputLvl + 1);
                TempTag += "</code>";
            }
            //Output TagContent
            //StringVectorList TempList;
            switch(TagContentType)
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
                    StringVectorList TempList = VariableVectorFunctions::ConvertStringToStringVectorList(TagContent);
                    SizeTemp = TempList.Size();
                    //Limit 16 entries a line
                    unsigned __int8 LineIndex = 0;
                    for(size_t Index = 0; Index < SizeTemp; ++Index&&++LineIndex)
                    {
                        if(LineIndex == 16)
                        {
                            TempTag += "<br>"; OutputBuffer.Add(TempTag);
                            TempTag = "<code>";
                            TempTag += StringFunctions::CreateTabSpace(OutputLvl + 1);
                            TempTag += "</code>";
                            LineIndex = 0;
                        }
                        if(LineIndex != 0)
                        {
                            TempTag += "<code> </code>";
                        }
                        TempTag += "<a href=\"#\"";
                        TempTag += TagContent;
                        TempTag += "\">";
                        TempTag += TagContent;
                        TempTag += "</a>";
                    }
                    TempTag += "<br>"; OutputBuffer.Add(TempTag);
                    TempTag = "<code>";
                    TempTag += StringFunctions::CreateTabSpace(OutputLvl + 1);
                    TempTag += "</code>";
                    break;
                }
                //case 5://Display index to Event with alt text of EventName (link to EventName)
                //{
                //	const size_t Index = StringFunctions::ReadXIntFromString(TempTag);
                //	const std::string NameTemp = SharedData.TargetBHVTreePointer->VariableData.eventNames.ElementAt(Index);
                //	TempTag += "<a href=\"#\"";
                //	//Link to EventName here
                //	TempTag += "eventNames_";
                //	TempTag += StringFunctions::DoubleToStringConversion(Index);
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
                //	const size_t Index = StringFunctions::ReadXIntFromString(TempTag);
                //	const std::string NameTemp = SharedData.TargetBHVTreePointer->VariableData.variableNames.ElementAt(Index);
                //	TempTag += "<a href=\"#\"";
                //	//;//Link to EventName here
                //	TempTag += "variableNames_";
                //	TempTag += StringFunctions::DoubleToStringConversion(Index);
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
                    TempTag += "<br>"; OutputBuffer.Add(TempTag);
                }
            }
        }
        else
        {
            if(!((TagContentType >= 1 && TagContentType <= 14) || TagContentType == 252))
            {//Don't Separate line for known single-line Tags
                TempTag += TagContent;
                TempTag += "<br>"; OutputBuffer.Add(TempTag);
            }
        }
    }
}
