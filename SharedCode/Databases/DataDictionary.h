// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef DataDictionary_IncludeGuard
#define DataDictionary_IncludeGuard

#include "tsl\ordered_map.h"//Ordered map from https://github.com/Tessil/ordered-map
#include "ArgList.h"

/// <summary>
/// Class named DataDictionary.
/// Implements the <see cref="std::unordered_map{unsigned int, DataNode}" />
/// </summary>
/// <seealso cref="std::unordered_map{unsigned int, DataNode}" />
template <typename DataNode>
class DataDictionary : public tsl ::ordered_map<unsigned int, DataNode>
{
private:
    /// <summary>
    /// The next index (Reserve 0 for root/none)
    /// </summary>
    unsigned int NextIndex = 1;
	std::vector<unsigned int> RemovedIndexes;
    unsigned int Add(unsigned int Key, DataNode Value)
    {
        this->insert_or_assign(Key, Value);
        return Key;
        //auto p = this->insert({ Key, Value });
        //if (!p.second) {
        //    // overwrite previous value
        //    p.first->second = Value;
        //}
	}
public:
    /// <summary>
    /// Adds the specified value into next free Index position(Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned int</returns>
    unsigned int Add(DataNode Value)
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
    /// Adds the specified current tag.
    /// </summary>
    /// <param name="CurrentTag">The current tag.</param>
    /// <param name="ArgBuffer">The argument buffer.</param>
    /// <param name="ParentNodeIndex">Index of the parent node.</param>
    /// <returns>unsigned int</returns>
    unsigned int Add(std::string CurrentTag, ArgList ArgBuffer, unsigned int ParentNodeIndex)
    {
        DataNode NewNode = CurrentTag;
        NewNode.ArgData = ArgBuffer;
        NewNode.ParentIndex = ParentNodeIndex;
        return Add(NewNode);
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
    /// Determines whether the specified target index has key.
    /// </summary>
    /// <param name="TargetIndex">Index of the target.</param>
    /// <returns>bool</returns>
    bool HasKey(unsigned int TargetIndex)
    {
        DataDictionary::iterator it;
        it = this->find(TargetIndex);
        if (it != this->end())
            return true;
        return false;
    }
    /// <summary>
    /// Initializes a new instance of the <see cref="DataDictionary"/> class.
    /// </summary>
    DataDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="DataDictionary"/> class.
    /// </summary>
    ~DataDictionary() {}
};
#endif