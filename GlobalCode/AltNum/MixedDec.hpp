// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"

#include "MediumDec.hpp"
//Modulus code will be adjusted later
//Bitwise based operation code will be coded later(not fully implimented yet--though likely inaccurate even for normal representation) 

//Preprocessor Switches
/*
MixedDec_EnableImaginaryNumRep = (+- 2147483647.999999999)i Representation enabled(Not Fully Implimented)
MixedDec_EnableENumRep = E*(+- 2147483647.999999999) Representation enabled(Not Fully Implimented)
MixedDec_EnablePIRep = PI*(+- 2147483647.999999999) Representation enabled(Not Fully Implimented)
MixedDec_EnableInfinityRep = (Not Fully Implimented)
MixedDec_EnableAltFloat = Possible alternative floating point representation later(Not Implimented)
*/

namespace BlazesRusCode
{
    class MixedDec;

    /// <summary>
    /// Alternative Non-Integer number representation with focus on accuracy and partially speed within certain range
    /// Represents +- 2147483647.999999999(with extra digit representation in floating point)
    /// (Optional support later for PI*(+- 2147483647.999999999), E*(+- 2147483647.999999999), and (+- 2147483647.999999999)i)
    /// (12 bytes worth of Variable Storage inside class for each instance)
    /// </summary>
    class DLL_API MixedDec : BlazesRusCode::MediumDec
    {
	private:
#if defined(MixedDec_EnablePIRep)
		float PIRep = -1.0f;
#endif
#if defined(MixedDec_EnableENumRep)
		float ERep = -2.0f;
#endif
#if defined(MixedDec_EnableImaginaryNumRep)
		float IRep = -3.0f;
#endif
#if defined(MixedDec_EnableImaginaryNumRep)
		float IRep = -4.0f;
#endif
    public:
        // <summary>
        /// If both DecimalHalf&ExtraRep are Positive with ExtraRep as non-zero, then ExtraRep acts as denominator
        /// If DecimalHalf is positive and ExtraRep is -2147483648, then MixedDec represents +- 2147483647.999999999 * PI
        /// If ExtraRep is -1 and 
        /// If ExtraRep is zero, then MixedDec represents +- 2147483647.999999999
        /// </summary>
        float ExtraRep;
        
        /// <summary>
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="intVal">The int value.</param>
        /// <param name="decVal01">The decimal val01.</param>
        /// <param name="decVal02">ExtraRep.</param>
        MixedDec(signed int intVal = 0, signed int decVal = 0, float extraVal = 0.0f)
        {
            IntValue = intVal;
            DecimalHalf = decVal;
            ExtraRep = extraVal;
        }
        
        void SetAsZero()
        {
            IntValue = 0; DecimalHalf = 0;
            ExtraRep = 0.0f;
        }
        
        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(MixedDec Value)
        {
            IntValue = Value.IntValue;
            DecimalHalf01 = Value.DecimalHalf01; ExtraRep = Value.ExtraRep;
        }
		
        /// <summary>
        /// Sets the value.
        /// </summary>
        /// <param name="Value">The value.</param>
        void SetVal(MediumDec Value)
        {
            IntValue = Value.IntValue;
            DecimalHalf01 = Value.DecimalHalf01; ExtraRep = 0.0f;
        }
        
#if defined(MixedDec_EnablePIRep)
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
#endif
        
protected:
        static MixedDec PINumValue()
        {
            return MixedDec(3, 141592654, 0);
        }
        
        static MixedDec ENumValue()
        {
            return MixedDec(2, 718281828, 0);
        }
        
        static MixedDec PIValue()
        {
            return MixedDec(1, 0, -2147483648);
        }
		
        static MixedDec ZeroValue()
        {
            return MixedDec(0, 0, 0);
        }
        
        static MixedDec EValue()
        {
#if defined(MixedDec_EnableENumRep)
            return MixedDec(1, 0, ERep); 
#else
            return MixedDec(2, 718281828, 0); 
#endif
        }
        
public:
        /// <summary>
        /// Returns PI(3.1415926535897932384626433) with tenth digit rounded up(3.141592654)
        /// </summary>
        /// <returns>MediumDec</returns>
        static MixedDec PINum;
        
        /// <summary>
        /// Euler's number (Non-Alternative Representation)
        /// Irrational number equal to about (1 + 1/n)^n
        /// (about 2.71828182845904523536028747135266249775724709369995)
        /// </summary>
        /// <returns>MediumDec</returns>
        static MixedDec ENum;
        
        static MixedDec PI;
        
        static MixedDec E;
		
		static MixedDec Zero;
        
#if defined(MixedDec_EnableImaginaryNumRep)
        void SetImaginaryVal(MediumDec Value)
        {
            IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
            ExtraRep = IRep;
        }
        
        void SetImaginaryVal(int Value)
        {
            IntValue = Value; DecimalHalf = 0;
            ExtraRep = IRep;
        }
#endif

#if defined(MixedDec_EnableENumRep)
        void SetEVal(MediumDec Value)
        {
            IntValue = Value.IntValue; DecimalHalf = Value.DecimalHalf;
            ExtraRep = ERep;
        }
        
        void SetEVal(int Value)
        {
            IntValue = Value; DecimalHalf = 0;
            ExtraRep = ERep;
        }
#endif

#ifdef MixedDec_EnableInfinityRep
        void SetAsPositiveInfinity()
        {
            IntValue = 2147483647; DecimalHalf = 2147483647; ExtraRep = 0.0f;
        }
        
        void SetAsNegativeInfinity()
        {
            IntValue = -2147483648; DecimalHalf = -2147483648; ExtraRep = 0.0f;
        }
#endif

        void UpdateValue(MediumDec& UpdateTarget)
        {
			UpdateTarget.IntValue = IntValue; UpdateTarget.DecimalHalf = DecimalHalf;
#if defined(MixedDec_EnablePIRep)
			if(ExtraRep==PIRep)
			{
				UpdateTarget *= MediumDec::PI;
				return;
			}
#endif
#if defined(MixedDec_EnableENumRep)
			if(ExtraRep==ERep)
			{
				UpdateTarget *= MediumDec::E;
			}
#endif
        }
        
