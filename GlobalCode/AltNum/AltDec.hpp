// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"

#include "MediumDec.hpp"
//Modulus code for Alternative Representations will be coded later(+,-,*,/ operations given priority)
//Bitwise based operation code will be coded later(not fully implimented yet--though likely inaccurate even for normal representation) 
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
	/// If AltDec_EnableENum is true and AltDec_EnableImaginaryNum is false(used when ExtraRep is negative if only one of them is enabled),
	///  then will support +- 2147483647.999999999E and +- 2147483647.999999999E/(Denom in range 1-2147483646)
	/// If AltDec_EnableImaginaryNum is true and AltDec_EnableENum is false(used when ExtraRep is negative if only one of them is enabled),
	///  then will support +- 2147483647.999999999i and +- 2147483647.999999999i/(Denom in range 1-2147483646)
	/// If both AltDec_EnableENum and AltDec_EnableImaginaryNum are enabled, then will support a lesser range of numbers for both
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
		
		void SetPiVal(int Value)
		{
			IntValue = Value; DecimalHalf = 0;
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
		
protected:
        static AltDec PINumValue()
        {
            return AltDec(3, 141592654, 0);
        }
		
        static AltDec ENumValue()
        {
			return AltDec(2, 718281828, 0);
        }
		
        static AltDec PIValue()
        {
            return AltDec(1, 0, -2147483648);
        }
		
        static AltDec EValue()
        {
#if !defined(AltDec_EnableENum)
            return AltDec(2, 718281828, 0);
#elif !defined(AltDec_EnableImaginaryNum)
			return AltDec(1, 0, -2147483647);
#else
			//Not Decided on format if both i and E alternative Representations enabled
#endif
        }
		
public:
		/// <summary>
        /// Returns PI(3.1415926535897932384626433) with tenth digit rounded up(3.141592654)
        /// </summary>
        /// <returns>MediumDec</returns>
		static AltDec PINum;
		
		/// <summary>
        /// Euler's number (Non-Alternative Representation)
        /// Irrational number equal to about (1 + 1/n)^n
        /// (about 2.71828182845904523536028747135266249775724709369995)
        /// </summary>
        /// <returns>MediumDec</returns>
		static AltDec ENum;
		
		static AltDec PI;
		
		static AltDec E;
		
#if defined(AltDec_EnableImaginaryNum) && (!defined(AltDec_EnableENum))
		void SetImaginaryVal(MediumDec Value)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = -2147483647;
		}
		
		void SetImaginaryVal(int Value)
		{
			IntValue = Value; DecimalHalf = 0;
			ExtraRep = -2147483647;
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

#if defined(AltDec_EnableENum) && (!defined(AltDec_EnableImaginaryNum))
		void SetEVal(MediumDec Value)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = -2147483647;
		}
		
		void SetEVal(int Value)
		{
			IntValue = Value; DecimalHalf = 0;
			ExtraRep = -2147483647;
		}
		
		void SetEFractionalVal(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor * -1;
		}
		
		void SetEFractionalValAsNeg(MediumDec Value, int Divisor)
		{
			IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
			ExtraRep = Divisor;
		}
#endif

#if defined(AltDec_EnableImaginaryNum) && defined(AltDec_EnableENum)

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
				if(DecimalHalf==0&&IntValue==10)
					UpdateTarget.IntValue = 31; UpdateTarget.DecimalHalf = 415926536;
				else
				{
					UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
					UpdateTarget *= MediumDec::PI;
				}
#ifdef AltDec_EnableInfinityRep
				}
#endif
			}
#if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
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
#if defined(AltDec_EnableImaginaryNum) || (!defined(AltDec_EnableENum)
			else//(ExtraRep<0)Imaginary number representation doesn't exist for MediumDec
			{
				UpdateTarget.SetVal(MediumDec::Nil);
			}
#elif defined(AltDec_EnableENum) || (!defined(AltDec_EnableImaginaryNum)
			else//(ExtraRep<0)
			{
				if(ExtraRep==-2147483647)
				{
					UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
					UpdateTarget *= MediumDec::E;
				}
				else
				{
					UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
					UpdateTarget *= MediumDec::E;
					UpdateTarget/= ExtraRep*-1;
				}
			}
#elif defined(AltDec_EnableImaginaryNum) && defined(AltDec_EnableENum)
			//Not decided on representation range if both are enabled
