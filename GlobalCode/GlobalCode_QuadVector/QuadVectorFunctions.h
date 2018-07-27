/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#ifdef BlazesGlobalCode_UsePreprocessor
#ifdef BlazesGlobalCode_LocalLayout
	#include "stdafx.h"
#else
	#include "..\stdafx.h"
#endif
#endif

#pragma once
#ifndef QuadVectorFunctions_IncludeGuard
#define QuadVectorFunctions_IncludeGuard

#include "QuadVector.h"
#include <string>

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
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