        void ConvertToNumRep()
        {
#if defined(MixedDec_EnablePIRep)
			if(ExtraRep==PIRep)
			{
				UpdateTarget *= PINum; ExtraRep = 0.0f;
				return;
			}
#endif
#if defined(MixedDec_EnableERep)
			if(ExtraRep==ERep)
			{
				UpdateTarget *= ENum; ExtraRep = 0.0f;
			}
#endif
        }
        
    #pragma region Comparison Operators
        /// <summary>
        /// Equal to Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator==(MixedDec self, MixedDec Value)
        {
            self.ConvertToNumRep(); Value.ConvertToNumRep();
            return (self.IntValue == Value.IntValue && self.DecimalHalf == Value.DecimalHalf);
        }

        /// <summary>
        /// Not equal to Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator!=(MixedDec self, MixedDec Value)
        {
            self.ConvertToNumRep(); Value.ConvertToNumRep();
            return (self.IntValue != Value.IntValue || self.DecimalHalf != Value.DecimalHalf);
        }

        /// <summary>
        /// Lesser than Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<(MixedDec self, MixedDec Value)
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
        /// Lesser than or Equal to Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator<=(MixedDec self, MixedDec Value)
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
        /// Greater than Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The right side value.</param>
        /// <returns>bool</returns>
        friend bool operator>(MixedDec self, MixedDec Value)
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
        /// Greater than or Equal to Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>bool</returns>
        friend bool operator>=(MixedDec self, MixedDec Value)
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
        
