// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef ArgList_IncludeGuard
#define ArgList_IncludeGuard

#include "ArgStringList.h"
//Ordered map from https://github.com/Tessil/ordered-map
#include "..\tsl\ordered_map.h"

/// <summary>
/// Class named ArgList.
/// Implements the <see cref="tsl::ordered_map{std::string, ValueType}" />
/// </summary>
/// <seealso cref="tsl::ordered_map{std::string, ArgElement}" />
class ArgList : public tsl ::ordered_map<std::string, ArgStringList>
{
public:
    /// <summary>
    /// Use insert if doesn't Already exist, otherwise set the value
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void Add(std::string Key, ArgStringList Value)
    {//https://stackoverflow.com/questions/31792229/how-to-set-a-value-in-an-unordered-map-and-find-out-if-a-new-key-was-added
        this->insert_or_assign(Key, Value);
    }

    /// <summary>
    /// Determines whether the specified target key has key.
    /// </summary>
    /// <param name="TargetKey">The target key.</param>
    /// <returns>bool</returns>
    bool HasKey(std::string TargetKey)
    {
        ArgList::iterator it;
        it = this->find(TargetKey);
        if (it != this->end())
            return true;
        return false;
    }

    /// <summary>
    /// Erases the key(Returns true if key existed).
    /// </summary>
    /// <param name="TargetKey">The target key.</param>
    /// <returns>bool</returns>
    bool Remove(std::string TargetKey)
    {
        ArgList::iterator it;
        it = this->find(TargetKey);
        if (it != this->end())
        {
            erase(it);
            return true;
        }
        return false;
    }
    ArgList(){}
    ~ArgList(){}
};
#endif