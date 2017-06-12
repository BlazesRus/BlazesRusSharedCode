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
                //else if (conversionType == typeof(DependencyProperty))
                //{
                //    return (SmallDec)(DependencyProperty)this;
                //}
                else
                {
                    string FullValueTypeName = conversionType.FullName;
                    if (FullValueTypeName == this.GetType().FullName)//Conversion from SmallDec to SmallDec
                    {
                        if (conversionType.AssemblyQualifiedName==this.GetType().AssemblyQualifiedName)//Conversion from same assembly SmallDec to same assembly SmallDec
                        {
                            return this;
                        }
                        else
                        {
                            Console.WriteLine("Conversion to other assembly version of SmallDec detected.");
                            dynamic ConvertedValue = Activator.CreateInstance(conversionType);
                            ConvertedValue = this;
                            return ConvertedValue;
                        }
                    }
                    //Dependency Property with unset value?
                    else if (FullValueTypeName == "MS.Internal.NamedObject")
                    {
                        return DependencyProperty.UnsetValue;
                        //return SmallDec.Zero;
                    }
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
                            Console.WriteLine("Exception of \n" + ex.ToString() + "\n occurred on attempting conversion of SmallDec to \n" + ConversionTypeString);
                            throw new InvalidCastException("Conversion to "+conversionType.Name+" is not supported.");
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
                Console.WriteLine("occurred when failing to convert from SmallDec to " + conversionType.ToString());
                throw;
            }

        }
    }
}
