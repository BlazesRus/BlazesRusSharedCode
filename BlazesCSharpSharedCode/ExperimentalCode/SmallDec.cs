/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/

using System;

//Does not need BigMath library to compile

//CSharpSharedCode.ExperimentalCode.SmallDec
namespace CSharpSharedCode.ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Globalization;

    /// <summary>
    /// Represent +- 65535.999999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    /// <para/>(Aka SuperDec_Int16_9Decimal Or SuperDec_Int16_4Decimal)
    /// </summary>
    //[System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
    ////[System.Security.SecurityCriticalAttribute]//Allow reflection permissions ;Removing Security Critical status since messes up its usage inside xaml GUIs
    //[CLSCompliant(false)]
    //[SerializableAttribute]
    //[BindableAttribute(true, BindingDirection.TwoWay)]
    public
#if (!BlazesSharedCode_SmallDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesSharedCode_SmallDec_AsStruct)
    class
#else
    struct
#endif
    SmallDec : IFormattable, INotifyPropertyChanged, IComparable<SmallDec>, IConvertible, IEquatable<SmallDec>
    {
#if (SmallDec_ReducedSize)
        public static short NegativeWholeNumber = -10000;
#elif(!SmallDec_UseLegacyStorage)
        public static int NegativeWholeNumber = -1000000000;
#endif
#if (SmallDec_ReducedSize||SmallDec_UseLegacyStorage)
        public static short DecimalOverflow = 10000;
#else
        public static int DecimalOverflow = 1000000000;
#endif

        /// <summary>
        /// Static variable for displaying how alternative decimal states are handles and such
        /// (so that other assembly versions of the type can see how to handle conversions)<para/>
        /// Default(0): Store 9 Decimal Places and negative/positive status inside int value<para/>
        /// SmallDec_ReducedSize(1) : Disable DecBoolStatus and instead use decimalStatus as short to store positive/negative status<para/>
        /// SmallDec_UseLegacyStorage(2) : Use  DecBoolStatus to store negative/positive status<para/>
        /// </summary>
        public static byte AlternativeDecimalStateMode
#if (SmallDec_ReducedSize)
        = 1;
#elif (SmallDec_UseLegacyStorage)
        = 2;
#else
        = 0;

#endif

#if (SmallDec_UseLegacyStorage)
        /// <summary>
        /// 0 = Positive;1=Negative;Other states at higher then 1;254 = Positive Infinity;255 = Negative Infinity
        /// </summary>
        public byte decBoolStatus;

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        public byte DecBoolStatus
        {
            get
            {
                return decBoolStatus;
            }

            set
            {
                decBoolStatus = value;
            }
        }
#endif

#if (SmallDec_UseLegacyStorage)
        /// <summary>
        /// Stores decimal section info (4 Decimal places stored)
        /// </summary>
        private ushort decimalStatus;

        /// <summary>
        /// Stores decimal section info (4 Decimal places stored)
        /// </summary>
        public ushort DecimalStatus
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
#elif (SmallDec_ReducedSize)
        /// <summary>
        /// Stores decimal section info and Negative/Positive Status(4 Decimal places stored)
        /// </summary>
        private short decimalStatus;

        /// <summary>
        /// Stores decimal section info and Negative/Positive Status(4 Decimal places stored)
        /// </summary>
        public short DecimalStatus
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
#else

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

#endif

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        private ushort intValue;

        /// <summary>
        /// Stores whole half of number
        /// </summary>
        public ushort IntValue
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

        /// <summary>
        /// Finds sum of Value Container
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Sum(IEnumerable<SmallDec> Value)
        {
            var TotalSum = SmallDec.Zero;
            foreach (var Element in Value)
            {
                TotalSum += Element;
            }
            return TotalSum;
        }

        /// <summary>
        /// Parses string value into SmallDec
        /// </summary>
        /// <param name="value"></param>
        /// <param name="TargetCulture"></param>
        /// <returns></returns>
        public static SmallDec Parse(string value, CultureInfo TargetCulture = null)
        {
            //if(TargetCulture==null)
            //{
            //    TargetCulture = CultureInfo.CurrentUICulture;
            //}
            SmallDec NewValue = SmallDec.GetValueFromString(value);
            return NewValue;
        }

        /// <summary>
        /// Parses string value into SmallDec
        /// </summary>
        /// <param name="value"></param>
        /// <param name="smallDec"></param>
        /// <param name="culture"></param>
        /// <param name="OutputValue"></param>
        /// <returns></returns>
        public static bool TryParse(string value, object smallDec, CultureInfo culture, out SmallDec OutputValue)
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
        public static SmallDec Max(dynamic LeftSide, dynamic RightSide)
        {
            var LeftSideAsType = (SmallDec)LeftSide;
            var RightSideAsType = (SmallDec)RightSide;
            return LeftSideAsType > RightSide ? LeftSideAsType : RightSideAsType;
        }

        /// <summary>
        /// Return the smallest of parameters
        /// </summary>
        /// <param name="LeftSide"></param>
        /// <param name="RightSide"></param>
        /// <returns></returns>
        public static SmallDec Min(dynamic LeftSide, dynamic RightSide)
        {
            var LeftSideAsType = (SmallDec)LeftSide;
            var RightSideAsType = (SmallDec)RightSide;
            return LeftSideAsType < RightSide ? LeftSideAsType : RightSideAsType;
        }

        /// <summary>
        /// Method version to Initialize Type instead of with Explicit operators
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static SmallDec Initialize(dynamic Value) => new SmallDec(Value);

        /// <summary>
        /// Initialize constructor
        /// </summary>
        /// <param name="Value"></param>
        public SmallDec(dynamic Value)
        {
            TypeCode typeCode = Type.GetTypeCode(Value.GetType());
            int typeCodeValue = (int)typeCode;
#if (!BlazesSharedCode_SmallDec_AsStruct)
            if (typeCodeValue >= 3 && typeCodeValue <= 12)//Integer based Value types+Bool
            {
                if (Value < 0)
                {
                    Value *= -1;
                    this.IntValue = Value;
                    this.DecimalStatus = NegativeWholeNumber;
                }
                else
                {
                    this.IntValue = Value;
                    this.DecimalStatus = 0;
                }
            }
            else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based Value types
            {
                SmallDec NewSelf = new SmallDec();
                switch (typeCode)
                {
                    case TypeCode.Single:
                        NewSelf = (SmallDec)(float)Value; break;
                    case TypeCode.Double:
                        NewSelf = (SmallDec)(double)Value; break;
                    case TypeCode.Decimal:
                        NewSelf = (SmallDec)(decimal)Value; break;
                    default:
                        NewSelf = (SmallDec)Value; break;
                }
            }
            else if (typeCode == TypeCode.String)
            {
                SmallDec NewSelf = SmallDec.GetValueFromString(Value as string);
                this.IntValue = NewSelf.IntValue;
                this.DecimalStatus = NewSelf.DecimalStatus;
#if (SmallDec_UseLegacyStorage)
                this.DecBoolStatus = Value.DecBoolStatus;
#endif
            }
            else
#endif
                if (Value == null)
            {
#if (BlazesSharedCode_SmallDec_AsStruct)
                this = SmallDec.Zero;
#else
                this.IntValue = 0;
                this.DecimalStatus = 0;
#endif
            }
            else
            {
                //Use to to detect different assembly versions of SmallDec class
                Type ValueType = (Value as object).GetType();
                string ValueTypeName = ValueType.FullName;
                if (ValueTypeName == "CSharpSharedCode.ExperimentalCode.SmallDec" || ValueType == typeof(SmallDec))
                {
#if (SmallDec_ReducedSize || SmallDec_UseLegacyStorage)
                this.DecBoolStatus = Value.DecBoolStatus;
#endif
                    this.intValue = Value.IntValue;
                    this.decimalStatus = Value.DecimalStatus;
                }
#if (SmallDec_UseLegacyStorage)
#if (!BlazesSharedCode_Disable128BitFeatures)
                else if (Value is MediumDec)
                {
                    intValue = (ushort)Value.IntValue;
                    uint TempDec = Value.DecimalStatus / 100000;
                    DecimalStatus = (ushort)TempDec;
                    DecBoolStatus = Value.DecBoolStatus;
                }
                else if (Value is ModerateSuperDec)
                {
                    intValue = (ushort)Value.IntValue;
                    ulong TempDec = Value.DecimalStatus / 100000000000000;
                    DecimalStatus = (ushort)TempDec;
                    DecBoolStatus = Value.DecBoolStatus;
                }
                else if (Value is LargeSuperDec)
                {
                    intValue = (ushort)Value.IntValue;
                    ulong TempDec = Value.DecimalStatus / 100000000000000;
                    DecimalStatus = (ushort)TempDec;
                    DecBoolStatus = Value.DecBoolStatus;
                }
#endif
#endif
#if (BlazesSharedCode_SmallDec_AsStruct)
                else if (ValueType == typeof(string))
                {
                    this = (string)Value;
                }
                else if (ValueType == typeof(float))
                {
                    this = (float)Value;
                }
                else if (ValueType == typeof(double))
                {
                    this = (double)Value;
                }
                else if (ValueType == typeof(decimal))
                {
                    this = (decimal)Value;
                }
                else if (ValueType == typeof(int))
                {
                    this = (int)Value;
                }
                else if (ValueType == typeof(long))
                {
                    this = (long)Value;
                }
                else if (ValueType == typeof(uint))
                {
                    this = (uint)Value;
                }
                else if (ValueType == typeof(ulong))
                {
                    this = (ulong)Value;
                }
                else if (ValueType == typeof(byte))
                {
                    this = (byte)Value;
                }
                else if (ValueType == typeof(sbyte))
                {
                    this = (sbyte)Value;
                }
                else if (ValueType == typeof(short))
                {
                    this = (short)Value;
                }
                else if (ValueType == typeof(ushort))
                {
                    this = (ushort)Value;
                }
                else if (ValueType == typeof(bool))
                {
                    this = (SmallDec)(bool)Value;
                }
                else if (ValueType == typeof(char))
                {
                    this = (char)(short)Value;
                }
#else
                else if (ValueType == typeof(char))
                {
                    SmallDec NewSelf = new SmallDec();
                    NewSelf = (SmallDec)(char)(short)Value;
                }
#endif
                else if (ValueType.IsValueType)
                {
                    dynamic ConvertedValue = Activator.CreateInstance(ValueType);
                    ConvertedValue = System.Convert.ChangeType(Value, ValueType, CultureInfo.CurrentCulture);
#if (BlazesSharedCode_SmallDec_AsStruct)
                this = ConvertedValue;
#else
                    this.IntValue = 0;
                    this.DecimalStatus = 0;
#endif
                }
                else
                {
#if (BlazesSharedCode_SmallDec_AsStruct)
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
                        this = SmallDec.Zero;
                    }
                }
#pragma warning restore EA002 // Swallow exceptions considered harmful
#else
                    this.IntValue = 0;
                    this.DecimalStatus = 0;
#endif
                }
            }

            //((System.Runtime.Remoting.ObjectHandle)Value).Unwrap().GetType().ToString();
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public override bool Equals(object value)
        {
            //Enable comparisons against other object types
            if (value == null) { return false; }

            try
            {
                Type valueType = value.GetType();
                string FullValueTypeName = valueType.FullName;
                if (FullValueTypeName == "CSharpSharedCode.ExperimentalCode.SmallDec")//SmallDec to SmallDec Comparison
                {
                    if (value.GetType() != typeof(SmallDec))//Alternative assembly version of SmallDec Detected
                    {
                        dynamic ConvertedValue = Activator.CreateInstance(value.GetType());
                        ConvertedValue = this;
                        return this == (SmallDec)ConvertedValue;
                    }
                    else
                    {
                        return this == (SmallDec)value;
                    }
                }
                else
                {
                    if (valueType == typeof(string))
                    {
                        return this == (string)value;
                    }
                    else if (valueType == typeof(float))
                    {
                        return this == (float)value;
                    }
                    else if (valueType == typeof(double))
                    {
                        return this == (double)value;
                    }
                    else if (valueType == typeof(decimal))
                    {
                        return this == (decimal)value;
                    }
                    else if (valueType == typeof(int))
                    {
                        return this == (int)value;
                    }
                    else if (valueType == typeof(long))
                    {
                        return this == (long)value;
                    }
                    else if (valueType == typeof(uint))
                    {
                        return this == (uint)value;
                    }
                    else if (valueType == typeof(ulong))
                    {
                        return this == (ulong)value;
                    }
                    else if (valueType == typeof(byte))
                    {
                        return this == (byte)value;
                    }
                    else if (valueType == typeof(sbyte))
                    {
                        return this == (sbyte)value;
                    }
                    else if (valueType == typeof(short))
                    {
                        return this == (short)value;
                    }
                    else if (valueType == typeof(ushort))
                    {
                        return this == (ushort)value;
                    }
                    else if (valueType == typeof(bool))
                    {
                        return this == (SmallDec)(bool)value;
                    }
                    else if (valueType == typeof(char))
                    {
                        return this == (char)(short)value;
                    }
                    //Dependency Property
                    else if (FullValueTypeName == "MS.Internal.NamedObject")
                    {
                        return this == SmallDec.Zero;
                    }
                    else
                    {
                        Console.WriteLine("Equals Comparison Test for " + valueType.ToString());
                        dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
                        return this == SmallDec.Initialize(changedObj);
                    }
                }
            }
            catch
#if (DEBUG)
            (Exception ex)
#endif
            {
#if (DEBUG)
                Console.WriteLine("Exception named ");
                Console.WriteLine(ex.ToString());
                Console.WriteLine("caught in Equals Method.");
#endif
                return false;
            }
        }

        /// <summary>
        /// Override the Object.GetHashCode() method
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
#if (SmallDec_ReducedSize)
#elif (SmallDec_UseLegacyStorage)
            if (DecBoolStatus == 1)
            {
                return ((int)intValue + (int)DecimalStatus) * -1;
            }
            else
            {
                return (int)intValue + (int)DecimalStatus;
            }
