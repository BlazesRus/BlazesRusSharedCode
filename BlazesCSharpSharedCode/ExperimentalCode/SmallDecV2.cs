/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpSharedCode.ExperimentalCode.SmallDec
namespace CSharpSharedCode.ExperimentalCode
{
    using System.Collections.Generic;
    using System.Globalization;
    using System.Windows;
    using static VariableConversionFunctions.VariableConversionFunctions;

#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS3008 // Identifier is not CLS-compliant
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
    ////Reduced size version of SmallDec at cost of potential slightly more costly operation costs
    //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
    //#if (BlazesSharedCode_SmallDecV2_AsStruct)
    //    public partial class SmallDecV2 : IComparable<SmallDecV2>
    //#else
    //    public partial class SmallDecV2 : IComparable<SmallDecV2>
    //#endif
    //    {
    //#if (BlazesSharedCode_SmallDecV2_AsStruct)
    //        //Stores decimal section info (4 Decimal places stored)
    //        public short DecimalStatus;

    //        public ushort IntValue;
    //#else
    //        //Stores decimal section info (4 Decimal places stored)
    //        public short DecimalStatus = 0;

    //        public ushort IntValue = 0;
    //#endif

    //        public static SmallDecV2 Sum(IEnumerable<SmallDecV2> Value)
    //        {
    //            SmallDecV2 TotalSum = SmallDecV2.Zero;
    //            foreach (var Element in Value)
    //            {
    //                TotalSum += Element;
    //            }
    //            return TotalSum;
    //        }

    //        public static SmallDecV2 Parse(string value, CultureInfo invariantCulture)
    //        {
    //            SmallDecV2 NewValue = SmallDecV2.Initialize(value);
    //            return NewValue;
    //        }

    //        public static bool TryParse(string value, object SmallDecV2, CultureInfo invariantCulture, out SmallDecV2 f)
    //        {
    //            f = Parse(value, invariantCulture);
    //            return true;
    //        }

    ////        public static SmallDecV2 Pow(SmallDecV2 self, int Value)
    ////        {
    ////            SmallDecV2 NewSelf = self;
    ////            if (Value == 0)
    ////            {
    ////                NewSelf.IntValue = 1;
    ////                NewSelf.DecBoolStatus = 0;
    ////            }
    ////            else if (Value < 0)
    ////            {
    ////                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
    ////                {
    ////                    NewSelf /= self;
    ////                }
    ////            }
    ////            else
    ////            {
    ////                for (int NumberOfTimes = Value; NumberOfTimes > 0; --NumberOfTimes)
    ////                {
    ////                    NewSelf *= self;
    ////                }
    ////            }
    ////            return NewSelf;
    ////        }

    ////        //public static SmallDecV2 Pow(double self, double Value) { return SmallDecV2.Pow((SmallDecV2)self, (SmallDecV2)Value); }
    ////        public static SmallDecV2 Pow(SmallDecV2 self, double Value) { return SmallDecV2.Pow(self, (SmallDecV2)Value); }
    ////#if (BlazesSharedCode_StandardExplicitConversionFrom)//Gets confused since it tries auto converting to SmallDecV2 inside parameter first
    ////        public static SmallDecV2 Pow(SmallDecV2 self, SmallDecV2 Value) { return SmallDecV2.Pow(self, Value); }
    ////#endif
    ////        //Approximate version of Math.Pow(double self, double Value)
    ////        public static SmallDecV2 Pow(SmallDecV2 self, SmallDecV2 Value)
    ////        {
    ////            SmallDecV2 NewSelf = self;
    ////            //SmallDecV2 version of Math.Pow()
    ////            if (Value.DecimalStatus == 0)
    ////            {
    ////                if (Value.IntValue == 0)
    ////                {
    ////                    NewSelf.IntValue = 1;
    ////                    NewSelf.DecBoolStatus = 0;
    ////                }
    ////                else if (Value.DecBoolStatus == 0)
    ////                {
    ////                    for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
    ////                    {
    ////                        NewSelf *= self;
    ////                    }
    ////                }
    ////                else
    ////                {
    ////                    for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
    ////                    {
    ////                        NewSelf /= self;
    ////                    }
    ////                }
    ////            }
    ////            else
    ////            {//To-Do need to finish remaining power part of code
    ////             //decimal SelfAsDecimal = (decimal) self;
    ////                if (Value.IntValue == 0)
    ////                {
    ////                    NewSelf.IntValue = 1;
    ////                    NewSelf.DecBoolStatus = 0;
    ////                }
    ////                else if (Value.DecBoolStatus == 0)
    ////                {
    ////                    for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
    ////                    {
    ////                        NewSelf *= self;
    ////                    }
    ////                }
    ////                else
    ////                {
    ////                    for (ushort NumberOfTimes = Value.IntValue; NumberOfTimes > 0; --NumberOfTimes)
    ////                    {
    ////                        NewSelf /= self;
    ////                    }
    ////                }
    ////                //Now need to deal with the remaining "power"
    ////                Value.IntValue = 0;
    ////                //Number is less then NewSelf Currently is (Sloping Curve in closeness to next power)
    ////                double TempDouble = Math.Pow((double)self, (double)Value);
    ////                if (Value.DecBoolStatus == 0)
    ////                {
    ////                    NewSelf *= TempDouble;
    ////                }
    ////                else
    ////                {
    ////                    NewSelf /= TempDouble;
    ////                }
    ////            }
    ////            return NewSelf;
    ////        }

