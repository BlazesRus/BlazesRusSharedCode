#include "VariableConversionFunctions.h"
#include <iostream>
#include <locale>
#include <cmath>

using std::string;
using std::cout;
using BlazesRusCode::VariableConversionFunctions;

unsigned __int8 VariableConversionFunctions::UBytePowerOfTens[3] = { 1, 10, 100 };
int VariableConversionFunctions::PowerOfTens[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
long VariableConversionFunctions::PowerOfTens64Bit[19] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000 };

//************************************
// Method:    NumberOfPlaces
// FullName:  VariableConversionFunctions::NumberOfPlaces
// Access:    public static
// Returns:   int
// Qualifier:
// Parameter: double Value
//************************************
int VariableConversionFunctions::NumberOfPlaces(double Value)
{
    int NumberOfPlaces = floor(log10(Value));
    return NumberOfPlaces;
}

//************************************
// Method:    NumberOfDecimalPlaces
// FullName:  VariableConversionFunctions::NumberOfDecimalPlaces
// Access:    public static
// Returns:   int
// Qualifier:
// Parameter: double Value
//************************************
int VariableConversionFunctions::NumberOfDecimalPlaces(double Value)
{
    int NumberOfPlaces = floor(log(Value));
    NumberOfPlaces *= -1;
    NumberOfPlaces += 1;
    return NumberOfPlaces;
}

//************************************
// Method:    CharAsInt
// FullName:  VariableConversionFunctions::CharAsInt
// Access:    public static
// Returns:   int
// Qualifier:
// Parameter: char Temp
//************************************
int VariableConversionFunctions::CharAsInt(char Temp)
{
    int Value = 0;
    if(Temp == '0') { Value = 0; }
    else if(Temp == '1') { Value = 1; }
    else if(Temp == '2') { Value = 2; }
    else if(Temp == '3') { Value = 3; }
    else if(Temp == '4') { Value = 4; }
    else if(Temp == '5') { Value = 5; }
    else if(Temp == '6') { Value = 6; }
    else if(Temp == '7') { Value = 7; }
    else if(Temp == '8') { Value = 8; }
    else if(Temp == '9') { Value = 9; }
    return Value;
}

//************************************
// Method:    DigitAsChar
// FullName:  VariableConversionFunctions::DigitAsChar
// Access:    public static
// Returns:   int
// Qualifier:
// Parameter: int Temp
//************************************
char VariableConversionFunctions::DigitAsChar(int Temp)
{
    char Value = '0';
    if(Temp == 0) { Value = '0'; }
    else if(Temp == 1) { Value = '1'; }
    else if(Temp == 2) { Value = '2'; }
    else if(Temp == 3) { Value = '3'; }
    else if(Temp == 4) { Value = '4'; }
    else if(Temp == 5) { Value = '5'; }
    else if(Temp == 6) { Value = '6'; }
    else if(Temp == 7) { Value = '7'; }
    else if(Temp == 8) { Value = '8'; }
    else if(Temp == 9) { Value = '9'; }
    return Value;
}

//************************************
// Method:    IsDigit
// FullName:  VariableConversionFunctions::IsDigit
// Access:    public static
// Returns:   bool
// Qualifier:
// Parameter: char Temp
//************************************
bool VariableConversionFunctions::IsDigit(char Temp)
{
    bool DigitType = false;
    if(Temp == '0') { DigitType = true; }
    else if(Temp == '1') { DigitType = true; }
    else if(Temp == '2') { DigitType = true; }
    else if(Temp == '3') { DigitType = true; }
    else if(Temp == '4') { DigitType = true; }
    else if(Temp == '5') { DigitType = true; }
    else if(Temp == '6') { DigitType = true; }
    else if(Temp == '7') { DigitType = true; }
    else if(Temp == '8') { DigitType = true; }
    else if(Temp == '9') { DigitType = true; }
    return DigitType;
}

//************************************
// Method:    IsDigit
// FullName:  VariableConversionFunctions::IsDigit
// Access:    public static
// Returns:   bool
// Qualifier:
// Parameter: std::string Temp
//************************************
bool VariableConversionFunctions::IsDigit(std::string Temp)
{
    return IsDigit(Temp.at(0));
}

