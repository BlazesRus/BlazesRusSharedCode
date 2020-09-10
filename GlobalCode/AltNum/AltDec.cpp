#include "AltDec.hpp"


#ifdef AltDec_PreferDecimalOverRad//Alternative code for when switch is set (only store value as a radical if decimal ends in truncation)

#pragma region PreferDecimalOverRad to This Conversions
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


#pragma endregion PreferDecimalOverRad to This Conversions
#pragma region PreferDecimalOverRad AltDecToAltDec Ops

#pragma endregion PreferDecimalOverRad AltDecToAltDec Ops
#pragma region PreferDecimalOverRad AltDecToOther Ops

#pragma endregion PreferDecimalOverRad AltDecToOther Ops

#endif