/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef IndexedDictionary_IncludeGuard
#define IndexedDictionary_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
    #include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
    #ifndef DLL_API
        #define DLL_API
    #endif
#endif

#include "CustomOrderedDictionary.h"
#include "CustomDictionary.h"

template <typename ValueType>
class DLL_API IndexedDictionary : public CustomDictionary<unsigned int, ValueType>
{
private:
	unsigned int NextIndex = 0;
	//bool ReverseIndexSearch = true;//Later might add code to force to search indexes in reverse by default if this is set
public:
	/// <summary>
	/// Use insert if doesn't Already exist, otherwise set the value
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void Add(ValueType Value)
	{
		//if(ReverseIndexSearch){}else{}
		bool Success = AddOnlyNew(NextIndex,Value);
		if(Success){NextIndex++;return;}
		int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
		for(Success=false;!Success||NextIndex==4294967295;Success=AddOnlyNew(NextIndex,Value))
		{
			NextIndex++;
		}
		if(Success){NextIndex++;return;}
		Success = AddOnlyNew(4294967295,Value);
		//ReverseIndexSearch = true;
		if(Success){return;}
		NextIndex = LastIndexSlot;
		for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
		{
			NextIndex--;
		}
	}
	void Remove(EntryType Key)
	{
		NextIndex = Key;
	}
	void clear()
	{
		NextIndex = 0;//Free up all index slots usage as well
	}
	IndexedDictionary(){}
	~IndexedDictionary(){}
};

template <typename ValueType>
class DLL_API IndexedOrderedDictionary : public CustomOrderedDictionary<unsigned int, ValueType>
{
private:
	unsigned int NextIndex = 0;
public:
	/// <summary>
	/// Use insert if doesn't Already exist, otherwise set the value
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void Add(ValueType Value)
	{
		//if(ReverseIndexSearch){}else{}
		bool Success = AddOnlyNew(NextIndex,Value);
		if(Success){NextIndex++;return;}
		int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
		for(Success=false;!Success||NextIndex==4294967295;Success=AddOnlyNew(NextIndex,Value))
		{
			NextIndex++;
		}
		if(Success){NextIndex++;return;}
		Success = AddOnlyNew(4294967295,Value);
		//ReverseIndexSearch = true;
		if(Success){return;}
		NextIndex = LastIndexSlot;
		for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
		{
			NextIndex--;
		}
	}
	void Remove(EntryType Key)
	{
		NextIndex = Key;
	}
	void clear()
	{
		NextIndex = 0;//Free up all index slots usage as well
	}
	IndexedDictionary(){}
	~IndexedDictionary(){}
};

template <typename ValueType>
class DLL_API IndexedLongDictionary: public CustomDictionary<unsigned _int64, ValueType>
{
private:
	unsigned _int64 NextIndex = 0;
public:
	/// <summary>
	/// Use insert if doesn't Already exist, otherwise set the value
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void Add(ValueType Value)
	{
		bool Success = AddOnlyNew(NextIndex,Value);
		if(Success){NextIndex++;return;}
		int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
		for(Success=false;!Success||NextIndex==18446744073709551615;Success=AddOnlyNew(NextIndex,Value))
		{
			NextIndex++;
		}
		if (Success) { NextIndex++; return; }
		Success = AddOnlyNew(18446744073709551615,Value);//Unlikely to require getting past this point but just in case
		if (Success) { return; }
		NextIndex = LastIndexSlot;
		for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
		{
			NextIndex--;
		}
	}
	void Remove(EntryType Key)
	{
		NextIndex = Key;
	}
	void clear()
	{
		NextIndex = 0;//Free up all index slots usage as well
	}
	IndexedLongDictionary(){}
	~IndexedLongDictionary(){}
};

template <typename ValueType>
class DLL_API IndexedOrderedLDictionary: public CustomOrderedDictionary<unsigned _int64, ValueType>
{
private:
	unsigned _int64 NextIndex = 0;
public:
	/// <summary>
	/// Use insert if doesn't Already exist, otherwise set the value
	/// </summary>
	/// <param name="Key">The key.</param>
	/// <param name="Value">The value.</param>
	void Add(ValueType Value)
	{
		bool Success = AddOnlyNew(NextIndex,Value);
		if (Success) { NextIndex++; return; }
		int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
		for(Success=false;!Success||NextIndex==18446744073709551615;Success=AddOnlyNew(NextIndex,Value))
		{
			NextIndex++;
		}
		if (Success) { NextIndex++; return; }
		Success = AddOnlyNew(18446744073709551615,Value);//Unlikely to require getting past this point but just in case
		if (Success) { return; }
		NextIndex = LastIndexSlot;
		for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
		{
			NextIndex--;
		}
	}
	void Remove(EntryType Key)
	{
		NextIndex = Key;
	}
	void clear()
	{
		NextIndex = 0;//Free up all index slots usage as well
	}
	IndexedOrderedLDictionary(){}
	~IndexedOrderedLDictionary(){}
};
#endif