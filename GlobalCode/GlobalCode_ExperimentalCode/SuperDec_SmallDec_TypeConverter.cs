using System;
using System.ComponentModel;
using System.Globalization;
using System.Drawing;


namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
	//Based on https://msdn.microsoft.com/en-us/library/ayybcxe5.aspx
	class SuperDec_SmallDec_TypeConverter : System.ComponentModel.TypeConverter
	{
		// Overrides the CanConvertFrom method of TypeConverter.
		// The ITypeDescriptorContext interface provides the context for the
		// conversion. Typically, this interface is used at design time to 
		// provide information about the design-time container.
		public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
		{
			if (sourceType == typeof(string) || sourceType == typeof(int) || sourceType == typeof(ulong) || sourceType == typeof(long) || sourceType == typeof(uint)
			|| sourceType == typeof(double) || sourceType == typeof(float) || sourceType == typeof(decimal))
			{
				return true;
			}
			return base.CanConvertFrom(context, sourceType);
		}

		public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType)
		{
			if (destinationType == typeof(string) || destinationType == typeof(int) || destinationType == typeof(ulong) || destinationType == typeof(long) || destinationType == typeof(uint)
			|| destinationType == typeof(double) || destinationType == typeof(float) || destinationType == typeof(decimal))
			{
				return true;
			}
			if (destinationType == typeof(System.ComponentModel.Design.Serialization.InstanceDescriptor))
				return true;
			return base.CanConvertTo(context, destinationType);
		}

		// Overrides the ConvertFrom method of TypeConverter.
		public override object ConvertFrom(ITypeDescriptorContext context, CultureInfo culture, object value)
		{
			//Console.WriteLine("Attempting convert from with context " + context.GetType().ToString() + " from type " + value.GetType().ToString());
			return SmallDec.DynamicConversionFrom(value);
			//if (value is string)
			//{
			//	return (SmallDec)value;
			//}
			//else if (value is double || value is float || value is decimal)
			//{
			//	return (SmallDec)value;
			//}
			//else if (value is SmallDec)
			//{
			//	return (SmallDec)value;
			//}
			//else if (value is int || value is uint || value is long || value is ulong || value is short || value is ushort)
			//{
			//	return (SmallDec)value;
			//}
			//else if (value is byte || value is sbyte)
			//{
			//	return (SmallDec)value;
			//}
			//else
			//{
			//	return base.ConvertFrom(context, culture, value);
			//}
		}

		// Overrides the ConvertTo method of TypeConverter.
		public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type destinationType)
		{
			//Console.WriteLine("Attempting to convert with context " + context.GetType().ToString() + " to type " + destinationType.ToString());
			if (destinationType == typeof(string))
			{
				return (string)value;
			}
			if (destinationType == typeof(double))
			{
				return (double)value;
			}
			if (destinationType == typeof(SmallDec))
			{
				return (SmallDec)value;
			}
			if (destinationType == typeof(float))
			{
				return (float)value;
			}
			if (destinationType == typeof(decimal))
			{
				return (decimal)value;
			}
			if (destinationType == typeof(int))
			{
				return (int)value;
			}
			return base.ConvertTo(context, culture, value, destinationType);
		}
	}
}
