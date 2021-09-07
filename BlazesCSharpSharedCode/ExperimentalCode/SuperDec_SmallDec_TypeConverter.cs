using System;
using System.ComponentModel;
using System.Globalization;
using System.Drawing;
using System.Linq;
using System.Windows.Data;

namespace CSharpSharedCode.ExperimentalCode
{
    using System.ComponentModel.Design.Serialization;
#pragma warning disable CC0001 // You should use 'var' whenever possible.
#pragma warning disable CC0105 // You should use 'var' whenever possible.
#pragma warning disable CS3001 // Argument type is not CLS-compliant
#pragma warning disable CS3002 // Return type is not CLS-compliant
#pragma warning disable CS3003 // Type is not CLS-compliant
#pragma warning disable CC0003 // Your catch should include an Exception
#pragma warning disable CS0436 // Type conflicts with imported type
    using System.IO;
    using System.Reflection;    
    //from https://ihadthisideaonce.com/2011/07/18/implementing-a-typeconverter/
    namespace ImplementingTypeConverter
    {
        /// <summary>
        /// Provides a unified way to convert <see cref="StreamWrapper"/> instances to <see cref="Stream"/>
        /// instances as well as <see cref="Stream"/> instances to <see cref="StreamWrapper"/> instances.
        /// </summary>
        public class StreamWrapperConverter : TypeConverter
        {
            /// <summary>
            /// Returns a value indicating whether this converter can convert from <paramref name="sourceType"/> to <see cref="StreamWrapper"/>,
            /// using the specified context.
            /// </summary>
            /// <param name="context">An <see cref="ITypeDescriptorContext"/> that provides a format context.</param>
            /// <param name="sourceType">A <see cref="Type"/> that represents the type you want to convert from.</param>
            /// <returns>true if this converter can perform the conversion; otherwise false.</returns>
            public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
            {
                return sourceType == typeof(global::System.IO.Stream) ||
                    base.CanConvertFrom(context, sourceType);
            }

            /// <summary>
            /// Converts <paramref name="value"/> to a <see cref="Stream"/>, using the specified context and culture information.
            /// </summary>
            /// <param name="context">An <see cref="ITypeDescriptorContext"/> that provides a format context.</param>
            /// <param name="culture">The <see cref="CultureInfo"/> to use as the current culture.</param>
            /// <param name="value">The <see cref="Object"/> to convert.</param>
            /// <returns>An <see cref="Object"/> that represents the converted value.</returns>
            public override object ConvertFrom(
                ITypeDescriptorContext context,
                CultureInfo culture,
                object value)
            {
                var o = value as global::System.IO.Stream;
                if (o != null)
                {
                    return StreamWrapper.FromStream(o);
                }

                return base.ConvertFrom(context, culture, value);
            }

            /// <summary>
            /// Returns a value indicating whether this converter can convert to <paramref name="destinationType"/> from <see cref="StreamWrapper"/>,
            /// using the specified context.
            /// </summary>
            /// <param name="context">An <see cref="ITypeDescriptorContext"/> that provides a format context.</param>
            /// <param name="destinationType">A <see cref="Type"/> that represents the type you want to convert to.</param>
            /// <returns>true if this converter can perform the conversion; otherwise, false.</returns>
            public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType)
            {
                return destinationType == typeof(global::System.IO.Stream) || base.CanConvertTo(context, destinationType);
            }

