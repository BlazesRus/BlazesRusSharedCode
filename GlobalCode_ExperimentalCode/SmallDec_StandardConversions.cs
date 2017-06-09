/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS0436 // Type conflicts with imported type
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
    //Aka SuperDec_Int16_4Decimal
    public
#if (BlazesGlobalCode_SmallDec_AsClass)
    sealed
#endif
    partial
#if (BlazesGlobalCode_SmallDec_AsClass)
    class
#else
    struct
#endif
    SmallDec : IComparable<SmallDec>, IConvertible, IEquatable<SmallDec>
#if (!SmallDec_DisableCustomTypeDescriptor)
    , ICustomTypeDescriptor
#endif
    {
        /// <summary>
        /// Display string with empty decimal places removed
        /// </summary>
        /// <returns></returns>
        public string ToOptimalString()
        {
            //string Value = "";
            var builder = new System.Text.StringBuilder("");
            ushort IntegerHalf = intValue;
            byte CurrentDigit;
            if (DecBoolStatus == 1)
            {
                //Value += "-";
                builder.Append("-");
            }

            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                //Value += DigitAsChar(CurrentDigit);
                builder.Append(DigitAsChar(CurrentDigit));
            }
            ushort DecimalHalf = DecimalStatus;
            if (DecimalStatus != 0)
            {
                //Value += ".";
                builder.Append(".");
                for (sbyte Index = 3; Index >= 0; Index--)
                {
                    if (DecimalStatus != 0)
                    {
                        CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
                        DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                        //Value += DigitAsChar(CurrentDigit);
                        builder.Append(DigitAsChar(CurrentDigit));
                    }
                }
            }
            //return Value;
            return builder.ToString();
        }

        /// <summary>
        /// Display string with empty decimal places show
        /// </summary>
        /// <returns></returns>
        public string ToFullString()
        {
            string Value = "";
            ushort IntegerHalf = intValue;
            byte CurrentDigit;
            if (DecBoolStatus == 1) { Value += "-"; }
            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                Value += DigitAsChar(CurrentDigit);
            }
            Value += ".";
            if (DecimalStatus != 0)
            {
                ushort DecimalHalf = DecimalStatus;
                for (sbyte Index = 3; Index >= 0; Index--)
                {
                    CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
                    DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                    Value += DigitAsChar(CurrentDigit);
                }
            }
            else
            {
                Value += "0000";
            }
            return Value;
        }


        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public string ToString(IFormatProvider provider)
        {
            return String.Format(provider, this.ToOptimalString());
        }

        /// <summary>
        /// Change variable to string with certain formating style
        /// </summary>
        /// <param name="FormatStyle"></param>
        /// <returns></returns>
        public string ToString(string FormatStyle)
        {
            return ToOptimalString();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override string ToString()
        {
            return ToOptimalString();
        }

        ///// <summary>
        ///// Change variable into string with certain formating style with culture info set
        ///// </summary>
        ///// <param name="FormatStyle"></param>
        ///// <param name="culture"></param>
        ///// <returns></returns>
        //public string ToString(string FormatStyle, CultureInfo culture)
        //{
        //    return String.Format(culture, this.ToOptimalString());//Ensure to reformat string based on culture
        //}

        /// <summary>
        /// 
        /// </summary>
        /// <param name="culture"></param>
        /// <returns></returns>
        public string ToString(CultureInfo culture)
        {
            return String.Format(culture, this.ToOptimalString());//Ensure to reformat string based on culture
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="numberFormat"></param>
        /// <returns></returns>
        public string ToString(NumberFormatInfo numberFormat)
        {
            return String.Format(numberFormat, this.ToOptimalString());//Ensure to reformat string based on format type
        }

        //From this type to Standard types

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator decimal(SmallDec self)
        {
            decimal Value = (decimal)self.intValue;
            Value += (decimal)(self.DecimalStatus * 0.0001);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// SmallDec to double explicit conversion
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator double(SmallDec self)
        {
            double Value = 0.0;
            Value += self.intValue;
            Value += (self.DecimalStatus * 0.0001);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator float(SmallDec self)
        {
            float Value = 0.0f;
            Value += self.intValue;
            Value += (float)(self.DecimalStatus * 0.0001);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator int(SmallDec self)
        {
            int Value = (int)self.intValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator long(SmallDec self)
        {
            long Value = self.intValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator uint(SmallDec self)
        {
            return self.intValue;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ulong(SmallDec self)
        {
            return self.intValue;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator byte(SmallDec self)
        {
            byte Value = (byte)self.intValue;
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator sbyte(SmallDec self)
        {
            sbyte Value = (sbyte)self.intValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ushort(SmallDec self)
        {
            ushort Value = (ushort)self.intValue;
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator short(SmallDec self)
        {
            short Value = (short)self.intValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        static public explicit operator string(SmallDec self) => self.ToOptimalString();

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator bool(SmallDec self)
        {
            return (int)self == 1;
        }

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <param name="self"></param>
        //static public explicit operator dynamic(SmallDec self) => SmallDec.Initialize(self);

        //From Standard types to this type 
#if (BlazesGlobalCode_StandardExplicitConversionFrom)
        public static explicit operator SmallDec(decimal Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(double Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(SmallDec Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(int Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(uint Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(long Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(ulong Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(ushort Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(short Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(sbyte Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(byte Value)	{	return new SmallDec(Value);	}

        public static explicit operator SmallDec(string Value) { return new SmallDec(Value); }

        public static explicit operator SmallDec(DependencyProperty Value)
        {
            SmallDec NewValue = Value.ToString();
            return NewValue;
        }
#else
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(decimal Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(double Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(float Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(int Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(uint Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(long Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(ulong Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(ushort Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(short Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(sbyte Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(byte Value) { return new SmallDec(Value); }

        /// <summary>
        /// String converted to SmallDec
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(string Value) { return new SmallDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator SmallDec(DependencyProperty Value)
        {
            //Type PropertyType = Value.PropertyType;
            SmallDec NewValue = Value.ToString();
            return NewValue;
        }
#endif
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(sbyte Value)
        {
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(short Value)
        {
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(int Value)
        {
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(byte Value)
        {
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
            this.DecBoolStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(ushort Value)
        {
            this.intValue = Value;
            this.decimalStatus = 0;
            this.DecBoolStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(uint Value)
        {
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
            this.DecBoolStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(ulong Value)
        {
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
            this.DecBoolStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(long Value)
        {
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(double Value)
        {
            if (Value < 0)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
            decimalStatus = (ushort)(Value * 10000);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(float Value)
        {
            if (Value < 0.0f)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
            decimalStatus = (ushort)(Value * 10000);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(decimal Value)
        {
            if (Value < 0.0M)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
            decimalStatus = (ushort)(Value * 10000);
        }

        /// <summary>
        /// Initialize constructor
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(string Value)
        {
            intValue = 0;
            decimalStatus = 0;
            DecBoolStatus = 0;
            sbyte PlaceNumber;
            //var StringLength = (byte)Value.Length;
            string WholeNumberBuffer = "";
            string DecimalBuffer = "";

            bool ReadingDecimal = false;
            int TempInt;
            int TempInt02;
            var Decimalbuilder = new System.Text.StringBuilder("");
            var WholeNumberbuilder = new System.Text.StringBuilder("");
            foreach (char StringChar in Value)
            {
                if (IsDigit(StringChar))
                {
                    if (ReadingDecimal)
                    {
                        Decimalbuilder.Append(StringChar);
                    }
                    else
                    {
                        WholeNumberbuilder.Append(StringChar);
                    }
                }
                else if (StringChar == '-')
                {
                    DecBoolStatus = 1;
                }
                else if (StringChar == '.')
                {
                    ReadingDecimal = true;
                }
            }
            WholeNumberBuffer = WholeNumberbuilder.ToString();
            DecimalBuffer = Decimalbuilder.ToString();
            PlaceNumber = (sbyte)(WholeNumberBuffer.Length - 1);
            foreach (char StringChar in WholeNumberBuffer)
            {
                TempInt = CharAsInt(StringChar);
                TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
                if (StringChar != '0')
                {
                    intValue += (ushort)TempInt02;
                }
                PlaceNumber--;
            }
            PlaceNumber = 3;
            foreach (char StringChar in DecimalBuffer)
            {
                //Limit stored decimal numbers to the amount it can store
                if (PlaceNumber > -1)
                {
                    TempInt = CharAsInt(StringChar);
                    TempInt02 = (ushort)(TempInt * Math.Pow(10, PlaceNumber));
                    if (StringChar != '0')
                    {
                        DecimalStatus += (ushort)TempInt02;
                    }
                    PlaceNumber--;
                }
            }
            //#if (DEBUG)
            //            PlaceNumber = 0;
            //#endif
        }

        /// <summary>
        /// Initialize constructor
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(DependencyProperty Value)
        {
            var NewValue = (SmallDec)Value;
            this.DecBoolStatus = NewValue.DecBoolStatus;
            this.intValue = NewValue.intValue;
            this.decimalStatus = NewValue.DecimalStatus;
        }

        /////// <summary>
        /////// 
        /////// </summary>
        /////// <param name="self"></param>
        /////// <param name="TargetProperty"></param>
        /////// <returns></returns>
        //public static void SetValueOfProperty(SmallDec self, ref DependencyProperty TargetProperty)
        //{
        //    SetValue(TargetProperty, self.ToString());
        //}
    }
}
