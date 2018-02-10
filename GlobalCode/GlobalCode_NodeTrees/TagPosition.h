/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagPosition_IncludeGuard
#define TagPosition_IncludeGuard

//Inside this ifdef block holds GlobalCode Environment library version of header structure (preprocessor defined inside all GlobalCode library configs)
#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\GlobalCode_VariableLists\VariableList.h" //This is Just Custom Derivatative Vector <VariableType> (Also using std::string here)
#include "..\GlobalCode_VariableLists\VariableTypeLists.h" //Holds VariableList<Integer> and includes header containing VariableList<string>
#include "..\DLLAPI.h"
//Local Version of headers here(within else block)
#else
#include "VariableList.h"
#include "VariableTypeLists.h"
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

class DLL_API TagPosition
{
public:
	//Example ParentIndexPosition="0_1"
	XIntegerList ParentIndexPosition;
	//Index in CurrentList
	long long int ListPosition = -1;
	void IncreaseListPos()
	{
		ListPosition += 1;
	}
	void IncreaseParentIndex()
	{
		ParentIndexPosition.Add(ListPosition);
		ListPosition = -1;
	}
	//************************************
	// Returns String in format ParentIndexPosition(Index:0)_ParentIndexPosition(Index:1)-ListPosition
	// Method:    PositionString
	// FullName:  TagData::TagPosition::PositionString
	// Access:    public
	// Returns:   string
	// Qualifier:
	//************************************
	std::string PositionString();
};
#endif