    #pragma region MixedDec-To-MixedDec Operators
    public:
/*        /// <summary>
        /// Basic Addition Operation Between MixedDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        void BasicAddOp(MixedDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return self;
                if (DecimalHalf == 0)
                {
                    IntValue += Value.IntValue;
                }
                else
                {
                    bool WasNegative = IntValue < 0;
                    if (WasNegative)
                        IntValue = IntValue == MixedDec::NegativeZero ? -1 : --IntValue;
                    IntValue += Value.IntValue;
                    if (IntValue == -1)
                        IntValue = DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                    else if (IntValue < 0)
                        ++IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                        DecimalHalf = MixedDec::DecimalOverflow - DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    IntValue = IntValue == MixedDec::NegativeZero ? -1 : --IntValue;
                if (Value.IntValue != 0 && Value.IntValue != MixedDec::NegativeZero)
                    IntValue += Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; --IntValue; }
                    }
                    else
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; ++IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; --IntValue; }
                    }
                    else
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; ++IntValue; }
                    }
                }
                if (IntValue == -1)
                    IntValue = DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                else if (IntValue < 0)
                    ++IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                    DecimalHalf = MixedDec::DecimalOverflow - DecimalHalf;
            }
        }
    
        /// <summary>
        /// Addition Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        static MixedDec& AddOp(MixedDec& self, MixedDec& Value)
        {
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0||ExtraRep==NegativeZero)
                {
#if MixedDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.BasicAddOp(Value);
#if MixedDec_EnableMixedFractional
                    }
#endif
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else if(self.ExtraRep==RevMaxInt)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
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
                    MixedDec ValueCopy = Value;
                    Value.ConvertToNumRep();
                    self.BasicAddOp(ValueCopy);
                }
            }
            return self;
        }

        /// <summary>
        /// Basic Subtraction Operation Between MixedDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        void BasicSubOp(MixedDec& Value)
        {
            if (Value.DecimalHalf == 0)
            {
                if (Value.IntValue == 0)//(Value == Zero)
                    return self;
                if (DecimalHalf == 0)
                {
                    IntValue -= Value.IntValue;
                }
                else
                {
                    bool WasNegative = IntValue < 0;
                    if (WasNegative)
                        IntValue = IntValue == MixedDec::NegativeZero ? -1 : --IntValue;
                    if (Value.IntValue != 0)
                        IntValue -= Value.IntValue;
                    if(IntValue==-1)
                        IntValue = DecimalHalf == 0?0:MixedDec::NegativeZero;
                    else if(IntValue<0)
                        ++IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && IntValue >= 0)||(WasNegative == 0 && IntValue < 0))
                        DecimalHalf = MixedDec::DecimalOverflow - DecimalHalf;
                }
            }
            else
            {
                bool WasNegative = IntValue < 0;
                //Deal with Int section first
                if (WasNegative)
                    IntValue = IntValue == MixedDec::NegativeZero ? -1 : --IntValue;
                if(Value.IntValue!=0&&Value.IntValue!=MixedDec::NegativeZero)
                    IntValue -= Value.IntValue;
                //Now deal with the decimal section
                if (Value.IntValue < 0)
                {
                    if (WasNegative)//-4.0 - -0.5 = -3.5
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; --IntValue; }
                    }
                    else//4.3 -  - 1.8
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; ++IntValue; }
                    }
                }
                else
                {
                    if (WasNegative)//-4.5 - 5.6
                    {
                        DecimalHalf += Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; ++IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; --IntValue; }
                    }
                    else//0.995 - 1 = 
                    {
                        DecimalHalf -= Value.DecimalHalf;
                        if (DecimalHalf < 0) { DecimalHalf += MixedDec::DecimalOverflow; --IntValue; }
                        else if (DecimalHalf >= MixedDec::DecimalOverflow) { DecimalHalf -= MixedDec::DecimalOverflow; ++IntValue; }
                    }
                }
                if (IntValue == -1)
                    IntValue = DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                else if (IntValue < 0)
                    ++IntValue;
                //If flips to other side of negative, invert the decimals
                if ((WasNegative && IntValue >= 0) || (WasNegative == 0 && IntValue < 0))
                    DecimalHalf = MixedDec::DecimalOverflow - DecimalHalf;
            }
        }

        /// <summary>
        /// Subtraction Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        static MixedDec& SubOp(MixedDec& self, MixedDec& Value)
        {
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0||self.ExtraRep==NegativeZero)
                {
#if MixedDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.BasicSubOp(Value);
#if MixedDec_EnableMixedFractional
                    }
#endif
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else if(self.ExtraRep==RevMaxInt)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else
                {
                
                }
    #endif
                if(self.ExtraRep!=0&&self.IntValue==0&&self.DecimalStatus==0)
                    self.ExtraRep = 0;
            }
            else
            {
                if(self.ExtraRep==0)
                {
                
                }
                else//Catch-all for other representation combinations
                {
                    MixedDec ValueCopy = Value;
                    Value.ConvertToNumRep();
                    self.BasicAddOp(ValueCopy);
                }
            }
            return self;
        }

        void PartialMultOp(MixedDec& Value)
        {
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == MixedDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                SwapNegativeStatus();
            }
            if (DecimalHalf == 0)
            {
                if (IntValue == 1) { self = Value; return self; }
                else if (Value.DecimalHalf == 0)
                {
                    IntValue *= Value.IntValue; return self;
                }
                else
                {
                    Value *= IntValue;
                    self = Value;
                }
            }
            else if (IntValue == 0)
            {
                __int64 SRep = (__int64)DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= MixedDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)DecimalHalf * Value.IntValue;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
                        IntValue = OverflowVal;
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        DecimalHalf = (signed int)SRep;
                    }
                }
            }
            else if (IntValue == MixedDec::NegativeZero)
            {
                __int64 SRep = (__int64)DecimalHalf;
                SRep *= Value.DecimalHalf;
                SRep /= MixedDec::DecimalOverflowX;
                if (Value.IntValue == 0)
                {
                    DecimalHalf = (signed int)SRep;
                }
                else
                {
                    SRep += (__int64)DecimalHalf * Value.IntValue;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
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
                    __int64 SRep = MixedDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.DecimalHalf;
                    SRep /= MixedDec::DecimalOverflowX;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
                        IntValue = (signed int)(SelfIsNegative ? -OverflowVal : OverflowVal);
                        DecimalHalf = (signed int)SRep;
                    }
                    else
                    {
                        IntValue = SelfIsNegative ? MixedDec::NegativeZero : 0;
                        DecimalHalf = (signed int)SRep;
                    }
                }
                else if (Value.DecimalHalf == 0)//Y is integer
                {
                    __int64 SRep = MixedDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.IntValue;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
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
                    __int64 SRep = IntValue == 0 ? DecimalHalf : MixedDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep *= Value.IntValue;//SRep holds __int64 version of X.Y * Z
                    //X.Y *.V
                    __int64 Temp03 = (__int64)IntValue * Value.DecimalHalf;//Temp03 holds __int64 version of X *.V
                    __int64 Temp04 = (__int64)DecimalHalf * (__int64)Value.DecimalHalf;
                    Temp04 /= MixedDec::DecimalOverflow;
                    //Temp04 holds __int64 version of .Y * .V
                    __int64 IntegerRep = SRep + Temp03 + Temp04;
                    __int64 IntHalf = IntegerRep / MixedDec::DecimalOverflow;
                    IntegerRep -= IntHalf * (__int64)MixedDec::DecimalOverflow;
                    if (IntHalf == 0) { IntValue = (signed int)SelfIsNegative ? MixedDec::NegativeZero : 0; }
                    else { IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    DecimalHalf = (signed int)IntegerRep;
                }
            }
        }

        /// <summary>
        /// Basic Multiplication Operation Between MixedDecs
        /// </summary>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        void BasicMultOp(MixedDec& Value)
        {
            if (Value == MixedDec::Zero) { SetAsZero(); return; }
            if ((IntValue==0&&DecimalStatus==0) || Value == MixedDec::One)
                return;
            PartialMultOp(Value);
            if (IntValue==0&&DecimalStatus==0) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
        }

        /// <summary>
        /// Multiplication Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        static MixedDec& MultOp(MixedDec& self, MixedDec& Value)
        {
            if (Value == MixedDec::Zero) { self.SetAsZero(); return self; }
            if (self == MixedDec::Zero || Value == MixedDec::One)
                return self;
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0)
                {
#if MixedDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.PartialMultOp(Value);
#if MixedDec_EnableMixedFractional
                    }
#endif
                }
                else if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else if(self.ExtraRep==RevMaxInt)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            if(self.ExtraRep!=0&&self.IntValue==0&&self.DecimalStatus==0)
                self.ExtraRep = 0;
            if (self == MixedDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }

        void PartialDivOp(MixedDec& Value)
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
                    __int64 SRep = IntValue * MixedDec::DecimalOverflowX;
                    __int64 YRep = Value.IntValue;
                    SRep /= Value.IntValue;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
                        IntValue = IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    }
                    else
                    {
                        IntValue = SelfIsNegative ? MixedDec::NegativeZero : 0;
                    }
                    DecimalHalf = (signed int)SRep;
                }
                else//Only self is integer while Value has both sides
                {
                    boost::multiprecision::uint128_t SRep02 = MixedDec::DecimalOverflowX * MixedDec::DecimalOverflowX;
                    SRep02 *= IntValue;
                    __int64 VRep = MixedDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
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
                __int64 SRep = (__int64)DecimalHalf * MixedDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : MixedDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / MixedDec::DecimalOverflowX;
                SRep -= IntHalf * MixedDec::DecimalOverflowX;
                IntValue = IntHalf;
                DecimalHalf = (signed int)SRep;
            }
            else if (IntValue == MixedDec::NegativeZero)
            {
                __int64 SRep = (__int64)DecimalHalf * MixedDec::DecimalOverflowX;
                SRep /= Value.IntValue == 0 ? Value.DecimalHalf : MixedDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                int IntHalf = SRep / MixedDec::DecimalOverflowX;
                SRep -= IntHalf * MixedDec::DecimalOverflowX;
                IntValue = IntHalf == 0 ? MixedDec::NegativeZero : -IntHalf;
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
                    __int64 SRep = MixedDec::DecimalOverflowX * IntValue + DecimalHalf;
                    SRep /= Value.IntValue;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
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
                    __int64 SRep_DecHalf = (__int64)DecimalHalf * MixedDec::DecimalOverflowX;
                    SRep_DecHalf /= Value.IntValue == 0 ? Value.DecimalHalf : MixedDec::DecimalOverflowX * Value.IntValue + (__int64)Value.DecimalHalf;
                    int IntHalf = SRep_DecHalf / MixedDec::DecimalOverflowX;
                    SRep_DecHalf -= IntHalf * MixedDec::DecimalOverflowX;

                    boost::multiprecision::uint128_t SRep02 = MixedDec::DecimalOverflowX * MixedDec::DecimalOverflowX;
                    //std::cout << "Multi-precision as String:" << SRep02 << std::endl;
                    SRep02 *= IntValue;
                    __int64 VRep = MixedDec::DecimalOverflowX * Value.IntValue + Value.DecimalHalf;
                    SRep02 /= VRep;
                    __int64 SRep = (__int64)SRep02 + SRep_DecHalf;
                    if (SRep >= MixedDec::DecimalOverflowX)
                    {
                        __int64 OverflowVal = SRep / MixedDec::DecimalOverflowX;
                        SRep -= OverflowVal * MixedDec::DecimalOverflowX;
                        IntHalf += OverflowVal;
                    }
                    if (IntHalf == 0) { IntValue = (signed int)SelfIsNegative ? MixedDec::NegativeZero : 0; }
                    else { IntValue = (signed int)SelfIsNegative ? IntHalf * -1 : IntHalf; }
                    DecimalHalf = (signed int)SRep;
                }
            }
        }

        void BasicDivOp(MixedDec& Value)
        {
            if (Value == MixedDec::Zero)
                throw "Target value can not be divided by zero";
            if (IntValue==0&&DecimalStatus==0)
                return;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == MixedDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                SwapNegativeStatus();
            }
            PartialDivOp(Value);
            if (IntValue==0&&DecimalStatus==0) { DecimalHalf = 1; }//Prevent Dividing into nothing
        }

        /// <summary>
        /// Division Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        static MixedDec& DivOp(MixedDec& self, MixedDec& Value)
        {
            if (Value == MixedDec::Zero)
                throw "Target value can not be divided by zero";
            if (self == MixedDec::Zero)
                return self;
            if (Value.IntValue < 0)
            {
                if (Value.IntValue == MixedDec::NegativeZero) { Value.IntValue = 0; }
                else { Value.IntValue *= -1; }
                self.SwapNegativeStatus();
            }
            if(self.ExtraRep==Value.ExtraRep)
            {
                if(self.ExtraRep==0)
                {
#if MixedDec_EnableMixedFractional
                    if(self.DecimalHalf<0)//MixedFractional
                    {
                    
                    }
                    else
                    {
#endif
                        self.PartialDivOp(Value);
#if MixedDec_EnableMixedFractional
                    }
#endif
                }
                else if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else if(self.ExtraRep==RevMaxInt)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            if (self == MixedDec::Zero) { self.DecimalHalf = 1; }//Prevent Dividing into nothing
            return self;
        }

        void PartialRemOp(MixedDec& Value)
        {
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MixedDec&</returns>
        static MixedDec& RemOp(MixedDec& self, MixedDec& Value)
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
                }
                else if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else if(self.ExtraRep==RevMaxInt)
                {
                }
                else if(self.ExtraRep>0)
    #else
                else//(Value/ExtraRep) Representation
    #endif
                {
                
                }
    #if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
                else
                {
                
                }
    #endif
            }
            return self;
        }
       */ 
    public:
        /// <summary>
        /// Addition Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator+(MixedDec self, MixedDec Value)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// += Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator+=(MixedDec& self, MixedDec Value)
        {
            return AddOp(self, Value);
        }
        
