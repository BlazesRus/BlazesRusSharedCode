// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************

#include <iostream>
#include "AltNum\MediumDec.hpp"

using MediumDec = BlazesRusCode::MediumDec;
using VariableConversionFunctions = BlazesRusCode::VariableConversionFunctions;

#include <cmath>
#include "AltNum\FloatingOperations.hpp"

#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

namespace BlazesRusDebug
{
    /// <summary>
    /// Get the (n)th Root
    /// Code from https://rosettacode.org/wiki/Nth_root#C.23 (Derived from C version)
    /// </summary>
    /// <param name="value">The value to apply the root to.</param>
    /// <param name="n">The n value to apply with root.</param>
    /// <param name="precision">Precision level (smaller = more precise)</param>
    /// <returns></returns>
    static MediumDec NthRootV1(MediumDec value, int n)
    {//Accuracy is off for 4th root of 4 compared to calculator at (1.65625 compared to 1.4953487812212205419118989941409)
        MediumDec Prec = MediumDec(0, 10);
        MediumDec NegPrec = MediumDec(MediumDec::NegativeZero, 10);//-Prec;
        double PrecFl = DBL_EPSILON * 10;
        double NegPrecFL = -DBL_EPSILON * 10;
        
        MediumDec d, r = MediumDec::One;
        double dFL, rFL = 1.0;

        double valAsFloating = (double)value;
        int nMinus1 = n - 1;

        MediumDec powResult;
        double powResultFL;
        //if (n < 1 || (value < 0.0 && !(n & 1))) {
        //    return;//0.0 / 0.0; /* NaN */
        //}
        do {
            powResultFL = pow(rFL, nMinus1);
            powResult = MediumDec::Pow(r, nMinus1);
            dFL = valAsFloating / powResultFL - rFL;
            d = value / powResult - r;
            dFL /= n;
            d /= n;
            rFL += dFL;
            r += d;
            //std::cout << "PowerResult Values(double,MediumDec) =" << powResultFL << "," << powResult.ToString() << std::endl;
            //std::cout << "Floating Values(d,r) =" << dFL << "," << rFL << std::endl;
            //std::cout << "MediumDec Values(d,r) =" << d.ToString() << "," << r.ToString();
            std::cout << std::endl;
        } while (d >= PrecFl || d <= NegPrecFL);//while (d >= Prec || d <= NegPrec);//precision check condition
        return r;
    }

    /// <summary>
    /// Finds nTh Root of value based on https://stackoverflow.com/questions/9652549/self-made-pow-c code
    /// </summary>
    /// <param name="value">The value.</param>
    /// <param name="nValue">The nth value.</param>
    /// <param name="KPrecision">Precision level (larger = more precise)</param>
    /// <returns>MediumDec</returns>
    static MediumDec NthRootV4(MediumDec value, int n, int KPrecision=5)
    {
        int nMinus1 = n - 1;
        int nPlus1 = n + 1;
        const int LastElem = KPrecision-1;
        std::vector<MediumDec> x;
        x.push_back(MediumDec::One);
        MediumDec Temp;
        for (int XElem = 0; XElem < KPrecision; ++XElem)
        {
            Temp = (MediumDec::One / n) * (nMinus1 * x.back() + value / MediumDec::PowConstOp(x.back(), nMinus1));
            x.push_back(Temp);
        }
        return x.back();
    }

      /// <summary>
      /// Get the (n)th Root
      /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
      /// </summary>
      /// <param name="n">The n value to apply with root.</param>
      /// <returns></returns>
      static MediumDec NthRootV5(MediumDec targetValue, int n, MediumDec& Precision=MediumDec::FiveBillionth)
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
      /// Log Base 10 of Value
      /// </summary>
      /// <param name="Value">The value.</param>
      /// <returns>MediumDec</returns>
      static MediumDec Log10(MediumDec Value)
      {
          return MediumDec::Ln(Value) / MediumDec::LN10;
      }

      /// <summary>
      /// Log Base 10 of Value
      /// </summary>
      /// <param name="Value">The value.</param>
      /// <returns>MediumDec</returns>
      static MediumDec Log10(int Value)
      {
          return MediumDec::Ln(Value) / MediumDec::LN10;
      }

      /// <summary>
      /// Log with Base of BaseVal of Value
      /// Based on http://home.windstream.net/okrebs/page57.html
      /// </summary>
      /// <param name="Value">The value.</param>
      /// <param name="BaseVal">The base of Log</param>
      /// <returns>MediumDec</returns>
      static MediumDec Log(MediumDec Value, MediumDec BaseVal)
      {
          return Log10(Value) / Log10(BaseVal);
      }

      /// <summary>
      /// Log with Base of BaseVal of Value
      /// Based on http://home.windstream.net/okrebs/page57.html
      /// </summary>
      /// <param name="Value">The value.</param>
      /// <param name="BaseVal">The base of Log</param>
      /// <returns>MediumDec</returns>
      static MediumDec Log(MediumDec Value, int BaseVal)
      {
          return Log10(Value) / Log10(BaseVal);
      }

