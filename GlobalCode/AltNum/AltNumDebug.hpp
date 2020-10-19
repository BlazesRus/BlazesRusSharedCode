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
      /// Applies Power of operation based on exp(expValue * log(value)) formula
      /// </summary>
      /// <param name="value">The target value.</param>
      /// <param name="expValue">The exponent value.</param>
      static MediumDec PowV2(MediumDec targetValue, MediumDec n)
      {
          double FloatingLn = log((double)targetValue);
          MediumDec LnVal = MediumDec::Ln(targetValue);
          std::cout << "LnResult:" << LnVal.ToString() << " Floating Equivalent:" << FloatingLn<<std::endl;
          return MediumDec::Exp(LnVal * n);
      }

    ///// <summary>
    ///// Finds nTh Root of value based on https://www.geeksforgeeks.org/n-th-root-number/ code
    ///// </summary>
    ///// <param name="value">The target value.</param>
    ///// <param name="nValue">The nth value.</param>
    ///// <param name="precision">Precision level (smaller = more precise)</param>
    ///// <returns>MediumDec</returns>
    //static MediumDec NthRootTest(MediumDec value, int n)
    //{
    //	MediumDec precision = MediumDec(0, 5);
    //	int nMinus1 = n - 1;
    //	MediumDec xPre = 1 + (value - 1) / n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method

    //	// initializing difference between two 
    //	// roots by INT_MAX 
    //	MediumDec delX = MediumDec::Maximum;

    //	//  xK denotes current value of x 
    //	MediumDec xK;

    //	double valueFl = (double)value;
    //	double xPreFl = 1.0 + (valueFl - 1.0) / n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method

    //// initializing difference between two 
    //// roots by INT_MAX 
    //	double delXFl = INT_MAX;

    //	//  xK denotes current value of x 
    //	double xKFl;

    //	MediumDec resDiff;
    //	MediumDec precDiff;

    //	//  loop until we reach desired accuracy
    //	do
    //	{//  calculating current value from previous value by newton's method
    //		xK = nMinus1 * xPre;
    //		xKFl = nMinus1 * xPreFl;
    //		xK += value / MediumDec::Pow(xPre, nMinus1);
    //		xKFl += valueFl / pow(xPreFl, nMinus1);
    //		xK /= n;
    //		xKFl /= n;
    //		delX = MediumDec::Abs(xK - xPre);
    //		delXFl = abs(xKFl - xPreFl);
    //		xPre = xK;
    //		if(delXFl< 0.0000000000001)//Floating precision met at this point
    //		{
    //			resDiff = xK - (MediumDec)xKFl;
    //			precDiff = delX - (MediumDec)delXFl;
    //			std::cout << "Floating precision met at delX:" << delX.ToString() << " result currently at " << xK.ToString() << " with current result difference of " << resDiff.ToString() << " and current accuracy difference of " << precDiff.ToString() << std::endl;
    //		}
    //		else if (delX < precision)
    //		{
 //               resDiff = xK - (MediumDec)xKFl;
 //               precDiff = delX - (MediumDec)delXFl;
 //               std::cout << "Floating precision met at delX:" << delX.ToString() << " result currently at " << xK.ToString() << " with current result difference of " << resDiff.ToString() << " and current accuracy difference of " << precDiff.ToString() << std::endl;
    //		}
    //	} while (delXFl > 0.0000000000001);//(delX > precision);
    //	return xK;
    //}

    ///// <summary>
    ///// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html while testing as floating at same time(for debugging)
    ///// </summary>
    ///// <param name="value">The target value.</param>
    ///// <param name="Frac">The exponent value to raise the value to power of.</param>
    ///// <returns>MediumDec</returns>
    //MediumDec FractionalPowTest(MediumDec targetVal, boost::rational<int> Frac)
    //{
    //	MediumDec CalcVal = MediumDec::PowConstOp(targetVal, Frac.numerator());
    //	double floatingVal = (double)targetVal;
    //	double floatingRes = pow(floatingVal, Frac.numerator());
    //	MediumDec resDiff = CalcVal - (MediumDec)floatingRes;
    //	CalcVal = NthRootTest(CalcVal, Frac.denominator());
    //	floatingRes = BlazesFloatingCode::NthRootV3(floatingRes, Frac.denominator());
    //	resDiff = CalcVal - (MediumDec)floatingRes;
    //	return CalcVal;
    //}

