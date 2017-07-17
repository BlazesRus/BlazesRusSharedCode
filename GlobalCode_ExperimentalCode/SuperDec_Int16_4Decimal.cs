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
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS0436 // Type conflicts with imported type
#pragma warning disable CS3021 // Type or member does not need a CLSCompliant attribute because the assembly does not have a CLSCompliant attribute
    /// <summary>
    /// Represent +- 65535.9999 with 100% consistency of accuracy(or 6 decimal places worth if SmallDecExpandedDecimal preprocessor used(Not Implemented yet))
    /// (Aka SuperDec_Int16_4Decimal)
    /// </summary>
    [System.ComponentModel.TypeConverter(typeof(SmallDec_TypeConverter))]
    //[System.Security.SecurityCriticalAttribute]//Allow reflection permissions ;Removing Security Critical status since messes up its usage inside xaml GUIs
    [CLSCompliant(false)]
    [SerializableAttribute]
    [BindableAttribute(true, BindingDirection.TwoWay)]
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
        ////Reference current assembly version of type (based on https://stackoverflow.com/questions/909555/how-can-i-get-the-assembly-file-version)
        //private System.Reflection.Assembly CurrentAssembly
        //{
        //    get
        //    {
        //        return System.Reflection.Assembly.GetExecutingAssembly();
        //    }
        //}

        //private Type CurrentType
        //{
        //    get
        //    {
        //        return CurrentAssembly.GetType("CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec");
        //    }
        //}

        /// <summary>
        /// Static variable for displaying how alternative decimal states are handles and such
        /// (so that other assembly versions of the type can see how to handle conversions)<para/>
        /// Default(0): Use  DecBoolStatus to store negative/positive status<para/>
        /// (1) : Disable DecBoolStatus and instead use decimalStatus as short to store positive/negative status<para/>
        /// (2) : Negative/Positive status stored inside decimalStatus as short with DecBoolStatus used to store additional decimal places when needed <para/>
        /// (Extended to maximum 6 decimal places worth stored), and some additional value representations stored such as +/- Infinity<para/>
        /// </summary>
        public static byte AlternativeDecimalStateMode
#if (SmallDec_DecimalStateMode_1)
        = 1;
#elif (SmallDec_DecimalStateMode_2)
        = 2;
#elif (SmallDec_DecimalStateMode_3)
        = 3;
#elif (SmallDec_DecimalStateMode_3)
        = 4;
#else
        = 0;
#endif

#if (!SmallDec_DecimalStateMode_1)
        /// <summary>
        /// 0 = Positive;1=Negative;Other states at higher then 1;254 = Positive Infinity;255 = Negative Infinity
        /// </summary>
        public byte DecBoolStatus;
