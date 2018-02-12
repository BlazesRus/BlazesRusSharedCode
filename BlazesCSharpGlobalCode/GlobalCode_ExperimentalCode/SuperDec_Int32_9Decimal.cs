/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/

using System;

//Does not need BigMath library to compile

//CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec
namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;

    /// <summary>
    /// Represent +- 4294967295.999999999 with 100% consistency of accuracy
    /// <para/>(Aka (Aka SuperDec_Int32_9Decimal))
	/// <para/>Requires BigMath library to compile for operation functionality other than +- unless use alternative code
    /// </summary>
    //[System.ComponentModel.TypeConverter(typeof(MediumDec_TypeConverter))]
    ////[System.Security.SecurityCriticalAttribute]//Allow reflection permissions ;Removing Security Critical status since messes up its usage inside xaml GUIs
    //[CLSCompliant(false)]
    //[SerializableAttribute]
    //[BindableAttribute(true, BindingDirection.TwoWay)]
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
    MediumDec : INotifyPropertyChanged//, IComparable<MediumDec>,IConvertible, IEquatable<MediumDec>, IFormattable
    {
        static int NegativeWholeNumber = -1000000000;
        static int DecimalOverflow = 1000000000;

        /// <summary>
        /// Stores decimal section info and Negative/Positive Status(9 Decimal places stored)
        /// </summary>
        private int decimalStatus;

        /// <summary>
        /// Stores decimal section info and Negative/Positive Status(9 Decimal places stored)
        /// </summary>
        public int DecimalStatus
        {
            get
            {
                return decimalStatus;
            }

            set
            {
                decimalStatus = value;
            }
        }

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        private uint intValue;

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        public uint IntValue
        {
            get
            {
                return intValue;
            }

            set
            {
                intValue = value;
            }
        }

        ///// <summary>
        ///// Finds sum of Value Container
        ///// </summary>
        ///// <param name="Value"></param>
        ///// <returns></returns>
        //public static MediumDec Sum(IEnumerable<MediumDec> Value)
        //{
        //    var TotalSum = MediumDec.Zero;
        //    foreach (var Element in Value)
        //    {
        //        TotalSum += Element;
        //    }
        //    return TotalSum;
        //}

        /// <summary>
        /// Parses string value into MediumDec
        /// </summary>
        /// <param name="value"></param>
        /// <param name="invariantCulture"></param>
        /// <returns></returns>
        public static MediumDec Parse(string value, CultureInfo invariantCulture)
        {
            MediumDec NewValue = MediumDec.Initialize(value);
            return NewValue;
        }

        /// <summary>
        /// Parses string value into MediumDec
        /// </summary>
        /// <param name="value"></param>
        /// <param name="MediumDec"></param>
        /// <param name="culture"></param>
        /// <param name="OutputValue"></param>
        /// <returns></returns>
        public static bool TryParse(string value, object MediumDec, CultureInfo culture, out MediumDec OutputValue)
        {
            OutputValue = Parse(value, culture);
            return true;
        }

        /// <summary>
        /// Return largest of parameters
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static MediumDec Max(dynamic LeftSide, dynamic RightSide)
        {
            var LeftSideAsType = (MediumDec)LeftSide;
            var RightSideAsType = (MediumDec)RightSide;
            return LeftSideAsType > RightSide ? LeftSideAsType : RightSideAsType;
        }

        /// <summary>
        /// Return the smallest of parameters
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static MediumDec Min(dynamic LeftSide, dynamic RightSide)
        {
            var LeftSideAsType = (MediumDec)LeftSide;
            var RightSideAsType = (MediumDec)RightSide;
            return LeftSideAsType < RightSide ? LeftSideAsType : RightSideAsType;
        }

        /// <summary>
        /// Method version to Initialize Type instead of with Explicit operators
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static MediumDec Initialize(dynamic Value) => new MediumDec(Value);

        /// <summary>
        /// Initialize constructor
        /// </summary>
        /// <param name="Value"></param>
        public MediumDec(dynamic Value)
        {
            //Use to to detect different assembly versions of MediumDec class
            Type ValueType = (Value as object).GetType();
            string ValueTypeName = ValueType.FullName;
            //((System.Runtime.Remoting.ObjectHandle)Value).Unwrap().GetType().ToString();
            if (ValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec" || ValueType == typeof(MediumDec))
            {
                this.intValue = Value.IntValue;
                this.decimalStatus = Value.DecimalStatus;
            }
            else if (Value == null)
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = MediumDec.Zero;
#else
                this.IntValue = 0;
                this.DecimalStatus = 0;
#endif
            }
            else if (ValueType == typeof(string))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (string)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(float))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (float)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(double))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (double)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(decimal))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (decimal)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(int))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (int)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(long))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (long)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
                this.decimalStatus = TempSelf.DecimalStatus;
