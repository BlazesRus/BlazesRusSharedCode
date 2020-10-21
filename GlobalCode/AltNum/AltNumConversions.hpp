// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once

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

#include "MediumDec.hpp"
#include <boost/multiprecision/cpp_int.hpp>

namespace BlazesRusCode
{
	using UInt128 = boost::multiprecision::uint128_t;
	//using Int128Dec = boost::multiprecision::;
	/*
	MediumDec ToMediumDec(Int128Dec value)
	{
	
	}
	
	Int128Dec ToInt128Dec(MediumDec value)
	{
	
	}
	*/
}