#endif

        /// <summary>
        /// Stores decimal section info (4 Decimal places stored)
        /// </summary>
        private ushort decimalStatus;

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
        /// <param name="invariantCulture"></param>
        /// <returns></returns>
        public static SmallDec Parse(string value, CultureInfo invariantCulture)
        {
            SmallDec NewValue = SmallDec.Initialize(value);
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
            //Use to to detect different assembly versions of SmallDec class
            Type ValueType = (Value as object).GetType();
            string ValueTypeName = ValueType.FullName;
            //((System.Runtime.Remoting.ObjectHandle)Value).Unwrap().GetType().ToString();
            if (ValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec")
            {
                this.DecBoolStatus = Value.DecBoolStatus;
                this.intValue = Value.IntValue;
                this.decimalStatus = Value.DecimalStatus;
            }
#if (!BlazesGlobalCode_Disable128BitFeatures)
            else if (Value is MediumSuperDec)
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
            else if (Value == null)
            {
                this = SmallDec.Zero;
            }
            else if (ValueType.IsValueType)
            {
                dynamic ConvertedValue = Activator.CreateInstance(ValueType);
                ConvertedValue = System.Convert.ChangeType(Value, ValueType, CultureInfo.CurrentCulture);
                this = ConvertedValue;
            }
            else
            {
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
            }
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
                if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec")//SmallDec to SmallDec Comparison
                {
                    if (value.GetType() != typeof(SmallDec))//Alternative assembly version of SmallDec Detected
                    {
                        dynamic ConvertedValue = Activator.CreateInstance(value.GetType());
                        ConvertedValue = this;
                        return this==(SmallDec)ConvertedValue;
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
                    else if(FullValueTypeName=="MS.Internal.NamedObject")
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
            if (DecBoolStatus == 1)
            {
                return ((int)intValue + (int)DecimalStatus) * -1;
            }
            else
            {
                return (int)intValue + (int)DecimalStatus;
            }
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
#if (SmallDec_DecimalStateMode_1 || SmallDec_DecimalStateMode_2)
            if(decimalStatus==–32768)//Negative WholeNumber
            {
                decimalStatus = 0;
            }
            else if(decimalStatus==0)//Positive WholeNumber
            {
                decimalStatus = –32768
            }
            else//Non-WholeNumber
            {
                decimalStatus *= -1;
            }
#else
            return DecBoolStatus == 1;
#endif
        }

        /// <summary>
        /// Switch from positive to negative and back
        /// </summary>
        public void SwapNegativeStatus()
        {
#if (SmallDec_DecimalStateMode_1)
            if(decimalStatus==–32768)//Negative WholeNumber
            {
                decimalStatus = 0;
            }
            else if(decimalStatus==0)//Positive WholeNumber
            {
                decimalStatus = –32768
            }
            else//Non-WholeNumber
            {
                decimalStatus *= -1;
            }
//#if (BlazesGlobalCode_SmallDec_EnableSpecialDecStates||SmallDec_DecimalStateMode_3)
//            if (DecBoolStatus % 2 == 0) { DecBoolStatus += 1; }
//            else { DecBoolStatus -= 1; }
#else
            if (DecBoolStatus == 0) { DecBoolStatus = 1; }
            else { DecBoolStatus = 0; }
#endif
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        /// <returns></returns>
        private static SmallDec MaximumValue()
        {
            return new SmallDec(65535, 9999);
        }

        /// <summary>
        /// Returns value of highest non-infinite/Special Decimal State Value that can store
        /// </summary>
        public static SmallDec Maximum = MaximumValue();

        //Returns value of lowest non-infinite/Special Decimal State Value that can store
        private static SmallDec MinimumValue()
        {
#if (SmallDec_DecimalStateMode_1)
            return new SmallDec(65535, -9999);
#else
            return new SmallDec(65535, 9999, 1);
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
            return DecBoolStatus == 255 || DecBoolStatus == 254;
        }

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

        ///// <summary>
        ///// 
        ///// </summary>
        ///// <returns></returns>
        //public dynamic DynamicConversion() => this;

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
            return DecBoolStatus == 202 ? true : false;
        }

        private static SmallDec ZeroValue()
        {
            return new SmallDec(0, 0);
        }

        /// <summary>
        /// Value at zero
        /// </summary>
        public static readonly SmallDec Zero = ZeroValue();

        private static SmallDec NaNValue()
        {
#if (BlazesGlobalCode_SmallDec_EnableSpecialDecStates)
            return new SmallDec(0, 202);
#else
            return new SmallDec(0, 0);
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
                    return this.decimalStatus==0?(this==SmallDec.Zero?0:1):-1;
                default:
                    {
                        if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec")//SmallDec comparisons
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
            this.DecBoolStatus = DecBoolStatus;
        }

        /// <summary>
        /// Copy Constructor for class
        /// </summary>
        /// <param name="value"></param>
        SmallDec(SmallDec value)
        {
            this.intValue = value.IntValue;
            this.decimalStatus = value.DecimalStatus;
            this.DecBoolStatus = value.DecBoolStatus;
        }

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
            else if(FullValueTypeName=="MS.Internal.NamedObject")
            {
                //if(value._name == "DependencyProperty.UnsetValue")//Initialyze at zero
                //{
                //	return SmallDec.Zero;
                //}
                //else
                //{
                //	return (SmallDec)value._name;
                //}
                return SmallDec.Zero;
            }
            else if (valueType == typeof(DependencyProperty))
            {
                DependencyProperty self = (DependencyProperty)value;
                return (SmallDec)self;
            }
            else if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.SmallDec")//SmallDec conversion
            {
                if (typeof(SmallDec) == value.GetType())
                {
                    return (SmallDec)value;
                }
                else
                {
                    SmallDec OtherValue = SmallDec.Zero;
                    dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
                    OtherValue.IntValue = changedObj.IntValue;
                    OtherValue.DecBoolStatus = changedObj.DecBoolStatus;
                    OtherValue.DecimalStatus = changedObj.DecimalStatus;
                    return OtherValue;
                }
            }
            else
            {
                dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
                return (SmallDec)changedObj;
            }
        }
#if (BlazesGlobalCode_SmallDec_AsClass)
        SmallDec()
        {
            this.intValue = 0;
            this.decimalStatus = 0;
            this.DecBoolStatus = 0;
        }
#endif
    }
#pragma warning restore CC0001 // You should use 'var' whenever possible.
#pragma warning restore CC0105 // You should use 'var' whenever possible.
#pragma warning restore CS3001 // Argument type is not CLS-compliant
#pragma warning restore CS3002 // Return type is not CLS-compliant
#pragma warning restore CS3003 // Type is not CLS-compliant
}