        /// <summary>
        /// += Operation Between MixedDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator+=(MixedDec* self, MixedDec Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator-(MixedDec self, MixedDec Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator-=(MixedDec& self, MixedDec Value)
        {
            return SubOp(self, Value);
        }
        
        /// <summary>
        /// -= Operation Between MixedDecs(from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator-=(MixedDec* self, MixedDec Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator*(MixedDec self, MixedDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between MixedDecs
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MixedDec</returns>
        friend MixedDec& operator*=(MixedDec& self, MixedDec Value)
        {
            return MultOp(self, Value);
        }

        ///// <summary>
        ///// *= Operation Between MixedDecs (from pointer)
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MixedDec</returns>
        friend MixedDec& operator*=(MixedDec* self, MixedDec Value){ return MultOp(**self, Value); }


        /// <summary>
        /// Division Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator/(MixedDec self, MixedDec Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator/=(MixedDec& self, MixedDec Value)
        {
            return DivOp(self, Value);
        }
        
        /// <summary>
        /// /= Operation Between MixedDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator/=(MixedDec* self, MixedDec Value){ return DivOp(**self, Value); }

        /// <summary>
        /// Remainder Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator%(MixedDec self, MixedDec Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator%=(MixedDec& self, MixedDec Value)
        {
            return RemOp(self, Value);
        }
        
        /// <summary>
        /// %= Operation Between MixedDecs (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        friend MixedDec& operator%=(MixedDec* self, MixedDec Value)
        {
            return RemOp(**self, Value);
        }

        /// <summary>
        /// XOR Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator^(MixedDec self, MixedDec Value)
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
        /// Bitwise Or Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator|(MixedDec self, MixedDec Value)
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
        /// Bitwise And Operation Between MixedDecs
        /// </summary>
        /// <param name="self">The left side value</param>
        /// <param name="Value">The right side value</param>
        /// <returns>MixedDec</returns>
        friend MixedDec operator&(MixedDec self, MixedDec Value)
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
        /// <returns>MixedDec</returns>
        friend MixedDec& operator-(MixedDec& self)
        {
            self.SwapNegativeStatus(); return self;
        }

        /// <summary>
        /// ++MixedDec Operator
        /// </summary>
        /// <returns>MixedDec &</returns>
        MixedDec& operator ++()
        {
            if (IntValue == NegativeZero) { IntValue = 0; }
            else if (DecimalHalf == 0) { ++IntValue; }
            else if (IntValue == -1) { IntValue = NegativeZero; }
            else { ++IntValue; }
            return *this;
        }