    /// <summary>
    /// Natural log
    /// </summary>
    /// <param name="value">The target value.</param>
    static MediumDec Ln(MediumDec value)
    {
        //if (value <= 0) {}else//Error if equal or less than 0
        if (value == MediumDec::One)
            return MediumDec::Zero;
        else if (value.IntValue < 2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
        {//This section gives correct answer
            MediumDec threshold = "0.00005";  // set this to whatever threshold you want
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
        {//Increasing iterations brings closer to accurate result
            MediumDec W = (value - 1) / (value + 1);
            MediumDec TotalRes = W;
#if(_DEBUG)
            MediumDec AddRes = MediumDec::Maximum;
            int WPow;
            for(WPow=3; AddRes>MediumDec::JustAboveZero;WPow+=2)
            {
                AddRes = MediumDec::PowRef(W, WPow) / WPow;
                TotalRes += AddRes;
            }
            TotalRes *= 2;
            std::cout << "Ln(" << value.ToString() << ") = " << TotalRes.ToString() << " FloatingResult:" << log((double)value) <<" WPow:"<< WPow <<" AddRes:"<<AddRes.ToString()<< std::endl;
            for (int AfterPow = WPow+10; WPow < AfterPow; WPow += 2)//Testing to see if AddRes fluctuates after getting small(to optimize to potentially get more accurate loop iteration number)
            {
                AddRes = MediumDec::PowRef(W, WPow) / WPow;
                std::cout << "(AfterPow)" << AddRes.ToString() << " at WPow Val of " << WPow << std::endl;
            }
            return TotalRes;
#else
            for (int WPow = 3; WPow <63; WPow += 2)
            {
                TotalRes += MediumDec::PowRef(W, WPow) / WPow;
            }
#endif
            return TotalRes * 2;
        }
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
    static MediumDec Ln(MediumDec value, MediumDec threshold)
    {
        return LnRef(value, threshold);
    }

    /*
    /// <summary>
    /// Natural log
    /// </summary>
    /// <param name="value">The target value.</param>
    static MediumDec LnV2(MediumDec value)
    {
        //if (value <= 0) {}else//Error if equal or less than 0
        if (value == MediumDec::One)
            return MediumDec::Zero;

        //if (value.IntValue == 0)//Returns a negative number derived from (http://www.netlib.org/cephes/qlibdoc.html#qlog)
        //{//Example:0.5
        //    MediumDec W = (value - 1) / (value + 1);//(-0.5)/(1.5)=-1/3
        //    MediumDec TotalRes = W;
        //    W.SwapNegativeStatus();
        //    MediumDec AddRes;
        //    int WPow = 3;
        //    do
        //    {
        //        AddRes = MediumDec::PowRef(W, WPow) / WPow;
        //        TotalRes -= AddRes;
        //        WPow += 2;
        //    } while (AddRes > MediumDec::JustAboveZero);//Total Result should be -0.346573590279972654708616060729088284037750067180127627060340004746696810984847357802931663498209344
        //    return TotalRes * 2;//Should result in -0.693147180559
        //}
        //if (value.IntValue == 0 && value.DecimalHalf01 > 500000000)//Ln[X] Power series from http://hyperphysics.phy-astr.gsu.edu/hbase/Math/lnseries.html
        //{//Example:0.75
        //    MediumDec AddRes;
        //    MediumDec W = (value - 1) / value;//-.25/0.75 = -1/3
        //    MediumDec TotalRes = W;
        //    MediumDec LastPow = W;
        //    int WPow = 2;
        //    do
        //    {
        //        LastPow *= W;
        //        AddRes = LastPow / WPow;//MediumDec::PowRef(W, WPow) / WPow;
        //        TotalRes += AddRes;
        //        ++WPow;
        //    } while (MediumDec::Abs(AddRes) > MediumDec::JustAboveZero);
        //    return TotalRes;//Should result in -0.287682072451780927439219005993827431503509710897761056506665685349292950720780464338110899179105286
        //}
        if (value.IntValue == 0)
        {
            if(value.DecimalHalf01 > 500000000)//Ln[X] Power series from http://hyperphysics.phy-astr.gsu.edu/hbase/Math/lnseries.html
            {
                //-1/3 + 2/9 - 3/27 + 4/81 - 5/243 + 6/729 - 7/2187 + 8/6561 = 
            }

            //Ln(1+x=value at .25) = Ln(x-1) || Ln(x) || Result
            //Ln(.75) = -0.287682072451780927439219005993827431503509710897761056506665685349292950720780464338110899179105286
            //value = x - 1 => value + 1 = x

        }
        else if (value.IntValue==1)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
        {//This section gives accurate answer(for values between 1 and 2)
            MediumDec threshold = MediumDec::FiveMillionth;
            MediumDec base = value - 1;        // Base of the numerator; exponent will be explicit
            int den = 1;              // Denominator of the nth term
            bool posSign = true;             // Used to swap the sign of each term
            MediumDec term = base;       // First term
            MediumDec prev;          // Previous sum
            MediumDec result = term;     // Kick it off

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
            } while (MediumDec::Abs(prev - result) > threshold);

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
    */
}