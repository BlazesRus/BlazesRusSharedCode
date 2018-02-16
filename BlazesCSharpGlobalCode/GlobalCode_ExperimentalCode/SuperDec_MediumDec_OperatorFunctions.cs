﻿/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka (Aka SuperDec_Int32_9Decimal))
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
    MediumDec : INotifyPropertyChanged, IComparable<MediumDec>, IEquatable<MediumDec>, IFormattable//,IConvertible
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
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator %(MediumDec self, MediumDec y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            if (SelfIsNegative)
            {
                if (SelfIsWholeN) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
            if (ValueIsNegative)
            {
                if (ValueIsWholeN) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
			
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
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
            if((SelfIsNegative&& ValueIsNegative)||(SelfIsNegative==false&& ValueIsNegative==false))
            {
                self.IntValue += y.IntValue;
                self.DecimalStatus += y.DecimalStatus;
                if(self.DecimalStatus>= DecimalOverflow)
                {
                    self.DecimalStatus -= DecimalOverflow;
                    ++self.IntValue;
                }
                PerformDecimalHalf = false;
            }
            else if(SelfIsNegative)//-X + Y
            {
                if(self.IntValue== y.IntValue)
                {
                    self.IntValue = 0;
                }
                else if(self.IntValue> y.IntValue)
                {
                    self.IntValue -= y.IntValue;
                }
                else
                {
                    self.IntValue = (ushort)(y.IntValue - self.IntValue);
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
                    self.IntValue = (ushort)(y.IntValue - self.IntValue);
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
            if(self.DecimalStatus>0&& SelfIsNegative)
            {
                self.DecimalStatus *= -1;
            }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
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
                    self.IntValue = (ushort)(y.IntValue - self.IntValue);
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
                    self.IntValue = (ushort)(y.IntValue - self.IntValue);
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
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator *(MediumDec self, MediumDec y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            if (SelfIsNegative)
            {
                if (SelfIsWholeN) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
            if (ValueIsNegative)
            {
                if (ValueIsWholeN) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }

            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator /(MediumDec self, MediumDec y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
            if (SelfIsNegative)
            {
                if (SelfIsWholeN) { self.DecimalStatus = 0; }
                else { self.DecimalStatus *= -1; }
            }
            bool ValueIsNegative = y.DecimalStatus < 0;
            bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
            if (ValueIsNegative)
            {
                if (ValueIsWholeN) { y.DecimalStatus = 0; }
                else { y.DecimalStatus *= -1; }
            }
			
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator %(MediumDec self, dynamic y)
        {
            bool SelfIsNegative = self.DecimalStatus < 0;
            TypeCode typeCode = Type.GetTypeCode(y.GetType());
            int typeCodeValue = (int)typeCode;
            if (typeCodeValue >= 4 && typeCodeValue <= 12)//Integer based Value types
            {
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }

            }
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self %= (MediumDec)y;
            //}
            else
            {
                return self %= (MediumDec)y;
            }
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
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
                    self.IntValue += y;
                    self.DecimalStatus += y.DecimalStatus;
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
                        self.IntValue = (ushort)(y.IntValue - self.IntValue);
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
                        self.IntValue = (ushort)(y.IntValue - self.IntValue);
                        SelfIsNegative = true;
                    }
                }
                if (self.DecimalStatus > 0 && SelfIsNegative)
                {
                    self.DecimalStatus *= -1;
                }
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
            if (typeCodeValue >= 4 && typeCodeValue <= 12)//Integer based Value types
            {
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
                }
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
                bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                if (SelfIsNegative)
                {
                    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                    else { self.DecimalStatus *= -1; }
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
            if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
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
                //bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
                //if (SelfIsNegative)
                //{
                //    if (SelfIsWholeN) { self.DecimalStatus = 0; }
                //    else { self.DecimalStatus *= -1; }
                //}
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
                    self.IntValue = (ushort)WholeHalf;
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
        {
			if(Value.DecimalStatus == NegativeWholeNumber)
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