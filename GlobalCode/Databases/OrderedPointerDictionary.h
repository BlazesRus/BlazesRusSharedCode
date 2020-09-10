// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once
#ifndef OrderedPointerDictionary_IncludeGuard
#define OrderedPointerDictionary_IncludeGuard

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
/// Class named OrderedPointerDictionary.
/// Implements the <see cref="tsl::ordered_map{EntryType, ValueType*}" />
/// </summary>
/// <seealso cref="tsl::ordered_map{EntryType, ValueType*}" />
template <typename EntryType, typename ValueType>
class DLL_API OrderedPointerDictionary : public tsl ::ordered_map<EntryType, ValueType*>
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
    /// <summary>
    /// Adds the empty.
    /// </summary>
    /// <param name="Key">The key.</param>
    void AddEmpty(EntryType Key)
    {//https://stackoverflow.com/questions/31792229/how-to-set-a-value-in-an-unordered-map-and-find-out-if-a-new-key-was-added
        auto p = this->insert({ Key, nullptr });
        //if (!p.second) {
        //	// overwrite previous value
        //	p.first->second = nullptr;
        //}
    }
    /// <summary>
    /// Adds the only new.
    /// </summary>
    /// <param name="First">The first.</param>
    /// <param name="Second">The second.</param>
    void AddOnlyNew(EntryType First, ValueType Second)
    {
        std::pair<EntryType, ValueType> Value = { First, Second };
        this->insert(Value);
    }
    //int operator[](const string key)
    //{
    //	return
    //}
/// <summary>
/// Initializes a new instance of the <see cref="OrderedPointerDictionary"/> class.
/// </summary>
    OrderedPointerDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="OrderedPointerDictionary"/> class.
    /// </summary>
    ~OrderedPointerDictionary()
    {
        for (auto& it : this)
        {
            if (it.second != nullptr)
            {
                delete it.second;
            }
        }
    }
};
#endif