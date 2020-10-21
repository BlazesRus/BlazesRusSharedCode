// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
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

#include <string>
#include <cmath>
#include "..\OtherFunctions\VariableConversionFunctions.h"

#include "boost/rational.hpp"
#include "MediumDec.hpp"

//Might represent imaginary numbers when DecimalHalf02 is negative(later)
//Bitwise based operation code likely mostly incorrect in calculations(not that is important for moment)
//Decimal with fraction operations might need fixed

//Preprocessor Switches
/*
AltDec_SkipDivisionModulusAccuracyChecks = Skip if(SRep % Value.IntValue) checks for accuracy loss for some operations
AltDec_SeparateMixedFractionWithTile = Separate mixed fraction with _ instead of space on OptimalString
*/
//#define AltDec_SkipDivisionModulusAccuracyChecks

namespace BlazesCodePt2//Separate namespace so can do better comparisons
{
    class AltDec;

    /// <summary>
    /// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
    /// Represents +- 2147483647.999999999 with 100% consistency of accuracy for most operations as long as don't get too small
    /// plus support for some fractal operations etc (Support for WholeNum + numerator/denominator representation)
    /// (12 bytes worth of Variable Storage inside class for each instance)
    /// </summary>
    class DLL_API AltDec : BlazesRusCode::MediumDec
    {
    public:
        /*
            /// <summary>
            /// Acts as denominator in when not zero (otherwise AltDec represents +- 2147483647.999999999)
            /// (might add alternative representations in negative values later)
            /// </summary>
            signed int DecimalHalf02;

            /// <summary>
            /// Initializes a new instance of the <see cref="AltDec"/> class.
            /// </summary>
            /// <param name="intVal">The int value.</param>
            /// <param name="decVal01">The decimal val01.</param>
            /// <param name="decVal02">The decimal val02.</param>
            AltDec(signed int intVal = 0, signed int decVal01 = 0, signed int decVal02 = 0)
            {
                IntValue = intVal;
                DecimalHalf01 = decVal01;
                DecimalHalf02 = decVal02;
            }

            /// <summary>
            /// Sets the value.
            /// </summary>
            /// <param name="Value">The value.</param>
            void SetVal(AltDec Value)
            {
                IntValue = Value.IntValue;
                DecimalHalf01 = Value.DecimalHalf01; DecimalHalf02 = Value.DecimalHalf02;
            }
        */
    };
}

namespace BlazesRusCode
{
    using AltDec = BlazesCodePt2::AltDec;
}