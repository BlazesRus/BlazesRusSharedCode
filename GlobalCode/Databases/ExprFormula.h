// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include "..\OtherFunctions\VariableConversionFunctions.h"

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

#include "..\tsl\ordered_map.h"

//#define ExpFormula_AltDecSupport//Replaces float storage for non-integer numbers from XML if toggled in project file(Toggle not finished)
//#define ExpFormula_ReplaceAllFloat//Replace all usage of float with own AltDec class(Toggle not finished)

#if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat 
#include "..\AltNum\AltDec.h"
#endif
#if defined ExpFormula_ImportIndexedIniData//Enable using IndexedIniData to load variable definitions
#include "IndexedIniData.h"
#endif
#if defined ExpFormula_ImportIniDataV2//Enable using IniDataV2 to load variable definitions
#include "IniDataV2.h"
#endif

namespace BlazesRusCode
{
    class DLL_API EvalResult
    {
    public:
        int IntResult = 0;
    #ifndef ExpFormula_ReplaceAllFloat
        float FResult = 0.0f;
    #endif
        bool BResult = false;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
        AltDec AltResult = AltDec::Zero;
    #endif
        //0 = Bool; 1= Int; 2= Float; 3 = AltDec
        short ResultType = 0;

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void clear()
        {
            IntResult = 0;
    #ifndef ExpFormula_ReplaceAllFloat
            FResult = 0.0f;
    #endif
            BResult = false;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            AltResult = 0;
    #endif
            ResultType = 0;
        }

    #ifndef ExpFormula_ReplaceAllFloat
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
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
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

        friend bool operator==(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch(self.ResultType)
                {
                case 1://Int
                    return self.IntResult == Value.IntResult;
                    break;
                case 2:
                    return self.FResult == Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult == Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult == Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1?self.IntResult:self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue == RValue;
            }
        }

        friend bool operator!=(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch (self.ResultType)
                {
                case 1://Int
                    return self.IntResult != Value.IntResult;
                    break;
                case 2:
                    return self.FResult != Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult != Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult != Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue != RValue;
            }
        }

        friend bool operator<(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch (self.ResultType)
                {
                case 1://Int
                    return self.IntResult < Value.IntResult;
                    break;
                case 2:
                    return self.FResult < Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult < Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult < Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue < RValue;
            }
        }

        friend bool operator<=(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch (self.ResultType)
                {
                case 1://Int
                    return self.IntResult <= Value.IntResult;
                    break;
                case 2:
                    return self.FResult <= Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult <= Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult <= Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue <= RValue;
            }
        }

        friend bool operator>(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch (self.ResultType)
                {
                case 1://Int
                    return self.IntResult > Value.IntResult;
                    break;
                case 2:
                    return self.FResult > Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult > Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult > Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue > RValue;
            }
        }

