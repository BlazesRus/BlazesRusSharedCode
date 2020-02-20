/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#if !defined(BufferedVariableArray_IncludeGuard) && !defined(ExcludeExperimentalCode)
#define BufferedVariableArray_IncludeGuard

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
