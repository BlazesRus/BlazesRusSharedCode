// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"

#include "MediumDec.hpp"

//Bitwise based operation code likely mostly incorrect in calculations(not that important for moment)
//Optional rep based code will be finished last(not fully implimented yet) 

//Preprocessor Switches
/*
AltDec_SkipDivisionModulusAccuracyChecks = Skip if(SRep % Value.IntValue) checks for accuracy loss for some operations
AltDec_SeparateMixedFractionWithTile = Separate mixed fraction with _ instead of space on OptimalString
*/

namespace BlazesRusCode
{
    class AltDec;

    /// <summary>
    /// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
    /// Represents +- 2147483647.999999999 with 100% consistency of accuracy for most operations as long as don't get too small
    /// plus support for some fractal operations etc
	/// (Support for Num/denominator representation, (Value*PI), Mixed Fractions, and other optional reps)
	/// If AltDec_EnableImaginaryNum is true, then will support +- 2147483647.999999999i and +- 2147483647.999999999i/(Denom in range 1-2147483646)
	/// If AltDec_EnableInfinityRep is true, then will support positive and negative infinity representations
    /// (12 bytes worth of Variable Storage inside class for each instance)
    /// </summary>
    class DLL_API AltDec : BlazesRusCode::MediumDec
    {
    public:
		// <summary>
		/// If both DecimalHalf&ExtraRep are Positive with ExtraRep as non-zero, then ExtraRep acts as denominator
		/// If DecimalHalf is positive and ExtraRep is -2147483648, then AltDec represents +- 2147483647.999999999 * PI
		/// If DecimalHalf is negative and ExtraRep is Positive, then AltDec represents mixed fraction of -2147483648 to 2147483647 + (DecimalHalf*-1)/ExtraRep
		/// If ExtraRep is zero and DecimalHalf is positive, then AltDec represents +- 2147483647.999999999
		/// </summary>
		signed int ExtraRep;
		
		/// <summary>
		/// Initializes a new instance of the <see cref="AltDec"/> class.
		/// </summary>
		/// <param name="intVal">The int value.</param>
		/// <param name="decVal01">The decimal val01.</param>
		/// <param name="decVal02">ExtraRep.</param>
		AltDec(signed int intVal = 0, signed int decVal = 0, signed int extraVal = 0)
		{
			IntValue = intVal;
			DecimalHalf = decVal;
			ExtraRep = extraVal;
		}
		
		/// <summary>
		/// Sets the value.
		/// </summary>
		/// <param name="Value">The value.</param>
		void SetVal(AltDec Value)
		{
			IntValue = Value.IntValue;
			DecimalHalf01 = Value.DecimalHalf01; ExtraRep = Value.ExtraRep;
		}
		
		void SetPiVal(MediumDec Value)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = -2147483648;
		}
		
		void SetFractionalVal(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor;
		}
		
		void SetFractionalVal(int Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = 0;
			ExtraRep = Divisor;
		}
		
		void SetMixedFractionalVal(int WholeNum, int Numerator, int Denom)
		{
			IntValue = Value.IntValue;
			DecimalHalf = Numerator*-1;
			ExtraRep = Divisor;
		}
		
		void SetMixedFractionalValAsNeg(int WholeNum, int NumeratorAsNeg, int Denom)
		{
			IntValue = Value.IntValue;
			DecimalHalf = Numerator;
			ExtraRep = Divisor;
		}
		
#ifdef AltDec_EnableImaginaryNum
		void SetImaginaryVal(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = -2147483647;
		}
		
		void SetImaginaryFractionalVal(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor * -1;
		}
		
		void SetImaginaryFractionalVal(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor * -1;
		}
		
		void SetImaginaryFractionalValAsNeg(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor;
		}
#endif

#ifdef AltDec_EnableInfinityRep
		void SetAsPositiveInfinity()
		{
			IntValue = 2147483647; DecimalHalf = 2147483647; ExtraRep = 2147483647;
		}
		
		void SetAsNegativeInfinity()
		{
			IntValue = -2147483648; DecimalHalf = -2147483648; ExtraRep = -2147483648;
		}
#endif

		void UpdateValue(MediumDec& UpdateTarget)
		{
			if(ExtraRep==0)
			{
				UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
			}
			else if(ExtraRep==-2147483648)
			{
#ifdef AltDec_EnableInfinityRep//If Negative Infinity, then convert number into MinimumValue instead
				if(IntValue==-2147483648&&DecimalHalf==-2147483648)//Negative Infinity
				{
					UpdateTarget.IntValue = -2147483647; UpdateTarget.DecimalHalf = 999999999;
				}
				else
				{
#endif
				UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
				#ifdef AltDec_EnableInfinityRep
				}
#endif
			}
#ifdef AltDec_EnableImaginaryNum
			else(ExtraRep>0)
#else
			else
#endif
			{
				if(DecimalHalf<0)//Mixed Fraction
				{
					UpdateTarget.IntValue = DecimalHalf*-1; UpdateTarget.DecimalHalf = 0;
					UpdateTarget /= ExtraRep;
					UpdateTarget += IntValue;
				}
				else//Value Divided by ExtraRep
				{
					UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
					UpdateTarget /= ExtraRep;
				}
			}
#endif
#ifdef AltDec_EnableImaginaryNum
			else//(ExtraRep<0)Imaginary number representation doesn't exist for MediumDec
			{
			}
#endif
		}
    };
}