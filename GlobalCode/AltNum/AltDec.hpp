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
#include "..\VariableConversionFunctions\VariableConversionFunctions.h"

#include "boost/rational.hpp"

class AltDec;

//Might represent imaginary numbers when DecimalHalf02 is negative(later)
//Bitwise based operation code likely mostly incorrect in calculations(not that is important for moment)
//Decimal with fraction operations might need fixed

//Preprocessor Switches
/*
AltDec_SkipDivisionModulusAccuracyChecks = Skip if(SRep % Value.IntValue) checks for accuracy loss for some operations
AltDec_SeparateMixedFractionWithTile = Separate mixed fraction with _ instead of space on OptimalString
*/
#define AltDec_SkipDivisionModulusAccuracyChecks

/// <summary>
/// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
/// Represents +- 2147483647.999999999 with 100% consistency of accuracy for most operations as long as don't get too small
/// plus support for some fractal operations etc (Support for WholeNum + numerator/denominator representation)
/// (12 bytes worth of Variable Storage inside class for each instance)
/// </summary>
class DLL_API AltDec
{
private:
    /// <summary>
    /// The decimal overflow
    /// </summary>
    static signed int const DecimalOverflow = 1000000000;

    /// <summary>
    /// The decimal overflow
    /// </summary>
    static signed _int64 const DecimalOverflowX = 1000000000;

    /// <summary>
    /// long double (Extended precision double)
    /// </summary>
    using ldouble = long double;

    using ModChecker = VariableConversionFunctions::ModChecker;
public:
    /// <summary>
    /// Value when IntValue is at negative zero (when has decimal part)
    /// </summary>
    static signed int const NegativeZero = -2147483648;

    /// <summary>
    /// Stores whole half of number(Including positive/negative status)
    /// </summary>
    signed int IntValue;

    /// <summary>
    /// Stores decimal section info when DecimalHalf02 is zero
    /// (Also acts as numerator in when DecimalHalf01 is positive)
    /// </summary>
    signed int DecimalHalf01;

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

    /// <summary>
    /// Adjusts value to account for Negative Zero(No Negative Value checks)
    /// </summary>
    /// <param name="value">The value.</param>
    void IncreaseInt(int& value)
    {
        if (IntValue == NegativeZero) { IntValue = value - 1; }
        else if (DecimalHalf01 == 0) { IntValue += value; }
        else if (value > IntValue)//Adjust for negative zero
        {
            IntValue += value;
            if (IntValue == 0) { IntValue = NegativeZero; }
            else { ++IntValue; }
        }
        else { IntValue += value; }
    }

    /// <summary>
    /// Adjusts value to account for Negative Zero(No Negative Value checks)
    /// </summary>
    /// <param name="value">The value.</param>
    void ReduceInt(int& value)
    {
        if (IntValue == NegativeZero) { IntValue = value * -1; }
        else if (DecimalHalf01 == 0) { IntValue -= value; }
        else if (value > IntValue)//Adjust for negative zero
        {
            IntValue -= value;
            if (IntValue == -1) { IntValue = NegativeZero; }
            else { --IntValue; }
        }
        else { IntValue -= value; }
    }

    /// <summary>
    /// Increase value with account for Negative Zero
    /// </summary>
    /// <param name="value">The value.</param>
    void IncreaseIntVal(int value)
    {
        if (value < 0) { value *= -1; ReduceInt(value); }
        else { IncreaseInt(value); }
    }

    /// <summary>
    /// Decrease value with account for Negative Zero
    /// </summary>
    /// <param name="value">The value.</param>
    void DecreaseIntVal(int value)
    {
        if (value < 0) { value *= -1; IncreaseInt(value); }
        else { ReduceInt(value); }
    }

#pragma region ValueDefines
private:
    /// <summary>
    /// Returns the value at zero
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec ZeroValue()
    {
        AltDec NewSelf = AltDec();
        return NewSelf;
    }
    /// <summary>
    /// Returns the value at one
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec OneValue()
    {
        AltDec NewSelf = AltDec(1);
        return NewSelf;
    }

    /// <summary>
    /// Returns the value at one
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec TwoValue()
    {
        AltDec NewSelf = AltDec(2);
        return NewSelf;
    }

    /// <summary>
    /// Returns the value at negative one
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec NegativeOneValue()
    {
        AltDec NewSelf = AltDec(-1);
        return NewSelf;
    }

    /// <summary>
    /// Returns the value at 0.5
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec Point5Value()
    {
        AltDec NewSelf = AltDec(0, 500000000);
        return NewSelf;
    }

    static AltDec JustAboveZeroValue()
    {
        AltDec NewSelf = AltDec(0, 1);
        return NewSelf;
    }

    static AltDec OneMillionthValue()
    {
        AltDec NewSelf = AltDec(0, 1000);
        return NewSelf;
    }

    /// <summary>
    /// Returns PI(3.1415926535897932384626433) with tenth digit rounded up(3.141592655)
    /// (about 1.000000000448883 times actual value of PI with digits past 15th cut off)
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec PIValue()
    {
        AltDec NewSelf = AltDec(3, 141592655);
        return NewSelf;
    }

    /// <summary>
    /// Returns value of -2147483647.999999999
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec MinimumValue()
    {
        return AltDec(-2147483647, 999999999);
    }

    /// <summary>
    /// Returns value of 2147483647.999999999
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec MaximumValue()
    {
        return AltDec(2147483647, 999999999);
    }

    /// <summary>
    /// Euler's number
    /// Irrational number equal to about (1 + 1/n)^n
    /// (about 2.71828182845904523536028747135266249775724709369995)
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec EValue()
    {
        return AltDec(2, 718281828);
    }

    static AltDec LN10Value()
    {
        return AltDec(2, 302585093);
    }
public:
    /// <summary>
    /// Returns PI as a Fractional (about 1.000000084162156 times actual value of PI with digits past 15th cut off)
    /// (http://davidbau.com/archives/2010/03/14/the_mystery_of_355113.html)
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec PIFracValue()
    {
        AltDec NewSelf = AltDec(0, 1330631944, 423553267);
        return NewSelf;
    }

    static AltDec PI;

    /// <summary>
    /// Returns the value at zero
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec Zero;

    /// <summary>
    /// Returns the value at one
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec One;

    /// <summary>
    /// Returns the value at two
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec Two;

    /// <summary>
    /// Returns the value at 0.5
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec PointFive;

    /// <summary>
    /// Returns the value at digit more than zero
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec JustAboveZero;

    /// <summary>
    /// Returns the value at .000001000
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec OneMillionth;

    /// <summary>
    /// Returns the value at negative one
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec NegativeOne;

    /// <summary>
    /// Returns value of highest non-infinite/Special Decimal State Value that can store
    /// </summary>
    static AltDec Maximum;

    /// <summary>
    /// Returns value of lowest non-infinite/Special Decimal State Value that can store
    /// </summary>
    static AltDec Minimum;

    /// <summary>
    /// Euler's number
    /// Irrational number equal to about (1 + 1/n)^n
    /// (about 2.71828182845904523536028747135266249775724709369995)
    /// </summary>
    /// <returns>AltDec</returns>
    static AltDec E;

    /// <summary>
    /// 2.3025850929940456840179914546844
    /// (Based on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having)
    /// </summary>
    static AltDec LN10;

    ///// <summary>
    ///// 16 x 1 Matrix with Values at Zero
    ///// </summary>
    //static AltDec ZeroMatrix16[16] = { Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero };
#pragma endregion ValueDefines

#pragma region Fraction Balancing

    /// <summary>
    /// Normalizes to number.
    /// </summary>
    void NormalizeToNum()
    {
        if (AttemptToConvertToNum() == false)
        {//likely to lose very small amount of precision since failed lossless fraction to number conversion(digits are truncated past the 1 millionth place)
            boost::rational<int> Frac = boost::rational<int>(DecimalHalf01, DecimalHalf02);
            __int64 overFlowStore = DecimalOverflowX * Frac.numerator() / Frac.denominator();
            DecimalHalf01 = (int)overFlowStore; DecimalHalf02 = 0;
        }
    }

    static void NormalizeFractions(AltDec& self, AltDec& Value)
    {
        if (Value.DecimalHalf02 != self.DecimalHalf02)//Normalize Denominators
        {
            self.OptimizeFractional(); Value.OptimizeFractional();
            ModChecker ModCheck;
            if (self.DecimalHalf02 > Value.DecimalHalf02)
            {
                if (ModCheck.CalcIfZero(self.DecimalHalf02, Value.DecimalHalf02))
                {//  3/10 && 1/5 become 3/10 && 2/10
                    Value.DecimalHalf02 = self.DecimalHalf02;
                    Value.DecimalHalf01 *= ModCheck.divRes;
                }
                else
                {
                    self.DecimalHalf01 *= Value.DecimalHalf02; Value.DecimalHalf01 *= self.DecimalHalf02;
                    self.DecimalHalf02 *= Value.DecimalHalf02; Value.DecimalHalf02 = self.DecimalHalf02;
                }
            }
            else
            {
                if (ModCheck.CalcIfZero(Value.DecimalHalf02, self.DecimalHalf02))
                {
                    self.DecimalHalf02 = Value.DecimalHalf02;
                    self.DecimalHalf01 *= ModCheck.divRes;
                }
                else
                {
                    self.DecimalHalf01 *= Value.DecimalHalf02; Value.DecimalHalf01 *= self.DecimalHalf02;
                    self.DecimalHalf02 *= Value.DecimalHalf02; Value.DecimalHalf02 = self.DecimalHalf02;
                }
            }
        }
    }

    /// <summary>
    /// Optimizes the rational numbers.
    /// </summary>
    void OptimizeFractional()
    {
        boost::rational<int> Frac = boost::rational<int>(DecimalHalf01, DecimalHalf02);
        DecimalHalf01 = Frac.numerator(); DecimalHalf02 = Frac.denominator();
    }

    /// <summary>
    /// Attempts to convert to from non-radical to radical (Returns true on success)
    /// </summary>
    /// <returns>bool</returns>
    void ConvertToRadical()
    {
        if (DecimalHalf02 == 0)
        {//Adjust code as needed for auto-detection of radicals
            bool ManualDetected = true;//Manually convert from decimal to commonly used fractions (to skip modulus checks)
            switch (DecimalHalf01)
            {
            case 250000000: DecimalHalf02 = 4; DecimalHalf01 = 1;
                break;
            case 100000000: DecimalHalf02 = 10; DecimalHalf01 = 1;
                break;
            case 125000000: DecimalHalf02 = 8; DecimalHalf01 = 1;
                break;
            case 200000000: DecimalHalf02 = 5; DecimalHalf01 = 1;
                break;
            default: ManualDetected = false; break;
            }
            if (ManualDetected) { return; }
            ModChecker modCheck;
            if (modCheck.CalcIfZero(DecimalHalf01, 100000000))//is ?/10th
            {
                DecimalHalf02 = 10; DecimalHalf01 = modCheck.divRes;
            }
            else if (modCheck.CalcIfZero(DecimalHalf01, 250000000))//is ?/4th
            {
                DecimalHalf02 = 4; DecimalHalf01 = modCheck.divRes;
            }
            else if (modCheck.CalcIfZero(DecimalHalf01, 125000000))//is ?/8th
            {
                DecimalHalf02 = 8; DecimalHalf01 = modCheck.divRes;
            }
            else if (modCheck.CalcIfZero(DecimalOverflow, DecimalHalf01))//check if is radical equal to 1/?
            {
                DecimalHalf01 = 1;
                DecimalHalf02 = modCheck.divRes;
            }
            else
            {
                boost::rational<int> Frac = boost::rational<int>(DecimalHalf01, DecimalOverflow);
                DecimalHalf01 = Frac.numerator(); DecimalHalf02 = Frac.denominator();
            }
        }
    }

