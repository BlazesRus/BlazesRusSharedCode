// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
//Designed mainly as a floating point based version of code for testing purposes
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

#include <cmath>
#include <cfloat>

namespace BlazesFloatingCode
{
    /// <summary>
    /// Get the (n)th Root
    /// Code from https://rosettacode.org/wiki/Nth_root#C.23 (Derived from C version)
    /// </summary>
    /// <param name="value">The value to apply the root to.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns></returns>
    static double NthRootV1(double value, int n)//, double precision = 0.0000000000001)
    {
        double d, r = 1.0;
        //if (n < 1 || (value < 0.0 && !(n & 1))) {
        //    return;//0.0 / 0.0; /* NaN */
        //}
        do {
            d = (value / pow(r, n - 1) - r) / n;
            r += d;
        } while (d >= DBL_EPSILON * 10 || d <= -DBL_EPSILON * 10);//precision check condition
        return r;
    }

    /// <summary>
    /// Get the (n)th Root without needing decimal powers
    /// Code based on Lifes' Answer on https://stackoverflow.com/questions/21141447/find-nth-root-of-a-number-in-c/21142383
    /// </summary>
    /// <param name="value">The value to apply the root to.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns></returns>
    static double NthRootV2(double value, int n, double precision = 0.0000000000001)
    {
        double x;
        double dx;
        x = value * 0.5;
        dx = (value / pow(x, n - 1) - x) / n;
        while (dx >= precision || dx <= -precision) {
            x = x + dx;
            dx = (value / pow(x, n - 1) - x) / n;
        }
        return x;
    }

    /// <summary>
    /// Finds nTh Root of value based on https://www.geeksforgeeks.org/n-th-root-number/ code
    /// </summary>
    /// <param name="value">The value.</param>
    /// <param name="nValue">The nth value.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns>MediumDec</returns>
    static double NthRootV3(double value, int n, double precision = 0.0000000000001)
    {
        int nMinus1 = n - 1;
        double xPre = 1 + (value - 1) / n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method

        // initializing difference between two 
        // roots by INT_MAX 
        double delX = INT_MAX;

        //  xK denotes current value of x 
        double xK;

        //  loop until we reach desired accuracy
        do
        {//  calculating current value from previous value by newton's method
            xK = (nMinus1 * xPre +
                value / pow(xPre, nMinus1)) / n;
            delX = abs(xK - xPre);
            xPre = xK;
        } while (delX > precision);
        return xK;
    }

    /// <summary>
    /// Finds nTh Root of value based on https://stackoverflow.com/questions/9652549/self-made-pow-c code (Works but slightly less accurate)
    /// </summary>
    /// <param name="value">The value.</param>
    /// <param name="nValue">The nth value.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns>MediumDec</returns>
    static double NthRootV4(double value, int n)
    {
        int nMinus1 = n - 1;
        int nPlus1 = n + 1;
        const int KSize = 6;
        int minusOne;
        double x[KSize] = { 1.0 };
        int XElem;
        for (XElem = 1; XElem < KSize; ++XElem)
        {
            minusOne = XElem - 1;
            x[XElem] = (1.0 / n) * (nMinus1 * x[minusOne] + value / pow(x[minusOne], nMinus1));
        }
        return x[XElem];
        //const int K = 6;
        //float x[K] = { 1 };
        //for (int k = 0; k < K - 1; k++)
        //    x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / pow(x[k], n - 1));
        //return x[K - 1];
    }

    //Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html
    static double FractionalPow(double value, int expNum, int expDenom)
    {
        double CalcVal = NthRootV3(pow(value, expNum), expDenom);
        return CalcVal;
    }

    static double Pow(double value, double expValue)
    {
        double CalcVal = exp(expValue * log(value));
        return CalcVal;
    }

    /// <summary>
    /// Applies Power of operation (for integer exponents)
    /// </summary>
    /// <param name="expValue">The exponent value.</param>
    template<typename ValueType>
    static double Pow(double targetValue, ValueType expValue)
    {
        if (expValue == 1) { return targetValue; }//Return self
        else if (expValue == 0)
        {
            return 1.0;
        }
        else if (expValue < 0)//Negative Pow
        {
            if (targetValue == 10.0 && expValue >= -9)
            {
                return 1.0/ (VariableConversionFunctions::PowerOfTens[expValue * -1]);
            }
            else
            {
                //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                expValue *= -1;
                double self = targetValue;
                targetValue = 1.0;// Initialize result
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
        else if (targetValue == 10.0)
        {
            return (double)VariableConversionFunctions::PowerOfTens[expValue];
        }
        else
        {
            //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
            double self = targetValue;
            targetValue = 1.0;// Initialize result
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
    /// Natural log (Equivalent to Log_E(value))
    /// </summary>
    /// <param name="value">The target value.</param>
    /// <returns>double</returns>
    static double LnRef(double& value)
    {
        //if (value <= 0) {}else//Error if equal or less than 0
        if (value == 1.0)
            return 0.0;
        if (value < 2.0)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
        {
            double threshold = 0.000000005;
            double base = value - 1;        // Base of the numerator; exponent will be explicit
            int den = 1;              // Denominator of the nth term
            bool posSign = true;             // Used to swap the sign of each term
            double term = base;       // First term
            double prev;          // Previous sum
            double result = term;     // Kick it off

            do
            {
                den++;
                posSign = !posSign;
                term *= base;
                prev = result;
                if (posSign)
                    result += term / den;
                else
                    result -= term / den;
            } while (abs(prev - result) > threshold);

            return result;
        }
        else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
        {//Increasing iterations brings closer to accurate result(Larger numbers need more iterations to get accurate level of result)
            //double W = (value - 1) / (value + 1);
            double TotalRes = (value - 1) / (value + 1);//W;
            double LastPow = TotalRes;
            double WSquared = TotalRes * TotalRes;
            double AddRes;
            int WPow = 3;
            do
            {
                LastPow *= WSquared;
                AddRes = LastPow/WPow;//double::PowRef(W, WPow) / WPow;
                TotalRes += AddRes; WPow += 2;
            } while (AddRes > 0.000000001);
            return TotalRes * 2;
        }
    }

    /// <summary>
    /// Natural log (Equivalent to Log_E(value))
    /// </summary>
    /// <param name="value">The target value.</param>
    static double Ln(double value)
    {
        return LnRef(value);
    }
}