/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef CustomDictionary_IncludeGuard
#define CustomDictionary_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
    #include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
    #ifndef DLL_API
        #define DLL_API
    #endif
#endif

#include <unordered_map>

template <typename EntryType, typename ValueType>
class DLL_API CustomDictionary : public std::unordered_map<EntryType, ValueType>
{
public:
	/// <summary>
	/// Use insert if doesn't Already exist, otherwise set the value
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void Add(EntryType Key, ValueType Value)
    {//https://stackoverflow.com/questions/31792229/how-to-set-a-value-in-an-unordered-map-and-find-out-if-a-new-key-was-added
		auto p = this->insert({ Key, Value });
		if (!p.second) {
			// overwrite previous value
			p.first->second = Value;

		}
    }
	bool AddOnlyNew(EntryType First, ValueType Second)
	{
		std::pair<EntryType, ValueType> Value = { First, Second };
		auto p = this->insert(Value);
		if (p.second)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//int operator[](const string key)
	//{
	//	return
	//}
	CustomDictionary(){}
	~CustomDictionary(){}
};
#endif