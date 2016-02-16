/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef QuadVectorFunctions_IncludeGuard
#define QuadVectorFunctions_IncludeGuard

#include "QuadVector.h"
#include <string>

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