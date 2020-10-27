// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

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

#include "ElementType.hpp"
#include <string>
#include "..\OtherFunctions\VariableConversionFunctions.h"
#include "..\tsl\ordered_map.h"
//#include <map>
#include <vector>
#include <unordered_map>

#include "..\AltNum\MediumDec.hpp"

namespace BlazesRusCode
{
    using IntVector = std::vector<int>;
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

    template<typename VarType>
    class DLL_API VariableFormula
    {
    public:
        class DLL_API VariableStoreData
        {
        public:
            /// <summary>
            /// Stored Variable Name
            /// </summary>
            std::string Name;

            /// <summary>
            /// The variable pointer data
            /// </summary>
            VarType* varPointerData;

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
            FormulaElementType ElementCat;

            /// <summary>
            /// (Primarily used for FormElements, ++,--, and TernaryOperator)
            /// The index/Key position of stored element (not used for booleans)
            //   For variable names: If not -1, refers to stored related Value Key(which is used for prefix/postfix ops as well)
            //   For Increment/Decrement Op: Refers to index of related value
            /// </summary>
            int Index;

            /// <summary>
            /// Initializes a new instance of the <see cref="VarTypeFormElement"/> class. (Defaults as boolean with true value)
            /// </summary>
            FormElement()
            {
                ElementCat = FormulaElementType::trueVal;
                Index = -1;
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="VarTypeFormElement"/> class.
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="index">The index.</param>
            FormElement(FormulaElementType Value, int index = 0)
            {
                ElementCat = Value;
                Index = index;
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="VarTypeFormElement"/> class for PostFix OpValue.
            /// </summary>
            /// <param name="Value">The value.</param>
            /// <param name="opBuffer">The operator value.</param>
            FormElement(std::string Value, std::string opBuffer, std::unordered_map<std::string, int>& VariableStorageMap)
            {
                if (opBuffer == "++") { ElementCat = FormulaElementType::PostFixPlus; }
                else { ElementCat = FormulaElementType::PostFixMinus; }
                //Create new variable storage and set index to it if variable storage matching key doesn't exist
                //int Index = VariableStorageMap.find(Value);
                //if ()
                //{
                //}
                Index = -1;
            }
        };

        /// <summary>
        /// VarType Formula Data (Variant of OrderedIndexDictionary)
        /// Implements the <see cref="tsl::ordered_map{int, VarTypeFormElement}" />
        /// </summary>
        /// <seealso cref="tsl::ordered_map{int, VarTypeFormElement}" />
        class DLL_API FormData : public tsl::ordered_map<int, FormElement>
        {
        private:
            using IntVector = std::vector<int>;
        public:
            int LastAdded = -1;

            /// <summary>
            /// Map of operation Index Values by with key storing precedence category (of those used for formula code) starting from zero
            /// </summary>
            std::vector<IntVector> OpOrderMap;

            /// <summary>
            /// The map that stores the actual numbers referenced
            /// </summary>
            std::unordered_map<int, VarType> NumMap;

            /// <summary>
            /// The map that stores the Variable Names and potential pointers to the referenced variable
            /// </summary>
            std::unordered_map<int, VariableStoreData> VariableMap;

            /// <summary>
            /// The variable storage map with Variable Name linked to related Index(shortcut)
            /// </summary>
            std::unordered_map<std::string, int> VariableStorageMap;

            /// <summary>
            /// Indexes last removed from map
            /// </summary>
            std::vector<int> RemovedIndexes;
        private:
            /// <summary>
            /// The next index
            /// </summary>
            int NextIndex = 0;
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
            void ReplaceFormValWBool(int Key, bool Value)
            {
                FormElement& KeyedVal = this->at(Key);
                if (Value) { KeyedVal.ElementCat = FormulaElementType::trueVal; }
                else { KeyedVal.ElementCat = FormulaElementType::falseVal; }
            }

            /// <summary>
            /// Replaces the non-number based form value (and add to number map).
            /// </summary>
            /// <param name="Key">The key.</param>
            /// <param name="Value">The value.</param>
            void ReplaceFormVal(int Key, VarType Value)
            {
                FormElement& KeyedVal = this->at(Key);
                KeyedVal.ElementCat = FormulaElementType::Num;
                NumMap.insert_or_assign(Key, Value);
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
                LastAdded = Add(FormElement(FormulaElementType::Num));
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
                    LastAdded = Add(FormElement(FormulaElementType::Variable));
                    this->at(LastAdded).Index = LastAdded;
                    VariableMap.insert_or_assign(LastAdded, Value);
                    VariableStorageMap.insert_or_assign(Value, LastAdded);
                }
                else
                {
                    LastAdded = Add(FormElement(FormulaElementType::Variable, foundValue->second));
                }
            }

            /// <summary>
            /// Adds the specified value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void AddBool(bool Value)
            {
                if (Value)
                    LastAdded = Add(FormElement(FormulaElementType::trueVal));
                else
                    LastAdded = Add(FormElement(FormulaElementType::falseVal));
            }

            /// <summary>
            /// Adds the specified operator value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void AddOp(FormulaElementType value)
            {
                LastAdded = Add(FormElement(value));
                switch (value)
                {
                    //"++PostFix"||Value=="--PostFix")//(Group 2 precedence, left to right associativity)
                case FormulaElementType::Pow:
                    OpOrderMap[0].push_back(LastAdded);
                    break;
                    //++Prefix, --Prefix as well(Group 3 precedence, right to left associativity)
                case FormulaElementType::Not:
                    OpOrderMap[1].push_back(LastAdded);
                    break;
                default:
                    break;
                }
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
        /// Class VariableFormula. (FormulaElement)Operator(FormulaElement)
        /// FormulaElements stored as std::vector<std::string>
        /// Expression Example: ((Variable01 >= 1)&&(Variable02>2.5))
        /// with (Variable01 >= 1) FormulaElement values:
        /// Variable01, >=, #i0
        /// with (Variable01 >= 1) values referenced from:
        /// Variable01, >=, IntValues[0]
        /// with (Variable02>2.5) FormulaElement values:
        /// Variable02, >, #i0
        /// with (Variable02>2.5) values referenced from:
        /// Variable02, >, VarTypeValues[0]
        /// Initial FormulaElement Values : @1, &&, @2
        /// </summary>
        std::vector<FormData> Data;

        /// <summary>
        /// Trims the formula.
        /// </summary>
        void TrimFormula()
        {
            if (Data.size() == 2 && Data.at(0).size() == 1 && Data.at(0).begin()->second.ElementCat == FormulaElementType::Formula)//Data[0][0].front() == "@")
            {
                Data[0] = Data[1]; Data.pop_back();//Reduce formula in (@1) to just @1
            }
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
                Data.at(FormulaIndex).AddBool(true);
            }
            else if (ConvertedStr == "false")
            {
                Data.at(FormulaIndex).AddBool(false);
            }
            else if (ScanType == 3)
            {
                Data.at(FormulaIndex).AddVariable(strBuffer);
            }
            else if (ScanType == 4)
            {
                Data.at(FormulaIndex).AddNum(strBuffer);
            }
            else if (ScanType == 1)
            {
                if (strBuffer == "+") { Data.at(FormulaIndex).AddOp(FormulaElementType::Add); }
                else if (strBuffer == "-") { Data.at(FormulaIndex).AddOp(FormulaElementType::Sub); }
                else if (strBuffer == "*") { Data.at(FormulaIndex).AddOp(FormulaElementType::Mult); }
                else if (strBuffer == "/") { Data.at(FormulaIndex).AddOp(FormulaElementType::Div); }
                else if (strBuffer == "%") { Data.at(FormulaIndex).AddOp(FormulaElementType::Rem); }
                else if (strBuffer == "^") { Data.at(FormulaIndex).AddOp(FormulaElementType::Pow); }
                else if (strBuffer == "SqrtOf") { Data.at(FormulaIndex).AddOp(FormulaElementType::Sqrt); }
                else if (strBuffer == "==") { Data.at(FormulaIndex).AddOp(FormulaElementType::Equal); }
                else if (strBuffer == "!=") { Data.at(FormulaIndex).AddOp(FormulaElementType::NotEqual); }
                else if (strBuffer == "<") { Data.at(FormulaIndex).AddOp(FormulaElementType::LessThan); }
                else if (strBuffer == "<=") { Data.at(FormulaIndex).AddOp(FormulaElementType::LessOrEqual); }
                else if (strBuffer == ">") { Data.at(FormulaIndex).AddOp(FormulaElementType::GreaterThan); }
                else if (strBuffer == ">=") { Data.at(FormulaIndex).AddOp(FormulaElementType::GreaterOrEqual); }
                else if (strBuffer == "&&") { Data.at(FormulaIndex).AddOp(FormulaElementType::AND); }
                else if (strBuffer == "||") { Data.at(FormulaIndex).AddOp(FormulaElementType::OR); }
                else if (strBuffer == "thRootOf") { Data.at(FormulaIndex).AddOp(FormulaElementType::NthRoot); }
                else if (strBuffer == "PowerOf") { Data.at(FormulaIndex).AddOp(FormulaElementType::Pow); }
                else if (strBuffer == "&") { Data.at(FormulaIndex).AddOp(FormulaElementType::BitwiseAND); }
                else if (strBuffer == "|") { Data.at(FormulaIndex).AddOp(FormulaElementType::BitwiseOr); }
                else if (strBuffer == "$") { Data.at(FormulaIndex).AddOp(FormulaElementType::XOR); }
            }
            else if (ScanType == 11)//Prefix ++ or --
            {
                Data.at(FormulaIndex).AddPrefixOp(strBuffer);
            }
            else if (ScanType == 10)//Postfix Op ++ or --
            {
                //Data.at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
            }
            //else if(ScanType==12)
            //{
            //	Data.at(FormulaIndex).AddTernaryOperatorOp(strBuffer);
            //}
            else//CATCH-ALL
            {
                Data.at(FormulaIndex).AddVariable(strBuffer);
            }
        }

        /// <summary>
        /// Resets to single blank formula
        /// </summary>
        void ResetToBlank()
        {
            Data.clear();
            Data.push_back(FormData());//Initialize first (Formula) field
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VariableFormula" /> class.
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        VariableFormula() { Data.push_back(FormData());//Initialize first (Formula) field}
        }
    };
}