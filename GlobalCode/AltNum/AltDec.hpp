// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
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

#include <string>
#include <cmath>
#include "..\OtherFunctions\VariableConversionFunctions.h"

#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include "MediumDec.hpp"
#include "AltNumModChecker.hpp"

/* Other MixedDec based Switches(that may or may not be implimented in AltDec)
AltDec_EnablePIRep = PI*(+- 2147483647.999999999) Representation enabled(Needed for some more accurate calculas operations when using radians instead of angle)(Not Fully Implimented)
AltDec_EnableNegativeZero = (Not Fully Implimented)
*/

//Preprocessor Switches
/*
AltDec_EnablePIPowers = (Not Fully Implimented)
AltDec_EnableMixedFractional = If DecimalHalf is negative and ExtraRep is Positive, then AltDec represents mixed fraction of -2147483648 to 2147483647 + (DecimalHalf*-1)/ExtraRep(Not Fully Implimented)
AltDec_EnableInfinityRep = Enable support of positive/negative infinity representations and approaching value representations(Not Fully Implimented)
AltDec_EnableNaN = Enable NaN based representations and operations(Not Fully Implimented)
AltDec_EnableComplexNum = Enable Representation of complex numbers with Imaginary number operations(Requires AltDec_EnableImaginaryNum, Not Implimented Yet)

Only one of below can be active at once:
AltDec_EnableENum = If DecimalHalf is positive and ExtraRep is -2147483647, then AltDec represents +- 2147483647.999999999 * e (Not Fully Implimented)
                    If DecimalHalf is positive and ExtraRep is negative number greator than -2147483647, then AltDec represents (+- 2147483647.999999999 * e)/(ExtraRep*-1)
AltDec_EnableImaginaryNum = If DecimalHalf is positive and ExtraRep is -2147483647, then AltDec represents +- 2147483647.999999999i(Not Fully Implimented)
                            If DecimalHalf is positive and ExtraRep is negative number greator than -2147483647, then AltDec represents (+- 2147483647.999999999i)/(ExtraRep*-1)
*/

//Only one of the 2 can be enabled at once(AltDec_EnableImaginaryNum given preference in case that both used)
#if defined(AltDec_EnableENum) && defined(AltDec_EnableImaginaryNum)
    #undef AltDec_EnableENum
#endif

namespace BlazesRusCode
{
    class AltDec;

/*---Accuracy Tests:

*/

    /// <summary>
    /// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
    /// Represents +- 2147483647.999999999 with 100% consistency of accuracy for most operations as long as don't get too small
    /// plus support for some fractal operations, and other representations like PI(and optionally things like e or imaginary numbers)
    /// (12 bytes worth of Variable Storage inside class for each instance)
    class DLL_API AltDec
    {
    private:
#if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
        //(If AltDec_EnableImaginaryNum is enabled, then represents Value*i )||(If AltDec_EnableENum is enabled, then represents Value*e) when ExtraRep==-2147483647
        static signed IERep = -2147483647;
#endif
#if defined(AltDec_EnableInfinityRep)
        //Is Infinity Representation when DecimalHalf==-2147483648 (IntValue==1 for positive infinity;IntValue==-1 for negative Infinity)
        static signed int InfinityRep = -2147483648;
        //Is Approaching IntValue when DecimalHalf==-2147483647
        static signed int ApproachingValRep = -2147483647;
#endif
        //Is PI*Value representation when ExtraRep==-2147483648
        static signed int const PIRep = -2147483648;
#if defined(AltDec_EnableInfinityRep)
        //Is NaN when DecimalHalf==2147483647
        static signed int NaNRep = 2147483647;
#endif
		enum class RepType: int
		{
			NormalType = 0,,
			NumByDiv,
			PIRep,
			PIPower,
			ENum,
			ENumByDiv,
			INum,
			INumByDiv,
			ComplexIRep,
			MixedFrac,
			MixedE,
			MixedI;
//#if defined(AltDec_EnableMixedFractional)
//#endif
//#if defined(AltDec_EnableInfinityRep)
			ApproachingVal,//Defaults to approaching from right exact in case of NegativeRep(NegativeRep = -0.000...1;Approaching Zero is equal to 0.000...1)
			ApproachingFromLeftVal,
			ApproachingPI,
			ApproachingE,
			ApproachingI,
			//InfinityRep
//#endif
			NaN,
			UnknownType
		};
		RepType GetRepType()
		{
			if(ExtraRep==0)
				return RepType::NormalType;
#ifdef AltDec_EnableInfinityRep
//            else if(DecimalHalf==InfinityRep)
//            {
//                if(IntValue==1)//If Positive Infinity, then convert number into MaximumValue instead
//                {
//                    UpdateTarget.IntValue = 2147483647; UpdateTarget.DecimalHalf = 999999999;
//                }
//                else//If Negative Infinity, then convert number into MinimumValue instead
//                {
//                    UpdateTarget.IntValue = -2147483647; UpdateTarget.DecimalHalf = 999999999;
//                }
//            }
            else if(DecimalHalf==ApproachingValRep)
				return RepType::ApproachingVal;//Approaching from left to Value
#endif
			else if(ExtraRep==PIRep)
				return RepType::PIRep;
			else if(ExtraRep>0)
				return RepType::NumByDiv;
#if defined(AltDec_EnableNaN)
			else if(DecimalHalf==NaNRep)
				return RepType::NaN;
#endif
			//(ExtraRep<0)
#if defined(AltDec_EnableImaginaryNum)
#if AltDec_EnableMixedFractional
			else if(DecimalHalf<0)
				return RepType::MixedI;
#endif
			else if(ExtraRep==IERep)
				return RepType::INum;
			else
				return RepType::INumByDiv;
#elif defined(AltDec_EnableENum)
#if AltDec_EnableMixedFractional
			else if(DecimalHalf<0)
				return RepType::MixedE;
#endif
			else if(ExtraRep==IERep)
				return RepType::ENum;
			else
				return RepType::ENumByDiv;
#endif
			throw "Unknown or non-enabled representation type detected from AltDec";
			return RepType::UnknownType;//Catch-All Value;
		}
    public:
        /// <summary>
        /// The decimal overflow
        /// </summary>
        static signed int const DecimalOverflow = 1000000000;

        /// <summary>
        /// The decimal overflow
        /// </summary>
        static signed _int64 const DecimalOverflowX = 1000000000;

        /// <summary>
        /// long double (Extended precision double)
        /// </summary>
        using ldouble = long double;
    public:
        /// <summary>
        /// Value when IntValue is at negative zero (when has decimal part)
        /// </summary>
        static signed int const NegativeRep = -2147483648;

        /// <summary>
        /// Stores whole half of number(Including positive/negative status)
        /// </summary>
        signed int IntValue;

        /// <summary>
        /// Stores decimal section info and possibly other special info
        /// </summary>
        signed int DecimalHalf;

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
        /// <param name="decVal">The decimal val01.</param>
        /// <param name="extraVal">ExtraRep.</param>
        AltDec(signed int intVal = 0, signed int decVal = 0, signed int extraVal = 0)
        {
            IntValue = intVal;
            DecimalHalf = decVal;
            ExtraRep = extraVal;
        }

        void SetAsZero()
        {
            IntValue = 0; DecimalHalf = 0;
            ExtraRep = 0;
        }
        
        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(AltDec Value)
        {
            IntValue = Value.IntValue;
            DecimalHalf = Value.DecimalHalf; ExtraRep = Value.ExtraRep;
        }
        
        void SetPiVal(MediumDec Value)
        {
            IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
            ExtraRep = PIRep;
        }
        
        void SetPiVal(int Value)
        {
            IntValue = Value; DecimalHalf = 0;
            ExtraRep = PIRep;
        }
        
        void SetFractionalVal(MediumDec Value, int Divisor)
        {
            IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
            ExtraRep = Divisor;
        }
        
        void SetFractionalVal(int Value, int Divisor)
        {
            IntValue = Value; DecimalHalf = 0;
            ExtraRep = Divisor;
        }
        
#if defined(AltDec_EnableMixedFractional)
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
#endif

//Infinity operations based on https://www.gnu.org/software/libc/manual/html_node/Infinity-and-NaN.html
// and https://tutorial.math.lamar.edu/classes/calcI/typesofinfinity.aspx
#if defined(AltDec_EnableInfinityRep)
        void SetAsInfinity()
        {
            IntValue = 1; DecimalHalf = InfinityRep;
            ExtraRep = 0;
        }

        void SetAsNegativeInfinity()
        {
            IntValue = -1; DecimalHalf = InfinityRep;
            ExtraRep = 0;
        }
  
		//Approaching Zero from Right
        void SetAsApproachingZero()
        {
            IntValue = 0; DecimalHalf = ApproachingValRep;
            ExtraRep = 0;
        }
		
        void SetAsApproachingZeroFromLeft()
        {
            IntValue = 0; DecimalHalf = ApproachingValRep;
            ExtraRep = NegativeRep;
        }
        
		void SetAsApproachingValueFromRight(int value)
		{
            IntValue = value; DecimalHalf = ApproachingValRep;
            ExtraRep = 0;
		}
		
		void SetAsApproachingValueFromLeft(int value)
		{
            IntValue = value; DecimalHalf = ApproachingValRep;
            ExtraRep = NegativeRep;
		}
private:
        static AltDec InfinityValue()
        {
            AltDec NewSelf = AltDec(1, InfinityRep);
            return NewSelf;
        }
        
        static AltDec NegativeInfinityValue()
        {
            AltDec NewSelf = AltDec(-1, InfinityRep);
            return NewSelf;
        }
        
        static AltDec ApproachingZeroValue()
        {
            AltDec NewSelf = AltDec(0, ApproachingValRep);
            return NewSelf;
        }
public:
#endif
#if defined(AltDec_EnableNaN)
        void SetAsNaN()
        {
            IntValue = 0; DecimalHalf = NaNRep;
            ExtraRep = 0;
        }

        static AltDec NaNValue()
        {
            AltDec NewSelf = AltDec(0, NaNRep);
            return NewSelf;
        }
#endif
//        void UpdateValue(MediumDec& UpdateTarget)
//        {
//            if(ExtraRep==0)
//            {
//                UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
//            }
//#ifdef AltDec_EnableInfinityRep
//            else if(DecimalHalf==InfinityRep)
//            {
//                if(IntValue==1)//If Positive Infinity, then convert number into MaximumValue instead
//                {
//                    UpdateTarget.IntValue = 2147483647; UpdateTarget.DecimalHalf = 999999999;
//                }
//                else//If Negative Infinity, then convert number into MinimumValue instead
//                {
//                    UpdateTarget.IntValue = -2147483647; UpdateTarget.DecimalHalf = 999999999;
//                }
//            }
//            else if(DecimalHalf==ApproachingValRep)
//            {
//                UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = 1;
//            }
//#endif
//            else if(ExtraRep==PIRep)
//            {
//                if (DecimalHalf == 0 && IntValue == 10)
//                {
//                    UpdateTarget.IntValue = 31; UpdateTarget.DecimalHalf = 415926536;
//                }
//                else
//                {
//                    UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
//                    UpdateTarget *= MediumDec::PI;
//                }
//            }
//#if defined(AltDec_EnableNaN)
//            else if(DecimalHalf==NaNRep)//If NaN, then convert number into Nil instead
//            {
//                UpdateTarget.IntValue = InfinityRep; UpdateTarget.DecimalHalf = InfinityRep;
//            }
//#endif
//#if AltDec_EnableMixedFractional
//#if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
//            else if(ExtraRep>0)
//#else
//            else
//#endif
//            {
//                if(DecimalHalf<0)//Mixed Fraction
//                {
//                    UpdateTarget.IntValue = DecimalHalf*-1; UpdateTarget.DecimalHalf = 0;
//                    UpdateTarget /= ExtraRep;
//                    UpdateTarget += IntValue;
//                }
//                else//Value Divided by ExtraRep
//                {
//                    UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
//                    UpdateTarget /= ExtraRep;
//                }
//            }
//#endif
//#if defined(AltDec_EnableImaginaryNum)
//#if AltDec_EnableMixedFractional
//            else//(ExtraRep<0)
//#else
//            else if(ExtraRep<0)
//#endif
//            {
//                UpdateTarget.SetVal(MediumDec::Nil);//Imaginary number representation doesn't exist for MediumDec
//            }
//#elif defined(AltDec_EnableENum)
//#if AltDec_EnableMixedFractional
//            else//(ExtraRep<0)
//#else
//            else if(ExtraRep<0)
//#endif
//            {
//                if(ExtraRep==-2147483647)
//                {
//                    UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
//                    UpdateTarget *= MediumDec::E;
//                }
//                else
//                {
//                    UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
//                    UpdateTarget *= MediumDec::E;
//                    UpdateTarget/= ExtraRep*-1;
//                }
//            }
//#endif
//        }