        /// <summary>
        /// ++MixedDec Operator
        /// </summary>
        /// <returns>MixedDec &</returns>
        MixedDec& operator --()
        {
            if (IntValue == NegativeZero) { IntValue = -1; }
            else if (DecimalHalf == 0) { --IntValue; }
            else if (IntValue == 0) { IntValue = NegativeZero; }
            else { --IntValue; }
            return *this;
        }

        /// <summary>
        /// MixedDec++ Operator
        /// </summary>
        /// <returns>MixedDec</returns>
        MixedDec operator ++(int)
        {
            MixedDec tmp(*this);
            ++* this;
            return tmp;
        }

        /// <summary>
        /// MixedDec-- Operator
        /// </summary>
        /// <returns>MixedDec</returns>
        MixedDec operator --(int)
        {
            MixedDec tmp(*this);
            --* this;
            return tmp;
        }

        /// <summary>
        /// MixedDec* Operator
        /// </summary>
        /// <returns>MixedDec &</returns>
        MixedDec& operator *()
        {
            return *this;
        }
    #pragma endregion MixedDec-To-MixedDec Operators

    #pragma region MixedDec-To-Int Comparison Operators
        /// <summary>
        /// Equality Operation between <see cref="MixedDec &"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(MixedDec self, IntType Value)
        {
            self.ConvertToNumRep();
            return (self.IntValue == Value && self.DecimalHalf == 0);
        }

