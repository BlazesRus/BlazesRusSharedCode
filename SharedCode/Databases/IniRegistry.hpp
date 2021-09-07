/*	Code Created by James Michael Armstrong(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once

#include "..\AltNum\MediumDec.hpp"
#include <vector>

#include "..\DLLAPI.h"

class DLL_API IniRegistryEntry
{

}

//Add only focused storage for multiple datatypes (Similar to IndexedIniData)
class DLL_API IniRegistry : public std::unordered_map<std::string, short>
{
public:
	std::vector<bool> BoolStore;
	std::vector<MediumDec> AltStore;
	std::vector<std::string> StringStore;
    /// <summary>
    /// Initializes a new instance of the <see cref="IndexedIniData"/> class.
    /// </summary>
    IniRegistry() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="IndexedIniData"/> class.
    /// </summary>
    ~IniRegistry() {}
};