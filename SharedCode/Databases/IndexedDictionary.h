// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#ifndef IndexedDictionary_IncludeGuard
#define IndexedDictionary_IncludeGuard

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

#include "CustomOrderedDictionary.h"
#include "CustomDictionary.h"
#include <string>

/// <summary>
/// Class named IndexedDictionary.
/// Implements the <see cref="CustomDictionary{unsigned int, ValueType}" />
/// </summary>
/// <seealso cref="CustomDictionary{unsigned int, ValueType}" />
template <typename ValueType>
class DLL_API IndexedDictionary :public CustomDictionary<unsigned int, ValueType>
{
private:
    /// <summary>
    /// The next index
    /// </summary>
    unsigned int NextIndex = 0;
    //bool ReverseIndexSearch = true;//Later might add code to force to search indexes in reverse by default if this is set
public:
    /// <summary>
    /// Adds the specified value into next free Index position(Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned int</returns>
    unsigned int Add(ValueType Value)
    {
        unsigned int IndexPos;
        bool Success = AddOnlyNew(NextIndex, Value);
        if (Success) { NextIndex++; return; }
        int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
        for (Success = false; !Success || NextIndex == 4294967295; Success = AddOnlyNew(NextIndex, Value))
        {
            NextIndex++;
        }
        if (Success) { IndexPos = NextIndex; NextIndex++; return IndexPos; }
        NextIndex = LastIndexSlot;
        for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
        {
            NextIndex--;
        }
        return IndexPos;
    }
    /// <summary>
    /// Removes the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    void Remove(unsigned int Key)
    {
        NextIndex = Key;
    }
    /// <summary>
    /// Clears this instance.
    /// </summary>
    void clear()
    {
        NextIndex = 0;//Free up all index slots usage as well
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="IndexedDictionary"/> class.
    /// </summary>
    IndexedDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="IndexedDictionary"/> class.
    /// </summary>
    ~IndexedDictionary() {}
};

/// <summary>
/// Class named IndexedLongDictionary.
/// Implements the <see cref="CustomDictionary{unsigned _int64, ValueType}" />
/// </summary>
/// <seealso cref="CustomDictionary{unsigned _int64, ValueType}" />
template <typename ValueType>
class DLL_API IndexedLongDictionary : public CustomDictionary<unsigned _int64, ValueType>
{
public:
    //Reserve Maxed value for NULL representation
/// <summary>
/// The null
/// </summary>
    static const unsigned __int64 NullRep = 18446744073709551615;
private:
    /// <summary>
    /// The next index
    /// </summary>
    unsigned _int64 NextIndex = 0;
public:
    /// <summary>
    /// Adds the specified value into next free Index position. (Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned _int64</returns>
    unsigned _int64 Add(ValueType Value)
    {
        unsigned _int64 IndexPos;
        bool Success = AddOnlyNew(NextIndex, Value);
        if (Success) { NextIndex++; return; }
        int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
        for (Success = false; !Success || NextIndex == 18446744073709551614; Success = AddOnlyNew(NextIndex, Value))
        {
            NextIndex++;
        }
        if (Success) { IndexPos = NextIndex; NextIndex++; return IndexPos; }
        if (Success) { return; }
        NextIndex = LastIndexSlot;
        for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
        {
            NextIndex--;
        }
        return IndexPos;
    }

    /// <summary>
    /// Removes the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    void Remove(unsigned _int64 Key)
    {
        NextIndex = Key;
    }
    /// <summary>
    /// Clears this instance.
    /// </summary>
    void clear()
    {
        NextIndex = 0;//Free up all index slots usage as well
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="IndexedLongDictionary"/> class.
    /// </summary>
    IndexedLongDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="IndexedLongDictionary"/> class.
    /// </summary>
    ~IndexedLongDictionary() {}
};

template <typename TreeNode> class NodeDictionary : public IndexedLongDictionary<TreeNode>
{
public:
    /// <summary>
    /// Adds fresh node with DisplayName of displayName.
    /// </summary>
    /// <param name="displayName">The display name.</param>
    /// <returns>unsigned __int64</returns>
    unsigned __int64 AddNode(std::string displayName)
    {
        TreeNode newNode;
        newNode.DisplayName = displayName;
        return Add(newNode);
    }
};

/// <summary>
/// Class named IndexedOrderedLDictionary.
/// Implements the <see cref="CustomOrderedDictionary{unsigned _int64, ValueType}" />
/// </summary>
/// <seealso cref="CustomOrderedDictionary{unsigned _int64, ValueType}" />
template <typename ValueType>
class DLL_API IndexedOrderedLDictionary : public CustomOrderedDictionary<unsigned _int64, ValueType>
{
public:
    //Reserve Maxed value for NULL representation
/// <summary>
/// The null
/// </summary>
    static const unsigned __int64 NullRep = 18446744073709551615;
private:
    /// <summary>
    /// The next index
    /// </summary>
    unsigned _int64 NextIndex = 0;
public:
    /// <summary>
    /// Adds the specified value into next free Index position. (Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned _int64</returns>
    unsigned _int64 Add(ValueType Value)
    {
        unsigned _int64 IndexPos;
        bool Success = AddOnlyNew(NextIndex, Value);
        if (Success) { NextIndex++; return; }
        int LastIndexSlot = NextIndex;//Check higher indexes first so save information of last index to check in reverse later
        for (Success = false; !Success || NextIndex == NullRep; Success = AddOnlyNew(NextIndex, Value))
        {
            NextIndex++;
        }
        if (Success) { IndexPos = NextIndex; NextIndex++; return IndexPos; }
        if (Success) { return; }
        NextIndex = LastIndexSlot;
        for (Success = false; !Success || NextIndex == 0; Success = AddOnlyNew(NextIndex, Value))//Search in reverse for slots now
        {
            NextIndex--;
        }
        return IndexPos;
    }
    /// <summary>
    /// Removes the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    void Remove(unsigned _int64 Key)
    {
        NextIndex = Key;
    }
    /// <summary>
    /// Clears this instance.
    /// </summary>
    void clear()
    {
        NextIndex = 0;//Free up all index slots usage as well
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="IndexedOrderedLDictionary"/> class.
    /// </summary>
    IndexedOrderedLDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="IndexedOrderedLDictionary"/> class.
    /// </summary>
    ~IndexedOrderedLDictionary() {}
};
#endif