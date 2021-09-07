/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once
#ifndef VariableTypeLists_IncludeGuard
#define VariableTypeLists_IncludeGuard

#ifdef BLAZESSharedCode_LIBRARY
#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

#include "VariableList.h"
#include "StringVectorList.h"
#include <string>

#ifdef IntegerList_AddBinaryFunctions
#include <bitset>
#endif

class DLL_API IntegerList : public VariableList < int >
{
public:
    //************************************
    // Method:    AddData
    // FullName:  IntegerList::AddData
    // Access:    public
    // Returns:   int
    // Qualifier:
    //************************************
    size_t AddData();
    //************************************
    // Method:    SaveDataToFile
    // FullName:  IntegerList::SaveDataToFile
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: std::string Path
    //************************************
    void SaveDataToFile(std::string Path);
    //************************************
    // Method:    AsStringList
    // FullName:  IntegerList::AsStringList
    // Access:    public
    // Returns:   StringVectorList
    // Qualifier:
    //************************************
    StringVectorList AsStringList();
    //************************************
    // Method:    AddEntry
    // FullName:  IntegerList::AddEntry
    // Access:    public
    // Returns:   void
    // Qualifier:
    //Adds new entry into list at index 0(Used mainly for InfiniteScopePosInt)
    //************************************
    void AddEntry();
    //************************************
    // Method:    EditLastEntry
    // FullName:  IntegerList::EditLastEntry
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: int TempValue
    // Edits last value in List(Used mainly for InfiniteScopePosInt)
    //************************************
    void EditLastEntry(int TempValue);
    void IncreaseLastEntry()
    {
        size_t LastIndex = Size() - 1;
        int TempValue = ElementAt(LastIndex);
        TempValue++;
        SetElementAt(LastIndex, TempValue);
    }
    //************************************
    // Generates String with format Index:0_Index:1...Index:5
    // Method:    GenerateAsString
    // FullName:  IntegerList::GenerateAsString
    // Access:    public
    // Returns:   string
    // Qualifier:
    //************************************
    std::string GenerateAsString();
    void ConvertStringToVectorList(std::string Content);
#ifdef IntegerList_AddBinaryFunctions
    std::bitset<32> RetrieveElementAsBitSet(size_t Index)
    {
        uint8_t Element = ElementAt(Index);
        std::bitset<32> bitten(Element);
    }
#endif
};

class DLL_API XIntegerList : public VariableList < long long int >
{
public:
    //************************************
    // Method:    AddData
    // FullName:  IntegerList::AddData
    // Access:    public
    // Returns:   int
    // Qualifier:
    //************************************
    size_t AddData();
    //************************************
    // Method:    SaveDataToFile
    // FullName:  IntegerList::SaveDataToFile
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: std::string Path
    //************************************
    void SaveDataToFile(std::string Path);
    //************************************
    // Method:    AsStringList
    // FullName:  IntegerList::AsStringList
    // Access:    public
    // Returns:   StringVectorList
    // Qualifier:
    //************************************
    StringVectorList AsStringList();
    //************************************
    // Method:    AddEntry
    // FullName:  IntegerList::AddEntry
    // Access:    public
    // Returns:   void
    // Qualifier:
    //Adds new entry into list at index 0(Used mainly for InfiniteScopePosInt)
    //************************************
    void AddEntry();
    //************************************
    // Method:    EditLastEntry
    // FullName:  IntegerList::EditLastEntry
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: int TempValue
    // Edits last value in List(Used mainly for InfiniteScopePosInt)
    //************************************
    void EditLastEntry(long long int TempValue);
    void IncreaseLastEntry()
    {
        size_t LastIndex = this->Size() - 1;
        long long int TempValue = this->ElementAt(LastIndex);
        TempValue++;
        this->SetElementAt(LastIndex, TempValue);
    }
    //************************************
    // Generates String with format Index:0_Index:1...Index:5
    // Method:    GenerateAsString
    // FullName:  IntegerList::GenerateAsString
    // Access:    public
    // Returns:   string
    // Qualifier:
    //************************************
    std::string GenerateAsString();
    void ConvertStringToVectorList(std::string Content);
#ifdef IntegerList_AddBinaryFunctions
    std::bitset<64> RetrieveElementAsBitSet(size_t Index)
    {
        uint8_t Element = ElementAt(Index);
        std::bitset<64> bitten(Element);
    }
#endif
};

class DLL_API UXIntList : public VariableList <unsigned __int64>
{
};

class DLL_API DoubleList : public VariableList < double >
{
public:
    size_t AddData();
    void SaveDataToFile(std::string Path);
    StringVectorList AsStringList();
    void ConvertStringToVectorList(std::string Content);
};

class DLL_API BoolList : public VariableList < bool >
{
public:
    size_t AddData();
    void SaveDataToFile(std::string Path);
    StringVectorList AsStringList();
    void ConvertStringToVectorList(std::string Content);
#ifdef IntegerList_AddBinaryFunctions
    std::bitset<8> RetrieveElementAsBitSet(size_t Index)
    {
        bool Element = ElementAt(Index);
        std::bitset<8> bitten(Element);
    }
#endif
};
#endif