    /// <summary>
    /// Attempts to convert to from radical to number if avoids losing accuracy(Returns true on success)
    /// </summary>
    /// <returns>bool</returns>
    bool AttemptToConvertToNum()
    {
        if (DecimalHalf02 == 0) { return true; }
        //Manually convert from commonly used fraction to decimal (to skip modulus checks)
        bool ManualDetected = true;
        switch (DecimalHalf02)
        {
        case 2: DecimalHalf01 = 500000000;
            break;
        case 4: DecimalHalf01 *= 250000000;
            break;
        case 10: DecimalHalf01 *= 100000000;
            break;
        default: ManualDetected = false; break;
        }
        if (ManualDetected) { DecimalHalf02 = 0; return true; }
        ModChecker modCheck;
        if (modCheck.CalcIfZero(DecimalOverflow, DecimalHalf02))//check if can divide without losing precision
        {
            DecimalHalf01 *= modCheck.divRes;
            DecimalHalf02 = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    void CombinedWholeHalfIntoFraction()
    {
        if (IntValue < 0)
        {
            DecimalHalf01 += DecimalHalf02 * (IntValue * -1); IntValue = NegativeZero;
        }
        else
        {
            DecimalHalf01 += DecimalHalf02 * IntValue; IntValue = 0;
        }
    }

    /// <summary>
    /// Balances the fraction.
    /// </summary>
    void BalanceFraction()
    {
        ModChecker ModCheck;
        ModCheck.CalcMod(DecimalHalf01, DecimalHalf02);
        if (ModCheck.divRes > 0)//Try to keep numerator less than full whole number
        {
            DecimalHalf01 = ModCheck.C;//-= ModCheck.divRes * DecimalHalf02;
            if (IntValue < 0)
            {
                ReduceInt(ModCheck.divRes);
            }
            else
            {
                IncreaseInt(ModCheck.divRes);
            }
        }
        boost::rational<int> Frac = boost::rational<int>(DecimalHalf01, DecimalHalf02);//Normalizing fraction
        DecimalHalf01 = Frac.numerator(); DecimalHalf02 = Frac.denominator();
    }

    void BalanceFractionSumOverflow()
    {
        if (DecimalHalf01 > DecimalHalf02)
        {
            DecimalHalf01 -= DecimalHalf02;
            IntValue < 0 ? -- * this : ++ * this;
        }
        else if (DecimalHalf01 == DecimalHalf02)
        {
            DecimalHalf01 = 0; DecimalHalf02 = 0;
            if (IntValue == NegativeZero) { IntValue = -1; }
            else if (IntValue < 0) { --* this; }
            else { ++* this; }
        }
        else if (DecimalHalf01 < 0)//numerator below zero
        {
            DecimalHalf01 += DecimalHalf02;
            IntValue < 0 ? ++ * this : -- * this;
        }
        else //if (DecimalHalf01 == 0)
        {
            DecimalHalf01 = 0; DecimalHalf02 = 0;
            if (IntValue == NegativeZero) { IntValue = 0; }
        }
    }

#pragma endregion Fraction Balancing
    /// <summary>
    /// Swaps the negative status.
    /// </summary>
    void SwapNegativeStatus()
    {
        if (IntValue == NegativeZero)
        {
            IntValue = 0;
        }
        else if (IntValue == 0)
        {
            IntValue = NegativeZero;
        }
        else
        {
            IntValue *= -1;
        }
    }
#pragma region String Commands
    /// <summary>
    /// Reads the fractional string.(Reading either number format or Numerator/Denominator format)
    /// </summary>
    /// <param name="Value">The value.</param>
    void ReadFractionalString(std::string Value);

    /// <summary>
    /// Reads the string.
    /// </summary>
    /// <param name="Value">The value.</param>
    void ReadString(std::string Value);

    /// <summary>
    /// Gets the value from string.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    AltDec GetValueFromString(std::string Value);

    /// <summary>
    /// Converts the fractional string to number.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    AltDec ConvertFractionalStringToNum(std::string Value);

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class from string literal
    /// </summary>
    /// <param name="strVal">The value.</param>
    AltDec(const char* strVal)
    {
        std::string Value = strVal;
        if (Value == "PI")
        {
            this->SetVal(PI);
        }
        else if (Value == "E")
        {
            this->SetVal(E);
        }
        else
        {
            this->ReadFractionalString(Value);
        }
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class.
    /// </summary>
    /// <param name="Value">The value.</param>
    AltDec(std::string Value)
    {
        if (Value == "PI")
        {
            this->SetVal(PI);
        }
        else if (Value == "E")
        {
            this->SetVal(E);
        }
        else
        {
            this->ReadFractionalString(Value);
        }
    }

    /// <summary>
    /// Converts to string.
    /// </summary>
    /// <returns>std.string</returns>
    std::string ToString();

    /// <summary>
    /// Converts to string with digits filled in even when empty
    /// </summary>
    /// <returns>std.string</returns>
    std::string ToFullString();

    /// <summary>
    /// Converts to normal string of non-integer number or fractional if decimalhalf02 is not zero
    /// </summary>
    /// <returns>std.string</returns>
    std::string ToOptimalString();

    /// <summary>
    /// Implements the operator std::string operator.
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator std::string() { return ToString(); }

    ///// <summary>
    ///// += AltDec operation added to std::string
    ///// </summary>
    ///// <param name="targetString">The target string(left side).</param>
    ///// <param name="Value">The right side value</param>
    ///// <returns>string</returns>
    //friend std::string operator+=(std::string targetString, AltDec self) { return targetString + self.ToString(); }
#pragma endregion String Commands
#pragma region From Standard types to this type
    /// <summary>
    /// Sets the value.
    /// </summary>
    /// <param name="Value">The value.</param>
    void SetVal(float Value)
    {
        bool IsNegative = Value < 0.0f;
        if (IsNegative) { Value *= -1.0f; }
        //Cap value if too big on initialize (preventing overflow on conversion)
        if (Value >= 2147483648.0f)
        {
            IntValue = 2147483647;
            if (IsNegative)
            {
                IntValue *= -1;
            }
            DecimalHalf01 = 999999999;
        }
        else
        {
            signed __int64 WholeValue = (signed __int64)std::floor(Value);
            Value -= (float)WholeValue;
            IntValue = IsNegative ? WholeValue * -1 : WholeValue;
            DecimalHalf01 = (signed int)Value * 10000000000;
        }
        DecimalHalf02 = 0;
    }

    /// <summary>
    /// Sets the value.
    /// </summary>
    /// <param name="Value">The value.</param>
    void SetVal(double Value)
    {
        bool IsNegative = Value < 0.0;
        if (IsNegative) { Value *= -1.0; }
        //Cap value if too big on initialize (preventing overflow on conversion)
        if (Value >= 2147483648.0)
        {
            IntValue = 2147483647;
            if (IsNegative)
            {
                IntValue *= -1;
            }
            DecimalHalf01 = 999999999;
        }
        else
        {
            signed __int64 WholeValue = (signed __int64)std::floor(Value);
            Value -= (double)WholeValue;
            IntValue = IsNegative ? WholeValue * -1 : WholeValue;
            DecimalHalf01 = (signed int)Value * 10000000000;
        }
        DecimalHalf02 = 0;
    }

    /// <summary>
    /// Sets the value.
    /// </summary>
    /// <param name="Value">The value.</param>
    void SetVal(ldouble Value)
    {
        bool IsNegative = Value < 0.0L;
        if (IsNegative) { Value *= -1.0L; }
        //Cap value if too big on initialize (preventing overflow on conversion)
        if (Value >= 2147483648.0)
        {
            IntValue = 2147483647;
            if (IsNegative)
            {
                IntValue *= -1;
            }
            DecimalHalf01 = 999999999;
        }
        else
        {
            signed __int64 WholeValue = (signed __int64)std::floor(Value);
            Value -= (ldouble)WholeValue;
            IntValue = IsNegative ? WholeValue * -1 : WholeValue;
            DecimalHalf01 = (signed int)Value * 10000000000;
        }
        DecimalHalf02 = 0;
    }

    /// <summary>
    /// Sets the value(false equals zero; otherwise is true).
    /// </summary>
    /// <param name="Value">The value.</param>
    void SetVal(bool Value)
    {
        IntValue = Value==false ? 0 : 1;
        DecimalHalf01 = 0; DecimalHalf02 = 0;
    }

    /// <summary>
    /// Sets the value.
    /// </summary>
    /// <param name="Value">The value.</param>
    void SetVal(int Value)
    {
        IntValue = Value; DecimalHalf01 = 0; DecimalHalf02 = 0;
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class.
    /// </summary>
    /// <param name="Value">The value.</param>
    AltDec(float Value)
    {
        this->SetVal(Value);
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class.
    /// </summary>
    /// <param name="Value">The value.</param>
    AltDec(double Value)
    {
        this->SetVal(Value);
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class.
    /// </summary>
    /// <param name="Value">The value.</param>
    AltDec(ldouble Value)
    {
        this->SetVal(Value);
    }

    /// <summary>
    /// Initializes a new instance of the <see cref="AltDec"/> class.
    /// </summary>
    /// <param name="Value">The value.</param>
    AltDec(bool Value)
    {
        this->SetVal(Value);
    }
#pragma endregion From Standard types to this type
#pragma region From this type to Standard types
    /// <summary>
    /// AltDec to float explicit conversion
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator float()
    {
        NormalizeToNum();
        float Value;
        if (IntValue < 0)
        {
            Value = IntValue == NegativeZero ? 0.0f : (float)IntValue;
            if (DecimalHalf01 != 0) { Value -= ((float)DecimalHalf01 * 0.000000001f); }
        }
        else
        {
            Value = (float)IntValue;
            if (DecimalHalf01 != 0) { Value += ((float)DecimalHalf01 * 0.000000001f); }
        }
        return Value;
    }
    /// <summary>
    /// AltDec to double explicit conversion
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator double()
    {
        NormalizeToNum();
        double Value;
        if (IntValue < 0)
        {
            Value = IntValue == NegativeZero ? 0.0 : (double)IntValue;
            if (DecimalHalf01 != 0) { Value -= ((double)DecimalHalf01 * 0.000000001); }
        }
        else
        {
            Value = (double)IntValue;
            if (DecimalHalf01 != 0) { Value += ((double)DecimalHalf01 * 0.000000001); }
        }
        return Value;
    }

    /// <summary>
    /// AltDec to long double explicit conversion
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator ldouble()
    {
        NormalizeToNum();
        ldouble Value;
        if (IntValue < 0)
        {
            Value = IntValue == NegativeZero ? 0.0L : (ldouble)IntValue;
            if (DecimalHalf01 != 0) { Value -= ((ldouble)DecimalHalf01 * 0.000000001L); }
        }
        else
        {
            Value = (ldouble)IntValue;
            if (DecimalHalf01 != 0) { Value += ((ldouble)DecimalHalf01 * 0.000000001L); }
        }
        return Value;
    }

    /// <summary>
    /// AltDec to int explicit conversion
    /// </summary>
    /// <returns>The result of the operator.</returns>
    explicit operator int() { NormalizeToNum(); return IntValue; }

    explicit operator bool() { NormalizeToNum(); return IntValue == 1 ? true : false; }

    /// <summary>
    /// AltDec to integer type explicit conversion
    /// </summary>
    /// <returns>The result of the operator.</returns>
    template<typename IntType>
    explicit operator IntType() { NormalizeToNum(); return IntValue; }
#pragma endregion From this type to Standard types
#pragma region Comparison Operators
    /// <summary>
    /// Equal to Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>bool</returns>
    friend bool operator==(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        return (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01);
    }
    /// <summary>
    /// Not equal to Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>bool</returns>
    friend bool operator!=(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        return (self.IntValue != Value.IntValue || self.DecimalHalf01 != Value.DecimalHalf01);
    }
    /// <summary>
    /// Lesser than Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>bool</returns>
    friend bool operator<(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        bool SelfIsNegative = self.IntValue < 0;
        bool ValueIsNegative = Value.IntValue < 0;
        bool SelfIsWholeN = self.DecimalHalf01 == 0;
        bool ValueIsWholeN = Value.DecimalHalf01 == 0;
        if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
        if (ValueIsNegative && SelfIsNegative == false) { return false; }
        else if (ValueIsNegative == false && SelfIsNegative) { return true; }
        else
        {//Both are either positive or negative
            if (SelfIsNegative)
            {//Larger number = farther down into negative
                if (self.IntValue > Value.IntValue)
                {
                    return true;
                }
                else if (self.IntValue == Value.IntValue)
                {
                    return SelfIsWholeN && (ValueIsWholeN ? false : self.DecimalHalf01 > Value.DecimalHalf01);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (self.IntValue < Value.IntValue)
                {
                    return true;
                }
                else if (self.IntValue == Value.IntValue)
                {
                    return SelfIsWholeN && (ValueIsWholeN ? false : self.DecimalHalf01 < Value.DecimalHalf01);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    /// <summary>
    /// Lesser than or Equal to Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>bool</returns>
    friend bool operator<=(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return true; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValueIsNegative = Value.IntValue < 0;
            bool SelfIsWholeN = self.DecimalHalf01 == 0;
            bool ValueIsWholeN = Value.DecimalHalf01 == 0;
            if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            if (ValueIsNegative && SelfIsNegative == false) { return false; }
            else if (ValueIsNegative == false && SelfIsNegative) { return true; }
            else
            {//Both are either positive or negative
                if (SelfIsNegative)
                {//Larger number = farther down into negative
                    if (self.IntValue > Value.IntValue)
                    {
                        return true;
                    }
                    else if (self.IntValue == Value.IntValue)
                    {
                        return SelfIsWholeN && (ValueIsWholeN ? false : self.DecimalHalf01 > Value.DecimalHalf01);
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if (self.IntValue < Value.IntValue)
                    {
                        return true;
                    }
                    else if (self.IntValue == Value.IntValue)
                    {
                        return SelfIsWholeN && (ValueIsWholeN ? false : self.DecimalHalf01 < Value.DecimalHalf01);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    /// <summary>
    /// Greater than Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The right side value.</param>
    /// <returns>bool</returns>
    friend bool operator>(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return false; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValueIsNegative = Value.IntValue < 0;
            bool SelfIsWholeN = self.DecimalHalf01 == 0;
            bool ValueIsWholeN = Value.DecimalHalf01 == 0;
            if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            if (ValueIsNegative && SelfIsNegative == false) { return true; }
            else if (ValueIsNegative == false && SelfIsNegative) { return false; }
            else
            {//Both are either positive or negative
                if (SelfIsNegative)
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)
                    {
                        return true;
                    }
                    else
                    {
                        return self.DecimalHalf01 < Value.DecimalHalf01;
                    }
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                    {
                        return true;
                    }
                    else
                    {
                        return self.DecimalHalf01 > Value.DecimalHalf01;
                    }
                }
            }
        }
    }
    /// <summary>
    /// Greater than or Equal to Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>bool</returns>
    friend bool operator>=(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return true; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValueIsNegative = Value.IntValue < 0;
            bool SelfIsWholeN = self.DecimalHalf01 == 0;
            bool ValueIsWholeN = Value.DecimalHalf01 == 0;
            if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            if (ValueIsNegative && SelfIsNegative == false) { return true; }
            else if (ValueIsNegative == false && SelfIsNegative) { return false; }
            else
            {//Both are either positive or negative
                if (SelfIsNegative)
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)
                    {
                        return true;
                    }
                    else
                    {
                        return self.DecimalHalf01 < Value.DecimalHalf01;
                    }
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                    {
                        return true;
                    }
                    else
                    {
                        return self.DecimalHalf01 > Value.DecimalHalf01;
                    }
                }
            }
        }
    }
#pragma endregion Comparison Operators
#pragma region AltDec-To-AltDec Operators
protected:
    /// <summary>
    /// Addition Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec& AddOp(AltDec& self, AltDec& Value)
    {
        if (Value == Zero) { return self; }
        if (Value.DecimalHalf01 == 0) { self.IncreaseIntVal(Value.IntValue); }
        else if (self.DecimalHalf02 == 0)
        {
            self.IncreaseIntVal(Value.IntValue);
            if (Value.DecimalHalf02 == 0)//Normal Variable Operations
            {
                self.DecimalHalf01 += Value.DecimalHalf01;
                if (self.DecimalHalf01 < 0) { self.DecimalHalf01 += DecimalOverflow; --self; }
                else if (self.DecimalHalf01 >= DecimalOverflow) { self.DecimalHalf01 -= DecimalOverflow; ++self; }
            }
            else//Left is normal while right is fractional
            {
                if (self.DecimalHalf01 == 0)
                {
                    Value.OptimizeFractional();
                    self.DecimalHalf02 = Value.DecimalHalf02;
                    if (Value.IntValue < 0)
                    {
                        if (self.IntValue < 0)//-2.0 + (-1 2/3) = -3 2/3
                        {
                            self.DecimalHalf01 = Value.DecimalHalf01;
                        }
                        else//2.0 + (-1 2/3) = 0 1/3
                        {
                            --self;
                            self.DecimalHalf01 = Value.DecimalHalf02 - Value.DecimalHalf01;
                        }
                    }
                    else
                    {
                        if (self.IntValue < 0)//-2.0 + (1 2/3) = -0 1/3
                        {
                            --self;
                            self.DecimalHalf01 = Value.DecimalHalf02 - Value.DecimalHalf01;
                        }
                        else//2.0 + (1 2/3) = 3 2/3
                        {
                            self.DecimalHalf01 = Value.DecimalHalf01;
                        }
                    }
                }
                else
                {
                    self.ConvertToRadical();
                    AltDec::NormalizeFractions(self, Value);
                    if (Value.IntValue < 0)
                    {
                        self.DecimalHalf01 -= Value.DecimalHalf01;
                    }
                    else
                    {
                        self.DecimalHalf01 += Value.DecimalHalf01;
                    }
                    //if (self.DecimalHalf01 > self.DecimalHalf02)
                    //{
                    //    self.DecimalHalf01 -= self.DecimalHalf02;
                    //    self.IntValue<0?--self:++self;
                    //}
                    //else if (self.DecimalHalf01==self.DecimalHalf02)
                    //{
                    //    self.DecimalHalf01 = 0; self.DecimalHalf02 = 0;
                    //    if (self.IntValue == NegativeZero) { self.IntValue = -1; }
                    //    else if (self.IntValue < 0){ --self; }
                    //    else { ++self; }
                    //}
                    //else if(self.DecimalHalf01==0)
                    //{
                    //    self.DecimalHalf01 = 0; self.DecimalHalf02 = 0;
                    //    if (self.IntValue == NegativeZero) { self.IntValue == 0; }
                    //}
                    //else//numerator below zero
                    //{
                    //    self.DecimalHalf01 += self.DecimalHalf02;
                    //    self.IntValue < 0 ? ++self : --self;
                    //}
                    self.BalanceFractionSumOverflow();
                }
            }
        }
        else
        {
            self.IncreaseIntVal(Value.IntValue);
            if (Value.DecimalHalf02 == 0)//Right is normal but left is not
            {
                if (Value.DecimalHalf01 != 0)
                {
                    Value.ConvertToRadical();
                    AltDec::NormalizeFractions(self, Value);
                    if (Value.IntValue < 0)
                    {
                        self.DecimalHalf01 -= Value.DecimalHalf01;
                    }
                    else
                    {
                        self.DecimalHalf01 += Value.DecimalHalf01;
                    }
                    self.BalanceFractionSumOverflow();
                }
            }
            else//Both are Radicals
            {//"(-1 1/2) + (-1 1/3) = -2 5/6"
                AltDec::NormalizeFractions(self, Value);
                if (Value.IntValue < 0)
                {
                    self.DecimalHalf01 -= Value.DecimalHalf01;
                }
                else
                {
                    self.DecimalHalf01 += Value.DecimalHalf01;
                }
                self.BalanceFractionSumOverflow();
            }
        }
        return self;
    }

    /// <summary>
    /// Subtraction Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    static AltDec& SubOp(AltDec& self, AltDec& Value)
    {
        if (Value == Zero) { return self; }
        if (Value.DecimalHalf01 == 0) { self.DecreaseIntVal(Value.IntValue); }
        else if (self.DecimalHalf02 == 0)
        {
            self.DecreaseIntVal(Value.IntValue);
            if (Value.DecimalHalf02 == 0)//Normal Variable Operations
            {
                self.DecimalHalf01 -= Value.DecimalHalf01;
                if (self.DecimalHalf01 < 0) { self.DecimalHalf01 += DecimalOverflow; --self; }
                else if (self.DecimalHalf01 >= DecimalOverflow) { self.DecimalHalf01 -= DecimalOverflow; ++self; }
            }
            else//Left is normal while right is fractional
            {
                if (self.DecimalHalf01 == 0)
                {
                    Value.OptimizeFractional();
                    self.DecimalHalf02 = Value.DecimalHalf02;
                    if (Value.IntValue < 0)
                    {
                        if (self.IntValue < 0)
                        {//-2 - (-1 1/3) = 2/3; "-2.0 - (-1 2/3) = " = "-2.0 - (-1 2/3) = 1/3"
                            --self;
                            self.DecimalHalf01 = Value.DecimalHalf02 - Value.DecimalHalf01;
                        }
                        else
                        {//2.0 - (-1 2/3) = 3 2/3
                            self.DecimalHalf01 = Value.DecimalHalf01;
                        }
                    }
                    else
                    {
                        if (self.IntValue < 0)//-2.0 - (1 1/3) = -3 1/3
                        {
                            self.DecimalHalf01 = Value.DecimalHalf01;
                        }
                        else//2.0 - (1 1/3) = 0 2/3
                        {
                            --self;
                            self.DecimalHalf01 = Value.DecimalHalf02 - Value.DecimalHalf01;
                        }
                    }
                }
                else
                {
                    self.ConvertToRadical();
                    AltDec::NormalizeFractions(self, Value);
                    if (Value.IntValue < 0)
                    {
                        self.DecimalHalf01 += Value.DecimalHalf01;
                    }
                    else
                    {
                        self.DecimalHalf01 -= Value.DecimalHalf01;
                    }
                    self.BalanceFractionSumOverflow();
                }
            }
        }
        else
        {
            self.DecreaseIntVal(Value.IntValue);
            if (Value.DecimalHalf02 == 0)//Right is normal but left is not
            {
                if (Value.DecimalHalf01 != 0)
                {
                    Value.ConvertToRadical();
                    AltDec::NormalizeFractions(self, Value);
                    if (Value.IntValue < 0)
                    {
                        self.DecimalHalf01 += Value.DecimalHalf01;
                    }
                    else
                    {
                        self.DecimalHalf01 -= Value.DecimalHalf01;
                    }
                    self.BalanceFractionSumOverflow();
                }
            }
            else//Both are Radicals
            {
                AltDec::NormalizeFractions(self, Value);
                if (Value.IntValue < 0)
                {
                    self.DecimalHalf01 += Value.DecimalHalf01;
                }
                else
                {
                    self.DecimalHalf01 -= Value.DecimalHalf01;
                }
                self.BalanceFractionSumOverflow();
            }
        }
        return self;
    }

    /// <summary>
    /// Multiplication Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    static AltDec& MultiplicationOp(AltDec& self, AltDec& Value)
    {
        if (self == Zero || Value == Zero) { return AltDec::Zero; }
        if (self.DecimalHalf02 == 0)
        {
            if (Value.DecimalHalf02 == 0)//Normal Variable Operations
            {
                if (Value == Zero) { self.IntValue = 0; self.DecimalHalf01 = 0; self.DecimalHalf02 = 0; return self; }
                if (self == Zero)
                    return self;
                if (Value.IntValue < 0)
                {
                    if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                    else { Value.IntValue *= -1; }
                    self.SwapNegativeStatus();
                }
                if (self.DecimalHalf01 == 0)
                {
                    if (Value.DecimalHalf01 == 0)
                    {
                        self.IntValue *= Value.IntValue; return self;
                    }
                    else
                    {
                        Value = Value * self.IntValue;
                        return Value;
                    }
                }
                else
                {
                    bool SelfIsNegative = self.IntValue < 0;
                    if (SelfIsNegative)
                    {
                        if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                        else { self.IntValue *= -1; }
                    }
                    if (Value.DecimalHalf01 == 0)//Y is integer
                    {
                        __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                        SRep *= Value.IntValue;
                        if (SRep >= DecimalOverflowX)
                        {
                            __int64 OverflowVal = SRep / DecimalOverflowX;
                            SRep -= OverflowVal * DecimalOverflowX;
                            self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
                        else
                        {
                            self.IntValue = 0;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
                        return self;
                    }
                    else if (Value.IntValue == 0 && self.IntValue == 0)
                    {
                        __int64 Temp04 = (__int64)self.DecimalHalf01 * (__int64)Value.DecimalHalf01;
                        Temp04 /= DecimalOverflowX;
                        self.DecimalHalf01 = (signed int)Temp04;
                    }
                    else
                    {
                        //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                        __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                        SRep *= Value.IntValue;//SRep holds __int64 version of X.Y * Z
                        //X.Y *.V
                        __int64 Temp03 = (__int64)self.IntValue * Value.DecimalHalf01;//Temp03 holds __int64 version of X *.V
                        __int64 Temp04 = (__int64)self.DecimalHalf01 * (__int64)Value.DecimalHalf01;
                        Temp04 /= DecimalOverflow;
                        //Temp04 holds __int64 version of .Y * .V
                        __int64 IntegerRep = SRep + Temp03 + Temp04;
                        __int64 IntHalf = IntegerRep / DecimalOverflow;
                        IntegerRep -= IntHalf * (__int64)DecimalOverflow;
                        if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
                        else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                        self.DecimalHalf01 = (signed int)IntegerRep;
                    }
                }
                return self;
            }
            else//Left is normal while right is fractional
            {
                bool ValueIsNegative = Value.IntValue < 0;
                if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                bool ValueIsWholeN = Value.DecimalHalf01 == 0;
            }
        }
        else//Left is Radical
        {
            if (Value.DecimalHalf02 == 0)//Right is normal
            {
                if (Value.DecimalHalf01 == 0)
                {
                    self.DecimalHalf01 *= Value.IntValue;
                    if (self.IntValue != NegativeZero && self.IntValue != 0)
                        self.IntValue *= Value.IntValue;
                    return self;
                }
                else
                {
                    Value.ConvertToRadical();
                }
            }
            // (3/4) * (2/3) = 6/12 =0.5
            if (Value.IntValue != 0 && Value.IntValue != NegativeZero)
            {
                self.CombinedWholeHalfIntoFraction();
            }
            self.DecimalHalf01 *= Value.DecimalHalf01;
            self.DecimalHalf02 *= Value.DecimalHalf02;
            self.BalanceFraction();
        }
        return self;
    }

    /// <summary>
    /// Division Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    static AltDec& DivisionOp(AltDec& self, AltDec& Value)
    {
        if (Value == Zero) { throw "Target value can not be divided by zero"; }
        if (self == Zero) { return self; }
        if (Value.IntValue < 0)
        {
            if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            else { Value.IntValue *= -1; }
            self.SwapNegativeStatus();
        }
        if (self.DecimalHalf02 == 0)
        {
            if (Value.DecimalHalf02 == 0)//Normal Variable Operations
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool SelfIsWholeN = self.DecimalHalf01 == 0;
                bool ValueIsNegative = Value.IntValue < 0;
                bool ValueIsWholeN = Value.DecimalHalf01 == 0;
                if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                if (self.DecimalHalf01 == 0 && Value.DecimalHalf01 == 0)
                {
                    if (self.IntValue < 0) { self.IntValue *= -1; }
                    __int64 SRep = DecimalOverflowX * self.IntValue;
                    __int64 YRep = Value.IntValue;
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                    if (SRep % Value.IntValue == 0)//Check for possible loss of precision to decide between radical representation vs decimal format
                    {
                        SRep = Value.divRes;
#else
                        SRep /= Value.IntValue;
#endif
                        if (SRep >= DecimalOverflowX)
                        {
                            __int64 OverflowVal = SRep / DecimalOverflowX;
                            SRep -= DecimalOverflowX * OverflowVal;
                            self.IntValue = self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
                        else
                        {
                            self.IntValue = SelfIsNegative ? NegativeZero : 0;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                    }//For 2/3 save as 0+2/3 instead of 0.666666666
                    else
                    {
                        if (self.IntValue < 0)
                        {
                            self.DecimalHalf01 = self.IntValue * -1;
                            self.DecimalHalf02 = Value.IntValue;
                            self.IntValue = NegativeZero;
                        }
                        else
                        {
                            self.DecimalHalf01 = self.IntValue;
                            self.DecimalHalf02 = Value.IntValue;
                            self.IntValue = 0;
                        }
                    }
#endif
                }
                else if (Value.DecimalHalf01 == 0)//Y is integer
                {
                    //return self / Value.IntValue;
                    __int64 SRep;
                    if (self.IntValue == NegativeZero) { SRep = (__int64)self.DecimalHalf01 * -1; }
                    else if (self.IntValue < 0) { SRep = DecimalOverflowX * self.IntValue - self.DecimalHalf01; }
                    else { SRep = DecimalOverflowX * self.IntValue + self.DecimalHalf01; }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                    if (SRep % Value.IntValue == 0)//Check for possible loss of precision to decide between radical representation vs decimal format
                    {
                        SRep = Value.divRes;
#else
                        SRep /= Value.IntValue;
#endif
                        bool SelfIsNegative = SRep < 0;
                        if (SelfIsNegative) { SRep *= -1; }
                        if (SRep >= DecimalOverflowX)
                        {
                            __int64 OverflowVal = SRep / DecimalOverflowX;
                            SRep -= OverflowVal * DecimalOverflowX;
                            self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
                        else
                        {
                            self.IntValue = 0;
                            self.DecimalHalf01 = (signed int)SRep;
                        }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                    }//Need to convert 1.11 to 111/100 or 1 + 11/100
                    else//1.11 has SRep of 1110000000
                    {
                        self.ConvertToRadical();
                        if (self.IntValue == 0 || self.IntValue == NegativeZero)
                        {//Just need to increase denominator size if no IntValue to deal with
                            self.DecimalHalf02 *= Value.IntValue;
                        }
                        else
                        {
                            if (self.IntValue < 0)
                            {
                                self.DecimalHalf01 += self.DecimalHalf02 * self.IntValue * -1;
                            }
                            else
                            {
                                self.DecimalHalf01 += self.DecimalHalf02 * self.IntValue;
                            }
                            self.DecimalHalf02 *= Value.IntValue;
                            ModChecker ModCheck;
                            if (ModCheck.CalcIfZero(self.DecimalHalf01, self.DecimalHalf02))//Try to keep numerator less than full whole number
                            {
                                self.DecimalHalf01 -= ModCheck.divRes * self.DecimalHalf02;
                                self.IncreaseIntVal(ModCheck.divRes);
                            }
                        }
                        boost::rational<int> Frac = boost::rational<int>(self.DecimalHalf01, self.DecimalHalf02);//Normalizing fraction
                        self.DecimalHalf01 = Frac.numerator(); self.DecimalHalf02 = Frac.denominator();
                    }
#endif
                }
                else if (self.IntValue < 10 && Value.IntValue == 0)//Using self method would cause overflow of SRep if more in most cases
                {//self part seems to work unless Value.int is more than 0 for some reason
                    if (self.IntValue < 0) { self.IntValue *= -1; }
                    __int64 SRep = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                    SRep *= DecimalOverflowX;
                    __int64 VRep = (DecimalOverflowX * Value.IntValue) + Value.DecimalHalf01;
                    SRep /= VRep;
                    __int64 IntHalf = SRep / DecimalOverflowX;
                    SRep -= IntHalf * DecimalOverflowX;
                    self.IntValue = (signed int)IntHalf;
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else
                {
                    if (self.IntValue < 0) { self.IntValue *= -1; }
                    __int64 SRep = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                    __int64 VRep = (DecimalOverflowX * Value.IntValue) + Value.DecimalHalf01;
                    SRep /= VRep;
                    int IntResult = (signed int)SRep;
                    SRep = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                    __int64 Temp01 = (__int64)IntResult * VRep;
                    SRep -= Temp01;
                    SRep *= DecimalOverflowX;
                    SRep /= VRep;
                    self.IntValue = IntResult;
                    self.DecimalHalf01 = (signed int)SRep;
                }
                if (SelfIsNegative)
                {
                    if (self.IntValue == 0)
                    {
                        if (self.DecimalHalf01 == 0) { self.IntValue = NegativeZero; }
                    }
                    else { self.IntValue *= -1; }
                }
                return self;
            }
            else//Right side is radical
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                if(self.DecimalHalf01==0)
                {
                    if(Value.IntValue==0)//2 / (3/4)
                    {
                        self.IntValue = SelfIsNegative ? NegativeZero : 0;
                        self.DecimalHalf01 = Value.DecimalHalf02;
                        self.DecimalHalf02 = Value.DecimalHalf01;
                    }
                    else
                    {

                    }
                }
                else
                {
                    if (Value.IntValue == 0)
                    {

                    }
                    else
                    {

                    }
                }
            }
        }
        else
        {
            if (Value.DecimalHalf02 == 0)//Right Value is normal but left is Fractional
            {
                if (Value.DecimalHalf01 == 0)
                {
                    self = self / Value.IntValue; return self;
                }
                else
                {
                    Value.ConvertToRadical();
                }
            }
            // (2/3) / (1/2) = (4/3) ;
            if (Value.IntValue != 0 && Value.IntValue != NegativeZero)
            {
                self.CombinedWholeHalfIntoFraction();
            }
            self.DecimalHalf01 *= Value.DecimalHalf02;
            self.DecimalHalf02 *= Value.DecimalHalf01;
            self.BalanceFraction();
        }
        return self;
    }

    /// <summary>
    /// Remainder/Modulus Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>AltDec&</returns>
    static AltDec& RemOp(AltDec& self, AltDec& Value)
    {
        bool SelfIsWholeN = self.DecimalHalf01 == 0;
        bool ValueIsWholeN = Value.DecimalHalf01 == 0;
        if (Value.IntValue == 0 && ValueIsWholeN) { return AltDec::Zero; }//Return zero instead of N/A
        if (SelfIsWholeN && ValueIsWholeN)//WholeNumbers
        {
            self.IntValue %= Value.IntValue; return self;
        }
        else if (self.DecimalHalf02 == 0)
        {
            if (Value.DecimalHalf02 == 0)//Normal Variable Operations
            {
                if (ValueIsWholeN)
                {
                    self %= Value.IntValue; return self;
                }
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                __int64 SRep = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                __int64 VRep = (DecimalOverflowX * Value.IntValue) + Value.DecimalHalf01;
                SRep /= VRep;
                __int64 IntResult = SRep;
                SRep = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                SRep -= IntResult * VRep;
                __int64 IntHalf = SRep / DecimalOverflowX;
                SRep -= DecimalOverflowX * IntHalf;
                self.IntValue = IntHalf;
                self.DecimalHalf01 = SRep;
                if (SelfIsNegative)
                {
                    self = Value - self;
                    if (ValueIsNegative == false)
                    {
                        SelfIsNegative = false;
                    }
                }
                else
                {
                    if (ValueIsNegative)
                    {
                        self = Value - self;
                    }
                }
                if (SelfIsNegative)
                {
                    if (self.IntValue == 0)
                    {
                        if (self.DecimalHalf01 == 0) { self.IntValue = NegativeZero; }
                    }
                    else { self.IntValue *= -1; }
                }
                return self;
            }
            else//Left is Fractional
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value < 0;
                if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                int LeftSide = self.IntValue * self.DecimalHalf02;
                if (SelfIsNegative) { LeftSide -= self.DecimalHalf01; }
                else { LeftSide += self.DecimalHalf01; }
                __int64 LeftBuffer = (DecimalOverflowX * LeftSide) / self.DecimalHalf02;
                __int64 RightBuffer = (DecimalOverflowX * Value.IntValue) + Value.DecimalHalf01;
                if (Value.IntValue == 0 && ValueIsNegative) { RightBuffer *= -1; }
                LeftBuffer %= RightBuffer;
                __int64 WholeBuffer = LeftBuffer / DecimalOverflowX;
                if (LeftBuffer < 0)
                {
                    LeftBuffer += DecimalOverflowX * WholeBuffer; LeftBuffer *= -1;
                    self.IntValue = WholeBuffer == 0 ? NegativeZero : WholeBuffer;
                    self.DecimalHalf01 = LeftBuffer; self.DecimalHalf02 = 0;
                }
                else
                {
                    LeftBuffer -= DecimalOverflowX * WholeBuffer;
                    self.IntValue = WholeBuffer;
                    self.DecimalHalf01 = LeftBuffer; self.DecimalHalf02 = 0;
                }
            }
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValueIsNegative = Value < 0;
            if (self.IntValue == NegativeZero) { self.IntValue = 0; } if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            if (Value.DecimalHalf02 == 0)//Left is normal while right is fractional
            {
                int RightSide = Value.IntValue * Value.DecimalHalf02;
                if (ValueIsNegative) { RightSide -= Value.DecimalHalf01; }
                else { RightSide += Value.DecimalHalf01; }
                __int64 RightBuffer = (DecimalOverflowX * RightSide) / Value.DecimalHalf02;
                __int64 LeftBuffer = (DecimalOverflowX * self.IntValue) + self.DecimalHalf01;
                if (self.IntValue == 0 && SelfIsNegative) { LeftBuffer *= -1; }
                LeftBuffer %= RightBuffer;
                __int64 WholeBuffer = LeftBuffer / DecimalOverflowX;
                if (LeftBuffer < 0)
                {
                    LeftBuffer += WholeBuffer * DecimalOverflowX; LeftBuffer *= -1;
                    self.IntValue = WholeBuffer == 0 ? NegativeZero : WholeBuffer;
                    self.DecimalHalf01 = LeftBuffer;
                }
                else
                {
                    LeftBuffer -= WholeBuffer * DecimalOverflowX;
                    self.IntValue = WholeBuffer;
                    self.DecimalHalf01 = LeftBuffer;
                }
            }
            else//Both are Radicals
            {
                int FractionMult;
                if (Value.DecimalHalf02 != self.DecimalHalf02)//Normalize Denominators
                {
                    self.OptimizeFractional(); Value.OptimizeFractional();
                    if (self.DecimalHalf02 > Value.DecimalHalf02)
                    {
                        if (self.DecimalHalf02 % Value.DecimalHalf02 == 0)
                        {
                            FractionMult = self.DecimalHalf02 / Value.DecimalHalf02;
                            Value.DecimalHalf01 *= FractionMult; Value.DecimalHalf02 = self.DecimalHalf02;
                        }
                        else
                        {
                            FractionMult = self.DecimalHalf02 * Value.DecimalHalf02;
                            self.DecimalHalf02 = FractionMult; Value.DecimalHalf02 = FractionMult;
                            self.DecimalHalf01 *= Value.DecimalHalf01; Value.DecimalHalf01 *= self.DecimalHalf01;
                        }
                    }
                    else
                    {
                        if (self.DecimalHalf02 % Value.DecimalHalf02 == 0)
                        {
                            FractionMult = Value.DecimalHalf02 / self.DecimalHalf02;
                            self.DecimalHalf01 *= FractionMult; self.DecimalHalf02 = Value.DecimalHalf02;
                        }
                        else
                        {
                            FractionMult = self.DecimalHalf02 * Value.DecimalHalf02;
                            self.DecimalHalf02 = FractionMult; Value.DecimalHalf02 = FractionMult;
                            self.DecimalHalf01 *= Value.DecimalHalf01; Value.DecimalHalf01 *= self.DecimalHalf01;
                        }
                    }
                }
                int LeftSide = self.IntValue * self.DecimalHalf02;
                if (SelfIsNegative) { LeftSide -= self.DecimalHalf01; }
                else { LeftSide += self.DecimalHalf01; }
                int RightSide = Value.IntValue * Value.DecimalHalf02;
                if (ValueIsNegative) { RightSide -= Value.DecimalHalf01; }
                else { RightSide += Value.DecimalHalf01; }
                LeftSide %= RightSide;
                if (LeftSide == 0) { self = AltDec::Zero; }
                else
                {
                    if (LeftSide < 0)
                    {
                        LeftSide *= -1;
                        self = AltDec(NegativeZero, LeftSide, self.DecimalHalf02);
                        self.IntValue = NegativeZero;
                        self.DecimalHalf01 = LeftSide;
                    }
                    else
                    {
                        self.IntValue = 0;
                        self.DecimalHalf01 = LeftSide;
                    }
                }
            }
        }
        return self;
    }
public:
    /// <summary>
    /// Addition Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator+(AltDec self, AltDec Value)
    {
        return AddOp(self, Value);
    }

    /// <summary>
    /// += Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator+=(AltDec& self, AltDec Value)
    {
        return AddOp(self, Value);
    }

    /// <summary>
    /// += Operation Between MediumDecs(from pointer)
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator+=(AltDec* self, AltDec Value){ return AddOp(**self, Value); }

    /// <summary>
    /// Subtraction Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator-(AltDec self, AltDec Value)
    {
        return SubOp(self, Value);
    }

    /// <summary>
    /// -= Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator-=(AltDec& self, AltDec Value)
    {
        return SubOp(self, Value);
    }

    /// <summary>
    /// -= Operation Between MediumDecs(from pointer)
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec& operator-=(AltDec* self, AltDec Value){ return SubOp(**self, Value); }

    /// <summary>
    /// Multiplication Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator*(AltDec self, AltDec Value)
    {
        return MultiplicationOp(self, Value);
    }

    ///// <summary>
    ///// *= Operation Between AltDecs
    ///// </summary>
    ///// <param name="self">The self.</param>
    ///// <param name="Value">The value.</param>
    ///// <returns>AltDec</returns>
    friend AltDec& operator*=(AltDec& self, AltDec Value)
    {
        return MultiplicationOp(self, Value);
    }

    ///// <summary>
    ///// *= Operation Between MediumDecs (from pointer)
    ///// </summary>
    ///// <param name="self">The self.</param>
    ///// <param name="Value">The value.</param>
    ///// <returns>AltDec</returns>
    friend AltDec& operator*=(AltDec* self, AltDec Value){ return MultOp(**self, Value); }

    /// <summary>
    /// Division Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator/(AltDec self, AltDec Value)
    {
        return DivisionOp(self, Value);
    }

    /// <summary>
    /// /= Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec& operator/=(AltDec& self, AltDec Value)
    {
        return DivisionOp(self, Value);
    }

    /// <summary>
    /// /= Operation Between MediumDecs (from pointer)
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator/=(AltDec* self, AltDec Value){ return DivOp(**self, Value); }

    /// <summary>
    /// Remainder Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>AltDec</returns>
    friend AltDec operator%(AltDec self, AltDec Value)
    {
        return RemOp(self, Value);
    }

    /// <summary>
    /// %= Operation Between AltDecs
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    friend AltDec operator%=(AltDec& self, AltDec Value)
    {
        return RemOp(self, Value);
    }

    /// <summary>
    /// XOR Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>AltDec</returns>
    friend AltDec operator^(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.DecimalHalf01 == 0 && Value.DecimalHalf01 == 0)//Whole Numbers
        {
            self.IntValue ^= Value.IntValue; return self;
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value.IntValue < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 ^ Value.IntValue) * -1;
                self.DecimalHalf01 ^= Value.DecimalHalf01;
            }
            else
            {
                if (ValIsNegative && Value.IntValue == NegativeZero)
                {
                    self.IntValue = (self.IntValue ^ 0) * -1;
                    self.DecimalHalf01 ^= Value.DecimalHalf01;
                }
                else
                {
                    self.IntValue ^= Value.IntValue; self.DecimalHalf01 ^= Value.DecimalHalf01;
                }
            }
        }
        return self;
    }

    /// <summary>
    /// Bitwise Or Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>AltDec</returns>
    friend AltDec operator|(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.DecimalHalf01 == 0 && Value.DecimalHalf01 == 0)//Whole Numbers
        {
            self.IntValue |= Value.IntValue; return self;
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value.IntValue < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 | Value.IntValue) * -1;
                self.DecimalHalf01 |= Value.DecimalHalf01;
            }
            else
            {
                if (ValIsNegative && Value.IntValue == NegativeZero)
                {
                    self.IntValue = (self.IntValue & 0) * -1;
                    self.DecimalHalf01 |= Value.DecimalHalf01;
                }
                else
                {
                    self.IntValue |= Value.IntValue; self.DecimalHalf01 |= Value.DecimalHalf01;
                }
            }
        }
        return self;
    }
    /// <summary>
    /// Bitwise And Operation Between AltDecs
    /// </summary>
    /// <param name="self">The left side value</param>
    /// <param name="Value">The right side value</param>
    /// <returns>AltDec</returns>
    friend AltDec operator&(AltDec self, AltDec Value)
    {
        self.NormalizeToNum(); Value.NormalizeToNum();
        if (self.DecimalHalf01 == 0 && Value.DecimalHalf01 == 0)//Whole Numbers
        {
            self.IntValue &= Value.IntValue; return self;
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value.IntValue < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 & Value.IntValue) * -1;
                self.DecimalHalf01 &= Value.DecimalHalf01;
            }
            else
            {
                if (ValIsNegative && Value.IntValue == NegativeZero)
                {
                    self.IntValue = (self.IntValue & 0) * -1;
                    self.DecimalHalf01 &= Value.DecimalHalf01;
                }
                else
                {
                    self.IntValue &= Value.IntValue; self.DecimalHalf01 &= Value.DecimalHalf01;
                }
            }
        }
        return self;
    }

    /// <summary>
    /// Negative Unary Operator(Flips negative status)
    /// </summary>
    /// <param name="self">The self.</param>
    /// <returns>AltDec</returns>
    friend AltDec& operator-(AltDec& self)
    {
        self.SwapNegativeStatus(); return self;
    }

    /// <summary>
    /// ++AltDec Operator
    /// </summary>
    /// <returns>AltDec &</returns>
    AltDec& operator ++()
    {
        if (IntValue == NegativeZero) { IntValue = 0; }
        else if (DecimalHalf01 == 0) { ++IntValue; }
        else if (IntValue == -1) { IntValue = NegativeZero; }
        else { ++IntValue; }
        return *this;
    }

    /// <summary>
    /// ++AltDec Operator
    /// </summary>
    /// <returns>AltDec &</returns>
    AltDec& operator --()
    {
        if (IntValue == NegativeZero) { IntValue = -1; }
        else if (DecimalHalf01 == 0) { --IntValue; }
        else if (IntValue == 0) { IntValue = NegativeZero; }
        else { --IntValue; }
        return *this;
    }

    /// <summary>
    /// AltDec++ Operator
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec operator ++(int)
    {
        AltDec tmp(*this);
        ++* this;
        return tmp;
    }

    /// <summary>
    /// AltDec-- Operator
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec operator --(int)
    {
        AltDec tmp(*this);
        --* this;
        return tmp;
    }

    /// <summary>
    /// AltDec* Operator
    /// </summary>
    /// <returns>AltDec &</returns>
    AltDec& operator *()
    {
        return *this;
    }

#pragma endregion AltDec-To-AltDec Operators
#pragma region Other Comparison Operators
    friend bool operator==(AltDec self, float Value) { return self == (AltDec)Value; }
    friend bool operator!=(AltDec self, float Value) { return self != (AltDec)Value; }
    friend bool operator<(AltDec self, float Value) { return self < (AltDec)Value; }
    friend bool operator<=(AltDec self, float Value) { return self <= (AltDec)Value; }
    friend bool operator>(AltDec self, float Value) { return self > (AltDec)Value; }
    friend bool operator>=(AltDec self, float Value) { return self >= (AltDec)Value; }

    friend bool operator==(float Value, AltDec self) { return self == (AltDec)Value; }
    friend bool operator!=(float Value, AltDec self) { return self != (AltDec)Value; }
    friend bool operator<(float Value, AltDec self) { return (AltDec)Value < self; }
    friend bool operator<=(float Value, AltDec self) { return self > (AltDec)Value; }
    friend bool operator>(float Value, AltDec self) { return (AltDec)Value > self; }
    friend bool operator>=(float Value, AltDec self) { return self < (AltDec)Value; }

    friend bool operator==(AltDec self, double Value) { return self == (AltDec)Value; }
    friend bool operator!=(AltDec self, double Value) { return self != (AltDec)Value; }
    friend bool operator<(AltDec self, double Value) { return self < (AltDec)Value; }
    friend bool operator<=(AltDec self, double Value) { return self <= (AltDec)Value; }
    friend bool operator>(AltDec self, double Value) { return self > (AltDec)Value; }
    friend bool operator>=(AltDec self, double Value) { return self >= (AltDec)Value; }

    friend bool operator==(double Value, AltDec self) { return self == (AltDec)Value; }
    friend bool operator!=(double Value, AltDec self) { return self != (AltDec)Value; }
    friend bool operator<(double Value, AltDec self) { return (AltDec)Value < self; }
    friend bool operator<=(double Value, AltDec self) { return self > (AltDec)Value; }
    friend bool operator>(double Value, AltDec self) { return (AltDec)Value > self; }
    friend bool operator>=(double Value, AltDec self) { return self < (AltDec)Value; }

    //friend float operator+=(float targetVal, AltDec self) { return targetVal + (float)self; }
    //friend float operator-=(float targetVal, AltDec self) { return targetVal - (float)self; }
    //friend float operator*=(float targetVal, AltDec self) { return targetVal * (float)self; }
    //friend float operator/=(float targetVal, AltDec self) { return targetVal / (float)self; }

    //friend double operator+=(double targetVal, AltDec self) { return targetVal + (double)self; }
    //friend double operator-=(double targetVal, AltDec self) { return targetVal - (double)self; }
    //friend double operator*=(double targetVal, AltDec self) { return targetVal * (double)self; }
    //friend double operator/=(double targetVal, AltDec self) { return targetVal / (double)self; }

    //friend AltDec operator+=(AltDec self, ldouble Value) { return self + (AltDec)Value; }
    //friend AltDec operator-=(AltDec self, ldouble Value) { return self - (AltDec)Value; }
    //friend AltDec operator*=(AltDec self, ldouble Value) { return self * (AltDec)Value; }
    //friend AltDec operator/=(AltDec self, ldouble Value) { return self % (AltDec)Value; }
#pragma endregion Other Comparison Operators
#pragma region AltDec-To-Int Comparison Operators
    /// <summary>
    /// Equality Operation between <see cref="AltDec &"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator==(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        return (self.IntValue == Value && self.DecimalHalf01 == 0);
    }
    /// <summary>
    /// != Operation between <see cref="AltDec"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator!=(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.DecimalHalf01 > 0) { return true; }
        else if (self.IntValue == Value && self.DecimalHalf01 == 0) { return false; }
        else { return true; };
    }
    /// <summary>
    /// Lesser than Operation between <see cref="AltDec"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator<(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.IntValue < Value) { return true; }
        return false;
    }
    /// <summary>
    /// Lesser than or equal to operation between <see cref="AltDec"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator<=(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.IntValue == Value && self.DecimalHalf01 == 0) { return true; }
        else if (self.IntValue < Value) { return true; }
        return false;
    }
    /// <summary>
    /// Greater than operation between <see cref="AltDec"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator>(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.IntValue > Value) { return true; }
        else if (self.IntValue == Value && self.DecimalHalf01 != 0) { return true; }
    }
    /// <summary>
    /// Greater than or equal to operation between <see cref="AltDec"/> and Integer Type.
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>bool</returns>
    template<typename IntType>
    friend bool operator>=(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.IntValue == Value && self.DecimalHalf01 == 0) { return true; }
        else if (self.IntValue > Value) { return true; }
        else if (self.IntValue == Value && self.DecimalHalf01 != 0) { return true; }
        return false;
    }
