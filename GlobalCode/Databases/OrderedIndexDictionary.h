// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef OrderedIndexDictionary_IncludeGuard
#define OrderedIndexDictionary_IncludeGuard

#ifdef BlazesGlobalCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesGlobalCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESGLOBALCODE_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include "..\tsl\ordered_map.h"//Ordered map from https://github.com/Tessil/ordered-map

/// <summary>
/// Class named OrderedIndexDictionary.
/// Implements the <see cref="std::unordered_map{unsigned int, ValueType}" />
/// </summary>
/// <seealso cref="std::unordered_map{unsigned int, ValueType}" />
template <typename ValueType>
class DLL_API OrderedIndexDictionary : public tsl ::ordered_map<unsigned int, ValueType>
{
private:
    /// <summary>
    /// The next index (Reserve 0 for root/none)
    /// </summary>
    unsigned int NextIndex = 1;
	std::vector<unsigned int> RemovedIndexes;
    unsigned int Add(unsigned int Key, ValueType Value)
    {
        this->insert_or_assign(Key, Value);
        return Key;
	}
public:
    /// <summary>
    /// Adds the specified value into next free Index position(Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned int</returns>
    unsigned int Add(ValueType Value)
    {
        unsigned int IndexPos;
		if(RemovedIndexes.empty())//Adds new Indexes in order
		{
			IndexPos = NextIndex;
			Add(NextIndex, Value);
			NextIndex++;return IndexPos;
		}
		else//Otherwise adds based on last removed key
		{
			unsigned int TargetIndex = RemovedIndexes.back();
			Add(TargetIndex, Value);
			RemovedIndexes.pop_back();
			return TargetIndex;
		}
    }
    /// <summary>
    /// Removes the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    void Remove(unsigned int Key)
    {
		this->erase(Key);
		RemovedIndexes.push_back(Key);
    }
    /// <summary>
    /// Clears this instance.
    /// </summary>
    void clear()
    {
        NextIndex = 0;//Free up all index slots usage as well
		RemovedIndexes.clear();
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="OrderedIndexDictionary"/> class.
    /// </summary>
    OrderedIndexDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="OrderedIndexDictionary"/> class.
    /// </summary>
    ~OrderedIndexDictionary() {}
};
#endif