            /// <summary>
            /// Converts <paramref name="value"/> to <paramref name="destinationType"/>, using the specified context and culture information.
            /// </summary>
            /// <param name="context">An <see cref="ITypeDescriptorContext"/> that provides a format context.</param>
            /// <param name="culture">A <see cref="CultureInfo"/>.  If null is passed, the current culture is assumed.</param>
            /// <param name="value">The <see cref="Object"/> to convert.</param>
            /// <param name="destinationType">The <see cref="Type"/> to convert the value parameter to.</param>
            /// <returns>An <see cref="Object"/> that represents the converted value.</returns>
            public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type destinationType)
            {
                var proxy = value as ImplementingTypeConverter.StreamWrapper;
                if (destinationType == typeof(global::System.IO.Stream) &&
                    proxy != null)
                {
                    return StreamWrapper.ToStream(proxy);
                }

                return base.ConvertTo(context, culture, value, destinationType);
            }
        }

        /// <summary>
        /// 
        /// </summary>
        public interface IStreamWrapper
        {
            /// <summary>
            /// Closes this instance.
            /// </summary>
            void Close();

            // Other methods omitted...
        }

        /// <summary>
        /// The StreamWrapper class provides an implementation of <see cref="IStreamWrapper"/> that wraps <see cref="Stream"/>.
        /// </summary>
        [TypeConverter(typeof(StreamWrapperConverter))]
        public class StreamWrapper : IStreamWrapper
        {
            /// <summary>
            /// The <see cref="Stream"/> wrapped by this object.
            /// </summary>
            private readonly Stream Stream;

            /// <summary>
            /// Initializes a new instance of the <see cref="StreamWrapper"/> class.
            /// </summary>
            /// <param name="stream">The object to wrap.</param>
            public StreamWrapper(Stream stream)
            {
                if (stream == null)
                {
                    throw new ArgumentNullException("stream", "stream is null.");
                }

                this.Stream = stream;
            }

            /// <summary>
            /// Converts <paramref name="source"/> to a <see cref="Stream"/>
            /// </summary>
            /// <param name="source">The object to convert.</param>
            /// <returns>A <see cref="Stream"/> that represents the same data as <paramref name="source"/>.</returns>
            public static implicit operator Stream(StreamWrapper source)
            {
                return StreamWrapper.ToStream(source: source);
            }

            /// <summary>
            /// Converts <paramref name="source"/> to a <see cref="StreamWrapper"/>
            /// </summary>
            /// <param name="source">The object to convert.</param>
            /// <returns>A <see cref="StreamWrapper"/> that represents the same data as <paramref name="source"/>.</returns>
            public static implicit operator StreamWrapper(Stream source)
            {
                return StreamWrapper.FromStream(source: source);
            }

            /// <summary>
            /// Converts <paramref name="source"/> to a <see cref="StreamWrapper"/>
            /// </summary>
            /// <param name="source">The object to convert.</param>
            /// <returns>A <see cref="StreamWrapper"/> that represents the same data as <paramref name="source"/>.</returns>
            public static StreamWrapper FromStream(Stream source)
            {
                return new StreamWrapper(stream: source);
            }

            /// <summary>
            /// Converts <paramref name="source"/> to a <see cref="Stream"/>
            /// </summary>
            /// <param name="source">The object to convert.</param>
            /// <returns>A <see cref="Stream"/> that represents the same data as <paramref name="source"/>.</returns>
            public static Stream ToStream(StreamWrapper source)
            {
                return source.Stream;
            }

            /// <summary>
            /// Closes this instance.
            /// </summary>
            public void Close()
            {
                this.Stream.Close();
            }
        }
    }

    /// <summary>
    /// SmallDec ValueConversion class
    /// Based on https://msdn.microsoft.com/en-us/library/ayybcxe5.aspx
    /// Stream conversions heavily based on code from https://ihadthisideaonce.com/2011/07/18/implementing-a-typeconverter/
    /// </summary>
    //[ValueConversion(typeof(string), typeof(SmallDec))]
    public class SmallDec_TypeConverter : System.ComponentModel.TypeConverter, IMultiValueConverter, IValueConverter
    {
        /// <summary>
        /// Convert from other type to SmallDec
        /// </summary>
        /// <param name="value"></param>
        /// <param name="culture"></param>
        /// <param name="context"></param>
        /// <returns></returns>
        public object ConvertToSmallDec(object value, CultureInfo culture, ITypeDescriptorContext context=null)
        {
            string ValueTypeString = value.GetType().ToString();
            try
            {
                if (value.GetType().FullName == typeof(SmallDec).FullName)//SmallDec to SmallDec Conversion
                {
                    if (value.GetType() != typeof(SmallDec))//Alternative assembly version of SmallDec Detected
                    {
                        dynamic ConvertedValue = Activator.CreateInstance(value.GetType());
                        ConvertedValue = this;
                        return (SmallDec)ConvertedValue;
                    }
                    else
                    {
                        return (SmallDec)value;
                    }
                }
                else if (ValueTypeString == "JValue")//Support for type-converting from JSON based class without referencing
                {
                    dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), culture);
                    return (SmallDec)changedObj.ToString();
                }
                else if (value.GetType() == typeof(global::System.IO.Stream))
                {
                    var o = value as global::System.IO.Stream;
                    if (o != null)
                    {
                        var TempStream = ImplementingTypeConverter.StreamWrapper.FromStream(o);
                        return (SmallDec)TempStream.ToString();
                    }
                }
                else if (value is string)
                {
                    return (SmallDec)(string)value;
                }
                else
                {
                    //Convert to underlying object first before explicitly converting to SmallDec
                    dynamic changedObj = changedObj = System.Convert.ChangeType(value, value.GetType(), culture);
                    if (changedObj == null)
                    {
                        System.Console.WriteLine("Converting from null to SmallDec");
                        if (changedObj.GetType() == typeof(float) || changedObj.GetType() == typeof(double) || changedObj.GetType() == typeof(decimal) || changedObj.GetType() == typeof(string))
                        {
                            return SmallDec.Zero;
                        }
                        else
                        {
                            return SmallDec.NaN;
                        }
                    }
                    else
                    {
                        try//Attempt Explicit conversion from type to SmallDec first
                        {
                            return (SmallDec)changedObj;
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine("Explicit conversion from " + ValueTypeString + "to SmallDec failed with exception ");
                            Console.WriteLine(ex.ToString());
                        }
                        try//Attempt Explicit conversion from value.ToString to SmallDec first
                        {
                            return (SmallDec)changedObj.ToString(CultureInfo.InvariantCulture);
                        }
                        catch (Exception ex)
                        {
                            Console.WriteLine("Value.ToString conversion from " + ValueTypeString + "to SmallDec failed with exception ");
                            Console.WriteLine(ex.ToString());
                        }
                    }
                }
            }
            catch (System.Exception ex)
            {
                System.Console.WriteLine("SmallDec_TypeConverter ConvertFrom Exception of");
                System.Console.WriteLine(ex.ToString());
                System.Console.WriteLine("after attempting to convert from object value of type");
                System.Console.WriteLine(ValueTypeString);
            }
            return base.ConvertFrom(context, culture, value);
        }

        /// <summary>
        /// Convert from SmallDec to other value types
        /// </summary>
        /// <param name="value"></param>
        /// <param name="culture"></param>
        /// <param name="destinationType"></param>
        /// <param name="context"></param>
        /// <returns></returns>
        public object ConvertFromSmallDec(object value, Type destinationType, System.Globalization.CultureInfo culture, ITypeDescriptorContext context =null)
        {
            //string ValueTypeString = value.GetType().ToString();//Only check for conversions from SmallDec to other types
            //string ConversionType = destinationType.ToString();
            try
            {
                if (typeof(SmallDec).FullName == destinationType.FullName)//SmallDec to SmallDec conversion detected
                {
                    if (destinationType != typeof(SmallDec))//Alternative assembly version of SmallDec Detected
                    {
                        Console.WriteLine("Other assembly conversion from SmallDec to SmallDec detected");
                        dynamic ConvertedValue = Activator.CreateInstance(destinationType);
                        ConvertedValue = this;
                        return ConvertedValue;
                    }
                    else
                    {
                        return (SmallDec)value;
                    }
                }
                else if (destinationType == typeof(InstanceDescriptor))
                {
                    //Based on https://www.cyotek.com/blog/creating-a-custom-typeconverter-part-2
                    //dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), culture);
                    SmallDec changedObj = (SmallDec)value;
                    ConstructorInfo constructorInfo;
                    //if (ValueTypeString == "SmallDec")
                    //{
                        constructorInfo = typeof(SmallDec).GetConstructor(new[] { typeof(SmallDec)});
                        return new InstanceDescriptor(constructorInfo, new object[] { (SmallDec)changedObj });
                    //}
                    //else
                    //{
                    //    constructorInfo = value.GetType().GetConstructor(new[] { value.GetType()});
                    //    return new InstanceDescriptor(constructorInfo, new object[] { changedObj });
                    //}
                    //constructorInfo = typeof(Length).GetConstructor(new[] { typeof(float), typeof(Unit) });
                    //result = new InstanceDescriptor(constructorInfo, new object[] { length.Value, length.Unit });
                }
                else if (destinationType == typeof(global::System.IO.Stream))
                {
                    var proxy = value as ImplementingTypeConverter.StreamWrapper;
                    if (destinationType == typeof(global::System.IO.Stream) && proxy != null)
                    {
                        return (global::System.IO.Stream)proxy;
                    }
                }
                else if (destinationType == typeof(string))
                {
                    //dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), culture);
                    SmallDec changedObj = (SmallDec)value;
                    return changedObj.ToString(culture);
                }
                else if (destinationType == typeof(float))
                {
                    return (float)(SmallDec)value;
                }
                else if (destinationType == typeof(double))
                {
                    return (double)(SmallDec)value;
                }
                else if (destinationType == typeof(decimal))
                {
                    return (decimal)(SmallDec)value;
                }
                else if (destinationType == typeof(int))
                {
                    return (int)(SmallDec)value;
                }
                else if (destinationType == typeof(long))
                {
                    return (long)(SmallDec)value;
                }
                else if (destinationType == typeof(uint))
                {
                    return (uint)(SmallDec)value;
                }
                else if (destinationType == typeof(ulong))
                {
                    return (ulong)(SmallDec)value;
                }
                else if (destinationType == typeof(byte))
                {
                    return (byte)(SmallDec)value;
                }
                else if (destinationType == typeof(sbyte))
                {
                    return (sbyte)(SmallDec)value;
                }
                else if (destinationType == typeof(short))
                {
                    return (short)(SmallDec)value;
                }
                else if (destinationType == typeof(ushort))
                {
                    return (ushort)(SmallDec)value;
                }
                else if (destinationType == typeof(bool))
                {
                    return (bool)(SmallDec)value;
                }
                else if (destinationType == typeof(char))
                {
                    return (char)(short)(SmallDec)value;
                }
                else
                {
                    SmallDec self = (SmallDec)value;
                    dynamic changedObj = System.Convert.ChangeType(self, destinationType, culture);
                    return changedObj;
                }
            }
            catch (System.Exception ex)
            {
                System.Console.WriteLine("SmallDec_TypeConverter ConvertTo Exception of");
                System.Console.WriteLine(ex.ToString());
                System.Console.WriteLine("occurred when attempting to convert from SmallDec to " + destinationType.ToString());
            }
            return base.ConvertTo(context, culture, value, destinationType);
        }
        /// <summary>
        /// Convert from SmallDec to other value types
        /// </summary>
        /// <param name="context"></param>
        /// <param name="culture"></param>
        /// <param name="value"></param>
        /// <param name="destinationType"></param>
        /// <returns></returns>
        public override object ConvertTo(ITypeDescriptorContext context, System.Globalization.CultureInfo culture, object value, Type destinationType)
        {
            return ConvertFromSmallDec(value, destinationType, culture, context);
        }

        /// <summary>
        /// Convert from Other Types into SmallDec
        /// The ITypeDescriptorContext interface provides the context for the
        /// conversion. Typically, this interface is used at design time to 
        /// provide information about the design-time container.
        /// </summary>
        /// <param name="context"></param>
        /// <param name="culture"></param>
        /// <param name="value"></param>
        /// <returns></returns>
        public override object ConvertFrom(ITypeDescriptorContext context, System.Globalization.CultureInfo culture, object value)
        {
            return ConvertToSmallDec(value, culture, context);
        }

        /// <summary>
        /// Checks to determine if can convert to other types
        /// </summary>
        /// <param name="context"></param>
        /// <param name="destinationType"></param>
        /// <returns></returns>
        public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType)
        {
            if(destinationType == typeof(string) || destinationType == typeof(global::System.IO.Stream) || destinationType == typeof(System.ComponentModel.Design.Serialization.InstanceDescriptor)
            || base.CanConvertTo(context, destinationType)||
            destinationType == typeof(string) || destinationType == typeof(int) || destinationType == typeof(ulong) || destinationType == typeof(long) || destinationType == typeof(uint)
            || destinationType == typeof(double) || destinationType == typeof(float) || destinationType == typeof(decimal))
            {
                return true;
            }
            else
            {
#if (DEBUG)
                string ConversionType = destinationType.ToString();
                Console.WriteLine("Non-Detected conversion type found attempting to convert from SmallDec to type" + ConversionType + ".");
#endif
                //return CanC
                return false;
            }
            
        }
        /// <summary>
        ///  Checks to determine if can convert from other types
        /// </summary>
        /// <param name="context"></param>
        /// <param name="sourceType"></param>
        /// <returns></returns>
        public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
        {
            string ConversionType = sourceType.ToString();
            if(sourceType == typeof(global::System.IO.Stream) || sourceType == typeof(string) || ConversionType == "SmallDec"
            || base.CanConvertFrom(context, sourceType)
            || sourceType == typeof(System.ComponentModel.Design.Serialization.InstanceDescriptor) ||
            sourceType == typeof(string) || sourceType == typeof(int) || sourceType == typeof(ulong) || sourceType == typeof(long) || sourceType == typeof(uint)
            || sourceType == typeof(double) || sourceType == typeof(float) || sourceType == typeof(decimal))
            {
                return true;
            }
            else
            {
#if (DEBUG)
                Console.WriteLine("Non-Detected conversion type found attempting to convert to SmallDec from type" + ConversionType + ".");
#endif
                return false;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="value"></param>
        /// <param name="targetTypes"></param>
        /// <param name="parameter"></param>
        /// <param name="culture"></param>
        /// <returns></returns>
        public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
        {
#if (!SmallDecTypeConverter_StoreAsMultivalueList)
            throw new NotSupportedException();
#else
            throw new NotSupportedException();
            //var NewList = new System.Collections.Generic.List<typeof(targetTypes)>();
            //return NewList;
#endif
        }

        /// <summary>
        /// The data binding engine calls this method when it propagates a value from the binding source to the binding target. (Converts a value from one type to another.) <para />
        /// (IValueConverter.Convert Method) https://msdn.microsoft.com/en-us/library/system.windows.data.ivalueconverter.convert(v=vs.110).aspx
        /// </summary>
        /// <param name="value">The value produced by the binding source.</param>
        /// <param name="targetType">The value produced by the binding source.</param>
        /// <param name="parameter">The converter parameter to use.</param>
        /// <param name="culture">The converter parameter to use.</param>
        /// <returns></returns>
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            //if (targetType == typeof(SmallDec))
            //{
            //    return (SmallDec)value;
            //}
            //else
            //{
            //    return Convert(new[] { value }, targetType, parameter, culture);
            //}
            //#if (DEBUG)
            //            dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), culture);
            //            Console.WriteLine("Converting " + changedObj.GetType().ToString() + " into " + targetType.ToString());
            //#endif
            if (targetType == typeof(SmallDec))
            {
                return ConvertToSmallDec(value,culture);
            }
            else
            {
                return ConvertFromSmallDec(value, targetType, culture);
            }
        }

        /// <summary>
        /// Converts source values to a value for the binding target. The data binding engine calls this method when it propagates the values from source bindings to the binding target. (Convert from List of other type to List of SmallDec Type?) <para />
        /// (IMultiValueConverter.Convert Method) https://msdn.microsoft.com/en-us/library/system.windows.data.imultivalueconverter.convert(v=vs.110).aspx
        /// </summary>
        /// <param name="values">The array of values that the source bindings in the MultiBinding produces. The value UnsetValue indicates that the source binding has no value to provide for conversion.</param>
        /// <param name="targetType">The type of the binding target property.</param>
        /// <param name="parameter">The type of the binding target property.</param>
        /// <param name="culture">The culture to use in the converter.</param>
        /// <returns></returns>
        public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
        {
#if (DEBUG)
            Console.WriteLine("");
            Console.Write("Value types detected in object list to convert are ");
            foreach (var val in values)
            {
                Console.Write(" " + val.GetType().ToString());
            }
            Console.Write(" with values .");
            foreach (var val in values)
            {
                Console.Write(" " + val.ToString());
            }
            Console.Write(".");
            Console.WriteLine("Target Type = " + targetType.ToString());
#endif
#if (!SmallDecTypeConverter_StoreAsMultivalueList)
            if (targetType == typeof(SmallDec))
            {
                var sum = SmallDec.Zero;
                foreach (var value in values)
                {
                    sum += (SmallDec)value;
                }
                return sum;
            }
            else
            {
                dynamic sum = Activator.CreateInstance(targetType);
                foreach (var value in values)
                {
                    sum += System.Convert.ChangeType(value, value.GetType(), culture);
                }
                return sum;
            }
#else
            //Store converted list as SmallDec container
            System.Collections.Generic.List <SmallDec> ConvertedList = new System.Collections.Generic.List<SmallDec>();
            foreach (var value in values)
            {
                ConvertedList.Add((SmallDec)value);
            }
            return ConvertedList;
#endif
        }

        /// <summary>
        /// Convert from SmallDec back into targetType <para/>
        /// The data binding engine calls this method when it propagates a value from the binding target to the binding source.
        /// The implementation of this method must be the inverse of the Convert method.
        /// </summary>
        /// <param name="value">The value that is produced by the binding target.</param>
        /// <param name="targetType">The type to convert to.</param>
        /// <param name="parameter">The converter parameter to use.</param>
        /// <param name="culture">The culture to use in the converter.</param>
        /// <returns></returns>
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (targetType == typeof(SmallDec))
            {
                return ConvertToSmallDec(value, culture);
            }
            else
            {
                return ConvertFromSmallDec(value, targetType, culture);
            }
        }
    }
}