#pragma once

#include "MediumDec.hpp"

namespace MediumDecCode
{
#pragma region Math/Trigonomic Etc Functions
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
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
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
    /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
    /// </summary>
    /// <param name="Value">The target value to apply on.</param>
    /// <returns>MediumDec</returns>
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
    /// <param name="Value">The value.</param>
    /// <returns>MediumDec</returns>
    static MediumDec Trunc(MediumDec Value)
    {
        return Value.Trunc();
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
                *this = NthRefRoot(*this, 2, MediumDec::JustAboveZero);
                break;
            }
        }
        else
        {
            *this = NthRefRoot(*this, 2, MediumDec::JustAboveZero);
        }
    }

    /// <summary>
    /// Gets the square root of the specified value.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns></returns>
    static MediumDec Sqrt(MediumDec Value)
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
                Value = NthRefRoot(Value, 2, MediumDec::JustAboveZero);
                break;
            }
        }
        else
        {
            Value = NthRefRoot(Value, 2, MediumDec::JustAboveZero);
        }
        return Value;
    }

    /// <summary>
    /// Rounds the specified value based on https://en.wikipedia.org/wiki/Rounding.
    /// </summary>
    /// <param name="value">The value.</param>
    /// <param name="precision">The precision.</param>
    /// <returns>MediumDec</returns>
    static MediumDec Round(MediumDec value, int precision = 0)
    {
        if (value.DecimalHalf01 == 0) { return value; }
        if (precision == 0)//RoundToNearest
        {
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
                    return MediumDec::Floor(value, precision);
                }
            }
        }
        return value;
    }
#pragma endregion Math/Trigonomic Etc Functions
}
