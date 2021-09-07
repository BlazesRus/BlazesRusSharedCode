// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"
#include "VariableFormula.hpp"

#include "..\AltNum\MediumDec.hpp"

namespace BlazesRusCode
{
    template<typename VarType, typename VarStoreType>
    class DLL_API BuiltinFormula : public VariableFormula<VarType>
    {
    public:

        /// <summary>
        /// Switches the operator into boolean value and erases old left+right side value.
        /// </summary>
        /// <param name="FormCopy">The form copy.</param>
        /// <param name="FormDRef[*CurrentVal]">The op value.</param>
        /// <param name="LeftIterator">The left iterator.</param>
        /// <param name="RightIterator">The right iterator.</param>
        /// <param name="Value">The value.</param>
        void SwitchOpToBoolVal(FormData& FormCopy, FormElement& OpVal, bool Value)
        {
            if (Value) { OpVal.ElementCat = FormulaElementType::trueVal; }
            else { OpVal.ElementCat = FormulaElementType::falseVal; }
        }

        /// <summary>
        /// Switches the operator into Value
        /// </summary>
        /// <param name="FormCopy">The formula data copy.</param>
        /// <param name="FormDRef[*CurrentVal]">The operator element value.</param>
        /// <param name="OpKey">The operator key.</param>
        /// <param name="RightIterator">The right value iterator.</param>
        /// <param name="RightIterator">The right value iterator.</param>
        /// <param name="Value">The value to turn operator into.</param>
        void SwitchOpToVal(FormData& FormCopy, FormElement& OpVal, int OpKey, VarType Value)
        {
            FormCopy.NumMap.insert_or_assign(OpKey, Value);
            OpVal.ElementCat = FormulaElementType::Num;
        }

