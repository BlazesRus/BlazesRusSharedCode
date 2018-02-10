/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

#pragma once
#ifndef FileName_IncludeGuard
#define FileName_IncludeGuard

//Non-ProjectBased Headers here

#ifndef BlazesGlobalCode_FileStructureVersion
	#define BlazesGlobalCode_FileStructureVersion 0
	//FileStructureVersion 0 = All required files from GlobalCode within same folder locally
	//FileStructureVersion 1 = Refers to required files set up similar/same as Library Versions of files
	//FileStructureVersion 2 = Nillib Based FileStructure
#endif

//Inside this ifdef block holds GlobalCode Environment library version of header structure (preprocessor defined inside all GlobalCode library configs)
#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
	
	//Headers for Library Version here
	//#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0
	//	//Place Local version layout here
	//#elif BlazesGlobalCode_FileStructureVersion == 1
	//	//Place Separate library Style header layout here
	//#endif
	
	
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
	//Headers for Library Version here
	#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0
	
	#elif BlazesGlobalCode_FileStructureVersion == 1
	
	#endif
#endif

class FileName
{

};

#endif