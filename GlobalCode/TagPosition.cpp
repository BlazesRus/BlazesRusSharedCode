#include "TagPosition.h"
#include "StringFunctions.h"

std::string TagPosition::PositionString()
{
	std::string PositionString = ParentIndexPosition.GenerateAsString();
	PositionString += "-";
	PositionString += StringFunctions::IntToStringConversion(ListPosition);
	return PositionString;
}