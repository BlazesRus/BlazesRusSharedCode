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
    using System.Globalization;
    using System.Windows;
    using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 4294967295.999999999 with 100% consistency of accuracy
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
        /// <summary>
        ///  Returns the TypeCode for this instance.
        /// </summary>
        /// <returns></returns>
        public TypeCode GetTypeCode()
        {
            return TypeCode.Object;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public bool ToBoolean(IFormatProvider provider)
        {
            return (bool)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public char ToChar(IFormatProvider provider)
        {
            return (char)(short)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public sbyte ToSByte(IFormatProvider provider)
        {
            return (sbyte)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public byte ToByte(IFormatProvider provider)
        {
            return (byte)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public short ToInt16(IFormatProvider provider)
        {
            return (short)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public ushort ToUInt16(IFormatProvider provider)
        {
            return (ushort)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public int ToInt32(IFormatProvider provider)
        {
            return (int)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public uint ToUInt32(IFormatProvider provider)
        {
            return (uint)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public long ToInt64(IFormatProvider provider)
        {
            return (long)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public ulong ToUInt64(IFormatProvider provider)
        {
            return (ulong)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public float ToSingle(IFormatProvider provider)
        {
            return (float)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public double ToDouble(IFormatProvider provider)
        {
            return (double)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public decimal ToDecimal(IFormatProvider provider)
        {
            return (decimal)this;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="provider"></param>
        /// <returns></returns>
        public DateTime ToDateTime(IFormatProvider provider)
        {
            return DateTime.Now;
        }

        /// <summary>
        /// Effectively replaces use of calls to System.Convert.ChangeType(this, conversionType, provider);
        /// </summary>
        /// <param name="conversionType"></param>
        /// <param name="provider"></param>
        /// <returns></returns>
        public object ToType(Type conversionType, IFormatProvider provider)
        {
            try
            {
                if (conversionType == typeof(string))
                {
                    return (string)this;
                }
                else if (conversionType == typeof(float))
                {
                    return (float)this;
                }
                else if (conversionType == typeof(double))
                {
                    return (double)this;
                }
                else if (conversionType == typeof(decimal))
                {
                    return (decimal)this;
                }
                else if (conversionType == typeof(int))
                {
                    return (int)this;
                }
                else if (conversionType == typeof(long))
                {
                    return (long)this;
                }
                else if (conversionType == typeof(uint))
                {
                    return (uint)this;
                }
                else if (conversionType == typeof(ulong))
                {
                    return (ulong)this;
                }
                else if (conversionType == typeof(byte))
                {
                    return (byte)this;
                }
                else if (conversionType == typeof(sbyte))
                {
                    return (sbyte)this;
                }
                else if (conversionType == typeof(short))
                {
                    return (short)this;
                }
                else if (conversionType == typeof(ushort))
                {
                    return (ushort)this;
                }
                else if (conversionType == typeof(bool))
                {
                    return (bool)this;
                }
                else if (conversionType == typeof(char))
                {
                    return (char)(short)this;
                }
#if (GlobalCode_EnableDependencyPropStuff)
                else if (conversionType == typeof(DependencyProperty))
                {
                    return (MediumDec)(DependencyProperty)this;
                }
#endif
                else
                {
                    string FullValueTypeName = conversionType.FullName;
                    if (FullValueTypeName == this.GetType().FullName)//Conversion from MediumDec to MediumDec
                    {
                        if (conversionType.AssemblyQualifiedName==this.GetType().AssemblyQualifiedName)//Conversion from same assembly MediumDec to same assembly MediumDec
                        {
                            return this;
                        }
                        else
                        {
                            Console.WriteLine("Conversion to other assembly version of MediumDec detected.");
                            dynamic ConvertedValue = Activator.CreateInstance(conversionType);
                            ConvertedValue = this;
                            return ConvertedValue;
                        }
                    }
                    ////Dependency Property with unset value?
                    //else if (FullValueTypeName == "MS.Internal.NamedObject")
                    //{
                    //    return DependencyProperty.UnsetValue;
                    //    //return MediumDec.Zero;
                    //}
                    else
                    {
                        string ConversionTypeString = conversionType.ToString();
                        try
                        {
                            //bool IsValueType = conversionType.IsValueType;
                            if (conversionType.IsValueType)
                            {
                                dynamic ConvertedValue = Activator.CreateInstance(conversionType);
                                ConvertedValue = System.Convert.ChangeType(this, conversionType, provider);
                                return ConvertedValue;
                            }
                            else
                            {
                                dynamic changedObj = System.Convert.ChangeType(this.ToOptimalString(), conversionType, provider);
                                return changedObj;
                            }
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine("Exception of \n" + ex.ToString() + "\n occurred on attempting conversion of MediumDec to \n" + ConversionTypeString);
                            throw new InvalidCastException("Conversion to "+conversionType.Name+" is not supported.",ex);
                        }
                    }
                    //StackOverflow exception occurs if attempt following code here
                    //dynamic changedObj = System.Convert.ChangeType(this, conversionType, provider);
                    //return changedObj;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception of");
                Console.WriteLine(ex.ToString());
                Console.WriteLine("occurred when failing to convert from MediumDec to " + conversionType.ToString());
                throw;
            }

        }

        class ConversionStatusValue
        {
            [Flags]
            public enum ConversionStatusEnum
            {
                InitialTypeIsArray = 1,
                TargetTypeIsArray = 1 << 1,
            }
            public ConversionStatusEnum ConversionStats;
            public ConversionStatusValue(Type InitialType, Type TargetType)
            {
                if (InitialType.IsArray) { ConversionStats |= ConversionStatusEnum.InitialTypeIsArray; }
                if (TargetType.IsArray) { ConversionStats |= ConversionStatusEnum.TargetTypeIsArray; }
            }
        }

        /// <summary>
        /// Convert from one Type to another
        /// </summary>
        /// <param name="InitialValue"></param>
        /// <param name="TargetType"></param>
        /// <returns></returns>
        public static dynamic Convert(dynamic InitialValue, Type TargetType)
        {
            object value = InitialValue as object;
            Type InitialType = value.GetType();
            if (InitialType == TargetType)
            {
                return InitialValue;
            }
            else if (value is MediumDec)
            {
                return InitialValue.ToType(TargetType);
            }
            else if(TargetType==typeof(MediumDec))
            {
                return MediumDec.Initialize(InitialValue);
            }
            else
            {
                string InitialTypeName = InitialType.FullName;
                string TargetTypeName = TargetType.FullName;
                ConversionStatusValue ConversionStatus = new ConversionStatusValue(InitialType, TargetType);
                return InitialValue.ToType(TargetType);
            }
        }
    }
}
