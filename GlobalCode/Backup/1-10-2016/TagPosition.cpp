#include "TagPosition.h"
#include "StringFunctions.h"

string TagPosition::PositionString()
{
	string PositionString = ParentIndexPosition.GenerateAsString();
	PositionString += "-";
	PositionString += StringFunctions::IntToStringConversion(ListPosition);
	return PositionString;
}