        void EvaluateOperations(size_t FormIndex = 0)
        {
            FormData& FormDRef = Data.at(FormIndex);
            FormData::iterator segmentStart = FormDRef.begin();
            VarType valResult;

            bool TempBool;
            VarType leftValue;
            VarType rightValue;

            IntVector& OpOrderElement = FormDRef.OpOrderMap[0];
            FormData::iterator OpIterator;
            FormData::iterator LeftVal;
            FormData::iterator RightVal;
            VarType leftResult;
            VarType rightResult;
            FormulaElementType OpApplied;
            int OpTargetKey;
            int leftKey;

            //bool moreOperations = FormDRef.size() > 3;

            //Applying operations via C++ variation of order of operations
            //https://en.cppreference.com/w/cpp/language/operator_precedence
            for (int opIndex = 0; opIndex < 11; ++opIndex)
            {
                OpOrderElement = FormDRef.OpOrderMap[opIndex];
                if (OpOrderElement.empty())
                    continue;
                for (IntVector::iterator CurrentVal = OpOrderElement.begin(), LastVal = OpOrderElement.end(); CurrentVal != LastVal; ++CurrentVal)
                {
                    OpTargetKey = *CurrentVal;
                    OpIterator = FormDRef.find(OpTargetKey);
                    if (opIndex == 1)
                    {
#ifndef Blazes_DisableFormula_NegativeSwapping
                        if (OpIterator->second.ElementCat == FormulaElementType::Negative && OpIterator != segmentStart)//Special conditional to potentially swap negative with minus
                        {
                            LeftVal = OpIterator - 1;
                            switch (LeftVal->second.ElementCat)
                            {
                            case FormulaElementType::Variable:
                                continue; break;//Ignore non-set variables for this version
                            case FormulaElementType::Formula:
                            case FormulaElementType::Num:
                            case FormulaElementType::trueVal:
                            case FormulaElementType::falseVal://Swapping out Negative application to right side, instead to a left-right subtraction operation
                            {
                                FormDRef[*CurrentVal].ElementCat = FormulaElementType::Sub;
                                //Making sure move the operation in correct operation order
                                if (FormDRef.OpOrderMap[3].empty() || FormDRef.OpOrderMap[3].back() < OpTargetKey)//If higher position then last element, then just add to end
                                    FormDRef.OpOrderMap[3].push_back(OpTargetKey);
                                else
                                {//Keys with lower indexes are normally in front
                                    for (IntVector::iterator cVal = FormDRef.OpOrderMap[3].begin(), LastSubVal = FormDRef.OpOrderMap[3].end(); cVal != LastSubVal; ++cVal)
                                    {
                                        if (*cVal > OpTargetKey)
                                        {
                                            FormDRef.OpOrderMap[3].insert(cVal, OpTargetKey);
                                            break;
                                        }
                                    }
                                }
                                continue;
                            }
                            default:
                                leftKey = -1;
                            }
                        }
                        else
#endif
                            leftKey = -1;
                    }
                    else if (opIndex != 0 || (OpIterator->second.ElementCat != FormulaElementType::Sqrt && OpIterator->second.ElementCat != FormulaElementType::LN && OpIterator->second.ElementCat != FormulaElementType::LOGTEN))
                    {
                        LeftVal = OpIterator - 1;
                        leftKey = LeftVal->first;
                        switch (LeftVal->second.ElementCat)
                        {
                        case FormulaElementType::Variable:
                            continue; break;//Ignore non-set variables for this version
                        case FormulaElementType::Formula:
                        {
                            EvaluateOperations(LeftVal->second.Index);//Condense inner formula if can
                            FormData& targetSegmentRef = Data.at(LeftVal->second.Index);
                            if (targetSegmentRef.size() == 1)
                            {
                                FormData::iterator targetElem = targetSegmentRef.begin();
                                if (targetElem->second.ElementCat != FormulaElementType::Variable)
                                    leftValue = targetElem->second.ElementCat == FormulaElementType::trueVal ? VarType::One : (targetElem->second.ElementCat == FormulaElementType::falseVal ? VarType::Zero : targetSegmentRef.NumMap[targetElem->first]);
                                else
                                    continue;//Ignore operation with unknown variable value
                            }
                            else
                                continue;//Ignore if not condensed down to single value
                        }
                        break;
                        case FormulaElementType::Num:
                            leftValue = FormDRef.NumMap[leftKey]; break;
                        case FormulaElementType::trueVal:
                            leftValue = VarType::One;
                        case FormulaElementType::falseVal:
                            leftValue = VarType::Zero;
                        default:
                            continue; break;
                        }
                    }
                    else
                        leftKey = -1;
                    RightVal = OpIterator + 1;
                    switch (RightVal->second.ElementCat)
                    {
                    case FormulaElementType::Variable:
                        continue; break;//Ignore non-set variables for this version
                    case FormulaElementType::Formula:
                    {
                        FormData& targetSegmentRef = Data.at(RightVal->second.Index);
                        EvaluateOperations(RightVal->second.Index);//Condense inner formula if can
                        if (targetSegmentRef.size() == 1)
                        {
                            FormData::iterator targetElem = targetSegmentRef.begin();
                            if (targetElem->second.ElementCat != FormulaElementType::Variable)
                                rightValue = targetElem->second.ElementCat == FormulaElementType::trueVal ? VarType::One : (targetElem->second.ElementCat == FormulaElementType::falseVal ? VarType::Zero : targetSegmentRef.NumMap[targetElem->first]);
                            else
                                continue;//Ignore operation with unknown variable value
                        }
                        else
                            continue;//Ignore if not condensed down to single value
                    }
                    break;
                    case FormulaElementType::Num:
                        rightValue = FormDRef.NumMap[RightVal->first]; break;
                    case FormulaElementType::trueVal:
                        rightValue = VarType::One;
                    case FormulaElementType::falseVal:
                        rightValue = VarType::Zero;
                    default:
                        continue; break;
                    }
                    switch (opIndex)
                    {
                    default://placeholder code
                        break;
                    case 0:
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Pow:
                            leftValue = VarType::PowOp(leftValue, rightValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                            break;
                        case FormulaElementType::Sqrt:
                            rightValue = VarType::Sqrt(rightValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, rightValue);
                            break;
                        case FormulaElementType::NthRoot:
                            rightValue = VarType::NthRootV2(rightValue, (int)leftValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, rightValue);
                            break;
                        case FormulaElementType::LN:
                            rightValue = VarType::Ln(rightValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, rightValue);
                            break;
                        case FormulaElementType::LOGTEN:
                            rightValue = VarType::Log10(rightValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, rightValue);
                            break;
                        case FormulaElementType::BaseNLog:
                            rightValue = VarType::Log(rightValue, leftValue);
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, rightValue);
                            break;
                        default://placeholder code
                            break;
                        }
                        break;
                    case 1://Remove operator in this case and change right side value
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
                            else if (RightVal->second.ElementCat == FormulaElementType::Formula)
                            {
                                FormDRef.at(RightVal->first).ElementCat = rightValue == VarType::Zero ? FormulaElementType::trueVal : FormulaElementType::falseVal;
                            }
                            else//Assuming is number
                            {
                                if (rightValue == VarType::Zero)//Zero is false otherwise count as if it was true
                                    FormDRef.NumMap[RightVal->first] = VarType::One;//SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], true);
                                else
                                    FormDRef.NumMap[RightVal->first] = VarType::Zero;//SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], false);
                            }
                            break;
                        case FormulaElementType::Negative://Only applies to numbers or Formulas(for now)
                            if (RightVal->second.ElementCat == FormulaElementType::Formula)
                            {
                                rightValue.SwapNegativeStatus();
                                FormDRef.at(RightVal->first).ElementCat = FormulaElementType::Num;
                                FormDRef.NumMap.insert_or_assign(RightVal->first, rightValue);
                            }
                            else
                            {
                                rightValue.SwapNegativeStatus();//rightValue = -rightValue;
                                FormDRef.NumMap[RightVal->first] = rightValue;
                            }
                            break;
                        default://placeholder code
                            break;
                        }
                        FormDRef.erase(OpIterator);
                        break;
                    case 2:// 	Multiplication, division, and remainder
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Mult:
                            leftValue *= rightValue;
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                            break;
                        case FormulaElementType::Div:
                            leftValue /= rightValue;
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                            break;
                        case FormulaElementType::Rem:
                            leftValue %= rightValue;
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                            break;
                        default://placeholder code
                            break;
                        }
                        break;
                    case 3://Addition and subtraction
                        switch (OpIterator->second.ElementCat)
                        {
                        case FormulaElementType::Add:
                        {
                            leftValue += rightValue;
                            //SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                            FormDRef.NumMap.insert_or_assign(OpTargetKey, leftValue);
                            FormDRef[OpTargetKey].ElementCat = FormulaElementType::Num;
                            break;
                        }
                        case FormulaElementType::Sub:
                            leftValue -= rightValue;
                            SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
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
                        SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], TempBool);
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
                        SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], TempBool);
                        break;
                    case 6://&
                        leftValue = leftValue & rightValue;
                        SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                        break;
                    case 7://XOR
                        leftValue = leftValue ^ rightValue;
                        SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                        break;
                    case 8:// | Bitwise OR (inclusive or)
                        leftValue = leftValue ^ rightValue;
                        SwitchOpToVal(FormDRef, FormDRef[*CurrentVal], OpTargetKey, leftValue);
                        break;
                    case 9://&&
                        TempBool = leftValue && rightValue;
                        SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], TempBool);
                        break;
                    case 10:// || (Logical OR)
                        TempBool = leftValue || rightValue;
                        SwitchOpToBoolVal(FormDRef, FormDRef[*CurrentVal], TempBool);
                        break;
                    }
                    if (opIndex != 1)
                    {
                        int RightKey = RightVal->first;
                        if (leftKey != -1)
                        {
                            FormDRef.erase(leftKey);
                        }
                        FormDRef.erase(RightKey);
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
            VarType targetResult;
            FormData& FormDRef = Data.at(FormIndex);
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (CurrentVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                {
                    ReplaceVariablesWithRefValues(ElementValues, CurrentVal->second.Index);
                }
                else if (CurrentVal->second.ElementCat == FormulaElementType::Variable)//Swap Variable with values
                {
                    CurString = this->VariableStore.at(CurrentVal->first);
                    tsl::ordered_map<std::string, VarType&>::iterator KeyedElemVal = ElementValues.find(CurString);
                    if (KeyedElemVal != ElementValues.end())//Only attempt to replace variable if matching variable is found
                    {
                        FormDRef.at(CurrentVal->first).ElementCat = FormulaElementType::Num;
                        targetResult = KeyedElemVal.value();
                        FormDRef.NumMap.insert_or_assign(CurrentVal->first, targetResult);//ElementValues.at(CurString));
                    }
                }
            }
        }

        /// <summary>
        /// Simplifies and evaluates the formula and then returns the copy.
        /// </summary>
        /// <param name="ElementValues">The element values.</param>
        /// <returns>BlazesRusCode.BuiltinFormula</returns>
        BuiltinFormula EvaluateRefToSimplifiedForm(ReferenceMap ElementValues)
        {
            BuiltinFormula FormCopy = *this;//Duplicate values so can erase parts when calculating
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
            VarType targetResult;
            FormData& FormDRef = Data.at(FormIndex);
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (CurrentVal->second.ElementCat == FormulaElementType::Formula)//FormulaDetected
                {
                    ReplaceVariablesWithValues(ElementValues, CurrentVal->second.Index);
                }
                else if (CurrentVal->second.ElementCat == FormulaElementType::Variable)//Swap Variable with values
                {
                    CurString = this->VariableStore.at(CurrentVal->second.Index);
                    tsl::ordered_map<std::string, VarType>::iterator KeyedElemVal = ElementValues.find(CurString);
                    if (KeyedElemVal != ElementValues.end())//Only attempt to replace variable if matching variable is found
                    {
                        FormDRef.at(CurrentVal->first).ElementCat = FormulaElementType::Num;
                        targetResult = KeyedElemVal.value();
                        FormDRef.NumMap.insert_or_assign(CurrentVal->first, targetResult);//ElementValues.at(CurString));
                    }
                }
            }
        }

        /// <summary>
        /// Simplifies and evaluates the formula and then returns the copy.
        /// </summary>
        /// <param name="ElementValues">The element values.</param>
        /// <returns>BlazesRusCode.BuiltinFormula</returns>
        BuiltinFormula EvaluateToSimplifiedForm(ValueMap ElementValues)
        {
            BuiltinFormula FormCopy = *this;//Duplicate values so can erase parts when calculating
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
                    strBuffer += this->VariableStore.at(CurrentVal->second.Index);
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
                    strBuffer += "SqrtOf";
                    break;
                case FormulaElementType::NthRoot:
                    strBuffer += "thRootOf";
                    break;
                case FormulaElementType::LOGTEN:
                    strBuffer += "LogTen";
                    break;
                case FormulaElementType::LN:
                    strBuffer += "Ln";
                    break;
                case FormulaElementType::BaseNLog:
                    strBuffer += "thBaseLog";
                    break;
                case FormulaElementType::Rem:
                    strBuffer += "%";
                    break;
                case FormulaElementType::PostFixPlus:
                    strBuffer += VariableStore.at(CurrentVal->second.Index) + "++";
                    break;
                case FormulaElementType::PostFixMinus:
                    strBuffer += VariableStore.at(CurrentVal->second.Index) + "++";
                    break;
                case FormulaElementType::PrefixPlus:
                    strBuffer += "++" + VariableStore.at(CurrentVal->second.Index);
                    break;
                case FormulaElementType::PrefixMinus:
                    strBuffer += "--" + VariableStore.at(CurrentVal->second.Index);
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
            for (FormData::iterator CurrentVal = FormDRef.begin(), LastVal = FormDRef.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                switch (CurrentVal->second.ElementCat)
                {
                case FormulaElementType::Formula:
                    strBuffer += "(";
                    RecursivelyAddToString(strBuffer, CurrentVal->second.Index);
                    strBuffer += ")";
                    break;
                case FormulaElementType::Num:
                    strBuffer += FormDRef.NumMap.at(CurrentVal->first).ToString();
                    break;
                case FormulaElementType::Variable:

                    strBuffer += this->VariableStore.at(CurrentVal->second.Index);
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
                    strBuffer += "SqrtOf";
                    break;
                case FormulaElementType::NthRoot:
                    strBuffer += "thRootOf";
                    break;
                case FormulaElementType::LOGTEN:
                    strBuffer += "LogTen";
                    break;
                case FormulaElementType::LN:
                    strBuffer += "Ln";
                    break;
                case FormulaElementType::BaseNLog:
                    strBuffer += "thBaseLog";
                    break;
                case FormulaElementType::Rem:
                    strBuffer += "%";
                    break;
                case FormulaElementType::PostFixPlus:
                    strBuffer += VariableStore.at(CurrentVal->second.Index) + "++";
                    break;
                case FormulaElementType::PostFixMinus:
                    strBuffer += VariableStore.at(CurrentVal->second.Index) + "++";
                    break;
                case FormulaElementType::PrefixPlus:
                    strBuffer += "++" + VariableStore.at(CurrentVal->second.Index);
                    break;
                case FormulaElementType::PrefixMinus:
                    strBuffer += "--" + VariableStore.at(CurrentVal->second.Index);
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
        /// Initializes a new instance of the <see cref="BuiltinFormula" /> class.
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        BuiltinFormula(std::string& ElemValue)
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
            bool numberWasLast = false;//Variable,Numbers, and formulas before - sets it to treat it as minus instead of negative
            //size_t CurrentFormElement = 0;
            Data.push_back(FormData());//Initialize first (Formula) field
            //auto targetForm = at(0);
            for (std::string::iterator CurrentVal = ElemValue.begin(), LastVal = ElemValue.end(); CurrentVal != LastVal; ++CurrentVal)
            {
                if (*CurrentVal == '(')
                {
                    numberWasLast = false;
                    //if(ScanType==10){strBuffer = at(FormulaIndex).back()+strBuffer;at(FormulaIndex).back()=strBuffer;}
                    if (!strBuffer.empty()) { InsertFromBuffer(strBuffer, FormulaIndex, ScanType, numberWasLast); strBuffer.clear(); }
                    FormulaIndex = AddFormulaToBuffer(FormulaIndex); ScanType = 0;
                }
                else if (*CurrentVal == ')')
                {
                    InsertFromBuffer(strBuffer, FormulaIndex, ScanType, numberWasLast);
                    --FormulaIndex;
                    numberWasLast = true;
                }
                else if (ScanType == 0 || ScanType == 10)
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
                    //---Other operations here as well in case of auto-sending variable on whitespace
                    else if (*CurrentVal == '!')//Negative Operator only valid for in front of NonOperators
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Not); numberWasLast = false;
                    }
                    else if (*CurrentVal == '^')
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Pow); numberWasLast = false;
                    }
                    else if (*CurrentVal == '&')
                    {
                        strBuffer = '&'; ScanType = 1;
                    }
                    else if (*CurrentVal == '|')
                    {
                        strBuffer = '|'; ScanType = 1;
                    }
                    else if (*CurrentVal == '>')
                    {
                        strBuffer = '>'; ScanType = 1;
                    }
                    else if (*CurrentVal == '<')
                    {
                        strBuffer = '<'; ScanType = 1;
                    }
                    else if (*CurrentVal == '/')
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Div); numberWasLast = false;
                    }
                    else if (*CurrentVal == '*')
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Mult); numberWasLast = false;
                    }
                    else if (*CurrentVal == '^')//Power of function
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Pow); numberWasLast = false;
                    }
                    else if (*CurrentVal == '$')//Shorthand for XOR for now
                    {
                        Data.at(FormulaIndex).AddOp(FormulaElementType::XOR); numberWasLast = false;
                    }
                    //---End of extra mid-formula operations
                    else
                    {
                        if (VariableConversionFunctions::IsDigit(*CurrentVal))
                        {
                            ScanType = 4;
                            strBuffer = *CurrentVal;
                        }
                        else if (*CurrentVal != ' ' && *CurrentVal != '\t')//If not whitespace, register as potential variable
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
                            ScanType = 4;
                            if (numberWasLast)
                            {
                                Data.at(FormulaIndex).AddOp(FormulaElementType::Sub);
                                numberWasLast = false;
                                strBuffer = *CurrentVal;
                            }
                            else
                                strBuffer += *CurrentVal;
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
                        numberWasLast = false;
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
                        numberWasLast = false;
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
                        numberWasLast = false;
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
                        numberWasLast = false;
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
                {//Scanning either number or variable at this point
                    if (*CurrentVal == '+')//++ or +
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '+'; ScanType = 1;
                    }
                    else if (*CurrentVal == '-')//--, -, or (unlikely) negative number
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '-'; ScanType = 1;
                    }
                    else if (*CurrentVal == '!')//!=
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '!'; ScanType = 1;
                    }
                    else if (*CurrentVal == '&')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '&'; ScanType = 1;
                    }
                    else if (*CurrentVal == '|')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '|'; ScanType = 1;
                    }
                    else if (*CurrentVal == '=')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '='; ScanType = 1;
                    }
                    else if (*CurrentVal == '>')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '>'; ScanType = 1;
                    }
                    else if (*CurrentVal == '<')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        strBuffer = '<'; ScanType = 1;
                    }
                    else if (*CurrentVal == '/')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Div);
                    }
                    else if (*CurrentVal == '*')
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Mult);
                    }
                    else if (*CurrentVal == '^')//Power of function
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::Pow);
                    }
                    else if (*CurrentVal == '$')//Shorthand for XOR for now
                    {
                        InsertFromBufferV2(strBuffer, FormulaIndex, ScanType, numberWasLast);
                        Data.at(FormulaIndex).AddOp(FormulaElementType::XOR);
                    }
                    else if (*CurrentVal == ' ' || *CurrentVal == '\t')//Immediately send variable if encounter whitespace
                    {
                        InsertFromBuffer(strBuffer, FormulaIndex, ScanType, numberWasLast);
                    }
                    else
                    {
                        strBuffer += *CurrentVal;
                    }
                }
            }
            //Finish unfinished potential scans
            if (!strBuffer.empty())
                InsertFromBuffer(strBuffer, FormulaIndex, ScanType, numberWasLast);
            TrimFormula();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="BuiltinFormula" /> class from StringCopy instead of reference.
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        BuiltinFormula(std::string ElemValue, bool BlankVar) : BuiltinFormula(ElemValue) {}

        /// <summary>
        /// Initializes a new instance of the <see cref="BuiltinFormula" /> class.(fix for initializing without copying from a string value set)
        /// </summary>
        /// <param name="ElemValue">The elem value to read in order to create formula data.</param>
        BuiltinFormula(const char* strVal) : BuiltinFormula(std::string(strVal), true) {}
    };

    class TestFormVarStore
    {
    public:
        MediumDec x = MediumDec::Two;
    };

    class DLL_API MediumDecFormulaV2 : public BuiltinFormula<MediumDec, TestFormVarStore>
    {

    };
}