        void ConvertToNumRep()
        {
            if(ExtraRep==PIRep)
            {
                ExtraRep = 0;
                if (DecimalHalf == 0 && IntValue == 10)
                {
                    IntValue = 31; DecimalHalf = 415926536; 
                }
                else
                {
                    BasicMultOp(PINum);
                }
            }
#ifdef AltDec_EnableInfinityRep
            else if(DecimalHalf==InfinityRep)
            {
                ExtraRep = 0;
                if(IntValue==1)//If Positive Infinity, then convert number into MaximumValue instead
                {
                    IntValue = 2147483647; DecimalHalf = 999999999;
                }
                else//If Negative Infinity, then convert number into MinimumValue instead
                {
                    IntValue = -2147483647; DecimalHalf = 999999999;
                }
            }
            else if(DecimalHalf==ApproachingValRep)
            {
                ExtraRep = 0;
                DecimalHalf = 1;
            }
#endif
#ifdef AltDec_EnableNaN
            else if(DecimalHalf==NaNRep)//Set as Zero instead of NaN
            {
                IntValue = 0; DecimalHalf = 0;
            }
#endif
#if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
            else(ExtraRep>0)
#else
            else
#endif
            {
#if AltDec_EnableMixedFractional
                if(DecimalHalf<0)//Mixed Fraction
                {
                    int TempAdd = IntValue;
                    IntValue = DecimalHalf*-1; DecimalHalf = 0;
                    BasicIntDivOp(ExtraRep);
                    BasicAddOp(TempAdd);
                }
                else//Value Divided by ExtraRep
                {
#endif
                    BasicDivOp(ExtraRep);
#if AltDec_EnableMixedFractional
                }
#endif
            }
#if defined(AltDec_EnableImaginaryNum)
            else(ExtraRep<0)
            {
                IntValue = -2147483648;
            }
#elif defined(AltDec_EnableENum)
            else(ExtraRep<0)
            {
                BasicAddOp(ENum);
                if(ExtraRep!=-2147483647)
                {
                    int TempDiv = ExtraRep*-1;
                    BasicDivOp(TempDiv);
                }
            }
#endif
            ExtraRep = 0;
        }
		
    #pragma region ValueDefines
private:
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
        
        static AltDec ZeroValue()
        {
            return AltDec(0, 0, 0);
        }
        
        static AltDec EValue()
        {
#if defined(AltDec_EnableENum)
            return AltDec(1, 0, IERep);
#else
            return AltDec(2, 718281828, 0);
#endif
        }
        
        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec OneValue()
        {
            AltDec NewSelf = AltDec(1);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec TwoValue()
        {
            AltDec NewSelf = AltDec(2);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at negative one
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec NegativeOneValue()
        {
            AltDec NewSelf = AltDec(-1);
            return NewSelf;
        }

        /// <summary>
        /// Returns the value at 0.5
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec Point5Value()
        {
            AltDec NewSelf = AltDec(0, 500000000);
            return NewSelf;
        }

        static AltDec JustAboveZeroValue()
        {
            AltDec NewSelf = AltDec(0, 1);
            return NewSelf;
        }

        static AltDec OneMillionthValue()
        {
            AltDec NewSelf = AltDec(0, 1000);
            return NewSelf;
        }

        static AltDec FiveThousandthValue()
        {
            AltDec NewSelf = AltDec(0, 5000000);
            return NewSelf;
        }

        static AltDec FiveMillionthValue()
        {
            AltDec NewSelf = AltDec(0, 5000);
            return NewSelf;
        }

        static AltDec TenMillionthValue()
        {
            AltDec NewSelf = AltDec(0, 100);
            return NewSelf;
        }

        static AltDec OneHundredMillionthValue()
        {
            AltDec NewSelf = AltDec(0, 10);
            return NewSelf;
        }

        static AltDec FiveBillionthValue()
        {
            AltDec NewSelf = AltDec(0, 5);
            return NewSelf;
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
        
#if defined(AltDec_EnableInfinityRep)
        static AltDec Infinity;
        static AltDec NegativeInfinity;
        static AltDec ApproachingZero;
#endif
        
        static AltDec PI;
      
        static AltDec E;
        
        static AltDec Zero;
        
        /// <summary>
        /// Returns the value at one
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec One;

        /// <summary>
        /// Returns the value at two
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec Two;

        /// <summary>
        /// Returns the value at 0.5
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec PointFive;

        /// <summary>
        /// Returns the value at digit one more than zero (0.000000001)
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec JustAboveZero;

        /// <summary>
        /// Returns the value at .000000005
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec FiveBillionth;

        /// <summary>
        /// Returns the value at .000001000
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec OneMillionth;

        /// <summary>
        /// Returns the value at "0.005"
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec FiveThousandth;

        /// <summary>
        /// Returns the value at .000000010
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec OneGMillionth;

        //0e-7
        static AltDec TenMillionth;

        /// <summary>
        /// Returns the value at "0.000005"
        /// </summary>
        static AltDec FiveMillionth;

        /// <summary>
        /// Returns the value at negative one
        /// </summary>
        /// <returns>AltDec</returns>
        static AltDec NegativeOne;
        
        /// <summary>
        /// Returns value of lowest non-infinite/Special Decimal State Value that can store
        /// </summary>
        static AltDec Minimum;
        
        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        static AltDec Maximum;
        
        /// <summary>
        /// 2.3025850929940456840179914546844
        /// (Based on https://stackoverflow.com/questions/35968963/trying-to-calculate-logarithm-base-10-without-math-h-really-close-just-having)
        /// </summary>
        static AltDec LN10;

        /// <summary>
        /// (1 / Ln10) (Ln10 operation as division as recommended by https://helloacm.com/fast-integer-log10/ for speed optimization)
        /// </summary>
        static AltDec LN10Mult;

        /// <summary>
        /// (1 / Ln10)*2 (Ln10 operation as division as recommended by https://helloacm.com/fast-integer-log10/ for speed optimization)
        /// </summary>
        static AltDec HalfLN10Mult;

        /// <summary>
        /// Nil Value as proposed by https://docs.google.com/document/d/19n-E8Mu-0MWCcNt0pQnFi2Osq-qdMDW6aCBweMKiEb4/edit
        /// </summary>
        static AltDec Nil;
    #pragma endregion ValueDefines
        /// <summary>
        /// Swaps the negative status.
        /// </summary>
        void SwapNegativeStatus()
        {
            if (IntValue == NegativeRep)
            {
                IntValue = 0;
            }
            else if (IntValue == 0)
            {
                IntValue = NegativeRep;
            }
            else
            {
                IntValue *= -1;
            }
        }
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
                this->SetVal(PI);
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
                this->SetVal(PI);
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
        /// Converts to string.
        /// </summary>
        /// <returns>std.string</returns>
        std::string ToString();

        /// <summary>
        /// Converts to string with digits filled in even when empty
        /// </summary>
        /// <returns>std.string</returns>
        std::string ToFullString();

        /// <summary>
        /// Implements the operator std::string operator.
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator std::string() { return ToString(); }

        ///// <summary>
        ///// += AltDec operation added to std::string
        ///// </summary>
        ///// <param name="targetString">The target string(left side).</param>
        ///// <param name="Value">The right side value</param>
        ///// <returns>string</returns>
        //friend std::string operator+=(std::string targetString, AltDec self) { return targetString + self.ToString(); }
    #pragma endregion String Commands

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

        AltDec(MediumDec Value)
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
                Value = IntValue == NegativeRep ? 0.0f : (float)IntValue;
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
                Value = IntValue == NegativeRep ? 0.0 : (double)IntValue;
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
                Value = IntValue == NegativeRep ? 0.0L : (ldouble)IntValue;
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

    #pragma region Comparison Operators
        /// <summary>
        /// Equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator==(AltDec self, AltDec Value)
        {
#if defined(AltDec_EnableInfinityRep)
	#if defined(AltDec_EnableImaginaryNum)
				if(self.DecimalHalf!=InfinityRep&&(self.ExtraRep>=0||self.ExtraRep==PIRep))
	#else
				if(self.DecimalHalf!=InfinityRep)
	#endif
				{
					self.ConvertToNumRep();
				}

	#if defined(AltDec_EnableImaginaryNum)
				if(Value.DecimalHalf!=InfinityRep&&(Value.ExtraRep>=0||Value.ExtraRep==PIRep))
	#else
				if(Value.DecimalHalf!=InfinityRep)
	#endif
				{
					Value.ConvertToNumRep();
				}
#else
	#if defined(AltDec_EnableImaginaryNum)
				if(self.ExtraRep>=0||self.ExtraRep==PIRep)
				{
					self.ConvertToNumRep();
				}
	#else
				self.ConvertToNumRep();
	#endif

	#if defined(AltDec_EnableImaginaryNum)
				if(Value.ExtraRep>=0||Value.ExtraRep==PIRep)
				{
					Value.ConvertToNumRep();
				}
	#else
				Value.ConvertToNumRep();
	#endif
#endif
#if defined(AltDec_EnableImaginaryNum)
			return (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf && self.ExtraRep == Value.ExtraRep);
#else
			return (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf);
#endif
        }

        /// <summary>
        /// Not equal to Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator!=(AltDec self, AltDec Value)
        {
#if defined(AltDec_EnableInfinityRep)
	#if defined(AltDec_EnableImaginaryNum)
				if(self.DecimalHalf!=InfinityRep&&(self.ExtraRep>=0||self.ExtraRep==PIRep))
	#else
				if(self.DecimalHalf!=InfinityRep)
	#endif
				{
					self.ConvertToNumRep();
				}

	#if defined(AltDec_EnableImaginaryNum)
				if(Value.DecimalHalf!=InfinityRep&&(Value.ExtraRep>=0||Value.ExtraRep==PIRep))
	#else
				if(Value.DecimalHalf!=InfinityRep)
	#endif
				{
					Value.ConvertToNumRep();
				}
#else
	#if defined(AltDec_EnableImaginaryNum)
				if(self.ExtraRep>=0||self.ExtraRep==PIRep)
				{
					self.ConvertToNumRep();
				}
	#else
				self.ConvertToNumRep();
	#endif

	#if defined(AltDec_EnableImaginaryNum)
				if(Value.ExtraRep>=0||Value.ExtraRep==PIRep)
				{
					Value.ConvertToNumRep();
				}
	#else
				Value.ConvertToNumRep();
	#endif
#endif
#if defined(AltDec_EnableImaginaryNum)
            return (self.IntValue != Value.IntValue || self.DecimalHalf != Value.DecimalHalf || self.ExtraRep != Value.ExtraRep);
#else
            return (self.IntValue != Value.IntValue || self.DecimalHalf != Value.DecimalHalf);
#endif
        }

        /// <summary>
        /// Lesser than Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<(AltDec self, AltDec Value)
        {
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(Value.ExtraRep==InfinityRep)
				{
					return self.IntValue<Value.IntValue;
				}
			}
			else if(Value.ExtraRep==InfinityRep)
			{
			
			}
#endif
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
                            if (self.IntValue == NegativeRep)
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
                        if (Value.IntValue == NegativeRep)
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
                    if (self.IntValue == NegativeRep)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(Value.ExtraRep==InfinityRep)
				{
					return self.IntValue<=Value.IntValue;
				}
			}
			else if(Value.ExtraRep==InfinityRep)
			{
			
			}
#endif
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
                            if (self.IntValue == NegativeRep)
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
                        if (Value.IntValue == NegativeRep && self.IntValue <= 1)
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
                    if (self.IntValue == NegativeRep)
                        self.IntValue = 0;
                    if (Value.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(Value.ExtraRep==InfinityRep)
				{
					return self.IntValue>Value.IntValue;
				}
			}
			else if(Value.ExtraRep==InfinityRep)
			{
			
			}
#endif
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
                        if (self.IntValue == NegativeRep)
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
                    if (Value.IntValue == NegativeRep)
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
                if (self.IntValue == NegativeRep)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(Value.ExtraRep==InfinityRep)
				{
					return self.IntValue>=Value.IntValue;
				}
				else
				{
				
				}
			}
			else if(Value.ExtraRep==InfinityRep)
			{
			
			}
#endif
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
                        if (self.IntValue == NegativeRep)
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
                    if (Value.IntValue == NegativeRep)
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
                if (self.IntValue == NegativeRep)
                    self.IntValue = 0;
                if (Value.IntValue == NegativeRep)
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

#pragma region Addition/Subtraction Operations
        /// <summary>
        /// Basic Addition Operation Between AltDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        void BasicAddOp(AltDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return;
                if (DecimalHalf == 0)
                {
                    IntValue += Value.IntValue;
                }
                else
                {
                    bool WasNegative = IntValue < 0;
                    if (WasNegative)
                        IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
                    IntValue += Value.IntValue;
                    if (IntValue == -1)
                        IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
                    else if (IntValue < 0)
                        ++IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                        DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
                if (Value.IntValue != 0 && Value.IntValue != AltDec::NegativeRep)
                    IntValue += Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; --IntValue; }
                    }
                    else
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; ++IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; --IntValue; }
                    }
                    else
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; ++IntValue; }
                    }
                }
                if (IntValue == -1)
                    IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
                else if (IntValue < 0)
                    ++IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                    DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
            }
        }
    
        /// <summary>
        /// Addition Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec& AddOp(AltDec& self, AltDec& Value)
        {
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf==InfinityRep)
                return self;
            if (Value.DecimalHalf == InfinityRep)
                return Value.IntValue == 1 ? self.SetAsInfinity() : self.SetAsNegativeInfinity();
