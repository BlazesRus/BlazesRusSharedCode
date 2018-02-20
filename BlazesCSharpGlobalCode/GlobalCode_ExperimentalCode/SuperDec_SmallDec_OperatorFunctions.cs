/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;

    // Represent +- 65535.999999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    //(Aka SuperDec_Int16_9Decimal Or SuperDec_Int16_4Decimal)
    public
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_SmallDec_AsStruct)
    class
#else
    struct
#endif
    SmallDec : IFormattable, INotifyPropertyChanged
    {
        // Self Less than Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            else
            {
                // Positive Self <= -Value
                if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
                // Negative Self <= Value
                else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
                else
                {
                    ulong SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    ulong ValueAsInt = Value.intValue;
                    ValueAsInt *= 10000;
                    ValueAsInt += Value.DecimalStatus;
                    //Both are either positive or negative numbers
                    if (self.DecBoolStatus == 0)
                    {
                        return SelfAsInt < ValueAsInt;
                    }
                    else
                    {//Larger number = farther down into negative
                        return !(SelfAsInt < ValueAsInt);
                    }
                }
            }
#else
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
#endif
        }

        // Self Less than or equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            else
            {
                // Positive Self <= -Value
                if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
                // Negative Self <= Value
                else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
                else
                {
                    uint SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    uint ValueAsInt = Value.intValue;
                    ValueAsInt *= 10000;
                    ValueAsInt += Value.DecimalStatus;
                    //Both are either positive or negative numbers
                    if (self.DecBoolStatus == 0)
                    {
                        return SelfAsInt <= ValueAsInt;
                    }
                    else
                    {//Larger number = farther down into negative
                        return !(SelfAsInt <= ValueAsInt);
                    }
                }
            }
#else
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
#endif
        }

        // Self Greater than Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
            else
            {
                // Positive Self >= -Value
                if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
                // Negative Self >= Value
                else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
                else
                {
                    uint SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    uint ValueAsInt = Value.intValue;
                    ValueAsInt *= 10000;
                    ValueAsInt += Value.DecimalStatus;
                    //Both are either positive or negative numbers
                    if (self.DecBoolStatus == 0)
                    {
                        return SelfAsInt > ValueAsInt;
                    }
                    else
                    {//Larger number = farther down into negative
                        return !(SelfAsInt > ValueAsInt);
                    }
                }
            }
#else
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
#endif
        }

        // Self Greater than or Equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
            else
            {
                // Positive Self >= -Value
                if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
                // Negative Self >= Value
                else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
                else
                {
                    ulong SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    ulong ValueAsInt = Value.intValue;
                    ValueAsInt *= 10000;
                    ValueAsInt += Value.DecimalStatus;
                    //Both are either positive or negative numbers
                    if (self.DecBoolStatus == 0)
                    {
                        return SelfAsInt >= ValueAsInt;
                    }
                    else
                    {//Larger number = farther down into negative
                        return !(SelfAsInt >= ValueAsInt);
                    }
                }
            }
#else
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
#endif
        }

        /// <summary>
        /// Equality operator for comparing self to type value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            return (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus);
#else
            return (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus);
#endif
        }

        /// <summary>
        /// Inequality operator
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(SmallDec self, SmallDec Value)
        {
#if (SmallDec_UseLegacyStorage)
            return (self.DecBoolStatus != Value.DecBoolStatus || self.intValue != Value.intValue || self.DecimalStatus != Value.DecimalStatus);
#else
            return (self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus);
#endif
        }

        /// <summary>
        /// Self Less than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self < (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            if (self.DecBoolStatus == 0) { return self.intValue < WholeHalf; }
                            else { return !(self.intValue < WholeHalf); }
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            return self.DecBoolStatus == 0 ? SelfAsInt < (WholeHalf * 1000000000) : !(SelfAsInt < (WholeHalf * 1000000000));
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf;
                        Decimalhalf = ExtractDecimalHalfV3(Value);
                        uint SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        if (self.DecBoolStatus == 0) { return SelfAsInt < ValueAsInt; }
                        else { return !(SelfAsInt < ValueAsInt); }
                    }
                }
            }
            else
            {
                if (Value < 0 && self.DecBoolStatus == 0) { return false; }
                else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    if (Value == self.intValue) { return true; }
                    else
                    {
                        //Both are either positive or negative numbers
                        if (self.DecBoolStatus == 0)
                        {
                            return self.intValue < Value;
                        }
                        else
                        {//Larger number = farther down into negative
                            return !(self.intValue < Value);
                        }
                    }
                }
            }