        /// <summary>
        /// != Operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(MixedDec self, IntType Value)
        {
            self.ConvertToNumRep();
            if (self.DecimalHalf > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(MixedDec self, IntType Value)
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
        /// Lesser than or equal to operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(MixedDec self, IntType Value)
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
        /// Greater than operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(MixedDec self, IntType Value)
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
        /// Greater than or equal to operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(MixedDec self, IntType Value)
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
        /// Equality Operation between Integer Type and <see cref="MixedDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator==(IntType Value, MixedDec self)
        {
            self.ConvertToNumRep();
            return (self.IntValue == Value && self.DecimalHalf == 0);
        }

        /// <summary>
        /// != Operation between Integer Type and <see cref="MixedDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator!=(IntType Value, MixedDec self)
        {
            self.ConvertToNumRep();
            if (self.DecimalHalf > 0) { return true; }
            else if (self.IntValue == Value && self.DecimalHalf == 0) { return false; }
            else { return true; };
        }

        /// <summary>
        /// Lesser than Operation between Integer Type and <see cref="MixedDec"/> .
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<(IntType Value, MixedDec self)
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
        /// Lesser than or equal to operation between Integer Type and <see cref="MixedDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator<=(IntType Value, MixedDec self)
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
        /// Greater than operation between Integer Type and <see cref="MixedDec"/>.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>(IntType Value, MixedDec self)
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
        /// Greater than or equal to operation between <see cref="MixedDec"/> and Integer Type.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>bool</returns>
        template<typename IntType>
        friend bool operator>=(IntType Value, MixedDec self)
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

    #pragma endregion MixedDec-To-Int Comparison Operators
    #pragma region Other Operations
        friend MixedDec operator+(MixedDec self, float Value) { return self + (MixedDec)Value; }
        friend MixedDec operator-(MixedDec self, float Value) { return self - (MixedDec)Value; }
        friend MixedDec operator*(MixedDec self, float Value) { return self * (MixedDec)Value; }
        friend MixedDec operator/(MixedDec self, float Value) { return self / (MixedDec)Value; }
        friend MixedDec operator%(MixedDec self, float Value) { return self % (MixedDec)Value; }
        friend MixedDec operator^(MixedDec self, float Value) { return self ^ (MixedDec)Value; }
        friend MixedDec operator|(MixedDec self, float Value) { return self | (MixedDec)Value; }
        friend MixedDec operator&(MixedDec self, float Value) { return self & (MixedDec)Value; }

        friend MixedDec operator+(float Value, MixedDec self) { return (MixedDec)Value + self; }
        friend MixedDec operator-(float Value, MixedDec self) { return (MixedDec)Value - self; }
        friend MixedDec operator*(float Value, MixedDec self) { return (MixedDec)Value * self; }
        friend MixedDec operator/(float Value, MixedDec self) { return (MixedDec)Value / self; }
        friend MixedDec operator%(float Value, MixedDec self) { return (MixedDec)Value % self; }
        friend MixedDec operator^(float Value, MixedDec self) { return (MixedDec)Value ^ self; }
        friend MixedDec operator|(float Value, MixedDec self) { return (MixedDec)Value | self; }
        friend MixedDec operator&(float Value, MixedDec self) { return (MixedDec)Value & self; }

        friend MixedDec operator+(MixedDec self, double Value) { return self + (MixedDec)Value; }
        friend MixedDec operator-(MixedDec self, double Value) { return self - (MixedDec)Value; }
        friend MixedDec operator*(MixedDec self, double Value) { return self * (MixedDec)Value; }
        friend MixedDec operator/(MixedDec self, double Value) { return self / (MixedDec)Value; }
        friend MixedDec operator%(MixedDec self, double Value) { return self % (MixedDec)Value; }
        friend MixedDec operator^(MixedDec self, double Value) { return self ^ (MixedDec)Value; }
        friend MixedDec operator|(MixedDec self, double Value) { return self | (MixedDec)Value; }
        friend MixedDec operator&(MixedDec self, double Value) { return self & (MixedDec)Value; }

        friend MixedDec operator+(double Value, MixedDec self) { return (MixedDec)Value + self; }
        friend MixedDec operator-(double Value, MixedDec self) { return (MixedDec)Value - self; }
        friend MixedDec operator*(double Value, MixedDec self) { return (MixedDec)Value * self; }
        friend MixedDec operator/(double Value, MixedDec self) { return (MixedDec)Value / self; }
        friend MixedDec operator%(double Value, MixedDec self) { return (MixedDec)Value % self; }
        friend MixedDec operator^(double Value, MixedDec self) { return (MixedDec)Value ^ self; }
        friend MixedDec operator|(double Value, MixedDec self) { return (MixedDec)Value | self; }
        friend MixedDec operator&(double Value, MixedDec self) { return (MixedDec)Value & self; }

        friend MixedDec operator+(MixedDec self, ldouble Value) { return self + (MixedDec)Value; }
        friend MixedDec operator-(MixedDec self, ldouble Value) { return self - (MixedDec)Value; }
        friend MixedDec operator*(MixedDec self, ldouble Value) { return self * (MixedDec)Value; }
        friend MixedDec operator/(MixedDec self, ldouble Value) { return self / (MixedDec)Value; }
        friend MixedDec operator%(MixedDec self, ldouble Value) { return self % (MixedDec)Value; }
        friend MixedDec operator^(MixedDec self, ldouble Value) { return self ^ (MixedDec)Value; }
        friend MixedDec operator|(MixedDec self, ldouble Value) { return self | (MixedDec)Value; }
        friend MixedDec operator&(MixedDec self, ldouble Value) { return self & (MixedDec)Value; }

        friend MixedDec operator+(ldouble Value, MixedDec self) { return (MixedDec)Value + self; }
        friend MixedDec operator-(ldouble Value, MixedDec self) { return (MixedDec)Value - self; }
        friend MixedDec operator*(ldouble Value, MixedDec self) { return (MixedDec)Value * self; }
        friend MixedDec operator/(ldouble Value, MixedDec self) { return (MixedDec)Value / self; }
        friend MixedDec operator%(ldouble Value, MixedDec self) { return (MixedDec)Value % self; }
        friend MixedDec operator^(ldouble Value, MixedDec self) { return (MixedDec)Value ^ self; }
        friend MixedDec operator|(ldouble Value, MixedDec self) { return (MixedDec)Value | self; }
        friend MixedDec operator&(ldouble Value, MixedDec self) { return (MixedDec)Value & self; }
    #pragma endregion Other Operations
        
#pragma region MixedDec-To-Integer Operations
    public:
/*        /// <summary>
        /// Addition Operation Between MixedDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& AddOp(MixedDec& self, IntType& value)
        {
            if (value == 0)
                return self;
            if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                self.ConvertToNumRep();
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(self.ExtraRep==RevMaxInt)//Valuei || ValueE Representation
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
                if (self.DecimalHalf == 0)
                    self.IntValue += value;
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue == MixedDec::NegativeZero ? -1 : --self.IntValue;
                    self.IntValue += value;
                    if (self.IntValue == -1)
                        self.IntValue = self.DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                    else if (self.IntValue < 0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = MixedDec::DecimalOverflow - self.DecimalHalf;
                }
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else//(Valuei/ExtraRep) || (ValueE/ExtraRep) Representation
            {
            
            }
#endif
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between MixedDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        static MixedDec& SubOp(MixedDec& self, IntType& value)
        {
            if (value == 0)
                return self;
            if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                self.ConvertToNumRep();
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(self.ExtraRep==RevMaxInt)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)//Normal Representation
            {
                if (self.DecimalHalf == 0)
                    self.IntValue -= value;
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue==MixedDec::NegativeZero ? -1 : --self.IntValue;
                    self.IntValue -= value;
                    if (self.IntValue == -1)
                        self.IntValue = self.DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                    else if (self.IntValue < 0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = MixedDec::DecimalOverflow - self.DecimalHalf;
                }
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }

        PartialMultOp(IntType& Value)
        {
            if (DecimalHalf == 0)
            {
                IntValue *= Value;
            }
            else
            {
                bool SelfIsNegative = IntValue < 0;
                if (SelfIsNegative)
                {
                    if (IntValue == NegativeZero) { IntValue = 0; }
                    else { IntValue *= -1; }
                }
                __int64 SRep = IntValue == 0 ? DecimalHalf : DecimalOverflowX * IntValue + DecimalHalf;
                SRep *= Value;
                if (SRep >= DecimalOverflowX)
                {
                    __int64 OverflowVal = SRep / DecimalOverflowX;
                    SRep -= OverflowVal * DecimalOverflowX;
                    IntValue = (signed int)SelfIsNegative ? OverflowVal * -1 : OverflowVal;
                    DecimalHalf = (signed int)SRep;
                }
                else
                {
                    IntValue = SelfIsNegative?NegativeZero:0;
                    DecimalHalf = (signed int)SRep;
                }
            }
        }

        /// <summary>
        /// Multiplication Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        static MixedDec& MultOp(MixedDec& self, IntType& Value)
        {
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
            if (self == Zero)
                return self;
            if(value==0)
            {
                self.SetAsZero(); return self;
            }
            if(self.ExtraRep==0)
            {
                self.PartialMultOp(Value);
            }
            else if(ExtraRep==NegativeZero)//Value*Pi Representation
            {
                self.PartialMultOp(Value);
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(ExtraRep==RevMaxInt)
            {
                if(Value==ExtraRep)
                    self.ExtraRep = -1;
                else
                    self.PartialMultOp(Value);
            }
            else if(ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
                if(Value==ExtraRep)
                    self.ExtraRep = 0;
                else
                    self.PartialMultOp(Value);
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }

        /// <summary>
        /// Division Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& DivOp(MixedDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            else if (self == Zero)
                return self;
            if (Value < 0)
            {
                if (Value == NegativeZero) { Value = 0; }
                else { Value *= -1; }
                self.SwapNegativeStatus();
            }
            if(self.ExtraRep==0)
            {
                ExtraRep = Value;
            }
            else if(ExtraRep==NegativeZero)//Value*Pi Representation
            {
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
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(ExtraRep==RevMaxInt)
            {
            }
            else if(ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
				ExtraRep *= Value;
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            if (self == Zero) { return JustAboveZero; }//Prevent dividing into nothing
            return self;
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& RemOp(MixedDec& self, IntType& Value)
        {
            if (Value == 0 || self == MixedDec::Zero)
            {
                self.SetAsZero();
                return self;
            }
            if(self.ExtraRep==0)
            {
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
            }
            else if(self.ExtraRep==NegativeZero)//Value*Pi Representation
            {
            
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(self.ExtraRep==RevMaxInt)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
            
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }

        /// <summary>
        /// Addition Operation Between MixedDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& UnsignedAddOp(MixedDec& self, IntType& value)
        {
            if(value==0)
                return self;
            if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                self.ConvertToNumRep();
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(self.ExtraRep==RevMaxInt)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
                if(self.DecimalHalf==0|| self.IntValue > 0)
                    self.IntValue += value;
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue == MixedDec::NegativeZero ? -1 : --self.IntValue;
                    self.IntValue += value;
                    if (self.IntValue == -1)
                        self.IntValue = self.DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                    else if (self.IntValue < 0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = MixedDec::DecimalOverflow - self.DecimalHalf;
                }
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }

        /// <summary>
        /// Subtraction Operation Between MixedDec and Integer value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        static MixedDec& UnsignedSubOp(MixedDec& self, IntType& value)
        {
            if (value == 0)
                return self;
            if(self.ExtraRep==NegativeZero)//Value*Pi Representation
                self.ConvertToNumRep();
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(self.ExtraRep==RevMaxInt)
            {
            }
            else if(self.ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
                self.ConvertToNumRep();
            if(self.ExtraRep==0)
            {
                if (self.DecimalHalf == 0)
                    self.IntValue -= value;
                else if (self.IntValue == NegativeZero)
                    self.IntValue = (signed int)value * -1;
                else if(self.IntValue < 0)
                    self.IntValue -= value;
                else
                {
                    bool WasNegative = self.IntValue < 0;
                    if (WasNegative)
                        self.IntValue = self.IntValue == MixedDec::NegativeZero ? -1 : --self.IntValue;
                    self.IntValue -= value;
                    if (self.IntValue == -1)
                        self.IntValue = self.DecimalHalf == 0 ? 0 : MixedDec::NegativeZero;
                    else if (self.IntValue < 0)
                        ++self.IntValue;
                    //If flips to other side of negative, invert the decimals
                    if ((WasNegative && self.IntValue >= 0) || (WasNegative == 0 && self.IntValue < 0))
                        self.DecimalHalf = MixedDec::DecimalOverflow - self.DecimalHalf;
                }
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }

        /// <summary>
        /// Multiplication Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        static MixedDec& UnsignedMultOp(MixedDec& self, IntType& Value)
        {
            if (self == Zero)
                return self;
            if(value==0)
            {
                self.SetAsZero(); return self;
            }
            if(self.ExtraRep==0)
            {
                self.PartialMultOp(Value);
            }
            else if(ExtraRep==NegativeZero)//Value*Pi Representation
            {
                self.PartialMultOp(Value);
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(ExtraRep==RevMaxInt)
            {
                if(Value==ExtraRep)
                    self.ExtraRep = -1;
                else
                    self.PartialMultOp(Value);
            }
            else if(ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
                if(Value==ExtraRep)
                    self.ExtraRep = 0;
                else
                    self.PartialMultOp(Value);
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }



        /// <summary>
        /// Division Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& UnsignedDivOp(MixedDec& self, IntType& Value)
        {
            if (Value == 0) { throw "Target value can not be divided by zero"; }
            if(self.ExtraRep==0)
            {
                ExtraRep = Value;
            }
            else if(ExtraRep==NegativeZero)//Value*Pi Representation
            {
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
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(ExtraRep==RevMaxInt)
            {
            }
            else if(ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
				ExtraRep *= Value;
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }
        
        /// <summary>
        /// Division Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& UnsignedDivOpV2(MixedDec& self, IntType Value)
        {
            return UnsignedDivOp(self, Value);
        }
        
        /// <summary>
        /// Remainder/Modulus Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec&</returns>
        template<typename IntType>
        static MixedDec& UnsignedRemOp(MixedDec& self, IntType& Value)
        {
            if(self == MixedDec::Zero)
                return self;
            if (Value == 0){ self.SetAsZero(); return self; }
            if(ExtraRep==0)
            {
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
            }
            else if(ExtraRep==NegativeZero)//Value*Pi Representation
            {
            
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else if(ExtraRep==RevMaxInt)
            {
            }
            else if(ExtraRep>0)
#else
            else//(Value/ExtraRep) Representation
#endif
            {
            
            }
#if defined(MixedDec_EnableImaginaryNum) || defined(MixedDec_EnableENum)
            else
            {
            
            }
#endif
            return self;
        }*/
        
    public:
        friend MixedDec operator+(MixedDec self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-(MixedDec self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*(MixedDec self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/(MixedDec self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%(MixedDec self, unsigned char Value){ return UnsignedRemOp(self, Value); }
        
        friend MixedDec operator+=(MixedDec& self, unsigned char Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-=(MixedDec& self, unsigned char Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*=(MixedDec& self, unsigned char Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/=(MixedDec& self, unsigned char Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%=(MixedDec& self, unsigned char Value){ return UnsignedRemOp(self, Value); }

        friend MixedDec operator+(MixedDec self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-(MixedDec self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*(MixedDec self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/(MixedDec self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%(MixedDec self, unsigned short Value){ return UnsignedRemOp(self, Value); }
        
        friend MixedDec operator+=(MixedDec& self, unsigned short Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-=(MixedDec& self, unsigned short Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*=(MixedDec& self, unsigned short Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/=(MixedDec& self, unsigned short Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%=(MixedDec& self, unsigned short Value){ return UnsignedRemOp(self, Value); }

        friend MixedDec operator+(MixedDec self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-(MixedDec self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*(MixedDec self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/(MixedDec self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%(MixedDec self, unsigned int Value){ return UnsignedRemOp(self, Value); }
        
        friend MixedDec operator+=(MixedDec& self, unsigned int Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-=(MixedDec& self, unsigned int Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*=(MixedDec& self, unsigned int Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/=(MixedDec& self, unsigned int Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%=(MixedDec& self, unsigned int Value){ return UnsignedRemOp(self, Value); }

        friend MixedDec operator+(MixedDec self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-(MixedDec self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*(MixedDec self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/(MixedDec self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%(MixedDec self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }
        
        friend MixedDec operator+=(MixedDec& self, unsigned __int64 Value){ return UnsignedAddOp(self, Value); }
        friend MixedDec operator-=(MixedDec& self, unsigned __int64 Value){ return UnsignedSubOp(self, Value); }
        friend MixedDec operator*=(MixedDec& self, unsigned __int64 Value){ return UnsignedMultOp(self, Value); }
        friend MixedDec operator/=(MixedDec& self, unsigned __int64 Value){ return UnsignedDivOp(self, Value); }
        friend MixedDec operator%=(MixedDec& self, unsigned __int64 Value){ return UnsignedRemOp(self, Value); }

        /// <summary>
        /// Addition Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator+(MixedDec self, IntType Value)
        {
            return AddOp(self, Value);
        }

        ///// <summary>
        ///// += Operation Between MixedDec and Integer Value
        ///// </summary>
        ///// <param name="self">The self.</param>
        ///// <param name="Value">The value.</param>
        ///// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator+=(MixedDec& self, IntType Value)
        {
            return AddOp(self, Value);
        }

        template<typename IntType>
        friend MixedDec operator+=(MixedDec* self, IntType Value){ return AddOp(**self, Value); }

        /// <summary>
        /// Subtraction Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator-(MixedDec self, IntType Value)
        {
            return SubOp(self, Value);
        }

        /// <summary>
        /// -= Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator-=(MixedDec& self, IntType Value)
        {
            return SubOp(self, Value);
        }

        template<typename IntType>
        friend MixedDec operator-=(MixedDec* self, IntType Value){ return SubOp(**self, Value); }

        /// <summary>
        /// Multiplication Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator*(MixedDec self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator*=(MixedDec& self, IntType Value)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// *= Operation Between MixedDec and Integer Value (from pointer)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator*=(MixedDec* self, IntType Value){ return MultOp(**self, Value); }

        /// <summary>
        /// Division Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator/(MixedDec self, IntType Value)
        {
            return DivOp(self, Value);
        }

        /// <summary>
        /// /= Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator/=(MixedDec& self, IntType Value)
        {
            return DivOp(self, Value);
        }

        template<typename IntType>
        friend MixedDec operator/=(MixedDec* self, IntType Value){ return DivOp(**self, Value); }
        
        /// <summary>
        /// Modulus Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator%(MixedDec self, IntType Value)
        {
            return RemOp(self, Value);
        }

        /// <summary>
        /// %= Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator%=(MixedDec& self, IntType Value)
        {
            return RemOp(self, Value);
        }

        template<typename IntType>
        friend MixedDec operator%=(MixedDec* self, IntType Value){ return RemOp(**self, Value); }

        /// <summary>
        /// Bitwise XOR Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator^(MixedDec self, IntType Value)
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
        /// Bitwise Or Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator|(MixedDec self, IntType Value)
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
        /// Bitwise And Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator&(MixedDec self, IntType Value)
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
    #pragma endregion MixedDec-To-Integer Operations
    #pragma region Integer-To-MixedDec Operations
        /// <summary>
        /// Addition Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator+(IntType Value, MixedDec self)
        {
            return AddOp(self, Value);
        }

        /// <summary>
        /// Subtraction Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator-(IntType Value, MixedDec self)
        {
            MixedDec Result = Value;
            return SubOp(Result, self);
        }

        /// <summary>
        /// Multiplication Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator*(IntType Value, MixedDec self)
        {
            return MultOp(self, Value);
        }

        /// <summary>
        /// Division Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator/(IntType Value, MixedDec self)
        {
            MixedDec Result = Value;
            return DivOp(Result, self);
        }

        /// <summary>
        /// Remainder/Modulus Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator%(IntType Value, MixedDec self)
        {
            MixedDec Result = Value;
            return RemOp(Result, self);
        }

        /// <summary>
        /// Bitwise XOR Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator^(IntType Value, MixedDec self)
        {
            return (MixedDec)Value ^ self;
        }
        /// <summary>
        /// Bitwise Or Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator|(IntType Value, MixedDec self)
        {
            return (MixedDec)Value | self;
        }
        /// <summary>
        /// Bitwise And Operation Between MixedDec and Integer Value
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The value.</param>
        /// <returns>MixedDec</returns>
        template<typename IntType>
        friend MixedDec operator&(IntType Value, MixedDec self)
        {
            return (MixedDec)Value & self;
        }
    #pragma endregion Integer-To-MixedDec Operations
    
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
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MixedDec(float Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MixedDec(double Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MixedDec(ldouble Value)
        {
            this->SetVal(Value);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MixedDec(bool Value)
        {
            this->SetVal(Value);
        }
    #pragma endregion From Standard types to this type

    #pragma region From this type to Standard types
        /// <summary>
        /// MixedDec to float explicit conversion
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
        /// MixedDec to double explicit conversion
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
        /// MixedDec to long double explicit conversion
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
        /// MixedDec to int explicit conversion
        /// </summary>
        /// <returns>The result of the operator.</returns>
        explicit operator int() { return IntValue; }

        explicit operator bool() { return IntValue == 0 ? false : true; }

        /// <summary>
        /// MixedDec to integer type explicit conversion
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
        /// <returns>MixedDec</returns>
        MixedDec GetValueFromString(std::string Value);

        /// <summary>
        /// Initializes a new instance of the <see cref="MixedDec"/> class from string literal
        /// </summary>
        /// <param name="strVal">The value.</param>
        MixedDec(const char* strVal)
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
        /// Initializes a new instance of the <see cref="MixedDec"/> class.
        /// </summary>
        /// <param name="Value">The value.</param>
        MixedDec(std::string Value)
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
        ///// += MixedDec operation added to std::string
        ///// </summary>
        ///// <param name="targetString">The target string(left side).</param>
        ///// <param name="Value">The right side value</param>
        ///// <returns>string</returns>
        //friend std::string operator+=(std::string targetString, MixedDec self) { return targetString + self.ToString(); }
    #pragma endregion String Commands
    };
    
    #pragma region ValueDefine Source
    MixedDec MixedDec::PI = PIValue();
    MixedDec MixedDec::E = EValue();
    MixedDec MixedDec::PINum = PINumValue();
    MixedDec MixedDec::ENum = ENumValue();
	MixedDec MixedDec::Zero = ZeroValue();
}