    ////        //SmallDecV2 version of Math.Exp(double Value)
    ////        public static SmallDecV2 Exp(SmallDecV2 Value)
    ////        {
    ////            double SelfAsDecimal = (double)Value;
    ////            SelfAsDecimal = Math.Exp(SelfAsDecimal);
    ////            return (SmallDecV2)SelfAsDecimal;
    ////        }

    //        public static SmallDecV2 Max(dynamic LeftSide, dynamic RightSide)
    //        {
    //            SmallDecV2 LeftSideAsType = (SmallDecV2)LeftSide;
    //            SmallDecV2 RightSideAsType = (SmallDecV2)RightSide;
    //            if (LeftSideAsType > RightSide) { return LeftSideAsType; }
    //            else { return RightSideAsType; }
    //        }

    //        public static SmallDecV2 Min(dynamic LeftSide, dynamic RightSide)
    //        {
    //            SmallDecV2 LeftSideAsType = (SmallDecV2)LeftSide;
    //            SmallDecV2 RightSideAsType = (SmallDecV2)RightSide;
    //            if (LeftSideAsType < RightSide) { return LeftSideAsType; }
    //            else { return RightSideAsType; }
    //        }

    //        //Method version to Initialize Type instead of with Explicit operators
    //        public static SmallDecV2 Initialize(dynamic Value)
    //        {
    //            return new SmallDecV2(Value);
    //        }

