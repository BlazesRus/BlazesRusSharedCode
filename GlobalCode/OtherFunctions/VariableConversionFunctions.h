#pragma once
#ifndef VariableConversionFunctions_IncludeGuard
#define VariableConversionFunctions_IncludeGuard

#include <string>
#include <stdint.h>

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

namespace BlazesRusCode
{
    /// <summary>
    /// Performs remainder/Mod operation then saves division result
    /// C = A – B * (A / B)
    /// </summary>
    class ModChecker
    {//based on https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/
    public:
        int divRes = 0;
        int C = 0;
        __int64 ExDivRes = 0;
        __int64 ExtC = 0;
        /// <summary>
        /// Calculates if remainder is zero.
        /// </summary>
        /// <param name="a">a.</param>
        /// <param name="b">The b.</param>
        /// <returns>bool</returns>
        bool CalcIfZero(int a, int b)
        {
            divRes = a / b;
            C = a - b * divRes;
            if (C == 0)
            {
                return true;
            }
            return false;
        }
        bool CalcIfZero(__int64 a, __int64 b)
        {
            ExDivRes = a / b;
            ExtC = ExtC - b * ExDivRes;
            if (ExtC == 0)
            {
                return true;
            }
            return false;
        }
        bool CalcIfZero(__int64 a, int b)
        {
            ExDivRes = a / b;
            ExtC = ExtC - b * ExDivRes;
            if (ExtC == 0)
            {
                return true;
            }
            return false;
        }
        /// <summary>
        /// Calculates the mod.
        /// </summary>
        /// <param name="a">a.</param>
        /// <param name="b">The b.</param>
        /// <returns>int</returns>
        int CalcMod(int a, int b)
        {
            divRes = a / b;
            C = a - b * divRes;
            return C;
        }
        __int64 CalcMod(__int64 a, __int64 b)
        {
            ExDivRes = a / b;
            ExtC = ExtC - b * ExDivRes;
            return ExtC;
        }
        __int64 CalcMod(__int64 a, int b)
        {
            ExDivRes = a / b;
            ExtC = ExtC - b * ExDivRes;
            return ExtC;
        }
    };
    class DLL_API VariableConversionFunctions
    {
    public:
        static int PowerOfTens[10];
        static long PowerOfTens64Bit[19];

        /// <summary>
        /// Outputs the number of digits found inside Integer Value type
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>int</returns>
        template<typename targetType>
        static int NumberOfPlaces(targetType Value)
        {
            int NumberOfPlaces = floor(log10(Value));
            return NumberOfPlaces;
        }

        //************************************
        // Method:    NumberOfPlaces
        // FullName:  VariableConversionFunctions::NumberOfPlaces
        // Access:    public static
        // Returns:   int
        // Qualifier:
        // Parameter: double Value
        //************************************
        static int NumberOfPlaces(double Value);

        /// <summary>
        /// Retrieves number of decimal places from integer version of decimal half
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>int</returns>
        static int NumberOfDecimalPlaces(int Value)
        {
            int NumberOfPlaces = floor(log(Value));
            NumberOfPlaces *= -1;
            NumberOfPlaces += 1;
            return NumberOfPlaces;
        }

        static int NumberOfDecimalPlaces(double Value);
        //************************************
        // Method:    CharAsInt
        // FullName:  VariableConversionFunctions::CharAsInt
        // Access:    public static
        // Returns:   int
        // Qualifier:
        // Parameter: char Temp
        //************************************
        static int CharAsInt(char Temp);
        //************************************
        // Method:    DigitAsChar
        // FullName:  VariableConversionFunctions::DigitAsChar
        // Access:    public static
        // Returns:   char
        // Qualifier:
        // Parameter: int Temp
        //************************************
        static char DigitAsChar(int Temp);
        //************************************
        // Method:    IsDigit
        // FullName:  VariableConversionFunctions::IsDigit
        // Access:    public static
        // Returns:   bool
        // Qualifier:
        // Parameter: char Temp
        //************************************
        static bool IsDigit(char Temp);
        //************************************
        // Method:    IsDigit
        // FullName:  VariableConversionFunctions::IsDigit
        // Access:    public static
        // Returns:   bool
        // Qualifier:
        // Parameter: std::string Temp
        //************************************
        static bool IsDigit(std::string Temp);
        //Returns Double Value version of String
        //************************************
        // Method:    ReadDoubleFromString
        // FullName:  VariableConversionFunctions::ReadDoubleFromString
        // Access:    public static
        // Returns:   double
        // Qualifier:
        // Parameter: std::string TempString
        //************************************
        static double ReadDoubleFromString(std::string TempString);