#pragma endregion AltDec-To-Int Comparison Operators
#pragma region Other Operations
    friend AltDec operator+(AltDec self, float Value) { return self + (AltDec)Value; }
    friend AltDec operator-(AltDec self, float Value) { return self - (AltDec)Value; }
    friend AltDec operator*(AltDec self, float Value) { return self * (AltDec)Value; }
    friend AltDec operator/(AltDec self, float Value) { return self / (AltDec)Value; }
    friend AltDec operator%(AltDec self, float Value) { return self % (AltDec)Value; }
    friend AltDec operator^(AltDec self, float Value) { return self ^ (AltDec)Value; }
    friend AltDec operator|(AltDec self, float Value) { return self | (AltDec)Value; }
    friend AltDec operator&(AltDec self, float Value) { return self & (AltDec)Value; }

    friend AltDec operator+(float Value, AltDec self) { return (AltDec)Value + self; }
    friend AltDec operator-(float Value, AltDec self) { return (AltDec)Value - self; }
    friend AltDec operator*(float Value, AltDec self) { return (AltDec)Value * self; }
    friend AltDec operator/(float Value, AltDec self) { return (AltDec)Value / self; }
    friend AltDec operator%(float Value, AltDec self) { return (AltDec)Value % self; }
    friend AltDec operator^(float Value, AltDec self) { return (AltDec)Value ^ self; }
    friend AltDec operator|(float Value, AltDec self) { return (AltDec)Value | self; }
    friend AltDec operator&(float Value, AltDec self) { return (AltDec)Value & self; }

    friend AltDec operator+(AltDec self, double Value) { return self + (AltDec)Value; }
    friend AltDec operator-(AltDec self, double Value) { return self - (AltDec)Value; }
    friend AltDec operator*(AltDec self, double Value) { return self * (AltDec)Value; }
    friend AltDec operator/(AltDec self, double Value) { return self / (AltDec)Value; }
    friend AltDec operator%(AltDec self, double Value) { return self % (AltDec)Value; }
    friend AltDec operator^(AltDec self, double Value) { return self ^ (AltDec)Value; }
    friend AltDec operator|(AltDec self, double Value) { return self | (AltDec)Value; }
    friend AltDec operator&(AltDec self, double Value) { return self & (AltDec)Value; }

    friend AltDec operator+(double Value, AltDec self) { return (AltDec)Value + self; }
    friend AltDec operator-(double Value, AltDec self) { return (AltDec)Value - self; }
    friend AltDec operator*(double Value, AltDec self) { return (AltDec)Value * self; }
    friend AltDec operator/(double Value, AltDec self) { return (AltDec)Value / self; }
    friend AltDec operator%(double Value, AltDec self) { return (AltDec)Value % self; }
    friend AltDec operator^(double Value, AltDec self) { return (AltDec)Value ^ self; }
    friend AltDec operator|(double Value, AltDec self) { return (AltDec)Value | self; }
    friend AltDec operator&(double Value, AltDec self) { return (AltDec)Value & self; }

    friend AltDec operator+(AltDec self, ldouble Value) { return self + (AltDec)Value; }
    friend AltDec operator-(AltDec self, ldouble Value) { return self - (AltDec)Value; }
    friend AltDec operator*(AltDec self, ldouble Value) { return self * (AltDec)Value; }
    friend AltDec operator/(AltDec self, ldouble Value) { return self / (AltDec)Value; }
    friend AltDec operator%(AltDec self, ldouble Value) { return self % (AltDec)Value; }
    friend AltDec operator^(AltDec self, ldouble Value) { return self ^ (AltDec)Value; }
    friend AltDec operator|(AltDec self, ldouble Value) { return self | (AltDec)Value; }
    friend AltDec operator&(AltDec self, ldouble Value) { return self & (AltDec)Value; }

    friend AltDec operator+(ldouble Value, AltDec self) { return (AltDec)Value + self; }
    friend AltDec operator-(ldouble Value, AltDec self) { return (AltDec)Value - self; }
    friend AltDec operator*(ldouble Value, AltDec self) { return (AltDec)Value * self; }
    friend AltDec operator/(ldouble Value, AltDec self) { return (AltDec)Value / self; }
    friend AltDec operator%(ldouble Value, AltDec self) { return (AltDec)Value % self; }
    friend AltDec operator^(ldouble Value, AltDec self) { return (AltDec)Value ^ self; }
    friend AltDec operator|(ldouble Value, AltDec self) { return (AltDec)Value | self; }
    friend AltDec operator&(ldouble Value, AltDec self) { return (AltDec)Value & self; }