#endif
            }
            else if (ValueType == typeof(uint))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (uint)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
#endif
            }
            else if (ValueType == typeof(ulong))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (ulong)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
#endif
            }
            else if (ValueType == typeof(byte))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (byte)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
#endif
            }
            else if (ValueType == typeof(sbyte))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (sbyte)Value;
#else
                MediumDec TempSelf = (MediumDec)Value;
                this.intValue = TempSelf.IntValue;
#endif
            }
            else if (ValueType == typeof(short))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (short)Value;
#else

#endif
            }
            else if (ValueType == typeof(ushort))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (ushort)Value;
#else

#endif
            }
            else if (ValueType == typeof(bool))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (MediumDec)(bool)Value;
#else

#endif
            }
            else if (ValueType == typeof(char))
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = (char)(short)Value;
#else

#endif
            }
            else if (ValueType.IsValueType)
            {
                dynamic ConvertedValue = Activator.CreateInstance(ValueType);
                ConvertedValue = System.Convert.ChangeType(Value, ValueType, CultureInfo.CurrentCulture);
#if (BlazesGlobalCode_MediumDec_AsStruct)
                this = ConvertedValue;
#else
                this.IntValue = 0;
                this.DecimalStatus = 0;
#endif
            }
            else
            {
#if (BlazesGlobalCode_MediumDec_AsStruct)
#pragma warning disable EA002 // Swallow exceptions considered harmful
                try
                {
                    //dynamic changedObj = System.Convert.ChangeType(this.ToOptimalString(), conversionType, provider);
                    //this = changedObj;
                    dynamic ConvertedValue = default(ValueType);
                    ConvertedValue = Value;
                    this = ConvertedValue;
                }
                catch
                {
                    try
                    {
                        this = Value.ToString();
                    }
                    catch
                    {
                        this = MediumDec.Zero;
                    }
                }
#pragma warning restore EA002 // Swallow exceptions considered harmful
#else
                this.IntValue = 0;
                this.DecimalStatus = 0;
#endif
            }
        }

//        /// <summary>
//        ///
//        /// </summary>
//        /// <param name="value"></param>
//        /// <returns></returns>
//        public override bool Equals(object value)
//        {
//            //Enable comparisons against other object types
//            if (value == null) { return false; }

