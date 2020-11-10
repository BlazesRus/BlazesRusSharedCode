// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"
#include "VariableFormula.hpp"
#include "..\AltNum\MediumDec.hpp"
#include "ElementType.hpp"
#include "tsl\ordered_map.h"

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
    class DLL_API MediumDecFormula : public VariableFormula<MediumDec>
    {
    public:

        /// <summary>
        /// Switches the operator into boolean value and erases old left+right side value.
        /// </summary>
        /// <param name="FormCopy">The form copy.</param>
        /// <param name="OpVal">The op value.</param>
        /// <param name="LeftIterator">The left iterator.</param>
        /// <param name="RightIterator">The right iterator.</param>
        /// <param name="Value">The value.</param>
        void SwitchOpToBoolVal(FormData& FormCopy, FormElement& OpVal, FormData::iterator& LeftIterator, FormData::iterator& RightIterator, bool Value)
        {
            if (Value) { OpVal.ElementCat = FormulaElementType::trueVal; }
            else { OpVal.ElementCat = FormulaElementType::falseVal; }

            if (LeftIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(LeftIterator->first); }
            if (RightIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(RightIterator->first); }

            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            FormCopy.erase(LeftIterator); FormCopy.erase(RightKey);
            FormCopy.RemovedIndexes.push_back(LeftKey); FormCopy.RemovedIndexes.push_back(RightKey);
        }

        /// <summary>
        /// Switches the operator into boolean value and erases old right side value.
        /// </summary>
        /// <param name="FormCopy">The formula data copy.</param>
        /// <param name="OpVal">The op value.</param>
        /// <param name="RightIterator">The right side value iterator.</param>
        /// <param name="Value">The value.</param>
        void SwitchOpToRBoolVal(FormData& FormCopy, FormElement& OpVal, FormData::iterator& RightIterator, bool Value)
        {
            if (Value) { OpVal.ElementCat = FormulaElementType::trueVal; }
            else { OpVal.ElementCat = FormulaElementType::falseVal; }

            if (RightIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(RightIterator->first); }

            FormCopy.erase(RightIterator);
            FormCopy.RemovedIndexes.push_back(RightIterator->first);
        }

        /// <summary>
        /// Switches the operator into Value and erases old right side Value
        /// </summary>
        /// <param name="FormCopy">The formula data copy.</param>
        /// <param name="OpVal">The operator element value.</param>
        /// <param name="OpKey">The operator key.</param>
        /// <param name="RightIterator">The right side value iterator.</param>
        /// <param name="Value">The value to turn operator into.</param>
        void SwitchOpToRVal(FormData& FormCopy, FormElement& OpVal, int OpKey, FormData::iterator& RightIterator, MediumDec Value)
        {
            FormCopy.NumMap.insert_or_assign(OpKey, Value);
            OpVal.ElementCat = FormulaElementType::Num;

            if (RightIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(RightIterator->first); }

            int RightKey = RightIterator->first;
            FormCopy.erase(RightKey);
            FormCopy.RemovedIndexes.push_back(RightKey);
        }

        /// <summary>
        /// Switches the operator into Value and erases old left+right side Value
        /// </summary>
        /// <param name="FormCopy">The formula data copy.</param>
        /// <param name="OpVal">The operator element value.</param>
        /// <param name="OpKey">The operator key.</param>
        /// <param name="RightIterator">The right value iterator.</param>
        /// <param name="RightIterator">The right value iterator.</param>
        /// <param name="Value">The value to turn operator into.</param>
        void SwitchOpToVal(FormData& FormCopy, FormElement& OpVal, int OpKey, FormData::iterator& LeftIterator, FormData::iterator& RightIterator, MediumDec Value)
        {
            FormCopy.NumMap.insert_or_assign(OpKey, Value);
            OpVal.ElementCat = FormulaElementType::Num;

            if (LeftIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(LeftIterator->first); }
            if (RightIterator->second.ElementCat == FormulaElementType::Num) { FormCopy.NumMap.erase(RightIterator->first); }

            int LeftKey = LeftIterator->first; int RightKey = RightIterator->first;
            FormCopy.erase(LeftIterator); FormCopy.erase(RightKey);
            FormCopy.RemovedIndexes.push_back(LeftKey); FormCopy.RemovedIndexes.push_back(RightKey);
        }

        void EvaluateOperations(size_t FormIndex = 0)
        {
            FormData& FormDRef = Data.at(FormIndex);
            MediumDec valResult;

            bool TempBool;
            MediumDec leftValue;
            MediumDec rightValue;

            IntVector& OpOrderElement = FormDRef.OpOrderMap[0];
            FormData::iterator OpIterator;
            auto OpVal = FormDRef.at(0);
            FormData::iterator LeftVal;
            FormData::iterator RightVal;
            MediumDec leftResult;
            MediumDec rightResult;

            //Applying operations via C++ variation of order of operations
            //https://en.cppreference.com/w/cpp/language/operator_precedence
            for (int opIndex = 0; opIndex < 11; ++opIndex)
            {
                OpOrderElement = FormDRef.OpOrderMap[opIndex];
                for (IntVector::iterator CurrentVal = OpOrderElement.begin(), LastVal = OpOrderElement.end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    OpIterator = FormDRef.find(*CurrentVal);
                    OpVal = FormDRef[*CurrentVal];
                    if (OpIterator->second.ElementCat != FormulaElementType::Not && OpIterator->second.ElementCat != FormulaElementType::Sqrt)
                    {
                        LeftVal = OpIterator - 1;
                        if (LeftVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                        {
                            FormData& targetFormulaRef = Data.at(LeftVal->second.Index);
                            if (targetFormulaRef.size() != 1)
                            {
                                EvaluateOperations(LeftVal->second.Index);//Condense inner formula if can
                            }
                            continue;//Ignore operations with inner formula results for now for now
                        }
                        else if (LeftVal->second.ElementCat == FormulaElementType::Formula)
                            continue;
                        else
                            leftValue = LeftVal->second.ElementCat == FormulaElementType::trueVal ? 1 : (LeftVal->second.ElementCat == FormulaElementType::falseVal ? 0 : FormDRef.NumMap[LeftVal->first]);
                    }
                    RightVal = OpIterator + 1;
                    if (RightVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                    {
                        FormData& targetFormulaRef = Data.at(RightVal->second.Index);
                        if (targetFormulaRef.size() != 1)
                        {
                            EvaluateOperations(LeftVal->second.Index);//Condense inner formula if can
                        }
                        continue;//Ignore operations with inner formula results for now for now
                    }
                    else if (LeftVal->second.ElementCat == FormulaElementType::Formula)
                        continue;
                    else
                        rightValue = RightVal->second.ElementCat == FormulaElementType::trueVal ? 1 : (RightVal->second.ElementCat == FormulaElementType::falseVal ? 0 : FormDRef.NumMap[RightVal->first]);

                    switch (opIndex)
                    {
                    default://placeholder code
                        break;
                    case 0:
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Pow:
                            leftValue = MediumDec::PowOp(leftValue, rightValue);
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, rightValue);
                            break;
                        case FormulaElementType::Sqrt:
                            rightValue = MediumDec::Sqrt(rightValue);
                            SwitchOpToRVal(FormDRef, OpVal, OpIterator->first, RightVal, rightValue);
                            break;
                        case FormulaElementType::NthRoot:
                            rightValue = MediumDec::NthRootV2(rightValue, (int)leftValue);
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, rightValue);
                            break;
                        case FormulaElementType::LN:
                            rightValue = MediumDec::Ln(rightValue);
                            SwitchOpToRVal(FormDRef, OpVal, OpIterator->first, RightVal, rightValue);
                            break;
                        case FormulaElementType::LOGTEN:
                            rightValue = MediumDec::Log10(rightValue);
                            SwitchOpToRVal(FormDRef, OpVal, OpIterator->first, RightVal, rightValue);
                            break;
                        //case FormulaElementType::BaseNLog:
                        //    rightValue = MediumDec::Log(rightValue, leftValue);
                        //    SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, rightValue);
                        //    break;
                        }
                        break;
                    case 1:
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Not:
                            if (RightVal->second.ElementCat == FormulaElementType::trueVal)
                            {
                                FormDRef.at(RightVal->first).ElementCat = FormulaElementType::falseVal;
                            }
                            else if (RightVal->second.ElementCat == FormulaElementType::falseVal)
                            {
                                FormDRef.at(RightVal->first).ElementCat = FormulaElementType::trueVal;
                            }
                            else
                            {
                                if (rightValue == MediumDec::Zero)//Zero is false otherwise count as if it was true
                                    SwitchOpToRBoolVal(FormDRef, OpVal, RightVal, true);
                                else
                                    SwitchOpToRBoolVal(FormDRef, OpVal, RightVal, false);
                            }
                            FormDRef.erase(OpIterator);
                            break;
                        case FormulaElementType::Negative://Only applies to numbers
                            rightValue.SwapNegativeStatus();//rightValue = -rightValue;
                            FormDRef.NumMap[RightVal->first] = rightValue;
                            break;
                        }
                        break;
                    case 2:// 	Multiplication, division, and remainder
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Mult:
                            leftValue *= rightValue;
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case FormulaElementType::Div:
                            leftValue /= rightValue;
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case FormulaElementType::Rem:
                            leftValue %= rightValue;
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        }
                        break;
                    case 3://Addition and subtraction
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Add:
                            leftValue += rightValue;
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        case FormulaElementType::Sub:
                            leftValue -= rightValue;
                            SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                            break;
                        }
                        break;
                    case 4://<,<=, >, >=
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::LessThan:
                            TempBool = leftValue < rightValue;
                            break;
                        case FormulaElementType::LessOrEqual:
                            TempBool = leftValue <= rightValue;
                            break;
                        case FormulaElementType::GreaterThan:
                            TempBool = leftValue > rightValue;
                            break;
                        case FormulaElementType::GreaterOrEqual:
                            TempBool = leftValue >= rightValue;
                            break;
                        }
                        SwitchOpToBoolVal(FormDRef, OpVal, LeftVal, RightVal, TempBool);
                        break;
                    case 5://==, !=
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Equal:
                            TempBool = leftValue == rightValue;
                            break;
                        case FormulaElementType::NotEqual:
                            TempBool = leftValue != rightValue;
                            break;
                        }
                        SwitchOpToBoolVal(FormDRef, OpVal, LeftVal, RightVal, TempBool);
                        break;
                    case 6://&
                        leftValue = leftValue & rightValue;
                        SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                        break;
                    case 7://XOR
                        leftValue = leftValue ^ rightValue;
                        SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                        break;
                    case 8:// | Bitwise OR (inclusive or)
                        leftValue = leftValue ^ rightValue;
                        SwitchOpToVal(FormDRef, OpVal, OpIterator->first, LeftVal, RightVal, leftValue);
                        break;
                    case 9://&&
                        TempBool = leftValue && rightValue;
                        SwitchOpToBoolVal(FormDRef, OpVal, LeftVal, RightVal, TempBool);
                        break;
                    case 10:// || (Logical OR)
                        TempBool = leftValue || rightValue;
                        SwitchOpToBoolVal(FormDRef, OpVal, LeftVal, RightVal, TempBool);
                        break;
                    //case 11://Ternary conditional, =, +=,   -=, *=,   /=,   %=,<<=,   >>=, &= ,  ^=,   |= (Not supported yet)
                    //    break;
                    }
                }
            }
        }

        /// <summary>
        /// Swaps the updated form data.
        /// </summary>
        /// <param name="FormCopy">The form copy.</param>
        /// <param name="ElementValues">The element values.</param>
        /// <param name="FormIndex">Index of the form.</param>
        void ReplaceVariablesWithRefValues(ReferenceMap ElementValues, size_t FormIndex = 0)
        {
            std::string CurString;
            MediumDec targetResult;
            FormData& FormDRef = Data.at(FormIndex);
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (CurrentVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                {
                    ReplaceVariablesWithRefValues(ElementValues, CurrentVal->second.Index);
                }
                else if (CurrentVal->second.ElementCat == FormulaElementType::Variable)//Swap Variable with values
                {
                    CurString = FormDRef.VariableMap.at(CurrentVal->first).Name;
                    tsl::ordered_map<std::string, MediumDec&>::iterator KeyedElemVal = ElementValues.find(CurString);
                    if (KeyedElemVal != ElementValues.end())//Only attempt to replace variable if matching variable is found
                    {
                        FormDRef.at(CurrentVal->first).ElementCat = FormulaElementType::Num;
                        targetResult = KeyedElemVal.value();
                        FormDRef.NumMap.insert_or_assign(CurrentVal->first, targetResult);//ElementValues.at(CurString));
                    }
                    else
                    {
                        std::cout << "Failed to replace variable named " << CurString << " with value data" << std::endl;
                    }
                }
            }
        }

        /// <summary>
        /// Simplifies and evaluates the formula and then returns the copy.
        /// </summary>
        /// <param name="ElementValues">The element values.</param>
        /// <returns>BlazesRusCode.MediumDecFormula</returns>
        MediumDecFormula EvaluateRefToSimplifiedForm(ReferenceMap ElementValues)
        {
            MediumDecFormula FormCopy = *this;//Duplicate values so can erase parts when calculating
            FormCopy.ReplaceVariablesWithRefValues(ElementValues);
            FormCopy.EvaluateOperations();
            return FormCopy;
        }

        /// <summary>
        /// Swaps the updated form data.
        /// </summary>
        /// <param name="FormCopy">The form copy.</param>
        /// <param name="ElementValues">The element values.</param>
        /// <param name="FormIndex">Index of the form.</param>
        void ReplaceVariablesWithValues(ValueMap& ElementValues, size_t FormIndex = 0)
        {
            std::string CurString;
            MediumDec targetResult;
            FormData& FormDRef = Data.at(FormIndex);
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (CurrentVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                {
                    ReplaceVariablesWithValues(ElementValues, CurrentVal->second.Index);
                    //if (Data.at(CurrentVal->second.Index).size() == 1)
                    //{
                    //    FormData& ContainedFormulaElement = Data.at(CurrentVal->first);
                    //    auto FirstElement = ContainedFormulaElement.front();
                    //    /*
                    //    if(ContainedFormulaElement.ElementCat == FormulaElementType::Num)
                    //    {
                    //    }
                    //    */
                    //    //targetResult = ContainedFormulaElement.;
                    //    //FormDRef.ReplaceFormVal(CurrentVal->first, targetResult);
                    //}
                }
                else if (CurrentVal->second.ElementCat == FormulaElementType::Variable)//Swap Variable with values
                {
                    CurString = FormDRef.VariableMap.at(CurrentVal->first).Name;
                    tsl::ordered_map<std::string, MediumDec>::iterator KeyedElemVal = ElementValues.find(CurString);
                    if(KeyedElemVal!= ElementValues.end())//Only attempt to replace variable if matching variable is found
                    {
                        FormDRef.at(CurrentVal->first).ElementCat = FormulaElementType::Num;
                        targetResult = KeyedElemVal.value();
                        FormDRef.NumMap.insert_or_assign(CurrentVal->first, targetResult);//ElementValues.at(CurString));
                    }
                    else
                    {
                        std::cout << "Failed to replace variable named " << CurString << " with value data" << std::endl;
                    }
                }
            }
        }

        /// <summary>
        /// Simplifies and evaluates the formula and then returns the copy.
        /// </summary>
        /// <param name="ElementValues">The element values.</param>
        /// <returns>BlazesRusCode.MediumDecFormula</returns>
        MediumDecFormula EvaluateToSimplifiedForm(ValueMap ElementValues)
        {
            MediumDecFormula FormCopy = *this;//Duplicate values so can erase parts when calculating
            FormCopy.ReplaceVariablesWithValues(ElementValues);
            FormCopy.EvaluateOperations();
            return FormCopy;
        }

        /// <summary>
        /// Recursively adds to the string.
        /// </summary>
        /// <param name="strBuffer">The string buffer.</param>
        /// <param name="FormIndex">Index of the form.</param>
        void RecursivelyAddToString(std::string& strBuffer, size_t FormIndex)
        {
            FormData& FormDRef = Data.at(FormIndex);
            int indexBuffer;
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                switch (CurrentVal->second.ElementCat)
                {
                default:
                    break;
                case FormulaElementType::Formula:
                    strBuffer += "(";
                    RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                    strBuffer += ")";
                    break;
                case FormulaElementType::Num:
                    strBuffer += FormDRef.NumMap.at(CurrentVal->first).ToString();
                    break;
                case FormulaElementType::Variable:
                    strBuffer += FormDRef.VariableMap.at(CurrentVal->first).Name;
                    break;
                case FormulaElementType::trueVal:
                    strBuffer += "true";
                    break;
                case FormulaElementType::falseVal:
                    strBuffer += "false";
                    break;
                case FormulaElementType::Equal:
                    strBuffer += "==";
                    break;
                case FormulaElementType::NotEqual:
                    strBuffer += "!=";
                    break;
                case FormulaElementType::AND:
                    strBuffer += "&&";
                    break;
                case FormulaElementType::OR:
                    strBuffer += "||";
                    break;
                case FormulaElementType::Not:
                    strBuffer += "!";
                    break;
                case FormulaElementType::LessThan:
                    strBuffer += "<";
                    break;
                case FormulaElementType::LessOrEqual:
                    strBuffer += "<=";
                    break;
                case FormulaElementType::GreaterThan:
                    strBuffer += ">";
                    break;
                case FormulaElementType::GreaterOrEqual:
                    strBuffer += ">=";
                    break;
                case FormulaElementType::Add:
                    strBuffer += "+";
                    break;
                case FormulaElementType::Sub:
                    strBuffer += "-";
                    break;
                case FormulaElementType::Negative:
                    strBuffer += "-";
                    break;
                case FormulaElementType::Mult:
                    strBuffer += "*";
                    break;
                case FormulaElementType::Div:
                    strBuffer += "/";
                    break;
                case FormulaElementType::Pow:
                    strBuffer += "^";
                    break;
                case FormulaElementType::Sqrt:
                    strBuffer += " SqrtOf";
                    break;
                case FormulaElementType::NthRoot:
                    strBuffer += "thRootOf";
                    break;
                case FormulaElementType::Rem:
                    strBuffer += "%";
                    break;
                case FormulaElementType::PostFixPlus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += FormDRef.VariableMap.at(indexBuffer).Name + "++";
                    break;
                case FormulaElementType::PostFixMinus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += FormDRef.VariableMap.at(indexBuffer).Name + "++";
                    break;
                case FormulaElementType::PrefixPlus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += "++" + FormDRef.VariableMap.at(indexBuffer).Name;
                    break;
                case FormulaElementType::PrefixMinus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += "--" + FormDRef.VariableMap.at(indexBuffer).Name;
                    break;
                case FormulaElementType::BitwiseAND:
                    strBuffer += "&";
                    break;
                case FormulaElementType::XOR:
                    strBuffer += "XOR";
                    break;
                case FormulaElementType::BitwiseOr:
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
            FormData& FormDRef = Data.at(0);
            int indexBuffer;
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                switch (CurrentVal->second.ElementCat)
                {
                case FormulaElementType::Formula:
                    strBuffer += "(";
                    indexBuffer = CurrentVal->second.Index;
                    RecursivelyAddToString(strBuffer, indexBuffer);//CurrentVal->second.Index);
                    strBuffer += ")";
                    break;
                case FormulaElementType::Num:
                    strBuffer += FormDRef.NumMap.at(CurrentVal->first).ToString();
                    break;
                case FormulaElementType::Variable:
                    strBuffer += FormDRef.VariableMap.at(CurrentVal->first).Name;
                    break;
                case FormulaElementType::trueVal:
                    strBuffer += "true";
                    break;
                case FormulaElementType::falseVal:
                    strBuffer += "false";
                    break;
                case FormulaElementType::Equal:
                    strBuffer += "==";
                    break;
                case FormulaElementType::NotEqual:
                    strBuffer += "!=";
                    break;
                case FormulaElementType::AND:
                    strBuffer += "&&";
                    break;
                case FormulaElementType::OR:
                    strBuffer += "||";
                    break;
                case FormulaElementType::Not:
                    strBuffer += "!";
                    break;
                case FormulaElementType::LessThan:
                    strBuffer += "<";
                    break;
                case FormulaElementType::LessOrEqual:
                    strBuffer += "<=";
                    break;
                case FormulaElementType::GreaterThan:
                    strBuffer += ">";
                    break;
                case FormulaElementType::GreaterOrEqual:
                    strBuffer += ">=";
                    break;
                case FormulaElementType::Add:
                    strBuffer += "+";
                    break;
                case FormulaElementType::Sub:
                    strBuffer += "-";
                    break;
                case FormulaElementType::Negative:
                    strBuffer += "-";
                    break;
                case FormulaElementType::Mult:
                    strBuffer += "*";
                    break;
                case FormulaElementType::Div:
                    strBuffer += "/";
                    break;
                case FormulaElementType::Pow:
                    strBuffer += "^";
                    break;
                case FormulaElementType::Sqrt:
                    strBuffer += " SqrtOf";
                    break;
                case FormulaElementType::NthRoot:
                    strBuffer += "thRootOf";
                    break;
                case FormulaElementType::Rem:
                    strBuffer += "%";
                    break;
                case FormulaElementType::PostFixPlus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += FormDRef.VariableMap.at(indexBuffer).Name + "++";
                    break;
                case FormulaElementType::PostFixMinus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += FormDRef.VariableMap.at(indexBuffer).Name + "++";
                    break;
                case FormulaElementType::PrefixPlus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += "++" + FormDRef.VariableMap.at(indexBuffer).Name;
                    break;
                case FormulaElementType::PrefixMinus:
                    indexBuffer = CurrentVal->second.Index;
                    strBuffer += "--" + FormDRef.VariableMap.at(indexBuffer).Name;
                    break;
                case FormulaElementType::BitwiseAND:
                    strBuffer += "&";
                    break;
                case FormulaElementType::XOR:
                    strBuffer += "XOR";
                    break;
                case FormulaElementType::BitwiseOr:
                    strBuffer += "|";
                    break;
                }
            }
            return strBuffer;
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
            Data.push_back(FormData());//Initialize first (Formula) field
            //auto targetForm = at(0);
            for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (*CurrentVal == '(')
                {
                    //if(ScanType==10){strBuffer = at(FormulaIndex).back()+strBuffer;at(FormulaIndex).back()=strBuffer;}
                    if (!strBuffer.empty()){ InsertFromBuffer(strBuffer, FormulaIndex, ScanType); strBuffer.clear(); }
                    FormulaIndex = AddFormulaToBuffer(FormulaIndex);
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
                            //Data.at(FormulaIndex).ChangeLastToPostfixOp(strBuffer, FormulaIndex);
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
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Not);
                    }
                    else if (*CurrentVal == '^')
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Pow);
                    }
