/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "IniData.h"
#include <string>

void IniData::LoadIniData(std::string FileName)
{
    StringVectorList TargetSettings;
    TargetSettings.LoadFileDataV2(FileName);
    //First part of command;Syntax:[ScriptArg01=ScriptArg02]
    std::string ScriptArg01;
    //Command Value;Syntax:[ScriptArg01=ScriptArg02]
    std::string ScriptArg02;
    //CommandScan Stage (limited to value of 255 to save little ram)
    unsigned __int8 CommandStage = 0;
    std::string LineString = "";
    size_t LineSize;
    char LineChar;
    bool InsideParenthesis = false;
    IniDataElement ElementData;
    for(size_t LineNumber = 0; TargetSettings.StreamLineData(); ++LineNumber)
    {
        LineString = TargetSettings.CurrentStreamedLineString();
        LineSize = LineString.length();
        for(size_t i = 0; i < LineSize; ++i)
        {
            LineChar = LineString.at(i);
            if(LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
            else if(LineChar == '[')
            {
                ScriptArg01 = "";
                CommandStage = 1;
            }
            else if(CommandStage > 0)
            {
                if(InsideParenthesis==false&&(LineChar == '=' || LineChar == ':'))
                {
                    CommandStage = 2;
                }
                else if(CommandStage == 2)
                {
                    if(LineChar == ']')
                    {
                        //std::cout << "Executing Command:" << ScriptArg01 << " with parameter "<<ScriptArg02<<"\n";
                        CommandStage = 0;
                        ElementData.ScriptArg01 = ScriptArg01;
                        ElementData.ScriptArg02 = ScriptArg02;
                        Add(ElementData);
                        ScriptArg02 = "";
                        ScriptArg01 = "";
                    }
                    else
                    {
                        ScriptArg02 += LineChar;
                    }
                }
                else
                {
                    ScriptArg01 += LineChar;
                }
            }
        }
    }
}

IniData::IniData()
{}


IniData::~IniData()
{}


IniDataElement::IniDataElement()
{}


IniDataElement::~IniDataElement()
{}
