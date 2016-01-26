#pragma once
#include <string>
class VariableData
{
public:
	std::string VariableName;
	std::string VariableType;
	std::string VariableValue_String;
	//************************************
	// Construct for creating variable via (VariableName,VariableType,VariableValue) string Arg
	// Method:    VariableData
	// FullName:  VariableData::VariableData
	// Access:    public
	// Returns:
	// Qualifier:
	// Parameter: std::string StringData
	//************************************
	VariableData(std::string StringData);
	VariableData() {};
	~VariableData() {};
};
