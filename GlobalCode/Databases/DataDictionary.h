// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#ifndef BasicDataDictionary_IncludeGuard
#define BasicDataDictionary_IncludeGuard

#include "tsl\ordered_map.h"//Ordered map from https://github.com/Tessil/ordered-map

/// <summary>
/// Class named BasicDataDictionary.
/// Implements the <see cref="std::unordered_map{std::string, DataNode}" />
/// </summary>
/// <seealso cref="std::unordered_map{std::string, DataNode}" />
template <typename DataNode>
class BasicDataDictionary : public tsl ::ordered_map<unsigned int, DataNode>
{
private:
    /// <summary>
    /// The next index (Reserve 0 for root/none)
    /// </summary>
    unsigned int NextIndex = 1;
	std::vector<unsigned int> RemovedIndexes;
    unsigned int Add(unsigned int Key, DataNode Value)
    {
        auto p = this->insert({ Key, Value });
        if (!p.second) {
            // overwrite previous value
            p.first->second = Value;
        }
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
		if(RemoveIndexes.empty())//Adds new Indexes in order
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
		this.erase(key);
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
    /// Initializes a new instance of the <see cref="BasicDataDictionary"/> class.
    /// </summary>
    BasicDataDictionary() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="BasicDataDictionary"/> class.
    /// </summary>
    ~BasicDataDictionary() {}
};
#endif