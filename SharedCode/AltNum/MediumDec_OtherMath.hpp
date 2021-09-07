// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#include "MediumDec.hpp"

namespace MediumDecCode
{
    using MediumDec = BlazesRusCode::MediumDec;
    
  //  /// <summary>
  //  /// Get the (n)th Root
  //  /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
  //  /// </summary>
  //  /// <param name="n">The n value to apply with root.</param>
  //  /// <returns></returns>
  //  MediumDec NthRoot(MediumDec targetValue, MediumDec n, MediumDec& Precision=MediumDec::OneMillionth)
  //  {
  //      MediumDec x[2] = {targetValue, targetValue / n};
  ////      x[0] = targetValue;
  ////      x[1] = targetValue / n;
  //      //MediumDec TempVal = (1 / n) * (((n - 1) * x[1]) + (targetValue / Pow(x[1], n - 1)));
  //      while (MediumDec::Abs(x[0] - x[1]) > Precision)
  //      {
  //          //x[1] = x[0];
  //          //x[0] = (1 / n) * (((n - 1) * x[1]) + (*this / MediumDec::Pow(x[1], n - 1)));
  //      }
  //      return targetValue;
  //  }

    /// <summary>
    /// Get the (n)th Root
    /// Code from https://rosettacode.org/wiki/Nth_root#C.23 (Derived from C version)
    /// </summary>
    /// <param name="value">The value to apply the root to.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns></returns>
    static MediumDec NthRootV1(MediumDec value, int n)//, MediumDec precision = 0.0000000000001)
    {
        MediumDec d, r = 1.0;
        //if (n < 1 || (value < 0.0 && !(n & 1))) {
        //    return;//0.0 / 0.0; /* NaN */
        //}
        do {
            d = (value / MediumDec::Pow(r, n - 1) - r) / n;
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
    static MediumDec NthRootV2(MediumDec value, int n, MediumDec precision = 0.0000000000001)
    {
        MediumDec x;
        MediumDec dx;
        x = value * 0.5;
        dx = (value / MediumDec::Pow(x, n - 1) - x) / n;
        while (dx >= precision || dx <= -precision) {
            x = x + dx;
            dx = (value / MediumDec::Pow(x, n - 1) - x) / n;
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
    MediumDec NthRootV3(MediumDec value, int n, MediumDec precision = 0.0000000000001)
    {
        // initially guessing a random number between 
        // 0 and 9 
        MediumDec xPre = std::rand() % 10;

        // initializing difference between two 
        // roots by INT_MAX 
        MediumDec delX = INT_MAX;

        //  xK denotes current value of x 
        MediumDec xK;

        //  loop until we reach desired accuracy
        do
        {
            //  calculating current value from previous
            // value by newton's method
            xK = ((n - 1.0) * xPre +
                value / MediumDec::Pow(xPre, n - 1)) / n;
            delX = MediumDec::Abs(xK - xPre);
            xPre = xK;
        } while (delX > precision);
        return xK;
    }
}