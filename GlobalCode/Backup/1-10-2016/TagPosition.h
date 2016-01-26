#pragma once

#include "VariableList.h" //This is Just Custom Derivatative Vector <VariableType> (Also using std::string here)
#include "VariableTypeLists.h" //Holds VariableList<Integer> and includes header containing VariableList<string>

class TagPosition
{
public:
	//Example ParentIndexPosition="0_1"
	IntegerList ParentIndexPosition;
	//Index in CurrentList
	int ListPosition = -1;
	void IncreaseListPos()
	{
		ListPosition += 1;
	}
	void IncreaseParentIndex()
	{
		ParentIndexPosition.Add(ListPosition);
		ListPosition = -1;
	}
	//************************************
	// Returns String in format ParentIndexPosition(Index:0)_ParentIndexPosition(Index:1)-ListPosition
	// Method:    PositionString
	// FullName:  TagData::TagPosition::PositionString
	// Access:    public
	// Returns:   string
	// Qualifier:
	//************************************
	string PositionString();
};