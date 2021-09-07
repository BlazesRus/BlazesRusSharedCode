/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "TagPosition.h"

//#include "VariableConversionFunctions.h"

//Inside this ifdef block holds SharedCode Environment library version of header structure (preprocessor defined inside all SharedCode library configs)
#ifdef BLAZESSharedCode_LIBRARY
#include "..\OtherFunctions\VariableConversionFunctions.h"
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
