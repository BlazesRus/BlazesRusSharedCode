/*	Code Created by James Michael Armstrong(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once

#include "..\DLLAPI.h"

#include "CustomOrderedDictionary.h"

//Ordered Custom Dictionary for string keys with unsigned int values
class DLL_API UIntDic : public CustomOrderedDictionary<std::string, unsigned int>{};