#endif
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0||ExtraRep==NegativeRep)
                {
#if AltDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.BasicAddOp(Value);
#if AltDec_EnableMixedFractional
                    }
#endif
                }
    #if defined(AltDec_EnableImaginaryNum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #elif defined(AltDec_EnableENum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            else
            {
                if(self.ExtraRep==0)
                {
                
                }
                else//Catch-all for other representation combinations
                {
                    AltDec ValueCopy = Value;
                    Value.ConvertToNumRep();
                    self.BasicAddOp(ValueCopy);
                }
            }
            return self;
        }

        /// <summary>
        /// Basic Subtraction Operation Between AltDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        void BasicSubOp(AltDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return;
                if (DecimalHalf == 0)
                {
                    IntValue -= Value.IntValue;
                }
                else
                {
                    bool WasNegative = IntValue < 0;
                    if (WasNegative)
                        IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
                    if (Value.IntValue != 0)
                        IntValue -= Value.IntValue;
                    if(IntValue==-1)
                        IntValue = DecimalHalf == 0?0:AltDec::NegativeRep;
                    else if(IntValue<0)
                        ++IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && IntValue >= 0)||(WasNegative == 0 && IntValue < 0))
                        DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
                if(Value.IntValue!=0&&Value.IntValue!=AltDec::NegativeRep)
                    IntValue -= Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)//-4.0 - -0.5 = -3.5
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; --IntValue; }
                    }
                    else//4.3 -  - 1.8
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; ++IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)//-4.5 - 5.6
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; --IntValue; }
                    }
                    else//0.995 - 1 = 
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += AltDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= AltDec::DecimalOverflow) { DecimalHalf -= AltDec::DecimalOverflow; ++IntValue; }
                    }
                }
                if (IntValue == -1)
                    IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
                else if (IntValue < 0)
                    ++IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                    DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
            }
        }

        /// <summary>
        /// Subtraction Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& SubOp(AltDec& self, AltDec& Value)
        {
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
                return self;
            if (Value.DecimalHalf == InfinityRep)
                return Value.IntValue == 1 ? self.SetAsInfinity() : self.SetAsNegativeInfinity();
#endif
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0||self.ExtraRep==NegativeRep)
                {
#if AltDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.BasicSubOp(Value);
#if AltDec_EnableMixedFractional
                    }
#endif
                }
    #if defined(AltDec_EnableImaginaryNum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #elif defined(AltDec_EnableENum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
                else
                {
                
                }
    #endif
                if(self.ExtraRep!=0&&self.IntValue==0&&self.DecimalHalf==0)
                    self.ExtraRep = 0;
            }
            else
            {
                if(self.ExtraRep==0)
                {
                
                }
                else//Catch-all for other representation combinations
                {
                    AltDec ValueCopy = Value;
                    Value.ConvertToNumRep();
                    self.BasicAddOp(ValueCopy);
                }
            }
            return self;
        }

        /// <summary>
        /// Partial Addition Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="value">The value.</param>
		template<typename IntType>
        void PartialIntAddition(IntType& value)
        {
            if (DecimalHalf == 0)
                IntValue += value;
            else
            {
				bool WasNegative = IntValue < 0;
				if (WasNegative)
					IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
				IntValue += value;
				if (IntValue == -1)
					IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
				else if (IntValue < 0)
					++IntValue;
				//If flips to other side of negative, invert the decimals
				if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
					DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
			}
		}

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
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
                return self;
#endif
            if(self.ExtraRep==PIRep)//Value*Pi Representation
			{
                self.ConvertToNumRep();
				self.PartialIntAddition(value);
			}
#if defined(AltDec_EnableImaginaryNum)
            else if(self.ExtraRep==IERep)
            {
				throw "Can't convert AltDec into complex number at moment";
            }
            else if(self.ExtraRep>0)