//            try
//            {
//                Type valueType = value.GetType();
//                string FullValueTypeName = valueType.FullName;
//                if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec")//MediumDec to MediumDec Comparison
//                {
//                    if (value.GetType() != typeof(MediumDec))//Alternative assembly version of MediumDec Detected
//                    {
//                        dynamic ConvertedValue = Activator.CreateInstance(value.GetType());
//                        ConvertedValue = this;
//                        return this == (MediumDec)ConvertedValue;
//                    }
//                    else
//                    {
//                        return this == (MediumDec)value;
//                    }
//                }
//                else
//                {
//                    if (valueType == typeof(string))
//                    {
//                        return this == (string)value;
//                    }
//                    else if (valueType == typeof(float))
//                    {
//                        return this == (float)value;
//                    }
//                    else if (valueType == typeof(double))
//                    {
//                        return this == (double)value;
//                    }
//                    else if (valueType == typeof(decimal))
//                    {
//                        return this == (decimal)value;
//                    }
//                    else if (valueType == typeof(int))
//                    {
//                        return this == (int)value;
//                    }
//                    else if (valueType == typeof(long))
//                    {
//                        return this == (long)value;
//                    }
//                    else if (valueType == typeof(uint))
//                    {
//                        return this == (uint)value;
//                    }
//                    else if (valueType == typeof(ulong))
//                    {
//                        return this == (ulong)value;
//                    }
//                    else if (valueType == typeof(byte))
//                    {
//                        return this == (byte)value;
//                    }
//                    else if (valueType == typeof(sbyte))
//                    {
//                        return this == (sbyte)value;
//                    }
//                    else if (valueType == typeof(short))
//                    {
//                        return this == (short)value;
//                    }
//                    else if (valueType == typeof(ushort))
//                    {
//                        return this == (ushort)value;
//                    }
//                    else if (valueType == typeof(bool))
//                    {
//                        return this == (MediumDec)(bool)value;
//                    }
//                    else if (valueType == typeof(char))
//                    {
//                        return this == (char)(short)value;
//                    }
//                    //Dependency Property
//                    else if (FullValueTypeName == "MS.Internal.NamedObject")
//                    {
//                        return this == MediumDec.Zero;
//                    }
//                    else
//                    {
//                        Console.WriteLine("Equals Comparison Test for " + valueType.ToString());
//                        dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
//                        return this == MediumDec.Initialize(changedObj);
//                    }
//                }
//            }
//            catch
//#if (DEBUG)
//            (Exception ex)
//#endif
//            {
//#if (DEBUG)
//                Console.WriteLine("Exception named ");
//                Console.WriteLine(ex.ToString());
//                Console.WriteLine("caught in Equals Method.");
//#endif
//                return false;
//            }
//        }

        /// <summary>
        /// Override the Object.GetHashCode() method
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            return DecimalStatus;
        }

        /// <summary>
        /// Return value as signed int 32 value
        /// </summary>
        /// <returns></returns>
        public int GetIntValueAsInt32()
        {
            return (int)intValue;
        }

        /// <summary>
        /// Method check that returns if represented number is negative
        /// </summary>
        /// <returns></returns>
        public bool IsNegative()
        {
            return DecimalStatus < 0;
        }

        /// <summary>
        /// Switch from positive to negative and back
        /// </summary>
        public void SwapNegativeStatus()
        {
            DecimalStatus *= -1;
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        /// <returns></returns>
        private static MediumDec MaximumValue()
        {
            return new MediumDec(4294967295, 999999999);
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static MediumDec Maximum = MaximumValue();

        //Returns value of lowest non-infinite/Special Decimal State Value that can store
        private static MediumDec MinimumValue()
        {
            return new MediumDec(4294967295, -999999999);
        }

        /// <summary>
        /// Returns value of lowest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static readonly MediumDec Minimum = MinimumValue();

        /// <summary>
        ///
        /// </summary>
        /// <returns></returns>
        public bool IsInfinity()
        {
            return false;
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
        /// <param name="Value"></param>
        /// <returns></returns>
        public static MediumDec DynamicConversionFrom(dynamic Value) => (MediumDec)Value;

        //      /// <summary>
        //      ///
        //      /// </summary>
        //      /// <param name="self"></param>
        //      /// <returns></returns>
        //      public static MediumDec SumOfList(MediumDec[] self)
        //      {
        //          var Total = MediumDec.Zero;
        //          foreach (MediumDec Element in self)
        //          {
        //              Total += Element;
        //          }
        //          return Total;
        //      }

        //      /// <summary>
        //      ///
        //      /// </summary>
        //      /// <param name="self"></param>
        //      /// <returns></returns>
        //      public static MediumDec SumOfList(IEnumerable<MediumDec> self)
        //      {
        //          var Total = MediumDec.Zero;
        //          foreach (MediumDec Element in self)
        //          {
        //              Total += Element;
        //          }
        //          return Total;
        //      }

        /// <summary>
        ///
        /// </summary>
        /// <returns></returns>
        public bool IsNull()
        {
#if (BlazesGlobalCode_MediumDec_AsStruct)
            return false;
#else
            return this == null;
#endif
        }

        private static MediumDec ZeroValue()
        {
            return new MediumDec(0, 0);
        }

        /// <summary>
        /// Value at zero
        /// </summary>
        public static readonly MediumDec Zero = ZeroValue();

        private static MediumDec NaNValue()
        {//No NaN definition for now
            return new MediumDec(0, 0);
        }

        /// <summary>
        /// Value at either zero or NaN (depending on preprocessor settings)
        /// </summary>
        public static readonly MediumDec NaN = NaNValue();

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="other"></param>
        ///// <returns></returns>
        //int IComparable<MediumDec>.CompareTo(MediumDec other)
        //{
        //    if (other == this)
        //    {
        //        return 0;
        //    }
        //    else if (this < other)
        //    {
        //        return -1;
        //    }
        //    else
        //    {
        //        return 1;
        //    }
        //}

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="CompareTarget"></param>
        ///// <param name="RangeWithin"></param>
        ///// <returns></returns>
        //public bool AlmostEquals(dynamic CompareTarget, dynamic RangeWithin)
        //{
        //    MediumDec ConvertedTarget = (MediumDec)CompareTarget;
        //    if (ConvertedTarget == this) { return true; }
        //    else
        //    {
        //        MediumDec LeftRange = ConvertedTarget - RangeWithin;
        //        MediumDec RightRange = ConvertedTarget + RangeWithin;
        //        return this == LeftRange || this == RightRange ? true : this > LeftRange && this < RightRange ? true : false;
        //    }
        //}

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="value"></param>
        ///// <returns></returns>
        //public int CompareTo(object value)
        //{
        //    string FullValueTypeName = value.GetType().FullName;
        //    MediumDec OtherAsSelfType = ObjectAsMediumDec(value);
        //    switch (FullValueTypeName)
        //    {
        //        case "MS.Internal.NamedObject":
        //            return this.decimalStatus == 0 ? (this == MediumDec.Zero ? 0 : 1) : -1;

        //        default:
        //            {
        //                if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec")//MediumDec comparisons
        //                {
        //                    if (value.GetType() != typeof(MediumDec))//Alternative assembly version of MediumDec
        //                    {
        //                        MediumDec ValueAsThisType = MediumDec.ObjectAsMediumDec(value);
        //                        return this.CompareTo(ValueAsThisType);
        //                    }
        //                    else
        //                    {
        //                        return this.CompareTo((MediumDec)value);
        //                    }
        //                }
        //                else
        //                {
        //                    if (OtherAsSelfType == this)
        //                    {
        //                        return 0;
        //                    }
        //                    else if (this < OtherAsSelfType)
        //                    {
        //                        return -1;
        //                    }
        //                    else
        //                    {
        //                        return 1;
        //                    }
        //                }
        //            }
        //    }
        //}

        ///// <summary>
        /////
        ///// </summary>
        ///// <param name="other"></param>
        ///// <returns></returns>
        //public int CompareTo(MediumDec other)
        //{
        //    if (other == this)
        //    {
        //        return 0;
        //    }
        //    else if (this < other)
        //    {
        //        return -1;
        //    }
        //    else
        //    {
        //        return 1;
        //    }
        //}

        /// <summary>
        ///
        /// </summary>
        /// <param name="IntValue"></param>
        /// <param name="DecimalStatus"></param>
        private MediumDec(uint IntValue, int DecimalStatus)
        {
            this.intValue = IntValue;
            this.decimalStatus = DecimalStatus;
        }

#if (!BlazesGlobalCode_MediumDec_AsStruct)

        /// <summary>
        /// Copy Constructor for class
        /// </summary>
        /// <param name="value"></param>
        private MediumDec(MediumDec value)
        {
            this.intValue = value.IntValue;
            this.decimalStatus = value.DecimalStatus;
        }

        public MediumDec()
        {
            this.intValue = 0;
            this.decimalStatus = 0;
        }

#endif

        /// <summary>
        ///
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        public bool Equals(MediumDec other)
        {
            return this == other;
        }

        ///// <summary>
        ///// Change variable into string with certain formating style with culture info set
        ///// </summary>
        ///// <param name="format"></param>
        ///// <param name="formatProvider"></param>
        ///// <returns></returns>
        //public string ToString(string format, IFormatProvider formatProvider)
        //{
        //    return String.Format(formatProvider, this.ToOptimalString());
        //}

//        /// <summary>
//        /// Convert Object into MediumDec for comparison etc
//        /// </summary>
//        /// <param name="value"></param>
//        /// <returns></returns>
//        public static MediumDec ObjectAsMediumDec(object value)
//        {
//            Type valueType = value.GetType();
//            string FullValueTypeName = valueType.FullName;
//            if (valueType == typeof(string))
//            {
//                return (MediumDec)(string)value;
//            }
//            else if (valueType == typeof(float))
//            {
//                return (MediumDec)(float)value;
//            }
//            else if (valueType == typeof(double))
//            {
//                return (MediumDec)(double)value;
//            }
//            else if (valueType == typeof(decimal))
//            {
//                return (MediumDec)(decimal)value;
//            }
//            else if (valueType == typeof(int))
//            {
//                return (MediumDec)(int)value;
//            }
//            else if (valueType == typeof(long))
//            {
//                return (MediumDec)(long)value;
//            }
//            else if (valueType == typeof(uint))
//            {
//                return (MediumDec)(uint)value;
//            }
//            else if (valueType == typeof(ulong))
//            {
//                return (MediumDec)(ulong)value;
//            }
//            else if (valueType == typeof(byte))
//            {
//                return (MediumDec)(byte)value;
//            }
//            else if (valueType == typeof(sbyte))
//            {
//                return (MediumDec)(sbyte)value;
//            }
//            else if (valueType == typeof(short))
//            {
//                return (MediumDec)(short)value;
//            }
//            else if (valueType == typeof(ushort))
//            {
//                return (MediumDec)(ushort)value;
//            }
//            else if (valueType == typeof(bool))
//            {
//                return (MediumDec)(bool)value;
//            }
//            else if (valueType == typeof(char))
//            {
//                return (MediumDec)(char)(short)value;
//            }
//            //Dependency Property with unset value?
//            else if (FullValueTypeName == "MS.Internal.NamedObject")
//            {
//                //if (value._name == "DependencyProperty.UnsetValue")//Initialize at zero
//                //{
//                //    return MediumDec.Zero;
//                //}
//                //else
//                //{
//                //    return (MediumDec)value._name;
//                //}
//                return MediumDec.Zero;
//            }
//#if (GlobalCode_EnableDependencyPropStuff)
//            else if (valueType == typeof(DependencyProperty))
//            {
//                DependencyProperty self = (DependencyProperty)value;
//                return (MediumDec)self;
//            }
//#endif
//            else
//            {
//                dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
//                return (MediumDec)changedObj;
//            }
//        }

        #region INotifyPropertyChanged Members

        public event PropertyChangedEventHandler PropertyChanged;

        /// Need to implement this interface in order to get data binding
        /// to work properly.
        private void NotifyPropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        #endregion INotifyPropertyChanged Members
    }
}