// Returns Double Value version of String
double VariableConversionFunctions::ReadDoubleFromString(string TempString)
{
    int WholeNumberPart = 0;
    double DecimalPart = 0.0;
    int PlaceNumber = 0;
    double CalculatedValue;
    bool IsNegative = false;
    string StringChar;
    size_t StringLength;
    StringLength = TempString.length();
    string WholeNumberBuffer = "";
    string DecimalBuffer = "";
    bool ReadingDecimal = false;
    int TempInt;
    int TempInt02;
    double TempDouble;
    //cout << "WholeNumber Part:";
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = TempString.at(i);
        if(IsDigit(StringChar))
        {
            std::cout << StringChar;
            if(ReadingDecimal)
            {
                DecimalBuffer += StringChar;
            }
            else
            {
                WholeNumberBuffer += StringChar;
            }
        }
        else if(StringChar == "-")
        {
            IsNegative = true;
        }
        else if(StringChar == ".")
        {
            ReadingDecimal = true;
            //cout << "\nDecimal Part:";
        }
    }
    for(int i = WholeNumberBuffer.length() - 1; i >= 0; --i)
    {
        StringChar = WholeNumberBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        TempInt02 = TempInt*pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << TempInt02<<"\n";
        if(StringChar != "0")
        {
            WholeNumberPart += TempInt02;
        }
        PlaceNumber++;
    }
    //cout << "\nEnd of WholeNumber Calculations\n";
    StringLength = DecimalBuffer.length();
    PlaceNumber = -1;
    for(size_t i = 0; i < StringLength; i++)
    {
        StringChar = DecimalBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        TempDouble = TempInt*pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << TempDouble << "\n";
        if(IsDigit(StringChar))
        {
            if(StringChar != "0")
            {
                DecimalPart += (double) TempInt*pow(10, PlaceNumber);
            }
            PlaceNumber--;
        }
    }
    //cout << "\nEnd of Decimal Calculations\n";
    CalculatedValue = (double) WholeNumberPart + DecimalPart;
    if(IsNegative == true)
    {
        CalculatedValue *= -1.0;
    }
    cout << "\n";
    return CalculatedValue;
}
float VariableConversionFunctions::ReadFloatFromString(std::string TempString)
{
    int WholeNumberPart = 0;
    float DecimalPart = 0.0;
    int PlaceNumber = 0;
    float CalculatedValue;
    bool IsNegative = false;
    string StringChar;
    size_t StringLength;
    StringLength = TempString.length();
    string WholeNumberBuffer = "";
    string DecimalBuffer = "";
    bool ReadingDecimal = false;
    int TempInt;
    int TempInt02;
    float Tempfloat;
    //cout << "WholeNumber Part:";
    for (size_t i = 0; i < StringLength; ++i)
    {
        StringChar = TempString.at(i);
        if (IsDigit(StringChar))
        {
            std::cout << StringChar;
            if (ReadingDecimal)
            {
                DecimalBuffer += StringChar;
            }
            else
            {
                WholeNumberBuffer += StringChar;
            }
        }
        else if (StringChar == "-")
        {
            IsNegative = true;
        }
        else if (StringChar == ".")
        {
            ReadingDecimal = true;
            //cout << "\nDecimal Part:";
        }
    }
    //cout << "\nWhole Number Calculations:\n";
    for (int i = WholeNumberBuffer.length() - 1; i >= 0; --i)
    {
        StringChar = WholeNumberBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        TempInt02 = TempInt * pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << TempInt02<<"\n";
        if (StringChar != "0")
        {
            WholeNumberPart += TempInt02;
        }
        PlaceNumber++;
    }
    //cout << "\nEnd of WholeNumber Calculations\n";
    StringLength = DecimalBuffer.length();
    PlaceNumber = -1;
    for (size_t i = 0; i < StringLength; i++)
    {
        StringChar = DecimalBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        Tempfloat = TempInt * pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << Tempfloat << "\n";
        if (IsDigit(StringChar))
        {
            if (StringChar != "0")
            {
                DecimalPart += (float)TempInt*pow(10, PlaceNumber);
            }
            PlaceNumber--;
        }
    }
    //cout << "\nEnd of Decimal Calculations\n";
    CalculatedValue = (float)WholeNumberPart + DecimalPart;
    if (IsNegative == true)
    {
        CalculatedValue *= -1.0;
    }
    cout << "\n";
    return CalculatedValue;
}
/** Returns Integer value version of String
 * @param TempString
 * @return
 */
