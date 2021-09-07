/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once
#if !defined(BufferedVariable_IncludeGuard) && !defined(ExcludeExperimentalCode)
#define BufferedVariable_IncludeGuard

#ifdef BlazesSharedCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesSharedCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESSharedCode_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

template <typename VariableTypeP>
class BufferedVariable
{public:
	VariableTypeP self;
	BufferedVariable()
	{
		self = nullptr;
	}
	void CopyFrom(VariableTypeP Target)
	{
		if(self!=nullptr){delete self;}
		self = Target;
	}
	void Delete(){if(self!=nullptr){delete self;self=nullptr;}}
	~BufferedVariable()
	{
		if(self!=nullptr){delete self;}
	}
};
#endif
