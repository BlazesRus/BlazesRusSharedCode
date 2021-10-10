/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once
#ifndef VariableData_IncludeGuard
#define VariableData_IncludeGuard

#include <string>

//Used for arg parameters of xml tags
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
#endif
