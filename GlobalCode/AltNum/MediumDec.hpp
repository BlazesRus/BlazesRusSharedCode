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

//#include <boost/math/tools/roots.hpp>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace BlazesRusCode
{
    //class UInt128 : boost::multiprecision::checked_uint128_t
    //{};

    class MediumDec;//Operations and functions will mess up if IntValue overflows/underflows or reaches exactly -2147483648 which is used to represent negative zero when has decimal values

    /// <summary>
    /// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
    /// Represents +- 2147483647.999999999 with 100% consistency of accuracy for most operations as long as don't get too small
    //  Use AltDec instead if want to use variant of this class that supports radical representation to save some extra precision
    /// (8 bytes worth of Variable Storage inside class for each instance)
    /// </summary>
    class DLL_API MediumDec
    {
    public:
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
        /// Stores decimal section info
        /// </summary>
        signed int DecimalHalf01;

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="intVal">The int value.</param>
        /// <param name="decVal01">The decimal val01.</param>
        /// <param name="decVal02">The decimal val02.</param>
        MediumDec(signed int intVal = 0, signed int decVal01 = 0)
        {
            IntValue = intVal;
            DecimalHalf01 = decVal01;
        }

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(MediumDec Value)
        {
            IntValue = Value.IntValue;
            DecimalHalf01 = Value.DecimalHalf01;
        }

    #pragma region ValueDefines
    private:
        /// <summary>
        /// Returns the value at zero
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec ZeroValue()
        {
            MediumDec NewSelf = MediumDec();
            return NewSelf;
        }
        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec OneValue()
        {
            MediumDec NewSelf = MediumDec(1);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec TwoValue()
        {
            MediumDec NewSelf = MediumDec(2);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at negative one
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec NegativeOneValue()
        {
            MediumDec NewSelf = MediumDec(-1);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at 0.5
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec Point5Value()
        {
            MediumDec NewSelf = MediumDec(0, 500000000);
            return NewSelf;
        }

        static MediumDec JustAboveZeroValue()
        {
            MediumDec NewSelf = MediumDec(0, 1);
            return NewSelf;
        }

        static MediumDec OneMillionthValue()
        {
            MediumDec NewSelf = MediumDec(0, 1000);
            return NewSelf;
        }

        static MediumDec FiveMillionthValue()
        {
            MediumDec NewSelf = MediumDec(0, 5000);
            return NewSelf;
        }

        static MediumDec TenMillionthValue()
        {
            MediumDec NewSelf = MediumDec(0, 100);
            return NewSelf;
        }

        static MediumDec OneHundredMillionthValue()
        {
            MediumDec NewSelf = MediumDec(0, 10);
            return NewSelf;
        }

        static MediumDec FiveBillionthValue()
        {
            MediumDec NewSelf = MediumDec(0, 5);
            return NewSelf;
        }

        /// <summary>
        /// Returns PI(3.1415926535897932384626433) with tenth digit rounded up(3.141592655)
        /// (about 1.000000000448883 times actual value of PI with digits past 15th cut off)
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec PIValue()
        {
            MediumDec NewSelf = MediumDec(3, 141592655);
            return NewSelf;
        }

        /// <summary>
        /// Returns value of -2147483647.999999999
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec MinimumValue()
        {
            return MediumDec(-2147483647, 999999999);
        }

        /// <summary>
        /// Returns value of 2147483647.999999999
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec MaximumValue()
        {
            return MediumDec(2147483647, 999999999);
        }

        /// <summary>
        /// Euler's number
        /// Irrational number equal to about (1 + 1/n)^n
        /// (about 2.71828182845904523536028747135266249775724709369995)
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec EValue()
        {
            return MediumDec(2, 718281828);
        }

        static MediumDec LN10Value()
        {
            return MediumDec(2, 302585093);
        }

        static MediumDec NilValue()
        {
            return MediumDec(-2147483647, -2147483647);
        }
    public:
        static MediumDec PI;

        /// <summary>
        /// Returns the value at zero
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec Zero;

        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec One;

        /// <summary>
        /// Returns the value at two
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec Two;

        /// <summary>
        /// Returns the value at 0.5
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec PointFive;

        /// <summary>
        /// Returns the value at digit more than zero
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec JustAboveZero;

        /// <summary>
        /// Returns the value at .000000005
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec FiveBillionth;

        /// <summary>
        /// Returns the value at .000001000
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec OneMillionth;

        /// <summary>
        /// Returns the value at .000000010
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec OneGMillionth;

        //0e-7
        static MediumDec TenMillionth;

        /// <summary>
        /// Returns the value at "0.000005"
        /// </summary>
        static MediumDec FiveMillionth;

        /// <summary>
        /// Returns the value at negative one
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec NegativeOne;

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        static MediumDec Maximum;

        /// <summary>
        /// Returns value of lowest non-infinite/Special Decimal State Value that can store
        /// </summary>
        static MediumDec Minimum;

        /// <summary>
        /// Euler's number
        /// Irrational number equal to about (1 + 1/n)^n
        /// (about 2.71828182845904523536028747135266249775724709369995)
        /// </summary>
        /// <returns>MediumDec</returns>
        static MediumDec E;

        /// <summary>
        /// 2.3025850929940456840179914546844
        /// (Based on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having)
        /// </summary>
        static MediumDec LN10;

        /// <summary>
        /// Nil Value as proposed by https://docs.google.com/document/d/19n-E8Mu-0MWCcNt0pQnFi2Osq-qdMDW6aCBweMKiEb4/edit
        /// </summary>
        static MediumDec Nil;

        ///// <summary>
        ///// 16 x 1 Matrix with Values at Zero
        ///// </summary>
        //static MediumDec ZeroMatrix16[16] = { Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero, Zero };
    #pragma endregion ValueDefines
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
        /// Reads the string.
        /// </summary>
        /// <param name="Value">The value.</param>
        void ReadString(std::string Value);

        /// <summary>
        /// Gets the value from string.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        MediumDec GetValueFromString(std::string Value);

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class from string literal
        /// </summary>
        /// <param name="strVal">The value.</param>
        MediumDec(const char* strVal)
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
                this->ReadString(Value);
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MediumDec(std::string Value)
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
                this->ReadString(Value);
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
        /// Implements the operator std::string operator.
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator std::string() { return ToString(); }

        ///// <summary>
        ///// += MediumDec operation added to std::string
        ///// </summary>
        ///// <param name="targetString">The target string(left side).</param>
        ///// <param name="Value">The right side value</param>
        ///// <returns>string</returns>
        //friend std::string operator+=(std::string targetString, MediumDec self) { return targetString + self.ToString(); }
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
        }

        /// <summary>
        /// Sets the value(false equals zero; otherwise is true).
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(bool Value)
        {
            IntValue = Value==false ? 0 : 1;
            DecimalHalf01 = 0;
        }

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(int Value)
        {
            IntValue = Value; DecimalHalf01 = 0;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MediumDec(float Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MediumDec(double Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MediumDec(ldouble Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MediumDec(bool Value)
        {
            this->SetVal(Value);
        }
    #pragma endregion From Standard types to this type
    #pragma region From this type to Standard types
        /// <summary>
        /// MediumDec to float explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator float()
        {
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
        /// MediumDec to double explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator double()
        {
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
        /// MediumDec to long double explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator ldouble()
        {
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
        /// MediumDec to int explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator int() { return IntValue; }

        explicit operator bool() { return IntValue == 0 ? false : true; }

        /// <summary>
        /// MediumDec to integer type explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        template<typename IntType>
        explicit operator IntType() { return IntValue; }
    #pragma endregion From this type to Standard types
    #pragma region Comparison Operators
        /// <summary>
        /// Equal to Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator==(MediumDec self, MediumDec Value)
        {
            return (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01);
        }

        /// <summary>
        /// Not equal to Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator!=(MediumDec self, MediumDec Value)
        {
            return (self.IntValue != Value.IntValue || self.DecimalHalf01 != Value.DecimalHalf01);
        }

        /// <summary>
        /// Lesser than Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<(MediumDec self, MediumDec Value)
        {
            if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return false; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return false; }// 5 > -5
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }// -5 <5
                else
                {//Both are either positive or negative
                    if (Value.DecimalHalf01 == 0)
                    {
                        if (self.DecimalHalf01 == 0)
                            return self.IntValue < Value.IntValue;
                        else
                        {
                            if (self.IntValue == NegativeZero)
                            {//-0.5<0
                                if (Value.IntValue >= 0)
                                    return true;
                            }
                            else if (self.IntValue < Value.IntValue) { return true; }//5.5 < 6
                            else if (self.IntValue == Value.IntValue) { return self.IntValue < 0 ? true : false; }//-5.5<-5 vs 5.5 > 5
                        }
                    }
                    else if (self.DecimalHalf01 == 0)
                    {
                        if (Value.IntValue == NegativeZero)
                        {
                            if (self.IntValue <= -1)
                                return true;
                        }
                        else if (self.IntValue < Value.IntValue)
                            return true;// 5 < 6.5
                        else if (Value.IntValue == self.IntValue)
                            return Value.IntValue < 0 ? false : true;//5 < 5.5 vs -5 > -5.5
                    }
                    //Assuming both are non-whole numbers if reach here
                    if (self.IntValue == NegativeZero)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeZero)
                        Value.IntValue = 0;
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf01 > Value.DecimalHalf01;
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf01 < Value.DecimalHalf01;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// Lesser than or Equal to Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<=(MediumDec self, MediumDec Value)
        {
            if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return true; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return false; }//5>=-5
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }//-5<=5
                else
                {
                    if (Value.DecimalHalf01 == 0)
                    {
                        if (self.DecimalHalf01 == 0)
                            return self.IntValue <= Value.IntValue;
                        else
                        {
                            if (self.IntValue == NegativeZero)
                            {//-0.5<0
                                if (Value >= 0)
                                    return true;
                            }
                            else if (self.IntValue < Value) { return true; }//5.5<=6
                            else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }
                        }
                    }
                    else if (self.DecimalHalf01 == 0)
                    {
                        if (Value.IntValue == NegativeZero && self.IntValue <= 1)
                        {//-1<-0.5
                            if (self.IntValue <= -1)
                                return true;
                        }
                        else if (self.IntValue < Value.IntValue)
                            return true;
                        else if (Value.IntValue == self.IntValue)
                            return Value.IntValue < 0 ? false : true;//5 <= 5.5 vs -5 >= -5.5
                    }
                    //Assuming both are non-whole numbers if reach here
                    if (self.IntValue == NegativeZero)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeZero)
                        Value.IntValue = 0;
                    if (SelfIsNegative)//Both are either positive or negative
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf01 > Value.DecimalHalf01;
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf01 < Value.DecimalHalf01;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// Greater than Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The right side value.</param>
        /// <returns>bool</returns>
        friend bool operator>(MediumDec self, MediumDec Value)
        {
            if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return false; }
            else
            {

                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return true; }//5 > -5
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }//-5<5
                else if (Value.DecimalHalf01 == 0)
                {
                    if (self.DecimalHalf01 == 0)
                        return self.IntValue > Value.IntValue;
                    else
                    {
                        if (self.IntValue == NegativeZero)
                        {//-0.5>-1
                            if (Value <= -1)
                                return true;
                        }
                        else if (self.IntValue > Value) { return true; }
                        else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }
                    }
                }
                else if (self.DecimalHalf01 == 0)
                {
                    if (Value.IntValue == NegativeZero)
                    {
                        if (self.IntValue >= 0)
                            return true;
                    }
                    else if (self.IntValue > Value.IntValue)
                        return true;
                    else if (Value.IntValue == self.IntValue)
                        return Value.IntValue < 0 ? true : false;//5 < 5.5 vs -5 > -5.5
                }
                //Assuming both are non-whole numbers if reach here
                if (self.IntValue == NegativeZero)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeZero)
                    Value.IntValue = 0;
                if (SelfIsNegative)//Both are either positive or negative
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf01 < Value.DecimalHalf01;
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf01 > Value.DecimalHalf01;
                }
            }
            return false;
        }

        /// <summary>
        /// Greater than or Equal to Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator>=(MediumDec self, MediumDec Value)
        {
            if (self.IntValue == Value.IntValue && self.DecimalHalf01 == Value.DecimalHalf01) { return true; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return true; }
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }
                else if (Value.DecimalHalf01 == 0)
                {
                    if (self.DecimalHalf01 == 0)
                        return self.IntValue >= Value.IntValue;
                    else
                    {
                        if (self.IntValue == NegativeZero)
                        {
                            if (Value <= -1)
                                return true;
                        }
                        else if (self.IntValue > Value)
                            return true;
                        else if (self.IntValue == Value)
                            return self.IntValue < 0 ? false : true;//-5.5<-5 vs 5.5>5
                    }
                }
                else if (self.DecimalHalf01 == 0)//return self.IntValue > Value;
                {
                    if (Value.IntValue == NegativeZero)
                    {//0>-0.5
                        if (self.IntValue >= 0)
                            return true;
                    }
                    else if (self.IntValue > Value.IntValue)
                        return true;
                    else if (Value.IntValue == self.IntValue)
                        return Value.IntValue < 0 ? true : false;//5 <= 5.5 vs -5 >= -5.5
                }
                //Assuming both are non-whole numbers if reach here
                if (self.IntValue == NegativeZero)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeZero)
                    Value.IntValue = 0;
                if (SelfIsNegative)//Both are either positive or negative
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)//-5.5 >= -6.5
                        return true;
                    else if (self.IntValue == Value.IntValue)//-5.5 >= -5.6
                        return self.DecimalHalf01 < Value.DecimalHalf01;
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf01 > Value.DecimalHalf01;
                }
            }
            return false;
        }

    #pragma endregion Comparison Operators
    #pragma region MediumDec-To-MediumDec Operators
    public:
        /// <summary>
        /// Addition Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        static MediumDec& AddOp(MediumDec& self, MediumDec& Value)
        {
            if (Value == Zero) { return self; }
            if (Value.DecimalHalf01 == 0){ self.IntValue += Value.IntValue; }
            else
            {
                self += Value.IntValue;
                self.DecimalHalf01 += Value.DecimalHalf01;
                if (self.DecimalHalf01 < 0) { self.DecimalHalf01 += DecimalOverflow; --self; }
                else if (self.DecimalHalf01 >= DecimalOverflow) { self.DecimalHalf01 -= DecimalOverflow; ++self; }
            }
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        static MediumDec& SubOp(MediumDec& self, MediumDec& Value)
        {
            if (Value == Zero) { return self; }
            if (Value.DecimalHalf01 == 0) { self.IntValue -= Value.IntValue; }
            else
            {
                self -= Value.IntValue;
                self.DecimalHalf01 -= Value.DecimalHalf01;
                if (self.DecimalHalf01 < 0) { self.DecimalHalf01 += DecimalOverflow; --self; }
                else if (self.DecimalHalf01 >= DecimalOverflow) { self.DecimalHalf01 -= DecimalOverflow; ++self; }
            }
            return self;
        }

        /// <summary>
        /// Multiplication Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        static MediumDec& MultOp(MediumDec& self, MediumDec& Value)
        {
            if (Value == MediumDec::Zero) { self.IntValue = 0; self.DecimalHalf01 = 0; return self; }
            if (self == MediumDec::Zero || Value == MediumDec::One)
                return self;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == MediumDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if (self.DecimalHalf01 == 0)
            {
                if (self.IntValue == 1) { self = Value; return self; }
                else if (Value.DecimalHalf01 == 0)
                {
                    self.IntValue *= Value.IntValue; return self;
                }
                else
                {
                    Value *= self.IntValue;
                    self = Value;
                }
            }
            else if (self.IntValue == 0)
            {
                __int64 SRep = (__int64)self.DecimalHalf01;
                SRep *= Value.DecimalHalf01;
                SRep /= MediumDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)self.DecimalHalf01 * Value.IntValue;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = OverflowVal;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                }
            }
            else if (self.IntValue == MediumDec::NegativeZero)
            {
                __int64 SRep = (__int64)self.DecimalHalf01;
                SRep *= Value.DecimalHalf01;
                SRep /= MediumDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)self.DecimalHalf01 * Value.IntValue;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = -OverflowVal;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.IntValue == 0)
                {
                    __int64 SRep = MediumDec::DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                    SRep *= Value.DecimalHalf01;
                    SRep /= MediumDec::DecimalOverflowX;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = (signed int)(SelfIsNegative ? -OverflowVal : OverflowVal);
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = SelfIsNegative ? MediumDec::NegativeZero : 0;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                }
                else if (Value.DecimalHalf01 == 0)//Y is integer
                {
                    __int64 SRep = MediumDec::DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                    SRep *= Value.IntValue;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = (signed int)OverflowVal;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = 0;
                        self.DecimalHalf01 = (signed int)SRep;
                    }
                    return self;
                }
                else
                {
                    //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                    __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : MediumDec::DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                    SRep *= Value.IntValue;//SRep holds __int64 version of X.Y * Z
                    //X.Y *.V
                    __int64 Temp03 = (__int64)self.IntValue * Value.DecimalHalf01;//Temp03 holds __int64 version of X *.V
                    __int64 Temp04 = (__int64)self.DecimalHalf01 * (__int64)Value.DecimalHalf01;
                    Temp04 /= MediumDec::DecimalOverflow;
                    //Temp04 holds __int64 version of .Y * .V
                    __int64 IntegerRep = SRep + Temp03 + Temp04;
                    __int64 IntHalf = IntegerRep / MediumDec::DecimalOverflow;
                    IntegerRep -= IntHalf * (__int64)MediumDec::DecimalOverflow;
                    if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? MediumDec::NegativeZero : 0; }
                    else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    self.DecimalHalf01 = (signed int)IntegerRep;
                }
            }
            if (self == MediumDec::Zero) { self.DecimalHalf01 = 1; }//Prevent Dividing into nothing
            return self;
        }

        /// <summary>
        /// Division Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        static MediumDec& DivOp(MediumDec& self, MediumDec& Value)
        {
            if (Value == MediumDec::Zero)
                throw "Target value can not be divided by zero";
            if (self == MediumDec::Zero) { return self; }
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == MediumDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if (self.DecimalHalf01 == 0)
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.DecimalHalf01 == 0)//Both are integers
                {
                    if (self.IntValue < 0) { self.IntValue *= -1; }
                    __int64 SRep = self.IntValue * MediumDec::DecimalOverflowX;
                    __int64 YRep = Value.IntValue;
                    SRep /= Value.IntValue;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = SelfIsNegative ? MediumDec::NegativeZero : 0;
                    }
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else//Only self is integer while Value has both sides
                {
                    /* Testing calculation 2.0/2.5 = 0.8
                    MediumDec::DecimalOverflowX * self.IntValue = 2000000000
                    (MediumDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf01) = 2500000000

                    Converting to 2/(5/2) = 4/5
                    4/5 = 800000000
                    2000000000/(2500000000/MediumDec::DecimalOverflowX)=800000000
                    */
                    boost::multiprecision::uint128_t SRep02 = MediumDec::DecimalOverflowX * MediumDec::DecimalOverflowX;
                    SRep02 *= self.IntValue;
                    __int64 VRep = MediumDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf01;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = 0;
                    }
                    self.DecimalHalf01 = (signed int)SRep;
                }
            }
            else if (self.IntValue == 0)
            {
                __int64 SRep = (__int64)self.DecimalHalf01 * MediumDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf01 : MediumDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf01;
                int IntHalf = SRep / MediumDec::DecimalOverflowX;
                SRep -= IntHalf * MediumDec::DecimalOverflowX;
                self.IntValue = IntHalf;
                self.DecimalHalf01 = (signed int)SRep;
            }
            else if (self.IntValue == MediumDec::NegativeZero)
            {
                __int64 SRep = (__int64)self.DecimalHalf01 * MediumDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf01 : MediumDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf01;
                int IntHalf = SRep / MediumDec::DecimalOverflowX;
                SRep -= IntHalf * MediumDec::DecimalOverflowX;
                self.IntValue = IntHalf == 0 ? MediumDec::NegativeZero : -IntHalf;
                self.DecimalHalf01 = (signed int)SRep;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.DecimalHalf01 == 0)//Y is integer but self is not
                {
                    __int64 SRep = MediumDec::DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                    SRep /= Value.IntValue;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        self.IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = 0;
                    }
                    self.DecimalHalf01 = (signed int)SRep;
                }
                else
                {//Splitting Integer Half and Decimal Half Division
                    __int64 SRep_DecHalf = (__int64)self.DecimalHalf01 * MediumDec::DecimalOverflowX;
                    SRep_DecHalf /= Value.IntValue == 0 ? Value.DecimalHalf01 : MediumDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf01;
                    int IntHalf = SRep_DecHalf / MediumDec::DecimalOverflowX;
                    SRep_DecHalf -= IntHalf * MediumDec::DecimalOverflowX;

                    boost::multiprecision::uint128_t SRep02 = MediumDec::DecimalOverflowX * MediumDec::DecimalOverflowX;
                    //std::cout << "Multi-precision as String:" << SRep02 << std::endl;
                    SRep02 *= self.IntValue;
                    __int64 VRep = MediumDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf01;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02 + SRep_DecHalf;
                    if (SRep >= MediumDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MediumDec::DecimalOverflowX;
                        SRep -= OverflowVal * MediumDec::DecimalOverflowX;
                        IntHalf += OverflowVal;
                    }
                    if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? MediumDec::NegativeZero : 0; }
                    else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    self.DecimalHalf01 = (signed int)SRep;
                }
            }
            if (self == MediumDec::Zero) { self.DecimalHalf01 = 1; }//Prevent Dividing into nothing
            return self;
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MediumDec&</returns>
        static MediumDec& RemOp(MediumDec& self, MediumDec& Value)
        {
            bool SelfIsWholeN = self.DecimalHalf01 == 0;
            bool ValueIsWholeN = Value.DecimalHalf01 == 0;
            if (Value.IntValue == 0 && ValueIsWholeN) { return MediumDec::Zero; }//Return zero instead of N/A
            if (SelfIsWholeN && ValueIsWholeN)//WholeNumbers
            {
                self.IntValue %= Value.IntValue;
            }
            else if (ValueIsWholeN)
            {
                self %= Value.IntValue;
            }
            else
            {
                //bool ValueIsNegative = Value.IntValue < 0;
                if (Value.IntValue < 0)
                {
                    self.IntValue *= -1;
                    if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                }
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf01 : DecimalOverflowX * self.IntValue + self.DecimalHalf01;
                __int64 SRep_DecHalf = SRep;
                __int64 VRep = DecimalOverflowX * Value.IntValue + Value.DecimalHalf01;;
                SRep %= VRep;
                __int64 IntResult = SRep;
                //Int Half Calculated now get decimal digits that got truncated off
                SRep_DecHalf -= IntResult * VRep;
                //Gives enough buffer room that doesn't lose the decimal values
                SRep_DecHalf *= DecimalOverflowX;
                SRep_DecHalf %= VRep;
                if (IntResult == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
                else { self.IntValue = (signed int)SelfIsNegative ? IntResult * -1 : IntResult; }
                self.DecimalHalf01 = (signed int)SRep;
            }
            return self;
        }
        
    public:
        /// <summary>
        /// Addition Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator+(MediumDec self, MediumDec Value)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// += Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator+=(MediumDec& self, MediumDec Value)
        {
            return AddOp(self, Value);
        }
        
        /// <summary>
        /// += Operation Between MediumDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator+=(MediumDec* self, MediumDec Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator-(MediumDec self, MediumDec Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator-=(MediumDec& self, MediumDec Value)
        {
            return SubOp(self, Value);
        }
        
        /// <summary>
        /// -= Operation Between MediumDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator-=(MediumDec* self, MediumDec Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator*(MediumDec self, MediumDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between MediumDecs
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MediumDec</returns>
        friend MediumDec& operator*=(MediumDec& self, MediumDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between MediumDecs (from pointer)
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MediumDec</returns>
        friend MediumDec& operator*=(MediumDec* self, MediumDec Value){ return MultOp(**self, Value); }


        /// <summary>
        /// Division Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator/(MediumDec self, MediumDec Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator/=(MediumDec& self, MediumDec Value)
        {
            return DivOp(self, Value);
        }
        
        /// <summary>
        /// /= Operation Between MediumDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator/=(MediumDec* self, MediumDec Value){ return DivOp(**self, Value); }

        /// <summary>
        /// Remainder Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator%(MediumDec self, MediumDec Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator%=(MediumDec& self, MediumDec Value)
        {
            return RemOp(self, Value);
        }
        
        /// <summary>
        /// %= Operation Between MediumDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        friend MediumDec& operator%=(MediumDec* self, MediumDec Value)
        {
            return RemOp(**self, Value);
        }

        /// <summary>
        /// XOR Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator^(MediumDec self, MediumDec Value)
        {
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
        /// Bitwise Or Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator|(MediumDec self, MediumDec Value)
        {
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
        /// Bitwise And Operation Between MediumDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MediumDec</returns>
        friend MediumDec operator&(MediumDec self, MediumDec Value)
        {
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
        /// <returns>MediumDec</returns>
        friend MediumDec& operator-(MediumDec& self)
        {
            self.SwapNegativeStatus(); return self;
        }

        /// <summary>
        /// ++MediumDec Operator
        /// </summary>
        /// <returns>MediumDec &</returns>
        MediumDec& operator ++()
        {
            if (IntValue == NegativeZero) { IntValue = 0; }
            else if (DecimalHalf01 == 0) { ++IntValue; }
            else if (IntValue == -1) { IntValue = NegativeZero; }
            else { ++IntValue; }
            return *this;
        }

        /// <summary>
        /// ++MediumDec Operator
        /// </summary>
        /// <returns>MediumDec &</returns>
        MediumDec& operator --()
        {
            if (IntValue == NegativeZero) { IntValue = -1; }
            else if (DecimalHalf01 == 0) { --IntValue; }
            else if (IntValue == 0) { IntValue = NegativeZero; }
            else { --IntValue; }
            return *this;
        }

        /// <summary>
        /// MediumDec++ Operator
        /// </summary>
        /// <returns>MediumDec</returns>
        MediumDec operator ++(int)
        {
            MediumDec tmp(*this);
            ++* this;
            return tmp;
        }

        /// <summary>
        /// MediumDec-- Operator
        /// </summary>
        /// <returns>MediumDec</returns>
        MediumDec operator --(int)
        {
            MediumDec tmp(*this);
            --* this;
            return tmp;
        }

        /// <summary>
        /// MediumDec* Operator
        /// </summary>
        /// <returns>MediumDec &</returns>
        MediumDec& operator *()
        {
            return *this;
        }

    #pragma endregion MediumDec-To-MediumDec Operators
    #pragma region Other Comparison Operators
        //friend bool operator==(MediumDec self, float Value) { return self == (MediumDec)Value; }
        //friend bool operator!=(MediumDec self, float Value) { return self != (MediumDec)Value; }
        //friend bool operator<(MediumDec self, float Value) { return self < (MediumDec)Value; }
        //friend bool operator<=(MediumDec self, float Value) { return self <= (MediumDec)Value; }
        //friend bool operator>(MediumDec self, float Value) { return self > (MediumDec)Value; }
        //friend bool operator>=(MediumDec self, float Value) { return self >= (MediumDec)Value; }

        //friend bool operator==(float Value, MediumDec self) { return self == (MediumDec)Value; }
        //friend bool operator!=(float Value, MediumDec self) { return self != (MediumDec)Value; }
        //friend bool operator<(float Value, MediumDec self) { return (MediumDec)Value < self; }
        //friend bool operator<=(float Value, MediumDec self) { return self > (MediumDec)Value; }
        //friend bool operator>(float Value, MediumDec self) { return (MediumDec)Value > self; }
        //friend bool operator>=(float Value, MediumDec self) { return self < (MediumDec)Value; }

        //friend bool operator==(MediumDec self, double Value) { return self == (MediumDec)Value; }
        //friend bool operator!=(MediumDec self, double Value) { return self != (MediumDec)Value; }
        //friend bool operator<(MediumDec self, double Value) { return self < (MediumDec)Value; }
        //friend bool operator<=(MediumDec self, double Value) { return self <= (MediumDec)Value; }
        //friend bool operator>(MediumDec self, double Value) { return self > (MediumDec)Value; }
        //friend bool operator>=(MediumDec self, double Value) { return self >= (MediumDec)Value; }

        //friend bool operator==(double Value, MediumDec self) { return self == (MediumDec)Value; }
        //friend bool operator!=(double Value, MediumDec self) { return self != (MediumDec)Value; }
        //friend bool operator<(double Value, MediumDec self) { return (MediumDec)Value < self; }
        //friend bool operator<=(double Value, MediumDec self) { return self > (MediumDec)Value; }
        //friend bool operator>(double Value, MediumDec self) { return (MediumDec)Value > self; }
        //friend bool operator>=(double Value, MediumDec self) { return self < (MediumDec)Value; }
    #pragma endregion Other Comparison Operators
    #pragma region MediumDec-To-Int Comparison Operators
        /// <summary>
        /// Equality Operation between <see cref="MediumDec &"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(MediumDec self, IntType Value)
        {
            return (self.IntValue == Value && self.DecimalHalf01 == 0);
        }

        /// <summary>
        /// != Operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(MediumDec self, IntType Value)
        {
            if (self.DecimalHalf01 > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf01 == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(MediumDec self, IntType Value)
        {
            if (self.DecimalHalf01 == 0)
            {
                return self.IntValue < Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5<0
                    if (Value >= 0)
                        return true;
                }
                else if (self.IntValue < Value) { return true; }//5.5 < 6
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//-5.5<-5 vs 5.5 > 5
            }
            return false;
        }
        /// <summary>
        /// Lesser than or equal to operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(MediumDec self, IntType Value)
        {
            if (self.DecimalHalf01 == 0)
            {
                return self.IntValue <= Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5<0
                    if (Value >= 0)
                        return true;
                }
                else if (self.IntValue < Value) { return true; }//5.5<=6
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }
            }
            return false;
        }
        /// <summary>
        /// Greater than operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(MediumDec self, IntType Value)
        {
            if (self.DecimalHalf01 == 0)
            {
                return self.IntValue > Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5>-1
                    if (Value <= -1)
                        return true;
                }
                else if (self.IntValue > Value) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }
            }
            return false;
        }
        /// <summary>
        /// Greater than or equal to operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(MediumDec self, IntType Value)
        {
            if (self.DecimalHalf01 == 0)
            {
                return self.IntValue >= Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value <= -1)
                        return true;
                }
                else if (self.IntValue > Value) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//-5.5<-5 vs 5.5>5
            }
            return false;
        }

        /// <summary>
        /// Equality Operation between Integer Type and <see cref="MediumDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(IntType Value, MediumDec self)
        {
            return (self.IntValue == Value && self.DecimalHalf01 == 0);
        }

        /// <summary>
        /// != Operation between Integer Type and <see cref="MediumDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(IntType Value, MediumDec self)
        {
            if (self.DecimalHalf01 > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf01 == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between Integer Type and <see cref="MediumDec"/> .
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(IntType Value, MediumDec self)
        {
            if (self.DecimalHalf01 == 0)
            {
                return Value < self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value <= -1)
                        return true;
                }
                else if (Value < self.IntValue) { return true; }// 5 < 6.5
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//5 < 5.5 vs -5 > -5.5
            }
            return false;
        }
        /// <summary>
        /// Lesser than or equal to operation between Integer Type and <see cref="MediumDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(IntType Value, MediumDec self)
        {
            if (self.DecimalHalf01 == 0)
            {
                return Value <= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero && Value <= 1)
                {//-1<-0.5
                    if (Value <= -1)
                        return true;
                }
                else if (Value < self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//5 <= 5.5 vs -5 >= -5.5
            }
            return false;
        }
        /// <summary>
        /// Greater than operation between Integer Type and <see cref="MediumDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(IntType Value, MediumDec self)
        {
            if (self.DecimalHalf01 == 0)
            {
                return Value > self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value >= 0)
                        return true;
                }
                else if (Value > self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//5 < 5.5 vs -5 > -5.5
            }
            return false;
        }
        /// <summary>
        /// Greater than or equal to operation between <see cref="MediumDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(IntType Value, MediumDec self)
        {
            if (self.DecimalHalf01 == 0)
            {
                return Value >= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//0>-0.5
                    if (Value >= 0)
                        return true;
                }
                else if (Value > self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//5 <= 5.5 vs -5 >= -5.5
            }
            return false;
        }

    #pragma endregion MediumDec-To-Int Comparison Operators
    #pragma region Other Operations
        friend MediumDec operator+(MediumDec self, float Value) { return self + (MediumDec)Value; }
        friend MediumDec operator-(MediumDec self, float Value) { return self - (MediumDec)Value; }
        friend MediumDec operator*(MediumDec self, float Value) { return self * (MediumDec)Value; }
        friend MediumDec operator/(MediumDec self, float Value) { return self / (MediumDec)Value; }
        friend MediumDec operator%(MediumDec self, float Value) { return self % (MediumDec)Value; }
        friend MediumDec operator^(MediumDec self, float Value) { return self ^ (MediumDec)Value; }
        friend MediumDec operator|(MediumDec self, float Value) { return self | (MediumDec)Value; }
        friend MediumDec operator&(MediumDec self, float Value) { return self & (MediumDec)Value; }

        friend MediumDec operator+(float Value, MediumDec self) { return (MediumDec)Value + self; }
        friend MediumDec operator-(float Value, MediumDec self) { return (MediumDec)Value - self; }
        friend MediumDec operator*(float Value, MediumDec self) { return (MediumDec)Value * self; }
        friend MediumDec operator/(float Value, MediumDec self) { return (MediumDec)Value / self; }
        friend MediumDec operator%(float Value, MediumDec self) { return (MediumDec)Value % self; }
        friend MediumDec operator^(float Value, MediumDec self) { return (MediumDec)Value ^ self; }
        friend MediumDec operator|(float Value, MediumDec self) { return (MediumDec)Value | self; }
        friend MediumDec operator&(float Value, MediumDec self) { return (MediumDec)Value & self; }

        friend MediumDec operator+(MediumDec self, double Value) { return self + (MediumDec)Value; }
        friend MediumDec operator-(MediumDec self, double Value) { return self - (MediumDec)Value; }
        friend MediumDec operator*(MediumDec self, double Value) { return self * (MediumDec)Value; }
        friend MediumDec operator/(MediumDec self, double Value) { return self / (MediumDec)Value; }
        friend MediumDec operator%(MediumDec self, double Value) { return self % (MediumDec)Value; }
        friend MediumDec operator^(MediumDec self, double Value) { return self ^ (MediumDec)Value; }
        friend MediumDec operator|(MediumDec self, double Value) { return self | (MediumDec)Value; }
        friend MediumDec operator&(MediumDec self, double Value) { return self & (MediumDec)Value; }

        friend MediumDec operator+(double Value, MediumDec self) { return (MediumDec)Value + self; }
        friend MediumDec operator-(double Value, MediumDec self) { return (MediumDec)Value - self; }
        friend MediumDec operator*(double Value, MediumDec self) { return (MediumDec)Value * self; }
        friend MediumDec operator/(double Value, MediumDec self) { return (MediumDec)Value / self; }
        friend MediumDec operator%(double Value, MediumDec self) { return (MediumDec)Value % self; }
        friend MediumDec operator^(double Value, MediumDec self) { return (MediumDec)Value ^ self; }
        friend MediumDec operator|(double Value, MediumDec self) { return (MediumDec)Value | self; }
        friend MediumDec operator&(double Value, MediumDec self) { return (MediumDec)Value & self; }

        friend MediumDec operator+(MediumDec self, ldouble Value) { return self + (MediumDec)Value; }
        friend MediumDec operator-(MediumDec self, ldouble Value) { return self - (MediumDec)Value; }
        friend MediumDec operator*(MediumDec self, ldouble Value) { return self * (MediumDec)Value; }
        friend MediumDec operator/(MediumDec self, ldouble Value) { return self / (MediumDec)Value; }
        friend MediumDec operator%(MediumDec self, ldouble Value) { return self % (MediumDec)Value; }
        friend MediumDec operator^(MediumDec self, ldouble Value) { return self ^ (MediumDec)Value; }
        friend MediumDec operator|(MediumDec self, ldouble Value) { return self | (MediumDec)Value; }
        friend MediumDec operator&(MediumDec self, ldouble Value) { return self & (MediumDec)Value; }

        friend MediumDec operator+(ldouble Value, MediumDec self) { return (MediumDec)Value + self; }
        friend MediumDec operator-(ldouble Value, MediumDec self) { return (MediumDec)Value - self; }
        friend MediumDec operator*(ldouble Value, MediumDec self) { return (MediumDec)Value * self; }
        friend MediumDec operator/(ldouble Value, MediumDec self) { return (MediumDec)Value / self; }
        friend MediumDec operator%(ldouble Value, MediumDec self) { return (MediumDec)Value % self; }
        friend MediumDec operator^(ldouble Value, MediumDec self) { return (MediumDec)Value ^ self; }
        friend MediumDec operator|(ldouble Value, MediumDec self) { return (MediumDec)Value | self; }
        friend MediumDec operator&(ldouble Value, MediumDec self) { return (MediumDec)Value & self; }

    #pragma endregion Other Operations
    #pragma region MediumDec-To-Integer Operations
    public:
        /// <summary>
        /// Addition Operation Between MediumDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& AddOp(MediumDec& self, IntType& value)
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
        /// Subtraction Operation Between MediumDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        static MediumDec& SubOp(MediumDec& self, IntType& value)
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
                else if(value>0)
                    self.IntValue = value - 1;
                else
                    self.IntValue += value;
            }
            else if(self.IntValue<0)
            {
                if(value<self.IntValue)//-4.5 - -5.5
                    self.IntValue -= value + 1;
                else if(value==self.IntValue)
                    self.IntValue = NegativeZero; //-1.5 + 1 = -0.5
                else
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
        /// Multiplication Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        static MediumDec& MultOp(MediumDec& self, IntType& Value)
        {
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
            if (self == Zero) {}
            else if (Value == 0) { self.IntValue = 0; self.DecimalHalf01 = 0; }
            else if (self.DecimalHalf01 == 0)
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
        /// Division Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& DivOp(MediumDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            else if (self == Zero) { return self; }
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
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
            if (self == Zero) { return JustAboveZero; }//Prevent dividing into nothing
            return self;
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& RemOp(MediumDec& self, IntType& Value)
        {
            if (Value == 0 || self == MediumDec::Zero) { return MediumDec::Zero; }
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

        /// <summary>
        /// Addition Operation Between MediumDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& UnsignedAddOp(MediumDec& self, IntType& value)
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
        /// Subtraction Operation Between MediumDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        static MediumDec& UnsignedSubOp(MediumDec& self, IntType& value)
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
        /// Multiplication Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        static MediumDec& UnsignedMultOp(MediumDec& self, IntType& Value)
        {
            if (self == Zero) {}
            else if (Value == 0) { self.IntValue = 0; self.DecimalHalf01 = 0; }
            else if (self.DecimalHalf01 == 0)
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
        /// Division Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& UnsignedDivOp(MediumDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            else if (self == Zero) { return self; }
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
        /// Remainder/Modulus Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec&</returns>
        template<typename IntType>
        static MediumDec& UnsignedRemOp(MediumDec& self, IntType& Value)
        {
            if(self == MediumDec::Zero) { return self; }
            if (Value == 0){ self.IntValue=0; self.DecimalHalf01 = 0; return self; }
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
     //   static MediumDec& SignedModulusOp(MediumDec& self, IntType& Value)
     //   {
        //}
    public:
        friend MediumDec operator+(MediumDec self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-(MediumDec self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*(MediumDec self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/(MediumDec self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%(MediumDec self, unsigned char Value){ return UnsignedRemOp(self, Value); }
        
        friend MediumDec operator+=(MediumDec& self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-=(MediumDec& self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*=(MediumDec& self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/=(MediumDec& self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%=(MediumDec& self, unsigned char Value){ return UnsignedRemOp(self, Value); }

        friend MediumDec operator+(MediumDec self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-(MediumDec self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*(MediumDec self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/(MediumDec self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%(MediumDec self, unsigned short Value){ return UnsignedRemOp(self, Value); }
        
        friend MediumDec operator+=(MediumDec& self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-=(MediumDec& self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*=(MediumDec& self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/=(MediumDec& self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%=(MediumDec& self, unsigned short Value){ return UnsignedRemOp(self, Value); }

        friend MediumDec operator+(MediumDec self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-(MediumDec self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*(MediumDec self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/(MediumDec self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%(MediumDec self, unsigned int Value){ return UnsignedRemOp(self, Value); }
        
        friend MediumDec operator+=(MediumDec& self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-=(MediumDec& self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*=(MediumDec& self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/=(MediumDec& self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%=(MediumDec& self, unsigned int Value){ return UnsignedRemOp(self, Value); }
        
        //friend MediumDec operator+=(MediumDec* self, unsigned int Value) { return UnsignedAddOp(**self, Value); }
        //friend MediumDec operator-=(MediumDec* self, unsigned int Value) { return UnsignedSubOp(**self, Value); }
        //friend MediumDec operator*=(MediumDec* self, unsigned int Value) { return UnsignedMultOp(**self, Value); }
        //friend MediumDec operator/=(MediumDec* self, unsigned int Value) { return UnsignedDivOp(**self, Value); }
        //friend MediumDec operator%=(MediumDec* self, unsigned int Value) { return UnsignedRemOp(**self, Value); }

        friend MediumDec operator+(MediumDec self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-(MediumDec self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*(MediumDec self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/(MediumDec self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%(MediumDec self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }
        
        friend MediumDec operator+=(MediumDec& self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend MediumDec operator-=(MediumDec& self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend MediumDec operator*=(MediumDec& self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend MediumDec operator/=(MediumDec& self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend MediumDec operator%=(MediumDec& self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }

     //   friend MediumDec operator+=(MediumDec* self, unsigned __int64 Value){ return UnsignedAddOp(**self, Value); }
        //friend MediumDec operator-=(MediumDec* self, unsigned __int64 Value){ return UnsignedSubOp(**self, Value); }
     //   friend MediumDec operator*=(MediumDec* self, unsigned __int64 Value){ return UnsignedMultOp(**self, Value); }
        //friend MediumDec operator/=(MediumDec* self, unsigned __int64 Value){ return UnsignedDivOp(**self, Value); }
     //   friend MediumDec operator%=(MediumDec* self, unsigned __int64 Value){ return UnsignedRemOp(**self, Value); }

        /// <summary>
        /// Addition Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator+(MediumDec self, IntType Value)
        {
            return AddOp(self, Value);
        }

        ///// <summary>
        ///// += Operation Between MediumDec and Integer Value
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator+=(MediumDec& self, IntType Value)
        {
            return AddOp(self, Value);
        }

        template<typename IntType>
        friend MediumDec operator+=(MediumDec* self, IntType Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator-(MediumDec self, IntType Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator-=(MediumDec& self, IntType Value)
        {
            return SubOp(self, Value);
        }

        template<typename IntType>
        friend MediumDec operator-=(MediumDec* self, IntType Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator*(MediumDec self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator*=(MediumDec& self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between MediumDec and Integer Value (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator*=(MediumDec* self, IntType Value){ return MultOp(**self, Value); }

        /// <summary>
        /// Division Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator/(MediumDec self, IntType Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator/=(MediumDec& self, IntType Value)
        {
            return DivOp(self, Value);
        }

        template<typename IntType>
        friend MediumDec operator/=(MediumDec* self, IntType Value){ return DivOp(**self, Value); }
        
        /// <summary>
        /// Modulus Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator%(MediumDec self, IntType Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator%=(MediumDec& self, IntType Value)
        {
            return RemOp(self, Value);
        }

        template<typename IntType>
        friend MediumDec operator%=(MediumDec* self, IntType Value){ return RemOp(**self, Value); }

        /// <summary>
        /// Bitwise XOR Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator^(MediumDec self, IntType Value)
        {
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
        /// Bitwise Or Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator|(MediumDec self, IntType Value)
        {
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
        /// Bitwise And Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator&(MediumDec self, IntType Value)
        {
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
    #pragma endregion MediumDec-To-Integer Operations
    #pragma region Integer-To-MediumDec Operations
        /// <summary>
        /// Addition Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator+(IntType Value, MediumDec self)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// Subtraction Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator-(IntType Value, MediumDec self)
        {
            MediumDec Result = Value;
            return SubOp(Result, self);
        }

        /// <summary>
        /// Multiplication Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator*(IntType Value, MediumDec self)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// Division Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator/(IntType Value, MediumDec self)
        {
            MediumDec Result = Value;
            return DivOp(Result, self);
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator%(IntType Value, MediumDec self)
        {
            MediumDec Result = Value;
            return RemOp(Result, self);
        }

        /// <summary>
        /// Bitwise XOR Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator^(IntType Value, MediumDec self)
        {
            return (MediumDec)Value ^ self;
        }
        /// <summary>
        /// Bitwise Or Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator|(IntType Value, MediumDec self)
        {
            return (MediumDec)Value | self;
        }
        /// <summary>
        /// Bitwise And Operation Between MediumDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        template<typename IntType>
        friend MediumDec operator&(IntType Value, MediumDec self)
        {
            return (MediumDec)Value & self;
        }
    #pragma endregion Integer-To-MediumDec Operations
    #pragma region Math/Trigonomic Etc Functions
        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <returns>MediumDec&</returns>
        MediumDec& Floor()
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
            return *this;
        }

        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>MediumDec&</returns>
        static MediumDec Floor(MediumDec Value)
        {
            return Value.Floor();
        }
        
        /// <summary>
        /// Returns floored value with all fractional digits after specified precision cut off.
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <param name="precision">The precision.</param>
        static MediumDec Floor(MediumDec Value, int precision)
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
        /// Returns the smallest integer that is greater than or equal to Value (Rounds up to integer value).
        /// </summary>
        /// <returns>MediumDec&</returns>
        MediumDec& Ceil()
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
            return *this;
        }

        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <returns>MediumDec&</returns>
        static int FloorInt(MediumDec Value)
        {
            if (Value.DecimalHalf01 == 0)
            {
                return Value.IntValue;
            }
            if (Value.IntValue == NegativeZero) { return -1; }
            else
            {
                return Value.IntValue - 1;
            }
        }

        /// <summary>
        /// Returns the smallest integer that is greater than or equal to Value (Rounds up to integer value).
        /// </summary>
        /// <returns>MediumDec&</returns>
        static int CeilInt(MediumDec Value)
        {
            if (Value.DecimalHalf01 == 0)
            {
                return Value.IntValue;
            }
            if (Value.IntValue == NegativeZero) { return 0; }
            else
            {
                return Value.IntValue+1;
            }
        }
        
        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Ceil(MediumDec Value)
        {
            return Value.Ceil();
        }
        
        /// <summary>
        /// Cuts off the decimal point from number
        /// </summary>
        /// <returns>MediumDec &</returns>
        MediumDec& Trunc()
        {
            DecimalHalf01 = 0;
            if (IntValue == NegativeZero) { IntValue = 0; }
            return *this;
        }
        
        /// <summary>
        /// Cuts off the decimal point from number
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Trunc(MediumDec Value)
        {
            return Value.Trunc();
        }
        
        /// <summary>
        /// Forces Number into non-negative
        /// </summary>
        /// <returns>MediumDec&</returns>
        MediumDec& Abs()
        {
            if (IntValue == NegativeZero) { IntValue = 0; }
            else if (IntValue < 0) { IntValue *= -1; }
            return *this;
        }
        
        /// <summary>
        /// Forces Number into non-negative
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Abs(MediumDec Value)
        {
            return Value.Abs();
        }

        /// <summary>
        /// Applies Power of operation on references(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        MediumDec PowOp(ValueType& expValue)
        {
            if (expValue == 1) { return *this; }//Return self
            else if (expValue == 0)
            { 
                IntValue = 1; DecimalHalf01 = 0;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (DecimalHalf01 == 0 && IntValue == 10 && expValue >= -9)
                {
                    IntValue = 0; DecimalHalf01 = DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1];
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    MediumDec self = *this;
                    IntValue = 1; DecimalHalf01 = 0;// Initialize result
                    while (expValue > 0)
                    {
                        // If expValue is odd, multiply self with result
                        if (expValue % 2 == 1)
                            *this /= self;
                        // n must be even now
                        expValue = expValue >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return this;
                }
            }
            else if (DecimalHalf01 == 0 && IntValue == 10)
                IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            else if (DecimalHalf01 == 0 && IntValue == -10)
                IntValue = expValue % 2 ? VariableConversionFunctions::PowerOfTens[expValue] : VariableConversionFunctions::PowerOfTens[expValue] * -1;
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                MediumDec self = *this;
                IntValue = 1; DecimalHalf01 = 0;// Initialize result
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
            return *this;
        }

        /// <summary>
        /// Applies Power of operation on references with const expValue(for integer exponents)(C3892 fix)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        MediumDec PowConstOp(const ValueType& expValue)
        {
            if (expValue == 1) { return *this; }//Return self
            else if (expValue == 0)
            {
                IntValue = 1; DecimalHalf01 = 0;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (DecimalHalf01 == 0 && IntValue == 10 && expValue >= -9)
                {
                    int expVal = expValue * -1;
                    IntValue = 0; DecimalHalf01 = DecimalOverflow / VariableConversionFunctions::PowerOfTens[expVal];
                }
                else
                {
                    int expVal = expValue;
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expVal *= -1;
                    MediumDec self = *this;
                    IntValue = 1; DecimalHalf01 = 0;// Initialize result
                    while (expVal > 0)
                    {
                        // If expValue is odd, multiply self with result
                        if (expVal % 2 == 1)
                            *this /= self;
                        // n must be even now
                        expVal = expVal >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return this;
                }
            }
            else if (DecimalHalf01 == 0 && IntValue == 10)
            {
                IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            }
            else
            {
                int expVal = expValue;
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                MediumDec self = *this;
                IntValue = 1; DecimalHalf01 = 0;// Initialize result
                while (expVal > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expVal % 2 == 1)
                        this *= self;
                    // n must be even now
                    expVal = expVal >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
            }
            return *this;
        }

        /// <summary>
        /// Applies Power of operation on references with const expValue(for integer exponents)(C3892 fix)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static MediumDec PowConstOp(MediumDec& targetValue, const ValueType& expValue)
        {
            return targetValue.PowConstOp(expValue);
        }

        /// <summary>
        /// Applies Power of operation on references(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static MediumDec PowOp(MediumDec& targetValue, ValueType& expValue)
        {
            return targetValue.PowOp(expValue);
        }
        
        /// <summary>
        /// Applies Power of operation(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        MediumDec Pow(ValueType expValue)
        {
            return this->PowOp(expValue);
        }

        /// <summary>
        /// Applies Power of operation (for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static MediumDec Pow(MediumDec targetValue, ValueType expValue)
        {
            if (expValue == 1) { return targetValue; }//Return self
            else if (expValue == 0)
            {
                targetValue.IntValue = 1; targetValue.DecimalHalf01 = 0;
                return targetValue;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (targetValue.DecimalHalf01 == 0 && targetValue.IntValue == 10 && expValue >= -9)
                {
                    targetValue.IntValue = 0; targetValue.DecimalHalf01 = MediumDec::DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1];
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    MediumDec self = targetValue;
                    targetValue.IntValue = 1; targetValue.DecimalHalf01 = 0;// Initialize result
                    while (expValue > 0)
                    {
                        // If expValue is odd, multiply self with result
                        if (expValue % 2 == 1)
                            targetValue /= self;
                        // n must be even now
                        expValue = expValue >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return targetValue;
                }
            }
            else if (targetValue.DecimalHalf01 == 0 && targetValue.IntValue == 10)
            {
                targetValue.IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            }
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                MediumDec self = targetValue;
                targetValue.IntValue = 1; targetValue.DecimalHalf01 = 0;// Initialize result
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        targetValue *= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
            }
            return targetValue;
        }

        /// <summary>
        /// Applies Power of operation (for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static MediumDec PowRef(MediumDec& targetValue, ValueType expValue)
        {
            if (expValue == 1)
                return targetValue;//Return self
            else if (expValue == 0)
                return MediumDec::One;
            else if (expValue < 0)//Negative Pow
            {
                if (targetValue.DecimalHalf01 == 0 && targetValue.IntValue == 10 && expValue >= -9)
                {
                    return MediumDec(0, MediumDec::DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1]);
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    MediumDec self = targetValue;
                    MediumDec Result = MediumDec::One;
                    while (expValue > 0)
                    {
                        // If expValue is odd, divide self with result
                        if (expValue % 2 == 1)
                            Result /= self;
                        // n must be even now
                        expValue = expValue >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return Result;
                }
            }
            else if (targetValue.DecimalHalf01 == 0 && targetValue.IntValue == 10)
                return MediumDec(VariableConversionFunctions::PowerOfTens[expValue], 0);
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                MediumDec self = targetValue;
                MediumDec Result = MediumDec::One;
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        Result *= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
                return Result;
            }
            return targetValue;
        }

        /// <summary>
        /// Perform square root on this instance.(Code other than switch statement from https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/)
        /// </summary>
        static MediumDec Sqrt(MediumDec value, int precision=7)
        {
            if (value.DecimalHalf01 == 0)
            {
                bool AutoSetValue = true;
                switch (value.IntValue)
                {
                case 1: value.IntValue = 1; break;
                case 4: value.IntValue = 2; break;
                case 9: value.IntValue = 3; break;
                case 16: value.IntValue = 4; break;
                case 25: value.IntValue = 5; break;
                case 36: value.IntValue = 6; break;
                case 49: value.IntValue = 7; break;
                case 64: value.IntValue = 8; break;
                case 81: value.IntValue = 9; break;
                case 100: value.IntValue = 10; break;
                case 121: value.IntValue = 11; break;
                case 144: value.IntValue = 12; break;
                case 169: value.IntValue = 13; break;
                case 196: value.IntValue = 14; break;
                case 225: value.IntValue = 15; break;
                case 256: value.IntValue = 16; break;
                case 289: value.IntValue = 17; break;
                case 324: value.IntValue = 18; break;
                case 361: value.IntValue = 19; break;
                case 400: value.IntValue = 20; break;
                default:
                    AutoSetValue = false;
                    break;
                }
                if(AutoSetValue)
                {
                    return value;
                }
            }
            MediumDec number = value;
            MediumDec start = 0, end = number;
            MediumDec mid;

            // variable to store the answer 
            MediumDec ans;

            // for computing integral part 
            // of square root of number 
            while (start <= end) {
                mid = (start + end) / 2;
                if (mid * mid == number) {
                    ans = mid;
                    break;
                }

                // incrementing start if integral 
                // part lies on right side of the mid 
                if (mid * mid < number) {
                    start = mid + 1;
                    ans = mid;
                }

                // decrementing end if integral part 
                // lies on the left side of the mid 
                else {
                    end = mid - 1;
                }
            }

            // For computing the fractional part 
            // of square root up to given precision 
            MediumDec increment = "0.1";
            for (int i = 0; i < precision; i++) {
                while (ans * ans <= number) {
                    ans += increment;
                }

                // loop terminates when ans * ans > number 
                ans = ans - increment;
                increment = increment / 10;
            }
            return ans;
        }

        /// <summary>
        /// Finds nTh Root of value based on https://www.geeksforgeeks.org/n-th-root-number/ code
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="nValue">The nth value.</param>
        /// <param name="precision">Precision level (smaller = more precise)</param>
        /// <returns>MediumDec</returns>
        static MediumDec NthRoot(MediumDec value, int n, MediumDec precision = MediumDec::JustAboveZero)
        {
            MediumDec xPre = 1+(value-1)/n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method
            int nMinus1 = n - 1;

            // initializing difference between two 
            // roots by INT_MAX 
            MediumDec delX = MediumDec(2147483647, 0);

            //  xK denotes current value of x 
            MediumDec xK;

            //  loop until we reach desired accuracy
            do
            {
                //  calculating current value from previous
                // value by newton's method
                xK = (nMinus1 * xPre +
                    value / MediumDec::Pow(xPre, nMinus1)) / n;
                delX = MediumDec::Abs(xK - xPre);
                xPre = xK;
            } while (delX > precision);
            return xK;
        }

        /// <summary>
        /// Get the (n)th Root
        /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
        /// </summary>
        /// <param name="n">The n value to apply with root.</param>
        /// <returns></returns>
        static MediumDec NthRootV2(MediumDec targetValue, int n, MediumDec& Precision = MediumDec::FiveBillionth)
        {
            int nMinus1 = n - 1;
            MediumDec x[2] = { (MediumDec::One / n) * ((nMinus1 * targetValue) + (targetValue / MediumDec::Pow(targetValue, nMinus1))), targetValue };
            while (MediumDec::Abs(x[0] - x[1]) > Precision)
            {
                x[1] = x[0];
                x[0] = (MediumDec::One / n) * ((nMinus1 * x[1]) + (targetValue / MediumDec::Pow(x[1], nMinus1)));
            }
            return x[0];
        }

        /// <summary>
        /// Taylor Series Exponential function derived from https://www.pseudorandom.com/implementing-exp
        /// </summary>
        /// <param name="x">The value to apply the exponential function to.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Exp(MediumDec x)
        {
            /*
             * Evaluates f(x) = e^x for any x in the interval [-709, 709].
             * If x < -709 or x > 709, raises an assertion error. Implemented
             * using the truncated Taylor series of e^x with ceil(|x| * e) * 12
             * terms. Achieves at least 14 and at most 16 digits of precision
             * over the entire interval.
             * Performance - There are exactly 36 * ceil(|x| * e) + 5
             * operations; 69,413 in the worst case (x = 709 or -709):
             * - (12 * ceil(|x| * e)) + 2 multiplications
             * - (12 * ceil(|x| * e)) + 1 divisions
             * - (12 * ceil(|x| * e)) additions
             * - 1 rounding
             * - 1 absolute value
             * Accuracy - Over a sample of 10,000 linearly spaced points in
             * [-709, 709] we have the following error statistics:
             * - Max relative error = 8.39803e-15
             * - Min relative error = 0.0
             * - Avg relative error = 0.0
             * - Med relative error = 1.90746e-15
             * - Var relative error = 0.0
             * - 0.88 percent of the values have less than 15 digits of precision
             * Args:
             *      - x: (MediumDec float) power of e to evaluate
             * Returns:
             *      - (MediumDec float) approximation of e^x in MediumDec precision
             */
             // Check that x is a valid input.
            assert(-709 <= x.IntValue && x.IntValue <= 709);
            // When x = 0 we already know e^x = 1.
            if (x == MediumDec::Zero) {
                return MediumDec::One;
            }
            // Normalize x to a non-negative value to take advantage of
            // reciprocal symmetry. But keep track of the original sign
            // in case we need to return the reciprocal of e^x later.
            MediumDec x0 = MediumDec::Abs(x);
            // First term of Taylor expansion of e^x at a = 0 is 1.
            // tn is the variable we we will return for e^x, and its
            // value at any time is the sum of all currently evaluated
            // Taylor terms thus far.
            MediumDec tn = MediumDec::One;
            // Chose a truncation point for the Taylor series using the
            // heuristic bound 12 * ceil(|x| e), then work down from there
            // using Horner's method.
            int n = MediumDec::CeilInt(x0 * MediumDec::E) * 12;
            for (int i = n; i > 0; --i) {
                tn = tn * (x0 / i) + MediumDec::One;
            }
            // If the original input x is less than 0, we want the reciprocal
            // of the e^x we calculated.
            if (x < 0) {
                tn = MediumDec::One / tn;
            }
            return tn;
        }

        /// <summary>
        /// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expNum">The numerator of the exponent value.</param>
        /// <param name="expDenom">The denominator of the exponent value.</param>
        static MediumDec FractionalPow(MediumDec value, int expNum, int expDenom)
        {
            MediumDec CalcVal = MediumDec::NthRoot(MediumDec::Pow(value, expNum), expDenom);
            return CalcVal;
        }

        /// <summary>
        /// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="Frac">The exponent value to raise the value to power of.</param>
        static MediumDec FractionalPow(MediumDec& value, boost::rational<int>& Frac)
        {
            MediumDec CalcVal = MediumDec::NthRoot(MediumDec::Pow(value, Frac.numerator()), Frac.denominator());
            return CalcVal;
        }

        /// <summary>
        /// Applies Power of operation
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expValue">The exponent value.</param>
        static MediumDec PowOp(MediumDec& value, MediumDec& expValue)
        {
            if (expValue.DecimalHalf01 == 0)
            {
                return value.Pow(expValue.IntValue);
            }
            else
            {
                boost::rational<int> Frac = boost::rational<int>(expValue.DecimalHalf01, MediumDec::DecimalOverflow);
                switch (expValue.IntValue)
                {
                    case 0:
                        return FractionalPow(value, Frac);
                        break;
                    case MediumDec::NegativeZero:
                        return 1 / FractionalPow(value, Frac);
                        break;
                    default:
                    {
                        if (expValue.IntValue < 0)//Negative Exponent 
                        {
                            MediumDec CalcVal = 1 / value.Pow(expValue.IntValue * -1);
                            CalcVal /= FractionalPow(value, Frac);
                            return CalcVal;
                        }
                        else
                        {
                            MediumDec CalcVal = value.Pow(expValue.IntValue);
                            CalcVal *= FractionalPow(value, Frac);
                            return CalcVal;
                        }
                        break;
                    }
                }
            }
        }

        /// <summary>
        /// Applies Power of operation
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expValue">The exponent value.</param>
        static MediumDec Pow(MediumDec value, MediumDec expValue)
        {
            return PowOp(value, expValue);
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="threshold">The threshold value for when value is between 0 and 2.</param>
        /// <returns>BlazesRusCode::MediumDec</returns>
        static MediumDec LnRef(MediumDec& value, MediumDec threshold)
        {
            //if (value <= 0) {}else//Error if equal or less than 0
            if (value == MediumDec::One)
                return MediumDec::Zero;
            else if (value.IntValue < 2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer
                MediumDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 1;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                MediumDec term = base;       // First term
                MediumDec prev = 0;          // Previous sum
                MediumDec result = term;     // Kick it off

                while (MediumDec::Abs(prev - result) > threshold) {
                    den++;
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                }

                return result;
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {//Increasing iterations brings closer to accurate result(Larger numbers need more iterations to get accurate level of result)
                MediumDec W = (value - 1) / (value + 1);
                MediumDec TotalRes = W;
                MediumDec AddRes;
                //for (int WPow = 3; AddRes > MediumDec::JustAboveZero; WPow += 2)
                int WPow = 3;
                do
                {
                    AddRes = MediumDec::PowRef(W, WPow) / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > MediumDec::JustAboveZero);
                return TotalRes * 2;
            }
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <returns>BlazesRusCode::MediumDec</returns>
        static MediumDec LnRef(MediumDec& value)
        {
            //if (value <= 0) {}else//Error if equal or less than 0
            if (value == MediumDec::One)
                return MediumDec::Zero;
            else if (value.IntValue < 2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer
                MediumDec threshold = MediumDec::FiveMillionth;
                MediumDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 1;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                MediumDec term = base;       // First term
                MediumDec prev = 0;          // Previous sum
                MediumDec result = term;     // Kick it off

                while (MediumDec::Abs(prev - result) > threshold) {
                    den++;
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                }

                return result;
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {//Increasing iterations brings closer to accurate result(Larger numbers need more iterations to get accurate level of result)
                MediumDec W = (value - 1) / (value + 1);
                MediumDec TotalRes = W;
                MediumDec AddRes;
                //for (int WPow = 3; AddRes > MediumDec::JustAboveZero; WPow += 2)
                int WPow = 3;
                do
                {
                    AddRes = MediumDec::PowRef(W, WPow) / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > MediumDec::JustAboveZero);
                return TotalRes * 2;
            }
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        static MediumDec Ln(MediumDec value, MediumDec threshold)
        {
            return LnRef(value, threshold);
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        static MediumDec Ln(MediumDec value)
        {
            return LnRef(value);
        }
    #pragma endregion Math Etc Functions
    #pragma region Trigonomic Etc Functions
        /// <summary>
        /// Get Sin from Value of angle.
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        static MediumDec SinFromAngle(MediumDec Value)
        {
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
            if (Value == Zero) { return MediumDec::Zero; }
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
                return MediumDec::Zero;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
            {
                return NegativeOne;
            }
            else
            {
                MediumDec NewValue = Zero;
                //Angle as Radian
                MediumDec Radius = PI * Value / 180;
                for (int i = 0; i < 7; ++i)
                { // That's Taylor series!!
                    NewValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Radius, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
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
        static MediumDec CosFromAngle(MediumDec Value)
        {
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
                return MediumDec::Zero;
            }
            else if (Value.IntValue == 180 && Value.DecimalHalf01 == 0)
            {
                return NegativeOne;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
            {
                return MediumDec::Zero;
            }
            else
            {
                MediumDec NewValue = Zero;
                //Angle as Radian
                MediumDec Radius = PI * Value / 180;
                for (int i = 0; i < 7; ++i)
                { // That's also Taylor series!!
                    NewValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Radius, 2 * i) / VariableConversionFunctions::Fact(2 * i);
                }
                return NewValue;
            }
        }

        /// <summary>
        /// Get Sin from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Sin(MediumDec Value)
        {
            MediumDec SinValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                SinValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            return SinValue;
        }

        /// <summary>
        /// Get Sin from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Cos(MediumDec Value)
        {
            MediumDec CosValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                CosValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return CosValue;
        }

        /// <summary>
        /// Get Tan from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>MediumDec</returns>
        static MediumDec Tan(MediumDec Value)
        {
            MediumDec SinValue = Zero;
            MediumDec CosValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                SinValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            for (int i = 0; i < 7; ++i)
            {
                CosValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return SinValue / CosValue;
        }

        /// <summary>
        /// Get Tangent from Value in Degrees (SlopeInPercent:http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>MediumDec</returns>
        static MediumDec TanFromAngle(MediumDec Value)
        {
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
            if (Value == Zero) { return MediumDec::Zero; }
            else if (Value.IntValue == 90 && Value.DecimalHalf01 == 0)
            {
                return MediumDec::Maximum;//Positive Infinity
            }
            else if (Value.IntValue == 180 && Value.DecimalHalf01 == 0)
            {
                return MediumDec::Zero;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf01 == 0)
            {
                return MediumDec::Minimum;//Negative Infinity
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
        /// <returns>MediumDec</returns>
        static MediumDec ATan(MediumDec Value)
        {
            MediumDec SinValue = Zero;
            MediumDec CosValue = Zero;
            //Angle as Radian
            for (int i = 0; i < 7; ++i)
            { // That's Taylor series!!
                SinValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            for (int i = 0; i < 7; ++i)
            { // That's also Taylor series!!
                CosValue += (i % 2 == 0 ? 1 : -1) * MediumDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
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
        /// <returns>MediumDec</returns>
        static MediumDec ArcTan2(MediumDec y, MediumDec x)
        {
            MediumDec coeff_1 = PI / 4;
            MediumDec coeff_2 = 3 * coeff_1;
            MediumDec abs_y = MediumDec::Abs(y) + JustAboveZero;// kludge to prevent 0/0 condition
            MediumDec r;
            MediumDec angle;
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
    #pragma endregion Math/Trigonomic Etc Functions
    };

    #pragma region ValueDefine Source
    MediumDec MediumDec::PI = PIValue();
    MediumDec MediumDec::One = OneValue();
    MediumDec MediumDec::Two = OneValue();
    MediumDec MediumDec::NegativeOne = NegativeOneValue();
    MediumDec MediumDec::Zero = ZeroValue();
    MediumDec MediumDec::PointFive = Point5Value();
    MediumDec MediumDec::JustAboveZero = JustAboveZeroValue();
    MediumDec MediumDec::OneMillionth = OneMillionthValue();
    MediumDec MediumDec::Minimum = MinimumValue();
    MediumDec MediumDec::Maximum = MaximumValue();
    MediumDec MediumDec::E = EValue();
    MediumDec MediumDec::LN10 = LN10Value();
    MediumDec MediumDec::TenMillionth = TenMillionthValue();
    MediumDec MediumDec::FiveMillionth = FiveMillionthValue();
    MediumDec MediumDec::FiveBillionth = FiveBillionthValue();
    MediumDec MediumDec::OneGMillionth = OneHundredMillionthValue();
    MediumDec MediumDec::Nil = NilValue();
    #pragma endregion ValueDefine Source

    #pragma region String Function Source
    /// <summary>
    /// Reads the string.
    /// </summary>
    /// <param name="Value">The value.</param>
    inline void MediumDec::ReadString(std::string Value)
    {
        IntValue = 0; DecimalHalf01 = 0;
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
    /// <returns>MediumDec</returns>
    inline MediumDec MediumDec::GetValueFromString(std::string Value)
    {
        MediumDec NewSelf = Zero;
        NewSelf.ReadString(Value);
        return NewSelf;
    }

    std::string MediumDec::ToString()
    {
        std::string Value = "";
        int CurrentSection = IntValue;
        unsigned __int8 CurrentDigit;
        std::string DecBuffer = "";
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
        if (DecimalHalf01 != 0)
        {
            Value += ".";
            CurrentSection = DecimalHalf01;
            for (__int8 Index = 8; Index >= 0; --Index)
            {
                CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
                CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
                if (CurrentDigit != 0)
                {
                    if(!DecBuffer.empty())
                    {
                        Value += DecBuffer;
                        DecBuffer.clear();
                    }
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
                else
                {
                    DecBuffer += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
            }
        }
        return Value;
    }

    std::string MediumDec::ToFullString()
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
        if (DecimalHalf01 != 0)
        {
            Value += ".";
            bool HasDigitsUsed = false;
            CurrentSection = DecimalHalf01;
            for (__int8 Index = 8; Index >= 0; --Index)
            {
                if (CurrentSection > 0)
                {
                    CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
                    CurrentSection -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
                else
                    Value += "0";
            }
        }
        else
        {
            Value += ".000000000";
        }
        return Value;
    }
    #pragma endregion String Function Source
}