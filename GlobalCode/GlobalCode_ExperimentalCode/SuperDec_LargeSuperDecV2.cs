using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    //class SuperDec_LargeSuperDecV2 : PercentValV2
    //Supports value +-18,446,744,073,709,551,623.XXXXXXXXXXXXXXXXXX
    //Values at range +-8.XXXXXXXXXXXXXXXXXX use only Section01 part of code
#if (BlazesGlobalCode_LargeSuperDecV2AsStruct)
    public partial struct LargeSuperDecV2 : IComparable<LargeSuperDecV2>
#else
    public partial class LargeSuperDecV2 : IComparable<LargeSuperDecV2>
#endif
    {
#if (BlazesGlobalCode_LargeSuperDecV2AsStruct)
        ulong Section02;
        PercentValV2 Section01;
#else
        ulong Section02 = 0;
        PercentValV2 Section01 = PercentValV2.Zero;
#endif

        public static LargeSuperDecV2 Sum(IEnumerable<LargeSuperDecV2> Value)
        {
            LargeSuperDecV2 TotalSum = LargeSuperDecV2.Zero;
            foreach (var Element in Value)
            {
                TotalSum += Element;
            }
            return TotalSum;
        }

        //        public LargeSuperDecV2 Abs()
        //        {
        //            if(ValueRep<0)
        //            {
        //                ValueRep *= -1;
        //            }
        //            return this;
        //        }
        //
        //        public LargeSuperDecV2 Floor()
        //        {
        //            sbyte WholeHalf = (sbyte)(ValueRep/1000000000000000000);
        //            this.ValueRep = WholeHalf* 1000000000000000000;
        //            return this;
        //        }

        //public static LargeSuperDecV2 Parse(string value, CultureInfo invariantCulture)
        //{
        //    LargeSuperDecV2 NewValue = LargeSuperDecV2.StringToValue(value);
        //    return NewValue;
        //}

        //// Returns rounded value with all fractional digits after specified precision cut off.
        //public static LargeSuperDecV2 Floor(LargeSuperDecV2 value, int precision)
        //{
        //    throw new NotImplementedException();
        //}

        //public LargeSuperDecV2 Ceil()
        //{
        //    throw new NotImplementedException();
        //}


        //public static LargeSuperDecV2 Pow(LargeSuperDecV2 self, int Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator LargeSuperDecV2(DependencyProperty v)
        //{
        //    throw new NotImplementedException();
        //}

        //public static LargeSuperDecV2 Pow(double self, double Value) { return LargeSuperDecV2.Pow((LargeSuperDecV2)self, (LargeSuperDecV2)Value); }
        //public static LargeSuperDecV2 Pow(LargeSuperDecV2 self, double Value) { return LargeSuperDecV2.Pow(self, (LargeSuperDecV2)Value); }
        //public static LargeSuperDecV2 Pow(LargeSuperDecV2 self, float Value) { return LargeSuperDecV2.Pow(self, (LargeSuperDecV2)Value); }

        ////Approximate version of Math.Pow(double self, double Value)
        //public static LargeSuperDecV2 Pow(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        ////LargeSuperDecV2 version of Math.Exp(double Value)
        //public static LargeSuperDecV2 Exp(LargeSuperDecV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        public static LargeSuperDecV2 Max(dynamic LeftSide, dynamic RightSide)
        {
            LargeSuperDecV2 LeftSideAsType = (LargeSuperDecV2)LeftSide;
            LargeSuperDecV2 RightSideAsType = (LargeSuperDecV2)RightSide;
            if (LeftSideAsType > RightSide) { return LeftSideAsType; }
            else { return RightSideAsType; }
        }

        public static LargeSuperDecV2 Min(dynamic LeftSide, dynamic RightSide)
        {
            LargeSuperDecV2 LeftSideAsType = (LargeSuperDecV2)LeftSide;
            LargeSuperDecV2 RightSideAsType = (LargeSuperDecV2)RightSide;
            if (LeftSideAsType < RightSide) { return LeftSideAsType; }
            else { return RightSideAsType; }
        }

        //public static LargeSuperDecV2 Round(LargeSuperDecV2 val)
        //{
        //    return val.Round();
        //}

        //public static LargeSuperDecV2 Round(LargeSuperDecV2 value, int Precision)
        //{
        //    if (Precision == 0)
        //    {
        //        return value.Round();
        //    }
        //    else
        //    {
        //        return LargeSuperDecV2.Round(value, 1, MidpointRounding.AwayFromZero);
        //    }
        //}

        //public static LargeSuperDecV2 RoundHalfDownValue(LargeSuperDecV2 value, int precision)
        //{
        //    if (precision == 0)
        //    {
        //        return value.Floor();
        //    }
        //    else
        //    {
        //        return LargeSuperDecV2.Round(value, precision, 1);
        //    }
        //}

        //public LargeSuperDecV2 Round()
        //{
        //    throw new NotImplementedException();
        //}

        //public LargeSuperDecV2 RoundToNonZero()
        //{
        //    throw new NotImplementedException();
        //}

        //public static LargeSuperDecV2 Round(LargeSuperDecV2 value, int precision, int RoundingMethod)
        //{//https://en.wikipedia.org/wiki/Rounding
        //    throw new NotImplementedException();
        //}

        //public static LargeSuperDecV2 Round(LargeSuperDecV2 value, int precision, MidpointRounding RoundingMethod)
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

        public static LargeSuperDecV2 operator -(LargeSuperDecV2 Value)
        {
            Value.Section01.ValueRep *= -1;
            return Value;
        }

        //public static LargeSuperDecV2 StringToValue(string Value)
        //{
        //    throw new NotImplementedException();
        //}

        //Method version to Initialize Type instead of with Explicit operators
        public static LargeSuperDecV2 Initialize(dynamic Value)
        {
            return new LargeSuperDecV2(Value);
        }

        public LargeSuperDecV2(dynamic Value)
        {
            if (Value is string)
            {
                throw new NotImplementedException();
            }
            else if (Value is PercentValV2)
            {
                Section02 = 0;
                Section01 = Value;
            }
            else if (Value is decimal || Value is double || Value is float)
            {
                throw new NotImplementedException();
                //ValueRep = (long)((Value)* 1000000000000000000);
            }
            else if (Value is SmallDec)
            {
                throw new NotImplementedException();
                //ValueRep = (long)Value.IntValue * 1000000000000000000;
            }
            else//if (Value is sbyte || Value is byte || Value is ushort || Value is int || Value is uint || Value is long|| Value is ulong)
            {
                throw new NotImplementedException();
                //ValueRep = (long)Value * 1000000000000000000;
            }
        }

        //From this type to Standard types

        public static explicit operator decimal(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator double(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator float(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator int(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator long(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator uint(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator ulong(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator byte(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator sbyte(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator ushort(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        public static explicit operator short(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        static public explicit operator string(LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        //From Standard types to this type

#if (BlazesGlobalCode_EnableLargeSuperDecV2_ImplicitConversionFrom)
        public static implicit operator LargeSuperDecV2(decimal Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(double Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(float Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(int Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(uint Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(long Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(ulong Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(ushort Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(short Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(sbyte Value)   {   return new LargeSuperDecV2(Value); }

        public static implicit operator LargeSuperDecV2(byte Value)    {   return new LargeSuperDecV2(Value); }
#else
        public static explicit operator LargeSuperDecV2(decimal Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(double Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(float Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(int Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(uint Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(long Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(ulong Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(ushort Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(short Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(sbyte Value) { return new LargeSuperDecV2(Value); }

        public static explicit operator LargeSuperDecV2(byte Value) { return new LargeSuperDecV2(Value); }
#endif

        public static explicit operator LargeSuperDecV2(PercentValV2 Value) { return new LargeSuperDecV2(Value); }

        // Self Less than Value
        public static bool operator <(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Self Less than or equal to Value
        public static bool operator <=(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Self Greater than Value
        public static bool operator >(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Self Greater than or Equal to Value
        public static bool operator >=(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Equality operator for comparing self
        public static bool operator ==(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Inequality operator for comparing self
        public static bool operator !=(LargeSuperDecV2 self, LargeSuperDecV2 Value)
        {
            throw new NotImplementedException();
        }

        // Self Less than Value
        public static bool operator <(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Self Less than or equal to Value
        public static bool operator <=(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Self Greater than Value
        public static bool operator >(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Self Greater than or Equal to Value
        public static bool operator >=(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Equality operator for comparing self
        public static bool operator ==(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Inequality operator for comparing self
        public static bool operator !=(LargeSuperDecV2 self, SmallDec Value)
        {
            throw new NotImplementedException();
        }

        // Self Less than Value
        public static bool operator <(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Self Less than or equal to Value
        public static bool operator <=(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Self Greater than Value
        public static bool operator >(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Self Greater than or Equal to Value
        public static bool operator >=(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Equality operator for comparing self
        public static bool operator ==(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Inequality operator for comparing self
        public static bool operator !=(SmallDec Value, LargeSuperDecV2 self)
        {
            throw new NotImplementedException();
        }

        // Self Less than Value
        public static bool operator <(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator <(dynamic Value, LargeSuperDecV2 self)
        {
            return self > Value;
        }

        // Self Less than or equal to Value
        public static bool operator <=(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator <=(dynamic Value, LargeSuperDecV2 self)
        {
            return self >= Value;
        }

        // Self Greater than Value
        public static bool operator >(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator >(dynamic Value, LargeSuperDecV2 self)
        {
            return self < Value;
        }

        // Self Greater than or Equal to Value
        public static bool operator >=(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator >=(dynamic Value, LargeSuperDecV2 self)
        {
            return self <= Value;
        }

        // Equality operator for comparing self to int type value
        public static bool operator ==(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator ==(dynamic Value, LargeSuperDecV2 self)
        {
            return self == Value;
        }

        // Inequality operator for comparing self to multiple value types
        public static bool operator !=(LargeSuperDecV2 self, dynamic Value)
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

        public static bool operator !=(dynamic Value, LargeSuperDecV2 self)
        {
            return self != Value;
        }

        public override bool Equals(object obj)
        {
            //Enable comparisons of other object types
            //if (obj == null || GetType() != obj.GetType()) { return false; }
            try
            {
                if (obj is PercentValV2)
                {
                    if (this.Section02 == 0)
                    {
                        if (Section01 == obj) { return true; }
                        else { return false; }
                    }
                    else { return false; }
                }
                else
                {
                    return this == (LargeSuperDecV2)obj;
                }
            }
            catch
            {
                return false;
            }
        }


        // Override the Object.GetHashCode() method:
        public override int GetHashCode()
        {
            if (Section01.ValueRep <= Int32.MaxValue && Section01.ValueRep >= Int32.MinValue)
            {
                return (int)Section01.ValueRep;
            }
            else
            {
                return (int)(Section01.ValueRep % Int32.MaxValue);
            }
        }

        public void SwapNegativeStatus()
        {
            Section01.ValueRep *= -1;
        }

        private static LargeSuperDecV2 MaximumValue()
        {
            LargeSuperDecV2 self = LargeSuperDecV2.Zero;
            self.Section02 = 18446744073709551615;
            self.Section01.ValueRep = 8999999999999999999;
            return self;
        }

        //Returns value of highest non-infinite/Special Decimal State Value that can stored
        public static LargeSuperDecV2 Maximum = MaximumValue();

        private static LargeSuperDecV2 MinimumValue()
        {
            LargeSuperDecV2 self = LargeSuperDecV2.Zero;
            self.Section02 = 18446744073709551615;
            self.Section01.ValueRep = -8999999999999999999;
            return self;
        }

        //Returns value of lowest non-infinite/Special Decimal State Value that can stored
        public static LargeSuperDecV2 Minimum = MinimumValue();

        //Max/Min of long = Infinity
        public bool IsInfinity()
        {
            //Negative Infinity
            if (Section01.ValueRep == 9223372036854775807)
            { return true; }
            //Positive Infinity
            else if (Section01.ValueRep == -9223372036854775808)
            { return true; }
            else { return false; }
        }

        public string ToString(string s, IFormatProvider provider)
        {
            return (string)this;
        }

        public string ToString(string s)
        {
            return (string)this;
        }

        internal string ToString(CultureInfo invariantCulture)
        {
            return (string)this;
        }

        public override string ToString() { return (string)this; }

        public static LargeSuperDecV2 SumOfList(LargeSuperDecV2[] self)
        {
            LargeSuperDecV2 Total = LargeSuperDecV2.Zero;
            foreach (LargeSuperDecV2 Element in self)
            {
                Total += Element;
            }
            return Total;
        }

        //      public static LargeSuperDecV2 SumOfList(PercentValV2[] self)
        //      {
        //          LargeSuperDecV2 Total = LargeSuperDecV2.Zero;
        //	//PercentValV2 TempSum = PercentValV2.Zero;
        //          foreach (PercentValV2 Element in self)
        //          {
        //		//if(TempSum!=Null)
        //		//{
        //		//	TempSum = Total.Section01+PercentValV2;
        //		//}
        //		//else
        //		//{
        //		//	Total += Element;
        //		//}
        //		Total += Element;
        //          }
        //          return Total;
        //      }

        public static LargeSuperDecV2 SumOfList(IEnumerable<LargeSuperDecV2> self)
        {
            LargeSuperDecV2 Total = LargeSuperDecV2.Zero;
            foreach (LargeSuperDecV2 Element in self)
            {
                Total += Element;
            }
            return Total;
        }

        public static LargeSuperDecV2 operator %(LargeSuperDecV2 self, LargeSuperDecV2 y)
        {
            throw new NotImplementedException();
        }

        public static LargeSuperDecV2 operator +(LargeSuperDecV2 self, LargeSuperDecV2 y)
        {
            throw new NotImplementedException();
        }

        public static LargeSuperDecV2 operator -(LargeSuperDecV2 self, LargeSuperDecV2 y)
        {
            throw new NotImplementedException();
        }

        public static LargeSuperDecV2 operator *(LargeSuperDecV2 self, LargeSuperDecV2 y)
        {
            throw new NotImplementedException();
        }

        public static LargeSuperDecV2 operator /(LargeSuperDecV2 self, LargeSuperDecV2 y)
        {
            throw new NotImplementedException();
        }

        public static LargeSuperDecV2 operator %(LargeSuperDecV2 self, dynamic y)
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

        public static LargeSuperDecV2 operator +(LargeSuperDecV2 self, dynamic y)
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

        public static LargeSuperDecV2 operator -(LargeSuperDecV2 self, dynamic y)
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

        public static LargeSuperDecV2 operator *(LargeSuperDecV2 self, dynamic y)
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

        public static LargeSuperDecV2 operator /(LargeSuperDecV2 self, dynamic y)
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
        public static LargeSuperDecV2 operator -(dynamic y, LargeSuperDecV2 self)
        {
            LargeSuperDecV2 YAsSuperDec = (LargeSuperDecV2)y;
            YAsSuperDec -= self;
            return YAsSuperDec;
        }

        public static LargeSuperDecV2 operator +(dynamic y, LargeSuperDecV2 self)
        {
            LargeSuperDecV2 YAsSuperDec = (LargeSuperDecV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        public static LargeSuperDecV2 operator *(dynamic y, LargeSuperDecV2 self)
        {
            LargeSuperDecV2 YAsSuperDec = (LargeSuperDecV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        public static LargeSuperDecV2 operator /(dynamic y, LargeSuperDecV2 self)
        {
            LargeSuperDecV2 YAsSuperDec = (LargeSuperDecV2)y;
            YAsSuperDec += self;
            return YAsSuperDec;
        }

        public float AsFloat()
        {
            return (float)this;
        }

        public double AsDouble()
        {
            return (double)this;
        }

        public int AsInt()
        {
            return (int)this;
        }

        public string AsString()
        {
            return (string)this;
        }

        public bool IsNull()
        {
            if (Section01.ValueRep == 9000000000000000002) { return true; }
            else { return false; }
        }

        private static LargeSuperDecV2 NullValue()
        {
#if (BlazesGlobalCode_LargeSuperDecV2AsStruct)
            LargeSuperDecV2 NewSelf;
            NewSelf.Section02 = 0;
            NewSelf.Section01.ValueRep = 900000000000000002;
            return NewSelf;
#else
            LargeSuperDecV2 NewSelf = LargeSuperDecV2.Zero;
            NewSelf.Section01.ValueRep = 900000000000000002;
            return NewSelf;
#endif
        }

        public static readonly LargeSuperDecV2 Null = NullValue();

        private static LargeSuperDecV2 ZeroValue()
        {
#if (BlazesGlobalCode_LargeSuperDecV2AsStruct)
            LargeSuperDecV2 NewSelf;
            NewSelf.Section02 = 0;
            NewSelf.Section01.ValueRep = 0;
            return NewSelf;
#else
            LargeSuperDecV2 NewSelf = new LargeSuperDecV2();
            return NewSelf;
#endif
        }

        public static readonly LargeSuperDecV2 Zero = ZeroValue();

        int IComparable<LargeSuperDecV2>.CompareTo(LargeSuperDecV2 other)
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

        public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
        {
            return CSharpGlobalCode.GlobalCode_ExperimentalCode.SuperDecGlobalCode.ConditionalReturn(Condition, X, Y);
        }

        public dynamic DynamicConversion()
        {
            return this;
        }
        //Class Only method section
#if (!BlazesGlobalCode_LargeSuperDecV2AsStruct)
        LargeSuperDecV2()
        {

        }
#endif
    }
}
