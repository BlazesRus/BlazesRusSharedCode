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
#ifndef CustomOrderedDictionary_IncludeGuard
#define CustomOrderedDictionary_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)

#else

#endif

class CustomOrderedDictionary
{

};
#endif