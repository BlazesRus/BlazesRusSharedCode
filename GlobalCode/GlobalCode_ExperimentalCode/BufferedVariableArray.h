/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#if !defined(BufferedVariableArray_IncludeGuard) && !defined(ExcludeGlobalCode_ExperimentalCode)
#define BufferedVariableArray_IncludeGuard

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

//"Unfinished" code here
template <typename VariableType>
class BufferedVariableArray
{public:
	int length=0;
	VariableType* self[];
	BufferedVariableArray()
	{
		self = nullptr;
		length=0;
	}
	//CopyFrom(VariableType* Target){if(self!=nullptr){delete self;}
	//	self = Target;
	//}
	void Delete(){if(self!=nullptr){delete self;self=nullptr;}
		length = 0;
	}
	~BufferedVariableArray()
	{
		if(self!=nullptr){delete self;}
	}
};
#endif
