/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef IniDataV2_IncludeGuard
#define IniDataV2_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

#include <string>

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "StringVectorList.h"
#include "VariableConversionFunctions.h"
#include "CustomDictionary.h"
#else
#include "..\GlobalCode_VariableLists\StringVectorList.h"
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#include "..\GlobalCode_IniData\CustomDictionary.h"
#endif

class DLL_API IniDataV2
{//Non-Ordered Version for now since don't really need Ini Saved in Order for now since not using categories
private:
    const std::string IntDeclaration = "#Int";
    const std::string MediumDecDeclaration = "#MediumDec";
public:
    /// <summary>
    /// The IniSettings with Int Values
    /// </summary>
    CustomDictionary<std::string, int> IntSettings = {};
    /// <summary>
    /// IniSettings with string values and key linkage to IniSettings
    /// </summary>
    CustomDictionary<std::string, std::string> self = {};
    /// <summary>
    /// Loads the Ini data.
    /// </summary>
    /// <param name="FileName">Name of the file.</param>
    /// <param name="IniFormat">The ini storage format.
    /// (TypeDeclaration) + Other Formating
    /// 0 = IniSetting:IniValue; format(Default)
    /// 1= [IniSetting=IniValue] format (based on my old C++ code)
    /// </param>
    void LoadIniData(std::string FileName, unsigned _int8 IniFormat = 0);

    bool CheckIfElementExists(std::string Value);
    ///// <summary>
    ///// Gets the element data.
    ///// </summary>
    ///// <param name="Value">The value.</param>
    ///// <returns></returns>
    //dynamic GetElementData(std::string Value)
    //{
    //	std::string ElementValue = (std::string)this[Value];
    //	if (ElementValue == IntDeclaration)
    //	{
    //		return IntSettings[Value];//return VariableConversionFunctions.IntTostd::stringConversion(IntSettings[Value]);
    //	}
    //	//else if (ElementValue == MediumDecDeclaration)
    //	//{
    //	//	return MediumDecSettings[Value];
    //	//}
    //	else
    //	{
    //		return ElementValue;
    //	}
    //}
    /// <summary>
    /// Gets the element data as std::string
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    std::string GetElementData(std::string Value);
    int GetIntElementData(std::string Value);
    IniDataV2() {};
    ~IniDataV2() {};
};
#endif