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
            dFL = (valAsFloating / powResultFL - rFL) / n;
            rFL += dFL;
			powResult = MediumDec::Pow(r, nMinus1);
			d = (value / powResult - r);
			d /= n;
            r += d;
			std::cout << "PowerResult Values(double,MediumDec) =" << powResultFL << "," << powResult.ToString() << std::endl;
			std::cout << "Floating Values(d,r) =" << dFL << "," << rFL << std::endl;
			std::cout << "MediumDec Values(d,r) =" << d.ToString() << "," << r.ToString();
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
        int minusOne;
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
		  MediumDec::Exp(n * MediumDec::Log(targetValue));
	  }

	/// <summary>
	/// Finds nTh Root of value based on https://www.geeksforgeeks.org/n-th-root-number/ code
	/// </summary>
	/// <param name="value">The target value.</param>
	/// <param name="nValue">The nth value.</param>
	/// <param name="precision">Precision level (smaller = more precise)</param>
	/// <returns>MediumDec</returns>
	static MediumDec NthRootTest(MediumDec value, int n)
	{
		MediumDec precision = MediumDec(0, 5);
		int nMinus1 = n - 1;
		MediumDec xPre = 1 + (value - 1) / n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method

		// initializing difference between two 
		// roots by INT_MAX 
		MediumDec delX = MediumDec::Maximum;

		//  xK denotes current value of x 
		MediumDec xK;

		double valueFl = (double)value;
		double xPreFl = 1.0 + (valueFl - 1.0) / n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method

	// initializing difference between two 
	// roots by INT_MAX 
		double delXFl = INT_MAX;

		//  xK denotes current value of x 
		double xKFl;

		MediumDec resDiff;
		MediumDec precDiff;

		//  loop until we reach desired accuracy
		do
		{//  calculating current value from previous value by newton's method
			xK = nMinus1 * xPre;
			xKFl = nMinus1 * xPreFl;
			xK += value / MediumDec::Pow(xPre, nMinus1);
			xKFl += valueFl / pow(xPreFl, nMinus1);
			xK /= n;
			xKFl /= n;
			delX = MediumDec::Abs(xK - xPre);
			delXFl = abs(xKFl - xPreFl);
			xPre = xK;
			if(delXFl< 0.0000000000001)//Floating precision met at this point
			{
				resDiff = xK - (MediumDec)xKFl;
				precDiff = delX - (MediumDec)delXFl;
				std::cout << "Floating precision met at delX:" << delX.ToString() << " result currently at " << xK.ToString() << " with current result difference of " << resDiff.ToString() << " and current accuracy difference of " << precDiff.ToString() << std::endl;
			}
			else if (delX < precision)
			{
                resDiff = xK - (MediumDec)xKFl;
                precDiff = delX - (MediumDec)delXFl;
                std::cout << "Floating precision met at delX:" << delX.ToString() << " result currently at " << xK.ToString() << " with current result difference of " << resDiff.ToString() << " and current accuracy difference of " << precDiff.ToString() << std::endl;
			}
		} while (delXFl > 0.0000000000001);//(delX > precision);
		return xK;
	}

	/// <summary>
	/// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html while testing as floating at same time(for debugging)
	/// </summary>
	/// <param name="value">The target value.</param>
	/// <param name="Frac">The exponent value to raise the value to power of.</param>
	MediumDec FractionalPowTest(MediumDec targetVal, boost::rational<int> Frac)
	{
		MediumDec CalcVal = MediumDec::PowConstOp(targetVal, Frac.numerator());
		double floatingVal = (double)targetVal;
		double floatingRes = pow(floatingVal, Frac.numerator());
		MediumDec resDiff = CalcVal - (MediumDec)floatingRes;
		CalcVal = NthRootTest(CalcVal, Frac.denominator());
		floatingRes = BlazesFloatingCode::NthRootV3(floatingRes, Frac.denominator());
		resDiff = CalcVal - (MediumDec)floatingRes;
		return CalcVal;
	}

	/// <summary>
	/// Applies Power of operation while testing as floating at same time(for debugging)
	/// </summary>
	/// <param name="value">The target value.</param>
	/// <param name="expValue">The exponent value.</param>
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
}