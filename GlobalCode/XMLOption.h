#pragma once
#include <string>
#include "..\GlobalCode\VariableList.h"
class XMLOption
{
public:
	std::string OptionName = "";
	//Value Stored inside Option
	//[[NULL--VALUE]] or "None" = No Value Stored
	//"Undetermined" or "" = Undefined (Default)
	std::string ValueType = "";
	std::string ValueString = "";
	//Value not Stored in Arg within String inside Parenthesis
	bool ValueNotInParenthesis = false;
	XMLOption(std::string Name, std::string Value)
	{
		OptionName = Name;
		ValueString = Value;
		//Auto-Detect ValueType
		if(Value == "[[NULL--VALUE]]")
		{
			ValueType = "None";
		}
		else
		{
			ValueType = "Undetermined";
		}
	}
	XMLOption();
	~XMLOption();
};

class XMLOptionList : public VariableList < XMLOption >
{
public:
	//************************************
	// Returns check for if Option with name OptionNameTemp found within
	// Method:    HasOption
	// FullName:  XMLOptionList::HasOption
	// Access:    public
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string OptionNameTemp
	//************************************
	bool HasOption(std::string OptionNameTemp);
	//************************************
	// Returns Value of OptionArg named OptionNameTemp
	// Method:    GetOptionValue
	// FullName:  XMLOptionList::GetOptionValue
	// Access:    public
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string OptionNameTemp
	//************************************
	std::string GetOptionValue(std::string OptionNameTemp);
	void AddOption(std::string NameTemp, std::string ValueTemp)
	{
		XMLOption OptionToAdd;
		OptionToAdd.OptionName = NameTemp;
		OptionToAdd.ValueString = ValueTemp;
		Add(OptionToAdd);
	}
};