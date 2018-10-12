/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;

    // Represent +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka SuperDec_Int32_9Decimal)
    public
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    class
#else
    struct
#endif
    MediumDec : IFormattable, INotifyPropertyChanged
    {
        // Self Less than Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(MediumDec self, MediumDec Value)
        {
            if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            else
            {
                bool SelfIsNegative = self.DecimalStatus < 0;
                bool ValueIsNegative = Value.DecimalStatus < 0;
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }
                if (ValueIsNegative)
                {
                    if (ValueIsWholeN) { Value.DecimalStatus = 0; }
                    else { Value.DecimalStatus *= -1; }
                }
                if (ValueIsNegative && SelfIsNegative == false) { return false; }
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }
                else
                {//Both are either positive or negative
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus > Value.DecimalStatus;
                        }
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus < Value.DecimalStatus;
                        }
                    }
                }
            }
        }

        // Self Less than or equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(MediumDec self, MediumDec Value)
        {
            if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            else
            {
                bool SelfIsNegative = self.DecimalStatus < 0;
                bool ValueIsNegative = Value.DecimalStatus < 0;
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }
                if (ValueIsNegative)
                {
                    if (ValueIsWholeN) { Value.DecimalStatus = 0; }
                    else { Value.DecimalStatus *= -1; }
                }
                if (ValueIsNegative && SelfIsNegative == false) { return false; }
                else if (ValueIsNegative == false && SelfIsNegative) { return true; }
                else
                {//Both are either positive or negative
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue > Value.IntValue)
                        {
                            return true;
                        }
                        else if (self.IntValue == Value.IntValue)
                        {
                            return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus > Value.DecimalStatus;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (self.IntValue < Value.IntValue)
                        {
                            return true;
                        }
                        else if (self.IntValue == Value.IntValue)
                        {
                            return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus < Value.DecimalStatus;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }

        // Self Greater than Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(MediumDec self, MediumDec Value)
        {
            if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            else
            {
                bool SelfIsNegative = self.DecimalStatus < 0;
                bool ValueIsNegative = Value.DecimalStatus < 0;
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }
                if (ValueIsNegative)
                {
                    if (ValueIsWholeN) { Value.DecimalStatus = 0; }
                    else { Value.DecimalStatus *= -1; }
                }
                if (ValueIsNegative && SelfIsNegative == false) { return true; }
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }
                else
                {//Both are either positive or negative
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue < Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus < Value.DecimalStatus;
                        }
                    }
                    else
                    {
                        if (self.IntValue > Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus > Value.DecimalStatus;
                        }
                    }
                }
            }
        }

        // Self Greater than or Equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(MediumDec self, MediumDec Value)
        {
            if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            else
            {
                bool SelfIsNegative = self.DecimalStatus < 0;
                bool ValueIsNegative = Value.DecimalStatus < 0;
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }
                if (ValueIsNegative)
                {
                    if (ValueIsWholeN) { Value.DecimalStatus = 0; }
                    else { Value.DecimalStatus *= -1; }
                }
                if (ValueIsNegative && SelfIsNegative == false) { return true; }
                else if (ValueIsNegative == false && SelfIsNegative) { return false; }
                else
                {//Both are either positive or negative
                    if (SelfIsNegative)
                    {//Larger number = farther down into negative
                        if (self.IntValue < Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus < Value.DecimalStatus;
                        }
                    }
                    else
                    {
                        if (self.IntValue > Value.IntValue)
                        {
                            return true;
                        }
                        else
                        {
                            return self.DecimalStatus > Value.DecimalStatus;
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Equality operator for comparing self to type value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(MediumDec self, MediumDec Value)
        {
            return (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus);
        }

        /// <summary>
        /// Inequality operator
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(MediumDec self, MediumDec Value)
        {
            return (self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus);
        }

        /// <summary>
        /// Self Less than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self < (MediumDec)Value;
            }
            //         if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            //         else
            //         {
            //             bool SelfIsNegative = self.DecimalStatus < 0;
            //             bool ValueIsNegative = Value.DecimalStatus < 0;
            //             bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             bool ValueIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             if (SelfIsNegative)
            //             {
            //                 if(SelfIsWholeN){self.DecimalStatus = 0;}
            //                 else {self.DecimalStatus *= -1;}
            //             }
            //             if (ValueIsNegative)
            //             {
            //                 if (ValueIsWholeN) { Value.DecimalStatus = 0; }
            //                 else { Value.DecimalStatus *= -1; }
            //             }
            //             if (ValueIsNegative && SelfIsNegative == false) { return false; }
            //             else if (ValueIsNegative==false && SelfIsNegative) { return true; }
            //             else
            //             {//Both are either positive or negative
            //                 if (SelfIsNegative)
            //                 {//Larger number = farther down into negative
            //                     if(self.IntValue> Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else
            //                     {
            //                         return self.DecimalStatus > Value.DecimalStatus;
            //                     }
            //                 }
            //                 else
            //                 {
            //                     if(self.IntValue<Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else
            //                     {
            //                         return self.DecimalStatus < Value.DecimalStatus;
            //                     }
            //                 }
            //             }
            //         }
            else
            {
                return self < (MediumDec)Value;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <(dynamic Value, MediumDec self) => self > Value;

        // Self Less than or equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self <= (MediumDec)Value;
            }
            //         if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            //         else
            //         {
            //             bool SelfIsNegative = self.DecimalStatus < 0;
            //             bool ValueIsNegative = Value.DecimalStatus < 0;
            //             bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             bool ValueIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             if (SelfIsNegative)
            //             {
            //                 if (SelfIsWholeN) { self.DecimalStatus = 0; }
            //                 else { self.DecimalStatus *= -1; }
            //             }
            //             if (ValueIsNegative)
            //             {
            //                 if (ValueIsWholeN) { Value.DecimalStatus = 0; }
            //                 else { Value.DecimalStatus *= -1; }
            //             }
            //             if (ValueIsNegative && SelfIsNegative == false) { return false; }
            //             else if (ValueIsNegative == false && SelfIsNegative) { return true; }
            //             else
            //             {//Both are either positive or negative
            //                 if (SelfIsNegative)
            //                 {//Larger number = farther down into negative
            //                     if (self.IntValue > Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else if (self.IntValue == Value.IntValue)
            //                     {
            //                         return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus > Value.DecimalStatus;
            //                     }
            //                     else
            //                     {
            //                         return false;
            //                     }
            //                 }
            //                 else
            //                 {
            //                     if (self.IntValue < Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else if (self.IntValue == Value.IntValue)
            //                     {
            //                         return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus < Value.DecimalStatus;
            //                     }
            //                     else
            //                     {
            //                         return false;
            //                     }
            //                 }
            //             }
            //         }
            else
            {
                return self <= (MediumDec)Value;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <=(dynamic Value, MediumDec self) => self >= Value;

        /// <summary>
        /// Self Greater than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self > (MediumDec)Value;
            }
            //         if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            //         else
            //         {
            //             bool SelfIsNegative = self.DecimalStatus < 0;
            //             bool ValueIsNegative = Value.DecimalStatus < 0;
            //             bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             bool ValueIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //             if (SelfIsNegative)
            //             {
            //                 if (SelfIsWholeN) { self.DecimalStatus = 0; }
            //                 else { self.DecimalStatus *= -1; }
            //             }
            //             if (ValueIsNegative)
            //             {
            //                 if (ValueIsWholeN) { Value.DecimalStatus = 0; }
            //                 else { Value.DecimalStatus *= -1; }
            //             }
            //             if (ValueIsNegative && SelfIsNegative == false) { return true; }
            //             else if (ValueIsNegative == false && SelfIsNegative) { return false; }
            //             else
            //             {//Both are either positive or negative
            //                 if (SelfIsNegative)
            //                 {//Larger number = farther down into negative
            //                     if (self.IntValue < Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else
            //                     {
            //                         return self.DecimalStatus < Value.DecimalStatus;
            //                     }
            //                 }
            //                 else
            //                 {
            //                     if (self.IntValue > Value.IntValue)
            //                     {
            //                         return true;
            //                     }
            //                     else
            //                     {
            //                         return self.DecimalStatus > Value.DecimalStatus;
            //                     }
            //                 }
            //             }
            //         }
            else
            {
                return self > (MediumDec)Value;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >(dynamic Value, MediumDec self) => self < Value;

        /// <summary>
        /// Self Greater than or Equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                //return (String)Value == (String)self;
                return self >= (MediumDec)Value;
            }
            //if (self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            //else
            //{
            //    bool SelfIsNegative = self.DecimalStatus < 0;
            //    bool ValueIsNegative = Value.DecimalStatus < 0;
            //    bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //    bool ValueIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            //    if (SelfIsNegative)
            //    {
            //        if (SelfIsWholeN) { self.DecimalStatus = 0; }
            //        else { self.DecimalStatus *= -1; }
            //    }
            //    if (ValueIsNegative)
            //    {
            //        if (ValueIsWholeN) { Value.DecimalStatus = 0; }
            //        else { Value.DecimalStatus *= -1; }
            //    }
            //    if (ValueIsNegative && SelfIsNegative == false) { return true; }
            //    else if (ValueIsNegative == false && SelfIsNegative) { return false; }
            //    else
            //    {//Both are either positive or negative
            //        if (SelfIsNegative)
            //        {//Larger number = farther down into negative
            //            if (self.IntValue < Value.IntValue)
            //            {
            //                return true;
            //            }
            //            else
            //            {
            //                return self.DecimalStatus < Value.DecimalStatus;
            //            }
            //        }
            //        else
            //        {
            //            if (self.IntValue > Value.IntValue)
            //            {
            //                return true;
            //            }
            //            else
            //            {
            //                return self.DecimalStatus > Value.DecimalStatus;
            //            }
            //        }
            //    }
            //}
            else
            {
                return self >= (MediumDec)Value;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >=(dynamic Value, MediumDec self) => self <= Value;

        /// <summary>
        /// Equality operator for comparing self with other Variable Types
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self == (MediumDec)Value;
            }
            else
            {
                return self == (MediumDec)Value;
            }
        }

        /// <summary>
        /// Equality operator
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator ==(dynamic Value, MediumDec self) => self == Value;

        // Inequality operator for comparing self to multiple value types
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(MediumDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self != (MediumDec)Value;
            }
            else
            {
                return self != (MediumDec)Value;
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator !=(dynamic Value, MediumDec self) => self != Value;

        /// <summary>
        /// Implements the operator %.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="Value">The Value.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static MediumDec operator %(MediumDec self, MediumDec Value)
        {
			if (Value.IntValue == 0 && Value.DecimalStatus == 0)
			{
				return MediumDec.Zero;//Return zero instead of N/A
			}
			if (self.DecimalStatus == 0 || self.DecimalStatus == NegativeWholeNumber)
			{
				if (Value.DecimalStatus == NegativeWholeNumber)
				{
					self = ApplyNegModulus(self, Value.IntValue);
					return self;
				}
				else
				{
					self %= Value.IntValue;
					return self;
				}
			}
			bool SelfIsNegative = self.DecimalStatus < 0;
			bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
			if (SelfIsNegative)
			{
				if (SelfIsWholeN) { self.DecimalStatus = 0; }
				else { self.DecimalStatus *= -1; }
			}
			bool ValueIsNegative = Value.DecimalStatus < 0;
			bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
			if (ValueIsNegative)
			{
				if (ValueIsWholeN) { Value.DecimalStatus = 0; }
				else { Value.DecimalStatus *= -1; }
			}
			long SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			long ValueRep = ((long)Value.IntValue * DecimalOverflow) + Value.DecimalStatus;
			SelfRep /= ValueRep;
			long IntResult = SelfRep;
			SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			SelfRep -= IntResult * ValueRep;
			long IntHalf = SelfRep / DecimalOverflow;
			SelfRep -= IntHalf * (long)DecimalOverflow;
			self.IntValue = (uint)IntHalf;
			self.DecimalStatus = (int)SelfRep;
			if (SelfIsNegative)
			{
				self = Value - self;
				if (ValueIsNegative == false)
				{
					SelfIsNegative = false;
				}
			}
			else
			{
				if (ValueIsNegative)
				{
					self = Value - self;
				}
			}
			if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
			return self;
		}

        /// <summary>
        /// Implements the operator +.(Self+TargetValue)
        /// </summary>
        /// <param name="self">Self.</param>
        /// <param name="y">The TargetValue.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static MediumDec operator +(MediumDec self, MediumDec y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            if (SelfIsNegative)
            {
                if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            if (ValueIsNegative)
            {
                if (y.DecimalStatus == NegativeWholeNumber) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
            bool PerformDecimalHalf = true;
            if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
            {
                self.IntValue += y.IntValue;
                self.DecimalStatus += y.DecimalStatus;
                if (self.DecimalStatus >= DecimalOverflow)
                {
                    self.DecimalStatus -= DecimalOverflow;
                    ++self.IntValue;
                }
                PerformDecimalHalf = false;
            }
            else if (SelfIsNegative)//-X + Y
            {
                if (self.IntValue == y.IntValue)
                {
                    self.IntValue = 0;
                }
                else if (self.IntValue > y.IntValue)
                {
                    self.IntValue -= y.IntValue;
                }
                else
                {
                    self.IntValue = (uint)(y.IntValue - self.IntValue);
                    SelfIsNegative = false;
                }
            }
            else// X - Y
            {
                if (self.IntValue == y.IntValue)
                {
                    self.IntValue = 0;
                }
                else if (self.IntValue > y.IntValue)
                {
                    self.IntValue -= y.IntValue;
                }
                else
                {
                    self.IntValue = (uint)(y.IntValue - self.IntValue);
                    SelfIsNegative = true;
                }
            }
            if (PerformDecimalHalf)
            {
                if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
                {
                    self.DecimalStatus += y.DecimalStatus;
                    if (self.DecimalStatus >= DecimalOverflow)
                    {
                        self.DecimalStatus -= DecimalOverflow;
                        ++self.IntValue;
                    }
                }
                else if (SelfIsNegative)
                {
                    if (self.DecimalStatus == y.DecimalStatus)
                    {
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else if (self.DecimalStatus > y.DecimalStatus)
                    {
                        self.DecimalStatus -= y.DecimalStatus;
                    }
                    else
                    {
                        self.DecimalStatus = y.DecimalStatus - self.DecimalStatus;
                        SelfIsNegative = false;
                    }
                }
                else
                {
                    if (self.DecimalStatus == y.DecimalStatus)
                    {
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else if (self.DecimalStatus > y.DecimalStatus)
                    {
                        self.DecimalStatus -= y.DecimalStatus;
                    }
                    else
                    {
                        self.DecimalStatus = y.DecimalStatus - self.DecimalStatus;
                        SelfIsNegative = true;
                    }
                }
            }
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            if (self.DecimalStatus > 0 && SelfIsNegative)
            {
                self.DecimalStatus *= -1;
            }
            return self;
        }

        /// <summary>
        /// Implements the operator -.(Self-TargetValue)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="y">The TargetValue.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static MediumDec operator -(MediumDec self, MediumDec y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            if (SelfIsNegative)
            {
                if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            if (ValueIsNegative)
            {
                if (y.DecimalStatus == NegativeWholeNumber) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
            if (ValueIsNegative) { ValueIsNegative = false; }
            bool PerformDecimalHalf = true;
            if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
            {
                self.IntValue += y.IntValue;
                self.DecimalStatus += y.DecimalStatus;
                if (self.DecimalStatus >= DecimalOverflow)
                {
                    self.DecimalStatus -= DecimalOverflow;
                    ++self.IntValue;
                }
                PerformDecimalHalf = false;
            }
            else if (SelfIsNegative)//-X + Y
            {
                if (self.IntValue == y.IntValue)
                {
                    self.IntValue = 0;
                }
                else if (self.IntValue > y.IntValue)
                {
                    self.IntValue -= y.IntValue;
                }
                else
                {
                    self.IntValue = (uint)(y.IntValue - self.IntValue);
                    SelfIsNegative = false;
                }
            }
            else// X - Y
            {
                if (self.IntValue == y.IntValue)
                {
                    self.IntValue = 0;
                }
                else if (self.IntValue > y.IntValue)
                {
                    self.IntValue -= y.IntValue;
                }
                else
                {
                    self.IntValue = (uint)(y.IntValue - self.IntValue);
                    SelfIsNegative = true;
                }
            }
            if (PerformDecimalHalf)
            {
                if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
                {
                    self.DecimalStatus += y.DecimalStatus;
                    if (self.DecimalStatus >= DecimalOverflow)
                    {
                        self.DecimalStatus -= DecimalOverflow;
                        ++self.IntValue;
                    }
                }
                else if (SelfIsNegative)
                {
                    if (self.DecimalStatus == y.DecimalStatus)
                    {
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else if (self.DecimalStatus > y.DecimalStatus)
                    {
                        self.DecimalStatus -= y.DecimalStatus;
                    }
                    else
                    {
                        self.DecimalStatus = y.DecimalStatus - self.DecimalStatus;
                        SelfIsNegative = false;
                    }
                }
                else
                {
                    if (self.DecimalStatus == y.DecimalStatus)
                    {
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else if (self.DecimalStatus > y.DecimalStatus)
                    {
                        self.DecimalStatus -= y.DecimalStatus;
                    }
                    else
                    {
                        self.DecimalStatus = y.DecimalStatus - self.DecimalStatus;
                        SelfIsNegative = true;
                    }
                }
            }
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            if (self.DecimalStatus > 0 && SelfIsNegative)
            {
                self.DecimalStatus *= -1;
            }
            return self;
        }

		/// <summary>
		/// Applies the Modulus with negative value
		/// </summary>
		/// <param name="self">The self.</param>
		/// <param name="Value">The value.</param>
		/// <returns></returns>
		public static MediumDec ApplyNegModulus(MediumDec self, uint Value)
		{
			//bool ValueIsNegative = Value < 0;
			if (self.DecimalStatus == 0)
			{
				self.IntValue %= Value;
				self.DecimalStatus = NegativeWholeNumber;
				self.IntValue = (uint)(Value - self.IntValue);
			}
			else if (self.DecimalStatus == NegativeWholeNumber)
			{
				self.IntValue %= Value;
				self.IntValue = (uint)(Value - self.IntValue);
			}
			else
			{
				self %= (MediumDec)Value;
			}
			return self;
		}

		/// <summary>
		/// </summary>
		/// <param name="self"></param>
		/// <param name="Value"></param>
		/// <returns></returns>
		public static MediumDec operator %(MediumDec self, dynamic Value)
        {
			if (self.DecimalStatus == 0)
			{
				self.IntValue %= Value;
				if (Value < 0)
				{
					self.DecimalStatus = NegativeWholeNumber;
					self.IntValue = (uint)(Value - (ValueType)self.IntValue);
				}
			}
			else if (self.DecimalStatus == NegativeWholeNumber)
			{
				self.IntValue %= Value;
				self.IntValue = (uint)(Value - (ValueType)self.IntValue);
				if (Value > 0)
				{
					self.DecimalStatus = 0;
				}
			}
			else
			{
				self %= (MediumDec)Value;
			}
			return self;
		}

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator +(MediumDec self, dynamic y)
        {
            TypeCode typeCode = Type.GetTypeCode(y.GetType());
            int typeCodeValue = (int)typeCode;
            if (typeCodeValue >= 4 && typeCodeValue <= 12)//Integer based Value types
            {
                bool SelfIsNegative = self.DecimalStatus < 0;
                bool ValueIsNegative = y < 0;
                if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
                {
                    self.IntValue += (uint)y;
                }
                else if (SelfIsNegative)//-X + Y
                {
                    if (self.IntValue == y)
                    {
                        self.IntValue = 0;
                    }
                    else if (self.IntValue > y)
                    {
                        self.IntValue -= (uint)y;
                    }
                    else
                    {
                        self.IntValue = ((uint)y - self.IntValue);
                        SelfIsNegative = false;
                    }
                }
                else// X - Y
                {
                    if (self.IntValue == y)
                    {
                        self.IntValue = 0;
                    }
                    else if (self.IntValue > y)
                    {
                        self.IntValue -= (uint)y;
                    }
                    else
                    {
                        self.IntValue = ((uint)y - self.IntValue);
                        SelfIsNegative = true;
                    }
                }
                if (self.DecimalStatus > 0 && SelfIsNegative)
                {
                    self.DecimalStatus *= -1;
                }
				else if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
			}
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self += (MediumDec)y;
            //}
            else
            {
                return self += (MediumDec)y;
            }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator -(MediumDec self, dynamic y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            TypeCode typeCode = Type.GetTypeCode(y.GetType());
            int typeCodeValue = (int)typeCode;
            if (typeCodeValue >= 5 && typeCodeValue <= 12)//Integer based Value types
            {
				if (typeCodeValue % 2 == 0)//Unsigned Integers
				{
					if (SelfIsNegative)//(-X) - Y
					{
						self.IntValue += (uint)y;
					}
					else//X - Y
					{
						if (self.IntValue == y)
						{
							self.IntValue = 0;
						}
						else if (y > self.IntValue)
						{
							self.IntValue = (uint)y - self.IntValue;
							SelfIsNegative = true;
						}
						else
						{
							self.IntValue -= (uint)y;
						}
					}
				}
				else
				{
					bool ValueIsNegative = y < 0;
					if (SelfIsNegative)
					{
						if (ValueIsNegative == false)//(-X) - (Y)
						{
							self.IntValue += (uint)y;
						}
						else//(-X) - (-Y)
						{
							if (self.IntValue == y)
							{
								self.IntValue = 0;
							}
							else if (y > self.IntValue)
							{
								self.IntValue = (uint)y - self.IntValue;
								SelfIsNegative = false;
							}
							else
							{
								self.IntValue -= (uint)(y * -1);
							}
						}
					}
					else
					{
						if (ValueIsNegative)//X - (-Y)
						{
							self.IntValue += (uint)(y * -1);
						}
						else//X - (Y)
						{
							if (self.IntValue == y)
							{
								self.IntValue = 0;
							}
							else if (y > self.IntValue)
							{
								self.IntValue = (uint)y - self.IntValue;
								SelfIsNegative = true;
							}
							else
							{
								self.IntValue -= (uint)y;
							}
						}
					}
				}
				if (self.DecimalStatus > 0 && SelfIsNegative)
				{
					self.DecimalStatus *= -1;
				}
				else if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
			}
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self -= (MediumDec)y;
            //}
            else
            {
                return self -= (MediumDec)y;
            }
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator *(MediumDec self, dynamic y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            TypeCode typeCode = Type.GetTypeCode(y.GetType());
            int typeCodeValue = (int)typeCode;
            if (typeCodeValue >= 4 && typeCodeValue <= 12)//Integer based Value types
            {
                if (self.DecimalStatus == 0)
                {
                    if (y < 0)
                    {
                        self.IntValue *= (y * -1);
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else
                    {
                        self.IntValue *= y;
                    }
                }
                else if (self.DecimalStatus == NegativeWholeNumber)
                {
                    if (y < 0)
                    {
                        self.IntValue *= (y * -1);
                        self.DecimalStatus = 0;
                    }
                    else
                    {
                        self.IntValue *= y;
                    }
                }
                else
                {
                    if (SelfIsNegative)
                    {
                        self.DecimalStatus *= -1;
                    }
                    self.IntValue *= y;
                    long TempDec = (long)self.DecimalStatus;
                    TempDec *= y;
                    if (TempDec >= DecimalOverflow)
                    {
                        long OverflowVal = TempDec / DecimalOverflow;
                        TempDec -= OverflowVal * DecimalOverflow;
                        self.IntValue += (uint)OverflowVal;
                    }
                    if (TempDec == 0) { self.DecimalStatus = 0; }
                    else
                    {
                        if (SelfIsNegative) { TempDec *= -1; }
                        self.DecimalStatus = (int) TempDec;
                    }
                }
            }
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self *= (MediumDec)y;
            //}
            else
            {
                return self *= (MediumDec)y;
            }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator /(MediumDec self, dynamic y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            TypeCode typeCode = Type.GetTypeCode(y.GetType());
            int typeCodeValue = (int)typeCode;
            if (typeCodeValue >= 4 && typeCodeValue <= 12)//Integer based Value types
            {
                if (y < 0)
                {
                    if (SelfIsNegative) { SelfIsNegative = false; }
                    else { SelfIsNegative = true; }
                    if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
                    else if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
                    y *= -1;
                }
                if (self.DecimalStatus == 0 || self.DecimalStatus == NegativeWholeNumber)//Only need to deal with Integer half of value
                {
                    long ValueRep = (long)self.IntValue * DecimalOverflow;
                    ValueRep /= y;
                    long WholeHalf = ValueRep / DecimalOverflow;
                    self.IntValue = (uint)WholeHalf;
                    ValueRep -= WholeHalf;
                    self.DecimalStatus = (int) WholeHalf;
                }
                else
                {
                    return self /= (MediumDec)y;
                }
            }
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self /= (MediumDec)y;
            //}
            else
            {
                return self /= (MediumDec)y;
            }
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            return self;
        }

        //Right side applications
        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static MediumDec operator -(dynamic y, MediumDec self)
        {
            MediumDec YAsSuperDec = (MediumDec)y;
            YAsSuperDec -= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static MediumDec operator +(dynamic y, MediumDec self)
        {
            MediumDec YAsSuperDec = (MediumDec)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static MediumDec operator *(dynamic y, MediumDec self)
        {
            MediumDec YAsSuperDec = (MediumDec)y;
            YAsSuperDec *= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static MediumDec operator /(dynamic y, MediumDec self)
        {
            MediumDec YAsSuperDec = (MediumDec)y;
            YAsSuperDec /= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static MediumDec operator -(MediumDec Value)
        {//Place DecBoolStatus>1 checks above in V2 of type
            if (Value.DecimalStatus == NegativeWholeNumber)
            {
                Value.DecimalStatus = 0;
            }
            else
            {
                Value.DecimalStatus *= -1;
            }
            return Value;
        }
    }
}