    //        //Initialize constructor
    //        public SmallDecV2(dynamic Value)
    //        {
    //            if (Value is DependencyProperty)
    //            {
    //                SmallDecV2 NewValue = (SmallDecV2)Value;
    //                this.IntValue = NewValue.IntValue;
    //                this.DecimalStatus = NewValue.DecimalStatus;
    //            }
    //            else if (Value is string)
    //            {
    //                IntValue = 0;
    //                DecimalStatus = 0;
    //                bool IsNegative = false;
    //                sbyte PlaceNumber;
    //                byte StringLength = (byte)Value.Length;
    //                string WholeNumberBuffer = "";
    //                string DecimalBuffer = "";
    //                bool ReadingDecimal = false;
    //                int TempInt;
    //                int TempInt02;
    //                foreach (char StringChar in Value)
    //                {
    //                    if (IsDigit(StringChar))
    //                    {
    //                        if (ReadingDecimal)
    //                        {
    //                            DecimalBuffer += StringChar;
    //                        }
    //                        else
    //                        {
    //                            WholeNumberBuffer += StringChar;
    //                        }
    //                    }
    //                    else if (StringChar == '-')
    //                    {
    //                        IsNegative = true;
    //                    }
    //                    else if (StringChar == '.')
    //                    {
    //                        ReadingDecimal = true;
    //                    }
    //                }
    //                PlaceNumber = (sbyte)(WholeNumberBuffer.Length - 1);
    //                foreach (char StringChar in WholeNumberBuffer)
    //                {
    //                    TempInt = CharAsInt(StringChar);
    //                    TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
    //                    if (StringChar != '0')
    //                    {
    //                        IntValue += (ushort)TempInt02;
    //                    }
    //                    PlaceNumber--;
    //                }
    //                PlaceNumber = 3;
    //                foreach (char StringChar in DecimalBuffer)
    //                {
    //                    //Limit stored decimal numbers to the amount it can store
    //                    if (PlaceNumber > -1)
    //                    {
    //                        TempInt = CharAsInt(StringChar);
    //                        TempInt02 = (short)(TempInt * Math.Pow(10, PlaceNumber));
    //                        if (StringChar != '0')
    //                        {
    //                            DecimalStatus += (short)TempInt02;
    //                        }
    //                        PlaceNumber--;
    //                    }
    //                }
    //            }
    //            //#if (!BlazesSharedCode_Disable128BitFeatures)
    //            //            else if (Value is MediumSuperDec)
    //            //            {
    //            //                IntValue = (ushort)Value.IntValue;
    //            //                uint TempDec = Value.DecimalStatus / 100000;
    //            //                DecimalStatus = (ushort)TempDec;
    //            //                DecBoolStatus = Value.DecBoolStatus;
    //            //            }
    //            //            else if (Value is ModerateSuperDec)
    //            //            {
    //            //                IntValue = (ushort)Value.IntValue;
    //            //                ulong TempDec = Value.DecimalStatus / 100000000000000;
    //            //                DecimalStatus = (ushort)TempDec;
    //            //                DecBoolStatus = Value.DecBoolStatus;
    //            //            }
    //            //            else if (Value is LargeSuperDec)
    //            //            {
    //            //                IntValue = (ushort)Value.IntValue;
    //            //                ulong TempDec = Value.DecimalStatus / 100000000000000;
    //            //                DecimalStatus = (ushort)TempDec;
    //            //                DecBoolStatus = Value.DecBoolStatus;
    //            //            }
    //            //#endif
    //            else if (Value is double || Value is float || Value is decimal)
    //            {
    //                bool IsNegative = false;
    //                if (Value < 0)
    //                {
    //                    Value *= -1;
    //                    IsNegative = true;
    //                }
    //                ulong WholeValue = (ulong)Math.Floor(Value);
    //                //Cap value if too big on initialize (preventing overflow on conversion)
    //                if (Value > 65535)
    //                {
    //                    Value = 65535;
    //                }
    //                Value -= WholeValue;
    //                IntValue = (ushort)WholeValue;
    //                DecimalStatus = (short)(Value * 10000);
    //                if (IsNegative) { DecimalStatus *= -1; }
    //            }
    //            //            else if (Value is byte ||Value is sbyte || Value is ushort || Value is short|| Value is int || Value is uint || Value is long|| Value is ulong)
    //            //            {
    //            //                if (Value < 0)
    //            //                {
    //            //                    this.DecBoolStatus = 1;
    //            //                    Value *= -1;
    //            //                }
    //            //                else
    //            //                {
    //            //                    this.DecBoolStatus = 0;
    //            //                }
    //            //                //Cap value if too big on initialize
    //            //                if (Value > 65535)
    //            //                {
    //            //                    Value = 65535;
    //            //                }
    //            //                this.DecBoolStatus = 0;
    //            //                this.IntValue = (ushort)Value;
    //            //                this.DecimalStatus = 0;
    //            //            }
    //            else if (Value is SmallDecV2)
    //            {
    //                this.IntValue = Value.IntValue;
    //                this.DecimalStatus = Value.DecimalStatus;
    //            }
    //            else if (Value is SmallDec)
    //            {
    //                this.IntValue = Value.IntValue;
    //                this.DecimalStatus = Value.DecimalStatus;
    //                if(Value.DecBoolStatus % 2==1)
    //                {
    //                    DecimalStatus *= -1;
    //                }
    //            }
    //            //            else
    //            //            {
    //            //                //Cap value if too big on initialize
    //            //                if (Value > 65535)
    //            //                {
    //            //                    Value = 65535;
    //            //                }
    //            //                this.DecBoolStatus = 0;
    //            //                this.IntValue = (ushort)Value;
    //            //                this.DecimalStatus = 0;
    //            //            }
    //        }

