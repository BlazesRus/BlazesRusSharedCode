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

    //Can represent +-8.XXXXXXXXXXXXXXXXXX
    public partial struct SuperDec_PercentValV2 : IComparable<SuperDec_PercentValV2>
    {
        public long ValueRep;

        public static SuperDec_PercentValV2 Sum(IEnumerable<SuperDec_PercentValV2> Value)
        {
            SuperDec_PercentValV2 TotalSum = SuperDec_PercentValV2.Zero;
            foreach (var Element in Value)
            {
                //TotalSum += Element;
            }
            return TotalSum;
        }

        public SuperDec_PercentValV2 Abs()
        {
            if(ValueRep<0)
            {
                ValueRep *= -1;
            }
            return this;
        }

        public SuperDec_PercentValV2 Floor()
        {
            sbyte WholeHalf = (sbyte)(ValueRep/1000000000000000000);
            this.ValueRep = WholeHalf* 1000000000000000000;
            return this;
        }

        //public static SuperDec_PercentValV2 Parse(string value, CultureInfo invariantCulture)
        //{
        //    SuperDec_PercentValV2 NewValue = SuperDec_PercentValV2.StringToValue(value);
        //    return NewValue;
        //}

        //// Returns rounded value with all fractional digits after specified precision cut off.
        //public static SuperDec_PercentValV2 Floor(SuperDec_PercentValV2 value, int precision)
        //{
        //    throw new NotImplementedException();
        //}

        //public SuperDec_PercentValV2 Ceil()
        //{
        //    throw new NotImplementedException();
        //}


        //public static SuperDec_PercentValV2 Pow(SuperDec_PercentValV2 self, int Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator SuperDec_PercentValV2(DependencyProperty v)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 Pow(double self, double Value) { return SuperDec_PercentValV2.Pow((SuperDec_PercentValV2)self, (SuperDec_PercentValV2)Value); }
        //public static SuperDec_PercentValV2 Pow(SuperDec_PercentValV2 self, double Value) { return SuperDec_PercentValV2.Pow(self, (SuperDec_PercentValV2)Value); }
        //public static SuperDec_PercentValV2 Pow(SuperDec_PercentValV2 self, float Value) { return SuperDec_PercentValV2.Pow(self, (SuperDec_PercentValV2)Value); }

        ////Approximate version of Math.Pow(double self, double Value)
        //public static SuperDec_PercentValV2 Pow(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        ////SuperDec_PercentValV2 version of Math.Exp(double Value)
        //public static SuperDec_PercentValV2 Exp(SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 Max(dynamic LeftSide, dynamic RightSide)
        //{
        //    SuperDec_PercentValV2 LeftSideAsType = (SuperDec_PercentValV2)LeftSide;
        //    SuperDec_PercentValV2 RightSideAsType = (SuperDec_PercentValV2)RightSide;
        //    if (LeftSideAsType > RightSide) { return LeftSideAsType; }
        //    else { return RightSideAsType; }
        //}

        //public static SuperDec_PercentValV2 Min(dynamic LeftSide, dynamic RightSide)
        //{
        //    SuperDec_PercentValV2 LeftSideAsType = (SuperDec_PercentValV2)LeftSide;
        //    SuperDec_PercentValV2 RightSideAsType = (SuperDec_PercentValV2)RightSide;
        //    if (LeftSideAsType < RightSide) { return LeftSideAsType; }
        //    else { return RightSideAsType; }
        //}

        //public static SuperDec_PercentValV2 Round(SuperDec_PercentValV2 val)
        //{
        //    return val.Round();
        //}

        //public static SuperDec_PercentValV2 Round(SuperDec_PercentValV2 value, int Precision)
        //{
        //    if (Precision == 0)
        //    {
        //        return value.Round();
        //    }
        //    else
        //    {
        //        return SuperDec_PercentValV2.Round(value, 1, MidpointRounding.AwayFromZero);
        //    }
        //}

        //public static SuperDec_PercentValV2 RoundHalfDownValue(SuperDec_PercentValV2 value, int precision)
        //{
        //    if (precision == 0)
        //    {
        //        return value.Floor();
        //    }
        //    else
        //    {
        //        return SuperDec_PercentValV2.Round(value, precision, 1);
        //    }
        //}

        //public SuperDec_PercentValV2 Round()
        //{
        //    throw new NotImplementedException();
        //}

        //public SuperDec_PercentValV2 RoundToNonZero()
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 Round(SuperDec_PercentValV2 value, int precision, int RoundingMethod)
        //{//https://en.wikipedia.org/wiki/Rounding
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 Round(SuperDec_PercentValV2 value, int precision, MidpointRounding RoundingMethod)
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

        //public static SuperDec_PercentValV2 operator -(SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 StringToValue(string Value)
        //{
        //    throw new NotImplementedException();
        //}

        ////Method version to Initialize Type instead of with Explicit operators
        //public static SuperDec_PercentValV2 Initialize(dynamic Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public SuperDec_PercentValV2(dynamic Value)
        //{
        //    if (Value is string)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is double || Value is float)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is sbyte || Value is ushort || Value is int || Value is long)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static explicit operator decimal(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        ////explicit Conversion from this to double
        //public static explicit operator double(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator float(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        ////Explicit/explicit Conversion from this to int
        //public static explicit operator int(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        ////Explicit Conversion from this to int 64
        //public static explicit operator long(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        ////Explicit Conversion from this to uint
        //public static explicit operator uint(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        ////Explicit Conversion from this to unsigned int 64
        //public static explicit operator ulong(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator byte(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator sbyte(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator ushort(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator short(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //static public explicit operator string(SuperDec_PercentValV2 self)
        //{
        //    throw new NotImplementedException();
        //}

        //public static explicit operator SuperDec_PercentValV2(decimal Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(double Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(float Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(int Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(uint Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(long Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(ulong Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(ushort Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(short Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(sbyte Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //public static explicit operator SuperDec_PercentValV2(byte Value)
        //{
        //    return new SuperDec_PercentValV2(Value);
        //}

        //// Self Less than Value
        //public static bool operator <(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Self Less than or equal to Value
        //public static bool operator <=(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Self Greater than Value
        //public static bool operator >(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Self Greater than or Equal to Value
        //public static bool operator >=(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Equality operator for comparing self to int type value
        //public static bool operator ==(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Inequality operator for comparing self to multiple value types
        //public static bool operator !=(SuperDec_PercentValV2 self, SuperDec_PercentValV2 Value)
        //{
        //    throw new NotImplementedException();
        //}

        //// Self Less than Value
        //public static bool operator <(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator <(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self > Value;
        //}

        //// Self Less than or equal to Value
        //public static bool operator <=(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator <=(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self >= Value;
        //}

        //// Self Greater than Value
        //public static bool operator >(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator >(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self < Value;
        //}

        //// Self Greater than or Equal to Value
        //public static bool operator >=(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator >=(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self <= Value;
        //}

        //// Equality operator for comparing self to int type value
        //public static bool operator ==(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator ==(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self == Value;
        //}

        //// Inequality operator for comparing self to multiple value types
        //public static bool operator !=(SuperDec_PercentValV2 self, dynamic Value)
        //{
        //    if (Value is double)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else if (Value is String)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //}

        //public static bool operator !=(dynamic Value, SuperDec_PercentValV2 self)
        //{
        //    return self != Value;
        //}

        //public override bool Equals(object obj)
        //{
        //    if (obj == null || GetType() != obj.GetType()) { return false; }

        //    try
        //    {
        //        return this == (SuperDec_PercentValV2)obj;
        //    }
        //    catch
        //    {
        //        return false;
        //    }
        //}

        //public byte GetDecBoolStatus()
        //{
        //    return DecBoolStatus;
        //}

        //public ulong GetDecimalStatus()
        //{
        //    return ValueRep;
        //}

        //// Override the Object.GetHashCode() method:
        //public override int GetHashCode()
        //{
        //    if (ValueRep <= Int32.MaxValue)
        //    {
        //        return (int)ValueRep;
        //    }
        //    else
        //    {
        //        return Int32.MaxValue;
        //    }
        //}

        public void SwapNegativeStatus()
        {
            ValueRep *= -1;
        }

        //Returns value of highest non-infinite/Special Decimal State Value that can store
        public static SuperDec_PercentValV2 Maximum()
        {
            SuperDec_PercentValV2 self;
            self.ValueRep = 8999999999999999999;
            return self;
        }

        //Returns value of minimum non-infinite/Special Decimal State Value that can store
        public static SuperDec_PercentValV2 Minimum()
        {
            throw new NotImplementedException();
        }

        public bool IsInfinity()
        {
            //Negative Infinity
            if (ValueRep == 9223372036854775807)
            { return true; }
            //Positive Infinity
            else if (ValueRep == -9223372036854775808)
            { return true; }
            else { return false; }
        }

        //public string ToString(string s, IFormatProvider provider)
        //{
        //    return (string)this;
        //}

        //public string ToString(string s)
        //{
        //    return (string)this;
        //}

        //internal string ToString(CultureInfo invariantCulture)
        //{
        //    return (string)this;
        //}

        //public override string ToString() { return (string)this; }

        //public static SuperDec_PercentValV2 SumOfList(SuperDec_PercentValV2[] self)
        //{
        //    SuperDec_PercentValV2 Total = SuperDec_PercentValV2.Zero;
        //    foreach (SuperDec_PercentValV2 Element in self)
        //    {
        //        Total += Element;
        //    }
        //    return Total;
        //}

        //public static SuperDec_PercentValV2 SumOfList(IEnumerable<SuperDec_PercentValV2> self)
        //{
        //    SuperDec_PercentValV2 Total = SuperDec_PercentValV2.Zero;
        //    foreach (SuperDec_PercentValV2 Element in self)
        //    {
        //        Total += Element;
        //    }
        //    return Total;
        //}

        //public static SuperDec_PercentValV2 operator %(SuperDec_PercentValV2 self, SuperDec_PercentValV2 y)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 operator +(SuperDec_PercentValV2 self, SuperDec_PercentValV2 y)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 operator -(SuperDec_PercentValV2 self, SuperDec_PercentValV2 y)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 operator *(SuperDec_PercentValV2 self, SuperDec_PercentValV2 y)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 operator /(SuperDec_PercentValV2 self, SuperDec_PercentValV2 y)
        //{
        //    throw new NotImplementedException();
        //}

        //public static SuperDec_PercentValV2 operator %(SuperDec_PercentValV2 self, dynamic y)
        //{
        //    if (y is double || y is float || y is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //    //return self;
        //}

        //public static SuperDec_PercentValV2 operator +(SuperDec_PercentValV2 self, dynamic y)
        //{
        //    if (y is double || y is float || y is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //    //return self;
        //}

        //public static SuperDec_PercentValV2 operator -(SuperDec_PercentValV2 self, dynamic y)
        //{
        //    if (y is double || y is float || y is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //    //return self;
        //}

        //public static SuperDec_PercentValV2 operator *(SuperDec_PercentValV2 self, dynamic y)
        //{
        //    if (y is double || y is float || y is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //    //return self;
        //}

        //public static SuperDec_PercentValV2 operator /(SuperDec_PercentValV2 self, dynamic y)
        //{
        //    if (y is double || y is float || y is decimal)
        //    {
        //        throw new NotImplementedException();
        //    }
        //    else
        //    {
        //        throw new NotImplementedException();
        //    }
        //    //return self;
        //}

        ////Right side applications
        //public static SuperDec_PercentValV2 operator -(dynamic y, SuperDec_PercentValV2 self)
        //{
        //    SuperDec_PercentValV2 YAsSuperDec = (SuperDec_PercentValV2)y;
        //    YAsSuperDec -= self;
        //    return YAsSuperDec;
        //}

        //public static SuperDec_PercentValV2 operator +(dynamic y, SuperDec_PercentValV2 self)
        //{
        //    SuperDec_PercentValV2 YAsSuperDec = (SuperDec_PercentValV2)y;
        //    YAsSuperDec += self;
        //    return YAsSuperDec;
        //}

        //public static SuperDec_PercentValV2 operator *(dynamic y, SuperDec_PercentValV2 self)
        //{
        //    SuperDec_PercentValV2 YAsSuperDec = (SuperDec_PercentValV2)y;
        //    YAsSuperDec += self;
        //    return YAsSuperDec;
        //}

        //public static SuperDec_PercentValV2 operator /(dynamic y, SuperDec_PercentValV2 self)
        //{
        //    SuperDec_PercentValV2 YAsSuperDec = (SuperDec_PercentValV2)y;
        //    YAsSuperDec += self;
        //    return YAsSuperDec;
        //}

        //public float AsFloat()
        //{
        //    return (float)this;
        //}

        //public double AsDouble()
        //{
        //    return (double)this;
        //}

        //public int AsInt()
        //{
        //    return (int)this;
        //}

        //public string AsString()
        //{
        //    return (string)this;
        //}

        public bool IsNull()
        {
            if (ValueRep == 9000000000000000002) { return true; }
            else { return false; }
        }

        private static SuperDec_PercentValV2 NullValue()
        {
            SuperDec_PercentValV2 NewSelf;
            NewSelf.ValueRep = 900000000000000002;
            return NewSelf;
        }

        public static readonly SuperDec_PercentValV2 Null = NullValue();

        private static SuperDec_PercentValV2 ZeroValue()
        {
            SuperDec_PercentValV2 NewSelf;
            NewSelf.ValueRep = 0;
            return NewSelf;
        }

        public static readonly SuperDec_PercentValV2 Zero = ZeroValue();

        int IComparable<SuperDec_PercentValV2>.CompareTo(SuperDec_PercentValV2 other)
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
    }

}