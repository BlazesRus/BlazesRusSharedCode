/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "IniDataV2.h"
#include <string>

/// <summary>
/// Loads the Ini data.
/// </summary>
/// <param name="FileName">Name of the file.</param>
/// <param name="IniFormat">The ini storage format.
/// (TypeDeclaration) + Other Formating
/// 0 = IniSetting:IniValue; format(Default)
/// 1= [IniSetting=IniValue] format (based on my old C++ code)
/// </param>

inline void IniDataV2::LoadIniData(std::string FileName, unsigned _int8 IniFormat)
{
    StringVectorList FileData;
    FileData.LoadFileDataV2(FileName);
    std::string LineData;
    std::string IniSetting = "";
    std::string IniValue = "";
    //byte InsideComment = 0;
    bool InsideTypeDeclaration = false;
    std::string TypeName = "";
    std::string builder = "";
    if (IniFormat == 1)
    {
        bool InsideParenthesis = false;
        int LineSize;
        char LineChar;
        int CommandStage = 0;
        //IniDataV2Element ElementData = new IniDataV2Element();
        for (int Index = 0; Index < FileData.length(); ++Index)
        {
            LineData = FileData[Index];
            LineSize = LineData.length();
            for (int i = 0; i < LineSize; ++i)
            {
                LineChar = LineData[i];
                if (LineChar == '"') { InsideParenthesis = !InsideParenthesis; }
                else if (LineChar == '[')
                {
                    IniSetting = "";
                    CommandStage = 1;
                }
                else if (InsideTypeDeclaration)
                {
                    if (LineChar == ')')
                    {
                        TypeName = builder;
                        InsideTypeDeclaration = false;
                    }
                    else
                    {
                        builder.append(&LineChar);//builder += LineChar;
                    }
                }
                else if (LineChar == '(')
                {
                    builder.clear(); InsideTypeDeclaration = true;
                }
                else if (CommandStage > 0)
                {
                    if (InsideParenthesis == false && (LineChar == '=' || LineChar == ':'))
                    {
                        CommandStage = 2;
                    }
                    else if (CommandStage == 2)
                    {
                        if (LineChar == ']')
                        {
                            CommandStage = 0;
                            if (TypeName == "Int")
                            {
                                self.Add(IniSetting, IntDeclaration);
                                IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue));
                            }
                            //else if(TypeName=="MediumDec")
                            //{
                            //	this.Add(IniSetting, MediumDecDeclaration);
                            //	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
                            //}
                            else
                            {
                                self.Add(IniSetting, IniValue);
                            }
                            IniValue = "";
                            IniSetting = "";
                        }
                        else
                        {
                            IniValue += LineChar;
                        }
                    }
                    else
                    {
                        IniSetting += LineChar;
                    }
                }
            }
        }
    }
    else
    {
        for (int Index = 0; Index < FileData.length(); ++Index)
        {
            LineData = FileData[Index];
            for (const char StringChar : LineData)
            {
                if (InsideTypeDeclaration)
                {
                    if (StringChar == ')')
                    {
                        TypeName = builder;
                        InsideTypeDeclaration = false;
                    }
                    else
                    {
                        builder.append(&StringChar);
                    }
                }
                else if (StringChar == ':')
                {//IniSetting
                    IniSetting = builder;
                    builder.clear();
                }
                else if (StringChar == ';')
                {
                    IniValue = builder;
                    builder.clear();
                    if (TypeName == "Int")
                    {
                        self.Add(IniSetting, IntDeclaration);
                        IntSettings.Add(IniSetting, VariableConversionFunctions::ReadIntFromString(IniValue));
                    }
                    //else if(TypeName=="MediumDec")
                    //{
                    //	this.Add(IniSetting, MediumDecDeclaration);
                    //	MediumDecSettings.Add(IniSetting, (MediumDec)IniValue);
                    //}
                    else
                    {
                        self.Add(IniSetting, IniValue);
                    }
                }
                else if (StringChar == '(')
                {
                    builder.clear(); InsideTypeDeclaration = true;
                }
                else if (StringChar == '/')//Start of line comment detected so skip rest of line
                {
                    if (builder == "/")
                    {
                        builder.clear();
                        break;
                    }
                    else//False alarm on line comment detection
                    {
                        builder.append(&StringChar);
                    }
                }
                else
                {
                    if (builder.length() == 0)
                    {
                        continue;
                    }
                    else
                    {
                        builder.append(&StringChar);
                        continue;
                    }
                }
            }
        }
    }
}

inline bool IniDataV2::CheckIfElementExists(std::string Value)
{
    return self.find(Value) != self.end();
}

/// <summary>
/// Gets the element data as std::string
/// </summary>
/// <param name="Value">The value.</param>
/// <returns></returns>

inline std::string IniDataV2::GetElementData(std::string Value)
{
    std::unordered_map<std::string, std::string>::iterator ValueInfo = self.find(Value);
    if (ValueInfo == self.end())
    {
        return "";
    }
    else
    {
        std::string ElementValue = ValueInfo->second;
        if (ElementValue == IntDeclaration)
        {
            return VariableConversionFunctions::IntToStringConversion(IntSettings[Value]);
        }
        //else if (ElementValue == MediumDecDeclaration)
        //{
        //	return MediumDecSettings[Value].ToFullString();
        //}
        else
        {
            return ElementValue;
        }
    }
}

inline int IniDataV2::GetIntElementData(std::string Value)
{
    return IntSettings[Value];
}