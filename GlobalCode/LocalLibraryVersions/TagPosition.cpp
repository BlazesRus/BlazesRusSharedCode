/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "TagPosition.h"
#include "VariableConversionFunctions.h"

std::string TagPosition::PositionString()
{
	std::string PositionString = ParentIndexPosition.GenerateAsString();
	PositionString += "-";
	PositionString += VariableConversionFunctions::XIntToStringConversion(ListPosition);
	return PositionString;
}