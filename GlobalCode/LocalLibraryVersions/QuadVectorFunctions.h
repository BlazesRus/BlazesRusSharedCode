/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef QuadVectorFunctions_IncludeGuard
#define QuadVectorFunctions_IncludeGuard

#include "QuadVector.h"
#include <string>

//Inside this ifdef block holds GlobalCode Environment library version of header structure (preprocessor defined inside all GlobalCode library configs)
#ifdef BLAZESGLOBALCODE_LIBRARY

//Local Version of headers here(within else block)
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

class QuadVectorFunctions
{
public:
	//Returns QuadValue from string;returns value of (0.0,0.0,0.0,0.0) if either invalid string sent
	static QuadVector ReadQuadVectorFromString(std::string LineString);
	static std::string QuadVectorToStringConversion(QuadVector TempValue);
	static QuadVectorList ReadQuadVectorListFromString(std::string LineString);
	QuadVectorFunctions();
	~QuadVectorFunctions();
};
#endif