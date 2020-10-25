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
#include "..\AltNum\MediumDec.hpp"
#include "..\OtherFunctions\VariableConversionFunctions.h"

//Preprocessor Switches
/*
*/
//Supported Operators/Functions
/*
^ = Power of; * = Multiplication; / = Division; % = Modulus
+ = Addition; - = Subtraction; ! = Not;
&& = And; || = Or;
$ = XOR (bitwise XOR operation)(Not fully supported by MediumDec yet)
++Prefix; --Prefix;
(Bitwise operators--Not fully supported by MediumDec yet)&, |
SqrtOf = Square Root of (applied to right value) (Not scanned yet but application code inside)
thRootOf = Nth Root of (left value is equal to N; applied to right value) (Not scanned yet but application code inside)

*/
//Unsupported Operators/Functions(for later)
/*
 ++Postfix; --Postfix (Need to update to code changes)
PowerOf = (for scanning PowerOf instead of ^)
? = TernaryOperator(Not stored/evaluated yet)
Assignment operators not supported
*/

namespace BlazesRusCode
{
    class MediumDecFormulaData::FormData;
    class MediumDecFormulaData::FormElement;
    class MediumDecFormulaData::MediumDecFormula;

    /// <summary>
    /// Class MediumDecFormula. (FormulaElement)Operator(FormulaElement)
    /// FormulaElements stored as std::vector<std::string>
    /// Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
    /// with (Variable01 >= 1) FormulaElement values:
    /// Variable01, >=, #i0
    /// with (Variable01 >= 1) values referenced from:
    /// Variable01, >=, IntValues[0]
    /// with (Variable02>2.5) FormulaElement values:
    /// Variable02, >, #i0
    /// with (Variable02>2.5) values referenced from:
    /// Variable02, >, MediumDecValues[0]
    /// Initial FormulaElement Values : @1, &&, @2
    /// </summary>
    DLL_API class MediumDecFormulaData
    {
    protected:
        using IntVector = std::vector<int>;
        //All Derivatives can use
        /// <summary>
        /// Returns the rest of string.
        /// </summary>
        /// <param name="targetStr">The target string.</param>
        /// <param name="index">The index.</param>
        /// <returns>std.string.</returns>
        static std::string ReturnRestOfString(std::string& targetStr, size_t index)
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
        /// Element Category Type
        /// </summary>
        enum class DLL_API ElementType : unsigned __int8
        {
            //Stored number
            Num = 0,
            //Variable Reference
            Variable,
            //Another Formula within
            Formula,
            // True or False Boolean
            trueVal, falseVal,
            //Power of Operation
            Pow,
            //Square Root of
            Sqrt,
            //Nth root of
            NthRoot,
            //PostFix++
            PostFixPlus,
            //PostFix--
            PostFixMinus,
            //++Prefix
            PrefixPlus,
            //--Prefix
            PrefixMinus,
            //(Group 3 precedence, right to left associativity)
            Not, Negative,
            // Multiplication, division, and remainder (Group 5 precedence)
            Mult, Div, Rem,
            // Addition and subtraction (Group 6 precedence)
            Add, Sub,
            //<,<=, >, >= (Group 8 precedence)
            LessThan, LessOrEqual, GreaterThan, GreaterOrEqual,
            // 	==, != (Group 9 precedence)
            Equal, NotEqual,
            // 	Bitwise AND
            BitwiseAND,
            // Bitwise ^ (exclusive Or)
            XOR,
            // 	Bitwise inclusive Or "|"
            BitwiseOr,
            //&&
            AND,
            // Or ||
            OR
        };

        class DLL_API VariableStoreData
        {
        private:
            //VariableStoreData()
            //{
            //	varPointerData = nullptr;
            //	Name = "";
            //}

            //int VariableStoreIndex;
        public:
            /// <summary>
            /// Stored Variable Name
            /// </summary>
            std::string Name;

            /// <summary>
            /// The variable pointer data
            /// </summary>
            MediumDec* varPointerData;

            /// <summary>
            /// Initializes a new instance of the <see cref="VariableStoreData"/> class.
            /// </summary>
            /// <param name="name">The name.</param>
            VariableStoreData(std::string name)
            {
                varPointerData = nullptr;
                Name = name;
            }
        };

        class DLL_API FormElement
        {
        protected:

        public:
            //0 = Num; 1 = Variable; 2 = Formula; 3 = true; 4 = false ; 5 >= Op;
            ElementType ElementCat;

            /// <summary>
            /// (Primarily used for FormElements, ++,--, and TernaryOperator)
            /// The index/Key position of stored element (not used for booleans)
            //   For variable names: If not -1, refers to stored related Value Key(which is used for prefix/postfix ops as well)
            //   For Increment/Decrement Op: Refers to index of related value
            /// </summary>
            int Index;

            /// <summary>
            /// Initializes a new instance of the <see cref="MediumDecFormElement"/> class. (Defaults as boolean with true value)
            /// </summary>
            FormElement()
            {
                ElementCat = ElementType::trueVal;
                Index = -1;
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="MediumDecFormElement"/> class.
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="index">The index.</param>
            FormElement(ElementType Value, int index = 0)
            {
                ElementCat = Value;
                Index = index;
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="MediumDecFormElement"/> class for PostFix OpValue.
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="opBuffer">The operator value.</param>
            FormElement(std::string Value, std::string opBuffer, std::unordered_map<std::string, int>& VariableStorageMap)
            {
                if (opBuffer == "++") { ElementCat = ElementType::PostFixPlus; }
                else { ElementCat = ElementType::PostFixMinus; }
                //Create new variable storage and set index to it if variable storage matching key doesn't exist
                //int Index = VariableStorageMap.find(Value);
                //if ()
                //{
                //}
                Index = -1;
            }
        };

        /// <summary>
        /// MediumDec Formula Data (Variant of OrderedIndexDictionary)
        /// Implements the <see cref="tsl::ordered_map{int, MediumDecFormElement}" />
        /// </summary>
        /// <seealso cref="tsl::ordered_map{int, MediumDecFormElement}" />
        class DLL_API FormData : public tsl::ordered_map<int, FormElement>
        {
        private:
            using IntVector = std::vector<int>;
            using ElementType = ElementType;
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

            std::unordered_map<int, MediumDec> NumMap;

            std::unordered_map<int, VariableStoreData> VariableMap;
            /// <summary>
            /// The variable storage map with Variable Name linked to related Index(shortcut)
            /// </summary>
            std::unordered_map<std::string, int> VariableStorageMap;
        private:
            /// <summary>
            /// The next index
            /// </summary>
            int NextIndex = 0;
            std::vector<int> RemovedIndexes;
            unsigned int Add(int Key, FormElement Value)
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
            int Add(FormElement Value)
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
            /// <summary>
            /// Replaces the non-number based form value.
            /// </summary>
            /// <param name="Key">The key.</param>
            /// <param name="Value">The value.</param>
            void ReplaceFormVal(int Key, bool Value)
            {
                FormElement& KeyedVal = this->at(Key);
                if (Value) { KeyedVal.ElementCat = ElementType::trueVal; }
                else { KeyedVal.ElementCat = ElementType::falseVal; }
            }

            /// <summary>
            /// Replaces the non-number based form value (and add to number map).
            /// </summary>
            /// <param name="Key">The key.</param>
            /// <param name="Value">The value.</param>
            void ReplaceFormVal(int Key, MediumDec Value)
            {
                FormElement& KeyedVal = this->at(Key);
                KeyedVal.ElementCat = ElementType::Num;
                NumMap.insert_or_assign(Key, Value);
            }

            void SwitchOpToVal(FormElement& OpVal, FormData::iterator& LeftIterator, FormData::iterator& RightIterator, bool Value)
            {
                if (Value) { OpVal.ElementCat = ElementType::trueVal; }
                else { OpVal.ElementCat = ElementType::falseVal; }

                if (LeftIterator->second.ElementCat == ElementType::Num) { NumMap.erase(LeftIterator->first); }
                if (RightIterator->second.ElementCat == ElementType::Num) { NumMap.erase(RightIterator->first); }

                int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
                this->erase(LeftIterator); this->erase(RightKey);
                RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
            }

            /// <summary>
            /// Switches the op into boolean value.
            /// </summary>
            /// <param name="OpVal">The op value.</param>
            /// <param name="RightIterator">The right iterator.</param>
            /// <param name="Value">The value.</param>
            void SwitchOpToVal(FormElement& OpVal, FormData::iterator& RightIterator, bool Value)
            {
                if (Value) { OpVal.ElementCat = ElementType::trueVal; }
                else { OpVal.ElementCat = ElementType::falseVal; }

                if (RightIterator->second.ElementCat == ElementType::Num) { NumMap.erase(RightIterator->first); }

                this->erase(RightIterator);
                RemovedIndexes.push_back(RightIterator->first);
            }

            void SwitchOpToVal(FormElement& OpVal, int OpKey, FormData::iterator& RightIterator, MediumDec Value)
            {
                NumMap.insert_or_assign(OpKey, Value);
                OpVal.ElementCat = ElementType::Num;

                if (RightIterator->second.ElementCat == ElementType::Num) { NumMap.erase(RightIterator->first); }

                int RightKey = RightIterator->first;
                this->erase(RightKey);
                RemovedIndexes.push_back(RightKey);
            }

            void SwitchOpToVal(FormElement& OpVal, int OpKey, FormData::iterator& LeftIterator, FormData::iterator& RightIterator, MediumDec Value)
            {
                NumMap.insert_or_assign(OpKey, Value);
                OpVal.ElementCat = ElementType::Num;

                if (LeftIterator->second.ElementCat == ElementType::Num) { NumMap.erase(LeftIterator->first); }
                if (RightIterator->second.ElementCat == ElementType::Num) { NumMap.erase(RightIterator->first); }

                int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
                this->erase(LeftIterator); this->erase(RightKey);
                RemovedIndexes.push_back(LeftKey); RemovedIndexes.push_back(RightKey);
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
            /// Adds the specified value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void AddNum(std::string Value)
            {
                LastAdded = Add(FormElement(ElementType::Num));
                NumMap.insert_or_assign(LastAdded, Value);
            }

            /// <summary>
            /// Adds the specified value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void AddVariable(std::string Value)
            {
                //
                //Only add new variable index to map
                std::unordered_map<std::string, int>::const_iterator foundValue = VariableStorageMap.find(Value);
                if (foundValue == VariableStorageMap.end())
                {
                    LastAdded = Add(FormElement(ElementType::Variable));
                    this->at(LastAdded).Index = LastAdded;
                    VariableMap.insert_or_assign(LastAdded, Value);
                    VariableStorageMap.insert_or_assign(Value, LastAdded);
                }
                else
                {
                    LastAdded = Add(FormElement(ElementType::Variable, foundValue->second));
                }
            }

            /// <summary>
    /// Adds the specified value.
    /// </summary>
    /// <param name="Value">The value.</param>
            void AddBool(bool Value)
            {
                if (Value)
                    LastAdded = Add(FormElement(ElementType::trueVal));
                else
                    LastAdded = Add(FormElement(ElementType::falseVal));
            }

            ///// <summary>
            ///// Adds the specified value.
            ///// </summary>
            ///// <param name="Value">The value.</param>
            //void Add(std::string Value)
            //{
            //    LastAdded = Add(FormElement(Value));
            //}

            /// <summary>
            /// Adds the specified operator value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void AddOp(ElementType value)
            {
                LastAdded = Add(FormElement(value));
                switch (value)
                {
                    //"++PostFix"||Value=="--PostFix")//(Group 2 precedence, left to right associativity)
                case ElementType::Pow:
                    OpOrderMap[0].push_back(LastAdded);
                    break;
                    //++Prefix, --Prefix as well(Group 3 precedence, right to left associativity)
                case ElementType::Not:
                    OpOrderMap[1].push_back(LastAdded);
                    break;
                default:
                    break;
                }
                //LastAdded = Add(FormElement(Value));
                //if(Value=="^"){  }
                //else if(Value=="!")
                //{
                //	OpOrderMap[1].push_back(LastAdded);
                //}
                //else if(Value=="*"||Value=="/"||Value=="%")// Multiplication, division, and remainder (Group 5 precedence)
                //{
                //	OpOrderMap[2].push_back(LastAdded);
                //}
                //else if (Value == "+"||Value=="-")// Addition and subtraction (Group 6 precedence)
                //{
                //	OpOrderMap[3].push_back(LastAdded);
                //}
                //else if (Value == "<"||Value== "<="||Value == ">"||Value== ">=")//<,<=, >, >= (Group 8 precedence)
                //{
                //	OpOrderMap[4].push_back(LastAdded);
                //}
                //else if (Value == "=="||Value=="!=")// 	==, != (Group 9 precedence)
                //{
                //	OpOrderMap[5].push_back(LastAdded);
                //}
                //else if (Value == "&")// 	Bitwise AND
                //{
                //	OpOrderMap[6].push_back(LastAdded);
                //}
                //else if (Value == "XOR")// 	Bitwise ^ (exclusive Or)
                //{
                //	OpOrderMap[7].push_back(LastAdded);
                //}
                //else if (Value == "|")// 	Bitwise inclusive Or
                //{
                //	OpOrderMap[8].push_back(LastAdded);
                //}
                //else if (Value == "&&")
                //{
                //	OpOrderMap[9].push_back(LastAdded);
                //}
                //else if (Value == "||")
                //{
                //	OpOrderMap[10].push_back(LastAdded);
                //}
                ////else if (Value == "?")//Ternary conditional, =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |= (Not supported yet)
                ////{
                ////    OpOrderMap[11].push_back(LastAdded);
                ////}
            }

            void AddPrefixOp(std::string Value)
            {
                std::string varName = ReturnRestOfString(Value, 2);
                if (Value.front() == '+')
                {
                }
                else
                {
                }
                //LastAdded = Add(FormElement(Value, Value.front() == '+' ? 0 : 1));
                OpOrderMap[1].push_back(LastAdded);
            }

            ///// <summary>
            ///// Changes the last added element into postfix ++/-- OpValue
            ///// </summary>
            ///// <param name="Value">The value.</param>
            ///// <param name="FormIndex">Index of the form.</param>
            //void ChangeLastToPostfixOp(std::string Value, size_t FormIndex)
            //{
            //    auto lastElement = this[FormIndex].at(LastAdded);
            //    //std::string strBuffer = lastElement.ElementType;
            //    lastElement.ElementCat =
            //    this[FormIndex].Remove(LastAdded);
            //    //LastAdded = Add(FormElement(strBuffer, Value));
            //}

            void ResetOps()
            {
                OpOrderMap.clear();
                for (int index = 0; index < 11; ++index) { OpOrderMap.push_back(IntVector()); }
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="FormData"/> class.
            /// </summary>
            FormData()
            {//Initialize vector for Order of operations
                for (int index = 0; index < 11; ++index) { OpOrderMap.push_back(IntVector()); }
            }
            /// <summary>
            /// Finalizes an instance of the <see cref="FormData"/> class.
            /// </summary>
            ~FormData() {}
        };

        /// <summary>
        /// Class MediumDecFormula. (FormulaElement)Operator(FormulaElement)
        /// FormulaElements stored as std::vector<std::string>
        /// Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
        /// with (Variable01 >= 1) FormulaElement values:
        /// Variable01, >=, #i0
        /// with (Variable01 >= 1) values referenced from:
        /// Variable01, >=, IntValues[0]
        /// with (Variable02>2.5) FormulaElement values:
        /// Variable02, >, #i0
        /// with (Variable02>2.5) values referenced from:
        /// Variable02, >, MediumDecValues[0]
        /// Initial FormulaElement Values : @1, &&, @2
        /// </summary>
        class DLL_API MediumDecFormula : public std::vector<MediumDecFormulaData::FormData>
        {
        public:
            MediumDecFormula() {}
            using ElementType = ElementType;
            /// <summary>
            /// Trims the formula.
            /// </summary>
            void TrimFormula()
            {
                if (this->size() == 2 && at(0).size() == 1 && at(0).begin()->second.ElementCat == ElementType::Formula)//this[0][0].front() == "@")
                {
                    this[0] = this[1]; this->pop_back();//Reduce formula in (@1) to just @1
                }
            }

            MediumDec EvaluateOrderOfOperations(FormData& FormCopy)
            {
                MediumDec valResult;

                bool TempBool;
                MediumDec tempValue;
                MediumDec leftValue;
                MediumDec rightValue;

                IntVector& OpOrderElement = FormCopy.OpOrderMap[0];
                FormData::iterator OpIterator;
                auto OpVal = FormCopy.at(0);
                FormData::iterator LeftVal;
                FormData::iterator RightVal;
                MediumDec leftResult;
                MediumDec rightResult;

                //Applying operations via C++ variation of order of operations
                //https://en.cppreference.com/w/cpp/language/operator_precedence
                for (int opIndex = 0; opIndex < 12; ++opIndex)
                {
                    OpOrderElement = FormCopy.OpOrderMap[opIndex];
                    for (IntVector::iterator CurrentVal = OpOrderElement.begin(), LastVal = OpOrderElement.end(); CurrentVal != LastVal; ++CurrentVal)
                    {
                        OpIterator = FormCopy.find(*CurrentVal);
                        OpVal = FormCopy[*CurrentVal];
                        if (OpIterator->second.ElementCat != ElementType::Not && OpIterator->second.ElementCat != ElementType::Sqrt)
                        {
                            LeftVal = OpIterator - 1;
                            leftValue = LeftVal->second.ElementCat == ElementType::trueVal ? 1 : (LeftVal->second.ElementCat == ElementType::falseVal ? 0 : FormCopy.NumMap[LeftVal->first]);
                        }
                        RightVal = OpIterator + 1;
                        rightValue = RightVal->second.ElementCat == ElementType::trueVal ? 1 : (RightVal->second.ElementCat == ElementType::falseVal ? 0 : FormCopy.NumMap[RightVal->first]);

                        switch (opIndex)
                        {
                        default://placeholder code
                            break;
                        case 0:
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::Pow:
                                leftValue = MediumDec::PowOp(leftValue, rightValue);
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            case ElementType::Sqrt:
                                rightValue = MediumDec::Sqrt(rightValue);
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, rightValue);
                                break;
                            case ElementType::NthRoot:
                                rightValue = MediumDec::NthRootV2(rightValue, (int)leftValue);
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, rightValue);
                                break;
                            }
                            break;
                        case 1:
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::Not:
                                if (RightVal->second.ElementCat == ElementType::trueVal)
                                {
                                    FormCopy.at(RightVal->first).ElementCat = ElementType::falseVal;
                                }
                                else if (RightVal->second.ElementCat == ElementType::falseVal)
                                {
                                    FormCopy.at(RightVal->first).ElementCat = ElementType::trueVal;
                                }
                                else
                                {
                                    if (rightValue == MediumDec::Zero)//Zero is false otherwise count as if it was true
                                        FormCopy.SwitchOpToVal(OpVal, OpIterator->first, RightVal, true);
                                    else
                                        FormCopy.SwitchOpToVal(OpVal, OpIterator->first, RightVal, false);
                                }
                                FormCopy.erase(OpIterator);
                                break;
                            case ElementType::Negative://Only applies to numbers
                                rightValue.SwapNegativeStatus();
                                FormCopy.NumMap[RightVal->first] = rightValue;
                                break;
                            }
                            break;
                        case 2:// 	Multiplication, division, and remainder
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::Mult:
                                leftValue *= rightValue;
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            case ElementType::Div:
                                leftValue /= rightValue;
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            case ElementType::Rem:
                                leftValue %= rightValue;
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            }
                            break;
                        case 3://Addition and subtraction
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::Add:
                                leftValue += rightValue;
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            case ElementType::Sub:
                                leftValue -= rightValue;
                                FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                                break;
                            }
                            break;
                        case 4://<,<=, >, >=
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::LessThan:
                                TempBool = leftValue < rightValue;
                                break;
                            case ElementType::LessOrEqual:
                                TempBool = leftValue <= rightValue;
                                break;
                            case ElementType::GreaterThan:
                                TempBool = leftValue > rightValue;
                                break;
                            case ElementType::GreaterOrEqual:
                                TempBool = leftValue >= rightValue;
                                break;
                            }
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
                            break;
                        case 5://==, !=
                            switch (OpIterator->second.ElementCat)
                            {
                            case ElementType::Equal:
                                TempBool = leftValue == rightValue;
                                break;
                            case ElementType::NotEqual:
                                TempBool = leftValue != rightValue;
                                break;
                            }
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
                            break;
                        case 6://&
                            leftValue = leftValue & rightValue;
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case 7://XOR
                            leftValue = leftValue ^ rightValue;
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case 8:// | Bitwise OR (inclusive or)
                            leftValue = leftValue ^ rightValue;
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case 9://&&
                            TempBool = leftValue && rightValue;
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
                            break;
                        case 10:// || (Logical OR)
                            TempBool = leftValue || rightValue;
                            FormCopy.SwitchOpToVal(OpVal, OpIterator->first, LeftVal, RightVal, TempBool);
                            break;
                            //case 11://Ternary conditional, =, +=,   -=, *=,   /=,   %=,<<=,   >>=, &= ,  ^=,   |= (Not supported yet)
                            //	break;
                        }
                    }
                }
                if (FormCopy.size() == 1)
                {
                    FormData::iterator ElementIter = FormCopy.begin();
                    int KeyIndex = ElementIter->first;
                    if (ElementIter->second.ElementCat == ElementType::trueVal)
                    {
                        return MediumDec::One;
                    }
                    else if (ElementIter->second.ElementCat == ElementType::falseVal)
                    {
                        return MediumDec::Zero;
                    }
                    else if (ElementIter->second.ElementCat == ElementType::Num)
                    {
                        return FormCopy.NumMap[KeyIndex];
                    }
                    else if (ElementIter->second.ElementCat == ElementType::Variable)
                    {
                        std::string ErrorMessage = "Failed to evaluate variable named:" + FormCopy.VariableMap.at(KeyIndex).Name;
                        throw ErrorMessage;
                    }
                    else
                    {
                        std::string ErrorMessage = "Failed to evaluate Element with Element Category of:";
                        ErrorMessage += VariableConversionFunctions::IntToStringConversion((int)ElementIter->second.ElementCat);
                        throw ErrorMessage;
                    }
                }
                else
                {
                    throw "Failed to evaluate to single value!";
                }
            }

            void SwapReferencedData(FormData& FormCopy, std::map<std::string, MediumDec&>& ElementValues, size_t FormIndex = 0)
            {
                std::string CurString;
                char firstChar;
                MediumDec targetResult;
                for (FormData::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    if (CurrentVal->second.ElementCat == ElementType::Formula)//FormulaDetected
                    {
                        targetResult = RecursivelyEvalRefValues(ElementValues, CurrentVal->second.Index);
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult);
                    }
                    else if (CurrentVal->second.ElementCat == ElementType::Variable)//Swap Variable with values
                    {
                        FormCopy.ReplaceFormVal(CurrentVal->first, ElementValues.at(CurString));
                    }
                }
            }

            void SwapUpdatedFormData(FormData& FormCopy, std::map<std::string, MediumDec>& ElementValues, size_t FormIndex = 0)
            {
                std::string CurString;
                char firstChar;
                MediumDec targetResult;
                for (FormData::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    if (CurrentVal->second.ElementCat == ElementType::Formula)//FormulaDetected
                    {
                        targetResult = RecursivelyEvalValues(ElementValues, CurrentVal->second.Index);
                        FormCopy.ReplaceFormVal(CurrentVal->first, targetResult);
                    }
                    else if (CurrentVal->second.ElementCat == ElementType::Variable)//Swap Variable with values
                    {
                        FormCopy.ReplaceFormVal(CurrentVal->first, ElementValues.at(CurString));
                    }
                }
            }

            MediumDec RecursivelyEvalRefValues(std::map<std::string, MediumDec&>& ElementValues, size_t FormIndex)
            {//Each Formula Calculates order of operations etc separately
                FormData FormCopy = at(FormIndex);
                SwapReferencedData(FormCopy, ElementValues, FormIndex);
                return EvaluateOrderOfOperations(FormCopy);
            }

            MediumDec RecursivelyEvalValues(std::map<std::string, MediumDec>& ElementValues, size_t FormIndex)
            {//Each Formula Calculates order of operations etc separately
                FormData FormCopy = at(FormIndex);
                SwapUpdatedFormData(FormCopy, ElementValues, FormIndex);
                return EvaluateOrderOfOperations(FormCopy);
            }

            MediumDec EvalValueRefs(std::map<std::string, MediumDec&> ElementValues)
            {
                FormData FormCopy = this->at(0);//Duplicate values so can erase parts when calculating
                SwapReferencedData(FormCopy, ElementValues);
                return EvaluateOrderOfOperations(FormCopy);
            }

            MediumDec EvalValues(std::map<std::string, MediumDec> ElementValues)
            {
                FormData FormCopy = this->at(0);//Duplicate values so can erase parts when calculating
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
                int indexBuffer;
                for (FormData::iterator CurrentVal = at(FormIndex).begin(), LastVal = at(FormIndex).end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    switch (CurrentVal->second.ElementCat)
                    {
                    default:
                        break;
                    case ElementType::Formula:
                        strBuffer += "(";
                        RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                        strBuffer += ")";
                        break;
                    case ElementType::Num:
                        strBuffer += at(0).NumMap.at(CurrentVal->first).ToString();
                        break;
                    case ElementType::Variable:
                        strBuffer += at(FormIndex).VariableMap.at(CurrentVal->first).Name;
                        break;
                    case ElementType::trueVal:
                        strBuffer += "true";
                        break;
                    case ElementType::falseVal:
                        strBuffer += "false";
                        break;
                    case ElementType::Equal:
                        strBuffer += "==";
                        break;
                    case ElementType::NotEqual:
                        strBuffer += "!=";
                        break;
                    case ElementType::AND:
                        strBuffer += "&&";
                        break;
                    case ElementType::OR:
                        strBuffer += "||";
                        break;
                    case ElementType::Not:
                        strBuffer += "!";
                        break;
                    case ElementType::LessThan:
                        strBuffer += "<";
                        break;
                    case ElementType::LessOrEqual:
                        strBuffer += "<=";
                        break;
                    case ElementType::GreaterThan:
                        strBuffer += ">";
                        break;
                    case ElementType::GreaterOrEqual:
                        strBuffer += ">=";
                        break;
                    case ElementType::Add:
                        strBuffer += "+";
                        break;
                    case ElementType::Sub:
                        strBuffer += "-";
                        break;
                    case ElementType::Negative:
                        strBuffer += "-";
                        break;
                    case ElementType::Mult:
                        strBuffer += "*";
                        break;
                    case ElementType::Div:
                        strBuffer += "/";
                        break;
                    case ElementType::Pow:
                        strBuffer += "^";
                        break;
                    case ElementType::Sqrt:
                        strBuffer += " SqrtOf";
                        break;
                    case ElementType::NthRoot:
                        strBuffer += "thRootOf";
                        break;
                    case ElementType::Rem:
                        strBuffer += "%";
                        break;
                    case ElementType::PostFixPlus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += at(FormIndex).VariableMap.at(indexBuffer).Name + "++";
                        break;
                    case ElementType::PostFixMinus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += at(FormIndex).VariableMap.at(indexBuffer).Name + "++";
                        break;
                    case ElementType::PrefixPlus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += "++" + at(FormIndex).VariableMap.at(indexBuffer).Name;
                        break;
                    case ElementType::PrefixMinus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += "--" + at(FormIndex).VariableMap.at(indexBuffer).Name;
                        break;
                    case ElementType::BitwiseAND:
                        strBuffer += "&";
                        break;
                    case ElementType::XOR:
                        strBuffer += "XOR";
                        break;
                    case ElementType::BitwiseOr:
                        strBuffer += "|";
                        break;
                    }
                }
            }

            /// <summary>
            /// Converts to string(with no extra spacing applied).
            /// </summary>
            /// <returns>std.string.</returns>
            std::string ToString()
            {
                std::string strBuffer = "";
                std::string CurString;
                int indexBuffer;
                for (FormData::iterator CurrentVal = at(0).begin(), LastVal = at(0).end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    switch (CurrentVal->second.ElementCat)
                    {
                    case ElementType::Formula:
                        strBuffer += "(";
                        RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                        strBuffer += ")";
                        break;
                    case ElementType::Num:
                        strBuffer += at(0).NumMap.at(CurrentVal->first).ToString();
                        break;
                    case ElementType::Variable:
                        strBuffer += at(0).VariableMap.at(CurrentVal->first).Name;
                        break;
                    case ElementType::trueVal:
                        strBuffer += "true";
                        break;
                    case ElementType::falseVal:
                        strBuffer += "false";
                        break;
                    case ElementType::Equal:
                        strBuffer += "==";
                        break;
                    case ElementType::NotEqual:
                        strBuffer += "!=";
                        break;
                    case ElementType::AND:
                        strBuffer += "&&";
                        break;
                    case ElementType::OR:
                        strBuffer += "||";
                        break;
                    case ElementType::Not:
                        strBuffer += "!";
                        break;
                    case ElementType::LessThan:
                        strBuffer += "<";
                        break;
                    case ElementType::LessOrEqual:
                        strBuffer += "<=";
                        break;
                    case ElementType::GreaterThan:
                        strBuffer += ">";
                        break;
                    case ElementType::GreaterOrEqual:
                        strBuffer += ">=";
                        break;
                    case ElementType::Add:
                        strBuffer += "+";
                        break;
                    case ElementType::Sub:
                        strBuffer += "-";
                        break;
                    case ElementType::Negative:
                        strBuffer += "-";
                        break;
                    case ElementType::Mult:
                        strBuffer += "*";
                        break;
                    case ElementType::Div:
                        strBuffer += "/";
                        break;
                    case ElementType::Pow:
                        strBuffer += "^";
                        break;
                    case ElementType::Sqrt:
                        strBuffer += " SqrtOf";
                        break;
                    case ElementType::NthRoot:
                        strBuffer += "thRootOf";
                        break;
                    case ElementType::Rem:
                        strBuffer += "%";
                        break;
                    case ElementType::PostFixPlus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += at(0).VariableMap.at(indexBuffer).Name + "++";
                        break;
                    case ElementType::PostFixMinus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += at(0).VariableMap.at(indexBuffer).Name + "++";
                        break;
                    case ElementType::PrefixPlus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += "++" + at(0).VariableMap.at(indexBuffer).Name;
                        break;
                    case ElementType::PrefixMinus:
                        indexBuffer = CurrentVal->second.Index;
                        strBuffer += "--" + at(0).VariableMap.at(indexBuffer).Name;
                        break;
                    case ElementType::BitwiseAND:
                        strBuffer += "&";
                        break;
                    case ElementType::XOR:
                        strBuffer += "XOR";
                        break;
                    case ElementType::BitwiseOr:
                        strBuffer += "|";
                        break;
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
                    this->at(FormulaIndex).AddBool(true);
                }
                else if (ConvertedStr == "false")
                {
                    this->at(FormulaIndex).AddBool(false);
                }
                else if (ScanType == 3)
                {
                    this->at(FormulaIndex).AddVariable(strBuffer);
                }
                else if (ScanType == 4)
                {
                    this->at(FormulaIndex).AddNum(strBuffer);
                }
                else if (ScanType == 1)
                {
                    if (strBuffer == "+") { this->at(FormulaIndex).AddOp(ElementType::Add); }
                    else if (strBuffer == "-") { this->at(FormulaIndex).AddOp(ElementType::Sub); }
                    else if (strBuffer == "*") { this->at(FormulaIndex).AddOp(ElementType::Mult); }
                    else if (strBuffer == "/") { this->at(FormulaIndex).AddOp(ElementType::Div); }
                    else if (strBuffer == "%") { this->at(FormulaIndex).AddOp(ElementType::Rem); }
                    else if (strBuffer == "^") { this->at(FormulaIndex).AddOp(ElementType::Pow); }
                    else if (strBuffer == "SqrtOf") { this->at(FormulaIndex).AddOp(ElementType::Sqrt); }
                    else if (strBuffer == "==") { this->at(FormulaIndex).AddOp(ElementType::Equal); }
                    else if (strBuffer == "!=") { this->at(FormulaIndex).AddOp(ElementType::NotEqual); }
                    else if (strBuffer == "<") { this->at(FormulaIndex).AddOp(ElementType::LessThan); }
                    else if (strBuffer == "<=") { this->at(FormulaIndex).AddOp(ElementType::LessOrEqual); }
                    else if (strBuffer == ">") { this->at(FormulaIndex).AddOp(ElementType::GreaterThan); }
                    else if (strBuffer == ">=") { this->at(FormulaIndex).AddOp(ElementType::GreaterOrEqual); }
                    else if (strBuffer == "&&") { this->at(FormulaIndex).AddOp(ElementType::AND); }
                    else if (strBuffer == "||") { this->at(FormulaIndex).AddOp(ElementType::OR); }
                    else if (strBuffer == "thRootOf") { this->at(FormulaIndex).AddOp(ElementType::NthRoot); }
                    else if (strBuffer == "PowerOf") { this->at(FormulaIndex).AddOp(ElementType::Pow); }
                    else if (strBuffer == "&") { this->at(FormulaIndex).AddOp(ElementType::BitwiseAND); }
                    else if (strBuffer == "|") { this->at(FormulaIndex).AddOp(ElementType::BitwiseOr); }
                    else if (strBuffer == "$") { this->at(FormulaIndex).AddOp(ElementType::XOR); }
                }
                else if (ScanType == 11)//Prefix ++ or --
                {
                    this->at(FormulaIndex).AddPrefixOp(strBuffer);
                }
                else if (ScanType == 10)//Postfix Op ++ or --
                {
                    //this->at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
                }
                //else if(ScanType==12)
                //{
                //	this->at(FormulaIndex).AddTernaryOperatorOp(strBuffer);
                //}
                else//CATCH-ALL
                {
                    this->at(FormulaIndex).AddVariable(strBuffer);
                }
            }

            /// <summary>
            /// Resets to single blank formula
            /// </summary>
            void ResetToBlank()
            {
                this->clear();
                this->push_back(FormData());//Initialize first (Formula) field
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="MediumDecFormula" /> class.
            /// </summary>
            /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
            MediumDecFormula(std::string& ElemValue)
            {
                //0 = ???
                //1 = Operator
                //3 = Variable Value
                //4 = Number
                short ScanType = 0;
                std::string strBuffer = "";
                //Extra buffer for saving potential postfix etc(send as variable if confirmed not as postfix op)
                std::string secondaryBuffer = "";
                size_t FormulaIndex = 0;
                //size_t CurrentFormElement = 0;
                this->push_back(FormData());//Initialize first (Formula) field
                //auto targetForm = at(0);
                for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    if (*CurrentVal == '(')
                    {
                        //if(ScanType==10){strBuffer = at(FormulaIndex).back()+strBuffer;at(FormulaIndex).back()=strBuffer;}
                        if (!strBuffer.empty()) { InsertFromBuffer(strBuffer, FormulaIndex, ScanType); }
                        FormulaIndex = this->size();
                        this->push_back(FormData());
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
                                //this->at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
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
                            this->at(FormulaIndex).AddOp(ElementType::Not);
                        }
                        else if (*CurrentVal == '^')
                        {
                            this->at(FormulaIndex).AddOp(ElementType::Pow);
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
                                this->at(FormulaIndex).AddOp(ElementType::Negative);
                                if (*CurrentVal == '!')//Inverse operator detected after
                                {
                                    this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
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
                                this->at(FormulaIndex).AddOp(ElementType::NotEqual); strBuffer.clear(); ScanType = 0;
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
                                this->at(FormulaIndex).AddOp(ElementType::Add);
                                if (*CurrentVal == '!')//Inverse operator detected after
                                {
                                    this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
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
                                this->at(FormulaIndex).AddOp(ElementType::AND); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                this->at(FormulaIndex).AddOp(ElementType::BitwiseAND);
                                if (*CurrentVal == '!')
                                {
                                    this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
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
                                this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                this->at(FormulaIndex).AddOp(ElementType::BitwiseOr);
                                if (*CurrentVal == '!')
                                {
                                    this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
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
                                //this->at(FormulaIndex).AddOp(strBuffer + *CurrentVal); strBuffer.clear(); ScanType = 0;
                            }
                            else
                            {
                                //this->at(FormulaIndex).AddOp(strBuffer);
                                if (*CurrentVal == '!')
                                {
                                    this->at(FormulaIndex).AddOp(ElementType::Not); strBuffer.clear(); ScanType = 0;
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
                            this->at(FormulaIndex).AddOp(ElementType::Div);
                        }
                        else if (*CurrentVal == '*')
                        {
                            InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                            this->at(FormulaIndex).AddOp(ElementType::Mult);
                        }
                        else if (*CurrentVal == '^')//Power of function
                        {
                            InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                            this->at(FormulaIndex).AddOp(ElementType::Pow);
                        }
                        else if (*CurrentVal == '$')//Shorthand for XOR for now
                        {
                            InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                            this->at(FormulaIndex).AddOp(ElementType::XOR);
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
            /// Initializes a new instance of the <see cref="MediumDecFormula" /> class. from StringCopy instead of reference
            /// </summary>
            /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
            MediumDecFormula(std::string ElemValue, bool BlankVar) : MediumDecFormula(ElemValue) {}

            /// <summary>
            /// Initializes a new instance of the <see cref="MediumDecFormula" /> class.(fix for initializing without copying from a string value set)
            /// </summary>
            /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
            MediumDecFormula(const char* strVal) : MediumDecFormula(std::string(strVal), true) {}
        };
        MediumDecFormula Data;
        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecFormulaData" /> class. Use Data to access the actual formula
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        MediumDecFormulaData(std::string ElemValue)
        {
            Data = ElemValue;
        }
        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecFormulaData"/> class.
        /// </summary>
        /// <param name="strVal">The string value.</param>
        MediumDecFormulaData(const char* strVal)//: MediumDecFormulaData(std::string(strVal)) {}
        {
            Data = strVal;
        }
    };
}