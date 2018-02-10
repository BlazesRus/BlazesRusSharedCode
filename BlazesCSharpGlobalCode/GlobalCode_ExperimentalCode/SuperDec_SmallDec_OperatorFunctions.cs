/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

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
    //    // Self Less than Value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator <(SmallDec self, SmallDec Value)
    //    {
    //        if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
    //        else
    //        {
    //            // Positive Self <= -Value
    //            if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
    //            // Negative Self <= Value
    //            else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                ulong SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                ulong ValueAsInt = Value.intValue;
    //                ValueAsInt *= 10000;
    //                ValueAsInt += Value.DecimalStatus;
    //                //Both are either positive or negative numbers
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    return SelfAsInt < ValueAsInt;
    //                }
    //                else
    //                {//Larger number = farther down into negative
    //                    return !(SelfAsInt < ValueAsInt);
    //                }
    //            }
    //        }
    //    }

    //    // Self Less than or equal to Value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator <=(SmallDec self, SmallDec Value)
    //    {
    //        if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
    //        else
    //        {
    //            // Positive Self <= -Value
    //            if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return false; }
    //            // Negative Self <= Value
    //            else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                uint SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                uint ValueAsInt = Value.intValue;
    //                ValueAsInt *= 10000;
    //                ValueAsInt += Value.DecimalStatus;
    //                //Both are either positive or negative numbers
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    return SelfAsInt <= ValueAsInt;
    //                }
    //                else
    //                {//Larger number = farther down into negative
    //                    return !(SelfAsInt <= ValueAsInt);
    //                }
    //            }
    //        }
    //    }

    //    // Self Greater than Value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator >(SmallDec self, SmallDec Value)
    //    {
    //        if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
    //        else
    //        {
    //            // Positive Self >= -Value
    //            if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
    //            // Negative Self >= Value
    //            else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                uint SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                uint ValueAsInt = Value.intValue;
    //                ValueAsInt *= 10000;
    //                ValueAsInt += Value.DecimalStatus;
    //                //Both are either positive or negative numbers
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    return SelfAsInt > ValueAsInt;
    //                }
    //                else
    //                {//Larger number = farther down into negative
    //                    return !(SelfAsInt > ValueAsInt);
    //                }
    //            }
    //        }
    //    }

    //    // Self Greater than or Equal to Value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator >=(SmallDec self, SmallDec Value)
    //    {
    //        if (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
    //        else
    //        {
    //            // Positive Self >= -Value
    //            if (Value.DecBoolStatus == 1 && self.DecBoolStatus == 0) { return true; }
    //            // Negative Self >= Value
    //            else if (Value.DecBoolStatus == 0 && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                ulong SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                ulong ValueAsInt = Value.intValue;
    //                ValueAsInt *= 10000;
    //                ValueAsInt += Value.DecimalStatus;
    //                //Both are either positive or negative numbers
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    return SelfAsInt >= ValueAsInt;
    //                }
    //                else
    //                {//Larger number = farther down into negative
    //                    return !(SelfAsInt >= ValueAsInt);
    //                }
    //            }
    //        }
    //    }

    //    // Equality operator for comparing self to int type value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator ==(SmallDec self, SmallDec Value) => (self.DecBoolStatus == Value.DecBoolStatus && self.intValue == Value.intValue && self.DecimalStatus == Value.DecimalStatus);

    //    /// <summary>
    //    /// Inequality operator
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator !=(SmallDec self, SmallDec Value) => (self.DecBoolStatus != Value.DecBoolStatus || self.intValue != Value.intValue || self.DecimalStatus != Value.DecimalStatus);

    //    /// <summary>
    //    /// Self Less than Value
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator <(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        if (self.DecBoolStatus == 0) { return self.intValue < WholeHalf; }
    //                        else { return !(self.intValue < WholeHalf); }
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        return self.DecBoolStatus == 0 ? SelfAsInt < (WholeHalf * 1000000000) : !(SelfAsInt < (WholeHalf * 1000000000));
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    uint SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    if (self.DecBoolStatus == 0) { return SelfAsInt < ValueAsInt; }
    //                    else { return !(SelfAsInt < ValueAsInt); }
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            return self < (SmallDec)Value;
    //        }
    //        else
    //        {
    //            if (Value < 0 && self.DecBoolStatus == 0) { return false; }
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                if (Value == self.intValue) { return true; }
    //                else
    //                {
    //                    //Both are either positive or negative numbers
    //                    if (self.DecBoolStatus == 0)
    //                    {
    //                        return self.intValue < Value;
    //                    }
    //                    else
    //                    {//Larger number = farther down into negative
    //                        return !(self.intValue < Value);
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator <(dynamic Value, SmallDec self) => self > Value;

    //    // Self Less than or equal to Value
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator <=(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        if (self.DecBoolStatus == 0) { return self.intValue <= WholeHalf; }
    //                        else { return !(self.intValue <= WholeHalf); }
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        if (self.DecBoolStatus == 0) { return SelfAsInt <= (uint)(WholeHalf * 1000); }
    //                        else { return !(SelfAsInt <= (uint)(WholeHalf * 10000)); }
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    uint SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    if (self.DecBoolStatus == 0) { return SelfAsInt <= ValueAsInt; }
    //                    else { return !(SelfAsInt <= ValueAsInt); }
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            return self <= (SmallDec)Value;
    //        }
    //        else
    //        {
    //            if (Value < 0 && self.DecBoolStatus == 0) { return false; }
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                if (Value == self.intValue) { return true; }
    //                else
    //                {
    //                    //Both are either positive or negative numbers
    //                    if (self.DecBoolStatus == 0)
    //                    {
    //                        return self.intValue <= Value;
    //                    }
    //                    else
    //                    {//Larger number = farther down into negative
    //                        return !(self.intValue <= Value);
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator <=(dynamic Value, SmallDec self) => self >= Value;

    //    /// <summary>
    //    /// Self Greater than Value
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator >(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            // Positive Self >= -Value
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        if (self.DecBoolStatus == 0) { return self.intValue > WholeHalf; }
    //                        else { return !(self.intValue > WholeHalf); }
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        if (self.DecBoolStatus == 0) { return SelfAsInt > (uint)(WholeHalf * 10000); }
    //                        else { return !(SelfAsInt > (uint)(WholeHalf * 10000)); }
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (Value == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (Value == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    }
    //                    uint SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
    //                    else { return !(SelfAsInt > ValueAsInt); }
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            //return (String)Value == (String)self;
    //            return self > (SmallDec)Value;
    //        }
    //        else
    //        {
    //            // Positive Self >= -Value
    //            if (Value < 0 && self.DecBoolStatus == 0) { return true; }
    //            // Negative Self >= Value
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                if (Value == self.intValue) { return false; }
    //                else
    //                {
    //                    //Both are either positive or negative numbers
    //                    if (self.DecBoolStatus == 0)
    //                    {
    //                        return self.intValue > Value;
    //                    }
    //                    else
    //                    {//Larger number = farther down into negative
    //                        return !(self.intValue > Value);
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator >(dynamic Value, SmallDec self) => self < Value;

    //    /// <summary>
    //    /// Self Greater than or Equal to Value
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator >=(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        if (self.DecBoolStatus == 0) { return self.intValue >= WholeHalf; }
    //                        else { return !(self.intValue >= WholeHalf); }
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = (uint)(self.intValue * 10000);
    //                        SelfAsInt += self.DecimalStatus;
    //                        if (self.DecBoolStatus == 0) { return SelfAsInt >= (uint)(WholeHalf * 10000); }
    //                        else { return !(SelfAsInt >= (uint)(WholeHalf * 10000)); }
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (Value == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (Value == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    }
    //                    uint SelfAsInt = (uint)(self.intValue * 10000);
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    if (self.DecBoolStatus == 0) { return SelfAsInt >= ValueAsInt; }
    //                    else { return !(SelfAsInt >= ValueAsInt); }
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            //return (String)Value == (String)self;
    //            return self >= (SmallDec)Value;
    //        }
    //        else
    //        {
    //            if (Value < 0 && self.DecBoolStatus == 0) { return true; }
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                if (Value == self.intValue) { return true; }
    //                else
    //                {
    //                    //Both are either positive or negative numbers
    //                    if (self.DecBoolStatus == 0)
    //                    {
    //                        return self.intValue >= Value;
    //                    }
    //                    else
    //                    {//Larger number = farther down into negative
    //                        return !(self.intValue >= Value);
    //                    }
    //                }
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator >=(dynamic Value, SmallDec self) => self <= Value;

    //    /// <summary>
    //    /// Equality operator for comparing self with other Variable Types
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator ==(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return false; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return false; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        //Use normal simple (int value) * (int value) if not dealing with anValue decimals
    //                        return self.intValue != WholeHalf;
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        return SelfAsInt != (uint)(WholeHalf * 1000);
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (Value == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (Value == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    }
    //                    uint SelfAsInt = (uint)(self.intValue * 10000);
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    return SelfAsInt == ValueAsInt;
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            return self == (SmallDec)Value;
    //        }
    //        else
    //        {
    //            if (self.DecimalStatus != 0) { return false; }
    //            else if (Value < 0 && self.DecBoolStatus == 0) { return false; }
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                return Value == self.intValue ? true : false;
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// Equality operator
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator ==(dynamic Value, SmallDec self) => self == Value;

    //    // Inequality operator for comparing self to multiple value types
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static bool operator !=(SmallDec self, dynamic Value)
    //    {
    //        if (Value is double || Value is float || Value is decimal)
    //        {
    //            // 0 = Double; 1 = float; 2 = decimal
    //            int ValueType = Value is double ? 0 : (Value is float ? 1 : 2);
    //            if (ValueType == 0 && Value < 0.0 && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 0 && Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 1 && Value < 0.0f && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 1 && Value >= 0.0f && self.DecBoolStatus == 1) { return true; }
    //            else if (ValueType == 2 && Value < 0.0M && self.DecBoolStatus == 0) { return true; }
    //            else if (ValueType == 2 && Value >= 0.0M && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                ushort WholeHalf = (ushort)Value;
    //                //Use x Int Operation instead if Value has no decimal places
    //                if (WholeHalf == Value)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        //Use normal simple (int value) * (int value) if not dealing with anValue decimals
    //                        return self.intValue != WholeHalf;
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        return SelfAsInt != (uint)(WholeHalf * 10000);
    //                    }
    //                }
    //                else
    //                {
    //                    Value -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (Value == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (Value == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(Value);
    //                    }
    //                    uint SelfAsInt = (ushort)(self.intValue * 10000);
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint ValueAsInt = WholeHalf;
    //                    ValueAsInt *= 10000;
    //                    ValueAsInt += Decimalhalf;
    //                    return SelfAsInt != ValueAsInt;
    //                }
    //            }
    //        }
    //        else if (Value is string)
    //        {
    //            return self != (SmallDec)Value;
    //        }
    //        else
    //        {
    //            if (self.DecimalStatus != 0) { return true; }
    //            else if (Value < 0 && self.DecBoolStatus == 0) { return true; }
    //            else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
    //            else
    //            {
    //                Value = Math.Abs(Value);
    //                return Value == self.intValue ? false : true;
    //            }
    //        }
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static bool operator !=(dynamic Value, SmallDec self) => self != Value;

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator %(SmallDec self, SmallDec y)
    //    {
    //        if (y.intValue == 0 && y.DecimalStatus == 0)
    //        {
    //            self.intValue = 0;
    //            self.DecimalStatus = 0;
    //            self.DecBoolStatus = 0;
    //        }
    //        else
    //        {
    //            if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
    //            if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
    //            {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                self.intValue %= y.intValue;
    //            }
    //            else if (y.DecimalStatus == 0)
    //            {
    //                uint SelfAsInt = self.DecimalStatus;
    //                SelfAsInt += (uint)(self.intValue * 10000);
    //                SelfAsInt %= y.intValue;
    //                self.intValue = (ushort)(SelfAsInt / 1000);
    //                SelfAsInt -= (uint)(self.intValue * 10000);
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            else
    //            {
    //                ulong SelfAsInt = self.DecimalStatus;
    //                SelfAsInt += (ulong)(self.intValue * 10000);
    //                uint YAsInt = y.intValue;
    //                YAsInt *= 10000;
    //                YAsInt += y.DecimalStatus;
    //                SelfAsInt %= YAsInt;
    //                SelfAsInt /= 10000;
    //                ulong TempStorage = SelfAsInt / 10000;
    //                self.intValue = (ushort)TempStorage;
    //                TempStorage = self.intValue;
    //                TempStorage *= 10000;
    //                SelfAsInt -= TempStorage;
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //            if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //        }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator +(SmallDec self, SmallDec y)
    //    {
    //        bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
    //        if (self.DecBoolStatus == 1 && IsYNegative)
    //        {// -X - Y (ex. -8 + -6)
    //            self.intValue = (ushort)(self.intValue + y.intValue);
    //        }
    //        else if (self.DecBoolStatus == 0 && IsYNegative == false)
    //        {
    //            //X + Y (ex. 8 + 6)
    //            self.intValue = (ushort)(self.intValue + y.intValue);
    //        }
    //        else
    //        {
    //            // -X + Y
    //            if (self.DecBoolStatus == 1)
    //            {   //ex. -8 + 9
    //                if (y.intValue > self.intValue)
    //                {
    //                    self.intValue = (ushort)(y.intValue - self.intValue);
    //                    self.DecBoolStatus = 0;
    //                }
    //                else
    //                {//ex. -8 +  4
    //                    self.intValue = (ushort)(self.intValue - y.intValue);
    //                }
    //            }// X + -Y
    //            else
    //            {
    //                if (self.intValue > y.intValue)
    //                {//ex. 9 + -6
    //                    self.intValue = (ushort)(self.intValue - y.intValue);
    //                }
    //                else
    //                {//ex. 9 + -10
    //                    self.intValue = (ushort)(y.intValue - self.intValue);
    //                    self.DecBoolStatus = 1;
    //                }
    //            }
    //        }
    //        //Decimal Section
    //        if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
    //        {
    //            // ?.XXXXXX + ?.YYYYYY (ex. 0.9 + 0.2)
    //            if (self.DecBoolStatus == 0 && IsYNegative == false)
    //            {
    //                //Potential Overflow check
    //                ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
    //                if (DecimalStatusTemp > 9999)
    //                {
    //                    DecimalStatusTemp -= 10000;
    //                    self.intValue += 1;
    //                }
    //                self.DecimalStatus = DecimalStatusTemp;
    //            }
    //            // -?.XXXXXX - ?.YYYYYY (ex. -0.9 + -0.2)
    //            else if (self.DecBoolStatus == 1 && IsYNegative)
    //            {
    //                //Potential Overflow check
    //                ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
    //                if (DecimalStatusTemp > 9999)
    //                {
    //                    DecimalStatusTemp -= 10000;
    //                    self.intValue -= 1;
    //                }
    //                self.DecimalStatus = DecimalStatusTemp;
    //            }
    //            else
    //            {
    //                if (IsYNegative)
    //                {
    //                    // ex. 0.6 + -0.5
    //                    if (self.DecimalStatus >= y.DecimalStatus)
    //                    {
    //                        self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
    //                    }// ex. 0.6 + -.7
    //                    else
    //                    {
    //                        self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
    //                        if (self.intValue == 0)
    //                        {
    //                            self.DecBoolStatus = 1;
    //                        }
    //                        else
    //                        {
    //                            self.intValue -= 1;
    //                        }
    //                    }
    //                }
    //                else
    //                { //ex -0.6 + 0.5
    //                    if (self.DecimalStatus >= y.DecimalStatus)
    //                    {
    //                        self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
    //                    }// ex. -1.6 + 0.7
    //                    else
    //                    {
    //                        self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
    //                        if (self.intValue == 0)
    //                        {
    //                            self.DecBoolStatus = 0;
    //                        }
    //                        else
    //                        {
    //                            self.intValue -= 1;
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //        //Fix potential negative zero
    //        if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator -(SmallDec self, SmallDec y)
    //    {
    //        bool IsYNegative = (y.DecBoolStatus == 1) ? true : false;
    //        //ex. -9 - 9
    //        if (self.DecBoolStatus == 1 && IsYNegative == false)
    //        {// -X - Y
    //            self.intValue = (ushort)(self.intValue + y.intValue);
    //        }//ex. 9 - (-1)
    //        else if (self.DecBoolStatus == 0 && IsYNegative == true)
    //        {
    //            //X - (-Y)
    //            self.intValue = (ushort)(self.intValue + y.intValue);
    //        }
    //        else
    //        {
    //            // X - (Y)
    //            if (self.DecBoolStatus == 0)
    //            {
    //                // ex. 8 - 9
    //                if (y.intValue > self.intValue)
    //                {
    //                    self.intValue = (ushort)(y.intValue - self.intValue);
    //                    self.DecBoolStatus = 1;
    //                } //ex. 8 - 7
    //                else
    //                {
    //                    self.intValue = (ushort)(self.intValue - y.intValue);
    //                }
    //            }// -X - (Y)
    //            else
    //            {
    //                // ex. -8 - (-9)
    //                if (self.intValue > y.intValue)
    //                {
    //                    self.intValue = (ushort)(y.intValue - self.intValue);
    //                    self.DecBoolStatus = 0;
    //                }
    //                else
    //                {//ex. -8 - (-5)
    //                    self.intValue = (ushort)(self.intValue - y.intValue);
    //                }
    //            }
    //        }
    //        //Decimal Section
    //        if (self.DecimalStatus != 0 || y.DecimalStatus != 0)
    //        {
    //            // ex. -0.5 - 0.6
    //            if (self.DecBoolStatus == 1 && IsYNegative == false)
    //            {
    //                //Potential Overflow check
    //                ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
    //                if (DecimalStatusTemp > 9999)
    //                {
    //                    DecimalStatusTemp -= 10000;
    //                    self.intValue += 1;
    //                }
    //                self.DecimalStatus = DecimalStatusTemp;
    //            }// ex. 0.5 - (-0.6)
    //            else if (self.DecBoolStatus == 0 && IsYNegative)
    //            {
    //                //Potential Overflow check
    //                ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + y.DecimalStatus);
    //                if (DecimalStatusTemp > 9999)
    //                {
    //                    DecimalStatusTemp -= 10000;
    //                    self.intValue += 1;
    //                }
    //                self.DecimalStatus = DecimalStatusTemp;
    //            }
    //            else
    //            {
    //                if (IsYNegative)
    //                {// ex. -0.7 - (-0.6)
    //                    if (self.DecimalStatus >= y.DecimalStatus)
    //                    {
    //                        self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
    //                    }
    //                    else
    //                    {
    //                        self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
    //                        if (self.intValue == 0)
    //                        {
    //                            self.DecBoolStatus = 0;
    //                        }
    //                        else
    //                        {
    //                            self.intValue -= 1;
    //                        }
    //                    }
    //                }
    //                else
    //                { //ex  0.6 - 0.5
    //                    if (self.DecimalStatus >= y.DecimalStatus)
    //                    {
    //                        self.DecimalStatus = (ushort)(self.DecimalStatus - y.DecimalStatus);
    //                    }
    //                    else
    //                    {
    //                        self.DecimalStatus = (ushort)(y.DecimalStatus - self.DecimalStatus);
    //                        if (self.intValue == 0)
    //                        {
    //                            self.DecBoolStatus = 1;
    //                        }
    //                        else
    //                        {
    //                            self.intValue -= 1;
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //        //Fix potential negative zero
    //        if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator *(SmallDec self, SmallDec y)
    //    {
    //        if (y.intValue == 0 && y.DecimalStatus == 0)
    //        {
    //            self.intValue = 0;
    //            self.DecimalStatus = 0;
    //            self.DecBoolStatus = 0;
    //        }
    //        else
    //        {
    //            if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
    //            if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
    //            {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                self.intValue *= y.intValue;
    //            }
    //            else if (y.DecimalStatus == 0)
    //            {
    //                uint SelfAsInt = self.DecimalStatus;
    //                SelfAsInt += (uint)(self.intValue * 10000);
    //                SelfAsInt *= y.intValue;
    //                self.intValue = (ushort)(SelfAsInt / 1000);
    //                SelfAsInt -= (uint)(self.intValue * 10000);
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            else
    //            {
    //                ulong SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                uint YAsInt = y.intValue;
    //                YAsInt *= 10000;
    //                YAsInt += y.DecimalStatus;
    //                SelfAsInt *= YAsInt;
    //                SelfAsInt /= 10000;
    //                ulong TempStorage = SelfAsInt / 10000;
    //                self.intValue = (ushort)TempStorage;
    //                TempStorage = self.intValue;
    //                TempStorage *= 10000;
    //                SelfAsInt -= TempStorage;
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //            if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //        }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator /(SmallDec self, SmallDec y)
    //    {
    //        if (y.intValue == 0 && y.DecimalStatus == 0)
    //        {
    //            Console.WriteLine("Prevented dividing by zero");
    //        }
    //        else
    //        {
    //            if (y.DecBoolStatus == 1) { self.SwapNegativeStatus(); }
    //            if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
    //            {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                self.intValue /= y.intValue;
    //            }
    //            else if (y.DecimalStatus == 0)
    //            {
    //                uint SelfAsInt = self.DecimalStatus;
    //                SelfAsInt += (uint)(self.intValue * 10000);
    //                SelfAsInt /= y.intValue;
    //                self.intValue = (ushort)(SelfAsInt / 1000);
    //                SelfAsInt -= (uint)(self.intValue * 10000);
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            else
    //            {
    //                ulong SelfAsInt = self.intValue;
    //                SelfAsInt *= 10000;
    //                SelfAsInt += self.DecimalStatus;
    //                uint YAsInt = y.intValue;
    //                YAsInt *= 10000;
    //                YAsInt += y.DecimalStatus;
    //                SelfAsInt /= YAsInt;
    //                SelfAsInt /= 10000;
    //                ulong TempStorage = SelfAsInt / 10000;
    //                self.intValue = (ushort)TempStorage;
    //                TempStorage = self.intValue;
    //                TempStorage *= 10000;
    //                SelfAsInt -= TempStorage;
    //                self.DecimalStatus = (ushort)SelfAsInt;
    //            }
    //            //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //            if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //        }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator %(SmallDec self, dynamic y)
    //    {
    //        if (y is double || y is float || y is decimal)
    //        {
    //            if (y == 0.0)
    //            {
    //                self.intValue = 0;
    //                self.DecimalStatus = 0;
    //                self.DecBoolStatus = 0;
    //            }
    //            else
    //            {
    //                if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
    //                ushort WholeHalf = (ushort)y;
    //                //Use x Int Operation instead if y has no decimal places
    //                if (WholeHalf == y)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        //Use normal simple (int value) * (int value) if not dealing with any decimals
    //                        self.intValue %= WholeHalf;
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        SelfAsInt %= WholeHalf;
    //                        self.intValue = (ushort)(SelfAsInt / 1000);
    //                        SelfAsInt -= (uint)(self.intValue * 10000);
    //                        self.DecimalStatus = (ushort)SelfAsInt;
    //                    }
    //                }
    //                else
    //                {
    //                    y -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (y == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (y == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(y);
    //                    }
    //                    ulong SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    ulong YAsInt = WholeHalf;
    //                    YAsInt *= 10000;
    //                    YAsInt += Decimalhalf;
    //                    SelfAsInt %= YAsInt;
    //                    SelfAsInt /= 10000;
    //                    ulong TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage = self.intValue;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        else if (y is string)
    //        {
    //            self %= (SmallDec)y;
    //        }
    //        else
    //        {
    //            if (y == 0)
    //            {
    //                self.intValue = 0;
    //                self.DecimalStatus = 0;
    //                self.DecBoolStatus = 0;
    //            }
    //            else
    //            {
    //                if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
    //                if (self.DecimalStatus == 0)
    //                {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                    self.intValue %= (ushort)y;
    //                }
    //                else
    //                {
    //                    uint SelfAsInt = self.DecimalStatus;
    //                    SelfAsInt += (uint)(self.intValue * 10000);
    //                    SelfAsInt %= y;
    //                    uint TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator +(SmallDec self, dynamic y)
    //    {
    //        if (y is double || y is SmallDec || y is decimal)
    //        {
    //            bool IsYNegative = (y < 0) ? true : false;
    //            y = Math.Abs(y);
    //            ushort WholeHalfOfY = (ushort)Math.Floor(y);
    //            y -= WholeHalfOfY;
    //            if (WholeHalfOfY == 0) { }
    //            else if (self.DecBoolStatus == 1 && IsYNegative)
    //            {// -X - Y (ex. -8 + -6)
    //                self.intValue = (ushort)(self.intValue + WholeHalfOfY);
    //            }
    //            else if (self.DecBoolStatus == 0 && IsYNegative == false)
    //            {
    //                //X + Y (ex. 8 + 6)
    //                self.intValue = (ushort)(self.intValue + WholeHalfOfY);
    //            }
    //            else
    //            {
    //                // -X + Y
    //                if (self.DecBoolStatus == 1)
    //                {   //ex. -8 + 9
    //                    if (y > self.intValue)
    //                    {
    //                        self.intValue = (ushort)(WholeHalfOfY - self.intValue);
    //                        self.DecBoolStatus = 0;
    //                    }
    //                    else
    //                    {//ex. -8 +  4
    //                        self.intValue = (ushort)(self.intValue - WholeHalfOfY);
    //                    }
    //                }// X-Y
    //                else
    //                {
    //                    if (self.intValue > WholeHalfOfY)
    //                    {//ex. 9 + -6
    //                        self.intValue = (ushort)(self.intValue - WholeHalfOfY);
    //                    }
    //                    else
    //                    {//ex. 9 + -10
    //                        self.intValue = (ushort)(WholeHalfOfY - self.intValue);
    //                        self.DecBoolStatus = 1;
    //                    }
    //                }
    //            }
    //            //Decimal Calculation Section
    //            if (self.DecBoolStatus != 0 || y != 0)
    //            {
    //                ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
    //                // ?.XXXXXX + ?.YYYYYY
    //                if (self.DecBoolStatus == 0 && IsYNegative == false)
    //                {
    //                    //Potential Overflow check
    //                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
    //                    if (DecimalStatusTemp > 9999)
    //                    {
    //                        DecimalStatusTemp -= 10000;
    //                        self.intValue += 1;
    //                    }
    //                    self.DecimalStatus = DecimalStatusTemp;
    //                }
    //                // -?.XXXXXX - ?.YYYYYY
    //                else if (self.DecBoolStatus == 1 && IsYNegative == true)
    //                {
    //                    //Potential Overflow check
    //                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
    //                    if (DecimalStatusTemp > 9999)
    //                    {
    //                        DecimalStatusTemp -= 10000;
    //                        self.intValue += 1;
    //                    }
    //                    self.DecimalStatus = DecimalStatusTemp;
    //                }
    //                else
    //                {
    //                    if (IsYNegative)
    //                    {
    //                        // ex. 0.6 + -0.5
    //                        if (self.DecimalStatus >= SecondDec)
    //                        {
    //                            self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
    //                        }// ex. 0.6 + -.7
    //                        else
    //                        {
    //                            self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
    //                            if (self.intValue == 0)
    //                            {
    //                                self.DecBoolStatus = 1;
    //                            }
    //                            else
    //                            {
    //                                self.intValue -= 1;
    //                            }
    //                        }
    //                    }
    //                    else
    //                    {
    //                        if (self.DecimalStatus >= SecondDec)
    //                        {
    //                            self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
    //                        }// ex. -1.6 + 0.7
    //                        else
    //                        {
    //                            self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
    //                            if (self.intValue == 0)
    //                            {
    //                                self.DecBoolStatus = 0;
    //                            }
    //                            else
    //                            {
    //                                self.intValue -= 1;
    //                            }
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //        else if (y is string)
    //        {
    //            self += (SmallDec)y;
    //        }
    //        else
    //        {
    //            if (self.DecBoolStatus == 1 && y < 0)
    //            {// -X - Y (ex. -8 + -6)
    //                self.intValue = (ushort)(self.intValue + (ushort)Math.Abs(y));
    //            }
    //            else if (self.DecBoolStatus == 0 && y >= 0)
    //            {
    //                //X + Y (ex. 8 + 6)
    //                self.intValue = (ushort)(self.intValue + y);
    //            }
    //            else
    //            {
    //                // -X + Y
    //                if (self.DecBoolStatus == 1)
    //                {   //ex. -8 + 9
    //                    if (y > self.intValue)
    //                    {
    //                        self.intValue = (ushort)(y - self.intValue);
    //                        self.DecBoolStatus = 0;
    //                    }
    //                    else
    //                    {//ex. -8 +  4
    //                        self.intValue = (ushort)(self.intValue - y);
    //                    }
    //                }// X-Y
    //                else
    //                {
    //                    ushort TempY = Math.Abs(y);
    //                    if (self.intValue > TempY)
    //                    {//ex. 9 + -6
    //                        self.intValue = (ushort)(self.intValue - TempY);
    //                    }
    //                    else
    //                    {//ex. 9 + -10
    //                        self.intValue = (ushort)(TempY - self.intValue);
    //                        self.DecBoolStatus = 1;
    //                    }
    //                }
    //            }
    //        }
    //        //Fix potential negative zero
    //        if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator -(SmallDec self, dynamic y)
    //    {
    //        if (y is double || y is SmallDec || y is decimal)
    //        {
    //            bool IsYNegative = (y < 0.0) ? true : false;
    //            y = Math.Abs(y);
    //            ushort WholeHalfOfY = (ushort)(Math.Floor(y));
    //            y -= WholeHalfOfY;
    //            if (WholeHalfOfY == 0) { }
    //            //ex. -9 - 9
    //            else if (self.DecBoolStatus == 1 && IsYNegative == false)
    //            {// -X - Y
    //                self.intValue = (ushort)(self.intValue + WholeHalfOfY);
    //            }//ex. 9 - (-1)
    //            else if (self.DecBoolStatus == 0 && IsYNegative)
    //            {
    //                //X - (-Y)
    //                self.intValue = (ushort)(self.intValue + WholeHalfOfY);
    //            }
    //            else
    //            {
    //                // X - (Y)
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    // ex. 8 - 9
    //                    if (WholeHalfOfY > self.intValue)
    //                    {
    //                        self.intValue = (ushort)(WholeHalfOfY - self.intValue);
    //                        self.DecBoolStatus = 1;
    //                    } //ex. 8 - 7
    //                    else
    //                    {
    //                        self.intValue = (ushort)(self.intValue - WholeHalfOfY);
    //                    }
    //                }// -X - (Y)
    //                else
    //                {
    //                    // ex. -8 - (-9)
    //                    if (self.intValue > WholeHalfOfY)
    //                    {
    //                        self.intValue = (ushort)(WholeHalfOfY - self.intValue);
    //                        self.DecBoolStatus = 0;
    //                    }
    //                    else
    //                    {//ex. -8 - (-5)
    //                        self.intValue = (ushort)(self.intValue - WholeHalfOfY);
    //                    }
    //                }
    //            }
    //            //Decimal Calculation Section
    //            ushort SecondDec = (ushort)((System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000);
    //            if (self.DecimalStatus != 0 || SecondDec != 0)
    //            {
    //                // ex. -0.5 - 0.6
    //                if (self.DecBoolStatus == 1 && IsYNegative == false)
    //                {
    //                    //Potential Overflow check
    //                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
    //                    if (DecimalStatusTemp > 9999)
    //                    {
    //                        DecimalStatusTemp -= 10000;
    //                        self.intValue += 1;
    //                    }
    //                    self.DecimalStatus = DecimalStatusTemp;
    //                }// ex. 0.5 - (-0.6)
    //                else if (self.DecBoolStatus == 0 && IsYNegative)
    //                {
    //                    //Potential Overflow check
    //                    ushort DecimalStatusTemp = (ushort)(self.DecimalStatus + SecondDec);
    //                    if (DecimalStatusTemp > 9999)
    //                    {
    //                        DecimalStatusTemp -= 10000;
    //                        self.intValue += 1;
    //                    }
    //                    self.DecimalStatus = DecimalStatusTemp;
    //                }
    //                else
    //                {
    //                    if (IsYNegative)
    //                    {// ex. -0.7 - (-0.6)
    //                        if (self.DecimalStatus >= SecondDec)
    //                        {
    //                            self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
    //                        }
    //                        else
    //                        {
    //                            self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
    //                            if (self.intValue == 0)
    //                            {
    //                                self.DecBoolStatus = 0;
    //                            }
    //                            else
    //                            {
    //                                self.intValue -= 1;
    //                            }
    //                        }
    //                    }
    //                    else
    //                    { //ex  0.6 - 0.5
    //                        if (self.DecimalStatus >= SecondDec)
    //                        {
    //                            self.DecimalStatus = (ushort)(self.DecimalStatus - SecondDec);
    //                        }
    //                        else
    //                        {
    //                            self.DecimalStatus = (ushort)(SecondDec - self.DecimalStatus);
    //                            if (self.intValue == 0)
    //                            {
    //                                self.DecBoolStatus = 1;
    //                            }
    //                            else
    //                            {
    //                                self.intValue -= 1;
    //                            }
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //        else if (y is string)
    //        {
    //            self -= (SmallDec)y;
    //        }
    //        else
    //        {
    //            //ex. -9 - 9
    //            if (self.DecBoolStatus == 1 && y >= 0)
    //            {// -X - Y
    //                self.intValue = (ushort)(self.intValue + y);
    //            }//ex. 9 - (-1)
    //            else if (self.DecBoolStatus == 0 && y < 0)
    //            {
    //                //X - (-Y)
    //                self.intValue = (ushort)(self.intValue + Math.Abs(y));
    //            }
    //            else
    //            {
    //                // X - (Y)
    //                if (self.DecBoolStatus == 0)
    //                {
    //                    // ex. 8 - 9
    //                    if (y > self.intValue)
    //                    {
    //                        self.intValue = (ushort)(y - self.intValue);
    //                        self.DecBoolStatus = 1;
    //                    } //ex. 8 - 7
    //                    else
    //                    {
    //                        self.intValue = (ushort)(self.intValue - y);
    //                    }
    //                }// -X - (Y)
    //                else
    //                {
    //                    ushort TempY = Math.Abs(y);
    //                    // ex. -8 - (-9)
    //                    if (self.intValue > TempY)
    //                    {
    //                        self.intValue = (ushort)(TempY - self.intValue);
    //                        self.DecBoolStatus = 0;
    //                    }
    //                    else
    //                    {//ex. -8 - (-5)
    //                        self.intValue = (ushort)(self.intValue - TempY);
    //                    }
    //                }
    //            }
    //        }
    //        //Fix potential negative zero
    //        if (self.intValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator *(SmallDec self, dynamic y)
    //    {
    //        if (y is double || y is SmallDec || y is decimal)
    //        {
    //            if (y == 0.0)
    //            {
    //                self.intValue = 0;
    //                self.DecimalStatus = 0;
    //                self.DecBoolStatus = 0;
    //            }
    //            else
    //            {
    //                if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
    //                ushort WholeHalf = (ushort)Math.Floor(y);
    //                //Use x Int Operation instead if y has no decimal places
    //                if (WholeHalf == y)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        //Use normal simple (int value) * (int value) if not dealing with any decimals
    //                        self.intValue *= WholeHalf;
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        SelfAsInt *= WholeHalf;
    //                        self.intValue = (ushort)(SelfAsInt / 1000);
    //                        SelfAsInt -= (uint)(self.intValue * 10000);
    //                        self.DecimalStatus = (ushort)SelfAsInt;
    //                    }
    //                }
    //                else
    //                {
    //                    y -= WholeHalf;
    //                    ushort Decimalhalf;
    //                    if (y == 0.25)
    //                    {
    //                        Decimalhalf = 2500;
    //                    }
    //                    else if (y == 0.5)
    //                    {
    //                        Decimalhalf = 5000;
    //                    }
    //                    else
    //                    {
    //                        Decimalhalf = ExtractDecimalHalfV3(y);
    //                    }
    //                    ulong SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint YAsInt = WholeHalf;
    //                    YAsInt *= 10000;
    //                    YAsInt += Decimalhalf;
    //                    SelfAsInt *= YAsInt;
    //                    SelfAsInt /= 10000;
    //                    ulong TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage = self.intValue;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        else if (y is string)
    //        {
    //            self *= (SmallDec)y;
    //        }
    //        else
    //        {
    //            if (y == 0)
    //            {
    //                self.intValue = 0;
    //                self.DecimalStatus = 0;
    //                self.DecBoolStatus = 0;
    //            }
    //            else
    //            {
    //                if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
    //                if (self.DecimalStatus == 0)
    //                {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                    self.intValue *= y;
    //                }
    //                else
    //                {
    //                    uint SelfAsInt = self.DecimalStatus;
    //                    SelfAsInt += (uint)(self.intValue * 10000);
    //                    SelfAsInt *= y;
    //                    uint TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        return self;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="self"></param>
    //    /// <param name="y"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator /(SmallDec self, dynamic y)
    //    {
    //        if (y is double || y is SmallDec || y is decimal)
    //        {
    //            if (y == 0)
    //            {
    //                Console.WriteLine("Prevented dividing by zero");
    //            }
    //            else
    //            {
    //                if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
    //                ushort WholeHalf = (ushort)Math.Floor(y);
    //                //Use x Int Operation instead if y has no decimal places
    //                if (WholeHalf == y)
    //                {
    //                    if (self.DecimalStatus == 0)
    //                    {
    //                        //Use normal simple (int value) * (int value) if not dealing with any decimals
    //                        self.intValue /= WholeHalf;
    //                    }
    //                    else
    //                    {
    //                        uint SelfAsInt = self.DecimalStatus;
    //                        SelfAsInt += (uint)(self.intValue * 10000);
    //                        SelfAsInt /= WholeHalf;
    //                        self.intValue = (ushort)(SelfAsInt / 1000);
    //                        SelfAsInt -= (uint)(self.intValue * 10000);
    //                        self.DecimalStatus = (ushort)SelfAsInt;
    //                    }
    //                }
    //                else
    //                {
    //                    y -= WholeHalf;
    //                    ushort Decimalhalf = ExtractDecimalHalfV3(y);
    //                    ulong SelfAsInt = self.intValue;
    //                    SelfAsInt *= 10000;
    //                    SelfAsInt += self.DecimalStatus;
    //                    uint YAsInt = WholeHalf;
    //                    YAsInt *= 10000;
    //                    YAsInt += Decimalhalf;
    //                    SelfAsInt /= YAsInt;
    //                    SelfAsInt /= 10000;
    //                    ulong TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage = self.intValue;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        else if (y is string)
    //        {
    //            self /= (SmallDec)y;
    //        }
    //        else
    //        {
    //            if (y == 0)
    //            {
    //                Console.WriteLine("Prevented dividing by zero");
    //            }
    //            else
    //            {
    //                if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
    //                if (self.DecimalStatus == 0)
    //                {//Use normal simple (int value) * (int value) if not dealing with any decimals
    //                    self.intValue /= (ushort)y;
    //                }
    //                else
    //                {
    //                    uint SelfAsInt = self.DecimalStatus;
    //                    SelfAsInt += (uint)(self.intValue * 10000);
    //                    SelfAsInt /= y;
    //                    uint TempStorage = SelfAsInt / 10000;
    //                    self.intValue = (ushort)TempStorage;
    //                    TempStorage *= 10000;
    //                    SelfAsInt -= TempStorage;
    //                    self.DecimalStatus = (ushort)SelfAsInt;
    //                }
    //                //Prevent dividing/multiplying value into nothing by dividing too small (set to .0001 instead of having value set as zero)
    //                if (self.intValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
    //            }
    //        }
    //        return self;
    //    }

    //    //Right side applications
    //    /// <summary>
    //    /// </summary>
    //    /// <param name="y"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator -(dynamic y, SmallDec self)
    //    {
    //        SmallDec YAsSuperDec = (SmallDec)y;
    //        YAsSuperDec -= self;
    //        return YAsSuperDec;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="y"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator +(dynamic y, SmallDec self)
    //    {
    //        SmallDec YAsSuperDec = (SmallDec)y;
    //        YAsSuperDec += self;
    //        return YAsSuperDec;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="y"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator *(dynamic y, SmallDec self)
    //    {
    //        SmallDec YAsSuperDec = (SmallDec)y;
    //        YAsSuperDec *= self;
    //        return YAsSuperDec;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="y"></param>
    //    /// <param name="self"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator /(dynamic y, SmallDec self)
    //    {
    //        SmallDec YAsSuperDec = (SmallDec)y;
    //        YAsSuperDec /= self;
    //        return YAsSuperDec;
    //    }

    //    /// <summary>
    //    /// </summary>
    //    /// <param name="Value"></param>
    //    /// <returns></returns>
    //    public static SmallDec operator -(SmallDec Value)
    //    {//Place DecBoolStatus>1 checks above in V2 of type
    //        if (Value.DecBoolStatus % 2 == 1)//ODD
    //        {
    //            Value.DecBoolStatus -= 1;
    //        }
    //        else
    //        {
    //            Value.DecBoolStatus += 1;
    //        }
    //        return Value;
    //    }
    }
}