/*
    /// <summary>
    /// Applies Power of operation while testing as floating at same time(for debugging)
    /// </summary>
    /// <param name="value">The target value.</param>
    /// <param name="expValue">The exponent value.</param>
    /// <returns>MediumDec</returns>
    MediumDec PowTest(MediumDec targetVal, MediumDec expVal)
    {
        if (expVal.DecimalHalf01 == 0)
        {
            return targetVal.Pow(expVal.IntValue);
        }
        else
        {
            boost::rational<int> Frac = boost::rational<int>(expVal.DecimalHalf01, MediumDec::DecimalOverflow);
            switch (expVal.IntValue)
            {
                case 0:
                    return FractionalPowTest(targetVal, Frac);
                    break;
                case MediumDec::NegativeZero:
                    return 1 / FractionalPowTest(targetVal, Frac);
                    break;
                default:
                {
                    if (expVal.IntValue < 0)//Negative Exponent 
                    {
                        MediumDec CalcVal = 1 / targetVal.Pow(expVal.IntValue * -1);
                        double floatingRes = 1 / pow((double)targetVal, expVal.IntValue *-1);
                        MediumDec resDiff = CalcVal - (MediumDec)floatingRes;
                        CalcVal /= FractionalPowTest(targetVal, Frac);
                        floatingRes /= (double)FractionalPowTest(targetVal, Frac);
                        resDiff = CalcVal - (MediumDec)floatingRes;
                        return CalcVal;
                    }
                    else
                    {
                        MediumDec CalcVal = targetVal.Pow(expVal.IntValue);
                        double floatingRes = pow((double)targetVal, expVal.IntValue);
                        MediumDec resDiff = CalcVal - (MediumDec)floatingRes;
                        CalcVal *= MediumDec::FractionalPow(targetVal, Frac);
                        floatingRes *= (double)FractionalPowTest(targetVal, Frac);
                        resDiff = CalcVal - (MediumDec)floatingRes;
                        return CalcVal;
                    }
                    break;
                }
            }
        }
    }
*/

 //   /// <summary>
 //   /// Continued Fractional Log based on https://en.wikipedia.org/wiki/Euler%27s_continued_fraction_formula
 //   /// </summary>
 //   /// <param name="value">The target value.</param>
    ///// <returns>MediumDec</returns>
    //static MediumDec log10(MediumDec value, int Iterations=20)
    //{
    //	MediumDec CalcVal, z = value - 1;
    //	for(int x=0;x<Iterations;++Iterations)
    //	{

    //	}
    //}

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
        {
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
        else//Returns a positive value(continued Fractional 
        {
            //based on https://en.wikipedia.org/wiki/Euler%27s_continued_fraction_formula,
            //https://stackoverflow.com/questions/33849986/how-to-implement-natural-logarithm-with-continued-fraction-in-c,
            //and https://www.purplemath.com/modules/logs3.htm,
            int ValueMin = -1;
            MediumDec MinCalc = MediumDec::One; MediumDec IterCalc = MediumDec::One;
            while(IterCalc< value)//Manually check each power of E
            {
                ++ValueMin;
                MinCalc = IterCalc;
                IterCalc*=MediumDec::E;
            }
            if (IterCalc == value)
                return MediumDec(ValueMin+1, 0);
            else
            {
                int n = 8;
                MediumDec zz = value * value;
                MediumDec cf = ValueMin;
                for (int i = n; i >= 1; i--) {
                    cf = (2 * i - 1) - i * i * zz / cf;
                }
                return 2 * value / cf;
            }
        }
    }
}