#elif defined(AltDec_EnableENum)
            else if(self.ExtraRep==IERep)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation and Normal Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
				self.PartialIntAddition(value);
            }
            return self;
        }

        /// <summary>
        /// Partial Subtraction Operation Between AltDec and Integer value
        /// </summary>
        /// <param name="value">The value.</param>
		template<typename IntType>
        void PartialIntSubtraction(IntType& value)
        {
            if (DecimalHalf == 0)
                IntValue -= value;
            else
            {
                bool WasNegative = self.IntValue < 0;
                if (WasNegative)
                    self.IntValue = self.IntValue == AltDec::NegativeRep ? -1 : --self.IntValue;
                self.IntValue -= value;
                if (self.IntValue == -1)
                    self.IntValue = self.DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
                else if (self.IntValue < 0)
                    ++self.IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                    self.DecimalHalf = AltDec::DecimalOverflow - self.DecimalHalf;
			}
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
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
                return self;
#endif
            if(self.ExtraRep==PIRep)//Value*Pi Representation
			{
                self.ConvertToNumRep();
				self.PartialIntSubtraction(value);
			}
#if defined(AltDec_EnableImaginaryNum)
            else if(self.ExtraRep==IERep)
            {
				throw "Can't convert AltDec into complex number at moment";
            }
            else if(self.ExtraRep>0)
#elif defined(AltDec_EnableENum)
            else if(self.ExtraRep==IERep)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation and Normal Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
				self.PartialIntSubtraction(value);
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
        void PartialUnsignedAddition(IntType& value)
		{
            if (DecimalHalf == 0 || IntValue > 0)
                IntValue += value;
            else
            {
                bool WasNegative = IntValue < 0;
                if (WasNegative)
				{
                    IntValue = IntValue == AltDec::NegativeRep ? -1 : --IntValue;
					IntValue += value;
					if (IntValue == -1)
						IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
					else if (IntValue < 0)
						++IntValue;
					//If flips to other side of negative, invert the decimals
					if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
						DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
				}
				else//Don't need to check if flipping to other sign if adding positive to positive
				{
					IntValue += value;
				}
            }
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
            if (value == 0)
                return self;
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
                return self;
#endif
            if(self.ExtraRep==PIRep)//Value*Pi Representation
			{
                self.ConvertToNumRep();
				self.PartialUnsignedAddition(value);
			}
#if defined(AltDec_EnableImaginaryNum)
            else if(self.ExtraRep==IERep)
            {
				throw "Can't convert AltDec into complex number at moment";
            }
            else if(self.ExtraRep>0)
#elif defined(AltDec_EnableENum)
            else if(self.ExtraRep==IERep)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation and Normal Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
				self.PartialUnsignedAddition(value);
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
        void PartialUnsignedSubtraction(IntType& value)
		{
            if (DecimalHalf == 0)
                IntValue -= value;
            else if (IntValue == NegativeRep)
                IntValue = (signed int)value * -1;
            else if (IntValue < 0)
                IntValue -= value;
            else
            {
                bool WasNegative = IntValue < 0;
                if (WasNegative)//Don't need to check if negative value if going farther negative
				{
					if(IntValue == AltDec::NegativeRep)
					{
						if(value==1)
							IntValue = 0;
						else
							IntValue = ((signed int) value)*-1;
					}
					else
					{
						IntValue -= value;
					}
				}
				else
				{
					IntValue -= value;
					if (IntValue == -1)
						IntValue = DecimalHalf == 0 ? 0 : AltDec::NegativeRep;
					else if (IntValue < 0)
						++IntValue;
					//If flips to other side of negative, invert the decimals
					if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
						DecimalHalf = AltDec::DecimalOverflow - DecimalHalf;
				}
            }
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
            if (value == 0)
                return self;
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
                return self;
#endif
            if(self.ExtraRep==PIRep)//Value*Pi Representation
			{
                self.ConvertToNumRep();
				self.PartialUnsignedSubtraction(value);
			}
#if defined(AltDec_EnableImaginaryNum)
            else if(self.ExtraRep==IERep)
            {
				throw "Can't convert AltDec into complex number at moment";
            }
            else if(self.ExtraRep>0)
#elif defined(AltDec_EnableENum)
            else if(self.ExtraRep==IERep)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation and Normal Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
				self.PartialUnsignedSubtraction(value);
            }
            return self;
        }
#pragma endregion Addition/Subtraction Operations

#pragma region Multiplication/Division Operations
        void PartialMultOp(AltDec& Value)
        {
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == AltDec::NegativeRep) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                SwapNegativeStatus();
            }
            if (DecimalHalf == 0)
            {
                if (IntValue == 1)
                {
                    IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
                    ExtraRep = Value.ExtraRep; return;
                }
                else if (Value.DecimalHalf == 0)
                {
                    IntValue *= Value.IntValue; return;
                }
                else
                {
                    Value *= IntValue;
                    IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
                    ExtraRep = Value.ExtraRep;
                }
            }
            else if (IntValue == 0)
            {
                __int64 SRep = (__int64)DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= AltDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)DecimalHalf * Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = OverflowVal;
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        DecimalHalf = (signed int)SRep;
                    }
                }
            }
            else if (IntValue == AltDec::NegativeRep)
            {
                __int64 SRep = (__int64)DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= AltDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)DecimalHalf * Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = -OverflowVal;
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        DecimalHalf = (signed int)SRep;
                    }
                }
            }
            else
            {
                bool SelfIsNegative = IntValue < 0;
                if (SelfIsNegative)
                {
                    IntValue *= -1;
                }
                if (Value.IntValue == 0)
                {
                    __int64 SRep = AltDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.DecimalHalf;
                    SRep /= AltDec::DecimalOverflowX;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = (signed int)(SelfIsNegative ? -OverflowVal : OverflowVal);
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        IntValue = SelfIsNegative ? AltDec::NegativeRep : 0;
                        DecimalHalf = (signed int)SRep;
                    }
                }
                else if (Value.DecimalHalf == 0)//Y is integer
                {
                    __int64 SRep = AltDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = (signed int)OverflowVal;
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        IntValue = 0;
                        DecimalHalf = (signed int)SRep;
                    }
                }
                else
                {
                    //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                    __int64 SRep = IntValue == 0 ? DecimalHalf : AltDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.IntValue;//SRep holds __int64 version of X.Y * Z
                    //X.Y *.V
                    __int64 Temp03 = (__int64)IntValue * Value.DecimalHalf;//Temp03 holds __int64 version of X *.V
                    __int64 Temp04 = (__int64)DecimalHalf * (__int64)Value.DecimalHalf;
                    Temp04 /= AltDec::DecimalOverflow;
                    //Temp04 holds __int64 version of .Y * .V
                    __int64 IntegerRep = SRep + Temp03 + Temp04;
                    __int64 IntHalf = IntegerRep / AltDec::DecimalOverflow;
                    IntegerRep -= IntHalf * (__int64)AltDec::DecimalOverflow;
                    if (IntHalf == 0) { IntValue = (signed int)SelfIsNegative ? AltDec::NegativeRep : 0; }
                    else { IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    DecimalHalf = (signed int)IntegerRep;
                }
            }
        }

        /// <summary>
        /// Basic Multiplication Operation Between AltDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        void BasicMultOp(AltDec& Value)
        {
            if (Value == AltDec::Zero) { SetAsZero(); return; }
            if ((IntValue==0&&DecimalHalf==0) || Value == AltDec::One)
                return;
            PartialMultOp(Value);
            if (IntValue==0&&DecimalHalf==0) { DecimalHalf = 1; }//Prevent Dividing into nothing
        }

        /// <summary>
        /// Multiplication Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& MultOp(AltDec& self, AltDec& Value)
        {
#if defined(AltDec_EnableInfinityRep)
            if (self.DecimalHalf == InfinityRep)
            {
                if (Value.DecimalHalf == InfinityRep && self.IntValue == Value.IntValue && self.IntValue == -1)
                    self.IntValue = 1;
                return self;
            }
            else if (Value.DecimalHalf == InfinityRep)
                return self;
#endif
            if (Value == AltDec::Zero) { self.SetAsZero(); return self; }
            if (self == AltDec::Zero || Value == AltDec::One)
                return self;
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0)
                {
#if AltDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.PartialMultOp(Value);
#if AltDec_EnableMixedFractional
                    }
#endif
                }
                else if(self.ExtraRep==NegativeRep)//Value*Pi Representation
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #if defined(AltDec_EnableENum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            if(self.ExtraRep!=0&&self.IntValue==0&&self.DecimalHalf==0)
                self.ExtraRep = 0;
            if (self == AltDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }


        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        static AltDec& MultIntOp(AltDec& self, IntType& Value)
        {
            if (Value < 0)
            {
                if (Value == NegativeRep) { Value = 0; }
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
                    if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
                    self.IntValue = SelfIsNegative ? NegativeRep : 0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            return self;
        }

        void PartialDivOp(AltDec& Value)
        {
            if (DecimalHalf == 0)
            {
                bool SelfIsNegative = IntValue < 0;
                if (SelfIsNegative)
                {
                    IntValue *= -1;
                }
                if (Value.DecimalHalf == 0)//Both are integers
                {
                    if (IntValue < 0) { IntValue *= -1; }
                    __int64 SRep = IntValue * AltDec::DecimalOverflowX;
                    __int64 YRep = Value.IntValue;
                    SRep /= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    }
                    else
                    {
                        IntValue = SelfIsNegative ? AltDec::NegativeRep : 0;
                    }
                    DecimalHalf = (signed int)SRep;
                }
                else//Only self is integer while Value has both sides
                {
                    boost::multiprecision::uint128_t SRep02 = AltDec::DecimalOverflowX * AltDec::DecimalOverflowX;
                    SRep02 *= IntValue;
                    __int64 VRep = AltDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        IntValue = 0;
                    }
                    DecimalHalf = (signed int)SRep;
                }
            }
            else if (IntValue == 0)
            {
                __int64 SRep = (__int64)DecimalHalf * AltDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / AltDec::DecimalOverflowX;
                SRep -= IntHalf * AltDec::DecimalOverflowX;
                IntValue = IntHalf;
                DecimalHalf = (signed int)SRep;
            }
            else if (IntValue == AltDec::NegativeRep)
            {
                __int64 SRep = (__int64)DecimalHalf * AltDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / AltDec::DecimalOverflowX;
                SRep -= IntHalf * AltDec::DecimalOverflowX;
                IntValue = IntHalf == 0 ? AltDec::NegativeRep : -IntHalf;
                DecimalHalf = (signed int)SRep;
            }
            else
            {
                bool SelfIsNegative = IntValue < 0;
                if (SelfIsNegative)
                {
                    IntValue *= -1;
                }
                if (Value.DecimalHalf == 0)//Y is integer but self is not
                {
                    __int64 SRep = AltDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep /= Value.IntValue;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntValue = (signed int)SelfIsNegative ? -OverflowVal : OverflowVal;
                    }
                    else
                    {
                        IntValue = 0;
                    }
                    DecimalHalf = (signed int)SRep;
                }
                else
                {//Splitting Integer Half and Decimal Half Division
                    __int64 SRep_DecHalf = (__int64)DecimalHalf * AltDec::DecimalOverflowX;
                    SRep_DecHalf /= Value.IntValue == 0 ? Value.DecimalHalf : AltDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                    int IntHalf = SRep_DecHalf / AltDec::DecimalOverflowX;
                    SRep_DecHalf -= IntHalf * AltDec::DecimalOverflowX;

                    boost::multiprecision::uint128_t SRep02 = AltDec::DecimalOverflowX * AltDec::DecimalOverflowX;
                    //std::cout << "Multi-precision as String:" << SRep02 << std::endl;
                    SRep02 *= IntValue;
                    __int64 VRep = AltDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02 + SRep_DecHalf;
                    if (SRep >= AltDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / AltDec::DecimalOverflowX;
                        SRep -= OverflowVal * AltDec::DecimalOverflowX;
                        IntHalf += OverflowVal;
                    }
                    if (IntHalf == 0) { IntValue = (signed int)SelfIsNegative ? AltDec::NegativeRep : 0; }
                    else { IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    DecimalHalf = (signed int)SRep;
                }
            }
        }

        void BasicDivOp(AltDec& Value)
        {
            if (Value == AltDec::Zero)
                throw "Target value can not be divided by zero";
            if (IntValue==0&&DecimalHalf==0)
                return;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == AltDec::NegativeRep) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                SwapNegativeStatus();
            }
            PartialDivOp(Value);
            if (IntValue==0&&DecimalHalf==0) { DecimalHalf = 1; }//Prevent Dividing into nothing
        }

        /// <summary>
        /// Division Operation Between AltDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        static AltDec& DivOp(AltDec& self, AltDec& Value)
        {
#if defined(AltDec_EnableInfinityRep)
            if (value.DecimalHalf == InfinityRep)
                return self.SetAsZero();
            if (Value == AltDec::Zero)
                return self.IntValue<0?self.SetAsNegativeInfinity:self.SetAsInfinity();
#else
            if (Value == AltDec::Zero)
                throw "Target value can not be divided by zero";
#endif
            if (self == AltDec::Zero)
                return self;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == AltDec::NegativeRep) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0)
                {
#if AltDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.PartialDivOp(Value);
#if AltDec_EnableMixedFractional
                    }
