// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include "..\OtherFunctions\VariableConversionFunctions.h"

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

#if defined IndexedIniData_AddAltDecSupport || defined IndexedIniData_ReplaceFloatWithAltDec
#include "..\AltNum\AltDec.h"
#endif

class DLL_API IndexedIniData : public std::unordered_map<std::string, short>
{
public:
    class IndexedIniDataResult
    {
    public:
        int IntResult = 0;
#ifndef ExpFormula_ReplaceAllFloat
        float FResult = 0.0f;
#endif
        bool BResult = false;
#if defined IndexedIniData_AddAltDecSupport || defined IndexedIniData_ReplaceFloatWithAltDec
        AltDec AltResult = AltDec::Zero;
#endif
        //0 = Bool; 1= Int; 2= Float; 3 = AltDec
        short ResultType = 0;

#ifndef IndexedIniData_ReplaceFloatWithAltDec
        void SetVal(float Value)
        {
            FResult = Value;
            ResultType = 2;
        }
#endif

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(int Value)
        {
            IntResult = Value;
            ResultType = 1;
        }
#if defined ExpFormula_AltDecFromXml || defined ExpFormula_ReplaceAllFloat
        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(AltDec Value)
        {
            AltResult = Value;
            ResultType = 3;
        }
#endif

        IndexedIniDataResult()
        {
            IntResult = 0;
#ifndef ExpFormula_ReplaceAllFloat
            FResult = 0.0f;
#endif
            BResult = false;
#if defined ExpFormula_AltDecFromXml || defined ExpFormula_ReplaceAllFloat
            AltResult = AltDec::Zero;
#endif
            ResultType = 0;
        }
    };
public:
    int LastAdded = -1;

#ifndef IndexedIniData_ReplaceFloatWithAltDec
    std::unordered_map<int, float> FloatMap;
#endif
    std::unordered_map<int, int> IntMap;
#if defined IndexedIniData_AddAltDecSupport || defined IndexedIniData_ReplaceFloatWithAltDec
    std::unordered_map<int, AltDec> AltMap;
#endif
private:
    /// <summary>
    /// The next index
    /// </summary>
    int NextIndex = 0;
    std::vector<int> RemovedIndexes;
    unsigned int Add(unsigned int Key, std::string Value)
    {
        this->insert_or_assign(Key, Value);
        return Key;
    }
protected:
    /// <summary>
    /// The element type or StringVariable
    /// #i = integer value; #f = float value;  #A = AltDec Value
    /// true/false for boolean values
    /// </summary>
    //std::string ElementType;

    /// <summary>
    /// Adds the specified value into next free Index position(Returns index of new value)
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>unsigned int</returns>
    int Add(std::string Value)
    {
        int IndexPos;
        if (RemovedIndexes.empty())//Adds new Indexes in order
        {
            IndexPos = NextIndex;
            Add(NextIndex, Value);
            NextIndex++; return IndexPos;
        }
        else//Otherwise adds based on last removed key
        {
            int TargetIndex = RemovedIndexes.back();
            Add(TargetIndex, Value);
            RemovedIndexes.pop_back();
            return TargetIndex;
        }
    }

    /// <summary>
    /// Removes the specified key.
    /// </summary>
    /// <param name="Key">The key.</param>
    void Remove(int Key)
    {
        this->erase(Key);
        RemovedIndexes.push_back(Key);
    }
public:
#ifndef IndexedIniData_ReplaceFloatWithAltDec
    /// <summary>
    /// Replaces the non-number based form value (and add to number map).
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void ReplaceFormVal(int Key, float Value)
    {
        std::string& KeyedVal = this->at(Key);
        KeyedVal.ElementType = "#f";
        FloatMap.insert_or_assign(Key, Value);
    }
#endif

    /// <summary>
    /// Replaces the non-number based form value (and add to number map).
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void ReplaceFormVal(int Key, int Value)
    {
        std::string& KeyedVal = this->at(Key);
        KeyedVal.ElementType = "#i";
        IntMap.insert_or_assign(Key, Value);
    }

    /// <summary>
    /// Replaces the non-number based form value.
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void ReplaceFormVal(int Key, bool Value)
    {
        std::string& KeyedVal = this->at(Key);
        if (Value) { KeyedVal.ElementType = "true"; }
        else { KeyedVal.ElementType = "false"; }
    }

#if defined IndexedIniData_AddAltDecSupport || defined IndexedIniData_ReplaceFloatWithAltDec
    /// <summary>
    /// Replaces the non-number based form value (and add to number map).
    /// </summary>
    /// <param name="Key">The key.</param>
    /// <param name="Value">The value.</param>
    void ReplaceFormVal(int Key, AltDec Value)
    {
        std::string& KeyedVal = this->at(Key);
        KeyedVal.ElementType = "#A";
        AltMap.insert_or_assign(Key, Value);
    }
#endif

    /// <summary>
    /// Clears this instance.
    /// </summary>
    void clear()
    {
        NextIndex = 0;//Free up all index slots usage as well
        RemovedIndexes.clear();
    }

    /// <summary>
    /// Adds the specified value.
    /// </summary>
    /// <param name="Value">The value.</param>
    void Add(std::string Value)
    {
        LastAdded = Add(std::string(Value));
    }

#ifndef IndexedIniData_ReplaceFloatWithAltDec
    /// <summary>
    /// Adds the float value to map
    /// </summary>
    /// <param name="Value">The value.</param>
    void AddValue(float Value)
    {
        LastAdded = Add(std::string("#f"));
        FloatMap.insert_or_assign(LastAdded, Value);
    }

    /// <summary>
    /// Adds the float value to map
    /// </summary>
    /// <param name="Value">The value.</param>
    void AddF(std::string Value)
    {
        float Value = VariableConversionFunctions::ReadFloatFromString(Value);
        AddF(Value);
    }
#endif

    void AddValue(int Value)
    {
        LastAdded = Add(std::string("#i"));
        IntMap.insert_or_assign(LastAdded, Value);
    }

    void AddI(std::string Value)
    {
        int Value = VariableConversionFunctions::ReadIntFromString(Value);
        AddI(Value);
    }

    void AddValue(bool Value)
    {
        LastAdded = Add(Value ? std::string() : std::string("false"));
    }

    EvalResult GetValue(IndexedIniData::iterator& targetIterator)
    {
        EvalResult targetResult;
        targetResult.SetVal(targetIterator->second.ElementType == "true" ? 1 : (targetIterator->second.ElementType == "false" ? 0 : (targetIterator->second.ElementType == "#i" ? IntMap[targetIterator->first] :
#ifdef IndexedIniData_ReplaceFloatWithAltDec
            AltMap[targetIterator->first])));
#elif IndexedIniData_AddAltDecSupport
            targetIterator->second.ElementType == "#A" ? AltMap[targetIterator->first] : FloatMap[targetIterator->first])));
#else
            FloatMap[targetIterator->first])));
#endif
        return targetResult;
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="IndexedIniData"/> class.
    /// </summary>
    IndexedIniData() {}
    /// <summary>
    /// Finalizes an instance of the <see cref="IndexedIniData"/> class.
    /// </summary>
    ~IndexedIniData() {}
};