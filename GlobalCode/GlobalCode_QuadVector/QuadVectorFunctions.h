/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef QuadVectorFunctions_IncludeGuard
#define QuadVectorFunctions_IncludeGuard

#include "QuadVector.h"
#include <string>

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