#pragma endregion Other Operations
#pragma region AltDec-To-Integer Operations
public:
    /// <summary>
    /// Addition Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& AddOp(AltDec& self, IntType& Value)
    {
        if(value==0){ return self; }
        else if(self.DecimalHalf01==0)
        {
            self.IntValue += value;
        }
        else if(self.IntValue==NegativeZero)
        {
            if(value==1)//-0.5 + 1
                self.IntValue = 0;
            else if(value<0)//-0.5 - 1
                self.IntValue = value;
            else//-0.5 + 2 = 1.5
                self.IntValue = value - 1;
        }
        else if(self.IntValue==0&&value<0)//0.5 - 1
        {
            self.IntValue = value - 1;
        }
        else if(self.IntValue<0)
        {
            int ReversedIntHalf = self.IntValue*-1;
            if(value>ReversedIntHalf)//-1.5+ 3
                self.IntValue += value -1;
            else if(value==ReversedIntHalf)
                self.IntValue = NegativeZero; //-1.5 + 1
            else
                self.IntValue += value;
        }
        else
        {
            if(value<0)
            {
                int ReversedValue = value*-1;
                int ValueAtNegativeZero = self.IntValue*-1 - 1;
                if(ReversedValue>self.IntValue)//5.5-7 = 1.5
                    self.IntValue  += value - 1;
                else if(value==ValueAtNegativeZero)
                    self.IntValue = NegativeZero;
                else
                    self.IntValue += value;
            }
            else
                self.IntValue += value;
        }
        return self;
    }

    /// <summary>
    /// Subtraction Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    static AltDec& SubOp(AltDec& self, IntType& Value)
    {
		if(Value==0){ return self; }
		else if(self.DecimalHalf01==0)
		{
			self.IntValue -= value;
		}
		if(self.IntValue==NegativeZero)
		{
			if(value==1)
				self.IntValue = 0;
			else if(value>0)
				self.IntValue = value - 1;
			else
				self.IntValue += value;
		}
		else if(self.IntValue<0)
		{
			if(Value<self.IntValue)//-4.5 - -5.5
				self.IntValue -= value + 1;
			else if(Value==self.IntValue)
				self.IntValue = NegativeZero; //-1.5 + 1 = -0.5
			else
				self.IntValue -= value;
		}
		else
		{
			//Value to apply to get to negative zero
			int ReversedAtZero = self.IntValue+1;
			if(Value>self.IntValue)//1.5-3 =-1.5
				self.IntValue -= Value; ++self.IntValue;
			else if(Value==ReversedAtZero)//1.5 - 2 = -0.5
				self.IntValue = NegativeZero;
			else
				self.IntValue -= Value;
		}
		return self;
    }

    /// <summary>
    /// Multiplication Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    static AltDec& MultiplicationOp(AltDec& self, IntType& Value)
    {
        if (Value < 0)
        {
            if (Value == NegativeZero) { Value = 0; }
            else { Value *= -1; }
            self.SwapNegativeStatus();
        }
        if (self == Zero) { return self; }
        if (self.DecimalHalf02 == 0)
        {
            if (self.DecimalHalf01 == 0)
            {
                self.IntValue *= Value;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                SRep *= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= OverflowVal * DecimalOverflowX;
                    self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else
                {
                    self.IntValue = SelfIsNegative ? NegativeZero:0;
                    self.DecimalHalf01 = (signed int)SRep;
                }
                return self;
            }
        }
        else//self is radical
        {
            self.CombinedWholeHalfIntoFraction();
            self.DecimalHalf01 *= Value;
            if (self.IntValue != 0 && self.IntValue != NegativeZero) { self.IntValue *= Value; }
            ModChecker ModCheck;
            if (ModCheck.CalcIfZero(self.DecimalHalf01, self.DecimalHalf02))//Try to keep numerator less than full whole number
            {
                self.DecimalHalf01 -= ModCheck.divRes * self.DecimalHalf02;
                self.IncreaseIntVal(ModCheck.divRes);
            }
        }
        return self;
    }

    /// <summary>
    /// Division Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& DivisionOp(AltDec& self, IntType& Value)
    {
        if (Value == 0) { throw "Target value can not be divided by zero"; }
        else if (self == Zero) { return self; }
        if (Value < 0)
        {
            if (Value == NegativeZero) { Value = 0; }
            else { Value *= -1; }
            self.SwapNegativeStatus();
        }
        if (self.DecimalHalf02 == 0)
        {
            if (self.DecimalHalf01 == 0)
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                if (SRep % Value == 0)//Check for possible loss of precision to decide between radical representation vs decimal format
                {
#endif
                    SRep /= Value;
                    if (SRep >= DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / DecimalOverflowX;
                        SRep -= OverflowVal * DecimalOverflowX;
                        self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = 0;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                }//For 2/3 save as 0+2/3 instead of 0.666666666
                else
                {
                    if (self.IntValue < 0)
                    {
                        self.DecimalHalf01 = self.IntValue * -1;
                        self.DecimalHalf02 = Value;
                        self.IntValue = NegativeZero;
                    }
                    else
                    {
                        self.DecimalHalf01 = self.IntValue;
                        self.DecimalHalf02 = Value;
                        self.IntValue = 0;
                    }
                    }
#endif
                }
            else
            {
                __int64 SRep;
                if (self.IntValue == NegativeZero) { SRep = (__int64)self.DecimalHalf01 * -1; }
                else if (self.IntValue < 0) { SRep = DecimalOverflowX * self.IntValue - self.DecimalHalf01; }
                else { SRep = DecimalOverflowX * self.IntValue + self.DecimalHalf01; }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                ModChecker ModCheck;
                if (ModCheck.CalcIfZero(SRep, Value))//Check for possible loss of precision to decide between radical representation vs decimal format
                {
#endif
                    bool SelfIsNegative = SRep < 0;
                    if (SelfIsNegative) { SRep *= -1; }
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                    SRep = ModCheck.ExDivRes;
#else
                    SRep /= Value;
#endif
                    if (SRep >= DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / DecimalOverflowX;
                        SRep -= DecimalOverflowX * OverflowVal;
                        self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = 0;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    return self;
#ifndef AltDec_SkipDivisionModulusAccuracyChecks
                }
                else
                {
                    self.ConvertToRadical();
                    if (self.IntValue == 0 || self.IntValue == NegativeZero)
                    {//Just need to increase denominator size if no IntValue to deal with
                        self.DecimalHalf02 *= Value;
                    }
                    else
                    {
                        self.CombinedWholeHalfIntoFraction();
                        self.DecimalHalf02 *= Value;
                        ModChecker ModCheck;
                        if (ModCheck.CalcIfZero(self.DecimalHalf01, self.DecimalHalf02))//Try to keep numerator less than full whole number
                        {
                            self.DecimalHalf01 -= ModCheck.divRes * self.DecimalHalf02;
                            self.IncreaseIntVal(ModCheck.divRes);
                        }
                    }
                    boost::rational<int> Frac = boost::rational<int>(self.DecimalHalf01, self.DecimalHalf02);//Normalizing fraction
                    self.DecimalHalf01 = Frac.numerator(); self.DecimalHalf02 = Frac.denominator();
                }
#endif
            }
            }
        else
        {
            if (self.IntValue == 0 || self.IntValue == NegativeZero)
            {//Just need to increase denominator size if no IntValue to deal with
                self.DecimalHalf02 *= Value;
            }
            else
            {
                self.CombinedWholeHalfIntoFraction();
                self.DecimalHalf02 *= Value;
                ModChecker ModCheck;
                if (ModCheck.CalcIfZero(self.DecimalHalf01, self.DecimalHalf02))//Try to keep numerator less than full whole number
                {
                    self.DecimalHalf01 -= ModCheck.divRes * self.DecimalHalf02;
                    self.IncreaseIntVal(ModCheck.divRes);
                }
            }
            boost::rational<int> Frac = boost::rational<int>(self.DecimalHalf01, self.DecimalHalf02);//Normalizing fraction
            self.DecimalHalf01 = Frac.numerator(); self.DecimalHalf02 = Frac.denominator();
        }
        return self;
    }

    /// <summary>
    /// Remainder/Modulus Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& RemOp(AltDec& self, IntType& Value)
    {
        if (self.DecimalHalf02 == 0)
        {
            if(self == Zero) { return self; }
            if (Value == 0){ self.IntValue=0; self.DecimalHalf01 = 0; self.DecimalHalf02 = 0; return self; }
            if (self.DecimalHalf01 == 0)
            {
                if (self.IntValue < 0)//https://www.quora.com/How-does-the-modulo-operation-work-with-negative-numbers-and-why
                {
                    self.IntValue %= Value;
                    self.IntValue = (signed int)(Value - self.IntValue);
                }
                else
                {
                    self.IntValue %= Value; return self;
                }
            }
            else//leftValue is non-whole number
            {
                if (Value < 0) { self.SwapNegativeStatus(); Value *= -1; }
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                SRep %= Value;
                __int64 VRep = DecimalOverflowX * Value;
                SRep /= VRep;
                __int64 IntResult = SRep;
                SRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalHalf01;
                SRep -= IntResult * VRep;
                __int64 IntHalf = SRep / DecimalOverflow;
                SRep -= IntHalf * (__int64)DecimalOverflow;
                if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
                else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                self.DecimalHalf01 = (signed int)SRep;
            }
            return self;
        }
        else//Left Side Value is a radical
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValueIsNegative = Value < 0;
            if (SelfIsNegative)
            {
                if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                else { self.IntValue *= -1; }
            }
            //if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
            int LeftSide = self.IntValue * self.DecimalHalf02;
            if (SelfIsNegative) { LeftSide -= self.DecimalHalf01; }
            else { LeftSide += self.DecimalHalf01; }
            int RightSide = Value * self.DecimalHalf02;
            LeftSide %= RightSide;
            if (LeftSide == 0) { self = AltDec::Zero; }
            else
            {
                if (LeftSide < 0)
                {
                    LeftSide *= -1;
                    self = AltDec(NegativeZero, LeftSide, self.DecimalHalf02);
                }
                else { self = AltDec(0, LeftSide, self.DecimalHalf02); }
            }
        }
        return self;
    }

    /// <summary>
    /// Addition Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& UnsignedAddOp(AltDec& self, IntType& value)
    {
        if(value==0){ return self; }
        else if(self.DecimalHalf01==0)
        {
            self.IntValue += value;
        }
        else if(self.IntValue==NegativeZero)
        {
            if(value==1)//-0.5 + 1
                self.IntValue = 0;
            //else if(value<0)-0.5 - 1
            //	self.IntValue = value;
            else//-0.5 + 2 = 1.5
                self.IntValue = value - 1;
        }
        else if(self.IntValue<0)
        {
            int ReversedIntHalf = self.IntValue*-1;
            if(value>ReversedIntHalf)//-1.5+ 3
                self.IntValue += value -1;
            else if(value==ReversedIntHalf)
                self.IntValue = NegativeZero; //-1.5 + 1
            else
                self.IntValue += value;
        }
        else
        {
            self.IntValue += value;
        }
        return self;
    }

    /// <summary>
    /// Subtraction Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    static AltDec& UnsignedSubOp(AltDec& self, IntType& value)
    {
        if(value==0){ return self; }
        else if(self.DecimalHalf01==0)
        {
            self.IntValue -= value;
        }
        else if(self.IntValue==NegativeZero)
        {
            if(value==1)
                self.IntValue = 0;
            else//if(value>0)
                self.IntValue = value - 1;
        }
        else if(self.IntValue<0)
        {
            self.IntValue -= value;
        }
        else
        {
            //value to apply to get to negative zero
            int ReversedAtZero = self.IntValue+1;
            if(value>self.IntValue)//1.5-3 =-1.5
                self.IntValue -= value - 1;
            else if(value==ReversedAtZero)//1.5 - 2 = -0.5
                self.IntValue = NegativeZero;
            else
                self.IntValue -= value;
        }
        return self;
    }

    /// <summary>
    /// Multiplication Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    static AltDec& UnsignedMultOp(AltDec& self, IntType& Value)
    {
        if (self == Zero) {return self;}
        else if (Value == 0) { self.IntValue = 0; self.DecimalHalf01 = 0; return self;}
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0)
        {
            self.IntValue *= Value;
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            if (SelfIsNegative)
            {
                if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                else { self.IntValue *= -1; }
            }
            __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
            SRep *= Value;
            if (SRep >= DecimalOverflowX)
            {
                __int64 OverflowVal = SRep / DecimalOverflowX;
                SRep -= OverflowVal * DecimalOverflowX;
                self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                self.DecimalHalf01 = (signed int)SRep;
            }
            else
            {
                self.IntValue = SelfIsNegative?NegativeZero:0;
                self.DecimalHalf01 = (signed int)SRep;
            }
        }
        return self;
    }

    /// <summary>
    /// Division Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& UnsignedDivOp(AltDec& self, IntType& Value)
    {
        if (Value == 0) { throw "Target value can not be divided by zero"; }
        else if (self == Zero) { return self; }
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0)
        {
            bool SelfIsNegative = self.IntValue < 0;
            if (SelfIsNegative)
                self.IntValue *= -1;
            __int64 SRep = DecimalOverflowX * self.IntValue;
            SRep /= Value;
            if (SRep >= DecimalOverflowX)
            {
                __int64 OverflowVal = SRep / DecimalOverflow;
                SRep -= OverflowVal * DecimalOverflow;
                self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                self.DecimalHalf01 = (signed int)SRep;
            }
            else
            {
                self.IntValue = SelfIsNegative?NegativeZero:0;
                self.DecimalHalf01 = (signed int)SRep;
            }
        }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            if (SelfIsNegative)
            {
                if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                else { self.IntValue *= -1; }
            }
            __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
            SRep /= Value;
            if (SRep >= DecimalOverflowX)
            {
                __int64 OverflowVal = SRep / DecimalOverflowX;
                SRep -= DecimalOverflowX * OverflowVal;
                self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                self.DecimalHalf01 = (signed int)SRep;
            }
            else
            {
                self.IntValue = 0;
                self.DecimalHalf01 = (signed int)SRep;
            }
        }
        return self;
    }
	
    /// <summary>
    /// Remainder/Modulus Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec&</returns>
    template<typename IntType>
    static AltDec& UnsignedRemOp(AltDec& self, IntType& Value)
    {
        if(self == AltDec::Zero) { return self; }
        if (Value == 0){ self.IntValue=0; self.DecimalHalf01 = 0; self.DecimalHalf02 = 0; return self; }
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0)
        {
            self.IntValue %= Value; return self;
        }
        else//leftValue is non-whole number
        {
            __int64 SRep;
            if (self.IntValue == NegativeZero) { SRep = (__int64)self.DecimalHalf01 * -1; }
            else if (self.IntValue < 0) { SRep = DecimalOverflowX * self.IntValue - self.DecimalHalf01; }
            else { SRep = DecimalOverflowX * self.IntValue + self.DecimalHalf01; }
            bool SelfIsNegative = SRep < 0;
            if (SelfIsNegative) { SRep *= -1; }
            SRep %= Value;
            __int64 VRep = DecimalOverflowX * Value;
            SRep /= VRep;
            __int64 IntResult = SRep;
            SRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalHalf01;
            SRep -= IntResult * VRep;
            __int64 IntHalf = SRep / DecimalOverflow;
            SRep -= IntHalf * (__int64)DecimalOverflow;
            if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
            else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
            self.DecimalHalf01 = (signed int)SRep;
        }
        return self;
    }

 //   template<typename IntType>
 //   static AltDec& SignedModulusOp(AltDec& self, IntType& Value)
 //   {
	//}
