/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef VariableVectorFunctions_IncludeGuard
#define VariableVectorFunctions_IncludeGuard

#ifdef BlazesGlobalCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesGlobalCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESGLOBALCODE_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include "VariableTypeLists.h"
#include <string>

class DLL_API VariableVectorFunctions
{
public:
    //Return param of strings from things like havok lists
    static StringVectorList ReadStringParamFromStringList(StringVectorList TempStringList);

    //Return param of strings from things like boneIndices param
    static IntegerList ReadIntParamFromStringList(StringVectorList TempStringList);
    //Return param of strings from things like hkbBoneWeightArray param
    static DoubleList ReadDoubleParamFromStringList(StringVectorList TempStringList);
    //Retrieve ParamInfo StringList from StringList
    static StringVectorList ParamInfoFromStringList(StringVectorList TempStringList);

    /** Retrieve ParamInfo StringList from LineString
    * @param LineString
    * @return
    */
    static StringVectorList ParamInfoFromString(std::string LineString);

    /** Convert Variable Index from one StringList to Another StringList
    * @param Index
    * @param CurrentVarList
    * @param NewVarList
    * @return integer of new VariableIndex
    */
    static size_t ConvertVariableIndex(size_t Index, StringVectorList CurrentVarList, StringVectorList NewVarList);

    /** Converts Entries in StringList to Rows of 16-entry Strings
    * (Use to convert StringList for BoneEntries back to Lines of Strings)
    * @param TempStringList
    * @return
    */
    static StringVectorList ConvertStringEntriesToStringRows(StringVectorList TempStringList);

    //Return StringList based on string info
    static StringVectorList IniInfoFromString(std::string LineString);

    /** Find Number of Parameters in LineString
    * @param LineString
    * @return
    */
    static size_t GetNumberOfParamsFromString(std::string LineString);
    static DoubleList ConvertStringToDoubleList(std::string Content);
    static IntegerList ConvertStringToIntegerList(std::string Content);
    static XIntegerList ConvertStringToXIntegerList(std::string Content);
    static BoolList ConvertStringToBoolList(std::string Content);
    static StringVectorList ConvertStringToStringVectorList(std::string Content)
    {
        StringVectorList ConvertedValue;
        const size_t StringSize = Content.length();
        char CurrentChar;
        std::string CurrentElement = "";
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
                    ConvertedValue.Add(CurrentElement);
                    CurrentElement = "";
                }
            }
        }
        return ConvertedValue;
    }
    VariableVectorFunctions();
    ~VariableVectorFunctions();
};
#endif