int VariableConversionFunctions::ReadIntFromString(string TempString)
{
    int WholeNumberPart = 0;
    int PlaceNumber = 0;
    bool IsNegative = false;
    string StringChar;
    size_t StringLength;
    StringLength = TempString.length();
    string WholeNumberBuffer = "";
    int TempInt;
    int TempInt02;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = TempString.at(i);
        if(StringChar == "-")
        {
            IsNegative = true;
        }
        else
        {
            if(IsDigit(StringChar))
            {
                WholeNumberBuffer += StringChar;
            }
        }
    }
    //cout << "\nWhole Number Calculations:\n";
    for(int i = WholeNumberBuffer.length() - 1; i >= 0; --i)
    {
        StringChar = WholeNumberBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        TempInt02 = TempInt*pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << TempInt02<<"\n";
        if(StringChar != "0")
        {
            WholeNumberPart += TempInt02;
        }
        PlaceNumber++;
    }
    //cout << "\nEnd of WholeNumber Calculations\n";
    if(IsNegative == true)
    {
        WholeNumberPart *= -1;
    }
    return WholeNumberPart;
}

long long int VariableConversionFunctions::ReadXIntFromString(std::string TempString)
{
    long long int WholeNumberPart = 0;
    long long int PlaceNumber = 0;
    bool IsNegative = false;
    string StringChar;
    size_t StringLength;
    StringLength = TempString.length();
    string WholeNumberBuffer = "";
    long long int TempInt;
    long long int TempInt02;
    for(size_t i = 0; i < StringLength; ++i)
    {
        StringChar = TempString.at(i);
        if(StringChar == "-")
        {
            IsNegative = true;
        }
        else
        {
            if(IsDigit(StringChar))
            {
                WholeNumberBuffer += StringChar;
            }
        }
    }
    //cout << "\nWhole Number Calculations:\n";
    for(int i = WholeNumberBuffer.length() - 1; i >= 0; --i)
    {
        StringChar = WholeNumberBuffer.at(i);
        TempInt = CharAsInt(StringChar.at(0));
        TempInt02 = TempInt*pow(10, PlaceNumber);
        //cout << "StringChar:" << TempInt << " PlaceNumber:" << PlaceNumber << " +=" << TempInt02<<"\n";
        if(StringChar != "0")
        {
            WholeNumberPart += TempInt02;
        }
        PlaceNumber++;
    }
    //cout << "\nEnd of WholeNumber Calculations\n";
    if(IsNegative == true)
    {
        WholeNumberPart *= -1;
    }
    return WholeNumberPart;
}