#endif
		}
		
		void ConvertToNumRep()
		{
			//if(ExtraRep==0)
			//{
			//	UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
			//}
			if(ExtraRep==-2147483648)
			{
#ifdef AltDec_EnableInfinityRep//If Negative Infinity, then convert number into MinimumValue instead
				if(IntValue==-2147483648&&DecimalHalf==-2147483648)//Negative Infinity
				{
					IntValue = -2147483647; DecimalHalf = 999999999;
				}
				else
				{
#endif
				if(DecimalHalf==0&&IntValue==10)
					IntValue = 31; DecimalHalf = 415926536;
				else
				{
					MediumDec::MultOp(this, PINum);
				}
#ifdef AltDec_EnableInfinityRep
				}
#endif
			}
			else(ExtraRep>0)
			{
				
				if(DecimalHalf<0)//Mixed Fraction
				{
					int TempAdd = IntValue;
					IntValue = DecimalHalf*-1; DecimalHalf = 0;
					MediumDec::DivOp(this, ExtraRep);
					MediumDec::AddOp(this, TempAdd);
				}
				else//Value Divided by ExtraRep
				{
					MediumDec::DivOp(this, ExtraRep);
				}
			}
#endif
#if defined(AltDec_EnableImaginaryNum) || (!defined(AltDec_EnableENum)
			else(ExtraRep<0)
			{
				IntValue = -2147483648;
			}
#elif defined(AltDec_EnableENum) || (!defined(AltDec_EnableImaginaryNum)
			else(ExtraRep<0)
			{
				if(ExtraRep==-2147483647)
				{
					MediumDec::MultOp(this, ENum);
				}
				else
				{
					MediumDec::MultOp(this, ENum);
					int TempDiv = ExtraRep*-1;
					MediumDec::DivOp(this, TempDiv);
				}
			}
#elif defined(AltDec_EnableImaginaryNum) && defined(AltDec_EnableENum)
			//Not decided on representation range if both are enabled
#endif
			ExtraRep = 0;
		}
		
    #pragma region Comparison Operators
        /// <summary>
        /// Equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator==(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            return (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf);
        }

        /// <summary>
        /// Not equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator!=(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            return (self.IntValue != Value.IntValue || self.DecimalHalf != Value.DecimalHalf);
        }

        /// <summary>
        /// Lesser than Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            if (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf) { return false; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return false; }// 5 > -5
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }// -5 <5
                else
                {//Both are either positive or negative
                    if (Value.DecimalHalf == 0)
                    {
                        if (self.DecimalHalf == 0)
                            return self.IntValue < Value.IntValue;
                        else
                        {
                            if (self.IntValue == NegativeZero)
                            {//-0.5<0
                                if (Value.IntValue >= 0)
                                    return true;
                            }
                            else if (self.IntValue < Value.IntValue) { return true; }//5.5 < 6
                            else if (self.IntValue == Value.IntValue) { return self.IntValue < 0 ? true : false; }//-5.5<-5 vs 5.5 > 5
                        }
                    }
                    else if (self.DecimalHalf == 0)
                    {
                        if (Value.IntValue == NegativeZero)
                        {
                            if (self.IntValue <= -1)
                                return true;
                        }
                        else if (self.IntValue < Value.IntValue)
                            return true;// 5 < 6.5
                        else if (Value.IntValue == self.IntValue)
                            return Value.IntValue < 0 ? false : true;//5 < 5.5 vs -5 > -5.5
                    }
                    //Assuming both are non-whole numbers if reach here
                    if (self.IntValue == NegativeZero)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeZero)
                        Value.IntValue = 0;
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf > Value.DecimalHalf;
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf < Value.DecimalHalf;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// Lesser than or Equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<=(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            if (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf) { return true; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return false; }//5>=-5
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }//-5<=5
                else
                {
                    if (Value.DecimalHalf == 0)
                    {
                        if (self.DecimalHalf == 0)
                            return self.IntValue <= Value.IntValue;
                        else
                        {
                            if (self.IntValue == NegativeZero)
                            {//-0.5<0
                                if (Value >= 0)
                                    return true;
                            }
                            else if (self.IntValue < Value) { return true; }//5.5<=6
                            else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }
                        }
                    }
                    else if (self.DecimalHalf == 0)
                    {
                        if (Value.IntValue == NegativeZero && self.IntValue <= 1)
                        {//-1<-0.5
                            if (self.IntValue <= -1)
                                return true;
                        }
                        else if (self.IntValue < Value.IntValue)
                            return true;
                        else if (Value.IntValue == self.IntValue)
                            return Value.IntValue < 0 ? false : true;//5 <= 5.5 vs -5 >= -5.5
                    }
                    //Assuming both are non-whole numbers if reach here
                    if (self.IntValue == NegativeZero)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeZero)
                        Value.IntValue = 0;
                    if (SelfIsNegative)//Both are either positive or negative
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf > Value.DecimalHalf;
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                            return true;
                        else if (self.IntValue == Value.IntValue)
                            return self.DecimalHalf < Value.DecimalHalf;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// Greater than Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The right side value.</param>
        /// <returns>bool</returns>
        friend bool operator>(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            if (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf) { return false; }
            else
            {

                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return true; }//5 > -5
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }//-5<5
                else if (Value.DecimalHalf == 0)
                {
                    if (self.DecimalHalf == 0)
                        return self.IntValue > Value.IntValue;
                    else
                    {
                        if (self.IntValue == NegativeZero)
                        {//-0.5>-1
                            if (Value <= -1)
                                return true;
                        }
                        else if (self.IntValue > Value) { return true; }
                        else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }
                    }
                }
                else if (self.DecimalHalf == 0)
                {
                    if (Value.IntValue == NegativeZero)
                    {
                        if (self.IntValue >= 0)
                            return true;
                    }
                    else if (self.IntValue > Value.IntValue)
                        return true;
                    else if (Value.IntValue == self.IntValue)
                        return Value.IntValue < 0 ? true : false;//5 < 5.5 vs -5 > -5.5
                }
                //Assuming both are non-whole numbers if reach here
                if (self.IntValue == NegativeZero)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeZero)
                    Value.IntValue = 0;
                if (SelfIsNegative)//Both are either positive or negative
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf < Value.DecimalHalf;
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf > Value.DecimalHalf;
                }
            }
            return false;
        }

        /// <summary>
        /// Greater than or Equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator>=(AltDec self, AltDec Value)
        {
			self.ConvertToNumRep(); Value.ConvertToNumRep();
            if (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf) { return true; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValueIsNegative = Value.IntValue < 0;
                if (ValueIsNegative && SelfIsNegative == false) { return true; }
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }
                else if (Value.DecimalHalf == 0)
                {
                    if (self.DecimalHalf == 0)
                        return self.IntValue >= Value.IntValue;
                    else
                    {
                        if (self.IntValue == NegativeZero)
                        {
                            if (Value <= -1)
                                return true;
                        }
                        else if (self.IntValue > Value)
                            return true;
                        else if (self.IntValue == Value)
                            return self.IntValue < 0 ? false : true;//-5.5<-5 vs 5.5>5
                    }
                }
                else if (self.DecimalHalf == 0)//return self.IntValue > Value;
                {
                    if (Value.IntValue == NegativeZero)
                    {//0>-0.5
                        if (self.IntValue >= 0)
                            return true;
                    }
                    else if (self.IntValue > Value.IntValue)
                        return true;
                    else if (Value.IntValue == self.IntValue)
                        return Value.IntValue < 0 ? true : false;//5 <= 5.5 vs -5 >= -5.5
                }
                //Assuming both are non-whole numbers if reach here
                if (self.IntValue == NegativeZero)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeZero)
                    Value.IntValue = 0;
                if (SelfIsNegative)//Both are either positive or negative
                {//Larger number = farther down into negative
                    if (self.IntValue < Value.IntValue)//-5.5 >= -6.5
                        return true;
                    else if (self.IntValue == Value.IntValue)//-5.5 >= -5.6
                        return self.DecimalHalf < Value.DecimalHalf;
                }
                else
                {
                    if (self.IntValue > Value.IntValue)
                        return true;
                    else if (self.IntValue == Value.IntValue)
                        return self.DecimalHalf > Value.DecimalHalf;
                }
            }
            return false;
        }
    #pragma endregion Comparison Operators
		
    #pragma region AltDec-To-AltDec Operators
    public:
        /// <summary>
        /// Addition Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec& AddOp(AltDec& self, AltDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return self;
                if (self.DecimalHalf == 0)
                {
                    self.IntValue += Value.IntValue;
                }
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                    self.IntValue += Value.IntValue;
                    if (self.IntValue == -1)
                        self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                    else if (self.IntValue < 0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = self.IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                if (Value.IntValue != 0 && Value.IntValue != AltDec::NegativeZero)
                    self.IntValue += Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)
                    {
                        self.DecimalHalf += Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; ++self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; --self.IntValue; }
                    }
                    else
                    {
                        self.DecimalHalf -= Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; --self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; ++self.IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)
                    {
                        self.DecimalHalf -= Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; ++self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; --self.IntValue; }
                    }
                    else
                    {
                        self.DecimalHalf += Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; --self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; ++self.IntValue; }
                    }
                }
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& SubOp(AltDec& self, AltDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return self;
                if (self.DecimalHalf == 0)
                {
                    self.IntValue -= Value.IntValue;
                }
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                    if (Value.IntValue != 0)
                        self.IntValue -= Value.IntValue;
                    if(self.IntValue==-1)
                        self.IntValue = self.DecimalHalf == 0?0:AltDec::NegativeZero;
                    else if(self.IntValue<0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0)||(WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = self.IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                if(Value.IntValue!=0&&Value.IntValue!=AltDec::NegativeZero)
                    self.IntValue -= Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)//-4.0 - -0.5 = -3.5
                    {
                        self.DecimalHalf -= Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; ++self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; --self.IntValue; }
                    }
                    else//4.3 -  - 1.8
                    {
                        self.DecimalHalf += Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; --self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; ++self.IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)//-4.5 - 5.6
                    {
                        self.DecimalHalf += Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; ++self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; --self.IntValue; }
                    }
                    else//0.995 - 1 = 
                    {
                        self.DecimalHalf -= Value.DecimalHalf;
                        if (self.DecimalHalf < 0) { self.DecimalHalf += AltDec::DecimalOverflow; --self.IntValue; }
                        else if (self.DecimalHalf >= AltDec::DecimalOverflow) { self.DecimalHalf -= AltDec::DecimalOverflow; ++self.IntValue; }
                    }
                }
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Multiplication Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& MultOp(AltDec& self, AltDec& Value)
        {
            if (Value == AltDec::Zero) { self.IntValue = 0; self.DecimalHalf = 0; return self; }
            if (self == AltDec::Zero || Value == AltDec::One)
                return self;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == AltDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if (self.DecimalHalf == 0)
            {
                if (self.IntValue == 1) { self = Value; return self; }
                else if (Value.DecimalHalf == 0)
                {
                    self.IntValue *= Value.IntValue; return self;
                }
                else
                {
                    Value *= self.IntValue;
                    self = Value;
                }
            }
            else if (self.IntValue == 0)
            {
                __int64 SRep = (__int64)self.DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= AltDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)self.DecimalHalf * Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = OverflowVal;
                        self.DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        self.DecimalHalf = (signed int)SRep;
                    }
                }
            }
            else if (self.IntValue == AltDec::NegativeZero)
            {
                __int64 SRep = (__int64)self.DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= AltDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)self.DecimalHalf * Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = -OverflowVal;
                        self.DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        self.DecimalHalf = (signed int)SRep;
                    }
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.IntValue == 0)
                {
                    __int64 SRep = AltDec::DecimalOverflowX * self.IntValue + self.DecimalHalf;
                    SRep *= Value.DecimalHalf;
                    SRep /= AltDec::DecimalOverflowX;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = (signed int)(SelfIsNegative ? -OverflowVal : OverflowVal);
                        self.DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = SelfIsNegative ? AltDec::NegativeZero : 0;
                        self.DecimalHalf = (signed int)SRep;
                    }
                }
                else if (Value.DecimalHalf == 0)//Y is integer
                {
                    __int64 SRep = AltDec::DecimalOverflowX * self.IntValue + self.DecimalHalf;
                    SRep *= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = (signed int)OverflowVal;
                        self.DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        self.IntValue = 0;
                        self.DecimalHalf = (signed int)SRep;
                    }
                    return self;
                }
                else
                {
                    //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                    __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : AltDec::DecimalOverflowX * self.IntValue + self.DecimalHalf;
                    SRep *= Value.IntValue;//SRep holds __int64 version of X.Y * Z
                    //X.Y *.V
                    __int64 Temp03 = (__int64)self.IntValue * Value.DecimalHalf;//Temp03 holds __int64 version of X *.V
                    __int64 Temp04 = (__int64)self.DecimalHalf * (__int64)Value.DecimalHalf;
                    Temp04 /= AltDec::DecimalOverflow;
                    //Temp04 holds __int64 version of .Y * .V
                    __int64 IntegerRep = SRep + Temp03 + Temp04;
                    __int64 IntHalf = IntegerRep / AltDec::DecimalOverflow;
                    IntegerRep -= IntHalf * (__int64)AltDec::DecimalOverflow;
                    if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? AltDec::NegativeZero : 0; }
                    else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    self.DecimalHalf = (signed int)IntegerRep;
                }
            }
            if (self == AltDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }

        /// <summary>
        /// Division Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& DivOp(AltDec& self, AltDec& Value)
        {
            if (Value == AltDec::Zero)
                throw "Target value can not be divided by zero";
            if (self == AltDec::Zero)
                return self;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == AltDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if (self.DecimalHalf == 0)
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.DecimalHalf == 0)//Both are integers
                {
                    if (self.IntValue < 0) { self.IntValue *= -1; }
                    __int64 SRep = self.IntValue * AltDec::DecimalOverflowX;
                    __int64 YRep = Value.IntValue;
                    SRep /= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = SelfIsNegative ? AltDec::NegativeZero : 0;
                    }
                    self.DecimalHalf = (signed int)SRep;
                }
                else//Only self is integer while Value has both sides
                {
                    boost::multiprecision::uint128_t SRep02 = AltDec::DecimalOverflowX * AltDec::DecimalOverflowX;
                    SRep02 *= self.IntValue;
                    __int64 VRep = AltDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = 0;
                    }
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            else if (self.IntValue == 0)
            {
                __int64 SRep = (__int64)self.DecimalHalf * AltDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / AltDec::DecimalOverflowX;
                SRep -= IntHalf * AltDec::DecimalOverflowX;
                self.IntValue = IntHalf;
                self.DecimalHalf = (signed int)SRep;
            }
            else if (self.IntValue == AltDec::NegativeZero)
            {
                __int64 SRep = (__int64)self.DecimalHalf * AltDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / AltDec::DecimalOverflowX;
                SRep -= IntHalf * AltDec::DecimalOverflowX;
                self.IntValue = IntHalf == 0 ? AltDec::NegativeZero : -IntHalf;
                self.DecimalHalf = (signed int)SRep;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    self.IntValue *= -1;
                }
                if (Value.DecimalHalf == 0)//Y is integer but self is not
                {
                    __int64 SRep = AltDec::DecimalOverflowX * self.IntValue + self.DecimalHalf;
                    SRep /= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        self.IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        self.IntValue = 0;
                    }
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {//Splitting Integer Half and Decimal Half Division
                    __int64 SRep_DecHalf = (__int64)self.DecimalHalf * AltDec::DecimalOverflowX;
                    SRep_DecHalf /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                    int IntHalf = SRep_DecHalf / AltDec::DecimalOverflowX;
                    SRep_DecHalf -= IntHalf * AltDec::DecimalOverflowX;

                    boost::multiprecision::uint128_t SRep02 = AltDec::DecimalOverflowX * AltDec::DecimalOverflowX;
                    //std::cout << "Multi-precision as String:" << SRep02 << std::endl;
                    SRep02 *= self.IntValue;
                    __int64 VRep = AltDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02 + SRep_DecHalf;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntHalf += OverflowVal;
                    }
                    if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? AltDec::NegativeZero : 0; }
                    else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            if (self == AltDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }

        /// <summary>
        /// Remainder/Modulus Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec&</returns>
        static AltDec& RemOp(AltDec& self, AltDec& Value)
        {
            bool SelfIsWholeN = self.DecimalHalf == 0;
            bool ValueIsWholeN = Value.DecimalHalf == 0;
            if (Value.IntValue == 0 && ValueIsWholeN) { return AltDec::Zero; }//Return zero instead of N/A
            if (SelfIsWholeN && ValueIsWholeN)//WholeNumbers
            {
                self.IntValue %= Value.IntValue;
            }
            else if (ValueIsWholeN)
            {
                self %= Value.IntValue;
            }
            else
            {
                //bool ValueIsNegative = Value.IntValue < 0;
                if (Value.IntValue < 0)
                {
                    self.IntValue *= -1;
                    if (Value.IntValue == NegativeZero) { Value.IntValue = 0; }
                }
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                __int64 SRep_DecHalf = SRep;
                __int64 VRep = DecimalOverflowX * Value.IntValue + Value.DecimalHalf;;
                SRep %= VRep;
                __int64 IntResult = SRep;
                //Int Half Calculated now get decimal digits that got truncated off
                SRep_DecHalf -= IntResult * VRep;
                //Gives enough buffer room that doesn't lose the decimal values
                SRep_DecHalf *= DecimalOverflowX;
                SRep_DecHalf %= VRep;
                if (IntResult == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
                else { self.IntValue = (signed int)SelfIsNegative ? IntResult * -1 : IntResult; }
                self.DecimalHalf = (signed int)SRep;
            }
            return self;
        }
        
    public:
        /// <summary>
        /// Addition Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec operator+(AltDec self, AltDec Value)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// += Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator+=(AltDec& self, AltDec Value)
        {
            return AddOp(self, Value);
        }
        
        /// <summary>
        /// += Operation Between AltDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator+=(AltDec* self, AltDec Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec operator-(AltDec self, AltDec Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator-=(AltDec& self, AltDec Value)
        {
            return SubOp(self, Value);
        }
        
        /// <summary>
        /// -= Operation Between AltDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator-=(AltDec* self, AltDec Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec operator*(AltDec self, AltDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between AltDecs
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>AltDec</returns>
        friend AltDec& operator*=(AltDec& self, AltDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between AltDecs (from pointer)
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>AltDec</returns>
        friend AltDec& operator*=(AltDec* self, AltDec Value){ return MultOp(**self, Value); }


        /// <summary>
        /// Division Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec operator/(AltDec self, AltDec Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator/=(AltDec& self, AltDec Value)
        {
            return DivOp(self, Value);
        }
        
        /// <summary>
        /// /= Operation Between AltDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator/=(AltDec* self, AltDec Value){ return DivOp(**self, Value); }

        /// <summary>
        /// Remainder Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec</returns>
        friend AltDec operator%(AltDec self, AltDec Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator%=(AltDec& self, AltDec Value)
        {
            return RemOp(self, Value);
        }
        
        /// <summary>
        /// %= Operation Between AltDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator%=(AltDec* self, AltDec Value)
        {
            return RemOp(**self, Value);
        }

        /// <summary>
        /// XOR Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec</returns>
        friend AltDec operator^(AltDec self, AltDec Value)
        {
            if (self.DecimalHalf == 0 && Value.DecimalHalf == 0)//Whole Numbers
            {
                self.IntValue ^= Value.IntValue; return self;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value.IntValue < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 ^ Value.IntValue) * -1;
                    self.DecimalHalf ^= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeZero)
                    {
                        self.IntValue = (self.IntValue ^ 0) * -1;
                        self.DecimalHalf ^= Value.DecimalHalf;
                    }
                    else
                    {
                        self.IntValue ^= Value.IntValue; self.DecimalHalf ^= Value.DecimalHalf;
                    }
                }
            }
            return self;
        }

        /// <summary>
        /// Bitwise Or Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec</returns>
        friend AltDec operator|(AltDec self, AltDec Value)
        {
            if (self.DecimalHalf == 0 && Value.DecimalHalf == 0)//Whole Numbers
            {
                self.IntValue |= Value.IntValue; return self;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value.IntValue < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 | Value.IntValue) * -1;
                    self.DecimalHalf |= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeZero)
                    {
                        self.IntValue = (self.IntValue & 0) * -1;
                        self.DecimalHalf |= Value.DecimalHalf;
                    }
                    else
                    {
                        self.IntValue |= Value.IntValue; self.DecimalHalf |= Value.DecimalHalf;
                    }
                }
            }
            return self;
        }
        /// <summary>
        /// Bitwise And Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec</returns>
        friend AltDec operator&(AltDec self, AltDec Value)
        {
            if (self.DecimalHalf == 0 && Value.DecimalHalf == 0)//Whole Numbers
            {
                self.IntValue &= Value.IntValue; return self;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value.IntValue < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 & Value.IntValue) * -1;
                    self.DecimalHalf &= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeZero)
                    {
                        self.IntValue = (self.IntValue & 0) * -1;
                        self.DecimalHalf &= Value.DecimalHalf;
                    }
                    else
                    {
                        self.IntValue &= Value.IntValue; self.DecimalHalf &= Value.DecimalHalf;
                    }
                }
            }
            return self;
        }

        /// <summary>
        /// Negative Unary Operator(Flips negative status)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <returns>AltDec</returns>
        friend AltDec& operator-(AltDec& self)
        {
            self.SwapNegativeStatus(); return self;
        }

        /// <summary>
        /// ++AltDec Operator
        /// </summary>
        /// <returns>AltDec &</returns>
        AltDec& operator ++()
        {
            if (IntValue == NegativeZero) { IntValue = 0; }
            else if (DecimalHalf == 0) { ++IntValue; }
            else if (IntValue == -1) { IntValue = NegativeZero; }
            else { ++IntValue; }
            return *this;
        }

        /// <summary>
        /// ++AltDec Operator
        /// </summary>
        /// <returns>AltDec &</returns>
        AltDec& operator --()
        {
            if (IntValue == NegativeZero) { IntValue = -1; }
            else if (DecimalHalf == 0) { --IntValue; }
            else if (IntValue == 0) { IntValue = NegativeZero; }
            else { --IntValue; }
            return *this;
        }

        /// <summary>
        /// AltDec++ Operator
        /// </summary>
        /// <returns>AltDec</returns>
        AltDec operator ++(int)
        {
            AltDec tmp(*this);
            ++* this;
            return tmp;
        }

        /// <summary>
        /// AltDec-- Operator
        /// </summary>
        /// <returns>AltDec</returns>
        AltDec operator --(int)
        {
            AltDec tmp(*this);
            --* this;
            return tmp;
        }

        /// <summary>
        /// AltDec* Operator
        /// </summary>
        /// <returns>AltDec &</returns>
        AltDec& operator *()
        {
            return *this;
        }
    #pragma endregion AltDec-To-AltDec Operators

    #pragma region AltDec-To-Int Comparison Operators
        /// <summary>
        /// Equality Operation between <see cref="AltDec &"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            return (self.IntValue == Value && self.DecimalHalf == 0);
        }

        /// <summary>
        /// != Operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return self.IntValue < Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5<0
                    if (Value >= 0)
                        return true;
                }
                else if (self.IntValue < Value) { return true; }//5.5 < 6
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//-5.5<-5 vs 5.5 > 5
            }
            return false;
        }
        /// <summary>
        /// Lesser than or equal to operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return self.IntValue <= Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5<0
                    if (Value >= 0)
                        return true;
                }
                else if (self.IntValue < Value) { return true; }//5.5<=6
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }
            }
            return false;
        }
        /// <summary>
        /// Greater than operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return self.IntValue > Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//-0.5>-1
                    if (Value <= -1)
                        return true;
                }
                else if (self.IntValue > Value) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }
            }
            return false;
        }
        /// <summary>
        /// Greater than or equal to operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(AltDec self, IntType Value)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return self.IntValue >= Value;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value <= -1)
                        return true;
                }
                else if (self.IntValue > Value) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//-5.5<-5 vs 5.5>5
            }
            return false;
        }

        /// <summary>
        /// Equality Operation between Integer Type and <see cref="AltDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            return (self.IntValue == Value && self.DecimalHalf == 0);
        }

        /// <summary>
        /// != Operation between Integer Type and <see cref="AltDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between Integer Type and <see cref="AltDec"/> .
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return Value < self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value <= -1)
                        return true;
                }
                else if (Value < self.IntValue) { return true; }// 5 < 6.5
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//5 < 5.5 vs -5 > -5.5
            }
            return false;
        }
        /// <summary>
        /// Lesser than or equal to operation between Integer Type and <see cref="AltDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return Value <= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero && Value <= 1)
                {//-1<-0.5
                    if (Value <= -1)
                        return true;
                }
                else if (Value < self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? false : true; }//5 <= 5.5 vs -5 >= -5.5
            }
            return false;
        }
        /// <summary>
        /// Greater than operation between Integer Type and <see cref="AltDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return Value > self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {
                    if (Value >= 0)
                        return true;
                }
                else if (Value > self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//5 < 5.5 vs -5 > -5.5
            }
            return false;
        }
        /// <summary>
        /// Greater than or equal to operation between <see cref="AltDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(IntType Value, AltDec self)
        {
			self.ConvertToNumRep();
            if (self.DecimalHalf == 0)
            {
                return Value >= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeZero)
                {//0>-0.5
                    if (Value >= 0)
                        return true;
                }
                else if (Value > self.IntValue) { return true; }
                else if (self.IntValue == Value) { return self.IntValue < 0 ? true : false; }//5 <= 5.5 vs -5 >= -5.5
            }
            return false;
        }

    #pragma endregion AltDec-To-Int Comparison Operators
    #pragma region Other Operations
        friend AltDec operator+(AltDec self, float Value) { return self + (AltDec)Value; }
        friend AltDec operator-(AltDec self, float Value) { return self - (AltDec)Value; }
        friend AltDec operator*(AltDec self, float Value) { return self * (AltDec)Value; }
        friend AltDec operator/(AltDec self, float Value) { return self / (AltDec)Value; }
        friend AltDec operator%(AltDec self, float Value) { return self % (AltDec)Value; }
        friend AltDec operator^(AltDec self, float Value) { return self ^ (AltDec)Value; }
        friend AltDec operator|(AltDec self, float Value) { return self | (AltDec)Value; }
        friend AltDec operator&(AltDec self, float Value) { return self & (AltDec)Value; }

        friend AltDec operator+(float Value, AltDec self) { return (AltDec)Value + self; }
        friend AltDec operator-(float Value, AltDec self) { return (AltDec)Value - self; }
        friend AltDec operator*(float Value, AltDec self) { return (AltDec)Value * self; }
        friend AltDec operator/(float Value, AltDec self) { return (AltDec)Value / self; }
        friend AltDec operator%(float Value, AltDec self) { return (AltDec)Value % self; }
        friend AltDec operator^(float Value, AltDec self) { return (AltDec)Value ^ self; }
        friend AltDec operator|(float Value, AltDec self) { return (AltDec)Value | self; }
        friend AltDec operator&(float Value, AltDec self) { return (AltDec)Value & self; }

        friend AltDec operator+(AltDec self, double Value) { return self + (AltDec)Value; }
        friend AltDec operator-(AltDec self, double Value) { return self - (AltDec)Value; }
        friend AltDec operator*(AltDec self, double Value) { return self * (AltDec)Value; }
        friend AltDec operator/(AltDec self, double Value) { return self / (AltDec)Value; }
        friend AltDec operator%(AltDec self, double Value) { return self % (AltDec)Value; }
        friend AltDec operator^(AltDec self, double Value) { return self ^ (AltDec)Value; }
        friend AltDec operator|(AltDec self, double Value) { return self | (AltDec)Value; }
        friend AltDec operator&(AltDec self, double Value) { return self & (AltDec)Value; }

        friend AltDec operator+(double Value, AltDec self) { return (AltDec)Value + self; }
        friend AltDec operator-(double Value, AltDec self) { return (AltDec)Value - self; }
        friend AltDec operator*(double Value, AltDec self) { return (AltDec)Value * self; }
        friend AltDec operator/(double Value, AltDec self) { return (AltDec)Value / self; }
        friend AltDec operator%(double Value, AltDec self) { return (AltDec)Value % self; }
        friend AltDec operator^(double Value, AltDec self) { return (AltDec)Value ^ self; }
        friend AltDec operator|(double Value, AltDec self) { return (AltDec)Value | self; }
        friend AltDec operator&(double Value, AltDec self) { return (AltDec)Value & self; }

        friend AltDec operator+(AltDec self, ldouble Value) { return self + (AltDec)Value; }
        friend AltDec operator-(AltDec self, ldouble Value) { return self - (AltDec)Value; }
        friend AltDec operator*(AltDec self, ldouble Value) { return self * (AltDec)Value; }
        friend AltDec operator/(AltDec self, ldouble Value) { return self / (AltDec)Value; }
        friend AltDec operator%(AltDec self, ldouble Value) { return self % (AltDec)Value; }
        friend AltDec operator^(AltDec self, ldouble Value) { return self ^ (AltDec)Value; }
        friend AltDec operator|(AltDec self, ldouble Value) { return self | (AltDec)Value; }
        friend AltDec operator&(AltDec self, ldouble Value) { return self & (AltDec)Value; }

        friend AltDec operator+(ldouble Value, AltDec self) { return (AltDec)Value + self; }
        friend AltDec operator-(ldouble Value, AltDec self) { return (AltDec)Value - self; }
        friend AltDec operator*(ldouble Value, AltDec self) { return (AltDec)Value * self; }
        friend AltDec operator/(ldouble Value, AltDec self) { return (AltDec)Value / self; }
        friend AltDec operator%(ldouble Value, AltDec self) { return (AltDec)Value % self; }
        friend AltDec operator^(ldouble Value, AltDec self) { return (AltDec)Value ^ self; }
        friend AltDec operator|(ldouble Value, AltDec self) { return (AltDec)Value | self; }
        friend AltDec operator&(ldouble Value, AltDec self) { return (AltDec)Value & self; }
    #pragma endregion Other Operations
		
