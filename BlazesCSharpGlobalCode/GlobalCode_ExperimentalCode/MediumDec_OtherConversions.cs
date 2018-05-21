/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.IO;

    // Represents +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka SuperDec_Int32_9Decimal)
    public
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesGlobalCode_MediumDec_AsStruct)
    class
#else
    struct
#endif
    MediumDec : IFormattable, INotifyPropertyChanged
    {
        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        /// <returns></returns>
        //        public static Tuple<string, MediumDec> ConvertTuple(Tuple<string, dynamic> Value)
        //        {
        //            Tuple<string, MediumDec> self = Tuple.Create(Value.Item1, (MediumDec)Value.Item2);
        //            return self;
        //        }

        //        //public static implicit operator Tuple<string, MediumDec>(Tuple<string, dynamic> Value)
        //        //{
        //        //	return ConvertTuple(Value);
        //        //}

        /// <summary>
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static dynamic DynamicMax(dynamic LeftSide, dynamic RightSide)
        {
            MediumDec LeftSideAsType = (MediumDec)LeftSide;
            MediumDec RightSideAsType = (MediumDec)RightSide;
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

        //#if (!BlazesGlobalCode_RestrictConversionBetweenSuperDec)
        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        /// <returns></returns>
        //        public MediumDec Convert(ModerateSuperDec Value)
        //        {
        //            ulong TempDec = Value.DecimalStatus;
        //            TempDec /= 1000000000000000;
        //            return new MediumDec((ushort)Value.IntValue, (ushort) TempDec, Value.DecBoolStatus);
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        /// <returns></returns>
        //        public MediumDec Convert(LargeSuperDec Value)
        //        {
        //            ulong TempDec = Value.DecimalStatus / 100000000000000;
        //            return new MediumDec((ushort)Value.IntValue, (ushort)TempDec, Value.DecBoolStatus);
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="self"></param>
        //        /// <param name="y"></param>
        //        /// <returns></returns>
        //        public static MediumDec operator +(MediumDec self, ModerateSuperDec y)
        //        {
        //            self += (MediumDec)y;
        //            return self;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="self"></param>
        //        /// <param name="y"></param>
        //        /// <returns></returns>
        //        public static MediumDec operator -(MediumDec self, ModerateSuperDec y)
        //        {
        //            self -= (MediumDec)y;
        //            return self;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="self"></param>
        //        /// <param name="y"></param>
        //        /// <returns></returns>
        //        public static MediumDec operator *(MediumDec self, ModerateSuperDec y)
        //        {
        //            self *= (MediumDec)y;
        //            return self;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="self"></param>
        //        /// <param name="y"></param>
        //        /// <returns></returns>
        //        public static MediumDec operator /(MediumDec self, ModerateSuperDec y)
        //        {
        //            self /= (MediumDec)y;
        //            return self;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        public static explicit operator MediumDec(MediumDec Value)
        //        {
        //            return new MediumDec(Value);
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        public static explicit operator MediumDec(ModerateSuperDec Value)
        //        {
        //            return new MediumDec().Convert(Value);
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="Value"></param>
        //        public static explicit operator MediumDec(LargeSuperDec Value)
        //        {
        //            return new MediumDec().Convert(Value);
        //        }
        //#endif

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(List<float> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(IReadOnlyList<float> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(List<int> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(List<long> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(List<dynamic> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        /// <summary>
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<MediumDec> CreateList(List<double> ListValue)
        {
            var NewList = new List<MediumDec>();
            foreach (var value in ListValue)
            {
                NewList.Add((MediumDec)value);
            }
            return NewList;
        }

        ///// <summary>
        ///// </summary>
        ///// <param name="ListValue"></param>
        //public static explicit operator MediumDec(List<float> ListValue)
        //{
        //    var Sum = MediumDec.Zero;
        //    foreach (var value in ListValue)
        //    {
        //        Sum += value;
        //    }
        //    return Sum;
        //}

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="ListValue"></param>
        //        public static explicit operator MediumDec(List<double> ListValue)
        //        {
        //            var Sum = MediumDec.Zero;
        //            foreach (var value in ListValue)
        //            {
        //                Sum += value;
        //            }
        //            return Sum;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="ListValue"></param>
        //        public static explicit operator MediumDec(List<decimal> ListValue)
        //        {
        //            var Sum = MediumDec.Zero;
        //            foreach (var value in ListValue)
        //            {
        //                Sum += value;
        //            }
        //            return Sum;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="ListValue"></param>
        //        public static explicit operator MediumDec(List<int> ListValue)
        //        {
        //            var Sum = MediumDec.Zero;
        //            foreach (var value in ListValue)
        //            {
        //                Sum += value;
        //            }
        //            return Sum;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <param name="ListValue"></param>
        //        public static explicit operator MediumDec(List<long> ListValue)
        //        {
        //            var Sum = MediumDec.Zero;
        //            foreach (var value in ListValue)
        //            {
        //                Sum += value;
        //            }
        //            return Sum;
        //        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator MediumDec(bool value)
        {
            if (value == false)
            {
                return MediumDec.Zero;
            }
            else
            {
                return new MediumDec(1,0);
            }
        }

        //        /// <summary>
        //        /// </summary>
        //        /// <returns></returns>
        //        public double AsDouble()
        //        {
        //            return (double)this;
        //        }

        //        /// <summary>
        //        /// </summary>
        //        /// <returns></returns>
        //        public int AsInt()
        //        {
        //            return (int)this;
        //        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator MediumDec(BinaryReader value)
        {
            return (MediumDec)value.ToString();
        }

        /// <summary>
        /// </summary>
        /// <param name="value"></param>
        public static explicit operator MediumDec(Stream value)
        {
            return (MediumDec)value.ToString();
        }

        /// <summary>
        /// Convert from List(MediumDec) to List(float)
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<float> ConvertToFloatList(List<MediumDec> ListValue)
        {
            List<float> NewList = new List<float>();
            foreach (var value in ListValue)
            {
                NewList.Add((float)value);
            }
            return NewList;
        }

        /// <summary>
        /// Convert from List(MediumDec) to List(double)
        /// </summary>
        /// <param name="ListValue"></param>
        /// <returns></returns>
        public static List<double> ConvertToDoubleList(List<MediumDec> ListValue)
        {
            List<double> NewList = new List<double>();
            foreach (var value in ListValue)
            {
                NewList.Add((double)value);
            }
            return NewList;
        }

        public static explicit operator MediumDec(SmallDec Value)
        {
            return new MediumDec(Value.IntValue, Value.DecimalStatus);
        }
    }

    //class MediumDecTuple : Tuple<string, MediumDec>
    //{
    //}
}
