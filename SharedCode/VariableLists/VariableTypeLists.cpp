/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "VariableTypeLists.h"
#include <iostream>
#include <fstream>
#include "../OtherFunctions/VariableConversionFunctions.h"

using std::cout;
using std::string;
using VariableConversionFunctions = BlazesRusCode::VariableConversionFunctions;

void DoubleList::SaveDataToFile(std::string Path)
{
    std::string LineString;
    std::fstream CraftedIniFile;
    CraftedIniFile.open(Path, std::ios::out | std::ios::trunc);
    size_t DataSize = Size();
    if (CraftedIniFile.is_open())
    {
        for (size_t i = 0; i < DataSize; ++i)
        {
            if (i != 0)
            {//Carriage Return to next line
                CraftedIniFile << "\r\n";
            }
            LineString = VariableConversionFunctions::DoubleToStringConversion(ElementAt(i));
            CraftedIniFile << LineString;
        }
        CraftedIniFile.close();
    }
    else
    {
        cout << "Failed to open" << Path << "\n";
    }
}

size_t DoubleList::AddData()
{
    size_t Index = Size();
    double TempValue = 0.0;
    Add(TempValue);
    return Index;
}

size_t IntegerList::AddData()
{
    size_t Index = Size();
    int TempValue = 0;
    Add(TempValue);
    return Index;
}

size_t XIntegerList::AddData()
{
    size_t Index = Size();
    long long int TempValue = 0;
    Add(TempValue);
    return Index;
}

void IntegerList::SaveDataToFile(std::string Path)
{
    std::string LineString;
    std::fstream CraftedIniFile;
    CraftedIniFile.open(Path, std::ios::out | std::ios::trunc);
    size_t DataSize = Size();
    if (CraftedIniFile.is_open())
    {
        for (size_t i = 0; i < DataSize; ++i)
        {
            if (i != 0)
            {//Carriage Return to next line
                CraftedIniFile << "\r\n";
            }
            LineString = VariableConversionFunctions::IntToStringConversion(ElementAt(i));
            CraftedIniFile << LineString;
        }
        CraftedIniFile.close();
    }
    else
    {
        cout << "Failed to open" << Path << "\n";
    }
}

void XIntegerList::SaveDataToFile(std::string Path)
{
    std::string LineString;
    std::fstream CraftedIniFile;
    CraftedIniFile.open(Path, std::ios::out | std::ios::trunc);
    size_t DataSize = Size();
    if (CraftedIniFile.is_open())
    {
        for (size_t i = 0; i < DataSize; ++i)
        {
            if (i != 0)
            {//Carriage Return to next line
                CraftedIniFile << "\r\n";
            }
            LineString = VariableConversionFunctions::XIntToStringConversion(ElementAt(i));
            CraftedIniFile << LineString;
        }
        CraftedIniFile.close();
    }
    else
    {
        cout << "Failed to open" << Path << "\n";
    }
}

StringVectorList DoubleList::AsStringList()
{
    StringVectorList TempStringList;
    std::string TempString;
    size_t TempInt = Size();
    for (size_t i = 0; i < TempInt; ++i)
    {
        TempString = VariableConversionFunctions::DoubleAsString(ElementAt(i));
        TempStringList.Add(TempString);
    }
    return TempStringList;
}

void DoubleList::ConvertStringToVectorList(std::string Content)
{
    if (Size() != 0)
    {
        Reset();
    }
    const size_t StringSize = Content.length();
    char CurrentChar;
    string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement == "")
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
                Add(VariableConversionFunctions::ReadDoubleFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
}

StringVectorList IntegerList::AsStringList()
{
    StringVectorList TempStringList;
    std::string TempString;
    size_t TempInt = Size();
    for (size_t i = 0; i < TempInt; ++i)
    {
        TempString = VariableConversionFunctions::IntToStringConversion(ElementAt(i));
        TempStringList.Add(TempString);
    }
    return TempStringList;
}

void IntegerList::AddEntry()
{
    this->Add(0);
}

void XIntegerList::AddEntry()
{
    this->Add(0);
}

void IntegerList::EditLastEntry(int TempValue)
{
    size_t LastIndex = this->Size() - 1;
    this->ElementAt(LastIndex);
}

void XIntegerList::EditLastEntry(long long int TempValue)
{
    size_t LastIndex = this->Size() - 1;
    this->ElementAt(LastIndex);
}

std::string IntegerList::GenerateAsString()
{
    string ListString;
    int TempValue;
    size_t TempSize = this->Size();
    for (int i = 0; i < TempSize; i++)
    {
        TempValue = this->ElementAt(i);
        if (i == 0)
        {
            ListString = VariableConversionFunctions::IntToStringConversion(TempValue);
        }
        else
        {
            ListString += "_";
            ListString += VariableConversionFunctions::IntToStringConversion(TempValue);
        }
    }
    return ListString;
}

void IntegerList::ConvertStringToVectorList(std::string Content)
{
    if (Size() != 0)
    {
        Reset();
    }
    const size_t StringSize = Content.length();
    char CurrentChar;
    string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement == "")
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
                Add(VariableConversionFunctions::ReadIntFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
}

std::string XIntegerList::GenerateAsString()
{
    string ListString;
    long long int TempValue;
    size_t TempSize = this->Size();
    for (size_t i = 0; i < TempSize; ++i)
    {
        TempValue = this->ElementAt(i);
        if (i == 0)
        {
            ListString = VariableConversionFunctions::XIntToStringConversion(TempValue);
        }
        else
        {
            ListString += "_";
            ListString += VariableConversionFunctions::XIntToStringConversion(TempValue);
        }
    }
    return ListString;
}

void XIntegerList::ConvertStringToVectorList(std::string Content)
{
    if (Size() != 0)
    {
        Reset();
    }
    const size_t StringSize = Content.length();
    char CurrentChar;
    string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement == "")
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
                Add(VariableConversionFunctions::ReadXIntFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
}

size_t BoolList::AddData()
{
    size_t Index = Size();
    bool TempValue = false;
    Add(TempValue);
    return Index;
}

void BoolList::SaveDataToFile(std::string Path)
{
    std::string LineString;
    std::fstream CraftedIniFile;
    CraftedIniFile.open(Path, std::ios::out || std::ios::trunc);
    size_t DataSize = Size();
    if (CraftedIniFile.is_open())
    {
        for (size_t i = 0; i < DataSize; i++)
        {
            if (i != 0)
            {//Carriage Return to next line
                CraftedIniFile << "\r\n";
            }
            LineString = VariableConversionFunctions::BoolAsString(ElementAt(i));
            CraftedIniFile << LineString;
        }
        CraftedIniFile.close();
    }
    else
    {
        cout << "Failed to open" << Path << "\n";
    }
}

StringVectorList BoolList::AsStringList()
{
    StringVectorList TempStringList;
    std::string TempString;
    size_t TempInt = Size();
    for (size_t i = 0; i < TempInt; i++)
    {
        TempString = VariableConversionFunctions::BoolAsString(ElementAt(i));
        TempStringList.Add(TempString);
    }
    return TempStringList;
}

void BoolList::ConvertStringToVectorList(std::string Content)
{
    if (Size() != 0)
    {
        Reset();
    }
    const size_t StringSize = Content.length();
    char CurrentChar;
    string CurrentElement = "";
    for (size_t Index = 0; Index < StringSize; ++Index)
    {
        CurrentChar = Content.at(Index);
        if (CurrentElement == "")
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
                Add(VariableConversionFunctions::ReadBoolFromString(CurrentElement));
                CurrentElement = "";
            }
        }
    }
}