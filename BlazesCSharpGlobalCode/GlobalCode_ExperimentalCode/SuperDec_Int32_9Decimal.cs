/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
using System;

//Requires BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.SuperDec_Int32_9Decimal
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CS0436 // Type conflicts with imported type
    /// <summary>
    /// Represent +- 4294967295.999999999 with 100% consistency of accuracy
    /// (Aka SuperDec_Int32_9Decimal)
    /// </summary>
    public partial struct MediumSuperDec : IComparable<MediumSuperDec>
    {
        /// <summary>
        /// 0 = Positive;1=Negative;Other states at higher then 1;254 = Positive Infinity;255 = Negative Infinity
        /// </summary>
        public byte DecBoolStatus;

        /// <summary>
        /// Stores decimal section info (9 Decimal places stored)
        /// </summary>
        public uint DecimalStatus;

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        public uint IntValue;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static MediumSuperDec Sum(IEnumerable<MediumSuperDec> Value)
        {
            MediumSuperDec TotalSum = MediumSuperDec.Zero;
            foreach (var Element in Value)
            {
                TotalSum += Element;
            }
            return TotalSum;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public MediumSuperDec Abs()
        {
            this.DecBoolStatus = 0;
            return this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public MediumSuperDec Floor()
        {
            this.DecimalStatus = 0;
            return this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public MediumSuperDec Ceil()
        {
            if (this.DecimalStatus != 0)
            {
                this.DecimalStatus = 0;
                this.IntValue += 1;
            }
            return this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public MediumSuperDec Round()
        {
            if (DecimalStatus >= 500000000) { this.IntValue += 1; }
            this.DecimalStatus = 0;
            return this;
        }

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <param name="Value"></param>
        //public MediumSuperDec(SmallDec Value)
        //{
        //    IntValue = (uint)Value.IntValue;
        //    DecimalStatus = (uint)Value.DecimalStatus * 100000;
        //    DecBoolStatus = Value.DecBoolStatus;
        //}

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator MediumSuperDec(SmallDec self)
        {
            return new MediumSuperDec(self);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public MediumSuperDec(dynamic Value)
        {
            if (Value is double || Value is float|| Value is decimal)
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
                IntValue = (uint)System.Math.Floor(Value);
                Value -= IntValue;
                DecimalStatus = ExtractDecimalHalfV2(Value);
            }
            else if (Value is sbyte || Value is ushort || Value is int || Value is long)
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
                if (Value > 4294967295)
                {
                    Value = 4294967295;
                }
                this.DecBoolStatus = 0;
                this.IntValue = (uint)Value;
                this.DecimalStatus = 0;
            }
            else
            {
                //Cap value if too big on initialize
                if (Value > 4294967295)
                {
                    Value = 4294967295;
                }
                this.DecBoolStatus = 0;
                this.IntValue = (uint)Value;
                this.DecimalStatus = 0;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator decimal(MediumSuperDec self)
        {
            decimal Value = 0.0M;
            Value += self.IntValue;
            Value += (self.DecimalStatus * 0.000000001M);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// Explicit Conversion from this to double
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator double(MediumSuperDec self)
        {
            double Value = 0.0;
            Value += self.IntValue;
            Value += (self.DecimalStatus * 0.000000001);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator float(MediumSuperDec self)
        {
            float Value = 0.0f;
            Value += self.IntValue;
            Value += (float)(self.DecimalStatus * 0.000000001);
            if (self.DecBoolStatus == 1) { Value *= -1; }
            return Value;
        }

        //
        /// <summary>
        /// Conversion from this to int
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator int(MediumSuperDec self)
        {
            int Value = (int)self.IntValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// Conversion from this to int 64
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator long(MediumSuperDec self)
        {
            long Value = self.IntValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// Explicit Conversion from this to uint
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator uint(MediumSuperDec self)
        {
            return self.IntValue;
        }

        /// <summary>
        /// Explicit Conversion from this to unsigned int 64
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ulong(MediumSuperDec self)
        {
            return self.IntValue;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator byte(MediumSuperDec self)
        {
            byte Value = (byte)self.IntValue;
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator sbyte(MediumSuperDec self)
        {
            sbyte Value = (sbyte)self.IntValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ushort(MediumSuperDec self)
        {
            ushort Value = (ushort)self.IntValue;
            return Value;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator short(MediumSuperDec self)
        {
            short Value = (short)self.IntValue;
            if (self.DecimalStatus == 1) { Value *= -1; }
            return Value;
        }

        //public static ulong ForceConvertFromInt256(BigMath.Int256 Value)
        //{
        //	ulong ConvertedValue = 0;
        //	//Larger than ulong (default to zero)
        //	if (Value > 18446744073709551615)
        //	{
        //		Console.WriteLine("Overflow Detected");
        //	}
        //	else
        //	{
        //		BigMath.Int128 Value02 = (BigMath.Int128)Value;
        //		ConvertedValue = (ulong)Value02;
        //	}
        //	return ConvertedValue;
        //}

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        static public explicit operator string(MediumSuperDec self)
        {
            System.String Value = "";
            uint IntegerHalf = self.IntValue;
            byte CurrentDigit;
            if (self.DecBoolStatus == 1) { Value += "-"; }
            for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
            {
                CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
                IntegerHalf -= (uint)(CurrentDigit * Math.Pow(10, Index));
                Value += DigitAsChar(CurrentDigit);
            }
            Value += ".";
            uint DecimalHalf = self.DecimalStatus;
            for (sbyte Index = 8; Index >= 0; Index--)
            {
                CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
                DecimalHalf -= (uint)(CurrentDigit * Math.Pow(10, Index));
                Value += DigitAsChar(CurrentDigit);
            }
            return Value;
        }

        //From Standard types to this type 
#if (BlazesGlobalCode_StandardExplicitConversionFrom)
        public static explicit operator MediumSuperDec(decimal Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(double Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(MediumSuperDec Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(int Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(uint Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(long Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(ulong Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(ushort Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(short Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(sbyte Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(byte Value)	{	return new MediumSuperDec(Value);	}

        public static explicit operator MediumSuperDec(string Value) { return new MediumSuperDec(Value); }

        public static explicit operator MediumSuperDec(DependencyProperty Value)
        {
            MediumSuperDec NewValue = Value.ToString();
            return NewValue;
        }
#else
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(decimal Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(double Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(float Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(int Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(uint Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(long Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(ulong Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(ushort Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(short Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(sbyte Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(byte Value) { return new MediumSuperDec(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static implicit operator MediumSuperDec(string Value) { return new MediumSuperDec(Value); }

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <param name="Value"></param>
        //public static implicit operator MediumSuperDec(DependencyProperty Value)
        //{
        //    MediumSuperDec NewValue = Value.ToString();
        //    return NewValue;
        //}
#endif

        /// <summary>
        /// 
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public override bool Equals(object obj)
        {
            if (obj == null || GetType() != obj.GetType()) { return false; }

            try
            {
                return this == (MediumSuperDec)obj;
            }
            catch
            {
                return false;
            }
        }

        /// <summary>
        /// Override the Object.GetHashCode() method
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            if (DecBoolStatus == 1)
            {
                return (int)(IntValue / 2 - 2147483648);
            }
            else
            {
                return (int)(IntValue / 2);
            }
        }

        /// <summary>
        /// Negative Operator
        /// </summary>
        public void SwapNegativeStatus()
        {
            if (DecBoolStatus == 1) { DecBoolStatus = 0; }
            else { DecBoolStatus = 1; }
        }

        //Returns value of highest non-infinite/Special Decimal State Value that can store
        private static MediumSuperDec MaximumValue()
        {
            MediumSuperDec NewSelf;
            NewSelf.IntValue = 4294967295;
            NewSelf.DecimalStatus = 999999999;
            NewSelf.DecBoolStatus = 0;
            return NewSelf;
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static readonly MediumSuperDec Maximum = MaximumValue();

        //Returns value of lowest non-infinite/Special Decimal State Value that can store
        private static MediumSuperDec MinimumValue()
        {
            MediumSuperDec NewSelf; 
            NewSelf.IntValue = 4294967295;
            NewSelf.DecimalStatus = 999999999;
            NewSelf.DecBoolStatus = 1;
            return NewSelf;
        }

        /// <summary>
        /// Returns value of lowest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static readonly MediumSuperDec Minimum = MinimumValue();

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool IsInfinity()
        {
            return DecBoolStatus == 255 ? true : DecBoolStatus == 254 ? true : false;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="provider"></param>
        /// <returns></returns>
        public string ToString(string s, IFormatProvider provider)
        {
            //float SelfAsFloat = this;
            //string StringValue = SelfAsFloat.ToString(s, provider);
            //return StringValue;
            return (string)this;
        }

        internal string ToString(CultureInfo invariantCulture)
        {
            return (string)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Condition"></param>
        /// <param name="X"></param>
        /// <param name="Y"></param>
        /// <returns></returns>
        public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
        {
            return Condition ? X : Y;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public float AsFloat() { return (float)this; }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public double AsDouble() { return (double)this; }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public int AsInt() { return (int)IntValue; }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public string AsString() { return (string)this; }
        //public SmallDec AsSmallDec() { return (SmallDec)this; }

        private static MediumSuperDec ZeroValue()
        {
            MediumSuperDec NewSelf;
            NewSelf.IntValue = 0; NewSelf.DecimalStatus = 0; NewSelf.DecBoolStatus = 0;
            return NewSelf;
        }

        /// <summary>
        /// Value at zero
        /// </summary>
        public static readonly MediumSuperDec Zero = ZeroValue();

        private static MediumSuperDec NaNValue()
        {
            MediumSuperDec NewSelf;
            NewSelf.IntValue = 0; NewSelf.DecimalStatus = 0;
#if (BlazesGlobalCode_MediumSuperDec_EnableSpecialDecStates)
            NewSelf.DecBoolStatus = 202;
#else
            NewSelf.DecBoolStatus = 0;
#endif
            return NewSelf;
        }

        /// <summary>
        /// Value at zero or NaN (depends on preprocessor flags)
        /// </summary>
        public static readonly MediumSuperDec NaN = NaNValue();

        int IComparable<MediumSuperDec>.CompareTo(MediumSuperDec other)
        {
            if (other == this)
            {
                return 0;
            }
            else if (this < other)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="CompareTarget"></param>
        /// <param name="RangeWithin"></param>
        /// <returns></returns>
        public bool AlmostEquals(dynamic CompareTarget, dynamic RangeWithin)
        {
            var ConvertedTarget = (MediumSuperDec)CompareTarget;
            if (CompareTarget == this) { return true; }
            else
            {
                MediumSuperDec LeftRange = CompareTarget - RangeWithin;
                MediumSuperDec RightRange = CompareTarget + RangeWithin;
                return this == LeftRange || this == RightRange ? true : CompareTarget > LeftRange && CompareTarget < RightRange ? true : false;
            }
        }
    }
#pragma warning restore CC0001 // You should use 'var' whenever possible.
#pragma warning restore CC0105 // You should use 'var' whenever possible.
#pragma warning restore CS3001 // Argument type is not CLS-compliant
#pragma warning restore CS3002 // Return type is not CLS-compliant
#pragma warning restore CS3003 // Type is not CLS-compliant
}