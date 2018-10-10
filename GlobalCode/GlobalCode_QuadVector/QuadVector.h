/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef QuadVector_IncludeGuard
#define QuadVector_IncludeGuard

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

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "StringVectorList.h"
#include "VariableList.h"
#else
#include "..\GlobalCode_VariableLists\StringVectorList.h"
#include "..\GlobalCode_VariableLists\VariableList.h"
#endif

class DLL_API QuadVector
{
public:
	double PositionX = 0.0;
	double PositionY = 0.0;
	double PositionZ = 0.0;
	double PositionW = 0.0;
	//Store values in Position in vector
	void StoreInVectorIndex(int index, double TempValue);
	//Get value based on index value
	double GetVectorValue(int index);
	//Reconstruct as string
	std::string ConvertToString();
	//Reconstruct as DoubleList vector
	DoubleList ConvertToDoubleList();
	//Construct QuadVector from String
	void ReadQuadVectorFromString(std::string LineString);
	QuadVector(std::string TempString);
	QuadVector();
	~QuadVector();
};

class DLL_API QuadVectorList : public VariableList < QuadVector >
{
	//************************************
	// Alias for Add(Fix compiler error of thinking Add(TempValue) has TempValue as double)
	// Method:    AddElement
	// FullName:  QuadVectorList::AddElement
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: QuadVector TempValue
	//************************************
	void AddElement(QuadVector TempValue)
	{
		Add(TempValue);
	}
	size_t AddData();
	void ConvertStringToVectorList(std::string Content);
};
#endif