    //        //From this type to Standard types

    //        //public static explicit operator decimal(SmallDecV2 self)
    //        //{
    //        //    decimal Value = (decimal)self.IntValue;
    //        //    Value += (decimal)(self.DecimalStatus * 0.0001);
    //        //    if (self.DecBoolStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator double(SmallDecV2 self)
    //        //{
    //        //    double Value = 0.0;
    //        //    Value += self.IntValue;
    //        //    Value += (self.DecimalStatus * 0.0001);
    //        //    if (self.DecBoolStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator float(SmallDecV2 self)
    //        //{
    //        //    float Value = 0.0f;
    //        //    Value += self.IntValue;
    //        //    Value += (float)(self.DecimalStatus * 0.0001);
    //        //    if (self.DecBoolStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator int(SmallDecV2 self)
    //        //{
    //        //    int Value = (int)self.IntValue;
    //        //    if (self.DecimalStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator long(SmallDecV2 self)
    //        //{
    //        //    long Value = self.IntValue;
    //        //    if (self.DecimalStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator uint(SmallDecV2 self)
    //        //{
    //        //    return self.IntValue;
    //        //}

    //        //public static explicit operator ulong(SmallDecV2 self)
    //        //{
    //        //    return self.IntValue;
    //        //}

    //        //public static explicit operator byte(SmallDecV2 self)
    //        //{
    //        //    byte Value = (byte)self.IntValue;
    //        //    return Value;
    //        //}

    //        //public static explicit operator sbyte(SmallDecV2 self)
    //        //{
    //        //    sbyte Value = (sbyte)self.IntValue;
    //        //    if (self.DecimalStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        //public static explicit operator ushort(SmallDecV2 self)
    //        //{
    //        //    ushort Value = (ushort)self.IntValue;
    //        //    return Value;
    //        //}

    //        //public static explicit operator short(SmallDecV2 self)
    //        //{
    //        //    short Value = (short)self.IntValue;
    //        //    if (self.DecimalStatus == 1) { Value *= -1; }
    //        //    return Value;
    //        //}

    //        static public explicit operator string(SmallDecV2 self)
    //        {
    //            return self.ToOptimalString();
    //        }

    //        //From Standard types to this type 
    //#if (BlazesSharedCode_StandardExplicitConversionFrom)
    //        public static explicit operator SmallDecV2(decimal Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(double Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(SmallDecV2 Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(int Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(uint Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(long Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(ulong Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(ushort Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(short Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(sbyte Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(byte Value)	{	return new SmallDecV2(Value);	}

    //        public static explicit operator SmallDecV2(string Value) { return new SmallDecV2(Value); }

    //        public static explicit operator SmallDecV2(DependencyProperty Value)
    //        {
    //            SmallDecV2 NewValue = Value.ToString();
    //            return NewValue;
    //        }
    //#else
    //        public static implicit operator SmallDecV2(decimal Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(double Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(float Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(int Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(uint Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(long Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(ulong Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(ushort Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(short Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(sbyte Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(byte Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(string Value) { return new SmallDecV2(Value); }

    //        public static implicit operator SmallDecV2(DependencyProperty Value)
    //        {
    //            SmallDecV2 NewValue = Value.ToString();
    //            return NewValue;
    //        }
    //#endif
    //        public override bool Equals(object obj)
    //        {
    //            //Enable comparisons against other object types
    //            //if (obj == null || GetType() != obj.GetType()) { return false; }

    //            try
    //            {
    //                return this == (SmallDecV2)obj;
    //            }
    //            catch
    //            {
    //                return false;
    //            }
    //        }


    //        // Override the Object.GetHashCode() method:
    //        public override int GetHashCode()
    //        {
    //            if (DecimalStatus < 0)
    //            {
    //                return (int)IntValue*-1;
    //            }
    //            else
    //            {
    //                return (int)IntValue;
    //            }
    //        }

    //        //public ushort GetIntValue()
    //        //{
    //        //    return IntValue;
    //        //}

    //        //public int GetIntValueAsInt32()
    //        //{
    //        //    return (int)IntValue;
    //        //}