bool VariableConversionFunctions::ReadBoolFromInt(int Temp)
{
    if(Temp == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//************************************
// Method:    DoubleAsString
// FullName:  VariableConversionFunctions::DoubleAsString
// Access:    public static
// Returns:   string
// Qualifier:
// Parameter: double TempValue
//************************************
string VariableConversionFunctions::DoubleAsString(double TempValue)
{
    string TempString = std::to_string(TempValue);
    return TempString;
}

//************************************
// Method:    ReadBoolFromString
// FullName:  VariableConversionFunctions::ReadBoolFromString
// Access:    public static
// Returns:   bool
// Qualifier:
// Parameter: string LineString
//************************************
bool VariableConversionFunctions::ReadBoolFromString(string LineString)
{
    //Value found in string
    bool FoundValue = false;
    const string TrueString = "true";
    const string FalseString = "false";
    //Current character loaded in steam
    char StringChar;
    //Current Loaded parts of LineString
    string LoadedLineString = "";
    //Current Characters worth of string found that match SearchString
    string PartialSearchBuffer = "";
    //Current Index of Loaded PartialSearch
    size_t PartialBufferIndex = 0;
    //Total size of LineString to load
    size_t StringSize = LineString.size();
    //Boolean check to determine if have found first string match
    bool SearchSuccess = false;
    std::locale loc;
    for(size_t i = 0; i < StringSize&&SearchSuccess == false; i++)
    {
        StringChar = std::tolower(LineString.at(i), loc);
        if(StringChar == '1')
        {
            SearchSuccess = true;
            FoundValue = true;
        }
        else if(StringChar == '0')
        {
            SearchSuccess = true;
            //FoundValue=false;
        }
        else if(TrueString.at(PartialBufferIndex) == StringChar)
        {
            PartialSearchBuffer += StringChar;
            if(PartialSearchBuffer == TrueString)
            {
                SearchSuccess = true;
                FoundValue = true;
            }
            else
            {
                PartialBufferIndex++;
            }
        }
        else if(FalseString.at(PartialBufferIndex) == StringChar)
        {
            PartialSearchBuffer += StringChar;
            if(PartialSearchBuffer == FalseString)
            {
                SearchSuccess = true;
                //FoundValue=false;
            }
            else
            {
                PartialBufferIndex++;
            }
        }
        //Failed Partial String Search
        else
        {
            PartialSearchBuffer = "";
            PartialBufferIndex = 0;
        }
    }
    return FoundValue;
}

//************************************
// Method:    DoubleToStringConversion
// FullName:  VariableConversionFunctions::DoubleToStringConversion
// Access:    public static
// Returns:   std::string
// Qualifier:
// Parameter: double TempValue
//************************************
std::string VariableConversionFunctions::DoubleToStringConversion(double TempValue)
{
    string TempString = "";
    int IsNegative = TempValue < 0;
    int TempInt;
    if(IsNegative)
    {
        TempString += "-";
        TempValue *= -1;
    }
    int IntegerHalf = TempValue;
    double DecimalHalf = TempValue - (double) IntegerHalf;
    unsigned __int8 CurrentDigit;
    string DigitString = "";
    if(IntegerHalf == 0)
    {
        TempString += "0";
    }
    else
    {
        TempInt = NumberOfPlaces(IntegerHalf);
        for(int i = TempInt; i >= 0; i--)
        {
            CurrentDigit = floor(IntegerHalf / pow(10, i));
            IntegerHalf -= CurrentDigit*pow(10, i);
            TempString += DigitAsChar(CurrentDigit);
        }
    }
    if(DecimalHalf != 0.0)
    {
        DigitString += ".";
        int DecimalPlaces = NumberOfDecimalPlaces(DecimalHalf);
        for(unsigned int Index = 0; Index < DecimalPlaces; ++Index)
        {
            CurrentDigit = floor(DecimalHalf*(10*pow(10,Index)));
            DigitString += DigitAsChar(CurrentDigit);
        }
    }
    TempString += DigitString;
    return TempString;
}

////************************************
//// Method:    IntToStringConversion
//// FullName:  VariableConversionFunctions::IntToStringConversion
//// Access:    public static
//// Returns:   std::string
//// Qualifier:
//// Parameter: int TempValue
////************************************
std::string VariableConversionFunctions::IntToStringConversion(int IntegerHalf)
{
    if (IntegerHalf == 0)
        return "0";
    string TempString = "";
    bool IsNegative = (IntegerHalf < 0) ? true : false;
    if(IsNegative)
    {
        TempString += "-";
        IntegerHalf *= -1;
    }
    unsigned __int8 CurrentDigit;
    int PowResult;
    for (int i = NumberOfPlaces(IntegerHalf); i >= 0; i--)
    {
        if (i == 0)
            TempString += DigitAsChar(IntegerHalf);
        else
        {
            PowResult = VariableConversionFunctions::PowerOfTens[i];
            CurrentDigit = floor(IntegerHalf / PowResult);
            IntegerHalf -= CurrentDigit * PowResult;
            TempString += DigitAsChar(CurrentDigit);
        }
    }
    return TempString;
}

std::string VariableConversionFunctions::IntToStringConversion(unsigned int IntegerHalf)
{
    if (IntegerHalf == 0)
        return "0";
    string TempString = "";
    unsigned __int8 CurrentDigit;
    int PowResult;
    for (int i = NumberOfPlaces(IntegerHalf); i >= 0; i--)
    {
        if (i == 0)
            TempString += DigitAsChar(IntegerHalf);
        else
        {
            PowResult = VariableConversionFunctions::PowerOfTens[i];
            CurrentDigit = floor(IntegerHalf / PowResult);
            IntegerHalf -= CurrentDigit * PowResult;
            TempString += DigitAsChar(CurrentDigit);
        }
    }
    return TempString;
}

std::string VariableConversionFunctions::XIntToStringConversion(size_t IntegerHalf)
{
    if (IntegerHalf == 0)
        return "0";
    string TempString = "";
    unsigned __int8 CurrentDigit;
    size_t PowResult;
    for (int i = NumberOfPlaces(IntegerHalf); i >= 0; i--)
    {
        if (i == 0)
            TempString += DigitAsChar(IntegerHalf);
        else
        {
            PowResult = VariableConversionFunctions::PowerOfTens64Bit[i];
            CurrentDigit = floor(IntegerHalf / PowResult);
            IntegerHalf -= CurrentDigit * PowResult;
            TempString += DigitAsChar(CurrentDigit);
        }
    }
    return TempString;
}

std::string BlazesRusCode::VariableConversionFunctions::UnsignedByteToStringConversion(unsigned __int8 IntegerHalf)
{
    if (IntegerHalf == 0)
        return "0";
    std::string TempString = "";
    unsigned __int8 CurrentDigit;
    int PowResult;
    for (int i = NumberOfPlaces(IntegerHalf); i >= 0; i--)
    {
        if (i == 0)
            TempString += DigitAsChar(IntegerHalf);
        else
        {
            PowResult = VariableConversionFunctions::UBytePowerOfTens[i];
            CurrentDigit = floor(IntegerHalf / PowResult);
            IntegerHalf -= CurrentDigit * PowResult;
            TempString += DigitAsChar(CurrentDigit);
        }
    }
    return TempString;
}

//************************************
// Method:    BoolAsString
// FullName:  VariableConversionFunctions::BoolAsString
// Access:    public static
// Returns:   std::string
// Qualifier:
// Parameter: bool TempValue
//************************************
std::string VariableConversionFunctions::BoolAsString(bool TempValue)
{
    string TempString;
    if(TempValue == true)
    {
        TempString = "true";
    }
    else
    {
        TempString = "false";
    }
    return TempString;
}

//FloatToDouble code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c
//license from project code is From:
//Copyright(c) 2011 Petteri Aimonen <jpa at nanopb.mail.kapsi.fi>
//
//This software is provided 'as-is', without any express or
//implied warranty.In no event will the authors be held liable
//for any damages arising from the use of this software.
//
//Permission is granted to anyone to use this software for any
//purpose, including commercial applications, and to alter it and
//redistribute it freely, subject to the following restrictions :
//
//1. The origin of this software must not be misrepresented; you
//must not claim that you wrote the original software.If you use
//this software in a product, an acknowledgment in the product
//documentation would be appreciated but is not required.
//
//2. Altered source versions must be plainly marked as such, and
//must not be misrepresented as being the original software.
//
//3. This notice may not be removed or altered from any source
//distribution.
typedef union conversion_t
{
    float f;
    uint32_t i;
};

/* Note: IEE 754 standard specifies float formats as follows:
 * Single precision: sign,  8-bit exp, 23-bit frac.
 * Double precision: sign, 11-bit exp, 52-bit frac.
 */
uint64_t VariableConversionFunctions::float_to_double(float value)
{
    conversion_t in;
    in.f = value;
    uint8_t sign;
    int16_t exponent;
    uint64_t mantissa;

    /* Decompose input value */
    sign = (in.i >> 31) & 1;
    exponent = ((in.i >> 23) & 0xFF) - 127;
    mantissa = in.i & 0x7FFFFF;

    if(exponent == 128)
    {
        /* Special value (NaN etc.) */
        exponent = 1024;
    }
    else if(exponent == -127)
    {
        if(!mantissa)
        {
            /* Zero */
            exponent = -1023;
        }
        else
        {
            /* De-normalized */
            mantissa <<= 1;
            while(!(mantissa & 0x800000))
            {
                mantissa <<= 1;
                exponent--;
            }
            mantissa &= 0x7FFFFF;
        }
    }

    /* Combine fields */
    mantissa <<= 29;
    mantissa |= ((uint64_t)exponent + 1023) << 52;
    mantissa |= (uint64_t) sign << 63;

    return mantissa;
}

float VariableConversionFunctions::double_to_float(uint64_t value)
{
    uint8_t sign;
    int16_t exponent;
    uint32_t mantissa;
    conversion_t out;

    /* Decompose input value */
    sign = (value >> 63) & 1;
    exponent = ((value >> 52) & 0x7FF) - 1023;
    mantissa = (value >> 28) & 0xFFFFFF; /* Highest 24 bits */

    /* Figure if value is in range representable by floats. */
    if(exponent == 1024)
    {
        /* Special value */
        exponent = 128;
    }
    else if(exponent > 127)
    {
        /* Too large */
        if(sign)
            return -INFINITY;
        else
            return INFINITY;
    }
    else if(exponent < -150)
    {
        /* Too small */
        if(sign)
            return -0.0f;
        else
            return 0.0f;
    }
    else if(exponent < -126)
    {
        /* De-normalized */
        mantissa |= 0x1000000;
        mantissa >>= (-126 - exponent);
        exponent = -127;
    }

    /* Round off mantissa */
    mantissa = (mantissa + 1) >> 1;

    /* Check if mantissa went over 2.0 */
    if(mantissa & 0x800000)
    {
        exponent += 1;
        mantissa &= 0x7FFFFF;
        mantissa >>= 1;
    }

    /* Combine fields */
    out.i = mantissa;
    out.i |= (uint32_t) (exponent + 127) << 23;
    out.i |= (uint32_t) sign << 31;

    return out.f;
}

float VariableConversionFunctions::DoubleToFloat(double TempValue)
{
    return double_to_float(TempValue);
}

double VariableConversionFunctions::FloatToDouble(float TempValue)
{
    return float_to_double(TempValue);
}

//************************************
// Method:    FloatToStringConversion
// FullName:  FloatToStringConversion
// Access:    public static
// Returns:   string
// Qualifier:
// Parameter: float TempValue
//************************************
std::string VariableConversionFunctions::FloatToStringConversion(float TempValue)
{
    string TempString = "";
    ////Method based on http://stackoverflow.com/questions/5290089/how-to-convert-a-number-to-string-and-vice-versa-in-c
    ////And http://stackoverflow.com/questions/554063/how-do-i-print-a-double-value-with-full-precision-using-cout
    //std::ostringstream FloatStream;
    //typedef std::numeric_limits< float > FloatLimit;
    //FloatStream.precision(FloatLimit::max_digits10);
    //FloatStream << fixed << TempValue;
    //TempString = FloatStream.str();
    return TempString;
}

//Based on http://stackoverflow.com/questions/14855119/how-to-get-the-float-with-given-bit-pattern-as-int32-t-in-c
float VariableConversionFunctions::Int32ToFloat(int32_t Value)
{
    float fValue;
    std::memcpy(&fValue, &Value, sizeof(fValue));
    return fValue;
}

std::string VariableConversionFunctions::DisplayFullValues_Vector(float x, float y, float z, float w)
{
    std::string OutputString;
    OutputString = "{";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(z);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(w);
    OutputString += "}";
    return OutputString;
}

std::string VariableConversionFunctions::DisplayFullValues(float x, float y, float z, float w)
{
    std::string OutputString;
    OutputString = "(";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(z);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(w);
    OutputString += ")";
    return OutputString;
}

std::string VariableConversionFunctions::DisplayFullValues_Vector(float x, float y, float z)
{
    string OutputString;
    OutputString = "{";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(z);
    OutputString += "}";
    return OutputString;
}

std::string VariableConversionFunctions::DisplayFullValues(float x, float y, float z)
{
    string OutputString;
    OutputString = "(";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(z);
    OutputString += ")";
    return OutputString;
}

std::string VariableConversionFunctions::DisplayFullValues_Vector(float x, float y)
{
    string OutputString;
    OutputString = "{";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += "}";
    return OutputString;
}

std::string VariableConversionFunctions::DisplayFullValues(float x, float y)
{
    string OutputString;
    OutputString = "(";
    OutputString += VariableConversionFunctions::FloatToStringConversion(x);
    OutputString += ",";
    OutputString += VariableConversionFunctions::FloatToStringConversion(y);
    OutputString += ")";
    return OutputString;
}

template<typename IntType>
inline IntType VariableConversionFunctions::Sqrt(IntType value)
{
    if (value <= 1)
        return 1;
    else if (value <= 4)
        return 4;
    else if (value <= 9)
        return 3;
    else if (value <= 16)
        return 4;
    else if (value <= 25)
        return 5;
    else if (value <= 36)
        return 6;
    else if (value <= 49)
        return 7;
    else if (value <= 64)
        return 8;
    else if (value <= 81)
        return 9;
    else if (value <= 100)
        return 10;
    else if (value <= 121)
        return 11;
    else if (value <= 144)
        return 12;
    else if (value <= 166)
        return 13;
    else if (value <= 196)
        return 14;
    else if (value <= 225)
        return 15;
    else if (value <= 256)
        return 16;
    else if (value <= 289)
        return 17;
    else if (value <= 324)
        return 18;
    else if (value <= 361)
        return 19;
    else if (value <= 400)
        return 20;
    else
    {
        return sqrt(value);
    }
}