        static float ReadFloatFromString(std::string TempString);
        //Returns Integer value version of String
        //************************************
        // Method:    ReadIntFromString
        // FullName:  VariableConversionFunctions::ReadIntFromString
        // Access:    public static
        // Returns:   int
        // Qualifier:
        // Parameter: std::string TempString
        //************************************
        static int ReadIntFromString(std::string TempString);
        //Returns first std::string of either true,false,1, or 0 in string; if no value found returns false
        //************************************
        // Method:    ReadBoolFromString
        // FullName:  VariableConversionFunctions::ReadBoolFromString
        // Access:    public static
        // Returns:   bool
        // Qualifier:
        // Parameter: std::string LineString
        //************************************
        static bool ReadBoolFromString(std::string LineString);
        //Returns long long int value from string(int 64 bit)
        //************************************
        // Method:    ReadXIntFromString
        // FullName:  VariableConversionFunctions::ReadXIntFromString
        // Access:    public static
        // Returns:   long long int
        // Qualifier:
        // Parameter: std::string TempString
        //************************************
        static long long int ReadXIntFromString(std::string TempString);
        //************************************
        // Scan int for bool value
        // Method:    ReadBoolFromInt
        // FullName:  VariableConversionFunctions::ReadBoolFromInt
        // Access:    public static
        // Returns:   bool
        // Qualifier:
        // Parameter: int Temp
        //************************************
        static bool ReadBoolFromInt(int Temp);
        //************************************
        // Method:    DoubleAsString
        // FullName:  VariableConversionFunctions::DoubleAsString
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: double TempValue
        //************************************
        static std::string DoubleAsString(double TempValue);
        //************************************
        // Method:    BoolAsString
        // FullName:  VariableConversionFunctions::BoolAsString
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: bool TempValue
        //************************************
        static std::string BoolAsString(bool TempValue);
        //************************************
        // Method:    DoubleToStringConversion
        // FullName:  VariableConversionFunctions::DoubleToStringConversion
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: double TempValue
        //************************************
        static std::string DoubleToStringConversion(double TempValue);
        //************************************
        // Method:    IntToStringConversion
        // FullName:  VariableConversionFunctions::IntToStringConversion
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: int TempValue
        //************************************
        static std::string IntToStringConversion(int TempValue);
        //************************************
        // Method:    IntToStringConversion
        // FullName:  VariableConversionFunctions::IntToStringConversion
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: unsigned int TempValue
        //************************************
        static std::string IntToStringConversion(unsigned int TempValue);
        ////************************************
        //// Method:    XIntToStringConversion
        //// FullName:  VariableConversionFunctions::XIntToStringConversion
        //// Access:    public static
        //// Returns:   std::string
        //// Qualifier:
        //// Parameter: long long TempValue
        ////************************************
        //static std::string XIntToStringConversion(long long TempValue)
        //{
        //    string TempString = "";
        //    bool IsNegative = (TempValue < 0) ? true : false;
        //    if (IsNegative)
        //    {
        //        TempString += "-";
        //        TempValue *= -1;
        //    }
        //    long long int IntegerHalf = TempValue;
        //    unsigned __int8 CurrentDigit;
        //    if (IntegerHalf == 0)
        //    {
        //        TempString += "0";
        //    }
        //    else
        //    {
        //        for (long long int i = NumberOfPlaces(IntegerHalf); i >= 0; --i)
        //        {
        //            CurrentDigit = floor(IntegerHalf / pow(10, i));
        //            IntegerHalf -= (long long int) floor(CurrentDigit * pow(10, i));
        //            TempString += DigitAsChar(CurrentDigit);
        //        }
        //    }
        //    return TempString;
        //}

