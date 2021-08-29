/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

#include "VariableVectorFunctions.h"
#include <string>
//#include "StringFunctions.h"

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "VariableConversionFunctions.h"
#else
#include "..\OtherFunctions\VariableConversionFunctions.h"
#endif

using std::string;
using VariableConversionFunctions = BlazesRusCode::VariableConversionFunctions;

StringVectorList VariableVectorFunctions::ReadStringParamFromStringList(StringVectorList TempStringList)
{
    string TempString = "";
    StringVectorList ParamList;
    size_t StringLength;
    char StringChar;
    string LineString;
    for (size_t ListLine = 0; TempStringList.StreamLineData(); ++ListLine)
    {
        LineString = TempStringList.CurrentStreamedLineString();
        StringLength = LineString.length();
        for (int i = 0; i < StringLength; i++)
        {
            StringChar = LineString.at(i);
            if (StringChar == ' ' || StringChar == '	' && !TempString.empty())
            {
                ParamList.Add(TempString);
                TempString = "";
            }
            else
            {
                TempString += StringChar;
            }
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(TempString);
    }
    return ParamList;
}

IntegerList VariableVectorFunctions::ReadIntParamFromStringList(StringVectorList TempStringList)
{
    string TempString = "";
    IntegerList ParamList;
    size_t StringLength;
    char StringChar;
    string LineString;
    for (size_t ListLine = 0; TempStringList.StreamLineData(); ++ListLine)
    {
        LineString = TempStringList.CurrentStreamedLineString();
        StringLength = LineString.length();
        for (int i = 0; i < StringLength; i++)
        {
            StringChar = LineString.at(i);
            if (StringChar == ' ' || StringChar == '	' && !TempString.empty())
            {
                ParamList.Add(VariableConversionFunctions::ReadIntFromString(TempString));
                TempString = "";
            }
            else
            {
                TempString += StringChar;
            }
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(VariableConversionFunctions::ReadIntFromString(TempString));
    }
    return ParamList;
}

DoubleList VariableVectorFunctions::ReadDoubleParamFromStringList(StringVectorList TempStringList)
{
    string TempString = "";
    DoubleList ParamList;
    size_t StringLength;
    char StringChar;
    string LineString;
    for (size_t ListLine = 0; TempStringList.StreamLineData(); ++ListLine)
    {
        LineString = TempStringList.CurrentStreamedLineString();
        StringLength = LineString.length();
        for (int i = 0; i < StringLength; i++)
        {
            StringChar = LineString.at(i);
            if (StringChar == ' ' || StringChar == '	')
            {
                ParamList.Add(VariableConversionFunctions::ReadDoubleFromString(TempString));
                TempString = "";
            }
            else
            {
                TempString += StringChar;
            }
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(VariableConversionFunctions::ReadDoubleFromString(TempString));
    }
    return ParamList;
}

//
/** Retrieve StringList from LineString
* @param LineString
* @return
*/
StringVectorList VariableVectorFunctions::ParamInfoFromString(string LineString)
{
    string TempString = "";
    StringVectorList ParamList;
    size_t StringLength = LineString.length();
    char StringChar;
    for (int i = 0; i < StringLength; i++)
    {
        StringChar = LineString.at(i);
        if (StringChar == ',')
        {
            ParamList.Add(TempString);
            TempString = "";
        }
        else
        {
            TempString += StringChar;
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(TempString);
    }
    return ParamList;
}

/** Convert Variable Index from one StringList to Another StringList
* @param Index
* @param CurrentVarList
* @param NewVarList
* @return integer of new VariableIndex
*/
size_t VariableVectorFunctions::ConvertVariableIndex(size_t Index, StringVectorList CurrentVarList, StringVectorList NewVarList)
{
    string TempString = CurrentVarList.elementAt(Index);
    return NewVarList.GetElementIndex(TempString);
}

/** Converts Entries in StringList to Rows of 16-entry Strings
* (Use to convert StringList for BoneEntries back to Lines of Strings)
* @param TempStringList
* @return
*/
StringVectorList VariableVectorFunctions::ConvertStringEntriesToStringRows(StringVectorList TempStringList)
{
    //16 Entries a row(Bone-indexes)
    StringVectorList StringRows;
    string CurrentRowString = "";
    int ColumnNum = 0;
    for (int i = 0; i < TempStringList.length(); i++)
    {
        if (ColumnNum == 0)
        {
            CurrentRowString = TempStringList.elementAt(i);
        }
        else
        {
            CurrentRowString += " " + TempStringList.elementAt(i);
        }
        ColumnNum++;
        if (ColumnNum >= 16)
        {
            StringRows.Add(CurrentRowString);
            ColumnNum = 0;
        }
    }
    if (ColumnNum != 0)
    {
        StringRows.Add(CurrentRowString);
    }
    return StringRows;
}

StringVectorList VariableVectorFunctions::IniInfoFromString(string LineString)
{
    string TempString = "";
    StringVectorList ParamList;
    size_t StringLength = LineString.length();
    string StringChar;
    bool IgnoreWhitespace = true;
    for (size_t i = 0; i < StringLength; ++i)
    {
        StringChar = LineString.at(i);
        if (StringChar == "=")
        {
            ParamList.Add(TempString);
            TempString = "";
        }
        else if (StringChar == "\\\"")
        {
            IgnoreWhitespace = !IgnoreWhitespace;
        }
        else if (IgnoreWhitespace && StringChar == "[^\\\\d]") {}
        else
        {
            TempString += StringChar;
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(TempString);
    }
    return ParamList;
}

StringVectorList VariableVectorFunctions::ParamInfoFromStringList(StringVectorList TempStringList)
{
    string TempString = "";
    StringVectorList ParamList;
    size_t StringLength;
    char StringChar;
    string LineString;
    for (size_t ListLine = 0; TempStringList.StreamLineData(); ++ListLine)
    {
        LineString = TempStringList.CurrentStreamedLineString();
        StringLength = LineString.length();
        for (size_t i = 0; i < StringLength; i++)
        {
            StringChar = LineString.at(i);
            if (StringChar == ',')
            {
                ParamList.Add(TempString);
                TempString = "";
            }
            else
            {
                TempString += StringChar;
            }
        }
    }
    if (!TempString.empty())
    {
        ParamList.Add(TempString);
    }
    return ParamList;
}

/** Find Number of Parameters in LineString
* @param LineString
* @return
*/
size_t VariableVectorFunctions::GetNumberOfParamsFromString(string LineString)
{
    StringVectorList ParamList = ParamInfoFromString(LineString);
    return ParamList.length();
}

inline DoubleList VariableVectorFunctions::ConvertStringToDoubleList(std::string Content)
{
    DoubleList ConvertedValue;
    const size_t StringSize = Content.length();
    char CurrentChar;
    std::string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement.empty())
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement = CurrentChar;
            }
        }
        else
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement += CurrentChar;
            }
            else
            {
                ConvertedValue.Add(VariableConversionFunctions::ReadDoubleFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
    return ConvertedValue;
}

inline IntegerList VariableVectorFunctions::ConvertStringToIntegerList(std::string Content)
{
    IntegerList ConvertedValue;
    const size_t StringSize = Content.length();
    char CurrentChar;
    std::string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement.empty())
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement = CurrentChar;
            }
        }
        else
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement += CurrentChar;
            }
            else
            {
                ConvertedValue.Add(VariableConversionFunctions::ReadIntFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
    return ConvertedValue;
}

inline XIntegerList VariableVectorFunctions::ConvertStringToXIntegerList(std::string Content)
{
    XIntegerList ConvertedValue;
    const size_t StringSize = Content.length();
    char CurrentChar;
    std::string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement.empty())
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement = CurrentChar;
            }
        }
        else
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement += CurrentChar;
            }
            else
            {
                ConvertedValue.Add(VariableConversionFunctions::ReadXIntFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
    return ConvertedValue;
}

inline BoolList VariableVectorFunctions::ConvertStringToBoolList(std::string Content)
{
    BoolList ConvertedValue;
    const size_t StringSize = Content.length();
    char CurrentChar;
    std::string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement.empty())
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement = CurrentChar;
            }
        }
        else
        {
            if (CurrentChar != '\n' && CurrentChar != ' ' && CurrentChar != '\t' && CurrentChar != '	')
            {
                CurrentElement += CurrentChar;
            }
            else
            {
                ConvertedValue.Add(VariableConversionFunctions::ReadBoolFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
    return ConvertedValue;
}

VariableVectorFunctions::VariableVectorFunctions()
{}

VariableVectorFunctions::~VariableVectorFunctions()
{}