public:
    friend AltDec operator+(AltDec self, unsigned char Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-(AltDec self, unsigned char Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*(AltDec self, unsigned char Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/(AltDec self, unsigned char Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%(AltDec self, unsigned char Value){ return UnsignedRemOp(self, Value); }
	
    friend AltDec operator+=(AltDec& self, unsigned char Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-=(AltDec& self, unsigned char Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*=(AltDec& self, unsigned char Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/=(AltDec& self, unsigned char Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%=(AltDec& self, unsigned char Value){ return UnsignedRemOp(self, Value); }

    friend AltDec operator+(AltDec self, unsigned short Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-(AltDec self, unsigned short Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*(AltDec self, unsigned short Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/(AltDec self, unsigned short Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%(AltDec self, unsigned short Value){ return UnsignedRemOp(self, Value); }
	
    friend AltDec operator+=(AltDec& self, unsigned short Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-=(AltDec& self, unsigned short Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*=(AltDec& self, unsigned short Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/=(AltDec& self, unsigned short Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%=(AltDec& self, unsigned short Value){ return UnsignedRemOp(self, Value); }

    friend AltDec operator+(AltDec self, unsigned int Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-(AltDec self, unsigned int Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*(AltDec self, unsigned int Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/(AltDec self, unsigned int Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%(AltDec self, unsigned int Value){ return UnsignedRemOp(self, Value); }
	
    friend AltDec operator+=(AltDec& self, unsigned int Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-=(AltDec& self, unsigned int Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*=(AltDec& self, unsigned int Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/=(AltDec& self, unsigned int Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%=(AltDec& self, unsigned int Value){ return UnsignedRemOp(self, Value); }
	
    //friend AltDec operator+=(AltDec* self, unsigned int Value){ return UnsignedAddOp(**self, Value); }
	//friend AltDec operator-=(AltDec* self, unsigned int Value){ return UnsignedSubOp(**self, Value); }
    //friend AltDec operator*=(AltDec* self, unsigned int Value){ return UnsignedMultOp(**self, Value); }
	//friend AltDec operator/=(AltDec* self, unsigned int Value){ return UnsignedDivOp(**self, Value); }
    //friend AltDec operator%=(AltDec* self, unsigned int Value){ return UnsignedRemOp(**self, Value); }

    friend AltDec operator+(AltDec self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-(AltDec self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*(AltDec self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/(AltDec self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%(AltDec self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }
	
    friend AltDec operator+=(AltDec& self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
	friend AltDec operator-=(AltDec& self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
    friend AltDec operator*=(AltDec& self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
	friend AltDec operator/=(AltDec& self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
    friend AltDec operator%=(AltDec& self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }
    //friend AltDec operator+=(AltDec* self, unsigned __int64 Value){ return UnsignedAddOp(**self, Value); }
	//friend AltDec operator-=(AltDec* self, unsigned __int64 Value){ return UnsignedSubOp(**self, Value); }
    //friend AltDec operator*=(AltDec* self, unsigned __int64 Value){ return UnsignedMultOp(**self, Value); }
	//friend AltDec operator/=(AltDec* self, unsigned __int64 Value){ return UnsignedDivOp(**self, Value); }
    //friend AltDec operator%=(AltDec* self, unsigned __int64 Value){ return UnsignedRemOp(**self, Value); }

    /// <summary>
    /// Addition Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator+(AltDec self, IntType Value)
    {
        return AddOp(self, Value);
    }

    ///// <summary>
    ///// += Operation Between AltDec and Integer Value
    ///// </summary>
    ///// <param name="self">The self.</param>
    ///// <param name="Value">The value.</param>
    ///// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator+=(AltDec& self, IntType Value)
    {
        return AddOp(self, Value);
    }

    template<typename IntType>
    friend AltDec operator+=(AltDec* self, IntType Value){ return AddOp(**self, Value); }

    /// <summary>
    /// Subtraction Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator-(AltDec self, IntType Value)
    {
        return SubOp(self, Value);
    }

    /// <summary>
    /// -= Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator-=(AltDec& self, IntType Value)
    {
        return SubOp(self, Value);
    }

    template<typename IntType>
    friend AltDec operator-=(AltDec* self, IntType Value){ return SubOp(**self, Value); }

    /// <summary>
    /// Multiplication Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator*(AltDec self, IntType Value)
    {
        return MultiplicationOp(self, Value);
    }

    /// <summary>
    /// *= Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator*=(AltDec& self, IntType Value)
    {
        return MultiplicationOp(self, Value);
    }

    /// <summary>
    /// *= Operation Between AltDec and Integer Value (frompointer
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator*=(AltDec* self, IntType Value){ return MultOp(**self, Value); }

    /// <summary>
    /// Division Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator/(AltDec self, IntType Value)
    {
        return DivisionOp(self, Value);
    }

    /// <summary>
    /// /= Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator/=(AltDec& self, IntType Value)
    {
        return DivisionOp(self, Value);
    }

    template<typename IntType>
    friend AltDec operator/=(AltDec* self, IntType Value){ return DivOp(**self, Value); }

    /// <summary>
    /// Modulus Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator%(AltDec self, IntType Value)
    {
        return RemOp(self, Value);
    }

    /// <summary>
    /// %= Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator%=(AltDec& self, IntType Value)
    {
        return RemOp(self, Value);
    }

    template<typename IntType>
    friend AltDec operator%=(AltDec* self, IntType Value){ return RemOp(**self, Value); }

    /// <summary>
    /// Bitwise XOR Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator^(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0) { self.IntValue ^= Value; return self; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 & Value) * -1;
                self.DecimalHalf01 ^= Value;
            }
            else
            {
                self.IntValue ^= Value; self.DecimalHalf01 ^= Value;
            }
        }
        return self;
    }

    /// <summary>
    /// Bitwise Or Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator|(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0) { self.IntValue |= Value; return self; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 & Value) * -1;
                self.DecimalHalf01 |= Value;
            }
            else
            {
                self.IntValue |= Value; self.DecimalHalf01 |= Value;
            }
        }
        return self;
    }

    /// <summary>
    /// Bitwise And Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator&(AltDec self, IntType Value)
    {
        self.NormalizeToNum();
        if (self.DecimalHalf01 == 0) { self.IntValue &= Value; return self; }
        else
        {
            bool SelfIsNegative = self.IntValue < 0;
            bool ValIsNegative = Value < 0;
            if (SelfIsNegative && self.IntValue == NegativeZero)
            {
                self.IntValue = (0 & Value) * -1;
                self.DecimalHalf01 &= Value;
            }
            else
            {
                self.IntValue &= Value; self.DecimalHalf01 &= Value;
            }
        }
        return self;
    }
#pragma endregion AltDec-To-Integer Operations
#pragma region Integer-To-AltDec Operations
    /// <summary>
    /// Addition Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator+(IntType Value, AltDec self)
    {
        return AddOp(self, Value);
    }

    /// <summary>
    /// Subtraction Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator-(IntType Value, AltDec self)
    {
        AltDec Result = Value;
        return SubOp(Result, self);
    }

    /// <summary>
    /// Multiplication Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator*(IntType Value, AltDec self)
    {
        return MultiplicationOp(self, Value);
    }

    /// <summary>
    /// Division Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator/(IntType Value, AltDec self)
    {
        AltDec Result = Value;
        return DivisionOp(Result, self);
    }

    /// <summary>
    /// Remainder/Modulus Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator%(IntType Value, AltDec self)
    {
        AltDec Result = Value;
        return RemOp(Result, self);
    }

    /// <summary>
    /// Bitwise XOR Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator^(IntType Value, AltDec self)
    {
        return (AltDec)Value ^ self;
    }
    /// <summary>
    /// Bitwise Or Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator|(IntType Value, AltDec self)
    {
        return (AltDec)Value | self;
    }
    /// <summary>
    /// Bitwise And Operation Between AltDec and Integer Value
    /// </summary>
    /// <param name="self">The self.</param>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    template<typename IntType>
    friend AltDec operator&(IntType Value, AltDec self)
    {
        return (AltDec)Value & self;
    }
#pragma endregion Integer-To-AltDec Operations
#pragma region Math/Trigonomic Etc Functions
    /// <summary>
    /// Forces Number into non-negative
    /// </summary>
    /// <returns>AltDec&</returns>
    AltDec& Abs()
    {
        if (IntValue == NegativeZero) { IntValue = 0; }
        else if (IntValue < 0) { IntValue *= -1; }
        return *this;
    }
    /// <summary>
    /// Forces Number into non-negative
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec AbsCopy()
    {
        AltDec Copy = *this; return Copy.Abs();
    }
    /// <summary>
    /// Forces Number into non-negative
    /// </summary>
    /// <param name="Value">The target value to apply on.</param>
    /// <returns>AltDec</returns>
    static AltDec Abs(AltDec Value)
    {
        return Value.Abs();
    }
    /// <summary>
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <returns>AltDec&</returns>
    AltDec& Floor()
    {
        if (DecimalHalf02 != 0)
        {
        }
        else
        {
            if (DecimalHalf01 == 0)
            {
                return *this;
            }
            DecimalHalf01 = 0;
            if (IntValue == NegativeZero) { IntValue = -1; }
            else
            {
                --IntValue;
            }
        }
        return *this;
    }
    /// <summary>
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec FloorCopy()
    {
        AltDec Copy = *this; return Copy.Floor();
    }
    /// <summary>
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <param name="Value">The target value to apply on.</param>
    /// <returns>AltDec</returns>
    static AltDec Floor(AltDec Value)
    {
        return Value.Floor();
    }

    /// <summary>
    /// Returns floored value with all fractional digits after specified precision cut off.
    /// </summary>
    /// <param name="Value">The target value to apply on.</param>
    /// <param name="precision">The precision.</param>
    static AltDec Floor(AltDec Value, int precision)
    {
        switch (precision)
        {
        case 9: break;
        case 8: Value.DecimalHalf01 /= 10; Value.DecimalHalf01 *= 10; break;
        case 7: Value.DecimalHalf01 /= 100; Value.DecimalHalf01 *= 100; break;
        case 6: Value.DecimalHalf01 /= 1000; Value.DecimalHalf01 *= 1000; break;
        case 5: Value.DecimalHalf01 /= 10000; Value.DecimalHalf01 *= 10000; break;
        case 4: Value.DecimalHalf01 /= 100000; Value.DecimalHalf01 *= 100000; break;
        case 3: Value.DecimalHalf01 /= 1000000; Value.DecimalHalf01 *= 1000000; break;
        case 2: Value.DecimalHalf01 /= 10000000; Value.DecimalHalf01 *= 10000000; break;
        case 1: Value.DecimalHalf01 /= 100000000; Value.DecimalHalf01 *= 100000000; break;
        default: Value.DecimalHalf01 = 0; break;
        }
        if (Value.IntValue == NegativeZero && Value.DecimalHalf01 == 0) { Value.DecimalHalf01 = 0; }
        return Value;
    }

    /// <summary>
    /// Returns the smallest integer that is greater than or equal to Value (Rounds up the nearest integer).
    /// </summary>
    /// <returns>AltDec&</returns>
    AltDec& Ceil()
    {
        if (DecimalHalf02 != 0)
        {
        }
        else
        {
            if (DecimalHalf01 == 0)
            {
                return *this;
            }
            DecimalHalf01 = 0;
            if (IntValue == NegativeZero) { IntValue = 0; }
            else
            {
                ++IntValue;
            }
        }
        return *this;
    }
    /// <summary>
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec CeilCopy()
    {
        AltDec Copy = *this; return Copy.Ceil();
    }
    /// <summary>
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <param name="Value">The target value to apply on.</param>
    /// <returns>AltDec</returns>
    static AltDec Ceil(AltDec Value)
    {
        return Value.Ceil();
    }
    /// <summary>
    /// Cuts off the decimal point from number
    /// </summary>
    /// <returns>AltDec &</returns>
    AltDec& Trunc()
    {
        if (DecimalHalf02 != 0)
        {
            DecimalHalf01 -= DecimalHalf01 % DecimalHalf02;
            if (IntValue < 0)
            {
                if (IntValue == NegativeZero) { IntValue = DecimalHalf01 / DecimalHalf02; }
                else { DecreaseIntVal(DecimalHalf01 / DecimalHalf02); }
            }
            else
            {
                IncreaseIntVal(DecimalHalf01 / DecimalHalf02);
            }
            DecimalHalf01 = 0; DecimalHalf02 = 0;
        }
        else
        {
            DecimalHalf01 = 0;
            if (IntValue == NegativeZero) { IntValue = 0; }
        }
        return *this;
    }
    /// <summary>
    /// Cuts off the decimal point from number
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec TruncCopy()
    {
        AltDec Copy = *this; return Copy.Floor();
    }
    /// <summary>
    /// Cuts off the decimal point from number
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec Trunc(AltDec Value)
    {
        return Value.Trunc();
    }

public:
    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    template<typename ValueType>
    AltDec& PowOp(ValueType& expValue)
    {
        if (expValue == 1) { return &this; }//Return self
        else if (expValue == 0)
        {
            IntValue = 1; DecimalHalf01 = 0; DecimalHalf02 = 0;
        }
        else if (expValue < 0)//Negative Pow
        {
            if (DecimalHalf01 == 0 && IntValue == 10 && expValue >= -9)
            {
                IntValue = 0; DecimalHalf01 = DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1]; DecimalHalf02 = 0;//return AltDec(0, DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1]);
            }
            else
            {
                //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                expValue *= -1;
                AltDec self = *this;
                IntValue = 1; DecimalHalf01 = 0; DecimalHalf02 = 0;// Initialize result
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        this /= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self / self; // Change x to x^-1
                }
            }
        }
        else if (DecimalHalf01 == 0 && IntValue == 10)
        {
            IntValue = VariableConversionFunctions::PowerOfTens[expValue];
        }
        else
        {
            //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
            AltDec self = *this;
            IntValue = 1; DecimalHalf01 = 0; DecimalHalf02 = 0;// Initialize result
            while (expValue > 0)
            {
                // If expValue is odd, multiply self with result
                if (expValue % 2 == 1)
                    this *= self;
                // n must be even now
                expValue = expValue >> 1; // y = y/2
                self = self * self; // Change x to x^2
            }
        }
        return this;
    }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    AltDec& NthRootOp(AltDec& n, AltDec& Precision)
    {
        AltDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (AltDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / AltDec::Pow(x[1], n - 1)));
        }
        *this = x[0];
        return *this;
    }
    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    AltDec& NthRootOpV2(AltDec n, AltDec& Precision)
    {
        AltDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (AltDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / AltDec::Pow(x[1], n - 1)));
        }
        *this = x[0];
        return *this;
    }

    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    AltDec& PowOp(AltDec& expValue)
    {
        if (expValue.DecimalHalf01 == 0)
        {
            this->NormalizeToNum();
            return this->PowOp(expValue.IntValue);
        }
        else
        {
            if (DecimalHalf02 != 0)
                this->ConvertToRadical();
            /// Approximate version of Math.Pow(double self, double expValue) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
            /// and https://stackoverflow.com/questions/3606734/calculate-fractional-exponent-in-for-loop-without-power-function
            if (expValue.IntValue == 0)
            {
                AltDec NewSelf = Pow(*this, expValue.DecimalHalf01);
                return *this->NthRootOpV2(expValue.DecimalHalf02, JustAboveZero);
            }
            else if (expValue.IntValue == NegativeZero)
            {
                AltDec NewSelf = Pow(*this, expValue.DecimalHalf01 * -1);
                return *this->NthRootOpV2(expValue.DecimalHalf02, JustAboveZero);
            }
            else
            {
                AltDec NewSelf = Pow(*this, expValue.DecimalHalf01 + (expValue.IntValue * expValue.DecimalHalf02));
                return *this->NthRootOpV2(expValue.DecimalHalf02, AltDec::JustAboveZero);
            }
        }
        return *this;
    }
public:
    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    AltDec Pow(AltDec expValue)
    {
        return *this->PowOp(expValue);
    }

    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    template<typename ValueType>
    AltDec Pow(ValueType expValue)
    {
        if (expValue == 1) { return *this; }//Return self
        else if (expValue == 0) { return One; }
        else if (expValue < 0)//Negative Pow
        {
            if (DecimalHalf01 == 0 && IntValue == 10 && expValue >= -9)
            {
                return AltDec(0, DecimalOverflowX / VariableConversionFunctions::PowerOfTens[expValue * -1]);
            }
            else
            {
                ValueType NumberOfTimes = (expValue * -1);
                AltDec ValueMult = *this;
                AltDec self = One;
                for (ValueType Num = 0; Num < NumberOfTimes; Num++)
                {
                    self /= ValueMult;
                }
                return self;
            }
        }
        else
        {
            if (DecimalHalf01 == 0 && IntValue == 10)
            {
                return AltDec(VariableConversionFunctions::PowerOfTens[expValue]);
            }
            else if (DecimalHalf01 == 0)
            {//Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                AltDec res = One; // Initialize result
                AltDec self = *this;
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        res *= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
                return AltDec(res);
            }
            else// if(DecimalHalf02==0)
            {
                ValueType NumOfTimes = expValue - 1;
                AltDec ValueMult = *this;
                AltDec Result = *this;
                for (ValueType Num = 0; Num < NumOfTimes; Num++)
                {
                    Result *= ValueMult;
                }
                return Result;
            }
        }
    }

    template<typename ValueType>
    static AltDec Pow(AltDec targetVal, ValueType exponent)
    {
        return targetVal.Pow(exponent);
    }

    /// <summary>
    /// Performs the natural logarithm of Value.
    /// </summary>
    AltDec& Log()
    {
        bool IsNegative = false;
        if (IntValue == NegativeZero) { IntValue = 0; IsNegative = true; }
        else if (IntValue < 0) { IntValue *= -1; IsNegative = true; }
        ldouble SelfAsDouble = (ldouble)IntValue;
        SelfAsDouble += DecimalHalf02 == 0 ? (ldouble)DecimalHalf01 * 0.000000001L : (ldouble)DecimalHalf01 / DecimalHalf02;
        if (IsNegative) { SelfAsDouble *= -1.0L; }
        SelfAsDouble = std::log(SelfAsDouble);
        *this = (AltDec)SelfAsDouble;
        return *this;
    }
    /// <summary>
    /// Returns the natural logarithm of Value.
    /// </summary>
    AltDec LogCopy()
    {//Switching to long double to use math library for now(loses small amount of precision in process)
        AltDec Copy = *this; return Copy.Log();
    }

    /// <summary>
    /// Perform square root on this instance.
    /// </summary>
    void Sqrt()
    {
        if (DecimalHalf01 == 0)
        {
            switch (IntValue)
            {
            case 1: IntValue = 1; break;
            case 4: IntValue = 2; break;
            case 9: IntValue = 3; break;
            case 16: IntValue = 4; break;
            case 25: IntValue = 5; break;
            case 36: IntValue = 6; break;
            case 49: IntValue = 7; break;
            case 64: IntValue = 8; break;
            case 81: IntValue = 9; break;
            case 100: IntValue = 10; break;
            case 121: IntValue = 11; break;
            case 144: IntValue = 12; break;
            case 196: IntValue = 13; break;
            case 225: IntValue = 15; break;
            case 256: IntValue = 16; break;
            case 289: IntValue = 17; break;
            case 324: IntValue = 18; break;
            case 361: IntValue = 19; break;
            case 400: IntValue = 20; break;
            default:
                *this = NthRefRoot(*this, 2, AltDec::JustAboveZero);
                break;
            }
        }
        else
        {
            *this = NthRefRoot(*this, 2, AltDec::JustAboveZero);
        }
    }

    /// <summary>
    /// Gets the square root of the specified value.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static AltDec Sqrt(AltDec Value)
    {
        if (Value.DecimalHalf01 == 0)
        {
            switch (Value.IntValue)
            {
            case 1: Value.IntValue = 1; break;
            case 4: Value.IntValue = 2; break;
            case 9: Value.IntValue = 3; break;
            case 16: Value.IntValue = 4; break;
            case 25: Value.IntValue = 5; break;
            case 36: Value.IntValue = 6; break;
            case 49: Value.IntValue = 7; break;
            case 64: Value.IntValue = 8; break;
            case 81: Value.IntValue = 9; break;
            case 100: Value.IntValue = 10; break;
            case 121: Value.IntValue = 11; break;
            case 144: Value.IntValue = 12; break;
            case 196: Value.IntValue = 13; break;
            case 225: Value.IntValue = 15; break;
            case 256: Value.IntValue = 16; break;
            case 289: Value.IntValue = 17; break;
            case 324: Value.IntValue = 18; break;
            case 361: Value.IntValue = 19; break;
            case 400: Value.IntValue = 20; break;
            default:
                Value = NthRefRoot(Value, 2, AltDec::JustAboveZero);
                break;
            }
        }
        else
        {
            Value = NthRefRoot(Value, 2, AltDec::JustAboveZero);
        }
        return Value;
    }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRoot(AltDec value, int n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRefRoot(AltDec& value, int n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRoot(int value, int n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRoot(AltDec value, AltDec n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRefRoot(AltDec& value, AltDec n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static AltDec NthRoot(int value, AltDec n, AltDec Precision);

    /// <summary>
    /// Get the (n)th Root with OneMillionth precision level
    /// </summary>
    /// <param name="nValue">The n value.</param>
    /// <returns>AltDec</returns>
    AltDec NthRoot(int nValue);

    AltDec& Exp()
    {
        bool IsNegative = false;
        if (IntValue == NegativeZero) { IntValue = 0; IsNegative = true; }
        else if (IntValue < 0) { IntValue *= -1; IsNegative = true; }
        ldouble SelfAsDouble = (ldouble)IntValue;
        SelfAsDouble += DecimalHalf02 == 0 ? (ldouble)DecimalHalf01 * 0.000000001L : (ldouble)DecimalHalf01 / DecimalHalf02;
        if (IsNegative) { SelfAsDouble *= -1.0L; }
        SelfAsDouble = std::exp(SelfAsDouble);
        *this = (AltDec)SelfAsDouble;
        return *this;
    }
    /// <summary>
    /// Returns the base-e exponential function of Value, which is e raised to the power Value: e^Value.
    /// </summary>
    /// <returns>AltDec</returns>
    AltDec ExpCopy()
    {
        AltDec Copy = *this; return Copy.Exp();
    }

    /// <summary>
    /// Get Sin from Value of angle.
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec SinFromAngle(AltDec Value)
    {
        Value.NormalizeToNum();
        if (Value.IntValue < 0)
        {
            if (Value.IntValue == NegativeZero)
            {
                Value.IntValue = 359; Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01;
            }
            else
            {
                Value.IntValue *= -1;
                Value.IntValue %= 360;
                Value.IntValue = 360 - Value.IntValue;
                if (Value.DecimalHalf01 != 0) { Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01; }
            }
        }
        else
        {
            Value.IntValue %= 360;
        }
        if (Value == Zero) { return AltDec::Zero; }
        else if (Value.IntValue == 30 && Value.DecimalHalf01 == 0)
        {
            return PointFive;
        }
        else if (Value.IntValue == 90 && Value.DecimalHalf01 == 0)
        {
            return One;
        }
        else if (Value.IntValue == 180 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Zero;
        }
        else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
        {
            return NegativeOne;
        }
        else
        {
            AltDec NewValue = Zero;
            //Angle as Radian
            AltDec Radius = PI * Value / 180;
            for (int i = 0; i < 7; ++i)
            { // That's Taylor series!!
                NewValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Radius, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            return NewValue;
        }
    }

    /// <summary>
    /// Get Cos() from Value of Angle
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static AltDec CosFromAngle(AltDec Value)
    {
        Value.NormalizeToNum();
        if (Value.IntValue < 0)
        {
            if (Value.IntValue == NegativeZero)
            {
                Value.IntValue = 359; Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01;
            }
            else
            {
                Value.IntValue *= -1;
                Value.IntValue %= 360;
                Value.IntValue = 360 - Value.IntValue;
                if (Value.DecimalHalf01 != 0) { Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01; }
            }
        }
        else
        {
            Value.IntValue %= 360;
        }
        if (Value == Zero) { return One; }
        else if (Value.IntValue == 90 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Zero;
        }
        else if (Value.IntValue == 180 && Value.DecimalHalf01 == 0)
        {
            return NegativeOne;
        }
        else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Zero;
        }
        else
        {
            AltDec NewValue = Zero;
            //Angle as Radian
            AltDec Radius = PI * Value / 180;
            for (int i = 0; i < 7; ++i)
            { // That's also Taylor series!!
                NewValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Radius, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return NewValue;
        }
    }

    /// <summary>
    /// Get Sin from Value in Radians
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value in Radians.</param>
    /// <returns>AltDec</returns>
    static AltDec Sin(AltDec Value)
    {
        AltDec SinValue = Zero;
        for (int i = 0; i < 7; ++i)
        {
            SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
        }
        return SinValue;
    }

    /// <summary>
    /// Get Sin from Value in Radians
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value in Radians.</param>
    /// <returns>AltDec</returns>
    static AltDec Cos(AltDec Value)
    {
        AltDec CosValue = Zero;
        for (int i = 0; i < 7; ++i)
        {
            CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
        }
        return CosValue;
    }

    /// <summary>
    /// Get Tan from Value in Radians
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value in Radians.</param>
    /// <returns>AltDec</returns>
    static AltDec Tan(AltDec Value)
    {
        AltDec SinValue = Zero;
        AltDec CosValue = Zero;
        for (int i = 0; i < 7; ++i)
        {
            SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
        }
        for (int i = 0; i < 7; ++i)
        {
            CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
        }
        return SinValue / CosValue;
    }

    /// <summary>
    /// Get Tangent from Value in Degrees (SlopeInPercent:http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec TanFromAngle(AltDec Value)
    {
        Value.NormalizeToNum();
        if (Value.IntValue < 0)
        {
            if (Value.IntValue == NegativeZero)
            {
                Value.IntValue = 359; Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01;
            }
            else
            {
                Value.IntValue *= -1;
                Value.IntValue %= 360;
                Value.IntValue = 360 - Value.IntValue;
                if (Value.DecimalHalf01 != 0) { Value.DecimalHalf01 = DecimalOverflow - Value.DecimalHalf01; }
            }
        }
        else
        {
            Value.IntValue %= 360;
        }
        if (Value == Zero) { return AltDec::Zero; }
        else if (Value.IntValue == 90 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Maximum;//Positive Infinity
        }
        else if (Value.IntValue == 180 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Zero;
        }
        else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
        {
            return AltDec::Minimum;//Negative Infinity
        }
        else
        {
            return Tan(PI * Value / 180);
        }
    }

    /// <summary>
    /// Gets Inverse Tangent from Value in Radians
    /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec ATan(AltDec Value)
    {
        AltDec SinValue = Zero;
        AltDec CosValue = Zero;
        //Angle as Radian
        for (int i = 0; i < 7; ++i)
        { // That's Taylor series!!
            SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
        }
        for (int i = 0; i < 7; ++i)
        { // That's also Taylor series!!
            CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
        }
        return CosValue / SinValue;
    }

    /// <summary>
    /// atan2 calculation with self normalization
    /// Application: Used when one wants to compute the 4-quadrant arctangent of a complex number (or any number with x-y coordinates) with a self-normalizing function.
    /// Example Applications: digital FM demodulation, phase angle computations
    /// Code from http://dspguru.com/dsp/tricks/fixed-point-atan2-with-self-normalization/ with some slight edit to get working
    /// </summary>
    /// <param name="y">The y.</param>
    /// <param name="X">The x.</param>
    /// <returns>AltDec</returns>
    static AltDec ArcTan2(AltDec y, AltDec x)
    {
        AltDec coeff_1 = PI / 4;
        AltDec coeff_2 = 3 * coeff_1;
        AltDec abs_y = AltDec::Abs(y) + JustAboveZero;// kludge to prevent 0/0 condition
        AltDec r;
        AltDec angle;
        if (x >= 0)
        {
            r = (x - abs_y) / (x + abs_y);
            angle = coeff_1 - coeff_1 * r;
        }
        else
        {
            r = (x + abs_y) / (abs_y - x);
            angle = coeff_2 - coeff_1 * r;
        }
        if (y < 0)
            return -angle;// negate if in quad III or IV
        else
            return angle;
    }

    /// <summary>
    /// Rounds the specified value based on https://en.wikipedia.org/wiki/Rounding.
    /// </summary>
    /// <param name="value">The value.</param>
    /// <param name="precision">The precision.</param>
    /// <returns>AltDec</returns>
    static AltDec Round(AltDec value, int precision = 0)
    {
        if (value.DecimalHalf01 == 0) { return value; }
        if (precision == 0)//RoundToNearest
        {
            value.NormalizeToNum();
            bool IsNegative = value.IntValue < 0;
            if (value.DecimalHalf01 >= 500000000)
            {
                if (value == NegativeZero)
                {
                }
                else if (value < 0)
                {
                }
                else
                {
                }
            }
            else
            {
            }
            value.DecimalHalf01 = 0;
            return value;
        }
        else if (precision >= 9) { return value; }
        else
        {
            value.NormalizeToNum();
            bool IsNegative = value.IntValue < 0;
            int HalfPoint; int NonRoundedDivider;
            switch (precision)
            {
            case 1: HalfPoint = 50000000; NonRoundedDivider = 100000000; break;
            case 2: HalfPoint = 5000000; NonRoundedDivider = 10000000; break;
            case 3: HalfPoint = 500000; NonRoundedDivider = 1000000; break;
            case 4: HalfPoint = 50000; NonRoundedDivider = 100000; break;
            case 5: HalfPoint = 5000; NonRoundedDivider = 10000; break;
            case 6: HalfPoint = 500; NonRoundedDivider = 1000; break;
            case 7: HalfPoint = 50; NonRoundedDivider = 100; break;
            default: HalfPoint = 5; NonRoundedDivider = 10; break;//precision:8
            }
            int NonRoundedPart = (value.DecimalHalf01 / NonRoundedDivider) * 10;
            int RoundSection = value.DecimalHalf01 - NonRoundedPart;
            if (RoundSection >= HalfPoint)
            {
                if (IsNegative)
                {
                }
                else
                {
                }
            }
            else
            {
                if (IsNegative)
                {
                }
                else
                {
                    return AltDec::Floor(value, precision);
                }
            }
        }
        return value;
    }

    /// <summary>
    /// Natural log of Value(https://en.wikipedia.org/wiki/Natural_logarithm)
    /// Based mostly on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static AltDec Ln(AltDec Value)
    {
        AltDec old_sum = Zero;
        AltDec xmlxpl = (Value - 1) / (Value + 1);
        AltDec xmlxpl_2 = xmlxpl * xmlxpl;
        int denom = 1;
        AltDec frac = xmlxpl;
        AltDec term = frac;
        AltDec sum = term;

        while (sum != old_sum)
        {
            old_sum = sum;
            denom += 2;
            frac *= xmlxpl_2;
            sum += frac / denom;
        }
        return 2 * sum;
    }

    /// <summary>
    /// Natural log of Value(https://en.wikipedia.org/wiki/Natural_logarithm)
    /// Based mostly on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static AltDec LnRef(AltDec& Value)
    {
        AltDec old_sum = Zero;
        AltDec xmlxpl = (Value - 1) / (Value + 1);
        AltDec xmlxpl_2 = xmlxpl * xmlxpl;
        int denom = 1;
        AltDec frac = xmlxpl;
        AltDec term = frac;
        AltDec sum = term;

        while (sum != old_sum)
        {
            old_sum = sum;
            denom += 2;
            frac *= xmlxpl_2;
            sum += frac / denom;
        }
        return 2.0 * sum;
    }

    /// <summary>
    /// Natural log of Value(https://en.wikipedia.org/wiki/Natural_logarithm)
    /// Based mostly on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static AltDec Ln(int Value)
    {
        AltDec old_sum = Zero;
        AltDec xmlxpl = (Value - 1) / (Value + 1);
        AltDec xmlxpl_2 = xmlxpl * xmlxpl;
        int denom = 1;
        AltDec frac = xmlxpl;
        AltDec term = frac;
        AltDec sum = term;

        while (sum != old_sum)
        {
            old_sum = sum;
            denom += 2;
            frac *= xmlxpl_2;
            sum += frac / denom;
        }
        return 2 * sum;
    }

    /// <summary>
    /// Log Base 10 of Value
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec Log10(AltDec Value)
    {
        return Ln(Value) / LN10;
    }

    /// <summary>
    /// Log Base 10 of Value
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    static AltDec Log10(int Value)
    {
        return Ln(Value) / LN10;
    }

    /// <summary>
    /// Log with Base of BaseVal of Value
    /// Based on http://home.windstream.net/okrebs/page57.html
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <param name="BaseVal">The base of Log</param>
    /// <returns>AltDec</returns>
    static AltDec Log(AltDec Value, AltDec BaseVal)
    {
        return Log10(Value) / Log10(BaseVal);
    }

    /// <summary>
    /// Log with Base of BaseVal of Value
    /// Based on http://home.windstream.net/okrebs/page57.html
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <param name="BaseVal">The base of Log</param>
    /// <returns>AltDec</returns>
    static AltDec Log(AltDec Value, int BaseVal)
    {
        return Log10(Value) / Log10(BaseVal);
    }
#pragma endregion Math/Trigonomic Etc Functions
    };

#pragma region ValueDefine Source
AltDec AltDec::PI = PIValue();
AltDec AltDec::One = OneValue();
AltDec AltDec::Two = OneValue();
AltDec AltDec::NegativeOne = NegativeOneValue();
AltDec AltDec::Zero = ZeroValue();
AltDec AltDec::PointFive = Point5Value();
AltDec AltDec::JustAboveZero = JustAboveZeroValue();
AltDec AltDec::OneMillionth = OneMillionthValue();
AltDec AltDec::Minimum = MinimumValue();
AltDec AltDec::Maximum = MaximumValue();
AltDec AltDec::E = EValue();
AltDec AltDec::LN10 = LN10Value();
#pragma endregion ValueDefine Source

#pragma region String Function Source
/// <summary>
/// Reads the string with additional support for fractions.(Reading either decimal number,mixed fraction, or Numerator/Denominator format)
/// </summary>
inline void AltDec::ReadFractionalString(std::string Value)
{
    IntValue = 0; DecimalHalf01 = 0; DecimalHalf02 = 0;
    bool IsNegative = false;
    int PlaceNumber;
    //Uses as either the whole number buffer or numerator buffer
    std::string Buffer01 = "";
    std::string Buffer02 = "";
    std::string DenominatorBuffer = "";

    bool ReadingDecimal = false;
    bool RadicalDetected = false;
    bool ReadingDenominator = false;
    //Support for format Int+Fraction
    bool MixedFractionsDetected = false;

    int TempInt;
    int TempInt02;
    for (char const& StringChar : Value)
    {
        if (VariableConversionFunctions::IsDigit(StringChar))
        {
            if (ReadingDenominator) { DenominatorBuffer += StringChar; }
            else if (ReadingDecimal || MixedFractionsDetected) { Buffer02 += StringChar; }
            else { Buffer01 += StringChar; }
        }
        else if (StringChar == '-')
        {
            IsNegative = true;
        }
        else if (StringChar == '.')
        {
            ReadingDecimal = true;
        }
        else if (StringChar == '_' || StringChar == ' ')
        {//Mixed Fraction format
            MixedFractionsDetected = true;
        }
        else if (StringChar == '/')
        {
            //if(ReadingDecimal){}Allow non integer numerators later
            RadicalDetected = true; ReadingDenominator = true;
        }
    }
    PlaceNumber = Buffer01.length() - 1;
    if (MixedFractionsDetected)
    {
        for (char const& StringChar : Buffer01)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                IntValue += TempInt02;
            }
            PlaceNumber--;
        }

        PlaceNumber = Buffer02.length() - 1;
        for (char const& StringChar : Buffer02)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                DecimalHalf01 += TempInt02;
            }
            PlaceNumber--;
        }

        PlaceNumber = DenominatorBuffer.length() - 1;
        for (char const& StringChar : DenominatorBuffer)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                DecimalHalf02 += TempInt02;
            }
            PlaceNumber--;
        }
    }
    else if (RadicalDetected)
    {
        for (char const& StringChar : Buffer01)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                DecimalHalf01 += TempInt02;
            }
            PlaceNumber--;
        }
        PlaceNumber = DenominatorBuffer.length() - 1;
        for (char const& StringChar : DenominatorBuffer)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                DecimalHalf02 += TempInt02;
            }
            PlaceNumber--;
        }
    }
    else
    {
        for (char const& StringChar : Buffer01)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                IntValue += TempInt02;
            }
            PlaceNumber--;
        }
        PlaceNumber = 8;
        for (char const& StringChar : Buffer02)
        {
            //Limit stored decimal numbers to the amount it can store
            if (PlaceNumber > -1)
            {
                TempInt = VariableConversionFunctions::CharAsInt(StringChar);
                TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
                if (StringChar != '0')
                {
                    DecimalHalf01 += TempInt02;
                }
                PlaceNumber--;
            }
        }
    }
    if (IsNegative)
    {
        if (IntValue == 0) { IntValue = NegativeZero; }
        else { IntValue *= -1; }
    }
}

/// <summary>
/// Reads the string.
/// </summary>
/// <param name="Value">The value.</param>
inline void AltDec::ReadString(std::string Value)
{
    IntValue = 0; DecimalHalf01 = 0; DecimalHalf02 = 0;
    bool IsNegative = false;
    int PlaceNumber;
    std::string WholeNumberBuffer = "";
    std::string DecimalBuffer = "";

    bool ReadingDecimal = false;
    int TempInt;
    int TempInt02;
    for (char const& StringChar : Value)
    {
        if (VariableConversionFunctions::IsDigit(StringChar))
        {
            if (ReadingDecimal) { DecimalBuffer += StringChar; }
            else { WholeNumberBuffer += StringChar; }
        }
        else if (StringChar == '-')
        {
            IsNegative = true;
        }
        else if (StringChar == '.')
        {
            ReadingDecimal = true;
        }
    }
    PlaceNumber = WholeNumberBuffer.length() - 1;
    for (char const& StringChar : WholeNumberBuffer)
    {
        TempInt = VariableConversionFunctions::CharAsInt(StringChar);
        TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
        if (StringChar != '0')
        {
            IntValue += TempInt02;
        }
        PlaceNumber--;
    }
    PlaceNumber = 8;
    for (char const& StringChar : DecimalBuffer)
    {
        //Limit stored decimal numbers to the amount it can store
        if (PlaceNumber > -1)
        {
            TempInt = VariableConversionFunctions::CharAsInt(StringChar);
            TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
            if (StringChar != '0')
            {
                DecimalHalf01 += TempInt02;
            }
            PlaceNumber--;
        }
    }
    if (IsNegative)
    {
        if (IntValue == 0) { IntValue = NegativeZero; }
        else { IntValue *= -1; }
    }
}

/// <summary>
/// Gets the value from string.
/// </summary>
/// <param name="Value">The value.</param>
/// <returns>AltDec</returns>
inline AltDec AltDec::GetValueFromString(std::string Value)
{
    AltDec NewSelf = Zero;
    NewSelf.ReadString(Value);
    return NewSelf;
}

/// <summary>
/// Converts the fractional string to number.
/// </summary>
/// <param name="Value">The value.</param>
/// <returns>AltDec</returns>
inline AltDec AltDec::ConvertFractionalStringToNum(std::string Value)
{
    AltDec self;
    self.ReadFractionalString(Value);
    return self;
}

std::string AltDec::ToString()
{
    std::string Value = "";
    int CurrentSection = IntValue;
    unsigned __int8 CurrentDigit;
    if (IntValue < 0)
    {
        Value += "-";
        if (IntValue == NegativeZero) { CurrentSection = 0; }
        else { CurrentSection *= -1; }
    }
    for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
    {
        CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
        CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
        Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
    }
    NormalizeToNum();
    if (DecimalHalf01 != 0)
    {
        Value += ".";
        bool HasDigitsUsed = false;
        CurrentSection = DecimalHalf01;
        for (__int8 Index = 8; Index >= 0; --Index)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            if (HasDigitsUsed == false)
            {
                if (CurrentDigit != 0)
                {
                    HasDigitsUsed = true;
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
            }
            else
            {
                Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
            }
        }
    }
    return Value;
}

std::string AltDec::ToFullString()
{
    std::string Value = "";
    int CurrentSection = IntValue;
    unsigned __int8 CurrentDigit;
    if (IntValue < 0)
    {
        Value += "-";
        if (IntValue == NegativeZero) { CurrentSection = 0; }
        else { CurrentSection *= -1; }
    }
    for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
    {
        CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
        CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
        Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
    }
    NormalizeToNum();
    if (DecimalHalf01 != 0)
    {
        Value += ".";
        bool HasDigitsUsed = false;
        CurrentSection = DecimalHalf01;
        for (__int8 Index = 8; Index >= 0; --Index)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            if (HasDigitsUsed == false)
            {
                if (CurrentDigit != 0)
                {
                    HasDigitsUsed = true;
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
            }
            else
            {
                Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
            }
        }
    }
    else
    {
        Value += ".000000000";
    }
    return Value;
}

std::string AltDec::ToOptimalString()
{
    std::string Value = "";
    int CurrentSection = IntValue;
    unsigned __int8 CurrentDigit;
    if (IntValue < 0)
    {
        Value += "-";
        if (IntValue == NegativeZero) { CurrentSection = 0; }
        else { CurrentSection *= -1; }
    }
    if (DecimalHalf02 == 0 || (IntValue != NegativeZero && IntValue != 0))
    {
        for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
        }
    }
    if (DecimalHalf02 != 0)
    {
        if (IntValue != NegativeZero && IntValue != 0)
        {
#ifdef AltDec_SeparateMixedFractionWithTile
            Value += "_";
#else
            Value += " ";
#endif
    }
        CurrentSection = DecimalHalf01;
        for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
        }
        Value += "/";
        CurrentSection = DecimalHalf02;
        for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
        }
}
    else if (DecimalHalf01 != 0)
    {
        Value += ".";
        bool HasDigitsUsed = false;
        CurrentSection = DecimalHalf01;
        for (__int8 Index = 8; Index >= 0; --Index)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            if (HasDigitsUsed == false)
            {
                if (CurrentDigit != 0)
                {
                    HasDigitsUsed = true;
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
            }
            else
            {
                Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
            }
        }
    }
    return Value;
        }
#pragma endregion String Function Source

#pragma region Root Source
/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRoot(AltDec value, int n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRefRoot(AltDec& value, int n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRoot(int value, int n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRoot(AltDec value, AltDec n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRefRoot(AltDec& value, AltDec n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root
/// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
/// </summary>
/// <param name="value">The value to apply the root on.</param>
/// <param name="n">The n value to apply with root.</param>
/// <returns></returns>
AltDec AltDec::NthRoot(int value, AltDec n, AltDec Precision)
{
    AltDec x[2];
    x[0] = value;
    x[1] = value / n;
    while (AltDec::Abs(x[0] - x[1]) > Precision)
    {
        x[1] = x[0];
        x[0] = (1 / n) * (((n - 1) * x[1]) + (value / AltDec::Pow(x[1], n - 1)));
    }
    return x[0];
}

/// <summary>
/// Get the (n)th Root with OneMillionth precision level
/// </summary>
/// <param name="nValue">The n value.</param>
/// <returns>AltDec</returns>
AltDec AltDec::NthRoot(int nValue)
{
    return NthRefRoot(*this, nValue, AltDec::OneMillionth);
}
#pragma endregion Root Source