#else
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
                return self < (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <(dynamic Value, SmallDec self) => self > Value;

        // Self Less than or equal to Value
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self <= (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            else if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            if (self.DecBoolStatus == 0) { return self.intValue <= WholeHalf; }
                            else { return !(self.intValue <= WholeHalf); }
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            if (self.DecBoolStatus == 0) { return SelfAsInt <= (uint)(WholeHalf * 1000); }
                            else { return !(SelfAsInt <= (uint)(WholeHalf * 10000)); }
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf = ExtractDecimalHalfV3(Value);
                        uint SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        if (self.DecBoolStatus == 0) { return SelfAsInt <= ValueAsInt; }
                        else { return !(SelfAsInt <= ValueAsInt); }
                    }
                }
            }
            else
            {
                if (Value < 0 && self.DecBoolStatus == 0) { return false; }
                else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    if (Value == self.intValue) { return true; }
                    else
                    {
                        //Both are either positive or negative numbers
                        if (self.DecBoolStatus == 0)
                        {
                            return self.intValue <= Value;
                        }
                        else
                        {//Larger number = farther down into negative
                            return !(self.intValue <= Value);
                        }
                    }
                }
            }
#else
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
                return self <= (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <=(dynamic Value, SmallDec self) => self >= Value;

        /// <summary>
        /// Self Greater than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self > (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            else if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                // Positive Self >= -Value
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            if (self.DecBoolStatus == 0) { return self.intValue > WholeHalf; }
                            else { return !(self.intValue > WholeHalf); }
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            if (self.DecBoolStatus == 0) { return SelfAsInt > (uint)(WholeHalf * 10000); }
                            else { return !(SelfAsInt > (uint)(WholeHalf * 10000)); }
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf;
                        if (Value == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (Value == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(Value);
                        }
                        uint SelfAsInt = self.intValue;
                        SelfAsInt *= 10000;
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
                        else { return !(SelfAsInt > ValueAsInt); }
                    }
                }
            }
            else
            {
                // Positive Self >= -Value
                if (Value < 0 && self.DecBoolStatus == 0) { return true; }
                // Negative Self >= Value
                else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    if (Value == self.intValue) { return false; }
                    else
                    {
                        //Both are either positive or negative numbers
                        if (self.DecBoolStatus == 0)
                        {
                            return self.intValue > Value;
                        }
                        else
                        {//Larger number = farther down into negative
                            return !(self.intValue > Value);
                        }
                    }
                }
            }
#else
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
                return self > (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >(dynamic Value, SmallDec self) => self < Value;

        /// <summary>
        /// Self Greater than or Equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                //return (String)Value == (String)self;
                return self >= (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            else if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            if (self.DecBoolStatus == 0) { return self.intValue >= WholeHalf; }
                            else { return !(self.intValue >= WholeHalf); }
                        }
                        else
                        {
                            uint SelfAsInt = (uint)(self.intValue * 10000);
                            SelfAsInt += self.DecimalStatus;
                            if (self.DecBoolStatus == 0) { return SelfAsInt >= (uint)(WholeHalf * 10000); }
                            else { return !(SelfAsInt >= (uint)(WholeHalf * 10000)); }
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf;
                        if (Value == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (Value == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(Value);
                        }
                        uint SelfAsInt = (uint)(self.intValue * 10000);
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
                        else { return !(SelfAsInt >= ValueAsInt); }
                    }
                }
            }
            else
            {
                if (Value < 0 && self.DecBoolStatus == 0) { return true; }
                else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    if (Value == self.intValue) { return true; }
                    else
                    {
                        //Both are either positive or negative numbers
                        if (self.DecBoolStatus == 0)
                        {
                            return self.intValue >= Value;
                        }
                        else
                        {//Larger number = farther down into negative
                            return !(self.intValue >= Value);
                        }
                    }
                }
            }
