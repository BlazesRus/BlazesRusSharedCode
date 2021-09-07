using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
#pragma warning disable CS0436 // Type conflicts with imported type
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
    /// <summary>
    /// Represents +- 8.999999999999999999 with 100% consistency of accuracy
    /// (Aka SuperDec_PercentValV2)
    /// </summary>
    public partial struct PercentValV2 : IComparable<PercentValV2>
    {
		private static PercentValV2 PIValue()
		{
			PercentValV2 NewSelf;
			NewSelf.ValueRep = 3141592653589793238;
			return NewSelf;
		}
		public static PercentValV2 PI = PIValue();
        /// <summary>
        /// Stores the value of both the decimal and whole number half
        /// </summary>
        public long ValueRep;

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static PercentValV2 Sum(IEnumerable<PercentValV2> Value)
        {
            PercentValV2 TotalSum = PercentValV2.Zero;
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
        public PercentValV2 Abs()
        {
            if(ValueRep<0)
            {
                ValueRep *= -1;
            }
            return this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public PercentValV2 Floor()
        {
            sbyte WholeHalf = (sbyte)(ValueRep/1000000000000000000);
            this.ValueRep = WholeHalf* 1000000000000000000;
            return this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="v"></param>
        public static explicit operator PercentValV2(string v)
        {
            throw new NotImplementedException();
        }

        //public static PercentValV2 Parse(string value, CultureInfo invariantCulture)
        //{
        //    PercentValV2 NewValue = PercentValV2.StringToValue(value);
        //    return NewValue;
        //}

        //// Returns rounded value with all fractional digits after specified precision cut off.
        //public static PercentValV2 Floor(PercentValV2 value, int precision)
        //{
        //    throw new NotImplementedException();
        //}

        //public PercentValV2 Ceil()
        //{
        //    throw new NotImplementedException();
        //}


        //public static PercentValV2 Pow(PercentValV2 self, int Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator PercentValV2(DependencyProperty v)
        //{
        //    throw new NotImplementedException();
        //}

        //public static PercentValV2 Pow(double self, double Value) { return PercentValV2.Pow((PercentValV2)self, (PercentValV2)Value); }
        //public static PercentValV2 Pow(PercentValV2 self, double Value) { return PercentValV2.Pow(self, (PercentValV2)Value); }
        //public static PercentValV2 Pow(PercentValV2 self, float Value) { return PercentValV2.Pow(self, (PercentValV2)Value); }

        ////Approximate version of Math.Pow(double self, double Value)
        //public static PercentValV2 Pow(PercentValV2 self, PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        ////PercentValV2 version of Math.Exp(double Value)
        //public static PercentValV2 Exp(PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static PercentValV2 Max(dynamic LeftSide, dynamic RightSide)
        //{
        //    PercentValV2 LeftSideAsType = (PercentValV2)LeftSide;
        //    PercentValV2 RightSideAsType = (PercentValV2)RightSide;
        //    if (LeftSideAsType > RightSide) { return LeftSideAsType; }
        //    else { return RightSideAsType; }
        //}

        //public static PercentValV2 Min(dynamic LeftSide, dynamic RightSide)
        //{
        //    PercentValV2 LeftSideAsType = (PercentValV2)LeftSide;
        //    PercentValV2 RightSideAsType = (PercentValV2)RightSide;
        //    if (LeftSideAsType < RightSide) { return LeftSideAsType; }
        //    else { return RightSideAsType; }
        //}

        //public static PercentValV2 Round(PercentValV2 val)
        //{
        //    return val.Round();
        //}

        //public static PercentValV2 Round(PercentValV2 value, int Precision)
        //{
        //    if (Precision == 0)
        //    {
        //        return value.Round();
        //    }
        //    else
        //    {
        //        return PercentValV2.Round(value, 1, MidpointRounding.AwayFromZero);
        //    }
        //}

        //public static PercentValV2 RoundHalfDownValue(PercentValV2 value, int precision)
        //{
        //    if (precision == 0)
        //    {
        //        return value.Floor();
        //    }
        //    else
        //    {
        //        return PercentValV2.Round(value, precision, 1);
        //    }
        //}

        //public PercentValV2 Round()
        //{
        //    throw new NotImplementedException();
        //}

        //public PercentValV2 RoundToNonZero()
        //{
        //    throw new NotImplementedException();
        //}

        //public static PercentValV2 Round(PercentValV2 value, int precision, int RoundingMethod)
        //{//https://en.wikipedia.org/wiki/Rounding
        //    throw new NotImplementedException();
        //}

        //public static PercentValV2 Round(PercentValV2 value, int precision, MidpointRounding RoundingMethod)
        //{
        //    if (RoundingMethod == MidpointRounding.ToEven) { return Round(value, precision, 0); }
        //    else if (RoundingMethod == MidpointRounding.AwayFromZero)
        //    {
        //        return Round(value, precision, 1);
        //    }
        //    else
        //    {
        //        return Round(value, precision, 2);
        //    }
        //}

        /// <summary>
        /// Negative Operator
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static PercentValV2 operator -(PercentValV2 Value)
        {
            Value.ValueRep *= -1;
            return Value;
        }

        //public static PercentValV2 StringToValue(string Value)
        //{
        //    throw new NotImplementedException();
        //}

        /// <summary>
        /// Method version to Initialize Type instead of with Explicit operators
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static PercentValV2 Initialize(dynamic Value)
        {
            return new PercentValV2(Value);
        }

        /// <summary>
        /// Initializer
        /// </summary>
        /// <param name="Value"></param>
        public PercentValV2(dynamic Value)
        {
            if (Value is string)
            {
                throw new NotImplementedException();
            }
            else if (Value is decimal||Value is double || Value is float)
            {
                ValueRep = (long)((Value)* 1000000000000000000);
            }
            else if (Value is SmallDec)
            {
                ValueRep = (long)Value.IntValue * 1000000000000000000;
            }
            else//if (Value is sbyte || Value is byte || Value is ushort || Value is int || Value is uint || Value is long|| Value is ulong)
            {
                ValueRep = (long)Value * 1000000000000000000;
            }
        }

        //From this type to Standard types

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator decimal(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator double(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator float(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator int(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator long(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator uint(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ulong(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator byte(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator sbyte(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator ushort(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        public static explicit operator short(PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        static public implicit operator string(PercentValV2 self)
        {
            return "0";
        }

        //From Standard types to this type

#if (BlazesSharedCode_EnablePercentValV2_ImplicitConversionFrom)
        public static implicit operator PercentValV2(decimal Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(double Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(float Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(int Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(uint Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(long Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(ulong Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(ushort Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(short Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(sbyte Value)   {   return new PercentValV2(Value); }

        public static implicit operator PercentValV2(byte Value)    {   return new PercentValV2(Value); }
#else
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(decimal Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(double Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(float Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(int Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(uint Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(long Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(ulong Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(ushort Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(short Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(sbyte Value) { return new PercentValV2(Value); }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator PercentValV2(byte Value) { return new PercentValV2(Value); }

#endif

        /// <summary>
        /// Self Less than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Less than or equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Greater than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Greater than or Equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Equality operator for comparing self
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Inequality operator for comparing self
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(PercentValV2 self, PercentValV2 Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Less than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Less than or equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Greater than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Greater than or Equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Equality operator for comparing self
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Inequality operator for comparing self
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(PercentValV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Value Less than self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Value Less than or equal to self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <=(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Value Greater than self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Value Greater than or Equal to self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >=(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Equality operator for comparing self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator ==(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Inequality operator for comparing self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator !=(SmallDec Value, PercentValV2 self)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Self Less than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// Value Less than Self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <(dynamic Value, PercentValV2 self)
        {
            return self > Value;
        }

        /// <summary>
        /// Self Less than or equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator <=(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// Value Less than or equal to self
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator <=(dynamic Value, PercentValV2 self)
        {
            return self >= Value;
        }

        /// <summary>
        /// Self Greater than Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >(dynamic Value, PercentValV2 self)
        {
            return self < Value;
        }

        /// <summary>
        /// Self Greater than or Equal to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator >=(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator >=(dynamic Value, PercentValV2 self)
        {
            return self <= Value;
        }

        /// <summary>
        /// Equality operator for comparing self to Value
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator ==(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator ==(dynamic Value, PercentValV2 self) => self == Value;

        /// <summary>
        /// Inequality operator for comparing self to multiple value types
        /// </summary>
        /// <param name="self"></param>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static bool operator !=(PercentValV2 self, dynamic Value)
        {
            if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
            }
            else if (Value is string)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static bool operator !=(dynamic Value, PercentValV2 self)
        {
            return self != Value;
        }

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
                return this == (PercentValV2)obj;
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
            if (ValueRep <= Int32.MaxValue&&ValueRep>=Int32.MinValue)
            {
                return (int)ValueRep;
            }
            else
            {
                return (int)(ValueRep%Int32.MaxValue);
            }
        }

        /// <summary>
        /// Negative Operator Applied
        /// </summary>
        public void SwapNegativeStatus()
        {
            ValueRep *= -1;
        }

        private static PercentValV2 MaximumValue()
        {
            PercentValV2 self;
            self.ValueRep = 8999999999999999999;
            return self;
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can stored
        /// </summary>
        public static PercentValV2 Maximum = MaximumValue();

        private static PercentValV2 MinimumValue()
        {
            PercentValV2 self;
            self.ValueRep = -8999999999999999999;
            return self;
        }

        //Returns value of lowest non-infinite/Special Decimal State Value that can stored
        /// <summary>
        /// 
        /// </summary>
        public static PercentValV2 Minimum = MinimumValue();

        /// <summary>
        /// Max/Min of long = Infinity
        /// </summary>
        /// <returns></returns>
        public bool IsInfinity()
        {
            return ValueRep == 9223372036854775807 ? true : ValueRep == -9223372036854775808;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <param name="provider"></param>
        /// <returns></returns>
        public string ToString(string s, IFormatProvider provider)
        {
            return (string)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public string ToString(string s)
        {
            return (string)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="invariantCulture"></param>
        /// <returns></returns>
        public string ToString(CultureInfo invariantCulture)
        {
            return (string)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public override string ToString() { return (string)this; }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 SumOfList(PercentValV2[] self)
        {
            PercentValV2 Total = PercentValV2.Zero;
            foreach (PercentValV2 Element in self)
            {
                Total += Element;
            }
            return Total;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 SumOfList(IEnumerable<PercentValV2> self)
        {
            PercentValV2 Total = PercentValV2.Zero;
            foreach (PercentValV2 Element in self)
            {
                Total += Element;
            }
            return Total;
        }

        /// <summary>
        /// Modulus operation
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator %(PercentValV2 self, PercentValV2 y)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator +(PercentValV2 self, PercentValV2 y)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator -(PercentValV2 self, PercentValV2 y)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator *(PercentValV2 self, PercentValV2 y)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator /(PercentValV2 self, PercentValV2 y)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator %(PercentValV2 self, dynamic y)
        {
            if (y is double || y is float || y is decimal)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
            //return self;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator +(PercentValV2 self, dynamic y)
        {
            if (y is double || y is float || y is decimal)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
            //return self;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator -(PercentValV2 self, dynamic y)
        {
            if (y is double || y is float || y is decimal)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
            //return self;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator *(PercentValV2 self, dynamic y)
        {
            if (y is double || y is float || y is decimal)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
            //return self;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static PercentValV2 operator /(PercentValV2 self, dynamic y)
        {
            if (y is double || y is float || y is decimal)
            {
                throw new NotImplementedException();
            }
            else
            {
                throw new NotImplementedException();
            }
            //return self;
        }

        //Right side applications
        /// <summary>
        /// 
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 operator -(dynamic y, PercentValV2 self)
        {
            PercentValV2 YAsSuperDec = (PercentValV2)y;
            YAsSuperDec -= self;
            return YAsSuperDec;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 operator +(dynamic y, PercentValV2 self)
        {
            PercentValV2 YAsSuperDec = (PercentValV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 operator *(dynamic y, PercentValV2 self)
        {
            PercentValV2 YAsSuperDec = (PercentValV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="y"></param>
        /// <param name="self"></param>
        /// <returns></returns>
        public static PercentValV2 operator /(dynamic y, PercentValV2 self)
        {
            PercentValV2 YAsSuperDec = (PercentValV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public float AsFloat()
        {
            return (float)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public double AsDouble()
        {
            return (double)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public int AsInt()
        {
            return (int)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public string AsString()
        {
            return (string)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public bool IsNull() => ValueRep == 9000000000000000002;

        private static PercentValV2 NullValue()
        {
            PercentValV2 NewSelf;
            NewSelf.ValueRep = 900000000000000002;
            return NewSelf;
        }

        /// <summary>
        /// Value is either Null or Zero (Depending on preprocessor settings)
        /// </summary>
        public static readonly PercentValV2 Null = NullValue();

        private static PercentValV2 ZeroValue()
        {
            PercentValV2 NewSelf;
            NewSelf.ValueRep = 0;
            return NewSelf;
        }

        /// <summary>
        /// Value is Zero
        /// </summary>
        public static readonly PercentValV2 Zero = ZeroValue();

        int IComparable<PercentValV2>.CompareTo(PercentValV2 other)
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
        /// <param name="Condition"></param>
        /// <param name="X"></param>
        /// <param name="Y"></param>
        /// <returns></returns>
        public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
        {
            return Condition ? X : Y;
        }

        //public dynamic DynamicConversion()
        //{
        //    return this;
        //}
    }

#pragma warning restore CC0001 // You should use 'var' whenever possible.
#pragma warning restore CC0105 // You should use 'var' whenever possible.
#pragma warning restore CS3001 // Argument type is not CLS-compliant
#pragma warning restore CS3002 // Return type is not CLS-compliant
#pragma warning restore CS3003 // Type is not CLS-compliant
}