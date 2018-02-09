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
    using System.IO;

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
    SmallDec : IComparable<SmallDec>, IConvertible, IEquatable<SmallDec>, IFormattable
#if (!SmallDec_DisableCustomTypeDescriptor)
    , ICustomTypeDescriptor
#endif
    {
        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static Tuple<string, SmallDec> ConvertTuple(Tuple<string, dynamic> Value)
        {
            Tuple<string, SmallDec> self = Tuple.Create(Value.Item1, (SmallDec)Value.Item2);
            return self;
        }

        //public static implicit operator Tuple<string, SmallDec>(Tuple<string, dynamic> Value)
        //{
        //	return ConvertTuple(Value);
        //}

        /// <summary>
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static dynamic DynamicMax(dynamic LeftSide, dynamic RightSide)
        {
            SmallDec LeftSideAsType = (SmallDec)LeftSide;
            SmallDec RightSideAsType = (SmallDec)RightSide;
            if (LeftSideAsType > RightSide) { return LeftSideAsType; }
            else { return RightSideAsType; }
        }

        /// <summary>
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static dynamic DynamicMin(dynamic LeftSide, dynamic RightSide)
        {
            if (LeftSide < RightSide) { return LeftSide; }
            else { return RightSide; }
        }

#if (!BlazesGlobalCode_RestrictConversionBetweenSuperDec)
        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public SmallDec Convert(ModerateSuperDec Value)
        {
            ulong TempDec = Value.DecimalStatus;
            TempDec /= 1000000000000000;
            return new SmallDec((ushort)Value.IntValue, (ushort) TempDec, Value.DecBoolStatus);
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public SmallDec Convert(LargeSuperDec Value)
        {
            ulong TempDec = Value.DecimalStatus / 100000000000000;
            return new SmallDec((ushort)Value.IntValue, (ushort)TempDec, Value.DecBoolStatus);
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator +(SmallDec self, ModerateSuperDec y)
        {
            self += (SmallDec)y;
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator -(SmallDec self, ModerateSuperDec y)
        {
            self -= (SmallDec)y;
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator *(SmallDec self, ModerateSuperDec y)
        {
            self *= (SmallDec)y;
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="self"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public static SmallDec operator /(SmallDec self, ModerateSuperDec y)
        {
            self /= (SmallDec)y;
            return self;
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator SmallDec(MediumSuperDec Value)
        {
            return new SmallDec(Value);
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator SmallDec(ModerateSuperDec Value)
        {
            return new SmallDec().Convert(Value);
        }

        /// <summary>
        /// </summary>
        /// <param name="Value"></param>
        public static explicit operator SmallDec(LargeSuperDec Value)
        {
            return new SmallDec().Convert(Value);
        }
#endif

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(List<float> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(IReadOnlyList<float> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(List<int> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(List<long> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(List<dynamic> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<SmallDec> CreateList(List<double> ListValue)
        {
            var NewList = new List<SmallDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((SmallDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        public static explicit operator SmallDec(List<float> ListValue)
        {
            var Sum = SmallDec.Zero;
            foreach (var value in ListValue)
            {
                Sum += value;
            }
            return Sum;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        public static explicit operator SmallDec(List<double> ListValue)
        {
            var Sum = SmallDec.Zero;
            foreach (var value in ListValue)
            {
                Sum += value;
            }
            return Sum;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        public static explicit operator SmallDec(List<decimal> ListValue)
        {
            var Sum = SmallDec.Zero;
            foreach (var value in ListValue)
            {
                Sum += value;
            }
            return Sum;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        public static explicit operator SmallDec(List<int> ListValue)
        {
            var Sum = SmallDec.Zero;
            foreach (var value in ListValue)
            {
                Sum += value;
            }
            return Sum;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        public static explicit operator SmallDec(List<long> ListValue)
        {
            var Sum = SmallDec.Zero;
            foreach (var value in ListValue)
            {
                Sum += value;
            }
            return Sum;
        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator SmallDec(bool value)
        {
            if (value == false)
            {
                return SmallDec.Zero;
            }
            else
            {
                return 1;
            }
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public double AsDouble()
        {
            return (double)this;
        }

        /// <summary>
        /// </summary>
        /// <returns></returns>
        public int AsInt()
        {
            return (int)this;
        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator SmallDec(BinaryReader value)
        {
            return (SmallDec)value.ToString();
        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator SmallDec(Stream value)
        {
            return (SmallDec)value.ToString();
        }

        /// <summary>
        /// Convert from List(SmallDec) to List(float)
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<float> ConvertToFloatList(List<SmallDec> ListValue)
        {
            List<float> NewList = new List<float>();
            foreach (var value in ListValue)
            {
                NewList.Add((float)value);
            }
            return NewList;
        }
    }

    //class SmallDecTuple : Tuple<string, SmallDec>
    //{
    //}
}