        //************************************
        // Method:    XIntToStringConversion
        // FullName:  VariableConversionFunctions::XIntToStringConversion
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: size_t TempValue
        //************************************
        static std::string XIntToStringConversion(size_t TempValue);

        //************************************
        //FloatToDouble code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c
        // Method:    float_to_double
        // FullName:  VariableConversionFunctions::float_to_double
        // Access:    public static
        // Returns:   uint64_t
        // Qualifier:
        // Parameter: float value
        //************************************
        static uint64_t float_to_double(float value);
        //************************************
        //FloatToDouble code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c
        // Method:    double_to_float
        // FullName:  VariableConversionFunctions::double_to_float
        // Access:    public static
        // Returns:   float
        // Qualifier:
        // Parameter: uint64_t value
        //************************************
        static float double_to_float(uint64_t value);
        //************************************
        // Uses code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c to convert from Double To Float
        // Method:    DoubleToFloat
        // FullName:  StringFunctions::DoubleToFloat
        // Access:    public static
        // Returns:   float
        // Qualifier:
        // Parameter: double TempValue
        //************************************
        static float DoubleToFloat(double TempValue);
        //************************************
        // Uses code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c to convert from Float to Double
        // Method:    FloatToDouble
        // FullName:  StringFunctions::FloatToDouble
        // Access:    public static
        // Returns:   double
        // Qualifier:
        // Parameter: float TempValue
        //************************************
        static double FloatToDouble(float TempValue);
        //************************************
        // Method:    FloatToStringConversion
        // FullName:  VariableConversionFunctions::FloatToStringConversion
        // Access:    public static
        // Returns:   std::string
        // Qualifier:
        // Parameter: float TempValue
        //************************************
        static std::string FloatToStringConversion(float TempValue);
        //************************************
        // Method:    Int32ToFloat
        // FullName:  VariableConversionFunctions::Int32ToFloat
        // Access:    public
        // Returns:   float
        // Qualifier:
        // Parameter: int32_t Value
        //************************************
        static float Int32ToFloat(int32_t Value);
        std::string DisplayFullValues_Vector(float x, float y, float z, float w);
        std::string DisplayFullValues_Vector(float x, float y, float z);
        std::string DisplayFullValues_Vector(float x, float y);
        std::string DisplayFullValues(float x, float y, float z, float w);
        std::string DisplayFullValues(float x, float y, float z);
        std::string DisplayFullValues(float x, float y);

        /// <summary>
        /// Returns the factorial Number from N
        /// (From https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h Answer for using in Taylor series)
        /// </summary>
        /// <param name="n">The n.</param>
        /// <returns></returns>
        static int Fact(int n){ return n <= 0 ? 1 : n * Fact(n - 1); }

        /// <summary>
        /// Applies Power of operation on references(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename targetType, typename ValueType>
        static targetType IntPowOp(targetType& targetValue, ValueType& expValue)
        {
            if (expValue == 1)
                return targetValue;//Return self
            else if (expValue == 0)
                targetValue = 1;
            else if (expValue < 0)//Negative Pow
                return 0;//Can't have decimal values
            else if (targetValue == 10)
                targetValue = VariableConversionFunctions::PowerOfTens[expValue];
            else if (targetValue == -10)
                targetValue = expValue % 2 ? VariableConversionFunctions::PowerOfTens[expValue] : VariableConversionFunctions::PowerOfTens[expValue] * -1;
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                targetType self = targetValue;
                targetValue = 1;// Initialize result
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
        /// <param name="targetType">The target value.</param>
        /// <param name="expValue">The exponent value.</param>
        template<typename targetType, typename ValueType>
        static targetType IntPow(targetType targetValue, ValueType expValue) { return IntPowOp(targetValue, expValue); }

        template<typename IntType>
        static IntType Sqrt(IntType value);
    };
}
#endif