        friend bool operator>=(EvalResult& self, EvalResult& Value)
        {
            if (self.ResultType == Value.ResultType)
            {
                switch (self.ResultType)
                {
                case 1://Int
                    return self.IntResult >= Value.IntResult;
                    break;
                case 2:
                    return self.FResult >= Value.FResult;
                    break;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                case 3:
                    return self.FResult >= Value.FResult;
                    break;
    #endif
                default://Bool
                    return self.BResult >= Value.BResult;
                    break;
                }
            }
            else
            {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                AltDec LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                AltDec RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #else
                auto LValue = self.ResultType == 0 ? self.BResult : self.ResultType == 1 ? self.IntResult : self.FResult;
                auto RValue = Value.ResultType == 0 ? Value.BResult : Value.ResultType == 1 ? Value.IntResult : Value.FResult;
    #endif
                return LValue >= RValue;
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="EvalResult"/> class.
        /// </summary>
        EvalResult()
        {
            IntResult = 0;
    #ifndef ExpFormula_ReplaceAllFloat
            FResult = 0.0f;
    #endif
            BResult = false;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            AltResult = AltDec::Zero;
    #endif
            ResultType = 0;
        }
    };

    class DLL_API ExprFormElement
    {
    public:
        /// <summary>
        /// The element type
        /// ? = TernaryOperator; #i = integer value; #f = float value; @ = Formula Val; $+Value = Increment/Decrement Op; #A = AltDec/AltDec Value
        /// true/false for boolean values
        /// </summary>
        std::string ElementType;
        /// <summary>
        /// (Primarily used for FormElements, ++,--, and TernaryOperator)
        /// The index/Key position of stored element (not used for variable names or booleans)(Might not even be needed for most values since matches key)
        //   For Increment/Decrement Op:
        //   0 = Prefix ++
        //   1 = Prefix --
        //   2 = Postfix ++
        //   3 = Postfix --
        /// </summary>
        int Index;

        /// <summary>
        /// Initializes a new instance of the <see cref="ExprFormElement"/> class. (Defaults as boolean with true value)
        /// </summary>
        ExprFormElement()
        {
            ElementType = "true";
            Index = 0;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ExprFormElement"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="index">The index.</param>
        ExprFormElement(std::string Value, int index = 0)
        {
            ElementType = Value;
            Index = index;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ExprFormElement"/> class for PostFix OpValue.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="opBuffer">The operator value.</param>
        ExprFormElement(std::string Value, std::string opBuffer)
        {
            if (opBuffer == "++") { Index = 2; }
            else { Index = 3; }
            ElementType = "$" + Value;
        }
    };

    /// <summary>
    /// Class EvalValueData. (Variant of OrderedIndexDictionary)
    /// Implements the <see cref="tsl::ordered_map{unsigned int, ExprFormElement}" />
    /// </summary>
    /// <seealso cref="tsl::ordered_map{unsigned int, ExprFormElement}" />
    class DLL_API EvalValueData : public tsl::ordered_map<int, ExprFormElement>
    {
    private:
        using IntVector = std::vector<int>;
        //protected:
        //    class TernaryOperator
        //    {
        //        std::vector<ExprFormElement> Condition;
        //        std::vector<ExprFormElement> ExpIfTrue;
        //        std::vector<ExprFormElement> ExpIfFalse;
        //        std::vector<int> IntValues;
        //        std::vector<float> FloatValues;
        //    };
    public:
        ///// <summary>
        ///// Vector referring to keys in formula
        ///// </summary>
        //std::vector<int> FormData;
        int LastAdded = -1;

        /// <summary>
        /// Map of operation Index Values by with key storing precedence category (of those used for formula code) starting from zero
        /// </summary>
        std::vector<IntVector> OpOrderMap;

    #ifndef ExpFormula_ReplaceAllFloat
        std::unordered_map<int, float> FloatMap;
    #endif
        std::unordered_map<int, int> IntMap;
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
        std::unordered_map<int, AltDec> AltMap;
    #endif
    private:
        /// <summary>
        /// The next index
        /// </summary>
        int NextIndex = 0;
        std::vector<int> RemovedIndexes;
        unsigned int Add(int Key, ExprFormElement Value)
        {
            this->insert_or_assign(Key, Value);
            return Key;
        }
    protected:
        /// <summary>
        /// Adds the specified value into next free Index position(Returns index of new value)
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>unsigned int</returns>
        int Add(ExprFormElement Value)
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
    #ifndef ExpFormula_ReplaceAllFloat
        /// <summary>
        /// Replaces the non-number based form value (and add to number map).
        /// </summary>
        /// <param name="Key">The key.</param>
        /// <param name="Value">The value.</param>
        void ReplaceFormVal(int Key, float Value)
        {
            ExprFormElement& KeyedVal = this->at(Key);
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
            ExprFormElement& KeyedVal = this->at(Key);
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
            ExprFormElement& KeyedVal = this->at(Key);
            if (Value) { KeyedVal.ElementType = "true"; }
            else { KeyedVal.ElementType = "false"; }
        }

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
        /// <summary>
        /// Replaces the non-number based form value (and add to number map).
        /// </summary>
        /// <param name="Key">The key.</param>
        /// <param name="Value">The value.</param>
        void ReplaceFormVal(int Key, AltDec Value)
        {
            ExprFormElement& KeyedVal = this->at(Key);
            KeyedVal.ElementType = "#A";
            AltMap.insert_or_assign(Key, Value);
        }
    #endif

    #ifndef ExpFormula_ReplaceAllFloat
        void SwitchOpToVal(ExprFormElement& OpVal, int OpKey, EvalValueData::iterator& LeftIterator, EvalValueData::iterator& RightIterator, float Value)
        {
            FloatMap.insert_or_assign(OpKey, Value);
            OpVal.ElementType = "#f";

    #if defined ExpFormula_AltDecSupport
            if (LeftIterator->second.ElementType == "#A") { AltMap.erase(LeftIterator->first); }
    #else
            if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
            else if (LeftIterator->second.ElementType == "#i") { IntMap.erase(LeftIterator->first); }

    #if defined ExpFormula_AltDecSupport
            if (RightIterator->second.ElementType == "#A") { AltMap.erase(RightIterator->first); }
    #else
            if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
            else if (RightIterator->second.ElementType == "#i") { IntMap.erase(RightIterator->first); }

            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            this->erase(LeftIterator); this->erase(RightKey);
            RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
        }
    #endif

        void SwitchOpToVal(ExprFormElement& OpVal, EvalValueData::iterator& LeftIterator, EvalValueData::iterator& RightIterator, int OpKey, int Value)
        {
            IntMap.insert_or_assign(OpKey, Value);
            OpVal.ElementType = "#f";

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            if (LeftIterator->second.ElementType == "#A") { AltMap.erase(LeftIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
    #else
            if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
            else if (LeftIterator->second.ElementType == "#i") { IntMap.erase(LeftIterator->first); }

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            if (RightIterator->second.ElementType == "#A") { AltMap.erase(RightIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
    #else
            if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
            else if (RightIterator->second.ElementType == "#i") { IntMap.erase(RightIterator->first); }

            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            this->erase(LeftIterator); this->erase(RightKey);
            RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
        }

        void SwitchOpToVal(ExprFormElement& OpVal, EvalValueData::iterator& LeftIterator, EvalValueData::iterator& RightIterator, bool Value)
        {
            if (Value) { OpVal.ElementType = "true"; }
            else { OpVal.ElementType = "false"; }

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            if (LeftIterator->second.ElementType == "#A") { AltMap.erase(LeftIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
    #else
            if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
            else if (LeftIterator->second.ElementType == "#i") { IntMap.erase(LeftIterator->first); }

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            if (RightIterator->second.ElementType == "#A") { AltMap.erase(RightIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
    #else
            if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
            else if (RightIterator->second.ElementType == "#i") { IntMap.erase(RightIterator->first); }

            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            this->erase(LeftIterator); this->erase(RightKey);
            RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
        }

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
        void SwitchOpToVal(ExprFormElement& OpVal, int OpKey, EvalValueData::iterator& LeftIterator, EvalValueData::iterator& RightIterator, AltDec Value)
        {
            AltMap.insert_or_assign(OpKey, Value);
            OpVal.ElementType = "#A";
            if (LeftIterator->second.ElementType == "#A") { AltMap.erase(LeftIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (LeftIterator->second.ElementType == "#f") { FloatMap.erase(LeftIterator->first); }
    #endif
            else if (LeftIterator->second.ElementType == "#i") { IntMap.erase(LeftIterator->first); }

            if (RightIterator->second.ElementType == "#A") { AltMap.erase(RightIterator->first); }
    #ifndef ExpFormula_ReplaceAllFloat
            else if (RightIterator->second.ElementType == "#f") { FloatMap.erase(RightIterator->first); }
    #endif
            else if (RightIterator->second.ElementType == "#i") { IntMap.erase(RightIterator->first); }
            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            this->erase(LeftIterator); this->erase(RightKey);
            RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
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
            LastAdded = Add(ExprFormElement(Value));
        }

    #ifndef ExpFormula_ReplaceAllFloat
        /// <summary>
        /// Adds the float value to map
        /// </summary>
        /// <param name="Value">The value.</param>
        void AddF(float Value)
        {
            LastAdded = Add(ExprFormElement("#f"));
            FloatMap.insert_or_assign(LastAdded, Value);
        }

        /// <summary>
        /// Adds the float value to map
        /// </summary>
        /// <param name="Value">The value.</param>
        void AddF(std::string Value)
        {
            float fValue = VariableConversionFunctions::ReadFloatFromString(Value);
            AddF(fValue);
        }
    #endif

        void AddI(int Value)
        {
            LastAdded = Add(ExprFormElement("#i"));
            IntMap.insert_or_assign(LastAdded, Value);
        }

        void AddI(std::string Value)
        {
            int iValue = VariableConversionFunctions::ReadIntFromString(Value);
            AddI(iValue);
        }

        void AddB(bool Value)
        {
            LastAdded = Add(Value ? ExprFormElement() : ExprFormElement("false"));
        }

        void AddOp(std::string Value)
        {
            LastAdded = Add(ExprFormElement(Value));
            if(Value=="!")
            {
                OpOrderMap[1].push_back(LastAdded);
            }
            else if(Value=="")// Multiplication, division, and remainder
            {
                OpOrderMap[2].push_back(LastAdded);
            }
            else if (Value == "")// Addition and subtraction
            {
                OpOrderMap[3].push_back(LastAdded);
            }
            else if (Value == "")//<,<=, >, >=
            {
                OpOrderMap[4].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[5].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[6].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[7].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[8].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[9].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[10].push_back(LastAdded);
            }
            else if (Value == "")// 	Multiplication, division, and remainder
            {
                OpOrderMap[11].push_back(LastAdded);
            }
            //else if (Value == "")//Ternary conditional, =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |= (Not supported yet)
            //{
            //    OpOrderMap[12].push_back(LastAdded);
            //}
        }

        void AddPrefixOp(std::string Value)
        {
            LastAdded = Add(ExprFormElement("$" + Value, Value.front() == '+' ? 0 : 1));
            OpOrderMap[1].push_back(LastAdded);
        }

        /// <summary>
        /// Changes the last added element into postfix ++/-- OpValue
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="FormIndex">Index of the form.</param>
        void ChangeLastToPostfixOp(std::string Value, size_t FormIndex)
        {
            auto lastElement = this[FormIndex].at(LastAdded);
            std::string strBuffer = lastElement.ElementType;
            this[FormIndex].Remove(LastAdded);
            LastAdded = Add(ExprFormElement(strBuffer, Value));
        }

        void ResetOps()
        {
            OpOrderMap.clear();
            for (int index = 0; index < 12; ++index) { OpOrderMap.push_back(IntVector()); }
        }

        EvalResult GetValue(EvalValueData::iterator& targetIterator)
        {
            EvalResult targetResult;
            targetResult.SetVal(targetIterator->second.ElementType == "true" ? 1 : (targetIterator->second.ElementType == "false" ? 0 : (targetIterator->second.ElementType == "#i" ? IntMap[targetIterator->first] :
    #ifdef ExpFormula_ReplaceAllFloat
                AltMap[targetIterator->first])));
    #elif ExpFormula_AltDecSupport
                targetIterator->second.ElementType == "#A"?AltMap[targetIterator->first]: FloatMap[targetIterator->first])));
    #else
                FloatMap[targetIterator->first])));
    #endif
            return targetResult;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="EvalValueData"/> class.
        /// </summary>
        EvalValueData()
        {//Initialize vector for Order of operations
            for (int index = 0; index < 12; ++index) { OpOrderMap.push_back(IntVector()); }
        }
        /// <summary>
        /// Finalizes an instance of the <see cref="EvalValueData"/> class.
        /// </summary>
        ~EvalValueData() {}
    };

    /// <summary>
    /// Class ExprFormula. (FormulaElement)Operator(FormulaElement)
    /// FormulaElements stored as std::vector<std::string>
    /// Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
    /// with (Variable01 >= 1) FormulaElement values:
    /// Variable01, >=, #i0
    /// with (Variable01 >= 1) values referenced from:
    /// Variable01, >=, IntValues[0]
    /// with (Variable02>2.5) FormulaElement values:
    /// Variable02, >, #i0
    /// with (Variable02>2.5) values referenced from:
    /// Variable02, >, FloatValues[0]
    /// Initial FormulaElement Values : @1, &&, @2
    /// </summary>
    DLL_API class ExprFormula : public std::vector<EvalValueData>
    {
    private:
        using IntVector = std::vector<int>;
        /// <summary>
        /// Prevents a default instance of the <see cref="ExprFormula"/> class from being created.
        /// </summary>
        ExprFormula() {}
    protected://All Derivatives can use
        /// <summary>
        /// Returns the rest of string.
        /// </summary>
        /// <param name="targetStr">The target string.</param>
        /// <param name="index">The index.</param>
        /// <returns>std.string.</returns>
        std::string ReturnRestOfString(std::string& targetStr, size_t index)
        {
            std::string strBuffer = "";
            for (std::string::iterator CurrentVal = targetStr.begin() + index, LastVal = targetStr.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                strBuffer += *CurrentVal;
            }
            return strBuffer;
        }
    public:
        /// <summary>
        /// Trims the formula.
        /// </summary>
        void TrimFormula()
        {
            if (this->size() == 2 && at(0).size() == 1 && at(0).begin()->second.ElementType.front() == '@')//this[0][0].front() == "@")
            {
                this[0] = this[1]; this->pop_back();//Reduce formula in (@1) to just @1
            }
        }

        EvalResult EvaluateOrderOfOperations(EvalValueData& FormCopy)
        {
            EvalResult valResult;

    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
            AltDec AltValue;
    #endif
    #ifndef ExpFormula_ReplaceAllFloat
            float TempValue;
    #endif
            bool TempBool;
            int TempIntVal;

            IntVector& OpOrderElement = FormCopy.OpOrderMap[0];
            EvalValueData::iterator OpIterator;
            auto OpVal = FormCopy.at(0);
            EvalValueData::iterator LeftVal;
            EvalValueData::iterator RightVal;
            EvalResult leftResult;
            EvalResult rightResult;
    #if defined ExpFormula_ReplaceAllFloat
            AltDec AltLeft;
            AltDec AltRight;
    #endif

            //Applying operations via C++ variation of order of operations
            //https://en.cppreference.com/w/cpp/language/operator_precedence
            for (int opIndex = 1; opIndex < 12; ++opIndex)
            {
                OpOrderElement = FormCopy.OpOrderMap[opIndex];
                for (IntVector::iterator CurrentVal = OpOrderElement.begin(), LastVal = OpOrderElement.end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    OpIterator = FormCopy.find(*CurrentVal);
                    OpVal = FormCopy[*CurrentVal];
                    if (OpIterator->second.ElementType != "!") { LeftVal = OpIterator - 1; }
                    RightVal = OpIterator + 1;
                    switch (opIndex)
                    {
                    default://placeholder code
                        break;
                    case 0://(Case 0)++ PostFix, -- PostFix Not Supported
                            //
                        break;
                    case 1://(++ PreFix, -- PreFix Not Supported), ! (Unary plus and minus not supported yet)
                        if (OpIterator->second.ElementType == "!")
                        {//Only support switching bool values
                            if (RightVal->second.ElementType == "true")
                            {
                                FormCopy.at(RightVal->first).ElementType = "false";
                            }
                            else if (RightVal->second.ElementType == "false")
                            {
                                FormCopy.at(RightVal->first).ElementType = "true";
                            }
                            FormCopy.erase(OpIterator);
                        }
                        //else
                        //{
                        //}
                        break;
                    case 2:// 	Multiplication, division, and remainder
                        if (OpVal.ElementType == "*")
                        {

                            if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                            {
                                TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                    * (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                            }
                            else
                            {
                                TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                    & (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                            }
                        }
                        else if (OpVal.ElementType == "/")
                        {
                            TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                * (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                        }
                        else if (OpVal.ElementType == "%")
                        {
                            if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                            {
                                TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                    * (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                            }
                            else
                            {
                                TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                    & (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                            }
                        }
                        break;
                    case 3://Addition and subtraction
                        if (OpVal.ElementType == "+")
                        {
    #if defined ExpFormula_ReplaceAllFloat
                            if (LeftVal->second.ElementType == "#A" || RightVal->second.ElementType == "#A")
                            {
                                AltValue = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.AltMap[LeftVal->first])))
                                    + (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.AltMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, AltValue);
                            }
    #else
                            if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                            {
                                TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                    + (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                            }
    #endif
                            else
                            {
                                TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                    & (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                            }
                        }
                        else if (OpVal.ElementType == "-")
                        {
    #if defined ExpFormula_ReplaceAllFloat
                            if (LeftVal->second.ElementType == "#A" || RightVal->second.ElementType == "#A")
                            {
                                AltValue = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.AltMap[LeftVal->first])))
                                    - (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.AltMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, AltValue);
                            }
    #else
                            if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                            {
                                TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                    - (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                            }
    #endif
                            else
                            {
                                TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                    - (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                            }
                        }
                        break;
                        //case 3.3://(<<   >>  Bitwise left shift and right shift not supported yet)
                        //	break;
                        //case 3.6: <=> 	Three-way comparison operator not supported yet
                        //	break;
                    case 4://<,<=, >, >=
    #if defined ExpFormula_ReplaceAllFloat
                        AltLeft = LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.AltMap[LeftVal->first]));
                        AltRight = RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.AltMap[RightVal->first]));
                        if (OpVal.ElementType == "<") { TempBool = AltLeft < AltRight; }
                        else if (OpVal.ElementType == "<=") { TempBool = AltLeft <= AltRight; }
                        else if (OpVal.ElementType == ">") { TempBool = AltLeft > AltRight; }
                        else if (OpVal.ElementType == ">=") { TempBool = AltLeft >= AltRight; }
                        FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
    #else
                        leftResult = FormCopy.GetValue(LeftVal);
                        rightResult = FormCopy.GetValue(RightVal);
                        if (OpVal.ElementType == "<") { TempBool = leftResult < rightResult; }
                        else if (OpVal.ElementType == "<=") { TempBool = leftResult <= rightResult; }
                        else if (OpVal.ElementType == ">") { TempBool = leftResult > rightResult; }
                        else if (OpVal.ElementType == ">=") { TempBool = leftResult >= rightResult; }
                        FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
    #endif
                        break;
                    case 5://==, !=
                        leftResult = FormCopy.GetValue(LeftVal);
                        rightResult = FormCopy.GetValue(RightVal);
                        if (OpVal.ElementType == "==") { TempBool = (leftResult == rightResult); }
                        else if (OpVal.ElementType == "!=") { TempBool = (leftResult != rightResult); }
                        FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
                        break;
                    case 7://&
                        if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                        {//Forcing as int since can't use this bitwise operation as float
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : (int)FormCopy.FloatMap[LeftVal->first])))
                                & (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : (int)FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        else
                        {
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                & (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        break;
                    case 8://^ (Bitwise XOR (exclusive or) )
                        if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                        {//Forcing as int since can't use this bitwise operation as float
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : (int)FormCopy.FloatMap[LeftVal->first])))
                                ^ (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : (int)FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        else
                        {
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                ^ (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                        }
                        break;
                    case 9:// | Bitwise OR (inclusive or)
                        if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                        {//Forcing as int since can't use this bitwise operation as float
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : (int)FormCopy.FloatMap[LeftVal->first])))
                                | (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : (int)FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        else
                        {
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                | (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        break;
                    case 10://&&
                        if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                        {
                            TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                && (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                        }
                        else
                        {
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                && (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        break;
                    case 11:// || (Logical OR)
                        if (LeftVal->second.ElementType == "#f" || RightVal->second.ElementType == "#f")
                        {
                            TempValue = (LeftVal->second.ElementType == "true" ? 1.0f : (LeftVal->second.ElementType == "false" ? 0.0f : (LeftVal->second.ElementType == "#i" ? FormCopy.IntMap[LeftVal->first] : FormCopy.FloatMap[LeftVal->first])))
                                || (RightVal->second.ElementType == "true" ? 1.0f : (RightVal->second.ElementType == "false" ? 0.0f : (RightVal->second.ElementType == "#i" ? FormCopy.IntMap[RightVal->first] : FormCopy.FloatMap[RightVal->first])));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempValue);
                        }
                        else
                        {
                            TempIntVal = (LeftVal->second.ElementType == "true" ? 1 : (LeftVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[LeftVal->first]))
                                || (RightVal->second.ElementType == "true" ? 1 : (RightVal->second.ElementType == "false" ? 0 : FormCopy.IntMap[RightVal->first]));
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempIntVal);
                        }
                        break;
                        //case 12://Ternary conditional, =, +=,   -=, *=,   /=,   %=,<<=,   >>=, &= ,  ^=,   |= (Not supported yet)
                        //	break;
                    }
                }
            }
            if (FormCopy.size() == 1)
            {
                EvalValueData::iterator ElementIter = FormCopy.begin();
                int KeyIndex = ElementIter->first;
                if (ElementIter->second.ElementType == "true")
                {
                    valResult.SetVal(true);
                }
                else if (ElementIter->second.ElementType == "false")
                {
                    valResult.SetVal(false);
                }
                else if (ElementIter->second.ElementType == "#i")
                {
                    valResult.SetVal(FormCopy.IntMap[KeyIndex]);
                }
                else if (ElementIter->second.ElementType == "#f")
                {
                    valResult.SetVal(FormCopy.IntMap[KeyIndex]);
                }
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                else if (ElementIter->second.ElementType == "#A")
                {
                    valResult.SetVal(FormCopy.IntMap[KeyIndex]);
                }
    #endif
                else
                {
                    throw "Failed to evaluate:" + ElementIter->second.ElementType;
                }
                return valResult;
            }
            else
            {
                throw "Failed to evaluate to single value!";
            }
        }

        void SwapUpdatedFormData(EvalValueData& FormCopy, std::map<std::string, float>& ElementValues, size_t FormIndex=0)
        {
            std::string CurString;
            char firstChar;
            EvalResult targetResult;
            for (EvalValueData::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
            {
                CurString = CurrentVal->second.ElementType;
                firstChar = CurString.front();
                if (firstChar == '@')//FormulaDetected
                {
                    targetResult = RecursivelyEvalValues(ElementValues, CurrentVal->second.Index);
                    switch (targetResult.ResultType)
                    {
                    case 0://Bool
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult.BResult);
                        break;
                    case 1://Int
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult.IntResult);
                        break;
    #ifndef ExpFormula_ReplaceAllFloat
                    case 2://Float
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult.FResult);
                        break;
    #endif
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                    case 3://AltDec/AltDec
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult.AltResult);
                        break;
    #endif
                    }
                }
                else if (firstChar != '#' && firstChar != '$' && firstChar != '+' && firstChar != '-' && firstChar != '*' && firstChar != '/' && firstChar != '%' &&
                    firstChar != '&' && firstChar != '|' && firstChar != '!' && firstChar != '<' && firstChar != '>' && firstChar != '^' && firstChar != '=' && CurString.front() != '?')
                {//Swap Variable with values
                    FormCopy.ReplaceFormVal(CurrentVal->first, ElementValues.at(CurString));
                }
            }
        }

        EvalResult RecursivelyEvalValues(std::map<std::string, float>& ElementValues, size_t FormIndex)
        {//Each Formula Calculates order of operations etc separately
            EvalValueData FormCopy = at(FormIndex);
            SwapUpdatedFormData(FormCopy, ElementValues, FormIndex);
            return EvaluateOrderOfOperations(FormCopy);
        }

        EvalResult EvalValues(std::map<std::string, float> ElementValues)
        {
            EvalValueData FormCopy = this->at(0);//Duplicate values so can erase parts when calculating
            SwapUpdatedFormData(FormCopy, ElementValues);
            return EvaluateOrderOfOperations(FormCopy);
        }

        /// <summary>
        /// Recursively adds to the string.
        /// </summary>
        /// <param name="strBuffer">The string buffer.</param>
        /// <param name="FormIndex">Index of the form.</param>
        void RecursivelyAddToString(std::string& strBuffer, size_t FormIndex)
        {
            std::string CurString;
            for (EvalValueData::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
            {
                CurString = CurrentVal->second.ElementType;
                if (CurString.front() == '@')//FormulaDetected
                {
                    strBuffer += "(";
                    RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                    strBuffer += ")";
                }
                else if (CurString.front() == '#')//NumberDetected
                {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                    if (CurString[1] == 'A')
                    {
                        strBuffer += at(0).AltMap.at(CurrentVal->first);
                    }
                    else if (CurString[1] == 'f')
    #else
                    if (CurString[1] == 'f')
    #endif
                    {
                        strBuffer += at(FormIndex).FloatMap.at(CurrentVal->first);
                    }
                    else if (CurString[1] == 'i')
                    {
                        strBuffer += at(FormIndex).IntMap.at(CurrentVal->first);
                    }
                }
                //else if (CurString.front() == '?')
                //{
                //}
                else
                {
                    strBuffer += CurString;
                }
            }
        }

    #if defined ExpFormula_ImportIniDataV2

    #endif
    #if defined ExpFormula_ImportIndexedIniData

    #endif

        /// <summary>
        /// Converts to string(with no extra spacing applied).
        /// </summary>
        /// <returns>std.string.</returns>
        std::string ToString()
        {
            std::string strBuffer = "";
            std::string CurString;
            for (EvalValueData::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
            {
                CurString = CurrentVal->second.ElementType;
                if (CurString.front() == '@')//FormulaDetected
                {
                    strBuffer += "(";
                    RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                    strBuffer += ")";
                }
                else if (CurString.front() == '#')//NumberDetected
                {
    #if defined ExpFormula_AltDecSupport || defined ExpFormula_ReplaceAllFloat
                    if (CurString[1] == 'A')
                    {
                        strBuffer += at(0).AltMap.at(CurrentVal->first);
                    }
                    else if (CurString[1] == 'f')
    #else
                    if (CurString[1] == 'f')
    #endif
                    {
                        strBuffer += at(0).FloatMap.at(CurrentVal->first);
                    }
                    else if (CurString[1] == 'i')
                    {
                        strBuffer += at(0).IntMap.at(CurrentVal->first);
                    }
                }
                //else if (CurString.front() == '?')
                //{
                //}
                else
                {
                    strBuffer += CurString;
                }
            }
            return strBuffer;
        }

        /// <summary>
        /// Inserts from buffer.
        /// </summary>
        /// <param name="strBuffer">The string buffer.</param>
        /// <param name="FormulaIndex">Index of the formula.</param>
        /// <param name="ScanType">Type of the scan.</param>
        void InsertFromBuffer(std::string& strBuffer, size_t& FormulaIndex, short& ScanType)
        {
            //https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
            std::string ConvertedStr = strBuffer;
            std::for_each(ConvertedStr.begin(), ConvertedStr.end(), [](char& c) {c = ::tolower(c); });
            if (ConvertedStr == "true")
            {
                this->at(FormulaIndex).AddB("true");
            }
            else if (ConvertedStr == "false")
            {
                this->at(FormulaIndex).AddB("false");
            }
            else if (ScanType == 3)
            {
                this->at(FormulaIndex).Add(strBuffer);
            }
            else if (ScanType == 5)
            {
                this->at(FormulaIndex).AddF(strBuffer);
            }
            else if (ScanType == 6 || ScanType == 4)
            {
                this->at(FormulaIndex).AddI(strBuffer);
            }
            else if (ScanType == 1)
            {
                this->at(FormulaIndex).AddOp(strBuffer);
            }
            else if (ScanType == 11)//Prefix ++ or --
            {
                this->at(FormulaIndex).AddPrefixOp(strBuffer);
            }
            else if (ScanType == 10)//Postfix Op ++ or --
            {
                this->at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
            }
            //else if(ScanType==12)
            //{
            //	this->at(FormulaIndex).AddTernaryOperatorOp(strBuffer);
            //}
            else//CATCH-ALL
            {
                this->at(FormulaIndex).Add(strBuffer);
            }
        }

        /// <summary>
        /// Resets to single blank formula
        /// </summary>
        void ResetToBlank()
        {
            this->clear();
            this->push_back(EvalValueData());//Initialize first (Formula) field
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ExprFormula" /> class.
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        ExprFormula(std::string ElemValue)
        {
            //0 = ???
            //1 = Operator
            //3 = Variable Value
            //4 = Number
            //5 = Float Number
            //6 = Int Number
            //7 = Bool Number
            short ScanType = 0;
            std::string strBuffer = "";
            size_t FormulaIndex = 0;
            //size_t CurrentFormElement = 0;
            this->push_back(EvalValueData());//Initialize first (Formula) field
            //auto targetForm = at(0);
            for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (*CurrentVal == '(')
                {
                    //if(ScanType==10){strBuffer = at(FormulaIndex).back()+strBuffer;at(FormulaIndex).back()=strBuffer;}
                    if (!strBuffer.empty()) { InsertFromBuffer(strBuffer, FormulaIndex, ScanType); }
                    FormulaIndex = this->size();
                    this->push_back(EvalValueData());
                }
                else if (*CurrentVal == ')')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                    strBuffer = ""; ScanType = 0;
                    --FormulaIndex;
                }
                else if (ScanType == 0 || ScanType == 10)//Almost only at either start of a formula or after operator
                {
                    if (ScanType == 10)//Prefix/postfix detection for ++/--
                    {
                        if (*CurrentVal == ' ' || *CurrentVal == '*' || *CurrentVal == '/' || *CurrentVal == '&' || *CurrentVal == '|' || *CurrentVal == '<' || *CurrentVal == '>' || *CurrentVal == '=' || *CurrentVal == '!' || *CurrentVal == '+' || *CurrentVal == '-')//Postfix
                        {
                            this->at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
                            ScanType = 0;
                        }
                        else//Likely prefix
                        {
                            strBuffer += *CurrentVal;
                            ScanType = 11;
                            continue;
                        }
                    }
                    //operators = ['==', '!=', '>=', '<=', '&&', '||', '&', '|', '-', '+', '>', '<', '/', '*', '!','++','--']
                    if (*CurrentVal == '+')
                    {
                        strBuffer = '+'; ScanType = 1;
                    }
                    else if (*CurrentVal == '-')
                    {
                        strBuffer = '-'; ScanType = 1;//Either Number or operator
                    }
                    else if (*CurrentVal == '!')//Negative Operator only valid for in front of NonOperators
                    {
                        this->at(FormulaIndex).AddOp("!");
                    }
                    else if (*CurrentVal == '^')
                    {
                        this->at(FormulaIndex).AddOp("^");
                    }
                    //else if(*CurrentVal == '?')//TernaryOperator detection start
                    //{
                    //	strBuffer = this->at(FormulaIndex).ExtractLastElem();
                    //	ScanType = 12;
                    //}
                    else
                    {
                        if (VariableConversionFunctions::IsDigit(*CurrentVal))
                        {
                            ScanType = 4;
                            strBuffer = *CurrentVal;
                        }
                        else if (*CurrentVal != ' ' && *CurrentVal != '\t')//Not Whitespace
                        {
                            ScanType = 3;
                            strBuffer = *CurrentVal;
                        }
                    }
                }
                else if (ScanType == 1)
                {
                    if (strBuffer == "-")
                    {
                        if (VariableConversionFunctions::IsDigit(*CurrentVal))
                        {
                            ScanType == 4; strBuffer += *CurrentVal;
                        }
                        else if (*CurrentVal == '-')//-- Operator
                        {
                            strBuffer = "--"; ScanType = 11;//this->at(FormulaIndex).push_back("--"); strBuffer.clear(); ScanType = 11;
                        }
                        else//- Operator
                        {
                            this->at(FormulaIndex).AddOp("-");
                            if (*CurrentVal == '!')//Inverse operator detected after
                            {
                                this->at(FormulaIndex).AddOp("!"); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                strBuffer = *CurrentVal;
                            }
                        }
                    }
                    else if (strBuffer == "!")
                    {
                        if (*CurrentVal == '=')//!= Operator
                        {
                            this->at(FormulaIndex).AddOp("!="); strBuffer.clear(); ScanType = 0;
                        }
                        else//- Operator
                        {
                            //Invalid operator between variables?
                            throw "Invalid operator between variables!";
                        }
                    }
                    else if (strBuffer == "+")
                    {
                        strBuffer += *CurrentVal;
                        //To-Do Create detection of Prefix/postfix detection
                        if (*CurrentVal == '+')//++ Operator
                        {
                            strBuffer = "++"; ScanType = 11;//this->at(FormulaIndex).push_back("++"); strBuffer.clear(); ScanType = 0;
                        }
                        else//+ Operator
                        {
                            this->at(FormulaIndex).AddOp("+");
                            if (*CurrentVal == '!')//Inverse operator detected after
                            {
                                this->at(FormulaIndex).AddOp("!"); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                strBuffer = *CurrentVal;
                                if (*CurrentVal == '-' || VariableConversionFunctions::IsDigit(*CurrentVal))
                                {
                                    ScanType = 4;
                                }
                                else
                                {
                                    ScanType = 3;
                                }
                            }
                        }
                    }
                    else if (strBuffer == "&")
                    {
                        strBuffer += *CurrentVal;
                        if (*CurrentVal == '&')
                        {
                            this->at(FormulaIndex).AddOp("&&"); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            this->at(FormulaIndex).AddOp("&");
                            if (*CurrentVal == '!')
                            {
                                this->at(FormulaIndex).AddOp("!"); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                strBuffer = *CurrentVal;
                                if (*CurrentVal == '-' || VariableConversionFunctions::IsDigit(*CurrentVal))
                                {
                                    ScanType = 4;
                                }
                                else
                                {
                                    ScanType = 3;
                                }
                            }
                        }
                    }
                    else if (strBuffer == "|")
                    {
                        strBuffer += *CurrentVal;
                        if (*CurrentVal == '|')
                        {
                            this->at(FormulaIndex).AddOp("||"); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            this->at(FormulaIndex).AddOp("|");
                            if (*CurrentVal == '!')
                            {
                                this->at(FormulaIndex).AddOp("!"); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                strBuffer = *CurrentVal;
                                if (*CurrentVal == '-' || VariableConversionFunctions::IsDigit(*CurrentVal))
                                {
                                    ScanType = 4;
                                }
                                else
                                {
                                    ScanType = 3;
                                }
                            }
                        }
                    }
                    else//Catch-all for most operators
                    {
                        //strBuffer += *CurrentVal;
                        if (*CurrentVal == '=')
                        {
                            this->at(FormulaIndex).AddOp(strBuffer + *CurrentVal); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            this->at(FormulaIndex).AddOp(strBuffer);
                            if (*CurrentVal == '!')
                            {
                                this->at(FormulaIndex).AddOp("!"); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                strBuffer = *CurrentVal;
                                if (*CurrentVal == '-' || VariableConversionFunctions::IsDigit(*CurrentVal))
                                {
                                    ScanType = 4;
                                }
                                else
                                {
                                    ScanType = 3;
                                }
                            }
                        }
                    }
                }
                else if (ScanType == 11)//Prefix Variable (Partial support for prefix increment variables)
                {
                    if (*CurrentVal != ' ' && *CurrentVal != '\t')//Whitespace
                    {
                        this->at(FormulaIndex).AddPrefixOp(strBuffer);
                    }
                    else
                    {
                        strBuffer += *CurrentVal;
                    }
                }
                else
                {//Scan type either number or variable at this point
                    if (*CurrentVal == '+')//++ or +
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '+'; ScanType = 1;
                    }
                    else if (*CurrentVal == '-')//-- or -
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '-'; ScanType = 1;
                    }
                    else if (*CurrentVal == '!')//!=
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '!'; ScanType = 1;
                    }
                    else if (*CurrentVal == '&')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '&'; ScanType = 1;
                    }
                    else if (*CurrentVal == '|')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '|'; ScanType = 1;
                    }
                    else if (*CurrentVal == '=')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '='; ScanType = 1;
                    }
                    else if (*CurrentVal == '>')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '>'; ScanType = 1;
                    }
                    else if (*CurrentVal == '<')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        strBuffer = '<'; ScanType = 1;
                    }
                    else if (*CurrentVal == '/')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        this->at(FormulaIndex).AddOp("/");
                    }
                    else if (*CurrentVal == '*')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        this->at(FormulaIndex).AddOp("*");
                    }
                    else if (*CurrentVal == '^')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        this->at(FormulaIndex).AddOp("^");
                    }
                    else
                    {
                        strBuffer += *CurrentVal;
                    }
                }
            }
            TrimFormula();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ExprFormula" /> class.(fix for initializing without copying from a string value set)
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        ExprFormula(const char* strVal) : ExprFormula(std::string(strVal)) {}
    };
}