#endif
                }
                else if(self.ExtraRep==NegativeRep)//Value*Pi Representation
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #elif defined(AltDec_EnableENum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            if (self == AltDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec&</returns>
        template<typename IntType>
        static AltDec& DivIntOp(AltDec& self, IntType& Value)
        {
			if (Value == 0)
#if defined(AltDec_EnableInfinityRep)
                return self.IntValue<0?self.SetAsNegativeInfinity:self.SetAsInfinity();
#else
                throw "Target value can not be divided by zero";
#endif
            else if (self == Zero) { return self; }
            if (Value < 0)
            {
                if (Value == NegativeRep) { Value = 0; }
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
                    self.IntValue = SelfIsNegative ? NegativeRep : 0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
                    if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
                    self.IntValue = SelfIsNegative ? NegativeRep : 0;
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
                    self.IntValue = SelfIsNegative ? NegativeRep : 0;
                    self.DecimalHalf = (signed int)SRep;
                }
            }
            else
            {
                bool SelfIsNegative = self.IntValue < 0;
                if (SelfIsNegative)
                {
                    if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
#pragma endregion Multiplication/Division Operations

#pragma region Remainder Operations
        /// <summary>
        /// Remainder Operation Between AltDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>AltDec&</returns>
        static AltDec& RemOp(AltDec& self, AltDec& Value)
        {
            bool SelfIsWholeN = self.DecimalHalf == 0;
            bool ValueIsWholeN = Value.DecimalHalf == 0;
            if (Value.IntValue == 0 && ValueIsWholeN) { self.SetAsZero(); return self; }//Return zero instead of N/A
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0)
                {
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
                            if (Value.IntValue == NegativeRep) { Value.IntValue = 0; }
                        }
                        bool SelfIsNegative = self.IntValue < 0;
                        if (SelfIsNegative)
                        {
                            if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
                        if (IntResult == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeRep : 0; }
                        else { self.IntValue = (signed int)SelfIsNegative ? IntResult * -1 : IntResult; }
                        self.DecimalHalf = (signed int)SRep;
                    }
                }
                else if(self.ExtraRep==NegativeRep)//Value*Pi Representation
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #elif defined(AltDec_EnableENum)
                else if(self.ExtraRep==IERep)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(AltDec_EnableImaginaryNum) || defined(AltDec_EnableENum)
                else
                {
                
                }
    #endif
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
        static AltDec& RemOp(AltDec& self, IntType& Value)
        {
            if (Value == 0 || self == AltDec::Zero) { self.SetAsZero(); return self; }
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
                    if (self.IntValue == NegativeRep) { self.IntValue = 0; }
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
                if (IntHalf == 0) { self.IntValue = SelfIsNegative ? (signed int)NegativeRep : 0; }
                else { self.IntValue = (signed int)(SelfIsNegative ? IntHalf * -1 : IntHalf); }
                self.DecimalHalf = (signed int)SRep;
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
            if (self == AltDec::Zero) { return self; }
            if (Value == 0) { self.IntValue = 0; self.DecimalHalf = 0; return self; }
            if (self.DecimalHalf == 0)
            {
                self.IntValue %= Value; return self;
            }
            else//leftValue is non-whole number
            {
                __int64 SRep;
                if (self.IntValue == NegativeRep) { SRep = (__int64)self.DecimalHalf * -1; }
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
                if (IntHalf == 0) { self.IntValue = (signed int)SelfIsNegative ? NegativeRep : 0; }
                else { self.IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                self.DecimalHalf = (signed int)SRep;
            }
            return self;
        }
#pragma endregion Remainder Operations

#pragma region AltDec-To-AltDec Operators
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
                {
                    self.IntValue = (0 ^ Value.IntValue) * -1;
                    self.DecimalHalf ^= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeRep)
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
                {
                    self.IntValue = (0 | Value.IntValue) * -1;
                    self.DecimalHalf |= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeRep)
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
                {
                    self.IntValue = (0 & Value.IntValue) * -1;
                    self.DecimalHalf &= Value.DecimalHalf;
                }
                else
                {
                    if (ValIsNegative && Value.IntValue == NegativeRep)
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
            if (IntValue == NegativeRep) { IntValue = 0; }
            else if (DecimalHalf == 0) { ++IntValue; }
            else if (IntValue == -1) { IntValue = NegativeRep; }
            else { ++IntValue; }
            return *this;
        }

        /// <summary>
        /// ++AltDec Operator
        /// </summary>
        /// <returns>AltDec &</returns>
        AltDec& operator --()
        {
            if (IntValue == NegativeRep) { IntValue = -1; }
            else if (DecimalHalf == 0) { --IntValue; }
            else if (IntValue == 0) { IntValue = NegativeRep; }
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
            return (self.IntValue == Value && self.DecimalHalf == 0 && self.ExtraRep==0);
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
            if (self.DecimalHalf!=0||self.ExtraRep!=0)
				return true;
            else if (self.IntValue == Value)
				return false;
            else
				return true;
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==-1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return self.IntValue < Value;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==-1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return self.IntValue <= Value;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return self.IntValue > Value;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return self.IntValue >= Value;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
            return (self.IntValue == Value && self.DecimalHalf == 0 && self.ExtraRep==0);
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
            if (self.DecimalHalf!=0||self.ExtraRep!=0)
				return true;
            else if (self.IntValue == Value)
				return false;
            else
				return true;
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return Value < self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return true;
				else
					return false;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return Value <= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeRep && Value <= 1)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return false;
				else
					return true;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return Value > self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
#if defined(AltDec_EnableInfinityRep)
			if(self.ExtraRep==InfinityRep)
			{
				if(self.IntValue==1)
					return false;
				else
					return true;
			}
#endif
#if defined(AltDec_EnableImaginaryNum)
			if(self.ExtraRep>=0||self.ExtraRep==PIRep)
			{
				self.ConvertToNumRep();
			}
			else
				throw "Can't compare real values against imaginary.";
#else
			self.ConvertToNumRep();
#endif
            if (self.DecimalHalf == 0)
            {
                return Value >= self.IntValue;
            }
            else
            {
                if (self.IntValue == NegativeRep)
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
        
        //friend AltDec operator+=(AltDec* self, unsigned int Value) { return UnsignedAddOp(**self, Value); }
        //friend AltDec operator-=(AltDec* self, unsigned int Value) { return UnsignedSubOp(**self, Value); }
        //friend AltDec operator*=(AltDec* self, unsigned int Value) { return UnsignedMultOp(**self, Value); }
        //friend AltDec operator/=(AltDec* self, unsigned int Value) { return UnsignedDivOp(**self, Value); }
        //friend AltDec operator%=(AltDec* self, unsigned int Value) { return UnsignedRemOp(**self, Value); }

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

     //   friend AltDec operator+=(AltDec* self, unsigned __int64 Value){ return UnsignedAddOp(**self, Value); }
        //friend AltDec operator-=(AltDec* self, unsigned __int64 Value){ return UnsignedSubOp(**self, Value); }
     //   friend AltDec operator*=(AltDec* self, unsigned __int64 Value){ return UnsignedMultOp(**self, Value); }
        //friend AltDec operator/=(AltDec* self, unsigned __int64 Value){ return UnsignedDivOp(**self, Value); }
     //   friend AltDec operator%=(AltDec* self, unsigned __int64 Value){ return UnsignedRemOp(**self, Value); }

        /// <summary>
        /// Addition Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator+(AltDec self, IntType Value)
        {
            return AddIntOp(self, Value);
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
            return AddIntOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator+=(AltDec* self, IntType Value){ return AddIntOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator-(AltDec self, IntType Value)
        {
            return SubIntOp(self, Value);
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
            return SubIntOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator-=(AltDec* self, IntType Value){ return SubIntOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*(AltDec self, IntType Value)
        {
            return MultIntOp(self, Value);
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
            return MultIntOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between AltDec and Integer Value (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator*=(AltDec* self, IntType Value){ return MultIntOp(**self, Value); }

        /// <summary>
        /// Division Operation Between AltDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename IntType>
        friend AltDec operator/(AltDec self, IntType Value)
        {
            return DivIntOp(self, Value);
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
            return DivIntOp(self, Value);
        }

        template<typename IntType>
        friend AltDec operator/=(AltDec* self, IntType Value){ return DivIntOp(**self, Value); }
        
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
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
                if (SelfIsNegative && self.IntValue == NegativeRep)
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
            return AddIntOp(self, Value);
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
            return MultIntOp(self, Value);
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
    #pragma region Math/Trigonomic Etc Functions
        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <returns>AltDec&</returns>
        AltDec& Floor()
        {
            if (DecimalHalf == 0)
            {
                return *this;
            }
            DecimalHalf = 0;
            if (IntValue == NegativeRep) { IntValue = -1; }
            else
            {
                --IntValue;
            }
            return *this;
        }

        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>AltDec&</returns>
        static AltDec Floor(AltDec Value)
        {
            return Value.Floor();
        }
        
        /// <summary>
        /// Returns floored value with all fractional digits after specified precision cut off.
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <param name="precision">The precision.</param>
        static AltDec Floor(AltDec Value, int precision)
        {
            switch (precision)
            {
            case 9: break;
            case 8: Value.DecimalHalf /= 10; Value.DecimalHalf *= 10; break;
            case 7: Value.DecimalHalf /= 100; Value.DecimalHalf *= 100; break;
            case 6: Value.DecimalHalf /= 1000; Value.DecimalHalf *= 1000; break;
            case 5: Value.DecimalHalf /= 10000; Value.DecimalHalf *= 10000; break;
            case 4: Value.DecimalHalf /= 100000; Value.DecimalHalf *= 100000; break;
            case 3: Value.DecimalHalf /= 1000000; Value.DecimalHalf *= 1000000; break;
            case 2: Value.DecimalHalf /= 10000000; Value.DecimalHalf *= 10000000; break;
            case 1: Value.DecimalHalf /= 100000000; Value.DecimalHalf *= 100000000; break;
            default: Value.DecimalHalf = 0; break;
            }
            if (Value.IntValue == NegativeRep && Value.DecimalHalf == 0) { Value.DecimalHalf = 0; }
            return Value;
        }
        
        /// <summary>
        /// Returns the smallest integer that is greater than or equal to Value (Rounds up to integer value).
        /// </summary>
        /// <returns>AltDec&</returns>
        AltDec& Ceil()
        {
            if (DecimalHalf == 0)
            {
                return *this;
            }
            DecimalHalf = 0;
            if (IntValue == NegativeRep) { IntValue = 0; }
            else
            {
                ++IntValue;
            }
            return *this;
        }

        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs to integer value).
        /// </summary>
        /// <returns>AltDec&</returns>
        static int FloorInt(AltDec Value)
        {
            if (Value.DecimalHalf == 0)
            {
                return Value.IntValue;
            }
            if (Value.IntValue == NegativeRep) { return -1; }
            else
            {
                return Value.IntValue - 1;
            }
        }

        /// <summary>
        /// Returns the smallest integer that is greater than or equal to Value (Rounds up to integer value).
        /// </summary>
        /// <returns>AltDec&</returns>
        static int CeilInt(AltDec Value)
        {
            if (Value.DecimalHalf == 0)
            {
                return Value.IntValue;
            }
            if (Value.IntValue == NegativeRep) { return 0; }
            else
            {
                return Value.IntValue+1;
            }
        }
        
        /// <summary>
        /// Returns the largest integer that is smaller than or equal to Value (Rounds downs the nearest integer).
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>AltDec</returns>
        static AltDec Ceil(AltDec Value)
        {
            return Value.Ceil();
        }
        
        /// <summary>
        /// Cuts off the decimal point from number
        /// </summary>
        /// <returns>AltDec &</returns>
        AltDec& Trunc()
        {
            DecimalHalf = 0;
            if (IntValue == NegativeRep) { IntValue = 0; }
            return *this;
        }
        
        /// <summary>
        /// Cuts off the decimal point from number
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec Trunc(AltDec Value)
        {
            return Value.Trunc();
        }
        
        /// <summary>
        /// Forces Number into non-negative
        /// </summary>
        /// <returns>AltDec&</returns>
        AltDec& Abs()
        {
            if (IntValue == NegativeRep) { IntValue = 0; }
            else if (IntValue < 0) { IntValue *= -1; }
            return *this;
        }
        
        /// <summary>
        /// Forces Number into non-negative
        /// </summary>
        /// <param name="Value">The target value to apply on.</param>
        /// <returns>AltDec</returns>
        static AltDec Abs(AltDec Value)
        {
            return Value.Abs();
        }

        /// <summary>
        /// Applies Power of operation on references(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        AltDec PowOp(ValueType& expValue)
        {
            if (expValue == 1) { return *this; }//Return self
            else if (expValue == 0)
            { 
                IntValue = 1; DecimalHalf = 0;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (DecimalHalf == 0 && IntValue == 10 && expValue >= -9)
                {
                    IntValue = 0; DecimalHalf = DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1];
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    AltDec self = *this;
                    IntValue = 1; DecimalHalf = 0;// Initialize result
                    while (expValue > 0)
                    {
                        // If expValue is odd, multiply self with result
                        if (expValue % 2 == 1)
                            *this /= self;
                        // n must be even now
                        expValue = expValue >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return this;
                }
            }
            else if (DecimalHalf == 0 && IntValue == 10)
                IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            else if (DecimalHalf == 0 && IntValue == -10)
                IntValue = expValue % 2 ? VariableConversionFunctions::PowerOfTens[expValue] : VariableConversionFunctions::PowerOfTens[expValue] * -1;
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                AltDec self = *this;
                IntValue = 1; DecimalHalf = 0;// Initialize result
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        this *= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
            }
            return *this;
        }

        /// <summary>
        /// Applies Power of operation on references with const expValue(for integer exponents)(C3892 fix)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        AltDec PowConstOp(const ValueType& expValue)
        {
            if (expValue == 1) { return *this; }//Return self
            else if (expValue == 0)
            {
                IntValue = 1; DecimalHalf = 0;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (DecimalHalf == 0 && IntValue == 10 && expValue >= -9)
                {
                    int expVal = expValue * -1;
                    IntValue = 0; DecimalHalf = DecimalOverflow / VariableConversionFunctions::PowerOfTens[expVal];
                }
                else
                {
                    int expVal = expValue;
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expVal *= -1;
                    AltDec self = *this;
                    IntValue = 1; DecimalHalf = 0;// Initialize result
                    while (expVal > 0)
                    {
                        // If expValue is odd, multiply self with result
                        if (expVal % 2 == 1)
                            *this /= self;
                        // n must be even now
                        expVal = expVal >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return this;
                }
            }
            else if (DecimalHalf == 0 && IntValue == 10)
            {
                IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            }
            else
            {
                int expVal = expValue;
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                AltDec self = *this;
                IntValue = 1; DecimalHalf = 0;// Initialize result
                while (expVal > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expVal % 2 == 1)
                        this *= self;
                    // n must be even now
                    expVal = expVal >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
            }
            return *this;
        }

        /// <summary>
        /// Applies Power of operation on references with const expValue(for integer exponents)(C3892 fix)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static AltDec PowConstOp(AltDec& targetValue, const ValueType& expValue)
        {
            return targetValue.PowConstOp(expValue);
        }

        /// <summary>
        /// Applies Power of operation on references(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static AltDec PowOp(AltDec& targetValue, ValueType& expValue)
        {
            return targetValue.PowOp(expValue);
        }
        
        /// <summary>
        /// Applies Power of operation(for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        AltDec Pow(ValueType expValue)
        {
            return this->PowOp(expValue);
        }

        /// <summary>
        /// Applies Power of operation (for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static AltDec Pow(AltDec targetValue, ValueType expValue)
        {
            if (expValue == 1) { return targetValue; }//Return self
            else if (expValue == 0)
            {
                targetValue.IntValue = 1; targetValue.DecimalHalf = 0;
                return targetValue;
            }
            else if (expValue < 0)//Negative Pow
            {
                if (targetValue.DecimalHalf == 0 && targetValue.IntValue == 10 && expValue >= -9)
                {
                    targetValue.IntValue = 0; targetValue.DecimalHalf = AltDec::DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1];
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    AltDec self = targetValue;
                    targetValue.IntValue = 1; targetValue.DecimalHalf = 0;// Initialize result
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
            else if (targetValue.DecimalHalf == 0 && targetValue.IntValue == 10)
            {
                targetValue.IntValue = VariableConversionFunctions::PowerOfTens[expValue];
            }
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                AltDec self = targetValue;
                targetValue.IntValue = 1; targetValue.DecimalHalf = 0;// Initialize result
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
        /// Applies Power of operation (for integer exponents)
        /// </summary>
        /// <param name="expValue">The exponent value.</param>
        template<typename ValueType>
        static AltDec PowRef(AltDec& targetValue, ValueType expValue)
        {
            if (expValue == 1)
                return targetValue;//Return self
            else if (expValue == 0)
                return AltDec::One;
            else if (expValue < 0)//Negative Pow
            {
                if (targetValue.DecimalHalf == 0 && targetValue.IntValue == 10 && expValue >= -9)
                {
                    return AltDec(0, AltDec::DecimalOverflow / VariableConversionFunctions::PowerOfTens[expValue * -1]);
                }
                else
                {
                    //Code(Reversed in application) based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                    expValue *= -1;
                    AltDec self = targetValue;
                    AltDec Result = AltDec::One;
                    while (expValue > 0)
                    {
                        // If expValue is odd, divide self with result
                        if (expValue % 2 == 1)
                            Result /= self;
                        // n must be even now
                        expValue = expValue >> 1; // y = y/2
                        self = self / self; // Change x to x^-1
                    }
                    return Result;
                }
            }
            else if (targetValue.DecimalHalf == 0 && targetValue.IntValue == 10)
                return AltDec(VariableConversionFunctions::PowerOfTens[expValue], 0);
            else
            {
                //Code based on https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
                AltDec self = targetValue;
                AltDec Result = AltDec::One;
                while (expValue > 0)
                {
                    // If expValue is odd, multiply self with result
                    if (expValue % 2 == 1)
                        Result *= self;
                    // n must be even now
                    expValue = expValue >> 1; // y = y/2
                    self = self * self; // Change x to x^2
                }
                return Result;
            }
            return targetValue;
        }

        /// <summary>
        /// Perform square root on this instance.(Code other than switch statement from https://www.geeksforgeeks.org/find-square-root-number-upto-given-precision-using-binary-search/)
        /// </summary>
        static AltDec Sqrt(AltDec value, int precision=7)
        {
            if (value.DecimalHalf == 0)
            {
                bool AutoSetValue = true;
                switch (value.IntValue)
                {
                case 1: value.IntValue = 1; break;
                case 4: value.IntValue = 2; break;
                case 9: value.IntValue = 3; break;
                case 16: value.IntValue = 4; break;
                case 25: value.IntValue = 5; break;
                case 36: value.IntValue = 6; break;
                case 49: value.IntValue = 7; break;
                case 64: value.IntValue = 8; break;
                case 81: value.IntValue = 9; break;
                case 100: value.IntValue = 10; break;
                case 121: value.IntValue = 11; break;
                case 144: value.IntValue = 12; break;
                case 169: value.IntValue = 13; break;
                case 196: value.IntValue = 14; break;
                case 225: value.IntValue = 15; break;
                case 256: value.IntValue = 16; break;
                case 289: value.IntValue = 17; break;
                case 324: value.IntValue = 18; break;
                case 361: value.IntValue = 19; break;
                case 400: value.IntValue = 20; break;
                default:
                    AutoSetValue = false;
                    break;
                }
                if(AutoSetValue)
                {
                    return value;
                }
            }
            AltDec number = value;
            AltDec start = 0, end = number;
            AltDec mid;

            // variable to store the answer 
            AltDec ans;

            // for computing integral part 
            // of square root of number 
            while (start <= end) {
                mid = (start + end) / 2;
                if (mid * mid == number) {
                    ans = mid;
                    break;
                }

                // incrementing start if integral 
                // part lies on right side of the mid 
                if (mid * mid < number) {
                    start = mid + 1;
                    ans = mid;
                }

                // decrementing end if integral part 
                // lies on the left side of the mid 
                else {
                    end = mid - 1;
                }
            }

            // For computing the fractional part 
            // of square root up to given precision 
            AltDec increment = "0.1";
            for (int i = 0; i < precision; i++) {
                while (ans * ans <= number) {
                    ans += increment;
                }

                // loop terminates when ans * ans > number 
                ans = ans - increment;
                increment = increment / 10;
            }
            return ans;
        }

        /// <summary>
        /// Finds nTh Root of value based on https://www.geeksforgeeks.org/n-th-root-number/ code
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="nValue">The nth value.</param>
        /// <param name="precision">Precision level (smaller = more precise)</param>
        /// <returns>AltDec</returns>
        static AltDec NthRoot(AltDec value, int n, AltDec precision = AltDec::JustAboveZero)
        {
            AltDec xPre = 1+(value-1)/n;//Estimating initial guess based on https://math.stackexchange.com/questions/787019/what-initial-guess-is-used-for-finding-n-th-root-using-newton-raphson-method
            int nMinus1 = n - 1;

            // initializing difference between two 
            // roots by INT_MAX 
            AltDec delX = AltDec(2147483647, 0);

            //  xK denotes current value of x 
            AltDec xK;

            //  loop until we reach desired accuracy
            do
            {
                //  calculating current value from previous
                // value by newton's method
                xK = (nMinus1 * xPre +
                    value / AltDec::Pow(xPre, nMinus1)) / n;
                delX = AltDec::Abs(xK - xPre);
                xPre = xK;
            } while (delX > precision);
            return xK;
        }

        /// <summary>
        /// Get the (n)th Root
        /// Code based mostly from https://rosettacode.org/wiki/Nth_root#C.23
        /// </summary>
        /// <param name="n">The n value to apply with root.</param>
        /// <returns></returns>
        static AltDec NthRootV2(AltDec targetValue, int n, AltDec& Precision = AltDec::FiveBillionth)
        {
            int nMinus1 = n - 1;
            AltDec x[2] = { (AltDec::One / n) * ((nMinus1 * targetValue) + (targetValue / AltDec::Pow(targetValue, nMinus1))), targetValue };
            while (AltDec::Abs(x[0] - x[1]) > Precision)
            {
                x[1] = x[0];
                x[0] = (AltDec::One / n) * ((nMinus1 * x[1]) + (targetValue / AltDec::Pow(x[1], nMinus1)));
            }
            return x[0];
        }

        /// <summary>
        /// Taylor Series Exponential function derived from https://www.pseudorandom.com/implementing-exp
        /// </summary>
        /// <param name="x">The value to apply the exponential function to.</param>
        /// <returns>AltDec</returns>
        static AltDec Exp(AltDec x)
        {
            /*
             * Evaluates f(x) = e^x for any x in the interval [-709, 709].
             * If x < -709 or x > 709, raises an assertion error. Implemented
             * using the truncated Taylor series of e^x with ceil(|x| * e) * 12
             * terms. Achieves at least 14 and at most 16 digits of precision
             * over the entire interval.
             * Performance - There are exactly 36 * ceil(|x| * e) + 5
             * operations; 69,413 in the worst case (x = 709 or -709):
             * - (12 * ceil(|x| * e)) + 2 multiplications
             * - (12 * ceil(|x| * e)) + 1 divisions
             * - (12 * ceil(|x| * e)) additions
             * - 1 rounding
             * - 1 absolute value
             * Accuracy - Over a sample of 10,000 linearly spaced points in
             * [-709, 709] we have the following error statistics:
             * - Max relative error = 8.39803e-15
             * - Min relative error = 0.0
             * - Avg relative error = 0.0
             * - Med relative error = 1.90746e-15
             * - Var relative error = 0.0
             * - 0.88 percent of the values have less than 15 digits of precision
             * Args:
             *      - x: (AltDec float) power of e to evaluate
             * Returns:
             *      - (AltDec float) approximation of e^x in AltDec precision
             */
             // Check that x is a valid input.
            assert(-709 <= x.IntValue && x.IntValue <= 709);
            // When x = 0 we already know e^x = 1.
            if (x == AltDec::Zero) {
                return AltDec::One;
            }
            // Normalize x to a non-negative value to take advantage of
            // reciprocal symmetry. But keep track of the original sign
            // in case we need to return the reciprocal of e^x later.
            AltDec x0 = AltDec::Abs(x);
            // First term of Taylor expansion of e^x at a = 0 is 1.
            // tn is the variable we we will return for e^x, and its
            // value at any time is the sum of all currently evaluated
            // Taylor terms thus far.
            AltDec tn = AltDec::One;
            // Chose a truncation point for the Taylor series using the
            // heuristic bound 12 * ceil(|x| e), then work down from there
            // using Horner's method.
            int n = AltDec::CeilInt(x0 * AltDec::E) * 12;
            for (int i = n; i > 0; --i) {
                tn = tn * (x0 / i) + AltDec::One;
            }
            // If the original input x is less than 0, we want the reciprocal
            // of the e^x we calculated.
            if (x < 0) {
                tn = AltDec::One / tn;
            }
            return tn;
        }

        /// <summary>
        /// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expNum">The numerator of the exponent value.</param>
        /// <param name="expDenom">The denominator of the exponent value.</param>
        static AltDec FractionalPow(AltDec value, int expNum, int expDenom)
        {
            AltDec CalcVal = AltDec::NthRoot(AltDec::Pow(value, expNum), expDenom);
            return CalcVal;
        }

        /// <summary>
        /// Calculate value to a fractional power based on https://study.com/academy/lesson/how-to-convert-roots-to-fractional-exponents.html
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="Frac">The exponent value to raise the value to power of.</param>
        static AltDec FractionalPow(AltDec& value, boost::rational<int>& Frac)
        {
            AltDec CalcVal = AltDec::NthRoot(AltDec::Pow(value, Frac.numerator()), Frac.denominator());
            return CalcVal;
        }

        /// <summary>
        /// Applies Power of operation
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expValue">The exponent value.</param>
        static AltDec PowOp(AltDec& value, AltDec& expValue)
        {
            if (expValue.DecimalHalf == 0)
            {
                return value.Pow(expValue.IntValue);
            }
            else
            {
                boost::rational<int> Frac = boost::rational<int>(expValue.DecimalHalf, AltDec::DecimalOverflow);
                switch (expValue.IntValue)
                {
                    case 0:
                        return FractionalPow(value, Frac);
                        break;
                    case AltDec::NegativeRep:
                        return 1 / FractionalPow(value, Frac);
                        break;
                    default:
                    {
                        if (expValue.IntValue < 0)//Negative Exponent 
                        {
                            AltDec CalcVal = 1 / value.Pow(expValue.IntValue * -1);
                            CalcVal /= FractionalPow(value, Frac);
                            return CalcVal;
                        }
                        else
                        {
                            AltDec CalcVal = value.Pow(expValue.IntValue);
                            CalcVal *= FractionalPow(value, Frac);
                            return CalcVal;
                        }
                        break;
                    }
                }
            }
        }

        /// <summary>
        /// Applies Power of operation
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <param name="expValue">The exponent value.</param>
        static AltDec Pow(AltDec value, AltDec expValue)
        {
            return PowOp(value, expValue);
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <returns>BlazesRusCode::AltDec</returns>
        static AltDec LnRef(AltDec& value)
        {
            //if (value <= 0) {}else//Error if equal or less than 0
            if (value == AltDec::One)
                return AltDec::Zero;
            if (value.IntValue<2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer(for values between 1 and 2)
                AltDec threshold = AltDec::FiveMillionth;
                AltDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 2;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                AltDec term = base;       // First term
                AltDec prev;          // Previous sum
                AltDec result = term;     // Kick it off

                do
                {
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                    ++den;
                } while (AltDec::Abs(prev - result) > threshold);

                return result;
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {//Increasing iterations brings closer to accurate result(Larger numbers need more iterations to get accurate level of result)
                AltDec TotalRes = (value - 1) / (value + 1);
                AltDec LastPow = TotalRes;
                AltDec WSquared = TotalRes * TotalRes;
                AltDec AddRes;
                int WPow = 3;
                do
                {
                    LastPow *= WSquared;
                    AddRes = LastPow / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return TotalRes * 2;
            }
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        /// <returns>BlazesRusCode::AltDec</returns>
        static AltDec LnRefV2(AltDec& value)
        {
            //if (value <= 0) {}else//Error if equal or less than 0
            if (value == AltDec::One)
                return AltDec::Zero;
            if(value.IntValue==0)//Returns a negative number derived from (http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {
                AltDec W = (value - 1)/ (value + 1);
                AltDec TotalRes = W;
                W.SwapNegativeStatus();
                AltDec LastPow = W;
                AltDec WSquared = W * W;
                int WPow = 3;
                AltDec AddRes;

                do
                {
                    LastPow *= WSquared;
                    AddRes = LastPow / WPow;
                    TotalRes -= AddRes;
                    WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return TotalRes * 2;
            }
            else if (value.IntValue==1)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer(for values between 1 and 2)
                AltDec threshold = AltDec::FiveMillionth;
                AltDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 2;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                AltDec term = base;       // First term
                AltDec prev;          // Previous sum
                AltDec result = term;     // Kick it off

                do
                {
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                    ++den;
                } while (AltDec::Abs(prev - result) > threshold);

                return result;
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {//Increasing iterations brings closer to accurate result(Larger numbers need more iterations to get accurate level of result)
                AltDec TotalRes = (value - 1) / (value + 1);
                AltDec LastPow = TotalRes;
                AltDec WSquared = TotalRes * TotalRes;
                AltDec AddRes;
                int WPow = 3;
                do
                {
                    LastPow *= WSquared;
                    AddRes = LastPow / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return TotalRes * 2;
            }
        }

        /// <summary>
        /// Natural log (Equivalent to Log_E(value))
        /// </summary>
        /// <param name="value">The target value.</param>
        static AltDec Ln(AltDec value)
        {
            return LnRef(value);
        }

        /// <summary>
        /// Log Base 10 of Value
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec Log10(AltDec value)
        {
            if (value == AltDec::One)
                return AltDec::Zero;
            if (value.DecimalHalf == 0 && value.IntValue % 10 == 0)
            {
                for (int index = 1; index < 9; ++index)
                {
                    if (value == BlazesRusCode::VariableConversionFunctions::PowerOfTens[index])
                        return AltDec(index, 0);
                }
                return AltDec(9, 0);
            }
            if (value.IntValue<2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer for values between 1 & 2
                AltDec threshold = AltDec::FiveBillionth;
                AltDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 1;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                AltDec term = base;       // First term
                AltDec prev = 0;          // Previous sum
                AltDec result = term;     // Kick it off

                while (AltDec::Abs(prev - result) > threshold) {
                    den++;
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                }
                return result*AltDec::LN10Mult;// result/AltDec::LN10;//Using Multiplication instead of division for speed improvement
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {
                AltDec TotalRes = (value - 1) / (value + 1);
                AltDec LastPow = TotalRes;
                AltDec WSquared = TotalRes * TotalRes;
                AltDec AddRes;
                int WPow = 3;
                do
                {
                    LastPow *= WSquared;
                    AddRes = LastPow / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return TotalRes * AltDec::HalfLN10Mult;//Gives more accurate answer than attempting to divide by Ln10
            }
            //return AltDec::Ln(value) / AltDec::HaLN10;//Slightly off because of truncation etc
        }

        /// <summary>
        /// Log Base 10 of Value(integer value variant)
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        template<typename ValueType>
        static AltDec Log10(ValueType value)
        {
            if (value == 1)
                return AltDec::Zero;
            else if (value % 10 == 0)
            {
                for (int index = 1; index < 9; ++index)
                {
                    if (value == BlazesRusCode::VariableConversionFunctions::PowerOfTens[index])
                        return AltDec(index, 0);
                }
                return AltDec(9, 0);
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {
                AltDec TotalRes = AltDec((value - 1), 0) / AltDec((value + 1), 0);
                AltDec LastPow = TotalRes;
                AltDec WSquared = TotalRes * TotalRes;
                AltDec AddRes;
                int WPow = 3;
                do
                {
                    LastPow *= WSquared;
                    AddRes = LastPow / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return TotalRes * AltDec::HalfLN10Mult;//Gives more accurate answer than attempting to divide by Ln10
            }
        }

        /// <summary>
        /// Log with Base of BaseVal of Value
        /// Based on http://home.windstream.net/okrebs/page57.html
        /// </summary>
        /// <param name="value">The value.</param>
        /// <param name="baseVal">The base of Log</param>
        /// <returns>AltDec</returns>
        static AltDec Log(AltDec value, AltDec baseVal)
        {
            if (value == AltDec::One)
                return AltDec::Zero;
            return Log10(value) / Log10(baseVal);
        }

        /// <summary>
        /// Log with Base of BaseVal of Value
        /// Based on http://home.windstream.net/okrebs/page57.html
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <param name="BaseVal">The base of Log</param>
        /// <returns>AltDec</returns>
        static AltDec Log(AltDec value, int baseVal)
        {
            if (value == AltDec::One)
                return AltDec::Zero;
            //Calculate Base log first
            AltDec baseTotalRes;
            bool lnMultLog = true;
            if (baseVal % 10 == 0)
            {
                for (int index = 1; index < 9; ++index)
                {
                    if (baseVal == BlazesRusCode::VariableConversionFunctions::PowerOfTens[index])
                    {
                        baseTotalRes = AltDec(index, 0);
                        break;
                    }
                }
                baseTotalRes = AltDec(9, 0); lnMultLog = false;
            }
            else//Returns a positive baseVal(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {
                baseTotalRes = AltDec((baseVal - 1), 0) / AltDec((baseVal + 1), 0);
                AltDec baseLastPow = baseTotalRes;
                AltDec baseWSquared = baseTotalRes * baseTotalRes;
                AltDec baseAddRes;
                int baseWPow = 3;
                do
                {
                    baseLastPow *= baseWSquared;
                    baseAddRes = baseLastPow / baseWPow;
                    baseTotalRes += baseAddRes; baseWPow += 2;
                } while (baseAddRes > AltDec::JustAboveZero);
            }

            //Now calculate other log
            if (value.DecimalHalf == 0 && value.IntValue % 10 == 0)
            {
                for (int index = 1; index < 9; ++index)
                {
                    if (value == BlazesRusCode::VariableConversionFunctions::PowerOfTens[index])
                        return lnMultLog ? AltDec(index, 0) / (baseTotalRes * AltDec::HalfLN10Mult): AltDec(index, 0)/ baseTotalRes;
                }
                return lnMultLog? AltDec(9, 0) / (baseTotalRes*AltDec::HalfLN10Mult):AltDec(9, 0)/baseTotalRes;
            }
            if (value.IntValue < 2)//Threshold between 0 and 2 based on Taylor code series from https://stackoverflow.com/questions/26820871/c-program-which-calculates-ln-for-a-given-variable-x-without-using-any-ready-f
            {//This section gives accurate answer for values between 1 & 2
                AltDec threshold = AltDec::FiveBillionth;
                AltDec base = value - 1;        // Base of the numerator; exponent will be explicit
                int den = 1;              // Denominator of the nth term
                bool posSign = true;             // Used to swap the sign of each term
                AltDec term = base;       // First term
                AltDec prev = 0;          // Previous sum
                AltDec result = term;     // Kick it off

                while (AltDec::Abs(prev - result) > threshold) {
                    den++;
                    posSign = !posSign;
                    term *= base;
                    prev = result;
                    if (posSign)
                        result += term / den;
                    else
                        result -= term / den;
                }
                return lnMultLog? result/baseTotalRes:(result*2)/ baseTotalRes;
            }
            else//Returns a positive value(http://www.netlib.org/cephes/qlibdoc.html#qlog)
            {
                AltDec W = (value - 1) / (value + 1);
                AltDec TotalRes = W;
                AltDec AddRes;
                int WPow = 3;
                do
                {
                    AddRes = AltDec::PowRef(W, WPow) / WPow;
                    TotalRes += AddRes; WPow += 2;
                } while (AddRes > AltDec::JustAboveZero);
                return lnMultLog? TotalRes/baseTotalRes:(TotalRes * AltDec::HalfLN10Mult)/ baseTotalRes;
            }
            //return Log10(Value) / Log10(BaseVal);
        }

    #pragma endregion Math Etc Functions
    #pragma region Trigonomic Etc Functions
        /// <summary>
        /// Get Sin from Value of angle.
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec SinFromAngle(AltDec Value)
        {
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == NegativeRep)
                {
                    Value.IntValue = 359; Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf;
                }
                else
                {
                    Value.IntValue *= -1;
                    Value.IntValue %= 360;
                    Value.IntValue = 360 - Value.IntValue;
                    if (Value.DecimalHalf != 0) { Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf; }
                }
            }
            else
            {
                Value.IntValue %= 360;
            }
            if (Value == Zero) { return AltDec::Zero; }
            else if (Value.IntValue == 30 && Value.DecimalHalf == 0)
            {
                return PointFive;
            }
            else if (Value.IntValue == 90 && Value.DecimalHalf == 0)
            {
                return One;
            }
            else if (Value.IntValue == 180 && Value.DecimalHalf == 0)
            {
                return AltDec::Zero;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf == 0)
            {
                return NegativeOne;
            }
            else
            {
                AltDec NewValue = Zero;
                //Angle as Radian
                AltDec Radius = PI * Value / 180;
                for (int i = 0; i < 7; ++i)
                { // That's Taylor series!!
                    NewValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Radius, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
                }
                return NewValue;
            }
        }

        /// <summary>
        /// Get Cos() from Value of Angle
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns></returns>
        static AltDec CosFromAngle(AltDec Value)
        {
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == NegativeRep)
                {
                    Value.IntValue = 359; Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf;
                }
                else
                {
                    Value.IntValue *= -1;
                    Value.IntValue %= 360;
                    Value.IntValue = 360 - Value.IntValue;
                    if (Value.DecimalHalf != 0) { Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf; }
                }
            }
            else
            {
                Value.IntValue %= 360;
            }
            if (Value == Zero) { return One; }
            else if (Value.IntValue == 90 && Value.DecimalHalf == 0)
            {
                return AltDec::Zero;
            }
            else if (Value.IntValue == 180 && Value.DecimalHalf == 0)
            {
                return NegativeOne;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf == 0)
            {
                return AltDec::Zero;
            }
            else
            {
                AltDec NewValue = Zero;
                //Angle as Radian
                AltDec Radius = PI * Value / 180;
                for (int i = 0; i < 7; ++i)
                { // That's also Taylor series!!
                    NewValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Radius, 2 * i) / VariableConversionFunctions::Fact(2 * i);
                }
                return NewValue;
            }
        }

        /// <summary>
        /// Get Sin from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>AltDec</returns>
        static AltDec Sin(AltDec Value)
        {
            AltDec SinValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            return SinValue;
        }

        /// <summary>
        /// Get Sin from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>AltDec</returns>
        static AltDec Cos(AltDec Value)
        {
            AltDec CosValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return CosValue;
        }

        /// <summary>
        /// Get Tan from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value in Radians.</param>
        /// <returns>AltDec</returns>
        static AltDec Tan(AltDec Value)
        {
            AltDec SinValue = Zero;
            AltDec CosValue = Zero;
            for (int i = 0; i < 7; ++i)
            {
                SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            for (int i = 0; i < 7; ++i)
            {
                CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return SinValue / CosValue;
        }

        /// <summary>
        /// Get Tangent from Value in Degrees (SlopeInPercent:http://communityviz.city-explained.com/communityviz/s360webhelp4-2/formulas/function_library/atan_function.htm)
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec TanFromAngle(AltDec Value)
        {
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == NegativeRep)
                {
                    Value.IntValue = 359; Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf;
                }
                else
                {
                    Value.IntValue *= -1;
                    Value.IntValue %= 360;
                    Value.IntValue = 360 - Value.IntValue;
                    if (Value.DecimalHalf != 0) { Value.DecimalHalf = DecimalOverflow - Value.DecimalHalf; }
                }
            }
            else
            {
                Value.IntValue %= 360;
            }
            if (Value == Zero) { return AltDec::Zero; }
            else if (Value.IntValue == 90 && Value.DecimalHalf == 0)
            {
                return AltDec::Maximum;//Positive Infinity
            }
            else if (Value.IntValue == 180 && Value.DecimalHalf == 0)
            {
                return AltDec::Zero;
            }
            else if (Value.IntValue == 270 && Value.DecimalHalf == 0)
            {
                return AltDec::Minimum;//Negative Infinity
            }
            else
            {
                return Tan(PI * Value / 180);
            }
        }

        /// <summary>
        /// Gets Inverse Tangent from Value in Radians
        /// Formula code based on answer from https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>AltDec</returns>
        static AltDec ATan(AltDec Value)
        {
            AltDec SinValue = Zero;
            AltDec CosValue = Zero;
            //Angle as Radian
            for (int i = 0; i < 7; ++i)
            { // That's Taylor series!!
                SinValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i + 1) / VariableConversionFunctions::Fact(2 * i + 1);
            }
            for (int i = 0; i < 7; ++i)
            { // That's also Taylor series!!
                CosValue += (i % 2 == 0 ? 1 : -1) * AltDec::Pow(Value, 2 * i) / VariableConversionFunctions::Fact(2 * i);
            }
            return CosValue / SinValue;
        }

        /// <summary>
        /// atan2 calculation with self normalization
        /// Application: Used when one wants to compute the 4-quadrant arctangent of a complex number (or any number with x-y coordinates) with a self-normalizing function.
        /// Example Applications: digital FM demodulation, phase angle computations
        /// Code from http://dspguru.com/dsp/tricks/fixed-point-atan2-with-self-normalization/ with some slight edit to get working
        /// </summary>
        /// <param name="y">The y.</param>
        /// <param name="X">The x.</param>
        /// <returns>AltDec</returns>
        static AltDec ArcTan2(AltDec y, AltDec x)
        {
            AltDec coeff_1 = PI / 4;
            AltDec coeff_2 = 3 * coeff_1;
            AltDec abs_y = AltDec::Abs(y) + JustAboveZero;// kludge to prevent 0/0 condition
            AltDec r;
            AltDec angle;
            if (x >= 0)
            {
                r = (x - abs_y) / (x + abs_y);
                angle = coeff_1 - coeff_1 * r;
            }
            else
            {
                r = (x + abs_y) / (abs_y - x);
                angle = coeff_2 - coeff_1 * r;
            }
            if (y < 0)
                return -angle;// negate if in quad III or IV
            else
                return angle;
        }
    #pragma endregion Math/Trigonomic Etc Functions
    };

    #pragma region ValueDefine Source
    AltDec AltDec::PI = PIValue();
    AltDec AltDec::One = OneValue();
    AltDec AltDec::Two = TwoValue();
    AltDec AltDec::NegativeOne = NegativeOneValue();
    AltDec AltDec::Zero = ZeroValue();
    AltDec AltDec::PointFive = Point5Value();
    AltDec AltDec::JustAboveZero = JustAboveZeroValue();
    AltDec AltDec::OneMillionth = OneMillionthValue();
    AltDec AltDec::FiveThousandth = FiveThousandthValue();
    AltDec AltDec::Minimum = MinimumValue();
    AltDec AltDec::Maximum = MaximumValue();
    AltDec AltDec::E = EValue();
    AltDec AltDec::LN10 = LN10Value();
    AltDec AltDec::LN10Mult = LN10MultValue();
    AltDec AltDec::HalfLN10Mult = HalfLN10MultValue();
    AltDec AltDec::TenMillionth = TenMillionthValue();
    AltDec AltDec::FiveMillionth = FiveMillionthValue();
    AltDec AltDec::FiveBillionth = FiveBillionthValue();
    AltDec AltDec::OneGMillionth = OneHundredMillionthValue();
    AltDec AltDec::Nil = NilValue();
    AltDec AltDec::PINum = PINumValue();
    AltDec AltDec::ENum = ENumValue();
    
#if defined(AltDec_EnableInfinityRep)
    AltDec AltDec::Infinity = InfinityValue();
    AltDec AltDec::NegativeInfinity = NegativeInfinityValue();
    AltDec AltDec::ApproachingZero = ApproachingZeroValue();
#endif
#if defined(AltDec_EnableNaN)
    AltDec AltDec::NaN = NaNValue();
#endif
    #pragma endregion ValueDefine Source

    #pragma region String Function Source
    /// <summary>
    /// Reads the string.
    /// </summary>
    /// <param name="Value">The value.</param>
    inline void AltDec::ReadString(std::string Value)
    {
        IntValue = 0; DecimalHalf = 0;
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
                    DecimalHalf += TempInt02;
                }
                PlaceNumber--;
            }
        }
        if (IsNegative)
        {
            if (IntValue == 0) { IntValue = NegativeRep; }
            else { IntValue *= -1; }
        }
    }

    /// <summary>
    /// Gets the value from string.
    /// </summary>
    /// <param name="Value">The value.</param>
    /// <returns>AltDec</returns>
    inline AltDec AltDec::GetValueFromString(std::string Value)
    {
        AltDec NewSelf = Zero;
        NewSelf.ReadString(Value);
        return NewSelf;
    }

    std::string AltDec::ToString()
    {
        std::string Value = "";
        int CurrentSection = IntValue;
        unsigned __int8 CurrentDigit;
        std::string DecBuffer = "";
        if (IntValue < 0)
        {
            Value += "-";
            if (IntValue == NegativeRep) { CurrentSection = 0; }
            else { CurrentSection *= -1; }
        }
        for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
        }
        if (DecimalHalf != 0)
        {
            Value += ".";
            CurrentSection = DecimalHalf;
            for (__int8 Index = 8; Index >= 0; --Index)
            {
                CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
                CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
                if (CurrentDigit != 0)
                {
                    if(!DecBuffer.empty())
                    {
                        Value += DecBuffer;
                        DecBuffer.clear();
                    }
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
                else
                {
                    DecBuffer += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
            }
        }
        return Value;
    }

    std::string AltDec::ToFullString()
    {
        std::string Value = "";
        int CurrentSection = IntValue;
        unsigned __int8 CurrentDigit;
        if (IntValue < 0)
        {
            Value += "-";
            if (IntValue == NegativeRep) { CurrentSection = 0; }
            else { CurrentSection *= -1; }
        }
        for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(CurrentSection); Index >= 0; Index--)
        {
            CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
            CurrentSection -= (signed int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
            Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
        }
        if (DecimalHalf != 0)
        {
            Value += ".";
            bool HasDigitsUsed = false;
            CurrentSection = DecimalHalf;
            for (__int8 Index = 8; Index >= 0; --Index)
            {
                if (CurrentSection > 0)
                {
                    CurrentDigit = (unsigned __int8)(CurrentSection / VariableConversionFunctions::PowerOfTens[Index]);
                    CurrentSection -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
                    Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
                }
                else
                    Value += "0";
            }
        }
        else
        {
            Value += ".000000000";
        }
        return Value;
    }
    #pragma endregion String Function Source

    /// <summary>
    /// (AltDec Version)Performs remainder operation then saves division result
    /// C = A - B * (A / B)
    /// </summary>
    class DLL_API AltModChecker : public AltNumModChecker<AltDec>
    {
    };
}