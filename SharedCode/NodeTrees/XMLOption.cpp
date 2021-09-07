/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "XMLOption.h"


XMLOption::XMLOption()
{}

XMLOption::~XMLOption()
{}

bool XMLOptionList::HasOption(std::string OptionNameTemp)
{
    bool OptionFound = false;
    size_t ListSize = Size();
    XMLOption* OptionPointer;
    for(size_t i = 0; i < ListSize&&OptionFound == false; ++i)
    {
        OptionPointer = this->GetElementPointerV2(i);
        if(OptionPointer->OptionName == OptionNameTemp)
        {
            OptionFound = true;
        }
    }
    return OptionFound;
}

std::string XMLOptionList::GetOptionValue(std::string OptionNameTemp)
{
    std::string OptionValue = "";
    bool OptionFound = false;
    size_t ListSize = Size();
    XMLOption* OptionPointer;
    for(size_t i = 0; i < ListSize&&OptionFound == false; ++i)
    {
        OptionPointer = this->GetElementPointerV2(i);
        if(OptionPointer->OptionName == OptionNameTemp)
        {
            OptionFound = true;
            OptionValue = OptionPointer->ValueString;
        }
    }
    if(OptionFound == false)
    {
        std::cout << "Error:Option with name " << OptionNameTemp << " not found. Returning Default value of \"\"\n";
    }
    return OptionValue;
}