    //        public void SwapNegativeStatus()
    //        {
    //            DecimalStatus *= -1;
    //        }

    //        //Returns value of highest non-infinite/Special Decimal State Value that can store
    //        private static SmallDecV2 MaximumValue()
    //        {
    //#if (BlazesSharedCode_SmallDecV2_AsStruct)
    //            SmallDecV2 NewSelf;
    //            NewSelf.IntValue = 65535;
    //            NewSelf.DecimalStatus = 9999;
    //#else
    //            SmallDecV2 NewSelf = new SmallDecV2(65535, 9999);
    //#endif
    //            return NewSelf;
    //        }

    //        //Returns value of highest non-infinite/Special Decimal State Value that can store
    //        public static SmallDecV2 Maximum = MaximumValue();

    //        //Returns value of lowest non-infinite/Special Decimal State Value that can store
    //        private static SmallDecV2 MinimumValue()
    //        {
    //            SmallDecV2 NewSelf;
    //            NewSelf.IntValue = 65535;
    //            NewSelf.DecimalStatus = 9999;
    //            NewSelf.DecBoolStatus = 1;
    //            return NewSelf;
    //        }

    //        //Returns value of lowest non-infinite/Special Decimal State Value that can store
    //        public static readonly SmallDecV2 Minimum = MinimumValue();


    //        //public bool IsInfinity()
    //        //{
    //        //    //Negative Infinity
    //        //    if (DecBoolStatus == 255)
    //        //    { return true; }
    //        //    //Positive Infinity
    //        //    else if (DecBoolStatus == 254)
    //        //    { return true; }
    //        //    else { return false; }
    //        //}

    //        //Display string with empty decimal places removed
    //        public string ToOptimalString()
    //        {
    //            System.String Value = "";
    //            ushort IntegerHalf = IntValue;
    //            byte CurrentDigit;
    //            if (DecBoolStatus == 1) { Value += "-"; }
    //            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
    //            {
    //                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
    //                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
    //                Value += DigitAsChar(CurrentDigit);
    //            }
    //            ushort DecimalHalf = DecimalStatus;
    //            if (DecimalStatus != 0)
    //            {
    //                Value += ".";
    //                for (sbyte Index = 3; Index >= 0; Index--)
    //                {
    //                    if (DecimalStatus != 0)
    //                    {
    //                        CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
    //                        DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
    //                        Value += DigitAsChar(CurrentDigit);
    //                    }
    //                }
    //            }
    //            return Value;
    //        }

    //        //Display string with empty decimal places show
    //        public string ToFullString()
    //        {
    //            System.String Value = "";
    //            ushort IntegerHalf = IntValue;
    //            byte CurrentDigit;
    //            if (DecBoolStatus == 1) { Value += "-"; }
    //            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
    //            {
    //                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
    //                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
    //                Value += DigitAsChar(CurrentDigit);
    //            }
    //            Value += ".";
    //            ushort DecimalHalf = DecimalStatus;
    //            for (sbyte Index = 3; Index >= 0; Index--)
    //            {
    //                CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
    //                DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
    //                Value += DigitAsChar(CurrentDigit);
    //            }
    //            return Value;
    //        }


    //        public string ToString(string s, IFormatProvider provider)
    //        {
    //            return ToOptimalString();
    //        }

    //        public string ToString(string s)
    //        {
    //            return ToOptimalString();
    //        }

    //        public string ToString(CultureInfo invariantCulture)
    //        {
    //            return ToOptimalString();
    //        }

    //        public string ToString(NumberFormatInfo numberFormat)
    //        {
    //            return ToOptimalString();
    //        }

    //        public override string ToString() { return ToOptimalString(); }

    //        public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
    //        {
    //            if (Condition)
    //            {
    //                return X;
    //            }
    //            else
    //            {
    //                return Y;
    //            }
    //        }

    //        public dynamic DynamicConversion()
    //        {
    //            return this;
    //        }

    //        public static SmallDecV2 DynamicConversionFrom(dynamic Value)
    //        {
    //            SmallDecV2 NewSelf = (SmallDecV2)Value;
    //            return NewSelf;
    //        }

