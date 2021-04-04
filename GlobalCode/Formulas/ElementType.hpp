// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"

namespace BlazesRusCode
{
    /// <summary>
    /// Element Category Type for Formula Elements
    /// </summary>
    enum class DLL_API FormulaElementType :unsigned __int8
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
        OR,
        LN,
        LOGTEN,
        BaseNLog,
        BuildInVariable,
        IntNumber//Integer number(for derivative classes that use more than one storage type)
    };
}