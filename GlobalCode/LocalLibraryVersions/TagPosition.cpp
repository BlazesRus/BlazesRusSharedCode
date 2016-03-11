/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "TagPosition.h"

//#include "VariableConversionFunctions.h"

//Inside this ifdef block holds GlobalCode Environment library version of header structure (preprocessor defined inside all GlobalCode library configs)
#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
//Local Version of headers here(within else block)
#else
#include "VariableConversionFunctions.h"
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

std::string TagPosition::PositionString()
{
	std::string PositionString = ParentIndexPosition.GenerateAsString();
	PositionString += "-";
	PositionString += VariableConversionFunctions::XIntToStringConversion(ListPosition);
	return PositionString;
}