    //        public static SmallDecV2 SumOfList(SmallDecV2[] self)
    //        {
    //            SmallDecV2 Total = SmallDecV2.Zero;
    //            foreach (SmallDecV2 Element in self)
    //            {
    //                Total += Element;
    //            }
    //            return Total;
    //        }

    //        public static SmallDecV2 SumOfList(IEnumerable<SmallDecV2> self)
    //        {
    //            SmallDecV2 Total = SmallDecV2.Zero;
    //            foreach (SmallDecV2 Element in self)
    //            {
    //                Total += Element;
    //            }
    //            return Total;
    //        }

    //        public double AsDouble()
    //        {
    //            return (double)this;
    //        }

    //        public int AsInt()
    //        {
    //            return (int)this;
    //        }

    //        public string AsString()
    //        {
    //            return (string)this;
    //        }

    //        public bool IsNull()
    //        {
    //            if (DecimalStatus == 10002) { return true; }
    //            else { return false; }
    //        }

    //        private static SmallDecV2 ZeroValue()
    //        {
    //#if (BlazesSharedCode_SmallDecV2_AsStruct)
    //            SmallDecV2 NewSelf;
    //            NewSelf.IntValue = 0; NewSelf.DecimalStatus = 0; NewSelf.DecBoolStatus = 0;
    //            return NewSelf;
    //#else
    //            return new SmallDecV2(0, 0);
    //#endif
    //        }

    //        public static readonly SmallDecV2 Zero = ZeroValue();

    //        private static SmallDecV2 NaNValue()
    //        {
    //#if (BlazesSharedCode_SmallDecV2_AsStruct)
    //            SmallDecV2 NewSelf;
    //            NewSelf.IntValue = 0; 
    //#if (BlazesSharedCode_SmallDecV2_EnableSpecialDecStates)
    //            NewSelf.DecimalStatus = 10002;
    //#else
    //            NewSelf.DecimalStatus = 0;
    //#endif
    //            return NewSelf;
    //#else
    //#if (BlazesSharedCode_SmallDecV2_EnableSpecialDecStates)
    //            return new SmallDecV2(0, 10002);
    //#else
    //            return new SmallDecV2(0, 0);
    //#endif
    //#endif
    //        }

    //        public static readonly SmallDecV2 NaN = NaNValue();
    //        private int v;

    //        int IComparable<SmallDecV2>.CompareTo(SmallDecV2 other)
    //        {
    //            if (other == this)
    //            {
    //                return 0;
    //            }
    //            else if (this < other)
    //            {
    //                return -1;
    //            }
    //            else
    //            {
    //                return 1;
    //            }
    //        }

    //        public bool AlmostEquals(dynamic CompareTarget, dynamic RangeWithin)
    //        {
    //            SmallDecV2 ConvertedTarget = (SmallDecV2)CompareTarget;
    //            if (CompareTarget == this) { return true; }
    //            else
    //            {
    //                SmallDecV2 LeftRange = CompareTarget - RangeWithin;
    //                SmallDecV2 RightRange = CompareTarget + RangeWithin;
    //                if (this == LeftRange || this == RightRange) { return true; }
    //                else if (CompareTarget > LeftRange && CompareTarget < RightRange) { return true; }
    //                else { return false; }
    //            }
    //        }

    //        public int CompareTo(object other)
    //        {
    //            SmallDecV2 OtherAsSelfType = (SmallDecV2)other;
    //            if (OtherAsSelfType == this)
    //            {
    //                return 0;
    //            }
    //            else if (this < OtherAsSelfType)
    //            {
    //                return -1;
    //            }
    //            else
    //            {
    //                return 1;
    //            }
    //        }

    //        public int CompareTo(SmallDecV2 other)
    //        {
    //            if (other == this)
    //            {
    //                return 0;
    //            }
    //            else if (this < other)
    //            {
    //                return -1;
    //            }
    //            else
    //            {
    //                return 1;
    //            }
    //        }

    //#if (!BlazesSharedCode_SmallDecV2_AsStruct)
    //        public SmallDecV2(ushort parm1, short parm2)
    //        {
    //            IntValue = parm1;
    //            DecimalStatus = parm2;
    //        }
    //#endif
    //    }
}