/*
                    else if(*CurrentVal == '?')//TernaryOperator detection start
                    {
                    	strBuffer = Data.at(FormulaIndex).ExtractLastElem();
                    	ScanType = 12;
                    }
*/
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
                            ScanType = 4; strBuffer += *CurrentVal;
                        }
                        else if (*CurrentVal == '-')//-- Operator
                        {
                            strBuffer = "--"; ScanType = 11;
                        }
                        else//- Operator
                        {
                            Data.at(FormulaIndex).AddOp(FormulaElementType::Negative);
                            if (*CurrentVal == '!')//Inverse operator detected after
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
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
                            Data.at(FormulaIndex).AddOp(FormulaElementType::NotEqual); strBuffer.clear(); ScanType = 0;
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
                            strBuffer = "++"; ScanType = 11;//Data.at(FormulaIndex).push_back("++"); strBuffer.clear(); ScanType = 0;
                        }
                        else//+ Operator
                        {
                            Data.at(FormulaIndex).AddOp(FormulaElementType::Add);
                            if (*CurrentVal == '!')//Inverse operator detected after
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
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
                            Data.at(FormulaIndex).AddOp(FormulaElementType::AND); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            Data.at(FormulaIndex).AddOp(FormulaElementType::BitwiseAND);
                            if (*CurrentVal == '!')
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
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
                            Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            Data.at(FormulaIndex).AddOp(FormulaElementType::BitwiseOr);
                            if (*CurrentVal == '!')
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
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
                            //Data.at(FormulaIndex).AddOp(strBuffer + *CurrentVal); strBuffer.clear(); ScanType = 0;
                        }
                        else
                        {
                            //Data.at(FormulaIndex).AddOp(strBuffer);
                            if (*CurrentVal == '!')
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Not); strBuffer.clear(); ScanType = 0;
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
                        Data.at(FormulaIndex).AddPrefixOp(strBuffer);
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
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Div);
                    }
                    else if (*CurrentVal == '*')
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Mult);
                    }
                    else if (*CurrentVal == '^')//Power of function
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Pow);
                    }
                    else if (*CurrentVal == '$')//Shorthand for XOR for now
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::XOR);
                    }
                    else
                    {
                        strBuffer += *CurrentVal;
                    }
                }
            }
            //Finish unfinished potential scans
            if(!strBuffer.empty())
                InsertFromBuffer(strBuffer, FormulaIndex, ScanType);
            TrimFormula();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecFormula" /> class from StringCopy instead of reference.
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        MediumDecFormula(std::string ElemValue, bool BlankVar) : MediumDecFormula(ElemValue) {}

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecFormula" /> class.(fix for initializing without copying from a string value set)
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        MediumDecFormula(const char* strVal) : MediumDecFormula(std::string(strVal),true) {}
    };
}