/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef CustomDecUnsigned_IncludeGuard
#define CustomDecUnsigned_IncludeGuard

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

#include <io.h>
#include <math.h>
#include <iostream>
#include <string>
#include "SuperDecHex.h"

//Non-Alternating headers above (Structure based headers in this section)
//#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0//(library style  layout)
	//Place  library Style  layout here
//#elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
	//Place Local version layout here
//#endif

////Use added C Wrapper Code to enable use of code in C# etc (BlazesGlobalCode_UseCWrapperCode)
#ifdef BlazesGlobalCode_UseCWrapperCode//C# version of code

#else//C++ version of code

//Alternative Version of CustomDec_Template that stores boolean state inside Decimal Field instead
//IntValue Stored as Unsigned Int version of value, DecType Stores positive/negative state
template <typename IntType = unsigned __int32,  typename DecType = signed __int32>
class DLL_API CustomDec_UnsignedTemplate
{

};
#endif

#endif