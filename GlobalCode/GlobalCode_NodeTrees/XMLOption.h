/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef XMLOption_IncludeGuard
#define XMLOption_IncludeGuard

#ifndef BlazesGlobalCode_FileStructureVersion
	#define BlazesGlobalCode_FileStructureVersion 0
	//FileStructureVersion 0 = Refers to required files set up similar/same as Library Versions of files
	//FileStructureVersion 1 = All required files from GlobalCode within same folder locally
#endif

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#include <string>
#include "VariableList.h"

class DLL_API XMLOption
{
public:
	std::string OptionName = "";
	//Value Stored inside Option
	//[[NULL--VALUE]] or "None" = No Value Stored
	//"Undetermined" or "" = Undefined (Default)
	std::string ValueType = "";
	std::string ValueString = "";
	//Value not Stored in Arg within String inside Parenthesis
	bool ValueNotInParenthesis = false;
	XMLOption(std::string Name, std::string Value)
	{
		OptionName = Name;
		ValueString = Value;
		//Auto-Detect ValueType
		if(Value == "[[NULL--VALUE]]")
		{
			ValueType = "None";
		}
		else
		{
			ValueType = "Undetermined";
		}
	}
	XMLOption();
	~XMLOption();
};

class DLL_API XMLOptionList : public VariableList < XMLOption >
{
public:
	//************************************
	// Returns check for if Option with name OptionNameTemp found within
	// Method:    HasOption
	// FullName:  XMLOptionList::HasOption
	// Access:    public
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string OptionNameTemp
	//************************************
	bool HasOption(std::string OptionNameTemp);
	//************************************
	// Returns Value of OptionArg named OptionNameTemp
	// Method:    GetOptionValue
	// FullName:  XMLOptionList::GetOptionValue
	// Access:    public
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string OptionNameTemp
	//************************************
	std::string GetOptionValue(std::string OptionNameTemp);
	void AddOption(std::string NameTemp, std::string ValueTemp)
	{
		XMLOption OptionToAdd;
		OptionToAdd.OptionName = NameTemp;
		OptionToAdd.ValueString = ValueTemp;
		Add(OptionToAdd);
	}
};
#endif