#pragma region AltDec-To-Integer Operations
    public:
        /// <summary>
        /// Addition Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& AddOp(AltDec& self, IntType& value)
        {
            if (value == 0)
                return self;
            if (self.DecimalHalf == 0)
                self.IntValue += value;
            else
            {
                bool WasNegative = self.IntValue < 0;
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                self.IntValue += value;
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        static AltDec& SubOp(AltDec& self, IntType& value)
        {
            if (value == 0)
                return self;
            if (self.DecimalHalf == 0)
                self.IntValue -= value;
            else
            {
                bool WasNegative = self.IntValue < 0;
                if (WasNegative)
                    self.IntValue = self.IntValue==AltDec::NegativeZero ? -1 : --self.IntValue;
                self.IntValue -= value;
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        static AltDec& MultOp(AltDec& self, IntType& Value)
        {
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
            if (self == Zero) {}
            else if (Value == 0) { self.IntValue = 0; self.DecimalHalf = 0; }
            else if (self.DecimalHalf == 0)
            {
                self.IntValue *= Value;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                SRep *= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= OverflowVal * DecimalOverflowX;
                    self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = SelfIsNegative?NegativeZero:0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            return self;
        }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& DivOp(AltDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            else if (self == Zero) { return self; }
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
            if (self.DecimalHalf == 0)
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                    self.IntValue *= -1;
                __int64 SRep = DecimalOverflowX * self.IntValue;
                SRep /= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflow;
                    SRep -= OverflowVal * DecimalOverflow;
                    self.IntValue = (signed int)(SelfIsNegative ? OverflowVal * -1 : OverflowVal);
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = SelfIsNegative?NegativeZero:0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                SRep /= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= DecimalOverflowX * OverflowVal;
                    self.IntValue = (signed int)(SelfIsNegative ? OverflowVal * -1 : OverflowVal);
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = 0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            if (self == Zero) { return JustAboveZero; }//Prevent dividing into nothing
            return self;
        }

        /// <summary>
        /// Remainder/Modulus Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& RemOp(AltDec& self, IntType& Value)
        {
            if (Value == 0 || self == AltDec::Zero) { return AltDec::Zero; }
            if (self.DecimalHalf == 0)
            {
                if (self.IntValue < 0)//https://www.quora.com/How-does-the-modulo-operation-work-with-negative-numbers-and-why
                {
                    self.IntValue %= Value;
                    self.IntValue = (signed int)(Value - self.IntValue);
                }
                else
                {
                    self.IntValue %= Value; return self;
                }
            }
            else//leftValue is non-whole number
            {
                if (Value < 0) { self.SwapNegativeStatus(); Value *= -1; }
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                SRep %= Value;
                __int64 VRep = DecimalOverflowX * Value;
                SRep /= VRep;
                __int64 IntResult = SRep;
                SRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalHalf;
                SRep -= IntResult * VRep;
                __int64 IntHalf = SRep / DecimalOverflow;
                SRep -= IntHalf * (__int64)DecimalOverflow;
                if (IntHalf == 0) { self.IntValue = SelfIsNegative ? (signed int)NegativeZero : 0; }
                else { self.IntValue = (signed int)(SelfIsNegative ? IntHalf * -1 : IntHalf); }
                self.DecimalHalf = (signed int)SRep;
            }
            return self;
        }

        /// <summary>
        /// Addition Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& UnsignedAddOp(AltDec& self, IntType& value)
        {
            if(value==0){ return self; }
            else if(self.DecimalHalf==0|| self.IntValue > 0)
                self.IntValue += value;
            else
            {
                bool WasNegative = self.IntValue < 0;
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                self.IntValue += value;
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        static AltDec& UnsignedSubOp(AltDec& self, IntType& value)
        {
            if (value == 0) { return self; }
            else if (self.DecimalHalf == 0)
                self.IntValue -= value;
            else if (self.IntValue == NegativeZero)
                self.IntValue = (signed int)value * -1;
            else if(self.IntValue < 0)
                self.IntValue -= value;
            else
            {
                bool WasNegative = self.IntValue < 0;
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeZero ? -1 : --self.IntValue;
                self.IntValue -= value;
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeZero;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
            }
            return self;
        }

        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        static AltDec& UnsignedMultOp(AltDec& self, IntType& Value)
        {
            if (self == Zero) {}
            else if (Value == 0) { self.IntValue = 0; self.DecimalHalf = 0; }
            else if (self.DecimalHalf == 0)
            {
                self.IntValue *= Value;
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                SRep *= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= OverflowVal * DecimalOverflowX;
                    self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = SelfIsNegative?NegativeZero:0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            return self;
        }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& UnsignedDivOp(AltDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            else if (self == Zero) { return self; }
            if (self.DecimalHalf == 0)
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                    self.IntValue *= -1;
                __int64 SRep = DecimalOverflowX * self.IntValue;
                SRep /= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflow;
                    SRep -= OverflowVal * DecimalOverflow;
                    self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = SelfIsNegative?NegativeZero:0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeZero) { self.IntValue = 0; }
                    else { self.IntValue *= -1; }
                }
                __int64 SRep = self.IntValue == 0 ? self.DecimalHalf : DecimalOverflowX * self.IntValue + self.DecimalHalf;
                SRep /= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= DecimalOverflowX * OverflowVal;
                    self.IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    self.DecimalHalf = (signed int)SRep;
                }
                else
                {
                    self.IntValue = 0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            return self;
        }
        
        /// <summary>
        /// Remainder/Modulus Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& UnsignedRemOp(AltDec& self, IntType& Value)
        {
            if(self == AltDec::Zero) { return self; }
            if (Value == 0){ self.IntValue=0; self.DecimalHalf = 0; return self; }
            if (self.DecimalHalf == 0)
            {
                self.IntValue %= Value; return self;
            }
            else//leftValue is non-whole number
            {
                __int64 SRep;
                if (self.IntValue == NegativeZero) { SRep = (__int64)self.DecimalHalf * -1; }
                else if (self.IntValue < 0) { SRep = DecimalOverflowX * self.IntValue - self.DecimalHalf; }
                else { SRep = DecimalOverflowX * self.IntValue + self.DecimalHalf; }
                bool SelfIsNegative = SRep < 0;
                if (SelfIsNegative) { SRep *= -1; }
                SRep %= Value;
                __int64 VRep = DecimalOverflowX * Value;
                SRep /= VRep;
                __int64 IntResult = SRep;
                SRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalHalf;
                SRep -= IntResult * VRep;
                __int64 IntHalf = SRep / DecimalOverflow;
                SRep -= IntHalf * (__int64)DecimalOverflow;
                if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeZero : 0; }
                else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                self.DecimalHalf = (signed int)SRep;
            }
            return self;
        }
		
    public:
        friend AltDec operator+(AltDec self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-(AltDec self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*(AltDec self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/(AltDec self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%(AltDec self, unsigned char Value){ return UnsignedRemOp(self, Value); }
        
        friend AltDec operator+=(AltDec& self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-=(AltDec& self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*=(AltDec& self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/=(AltDec& self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%=(AltDec& self, unsigned char Value){ return UnsignedRemOp(self, Value); }

        friend AltDec operator+(AltDec self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-(AltDec self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*(AltDec self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/(AltDec self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%(AltDec self, unsigned short Value){ return UnsignedRemOp(self, Value); }
        
        friend AltDec operator+=(AltDec& self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-=(AltDec& self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*=(AltDec& self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/=(AltDec& self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%=(AltDec& self, unsigned short Value){ return UnsignedRemOp(self, Value); }

        friend AltDec operator+(AltDec self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-(AltDec self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*(AltDec self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/(AltDec self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%(AltDec self, unsigned int Value){ return UnsignedRemOp(self, Value); }
        
        friend AltDec operator+=(AltDec& self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-=(AltDec& self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*=(AltDec& self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/=(AltDec& self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%=(AltDec& self, unsigned int Value){ return UnsignedRemOp(self, Value); }

        friend AltDec operator+(AltDec self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-(AltDec self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*(AltDec self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/(AltDec self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%(AltDec self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }
        
        friend AltDec operator+=(AltDec& self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend AltDec operator-=(AltDec& self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend AltDec operator*=(AltDec& self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend AltDec operator/=(AltDec& self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend AltDec operator%=(AltDec& self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }

        /// <summary>
        /// Addition Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator+(AltDec self, IntType Value)
        {
            return AddOp(self, Value);
        }

        ///// <summary>
        ///// += Operation Between AltDec and Integer Value
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator+=(AltDec& self, IntType Value)
        {
            return AddOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator+=(AltDec* self, IntType Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator-(AltDec self, IntType Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator-=(AltDec& self, IntType Value)
        {
            return SubOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator-=(AltDec* self, IntType Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*(AltDec self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*=(AltDec& self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between AltDec and Integer Value (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*=(AltDec* self, IntType Value){ return MultOp(**self, Value); }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator/(AltDec self, IntType Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator/=(AltDec& self, IntType Value)
        {
            return DivOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator/=(AltDec* self, IntType Value){ return DivOp(**self, Value); }
        
        /// <summary>
        /// Modulus Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator%(AltDec self, IntType Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator%=(AltDec& self, IntType Value)
        {
            return RemOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator%=(AltDec* self, IntType Value){ return RemOp(**self, Value); }

        /// <summary>
        /// Bitwise XOR Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator^(AltDec self, IntType Value)
        {
            if (self.DecimalHalf == 0) { self.IntValue ^= Value; return self; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 & Value) * -1;
                    self.DecimalHalf ^= Value;
                }
                else
                {
                    self.IntValue ^= Value; self.DecimalHalf ^= Value;
                }
            }
            return self;
        }

        /// <summary>
        /// Bitwise Or Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator|(AltDec self, IntType Value)
        {
            if (self.DecimalHalf == 0) { self.IntValue |= Value; return self; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 & Value) * -1;
                    self.DecimalHalf |= Value;
                }
                else
                {
                    self.IntValue |= Value; self.DecimalHalf |= Value;
                }
            }
            return self;
        }

        /// <summary>
        /// Bitwise And Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator&(AltDec self, IntType Value)
        {
            if (self.DecimalHalf == 0) { self.IntValue &= Value; return self; }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                bool ValIsNegative = Value < 0;
                if (SelfIsNegative && self.IntValue == NegativeZero)
                {
                    self.IntValue = (0 & Value) * -1;
                    self.DecimalHalf &= Value;
                }
                else
                {
                    self.IntValue &= Value; self.DecimalHalf &= Value;
                }
            }
            return self;
        }
    #pragma endregion AltDec-To-Integer Operations
    #pragma region Integer-To-AltDec Operations
        /// <summary>
        /// Addition Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator+(IntType Value, AltDec self)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// Subtraction Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator-(IntType Value, AltDec self)
        {
            AltDec Result = Value;
            return SubOp(Result, self);
        }

        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*(IntType Value, AltDec self)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator/(IntType Value, AltDec self)
        {
            AltDec Result = Value;
            return DivOp(Result, self);
        }

        /// <summary>
        /// Remainder/Modulus Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator%(IntType Value, AltDec self)
        {
            AltDec Result = Value;
            return RemOp(Result, self);
        }

        /// <summary>
        /// Bitwise XOR Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator^(IntType Value, AltDec self)
        {
            return (AltDec)Value ^ self;
        }
        /// <summary>
        /// Bitwise Or Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator|(IntType Value, AltDec self)
        {
            return (AltDec)Value | self;
        }
        /// <summary>
        /// Bitwise And Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator&(IntType Value, AltDec self)
        {
            return (AltDec)Value & self;
        }
    #pragma endregion Integer-To-AltDec Operations
	
    #pragma region From Standard types to this type
        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(float Value)
        {
            bool IsNegative = Value < 0.0f;
            if (IsNegative) { Value *= -1.0f; }
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value >= 2147483648.0f)
            {
                IntValue = 2147483647;
                if (IsNegative)
                {
                    IntValue *= -1;
                }
                DecimalHalf = 999999999;
            }
            else
            {
                signed __int64 WholeValue = (signed __int64)std::floor(Value);
                Value -= (float)WholeValue;
                IntValue = IsNegative ? WholeValue * -1 : WholeValue;
                DecimalHalf = (signed int)Value * 10000000000;
            }
        }

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(double Value)
        {
            bool IsNegative = Value < 0.0;
            if (IsNegative) { Value *= -1.0; }
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value >= 2147483648.0)
            {
                IntValue = 2147483647;
                if (IsNegative)
                {
                    IntValue *= -1;
                }
                DecimalHalf = 999999999;
            }
            else
            {
                signed __int64 WholeValue = (signed __int64)std::floor(Value);
                Value -= (double)WholeValue;
                IntValue = IsNegative ? WholeValue * -1 : WholeValue;
                DecimalHalf = (signed int)Value * 10000000000;
            }
        }

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(ldouble Value)
        {
            bool IsNegative = Value < 0.0L;
            if (IsNegative) { Value *= -1.0L; }
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value >= 2147483648.0)
            {
                IntValue = 2147483647;
                if (IsNegative)
                {
                    IntValue *= -1;
                }
                DecimalHalf = 999999999;
            }
            else
            {
                signed __int64 WholeValue = (signed __int64)std::floor(Value);
                Value -= (ldouble)WholeValue;
                IntValue = IsNegative ? WholeValue * -1 : WholeValue;
                DecimalHalf = (signed int)Value * 10000000000;
            }
        }

        /// <summary>
        /// Sets the value(false equals zero; otherwise is true).
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(bool Value)
        {
            IntValue = Value==false ? 0 : 1;
            DecimalHalf = 0;
        }

        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(int Value)
        {
            IntValue = Value; DecimalHalf = 0;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        AltDec(float Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        AltDec(double Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        AltDec(ldouble Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        AltDec(bool Value)
        {
            this->SetVal(Value);
        }
    #pragma endregion From Standard types to this type

    #pragma region From this type to Standard types
        /// <summary>
        /// AltDec to float explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator float()
        {
            float Value;
            if (IntValue < 0)
            {
                Value = IntValue == NegativeZero ? 0.0f : (float)IntValue;
                if (DecimalHalf != 0) { Value -= ((float)DecimalHalf * 0.000000001f); }
            }
            else
            {
                Value = (float)IntValue;
                if (DecimalHalf != 0) { Value += ((float)DecimalHalf * 0.000000001f); }
            }
            return Value;
        }
        /// <summary>
        /// AltDec to double explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator double()
        {
            double Value;
            if (IntValue < 0)
            {
                Value = IntValue == NegativeZero ? 0.0 : (double)IntValue;
                if (DecimalHalf != 0) { Value -= ((double)DecimalHalf * 0.000000001); }
            }
            else
            {
                Value = (double)IntValue;
                if (DecimalHalf != 0) { Value += ((double)DecimalHalf * 0.000000001); }
            }
            return Value;
        }

        /// <summary>
        /// AltDec to long double explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator ldouble()
        {
            ldouble Value;
            if (IntValue < 0)
            {
                Value = IntValue == NegativeZero ? 0.0L : (ldouble)IntValue;
                if (DecimalHalf != 0) { Value -= ((ldouble)DecimalHalf * 0.000000001L); }
            }
            else
            {
                Value = (ldouble)IntValue;
                if (DecimalHalf != 0) { Value += ((ldouble)DecimalHalf * 0.000000001L); }
            }
            return Value;
        }

        /// <summary>
        /// AltDec to int explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator int() { return IntValue; }

        explicit operator bool() { return IntValue == 0 ? false : true; }

        /// <summary>
        /// AltDec to integer type explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        template<typename IntType>
        explicit operator IntType() { return IntValue; }
    #pragma endregion From this type to Standard types

    #pragma region String Commands
        /// <summary>
        /// Reads the string.
        /// </summary>
        /// <param name="Value">The value.</param>
        void ReadString(std::string Value);

        /// <summary>
        /// Gets the value from string.
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        AltDec GetValueFromString(std::string Value);

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class from string literal
        /// </summary>
        /// <param name="strVal">The value.</param>
        AltDec(const char* strVal)
        {
            std::string Value = strVal;
            if (Value == "PI")
            {
                this->SetPiVal(1);//this->SetVal(PI);
            }
            else if (Value == "E")
            {
                this->SetVal(E);
            }
            else
            {
                this->ReadString(Value);
            }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="AltDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        AltDec(std::string Value)
        {
            if (Value == "PI")
            {
				this->SetPiVal(1);//this->SetVal(PI);
            }
            else if (Value == "E")
            {
                this->SetVal(E);
            }
            else
            {
                this->ReadString(Value);
            }
        }
  //      /// <summary>
  //      /// Converts to string.
  //      /// </summary>
  //      /// <returns>std.string</returns>
  //      std::string ToString();

  //      /// <summary>
  //      /// Converts to string with digits filled in even when empty
  //      /// </summary>
  //      /// <returns>std.string</returns>
  //      std::string ToFullString();

  //      /// <summary>
  //      /// Implements the operator std::string operator.
  //      /// </summary>
  //      /// <returns>The result of the operator.</returns>
  //      explicit operator std::string() { return ToString(); }

        ///// <summary>
        ///// += AltDec operation added to std::string
        ///// </summary>
        ///// <param name="targetString">The target string(left side).</param>
        ///// <param name="Value">The right side value</param>
        ///// <returns>string</returns>
        //friend std::string operator+=(std::string targetString, AltDec self) { return targetString + self.ToString(); }
    #pragma endregion String Commands
    };
	
    #pragma region ValueDefine Source
    AltDec AltDec::PI = PIValue();
	AltDec AltDec::E = EValue();
	AltDec AltDec::PINum = PINumValue();
	AltDec AltDec::ENum = ENumValue();
}