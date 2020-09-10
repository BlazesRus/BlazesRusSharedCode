#pragma once

#include "MediumDec.hpp"

namespace MediumDecCode
{
public:
    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static MediumDec NthRoot(MediumDec value, int n, MediumDec& Precision) { return value.NthRootOpCopy(n, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static MediumDec NthRefRoot(MediumDec& value, int n, MediumDec& Precision) { return value.NthRootOpCopy(n, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static MediumDec NthRoot(MediumDec value, MediumDec n, MediumDec& Precision) { return value.NthRootOpCopy(n, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    static MediumDec NthRefRoot(MediumDec& value, MediumDec n, MediumDec Precision) { return value.NthRootOpCopy(n, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root with OneMillionth precision level
    /// </summary>
    /// <param name="nValue">The n value.</param>
    /// <returns>MediumDec</returns>
    MediumDec NthRoot(int nValue) { return this->NthRootOpCopy(nValue, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root with OneMillionth precision level
    /// </summary>
    /// <param name="nValue">The n value.</param>
    /// <returns>MediumDec</returns>
    MediumDec NthRoot(MediumDec nValue) { return this->NthRootOp(nValue, OneMillionth); }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    MediumDec& NthRootOp(MediumDec& n, MediumDec& Precision)
    {
        MediumDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (MediumDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / MediumDec::Pow(x[1], n - 1)));
        }
        *this = x[0];
        return *this;
    }

    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="value">The value to apply the root on.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    MediumDec NthRootOpCopy(int& n, MediumDec& Precision)
    {
        MediumDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (MediumDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / MediumDec::Pow(x[1], n - 1)));
        }
        return x[0];
    }

    MediumDec NthRootOpByValue(MediumDec n, MediumDec& Precision)
    {
        MediumDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (MediumDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / MediumDec::Pow(x[1], n - 1)));
        }
        return x[0];
    }
    /// <summary>
    /// Get the (n)th Root
    /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
    /// </summary>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    MediumDec NthRootOpCopy(MediumDec& n, MediumDec& Precision)
    {
        MediumDec x[2];
        x[0] = *this;
        x[1] = *this / n;
        while (MediumDec::Abs(x[0] - x[1]) > Precision)
        {
            x[1] = x[0];
            x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / MediumDec::Pow(x[1], n - 1)));
        }
        return x[0];
    }

private:
    MediumDec NthRootsExp(MediumDec a, MediumDec b)
    {
        MediumDec t(1);
        for (int i = 0; i < b; ++i)
            t *= a;
        return t;
    }
public:

    /// <summary>
    /// Get the (n)th Root without needing decimal powers
    /// Code based on Lifes' Answer on https://stackoverflow.com/questions/21141447/find-nth-root-of-a-number-in-c/21142383
    /// </summary>
    /// <param name="n">The n value to apply with root.</param>
    /// <returns></returns>
    MediumDec NthRootV2Op(MediumDec& n, MediumDec& Precision=OneMillionth)
    {
        MediumDec x;
        MediumDec A(n);
        MediumDec dx;
        //MediumDec n(Precision);
        x = A * 0.5;
        dx = (A / NthRootsExp(x, n - 1) - x) / n;
        while (dx >= Precision || dx <= -Precision) {
            x = x + dx;
            dx = (A / NthRootsExp(x, n - 1) - x) / n;
        }
        return x;
    }

    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    MediumDec& PowOp(MediumDec& expValue)
    {
        if (expValue.DecimalHalf01 == 0)
        {
            *this = this->PowOp(expValue.IntValue);
        }
        else
        {
            MediumDec decimalHalfOfPow;
            switch(expValue.IntValue)
            {
                case 0://Between 0 and 1 based on https://stackoverflow.com/questions/9652549/self-made-pow-c
                    this->NthRootOpByValue(1 / expValue, JustAboveZero);
                    break;
                case NegativeZero:
                {
                    decimalHalfOfPow = this->NthRootOpByValue(1 / expValue, JustAboveZero);
                    *this = One / decimalHalfOfPow;
                    break;
                }
                default://Based on based on Fractional part of https://stackoverflow.com/questions/9652549/self-made-pow-c multiplied by power of IntValue
                {
                    if (expValue.IntValue < 0)//Negative Exponent
                    {
                        decimalHalfOfPow = MediumDec(0, expValue.DecimalHalf01);
                        decimalHalfOfPow = this->NthRootOpByValue(1 / decimalHalfOfPow, JustAboveZero);
                        this->PowOp(expValue.IntValue);
                        *this /= decimalHalfOfPow;
                    }
                    else
                    {
                        decimalHalfOfPow = MediumDec(0, expValue.DecimalHalf01);
                        decimalHalfOfPow = this->NthRootOpByValue(1 / decimalHalfOfPow, JustAboveZero);
                        this->PowOp(expValue.IntValue);
                        *this *= decimalHalfOfPow;
                    }
                    break;
                }
            }
        }
        return *this;
    }

    ///// <summary>
    ///// Applies Power of operation
    ///// </summary>
    ///// <param name="expValue">The exponent value.</param>
    //MediumDec PowOpV2(MediumDec& expValue)
    //{
    //    if (expValue.DecimalHalf01 == 0)
    //    {
    //        return this->PowOp(expValue.IntValue);
    //    }
    //    else if (expValue.IntValue == 0)//Between 0 and 1 based on https://stackoverflow.com/questions/9652549/self-made-pow-c
    //    {
    //        return this->NthRootOp(1 / expValue, JustAboveZero);
    //    }
    //    else if (expValue.IntValue == NegativeZero)
    //    {
    //        MediumDec Temp = this->NthRootOp(1/expValue, JustAboveZero);
    //        return One / Temp;
    //    }
    //    else
    //    {
    //        boost::rational<int> ExpFrac = boost::rational<int>(expValue.DecimalHalf01, DecimalOverflow);

    //    }
    //    return *this;
    //}
public:
    /// <summary>
    /// Applies Power of operation
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    MediumDec Pow(MediumDec expValue)
    {
        if (expValue.DecimalHalf01 == 0)
        {
            return Pow(expValue.IntValue);
        }
        else
        {

        }
        return *this;
    }

    template<typename ValueType>
    static MediumDec Pow(MediumDec targetVal, ValueType exponent)
    {
        return targetVal.PowOp(exponent);//targetVal.Pow(exponent);
    }
}
