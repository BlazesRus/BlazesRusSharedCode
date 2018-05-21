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
        /// <param name="y">The y.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static MediumDec operator %(MediumDec self, MediumDec y)
        {
            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
                return MediumDec.Zero;//Return zero instead of N/A
            }
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

            long SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
            long ValueRep = ((long)y.IntValue * DecimalOverflow) + y.DecimalStatus;
            SelfRep /= ValueRep;
            long IntResult = SelfRep;
            SelfRep = ((long)self.IntValue * DecimalOverflow) + self.DecimalStatus;
            SelfRep -= IntResult * ValueRep;
            long IntHalf = SelfRep / DecimalOverflow;
            SelfRep -= IntHalf * (long)DecimalOverflow;
            self.IntValue = (ushort)IntHalf;
            self.DecimalStatus = (int)SelfRep;
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
        public static MediumDec operator %(MediumDec self, dynamic y)
        {
#if (MediumDec_UseLegacyStorage)
            if (y is double || y is float || y is decimal)
            {
                if (y == 0.0)
                {
                    self.intValue = 0;
                    self.DecimalStatus = 0;
                    self.DecBoolStatus = 0;
                }
                else
                {
                    if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
                    ushort WholeHalf = (ushort)y;
                    //Use x Int Operation instead if y has no decimal places
                    if (WholeHalf == y)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            //Use normal simple (int value) * (int value) if not dealing with any decimals
                            self.intValue %= WholeHalf;
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            SelfAsInt %= WholeHalf;
                            self.intValue = (ushort)(SelfAsInt / 1000);
                            SelfAsInt -= (uint)(self.intValue * 10000);
                            self.DecimalStatus = (ushort)SelfAsInt;
                        }
                    }
                    else
                    {
                        y -= WholeHalf;
                        ushort Decimalhalf;
                        if (y == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (y == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(y);
                        }
                        ulong SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        ulong YAsInt = WholeHalf;
                        YAsInt *= 10000;
                        YAsInt += Decimalhalf;
                        SelfAsInt %= YAsInt;
                        SelfAsInt /= 10000;
                        ulong TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage = self.intValue;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
            else if (y is string)
            {
                self %= (MediumDec)y;
            }
            else
            {
                if (y == 0)
                {
                    self.intValue = 0;
                    self.DecimalStatus = 0;
                    self.DecBoolStatus = 0;
                }
                else
                {
                    if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
                    if (self.DecimalStatus == 0)
                    {//Use normal simple (int value) * (int value) if not dealing with any decimals
                        self.intValue %= (ushort)y;
                    }
                    else
                    {
                        uint SelfAsInt = self.DecimalStatus;
                        SelfAsInt += (uint)(self.intValue * 10000);
                        SelfAsInt %= y;
                        uint TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
            return self;
#else
            return self %= (MediumDec)y;
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator +(MediumDec self, dynamic y)
        {
#if (MediumDec_UseLegacyStorage)
            if (y is double || y is MediumDec || y is decimal)
            {
                bool IsYNegative = (y < 0) ? true : false;
                y = Math.Abs(y);
                ushort WholeHalfOfY = (ushort)Math.Floor(y);
                y -= WholeHalfOfY;
                if (WholeHalfOfY == 0) { }
                else if (self.DecBoolStatus == 1 && IsYNegative)
                {// -X - Y (ex. -8 + -6)
                    self.intValue = (ushort)(self.intValue + WholeHalfOfY);
                }
                else if (self.DecBoolStatus == 0 && IsYNegative == false)
                {
                    //X + Y (ex. 8 + 6)
                    self.intValue = (ushort)(self.intValue + WholeHalfOfY);
                }
                else
                {
                    // -X + Y
                    if (self.DecBoolStatus == 1)
                    {   //ex. -8 + 9
                        if (y > self.intValue)
                        {
                            self.intValue = (ushort)(WholeHalfOfY - self.intValue);
                            self.DecBoolStatus = 0;
                        }
                        else
                        {//ex. -8 +  4
                            self.intValue = (ushort)(self.intValue - WholeHalfOfY);
                        }
                    }// X-Y
                    else
                    {
                        if (self.intValue > WholeHalfOfY)
                        {//ex. 9 + -6
                            self.intValue = (ushort)(self.intValue - WholeHalfOfY);
                        }
                        else
                        {//ex. 9 + -10
                            self.intValue = (ushort)(WholeHalfOfY - self.intValue);
                            self.DecBoolStatus = 1;
                        }
                    }
                }
                //Decimal Calculation Section
                if (self.DecBoolStatus != 0 || y != 0)
                {
                    ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
                    // ?.XXXXXX + ?.YYYYYY
                    if (self.DecBoolStatus == 0 && IsYNegative == false)
                    {
                        //Potential Overflow check
                        ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
                        if (DecimalStatusTemp > 9999)
                        {
                            DecimalStatusTemp -= 10000;
                            self.intValue += 1;
                        }
                        self.DecimalStatus = DecimalStatusTemp;
                    }
                    // -?.XXXXXX - ?.YYYYYY
                    else if (self.DecBoolStatus == 1 && IsYNegative == true)
                    {
                        //Potential Overflow check
                        ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
                        if (DecimalStatusTemp > 9999)
                        {
                            DecimalStatusTemp -= 10000;
                            self.intValue += 1;
                        }
                        self.DecimalStatus = DecimalStatusTemp;
                    }
                    else
                    {
                        if (IsYNegative)
                        {
                            // ex. 0.6 + -0.5
                            if (self.DecimalStatus >= SecondDec)
                            {
                                self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
                            }// ex. 0.6 + -.7
                            else
                            {
                                self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
                                if (self.intValue == 0)
                                {
                                    self.DecBoolStatus = 1;
                                }
                                else
                                {
                                    self.intValue -= 1;
                                }
                            }
                        }
                        else
                        {
                            if (self.DecimalStatus >= SecondDec)
                            {
                                self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
                            }// ex. -1.6 + 0.7
                            else
                            {
                                self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
                                if (self.intValue == 0)
                                {
                                    self.DecBoolStatus = 0;
                                }
                                else
                                {
                                    self.intValue -= 1;
                                }
                            }
                        }
                    }
                }
            }
            else if (y is string)
            {
                self += (MediumDec)y;
            }
            else
            {
                if (self.DecBoolStatus == 1 && y < 0)
                {// -X - Y (ex. -8 + -6)
                    self.intValue = (ushort)(self.intValue + (ushort)Math.Abs(y));
                }
                else if (self.DecBoolStatus == 0 && y >= 0)
                {
                    //X + Y (ex. 8 + 6)
                    self.intValue = (ushort)(self.intValue + y);
                }
                else
                {
                    // -X + Y
                    if (self.DecBoolStatus == 1)
                    {   //ex. -8 + 9
                        if (y > self.intValue)
                        {
                            self.intValue = (ushort)(y - self.intValue);
                            self.DecBoolStatus = 0;
                        }
                        else
                        {//ex. -8 +  4
                            self.intValue = (ushort)(self.intValue - y);
                        }
                    }// X-Y
                    else
                    {
                        ushort TempY = Math.Abs(y);
                        if (self.intValue > TempY)
                        {//ex. 9 + -6
                            self.intValue = (ushort)(self.intValue - TempY);
                        }
                        else
                        {//ex. 9 + -10
                            self.intValue = (ushort)(TempY - self.intValue);
                            self.DecBoolStatus = 1;
                        }
                    }
                }
            }
            //Fix potential negative zero
            if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
#else
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
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator -(MediumDec self, dynamic y)
        {
#if (MediumDec_UseLegacyStorage)
            if (y is double || y is MediumDec || y is decimal)
            {
                bool IsYNegative = (y < 0.0) ? true : false;
                y = Math.Abs(y);
                ushort WholeHalfOfY = (ushort)(Math.Floor(y));
                y -= WholeHalfOfY;
                if (WholeHalfOfY == 0) { }
                //ex. -9 - 9
                else if (self.DecBoolStatus == 1 && IsYNegative == false)
                {// -X - Y
                    self.intValue = (ushort)(self.intValue + WholeHalfOfY);
                }//ex. 9 - (-1)
                else if (self.DecBoolStatus == 0 && IsYNegative)
                {
                    //X - (-Y)
                    self.intValue = (ushort)(self.intValue + WholeHalfOfY);
                }
                else
                {
                    // X - (Y)
                    if (self.DecBoolStatus == 0)
                    {
                        // ex. 8 - 9
                        if (WholeHalfOfY > self.intValue)
                        {
                            self.intValue = (ushort)(WholeHalfOfY - self.intValue);
                            self.DecBoolStatus = 1;
                        } //ex. 8 - 7
                        else
                        {
                            self.intValue = (ushort)(self.intValue - WholeHalfOfY);
                        }
                    }// -X - (Y)
                    else
                    {
                        // ex. -8 - (-9)
                        if (self.intValue > WholeHalfOfY)
                        {
                            self.intValue = (ushort)(WholeHalfOfY - self.intValue);
                            self.DecBoolStatus = 0;
                        }
                        else
                        {//ex. -8 - (-5)
                            self.intValue = (ushort)(self.intValue - WholeHalfOfY);
                        }
                    }
                }
                //Decimal Calculation Section
                ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
                if (self.DecimalStatus != 0 || SecondDec != 0)
                {
                    // ex. -0.5 - 0.6
                    if (self.DecBoolStatus == 1 && IsYNegative == false)
                    {
                        //Potential Overflow check
                        ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
                        if (DecimalStatusTemp > 9999)
                        {
                            DecimalStatusTemp -= 10000;
                            self.intValue += 1;
                        }
                        self.DecimalStatus = DecimalStatusTemp;
                    }// ex. 0.5 - (-0.6)
                    else if (self.DecBoolStatus == 0 && IsYNegative)
                    {
                        //Potential Overflow check
                        ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
                        if (DecimalStatusTemp > 9999)
                        {
                            DecimalStatusTemp -= 10000;
                            self.intValue += 1;
                        }
                        self.DecimalStatus = DecimalStatusTemp;
                    }
                    else
                    {
                        if (IsYNegative)
                        {// ex. -0.7 - (-0.6)
                            if (self.DecimalStatus >= SecondDec)
                            {
                                self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
                            }
                            else
                            {
                                self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
                                if (self.intValue == 0)
                                {
                                    self.DecBoolStatus = 0;
                                }
                                else
                                {
                                    self.intValue -= 1;
                                }
                            }
                        }
                        else
                        { //ex  0.6 - 0.5
                            if (self.DecimalStatus >= SecondDec)
                            {
                                self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
                            }
                            else
                            {
                                self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
                                if (self.intValue == 0)
                                {
                                    self.DecBoolStatus = 1;
                                }
                                else
                                {
                                    self.intValue -= 1;
                                }
                            }
                        }
                    }
                }
            }
            else if (y is string)
            {
                self -= (MediumDec)y;
            }
            else
            {
                //ex. -9 - 9
                if (self.DecBoolStatus == 1 && y >= 0)
                {// -X - Y
                    self.intValue = (ushort)(self.intValue + y);
                }//ex. 9 - (-1)
                else if (self.DecBoolStatus == 0 && y < 0)
                {
                    //X - (-Y)
                    self.intValue = (ushort)(self.intValue + Math.Abs(y));
                }
                else
                {
                    // X - (Y)
                    if (self.DecBoolStatus == 0)
                    {
                        // ex. 8 - 9
                        if (y > self.intValue)
                        {
                            self.intValue = (ushort)(y - self.intValue);
                            self.DecBoolStatus = 1;
                        } //ex. 8 - 7
                        else
                        {
                            self.intValue = (ushort)(self.intValue - y);
                        }
                    }// -X - (Y)
                    else
                    {
                        ushort TempY = Math.Abs(y);
                        // ex. -8 - (-9)
                        if (self.intValue > TempY)
                        {
                            self.intValue = (ushort)(TempY - self.intValue);
                            self.DecBoolStatus = 0;
                        }
                        else
                        {//ex. -8 - (-5)
                            self.intValue = (ushort)(self.intValue - TempY);
                        }
                    }
                }
            }
            //Fix potential negative zero
            if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
#else
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
#if (MediumDec_ReducedSize)
#else

#endif
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
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator *(MediumDec self, dynamic y)
        {
#if (MediumDec_UseLegacyStorage)
            if (y is double || y is MediumDec || y is decimal)
            {
                if (y == 0.0)
                {
                    self.intValue = 0;
                    self.DecimalStatus = 0;
                    self.DecBoolStatus = 0;
                }
                else
                {
                    if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
                    ushort WholeHalf = (ushort)Math.Floor(y);
                    //Use x Int Operation instead if y has no decimal places
                    if (WholeHalf == y)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            //Use normal simple (int value) * (int value) if not dealing with any decimals
                            self.intValue *= WholeHalf;
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            SelfAsInt *= WholeHalf;
                            self.intValue = (ushort)(SelfAsInt / 1000);
                            SelfAsInt -= (uint)(self.intValue * 10000);
                            self.DecimalStatus = (ushort)SelfAsInt;
                        }
                    }
                    else
                    {
                        y -= WholeHalf;
                        ushort Decimalhalf;
                        if (y == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (y == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(y);
                        }
                        ulong SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        uint YAsInt = WholeHalf;
                        YAsInt *= 10000;
                        YAsInt += Decimalhalf;
                        SelfAsInt *= YAsInt;
                        SelfAsInt /= 10000;
                        ulong TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage = self.intValue;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
            else if (y is string)
            {
                self *= (MediumDec)y;
            }
            else
            {
                if (y == 0)
                {
                    self.intValue = 0;
                    self.DecimalStatus = 0;
                    self.DecBoolStatus = 0;
                }
                else
                {
                    if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
                    if (self.DecimalStatus == 0)
                    {//Use normal simple (int value) * (int value) if not dealing with any decimals
                        self.intValue *= y;
                    }
                    else
                    {
                        uint SelfAsInt = self.DecimalStatus;
                        SelfAsInt += (uint)(self.intValue * 10000);
                        SelfAsInt *= y;
                        uint TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
#else
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
#if (MediumDec_ReducedSize)
                int TempDec = (int)self.DecimalStatus;
#else
                    long TempDec = (long)self.DecimalStatus;
#endif
                    TempDec *= y;
                    if (TempDec >= DecimalOverflow)
                    {
#if (MediumDec_ReducedSize)
                        int
#else
                        long
#endif
                        OverflowVal = TempDec / DecimalOverflow;
                        TempDec -= OverflowVal * DecimalOverflow;
                        self.IntValue += (ushort)OverflowVal;
                    }
                    if (TempDec == 0) { self.DecimalStatus = 0; }
                    else
                    {
                        if (SelfIsNegative) { TempDec *= -1; }
                        self.DecimalStatus =
#if (MediumDec_ReducedSize)
                        (short)
#else
                        (int)
#endif
                        TempDec;
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
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static MediumDec operator /(MediumDec self, dynamic y)
        {
#if (MediumDec_UseLegacyStorage)
            if (y is double || y is MediumDec || y is decimal)
            {
                if (y == 0)
                {
                    Console.WriteLine("Prevented dividing by zero");
                }
                else
                {
                    if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
                    ushort WholeHalf = (ushort)Math.Floor(y);
                    //Use x Int Operation instead if y has no decimal places
                    if (WholeHalf == y)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            //Use normal simple (int value) * (int value) if not dealing with any decimals
                            self.intValue /= WholeHalf;
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            SelfAsInt /= WholeHalf;
                            self.intValue = (ushort)(SelfAsInt / 1000);
                            SelfAsInt -= (uint)(self.intValue * 10000);
                            self.DecimalStatus = (ushort)SelfAsInt;
                        }
                    }
                    else
                    {
                        y -= WholeHalf;
                        ushort Decimalhalf = ExtractDecimalHalfV3(y);
                        ulong SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        uint YAsInt = WholeHalf;
                        YAsInt *= 10000;
                        YAsInt += Decimalhalf;
                        SelfAsInt /= YAsInt;
                        SelfAsInt /= 10000;
                        ulong TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage = self.intValue;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
            else if (y is string)
            {
                self /= (MediumDec)y;
            }
            else
            {
                if (y == 0)
                {
                    Console.WriteLine("Prevented dividing by zero");
                }
                else
                {
                    if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
                    if (self.DecimalStatus == 0)
                    {//Use normal simple (int value) * (int value) if not dealing with any decimals
                        self.intValue /= (ushort)y;
                    }
                    else
                    {
                        uint SelfAsInt = self.DecimalStatus;
                        SelfAsInt += (uint)(self.intValue * 10000);
                        SelfAsInt /= y;
                        uint TempStorage = SelfAsInt / 10000;
                        self.intValue = (ushort)TempStorage;
                        TempStorage *= 10000;
                        SelfAsInt -= TempStorage;
                        self.DecimalStatus = (ushort)SelfAsInt;
                    }
                    //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
                    if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
                }
            }
#else
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
#if (MediumDec_ReducedSize)
                    int ValueRep = (int)self.IntValue * DecimalOverflow;
#else
                    long ValueRep = (long)self.IntValue * DecimalOverflow;
#endif
                    ValueRep /= y;
#if (MediumDec_ReducedSize)
                    int
#else
                    long
#endif
                    WholeHalf = ValueRep / DecimalOverflow;
                    self.IntValue = (ushort)WholeHalf;
                    ValueRep -= WholeHalf;
                    self.DecimalStatus =
#if (MediumDec_ReducedSize)
                    (short)
#else
                    (int)
#endif
                    WholeHalf;
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
#endif
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
#if (MediumDec_UseLegacyStorage)
            if (Value.DecBoolStatus % 2 == 1)//ODD
            {
                Value.DecBoolStatus -= 1;
            }
            else
            {
                Value.DecBoolStatus += 1;
            }
#else
            if (Value.DecimalStatus == NegativeWholeNumber)
            {
                Value.DecimalStatus = 0;
            }
            else
            {
                Value.DecimalStatus *= -1;
            }
#endif
            return Value;
        }
    }
}
