/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.ComponentModel;
    using System.Globalization;
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
#if (SmallDec_UseLegacyStorage)
            if (DecBoolStatus == 1)
            {
                //Value += "-";
                builder.Append("-");
            }
#else
            bool IsNegative = DecimalStatus < 0;
            if (IsNegative)
            {
                builder.Append("-");
            }
#endif

            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                //Value += DigitAsChar(CurrentDigit);
                builder.Append(DigitAsChar(CurrentDigit));
            }
#if (SmallDec_UseLegacyStorage)
            if (DecimalStatus != 0)
#else
            if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
#endif
            {
#if (SmallDec_UseLegacyStorage || SmallDec_ReducedSize)
                ushort DecimalHalf =
#if (SmallDec_ReducedSize)
                (ushort)
#endif
                DecimalStatus;
#else
                uint DecimalHalf = (uint)DecimalStatus;
#endif
                //Value += ".";
                builder.Append(".");
                for (sbyte Index = 3; Index >= 0; Index--)
                {
                    if (DecimalStatus != 0)
                    {
                        CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
#if (SmallDec_UseLegacyStorage || SmallDec_ReducedSize)
                        DecimalHalf -= (ushort)
#else
                        DecimalHalf -= (uint)
#endif
                        (CurrentDigit * Math.Pow(10, Index));
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
#if (SmallDec_UseLegacyStorage)
            if (DecBoolStatus == 1)
            {
                Value += "-";
            }
#else
            bool IsNegative = DecimalStatus < 0;
            if (IsNegative)
            {
                Value += "-";
            }
#endif
            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
                IntegerHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                Value += DigitAsChar(CurrentDigit);
            }
#if (SmallDec_UseLegacyStorage)
            if (DecimalStatus != 0)
#else
            if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
#endif
            {
                Value += ".";
#if (SmallDec_UseLegacyStorage || SmallDec_ReducedSize)
                ushort DecimalHalf =
#if (SmallDec_ReducedSize)
                (ushort)
#endif
                DecimalStatus;
#else
                uint DecimalHalf = (uint)DecimalStatus;
#endif
                for (sbyte Index = 3; Index >= 0; Index--)
                {
                    CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
                    DecimalHalf -= (ushort)(CurrentDigit * Math.Pow(10, Index));
                    Value += DigitAsChar(CurrentDigit);
                }
            }
            else
            {
#if (SmallDec_UseLegacyStorage || SmallDec_ReducedSize)
                Value += ".0000";
#else
                Value += ".000000000";
#endif
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

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(sbyte Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
#else
            if (Value < 0) { this.decimalStatus = NegativeWholeNumber; Value *= -1; }
#endif
            this.intValue = (ushort)Value;
#if (SmallDec_UseLegacyStorage)
            this.decimalStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(short Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
#else
            if (Value < 0) { this.decimalStatus = NegativeWholeNumber; Value *= -1; }
#endif
            this.intValue = (ushort)Value;
#if (SmallDec_UseLegacyStorage)
            this.decimalStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(int Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
#else
            if (Value < 0) { this.decimalStatus = NegativeWholeNumber; Value *= -1; }
#endif
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
#if (SmallDec_UseLegacyStorage)
            this.decimalStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(byte Value)
        {
            this.intValue = (ushort)Value;
            this.decimalStatus = 0;
#if (SmallDec_UseLegacyStorage)
            this.decimalStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(ushort Value)
        {
            this.intValue = Value;
            this.decimalStatus = 0;
#if (SmallDec_UseLegacyStorage)
            this.DecBoolStatus = 0;
#endif
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
#if (SmallDec_UseLegacyStorage)
            this.DecBoolStatus = 0;
#endif
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
#if (SmallDec_UseLegacyStorage)
            this.DecBoolStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(long Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0)
            {
                this.DecBoolStatus = 1;
                Value *= -1;
            }
            else
            {
                this.DecBoolStatus = 0;
            }
#else
            if (Value < 0) { this.decimalStatus = NegativeWholeNumber; Value *= -1; }
#endif
            //Cap value if too big on initialize
            if (Value > 65535)
            {
                Value = 65535;
            }
            this.intValue = (ushort)Value;
#if (SmallDec_UseLegacyStorage)
            this.decimalStatus = 0;
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(double Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
#else
            bool IsNegative = Value < 0;
            if (IsNegative) { Value *= -1.0; }
#endif
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
#if (SmallDec_UseLegacyStorage)
            decimalStatus = (ushort)(Value * 10000);
#elif (SmallDec_ReducedSize)
            decimalStatus = (short)(Value * 10000);
#else
            decimalStatus = (int)(Value * 10000000000);
#endif
#if (!SmallDec_UseLegacyStorage)
            if (IsNegative)
            {
                if (decimalStatus == 0)
                {
                    decimalStatus = NegativeWholeNumber;
                }
                else
                {
                    decimalStatus *= -1;
                }
            }
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(float Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0.0f)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
#else
            bool IsNegative = Value < 0;
            if (IsNegative) { Value *= -1.0f; }
#endif
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
#if (SmallDec_UseLegacyStorage)
            decimalStatus = (ushort)(Value * 10000);
#elif (SmallDec_ReducedSize)
            decimalStatus = (short)(Value * 10000);
#else
            decimalStatus = (int)(Value * 10000000000);
#endif
#if (!SmallDec_UseLegacyStorage)
            if (IsNegative)
            {
                if (decimalStatus == 0)
                {
                    decimalStatus = NegativeWholeNumber;
                }
                else
                {
                    decimalStatus *= -1;
                }
            }
#endif
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(decimal Value)
        {
#if (SmallDec_UseLegacyStorage)
            if (Value < 0.0M)
            {
                Value *= -1;
                DecBoolStatus = 1;
            }
            else
            {
                DecBoolStatus = 0;
            }
#else
            bool IsNegative = Value < 0;
            if (IsNegative) { Value *= -1.0m; }
#endif
            ulong WholeValue = (ulong)Math.Floor(Value);
            //Cap value if too big on initialize (preventing overflow on conversion)
            if (Value > 65535)
            {
                Value = 65535;
            }
            Value -= WholeValue;
            intValue = (ushort)WholeValue;
#if (SmallDec_UseLegacyStorage)
            decimalStatus = (ushort)(Value * 10000);
#elif (SmallDec_ReducedSize)
            decimalStatus = (short)(Value * 10000);
#else
            decimalStatus = (int)(Value * 10000000000);
#endif
#if (!SmallDec_UseLegacyStorage)
            if (IsNegative)
            {
                if (decimalStatus == 0)
                {
                    decimalStatus = NegativeWholeNumber;
                }
                else
                {
                    decimalStatus *= -1;
                }
            }
#endif
        }

        /// <summary>
        /// Initialize constructor
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(string Value)
        {
            intValue = 0;
            decimalStatus = 0;
#if (SmallDec_UseLegacyStorage)
            DecBoolStatus = 0;
#else
            bool IsNegative = false;
#endif
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
#if (SmallDec_UseLegacyStorage)
                    DecBoolStatus = 1;
#else
                    IsNegative = true;
#endif
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
#if (!SmallDec_UseLegacyStorage)
            if (IsNegative)
            {
                DecimalStatus *= -1;
            }
#endif
        }

#if (GlobalCode_EnableDependencyPropStuff)
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
#endif

#region From this type to Standard types

        /// <summary>
        ///
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator decimal(SmallDec self)
        {
            decimal Value = (decimal)self.IntValue;
#if (SmallDec_UseLegacyStorage)
            Value += (decimal)(self.DecimalStatus * 0.0001);
            if (self.DecBoolStatus == 1) { Value *= -1.0M; }
#else
            if(self.DecimalStatus<0)
            {
                if(self.DecimalStatus== NegativeWholeNumber)
                {
                    Value *= -1;
                }
                else
                {
                    self.DecimalStatus *= -1;
#if (SmallDec_ReducedSize)
                    Value += (decimal)(self.DecimalStatus * 0.0001M);
#else
                    Value += (decimal)(self.DecimalStatus * 0.000000001M);
#endif
                    Value *= -1.0M;
                }
            }
            else
            {
#if (SmallDec_ReducedSize)
                Value += (decimal)(self.DecimalStatus * 0.0001M);
#else
                Value += (decimal)(self.DecimalStatus * 0.000000001M);
#endif
            }
#endif
            return Value;
        }

        /// <summary>
        /// SmallDec to double explicit conversion
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator double(SmallDec self)
        {
            double Value = (double)self.IntValue;
#if (SmallDec_UseLegacyStorage)
            Value += (double)(self.DecimalStatus * 0.0001);
            if (self.DecBoolStatus == 1) { Value *= -1.0; }
#else
            if (self.DecimalStatus < 0)
            {
                if (self.DecimalStatus == NegativeWholeNumber)
                {
                    Value *= -1;
                }
                else
                {
                    self.DecimalStatus *= -1;
#if (SmallDec_ReducedSize)
                    Value += (double)(self.DecimalStatus * 0.0001);
#else
                    Value += (double)(self.DecimalStatus * 0.000000001);
#endif
                    Value *= -1.0;
                }
            }
            else
            {
#if (SmallDec_ReducedSize)
                Value += (double)(self.DecimalStatus * 0.0001);
#else
                Value += (double)(self.DecimalStatus * 0.000000001);
#endif
            }
#endif
            return Value;
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator float(SmallDec self)
        {
            float Value = (float)self.IntValue;
#if (SmallDec_UseLegacyStorage)
            Value += (float)(self.DecimalStatus * 0.0001f);
            if (self.DecBoolStatus == 1) { Value *= -1.0f; }
#else
            if (self.DecimalStatus < 0)
            {
                if (self.DecimalStatus == NegativeWholeNumber)
                {
                    Value *= -1;
                }
                else
                {
                    self.DecimalStatus *= -1;
#if (SmallDec_ReducedSize)
                    Value += (float)(self.DecimalStatus * 0.0001f);
#else
                    Value += (float)(self.DecimalStatus * 0.000000001f);
#endif
                    Value *= -1.0f;
                }
            }
            else
            {
#if (SmallDec_ReducedSize)
                Value += (float)(self.DecimalStatus * 0.0001f);
#else
                Value += (float)(self.DecimalStatus * 0.000000001f);
#endif
            }
#endif
            return Value;
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator int(SmallDec self)
        {
            int Value = (int)self.intValue;
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == 1) { Value *= -1; }
#else
            if (self.DecimalStatus < 0) { Value *= -1; }
#endif
            return Value;
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator long(SmallDec self)
        {
            long Value = self.intValue;
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == 1) { Value *= -1; }
#else
            if (self.DecimalStatus < 0) { Value *= -1; }
#endif
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
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == 1) { Value *= -1; }
#else
            if (self.DecimalStatus < 0) { Value *= -1; }
#endif
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
#if (SmallDec_UseLegacyStorage)
            if (self.DecBoolStatus == 1) { Value *= -1; }
#else
            if (self.DecimalStatus < 0) { Value *= -1; }
#endif
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

#endregion From this type to Standard types

        //From Standard types to this type
#if (!BlazesGlobalCode_ImplicitConversionFrom)

        public static explicit operator SmallDec(decimal Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(double Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(int Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(uint Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(long Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(ulong Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(ushort Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(short Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(sbyte Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(byte Value)
        {
            return new SmallDec(Value);
        }

        public static explicit operator SmallDec(string Value)
        {
            return new SmallDec(Value);
        }

#if (GlobalCode_EnableDependencyPropStuff)
        public static explicit operator SmallDec(System.Windows.DependencyProperty Value)
        {
            SmallDec NewValue = (SmallDec)Value.ToString();
            return NewValue;
        }
#endif
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

#if (GlobalCode_EnableDependencyPropStuff)
        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="Value"></param>
        //public static implicit operator SmallDec(DependencyProperty Value)
        //{
        //    //Type PropertyType = Value.PropertyType;
        //    SmallDec NewValue = Value.ToString();
        //    return NewValue;
        //}
#endif
#endif
    }
}