#else
            return DecimalStatus;
#endif
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
#if (SmallDec_ReducedSize)
            if(decimalStatus==NegativeWholeNumber)//Negative WholeNumber
            {
                decimalStatus = 0;
            }
            else if(decimalStatus==0)//Positive WholeNumber
            {
                decimalStatus = NegativeWholeNumber
            }
            else//Non-WholeNumber
            {
                decimalStatus *= -1;
            }
#elif (SmallDec_UseLegacyStorage)
            return DecBoolStatus == 1;
#else
            return DecimalStatus < 0;
#endif
        }

        /// <summary>
        /// Switch from positive to negative and back
        /// </summary>
        public void SwapNegativeStatus()
        {
#if (SmallDec_ReducedSize)
            if(decimalStatus==NegativeWholeNumber)//Negative WholeNumber
            {
                decimalStatus = 0;
            }
            else if(decimalStatus==0)//Positive WholeNumber
            {
                decimalStatus = NegativeWholeNumber;
            }
            else//Non-WholeNumber
            {
                decimalStatus *= -1;
            }
#elif (SmallDec_UseLegacyStorage)
            if (DecBoolStatus == 0) { DecBoolStatus = 1; }
            else { DecBoolStatus = 0; }
            //#if (BlazesSharedCode_SmallDec_EnableSpecialDecStates||SmallDec_DecimalStateMode_3)
            //            if (DecBoolStatus % 2 == 0) { DecBoolStatus += 1; }
            //            else { DecBoolStatus -= 1; }
#else
            DecimalStatus *= -1;
#endif
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        /// <returns></returns>
        private static SmallDec MaximumValue()
        {
#if (SmallDec_ReducedSize)
            return new SmallDec(65535, 9999);
#elif (SmallDec_UseLegacyStorage)
            return new SmallDec(65535, 9999);
#else
            return new SmallDec(65535, 999999999);
#endif
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static SmallDec Maximum = MaximumValue();

        //Returns value of lowest non-infinite/Special Decimal State Value that can store
        private static SmallDec MinimumValue()
        {
#if (SmallDec_ReducedSize)
            return new SmallDec(65535, -9999);
#elif (SmallDec_UseLegacyStorage)
            return new SmallDec(65535, 9999, 1);
#else
            return new SmallDec(65535, -999999999);
#endif
        }

        /// <summary>
        /// Returns value of lowest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static readonly SmallDec Minimum = MinimumValue();

        /// <summary>
        ///
        /// </summary>
        /// <returns></returns>
        public bool IsInfinity()
        {
#if (SmallDec_UseLegacyStorage)
            return DecBoolStatus == 255 || DecBoolStatus == 254;
#else
            return false;
#endif
        }

#if (SmallDec_ReducedSize || SmallDec_UseLegacyStorage)
        /// <summary>
        /// Represents Positive Infinity(Only checked in in most methods if certain Preprocessor is set;Checks not implimented yet in code)
        /// </summary>
        /// <returns></returns>
        private static SmallDec PositiveInfinityValue()
        {
            return new SmallDec(0, 0, 254);
        }

        /// <summary>
        /// Represents Positive Infinity(Only checked in in most methods if certain Preprocessor is set;Checks not implimented yet in code)
        /// </summary>
        public static SmallDec PositiveInfinity = PositiveInfinityValue();

        /// <summary>
        /// Represents Negative Infinity(Only checked in in most methods if certain Preprocessor is set;Checks not implimented yet in code)
        /// </summary>
        /// <returns></returns>
        private static SmallDec NegativeInfinityValue()
        {
            return new SmallDec(0, 0, 255);
        }

        /// <summary>
        /// Represents Negative Infinity(Only checked in in most methods if certain Preprocessor is set;Checks not implimented yet in code)
        /// </summary>
        public static SmallDec NegativeInfinity = NegativeInfinityValue();
#else//No Negative and Positive Infinity Definitions for now

#endif

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
        public static SmallDec DynamicConversionFrom(dynamic Value) => (SmallDec)Value;

        /// <summary>
        ///
        /// </summary>
        /// <param name="self"></param>
        /// <returns></returns>
        public static SmallDec SumOfList(SmallDec[] self)
        {
            var Total = SmallDec.Zero;
            foreach (SmallDec Element in self)
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
        public static SmallDec SumOfList(IEnumerable<SmallDec> self)
        {
            var Total = SmallDec.Zero;
            foreach (SmallDec Element in self)
            {
                Total += Element;
            }
            return Total;
        }

        /// <summary>
        ///
        /// </summary>
        /// <returns></returns>
        public bool IsNull()
        {
#if (SmallDec_UseLegacyStorage)
            return DecBoolStatus == 202 ? true : false;
#else
#if (BlazesSharedCode_SmallDec_AsStruct)
            return false;
#else
            return this == null;
#endif
#endif
        }

        private static SmallDec ZeroValue()
        {
            return new SmallDec(0, 0);
        }

        /// <summary>
        /// Value at zero
        /// </summary>
        public static readonly SmallDec Zero = ZeroValue();

        /// <summary>
        /// Value at one
        /// </summary>
        public static readonly SmallDec One = OneValue();

        private static SmallDec OneValue() => new SmallDec(1, 0);

        /// <summary>
        /// .000001000
        /// </summary>
        public static readonly SmallDec OneMillionth = OneMillionthValue();

        private static SmallDec OneMillionthValue() => new SmallDec(0, 1000);

        private static SmallDec NaNValue()
        {
#if (SmallDec_ReducedSize || SmallDec_UseLegacyStorage)
#if (BlazesSharedCode_SmallDec_EnableSpecialDecStates)
            return new SmallDec(0, 202);
#else
            return new SmallDec(0, 0);
#endif
#else
#if !BlazesSharedCode_SmallDec_AsStruct && !BlazesSharedCode_ZeroAtNaN
            return null;//NaN is Null unless preprocessor switch is set for BlazesSharedCode_ZeroAtNaN when is class
#else
            return new SmallDec(0, 0);
#endif
#endif
        }

        /// <summary>
        /// Value at either zero or NaN (depending on preprocessor settings)
        /// </summary>
        public static readonly SmallDec NaN = NaNValue();

        /// <summary>
        ///
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        int IComparable<SmallDec>.CompareTo(SmallDec other)
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
            SmallDec ConvertedTarget = (SmallDec)CompareTarget;
            if (ConvertedTarget == this) { return true; }
            else
            {
                SmallDec LeftRange = ConvertedTarget - RangeWithin;
                SmallDec RightRange = ConvertedTarget + RangeWithin;
                return this == LeftRange || this == RightRange ? true : this > LeftRange && this < RightRange ? true : false;
            }
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public int CompareTo(object value)
        {
            string FullValueTypeName = value.GetType().FullName;
            SmallDec OtherAsSelfType = ObjectAsSmallDec(value);
            switch (FullValueTypeName)
            {
                case "MS.Internal.NamedObject":
                    return this.decimalStatus == 0 ? (this == SmallDec.Zero ? 0 : 1) : -1;

                default:
                    {
                        if (FullValueTypeName == "CSharpSharedCode.ExperimentalCode.SmallDec")//SmallDec comparisons
                        {
                            if (value.GetType() != typeof(SmallDec))//Alternative assembly version of SmallDec
                            {
                                SmallDec ValueAsThisType = SmallDec.ObjectAsSmallDec(value);
                                return this.CompareTo(ValueAsThisType);
                            }
                            else
                            {
                                return this.CompareTo((SmallDec)value);
                            }
                        }
                        else
                        {
                            if (OtherAsSelfType == this)
                            {
                                return 0;
                            }
                            else if (this < OtherAsSelfType)
                            {
                                return -1;
                            }
                            else
                            {
                                return 1;
                            }
                        }
                    }
            }
        }

        /// <summary>
        ///
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        public int CompareTo(SmallDec other)
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

#if (SmallDec_ReducedSize || SmallDec_UseLegacyStorage)
        /// <summary>
        ///
        /// </summary>
        /// <param name="IntValue"></param>
        /// <param name="DecimalStatus"></param>
        /// <param name="DecBoolStatus"></param>
        SmallDec(ushort IntValue, ushort DecimalStatus, byte DecBoolStatus = 0)
        {
            this.intValue = IntValue;
            this.decimalStatus = DecimalStatus;
#if (SmallDec_UseLegacyStorage)
            this.DecBoolStatus = DecBoolStatus;
#endif
        }
#else

        /// <summary>
        ///
        /// </summary>
        /// <param name="IntValue"></param>
        /// <param name="DecimalStatus"></param>
        private SmallDec(ushort IntValue, int DecimalStatus)
        {
            this.intValue = IntValue;
            this.decimalStatus = DecimalStatus;
        }

#endif

#if (!BlazesSharedCode_SmallDec_AsStruct)

        /// <summary>
        /// Copy Constructor for class
        /// </summary>
        /// <param name="value"></param>
        private SmallDec(SmallDec value)
        {
            this.intValue = value.IntValue;
            this.decimalStatus = value.DecimalStatus;
#if (SmallDec_UseLegacyStorage)
            this.DecBoolStatus = value.DecBoolStatus;
#endif
        }

        public SmallDec()
        {
            this.intValue = 0;
            this.decimalStatus = 0;
#if (SmallDec_UseLegacyStorage)
            this.decBoolStatus = 0;
#endif
        }

#endif

        /// <summary>
        ///
        /// </summary>
        /// <param name="other"></param>
        /// <returns></returns>
        public bool Equals(SmallDec other)
        {
            return this == other;
        }

        /// <summary>
        /// Change variable into string with certain formating style with culture info set
        /// </summary>
        /// <param name="format"></param>
        /// <param name="formatProvider"></param>
        /// <returns></returns>
        public string ToString(string format, IFormatProvider formatProvider)
        {
            return String.Format(formatProvider, this.ToOptimalString());
        }

        /// <summary>
        /// Convert Object into SmallDec for comparison etc
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public static SmallDec ObjectAsSmallDec(object value)
        {
            Type valueType = value.GetType();
            string FullValueTypeName = valueType.FullName;
            if (valueType == typeof(string))
            {
                return (SmallDec)(string)value;
            }
            else if (valueType == typeof(float))
            {
                return (SmallDec)(float)value;
            }
            else if (valueType == typeof(double))
            {
                return (SmallDec)(double)value;
            }
            else if (valueType == typeof(decimal))
            {
                return (SmallDec)(decimal)value;
            }
            else if (valueType == typeof(int))
            {
                return (SmallDec)(int)value;
            }
            else if (valueType == typeof(long))
            {
                return (SmallDec)(long)value;
            }
            else if (valueType == typeof(uint))
            {
                return (SmallDec)(uint)value;
            }
            else if (valueType == typeof(ulong))
            {
                return (SmallDec)(ulong)value;
            }
            else if (valueType == typeof(byte))
            {
                return (SmallDec)(byte)value;
            }
            else if (valueType == typeof(sbyte))
            {
                return (SmallDec)(sbyte)value;
            }
            else if (valueType == typeof(short))
            {
                return (SmallDec)(short)value;
            }
            else if (valueType == typeof(ushort))
            {
                return (SmallDec)(ushort)value;
            }
            else if (valueType == typeof(bool))
            {
                return (SmallDec)(bool)value;
            }
            else if (valueType == typeof(char))
            {
                return (SmallDec)(char)(short)value;
            }
            //Dependency Property with unset value?
            else if (FullValueTypeName == "MS.Internal.NamedObject")
            {
                //if (value._name == "DependencyProperty.UnsetValue")//Initialize at zero
                //{
                //    return SmallDec.Zero;
                //}
                //else
                //{
                //    return (SmallDec)value._name;
                //}
                return SmallDec.Zero;
            }
#if (SharedCode_EnableDependencyPropStuff)
            else if (valueType == typeof(DependencyProperty))
            {
                DependencyProperty self = (DependencyProperty)value;
                return (SmallDec)self;
            }
#endif
            //else if (FullValueTypeName == "CSharpSharedCode.ExperimentalCode.SmallDec")//SmallDec conversion
            //{
            //    if (typeof(SmallDec) == value.GetType())
            //    {
            //        return (SmallDec)value;
            //    }
            //    else
            //    {
            //        SmallDec OtherValue = SmallDec.Zero;
            //        dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
            //        OtherValue.IntValue = changedObj.IntValue;
            //        OtherValue.DecBoolStatus = changedObj.DecBoolStatus;
            //        OtherValue.DecimalStatus = changedObj.DecimalStatus;
            //        return OtherValue;
            //    }
            //}
            else
            {
                dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
                return (SmallDec)changedObj;
            }
        }

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