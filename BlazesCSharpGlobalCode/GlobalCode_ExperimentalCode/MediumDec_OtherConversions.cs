/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

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

		/// <summary>
		/// Determines whether the specified value is infinity.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>
		///   <c>true</c> if the specified value is infinity; otherwise, <c>false</c>.
		/// </returns>
		public bool IsInfinity(MediumDec Value) => false;

		/// <summary>
		/// Determines whether [the specified value] is NaN.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>
		///   <c>true</c> if [is na n] [the specified value]; otherwise, <c>false</c>.
		/// </returns>
		public bool IsNaN(MediumDec Value) => this == null ? true : false;
    }

    //class MediumDecTuple : Tuple<string, MediumDec>
    //{
    //}
}