#else
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
                return self >= (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >=(dynamic Value, SmallDec self) => self <= Value;

        /// <summary>
        /// Equality operator for comparing self with other Variable Types
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self == (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            else if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            //Use normal simple (int value) * (int value) if not dealing with anValue decimals
                            return self.intValue != WholeHalf;
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            return SelfAsInt != (uint)(WholeHalf * 1000);
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf;
                        if (Value == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (Value == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(Value);
                        }
                        uint SelfAsInt = (uint)(self.intValue * 10000);
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        return SelfAsInt == ValueAsInt;
                    }
                }
            }
            else
            {
                if (self.DecimalStatus != 0) { return false; }
                else if (Value < 0 && self.DecBoolStatus == 0) { return false; }
                else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
                else
                {
                    Value = Math.Abs(Value);
                    return Value == self.intValue ? true : false;
                }
            }
#else
            else
            {
                return self == (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// Equality operator
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator ==(dynamic Value, SmallDec self) => self == Value;

        // Inequality operator for comparing self to multiple value types
        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(SmallDec self, dynamic Value)
        {
            if (Value is string)
            {
                return self != (SmallDec)Value;
            }
#if (SmallDec_UseLegacyStorage)
            if (Value is double || Value is float || Value is decimal)
            {
                // 0 = Double; 1 = float; 2 = decimal
                int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
                if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
                else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
                else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    ushort WholeHalf = (ushort)Value;
                    //Use x Int Operation instead if Value has no decimal places
                    if (WholeHalf == Value)
                    {
                        if (self.DecimalStatus == 0)
                        {
                            //Use normal simple (int value) * (int value) if not dealing with anValue decimals
                            return self.intValue != WholeHalf;
                        }
                        else
                        {
                            uint SelfAsInt = self.DecimalStatus;
                            SelfAsInt += (uint)(self.intValue * 10000);
                            return SelfAsInt != (uint)(WholeHalf * 10000);
                        }
                    }
                    else
                    {
                        Value -= WholeHalf;
                        ushort Decimalhalf;
                        if (Value == 0.25)
                        {
                            Decimalhalf = 2500;
                        }
                        else if (Value == 0.5)
                        {
                            Decimalhalf = 5000;
                        }
                        else
                        {
                            Decimalhalf = ExtractDecimalHalfV3(Value);
                        }
                        uint SelfAsInt = (ushort)(self.intValue * 10000);
                        SelfAsInt += self.DecimalStatus;
                        uint ValueAsInt = WholeHalf;
                        ValueAsInt *= 10000;
                        ValueAsInt += Decimalhalf;
                        return SelfAsInt != ValueAsInt;
                    }
                }
            }
            else
            {
                if (self.DecimalStatus != 0) { return true; }
                else if (Value < 0 && self.DecBoolStatus == 0) { return true; }
                else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
                else
                {
                    Value = Math.Abs(Value);
                    return Value == self.intValue ? false : true;
                }
            }
#else
            else
            {
                return self != (SmallDec)Value;
            }
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator !=(dynamic Value, SmallDec self) => self != Value;

        /// <summary>
        /// Implements the operator %.
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="y">The y.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static SmallDec operator %(SmallDec self, SmallDec y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
                self.intValue = 0;
                self.DecimalStatus = 0;
                self.DecBoolStatus = 0;
            }
            else
            {
                if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
                if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
                {//Use normal simple (int value) * (int value) if not dealing with any decimals
                    self.intValue %= y.intValue;
                }
                else if (y.DecimalStatus == 0)
                {
                    uint SelfAsInt = self.DecimalStatus;
                    SelfAsInt += (uint)(self.intValue * 10000);
                    SelfAsInt %= y.intValue;
                    self.intValue = (ushort)(SelfAsInt / 1000);
                    SelfAsInt -= (uint)(self.intValue * 10000);
                    self.DecimalStatus = (ushort)SelfAsInt;
                }
                else
                {
                    ulong SelfAsInt = self.DecimalStatus;
                    SelfAsInt += (ulong)(self.intValue * 10000);
                    uint YAsInt = y.intValue;
                    YAsInt *= 10000;
                    YAsInt += y.DecimalStatus;
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
            return self;
#else
            SmallDec NewSelf = self / y;
            if (NewSelf.IntValue < 1)
            {
                if (y.DecimalStatus < 0)
                {
                    if (self.DecimalStatus == NegativeWholeNumber)
                    {
                        self.DecimalStatus = 0;
                    }
                    else if (self.DecimalStatus == 0)
                    {
                        self.DecimalStatus = NegativeWholeNumber;
                    }
                    else
                    {
                        self.DecimalStatus *= -1;
                    }
                }
                return self;
            }
            else
            {
                return self - (NewSelf.IntValue * y);
            }
#endif
        }

        /// <summary>
        /// Implements the operator +.(Self+TargetValue)
        /// </summary>
        /// <param name="self">Self.</param>
        /// <param name="y">The TargetValue.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static SmallDec operator +(SmallDec self, SmallDec y)
        {
#if (SmallDec_UseLegacyStorage)
            bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
            if (self.DecBoolStatus == 1 && IsYNegative)
            {// -X - Y (ex. -8 + -6)
                self.intValue = (ushort)(self.intValue + y.intValue);
            }
            else if (self.DecBoolStatus == 0 && IsYNegative == false)
            {
                //X + Y (ex. 8 + 6)
                self.intValue = (ushort)(self.intValue + y.intValue);
            }
            else
            {
                // -X + Y
                if (self.DecBoolStatus == 1)
                {   //ex. -8 + 9
                    if (y.intValue > self.intValue)
                    {
                        self.intValue = (ushort)(y.intValue - self.intValue);
                        self.DecBoolStatus = 0;
                    }
                    else
                    {//ex. -8 +  4
                        self.intValue = (ushort)(self.intValue - y.intValue);
                    }
                }// X + -Y
                else
                {
                    if (self.intValue > y.intValue)
                    {//ex. 9 + -6
                        self.intValue = (ushort)(self.intValue - y.intValue);
                    }
                    else
                    {//ex. 9 + -10
                        self.intValue = (ushort)(y.intValue - self.intValue);
                        self.DecBoolStatus = 1;
                    }
                }
            }
            //Decimal Section
            if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
            {
                // ?.XXXXXX + ?.YYYYYY (ex. 0.9 + 0.2)
                if (self.DecBoolStatus == 0 && IsYNegative == false)
                {
                    //Potential Overflow check
                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
                    if (DecimalStatusTemp > 9999)
                    {
                        DecimalStatusTemp -= 10000;
                        self.intValue += 1;
                    }
                    self.DecimalStatus = DecimalStatusTemp;
                }
                // -?.XXXXXX - ?.YYYYYY (ex. -0.9 + -0.2)
                else if (self.DecBoolStatus == 1 && IsYNegative)
                {
                    //Potential Overflow check
                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
                    if (DecimalStatusTemp > 9999)
                    {
                        DecimalStatusTemp -= 10000;
                        self.intValue -= 1;
                    }
                    self.DecimalStatus = DecimalStatusTemp;
                }
                else
                {
                    if (IsYNegative)
                    {
                        // ex. 0.6 + -0.5
                        if (self.DecimalStatus >= y.DecimalStatus)
                        {
                            self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
                        }// ex. 0.6 + -.7
                        else
                        {
                            self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
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
                    { //ex -0.6 + 0.5
                        if (self.DecimalStatus >= y.DecimalStatus)
                        {
                            self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
                        }// ex. -1.6 + 0.7
                        else
                        {
                            self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
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
            //Fix potential negative zero
            if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
#else
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
#endif
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
        public static SmallDec operator -(SmallDec self, SmallDec y)
        {
#if (SmallDec_UseLegacyStorage)
            bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
            //ex. -9 - 9
            if (self.DecBoolStatus == 1 && IsYNegative == false)
            {// -X - Y
                self.intValue = (ushort)(self.intValue + y.intValue);
            }//ex. 9 - (-1)
            else if (self.DecBoolStatus == 0 && IsYNegative == true)
            {
                //X - (-Y)
                self.intValue = (ushort)(self.intValue + y.intValue);
            }
            else
            {
                // X - (Y)
                if (self.DecBoolStatus == 0)
                {
                    // ex. 8 - 9
                    if (y.intValue > self.intValue)
                    {
                        self.intValue = (ushort)(y.intValue - self.intValue);
                        self.DecBoolStatus = 1;
                    } //ex. 8 - 7
                    else
                    {
                        self.intValue = (ushort)(self.intValue - y.intValue);
                    }
                }// -X - (Y)
                else
                {
                    // ex. -8 - (-9)
                    if (self.intValue > y.intValue)
                    {
                        self.intValue = (ushort)(y.intValue - self.intValue);
                        self.DecBoolStatus = 0;
                    }
                    else
                    {//ex. -8 - (-5)
                        self.intValue = (ushort)(self.intValue - y.intValue);
                    }
                }
            }
            //Decimal Section
            if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
            {
                // ex. -0.5 - 0.6
                if (self.DecBoolStatus == 1 && IsYNegative == false)
                {
                    //Potential Overflow check
                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
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
                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
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
                        if (self.DecimalStatus >= y.DecimalStatus)
                        {
                            self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
                        }
                        else
                        {
                            self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
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
                        if (self.DecimalStatus >= y.DecimalStatus)
                        {
                            self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
                        }
                        else
                        {
                            self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
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
            //Fix potential negative zero
            if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
#else
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
#endif
            return self;
        }

        /// <summary>
        /// Implements the operator *.(Self*TargetValue)
        /// </summary>
        /// <param name="self">The self.</param>
        /// <param name="y">The y.</param>
        /// <returns>
        /// The result of the operator.
        /// </returns>
        public static SmallDec operator *(SmallDec self, SmallDec y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
                self.intValue = 0;
                self.DecimalStatus = 0;
                self.DecBoolStatus = 0;
            }
            else
            {
                if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
                if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
                {//Use normal simple (int value) * (int value) if not dealing with any decimals
                    self.intValue *= y.intValue;
                }
                else if (y.DecimalStatus == 0)
                {
                    uint SelfAsInt = self.DecimalStatus;
                    SelfAsInt += (uint)(self.intValue * 10000);
                    SelfAsInt *= y.intValue;
                    self.intValue = (ushort)(SelfAsInt / 1000);
                    SelfAsInt -= (uint)(self.intValue * 10000);
                    self.DecimalStatus = (ushort)SelfAsInt;
                }
                else
                {
                    ulong SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    uint YAsInt = y.intValue;
                    YAsInt *= 10000;
                    YAsInt += y.DecimalStatus;
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
#else
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
            if (self.DecimalStatus == 0)
            {
                if (y.DecimalStatus == 0)
                {
                    y.IntValue *= self.IntValue;
                }
                else
                {
                    y.IntValue *= self.IntValue;
#if (SmallDec_ReducedSize)
                    int TempDec = (int)y.DecimalStatus;
#else
                    long TempDec = (long)y.DecimalStatus;
#endif
                    TempDec *= self.IntValue;
                    if (TempDec >= DecimalOverflow)
                    {
#if (SmallDec_ReducedSize)
                        int
#else
                        long
#endif
                        OverflowVal = TempDec / DecimalOverflow;
                        TempDec -= OverflowVal * DecimalOverflow;
                        y.IntValue += (ushort)OverflowVal;
                    }
                    if (TempDec == 0) { y.DecimalStatus = 0; }
                    else
                    {
                        if (SelfIsNegative) { TempDec *= -1; }
                        y.DecimalStatus =
#if (SmallDec_ReducedSize)
                        (short)
#else
                        (int)
#endif
                    TempDec;
                    }
                    self = y;
                }
            }
            else if (y.DecimalStatus == 0)
            {
                self.IntValue *= y.IntValue;
#if (SmallDec_ReducedSize)
                int TempDec = (int)self.DecimalStatus;
#else
                long TempDec = (long)self.DecimalStatus;
#endif
                TempDec *= y.IntValue;
                if (TempDec >= DecimalOverflow)
                {
#if (SmallDec_ReducedSize)
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
#if (SmallDec_ReducedSize)
                    (short)
#else
                    (int)
#endif
                    TempDec;
                }
            }
            else if(self.IntValue==0&&y.IntValue==0)//Fractional Multiplied by Fractional (will only be at or above DecimalOverflow if error in calculation)
            {
                long DTemp = self.DecimalStatus;
                DTemp *= y.DecimalStatus;
                DTemp /= DecimalOverflow;
                self = new SmallDec(0, (int)DTemp);
            }
            else if (self.IntValue == 0|| y.IntValue == 0)
            {
                long DTemp;
                long DTemp02;
                if(self.IntValue == 0)
                {
                    DTemp = self.DecimalStatus;
                    DTemp *= y.IntValue;
                    DTemp02 = self.DecimalStatus;
                    DTemp02 *= y.DecimalStatus;
                    DTemp02 /= DecimalOverflow;
                }
                else
                {
                    DTemp = y.DecimalStatus;
                    DTemp *= self.IntValue;
                    DTemp02 = y.DecimalStatus;
                    DTemp02 *= self.DecimalStatus;
                    DTemp02 /= DecimalOverflow;
                }
                long DecimalTotal = DTemp + DTemp02;
                if (DecimalTotal > DecimalOverflow)
                {
                    long OverflowedInt = DecimalTotal / DecimalOverflow;
                    DecimalTotal -= OverflowedInt * DecimalOverflow;
                    self = new SmallDec((ushort)OverflowedInt, (int)DecimalTotal);
                }
                else
                {
                    self = new SmallDec(0, (int)DecimalTotal);
                }

            }
            else
            {
                SmallDec XRep = new SmallDec(self.IntValue,0);
                SmallDec ZRep = new SmallDec(y.IntValue, 0);
                SmallDec YRep = new SmallDec(0, self.DecimalStatus);
                SmallDec VRep = new SmallDec(0, y.DecimalStatus);
                //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                SmallDec TotalRep = XRep * ZRep;
                TotalRep += XRep * VRep;
                TotalRep += ZRep * YRep;
                TotalRep += YRep * VRep;
                if(TotalRep.DecimalStatus> DecimalOverflow)
                {
                    int DOverflow = TotalRep.DecimalStatus / DecimalOverflow;
                    TotalRep += DOverflow;
                    TotalRep.DecimalStatus -= DecimalOverflow;
                }
                self = TotalRep;
            }
            if (ValueIsNegative)
            {
                SelfIsNegative = !SelfIsNegative;
            }
            if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
#endif
                return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator /(SmallDec self, SmallDec y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y.intValue == 0 && y.DecimalStatus == 0)
            {
                Console.WriteLine("Prevented dividing by zero");
            }
            else
            {
                if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
                if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
                {//Use normal simple (int value) * (int value) if not dealing with any decimals
                    self.intValue /= y.intValue;
                }
                else if (y.DecimalStatus == 0)
                {
                    uint SelfAsInt = self.DecimalStatus;
                    SelfAsInt += (uint)(self.intValue * 10000);
                    SelfAsInt /= y.intValue;
                    self.intValue = (ushort)(SelfAsInt / 1000);
                    SelfAsInt -= (uint)(self.intValue * 10000);
                    self.DecimalStatus = (ushort)SelfAsInt;
                }
                else
                {
                    ulong SelfAsInt = self.intValue;
                    SelfAsInt *= 10000;
                    SelfAsInt += self.DecimalStatus;
                    uint YAsInt = y.intValue;
                    YAsInt *= 10000;
                    YAsInt += y.DecimalStatus;
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
#else
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
            if (self.DecimalStatus == 0)
            {
                if (y.DecimalStatus == 0)
                {
                    self.IntValue /= y.IntValue;
                }
                else
                {
                    self.IntValue /= y.IntValue;
#if (SmallDec_ReducedSize)
                    int TempDec = (int)y.DecimalStatus;
#else
                    long TempDec = (long)y.DecimalStatus;
#endif
                    TempDec *= self.IntValue;
                    if (TempDec >= DecimalOverflow)
                    {
#if (SmallDec_ReducedSize)
                        int
#else
                        long
#endif
                        OverflowVal = TempDec / DecimalOverflow;
                        TempDec -= OverflowVal * DecimalOverflow;
                        y.IntValue += (ushort)OverflowVal;
                    }
                    if (TempDec == 0) { y.DecimalStatus = 0; }
                    else
                    {
                        if (SelfIsNegative) { TempDec *= -1; }
                        y.DecimalStatus =
#if (SmallDec_ReducedSize)
                        (short)
#else
                        (int)
#endif
                    TempDec;
                    }
                    self = y;
                }
            }
            else if (y.DecimalStatus == 0)
            {
                self.IntValue /= y.IntValue;
#if (SmallDec_ReducedSize)
                int TempDec = (int)self.DecimalStatus;
#else
                long TempDec = (long)self.DecimalStatus;
#endif
                TempDec /= y.IntValue;
                if (TempDec >= DecimalOverflow)
                {
#if (SmallDec_ReducedSize)
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
#if (SmallDec_ReducedSize)
                    (short)
#else
                    (int)
#endif
                    TempDec;
                }
            }
            else if (self.IntValue == 0 && y.IntValue == 0)//Fractional Multiplied by Fractional (will only be at or above DecimalOverflow if error in calculation)
            {
                long DTemp = self.DecimalStatus;
                DTemp /= y.DecimalStatus;
                DTemp /= DecimalOverflow;
                self = new SmallDec(0, (int)DTemp);
            }
            else if (self.IntValue == 0 || y.IntValue == 0)
            {
                long DTemp;
                long DTemp02;
                if (self.IntValue == 0)
                {
                    DTemp = self.DecimalStatus;
                    DTemp /= y.IntValue;
                    DTemp02 = self.DecimalStatus;
                    DTemp02 /= y.DecimalStatus;
                    DTemp02 /= DecimalOverflow;
                }
                else
                {
                    DTemp = y.DecimalStatus;
                    DTemp /= self.IntValue;
                    DTemp02 = y.DecimalStatus;
                    DTemp02 /= self.DecimalStatus;
                    DTemp02 /= DecimalOverflow;
                }
                long DecimalTotal = DTemp + DTemp02;
                if (DecimalTotal > DecimalOverflow)
                {
                    long OverflowedInt = DecimalTotal / DecimalOverflow;
                    DecimalTotal -= OverflowedInt * DecimalOverflow;
                    self = new SmallDec((ushort)OverflowedInt, (int)DecimalTotal);
                }
                else
                {
                    self = new SmallDec(0, (int)DecimalTotal);
                }

            }
            else
            {
                SmallDec XRep = (SmallDec)self.IntValue;
                SmallDec ZRep = (SmallDec)y.IntValue;
                SmallDec YRep = new SmallDec(0, self.DecimalStatus);
                SmallDec VRep = new SmallDec(0, y.DecimalStatus);
                //X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
                SmallDec TotalRep = XRep / ZRep;
                TotalRep += XRep / VRep;
                TotalRep += ZRep / YRep;
                TotalRep += YRep / VRep;
                if (TotalRep.DecimalStatus > DecimalOverflow)
                {
                    int DOverflow = TotalRep.DecimalStatus / DecimalOverflow;
                    TotalRep += DOverflow;
                    TotalRep.DecimalStatus -= DecimalOverflow;
                }
                self = TotalRep;
            }
            if (ValueIsNegative)
            {
                SelfIsNegative = !SelfIsNegative;
            }
            if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator %(SmallDec self, dynamic y)
        {
#if (SmallDec_UseLegacyStorage)
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
                self %= (SmallDec)y;
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
            return self %= (SmallDec)y;
#endif
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator +(SmallDec self, dynamic y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y is double || y is SmallDec || y is decimal)
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
                self += (SmallDec)y;
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
            //    return self += (SmallDec)y;
            //}
            else
            {
                return self += (SmallDec)y;
            }
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator -(SmallDec self, dynamic y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y is double || y is SmallDec || y is decimal)
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
                self -= (SmallDec)y;
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
#if (SmallDec_ReducedSize)
#else

#endif
            }
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self -= (SmallDec)y;
            //}
            else
            {
                return self -= (SmallDec)y;
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
        public static SmallDec operator *(SmallDec self, dynamic y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y is double || y is SmallDec || y is decimal)
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
                self *= (SmallDec)y;
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
#if (SmallDec_ReducedSize)
                int TempDec = (int)self.DecimalStatus;
#else
                    long TempDec = (long)self.DecimalStatus;
#endif
                    TempDec *= y;
                    if (TempDec >= DecimalOverflow)
                    {
#if (SmallDec_ReducedSize)
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
#if (SmallDec_ReducedSize)
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
            //    return self *= (SmallDec)y;
            //}
            else
            {
                return self *= (SmallDec)y;
            }
#endif
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator /(SmallDec self, dynamic y)
        {
#if (SmallDec_UseLegacyStorage)
            if (y is double || y is SmallDec || y is decimal)
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
                self /= (SmallDec)y;
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
#if (SmallDec_ReducedSize)
                    int ValueRep = (int)self.IntValue * DecimalOverflow;
#else
                    long ValueRep = (long)self.IntValue * DecimalOverflow;
#endif
                    ValueRep /= y;
#if (SmallDec_ReducedSize)
                    int
#else
                    long
#endif
                    WholeHalf = ValueRep / DecimalOverflow;
                    self.IntValue = (ushort)WholeHalf;
                    ValueRep -= WholeHalf;
                    self.DecimalStatus =
#if (SmallDec_ReducedSize)
                    (short)
#else
                    (int)
#endif
                    WholeHalf;
                }
                else
                {
                    return self /= (SmallDec)y;
                }
            }
            //else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based formula value types
            //{
            //    return self /= (SmallDec)y;
            //}
            else
            {
                return self /= (SmallDec)y;
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
        public static SmallDec operator -(dynamic y, SmallDec self)
        {
            SmallDec YAsSuperDec = (SmallDec)y;
            YAsSuperDec -= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static SmallDec operator +(dynamic y, SmallDec self)
        {
            SmallDec YAsSuperDec = (SmallDec)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static SmallDec operator *(dynamic y, SmallDec self)
        {
            SmallDec YAsSuperDec = (SmallDec)y;
            YAsSuperDec *= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static SmallDec operator /(dynamic y, SmallDec self)
        {
            SmallDec YAsSuperDec = (SmallDec)y;
            YAsSuperDec /= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec operator -(SmallDec Value)
        {//Place DecBoolStatus>1 checks above in V2 of type
#if (SmallDec_UseLegacyStorage)
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