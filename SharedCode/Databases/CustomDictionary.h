// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#ifndef CustomDictionary_IncludeGuard
#define CustomDictionary_IncludeGuard

#ifdef BlazesSharedCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesSharedCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESSharedCode_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include <unordered_map>

/// <summary>
/// Class named CustomDictionary.
/// Implements the <see cref="std::unordered_map{EntryType, ValueType}" />
/// </summary>
/// <seealso cref="std::unordered_map{EntryType, ValueType}" />
template <typename EntryType, typename ValueType>
class DLL_API CustomDictionary : public std::unordered_map<EntryType, ValueType>
{
public:
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value (Returns True if adds new non-existing element)
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    bool Add(EntryType Key, ValueType Value)
    {//https://stackoverflow.com/questions/31792229/how-to-set-a-value-in-an-unordered-map-and-find-out-if-a-new-key-was-added
        auto p = this->insert({ Key, Value });
        if (!p.second) {
            // overwrite previous value
            p.first->second = Value;
            return false;
        }
        else
            return true;
    }

    /// <summary>
    /// Use insert if doesn't Already exist(Return true on success)
    /// </summary>
    /// <param name="First">The first.</param>
    /// <param name="Second">The second.</param>
    /// <returns>bool.</returns>
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
    /// <summary>
    /// Initializes a new instance of the <see cref="CustomDictionary"/> class.
    /// </summary>
    CustomDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="CustomDictionary"/> class.
    /// </summary>
    ~CustomDictionary() {}
};
#endif