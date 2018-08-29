/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#ifndef MediumDec_IncludeGuard
#define MediumDec_IncludeGuard

#ifndef BlazesGlobalCode_FileStructureVersion
#	define BlazesGlobalCode_FileStructureVersion 0
//FileStructureVersion 0 = Refers to required files set up similar/same as Library Versions of files
//FileStructureVersion 1 = All required files from GlobalCode within same folder locally
#endif

#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#	ifndef DLL_API
#		define DLL_API
#	endif
#endif

#include <io.h>
#include <math.h>
#include <iostream>
#include <string>

//#include "SuperDecHex.h"
#include "CustomDec.h"

namespace CPlusGlobalCode_ExperimentalCode
{
    /// <summary>
    /// Represent +- 4294967295.999999999 with 100% consistency of accuracy
    /// </summary>
	class DLL_API MediumDec : CustomDec<MediumDec, unsigned int, signed int, long, -1000000000, 1000000000>
    {
public:
//		/// <summary>
//		/// Finds sum of Value Container
//		/// </summary>
//		/// <param name="Value"></param>
//		/// <returns></returns>
//		static MediumDec Sum(IEnumerable<MediumDec> Value)
//		{
//			var TotalSum = MediumDec.Zero;
//			foreach(var Element in Value)
//			{
//				TotalSum += Element;
//			}
//			return TotalSum;
//		}
//
//		/// <summary>
//		/// Parses string value into MediumDec
//		/// </summary>
//		/// <param name="value"></param>
//		/// <param name="TargetCulture"></param>
//		/// <returns></returns>
//		static MediumDec Parse(string value, CultureInfo TargetCulture = null)
//		{
//			//if(TargetCulture==null)
//			//{
//			//    TargetCulture = CultureInfo.CurrentUICulture;
//			//}
//			MediumDec NewValue = MediumDec.GetValueFromString(value);
//			return NewValue;
//		}
//
//		/// <summary>
//		/// Parses string value into MediumDec
//		/// </summary>
//		/// <param name="value"></param>
//		/// <param name="MediumDec"></param>
//		/// <param name="culture"></param>
//		/// <param name="OutputValue"></param>
//		/// <returns></returns>
//		static bool TryParse(string value, object MediumDec, CultureInfo culture, out MediumDec OutputValue)
//		{
//			OutputValue = Parse(value, culture);
//			return true;
//		}
//
//		/// <summary>
//		/// Return largest of parameters
//		/// </summary>
//		/// <param name="LeftSide"></param>
//		/// <param name="RightSide"></param>
//		/// <returns></returns>
//		static MediumDec Max(dynamic LeftSide, dynamic RightSide)
//		{
//			var LeftSideAsType = (MediumDec)LeftSide;
//			var RightSideAsType = (MediumDec)RightSide;
//			return LeftSideAsType > RightSide ? LeftSideAsType : RightSideAsType;
//		}
//
//		/// <summary>
//		/// Return the smallest of parameters
//		/// </summary>
//		/// <param name="LeftSide"></param>
//		/// <param name="RightSide"></param>
//		/// <returns></returns>
//		static MediumDec Min(dynamic LeftSide, dynamic RightSide)
//		{
//			var LeftSideAsType = (MediumDec)LeftSide;
//			var RightSideAsType = (MediumDec)RightSide;
//			return LeftSideAsType < RightSide ? LeftSideAsType : RightSideAsType;
//		}
//
//		/// <summary>
//		/// Method version to Initialize Type instead of with Explicit operators
//		/// </summary>
//		/// <param name="Value"></param>
//		/// <returns></returns>
//		static MediumDec Initialize(dynamic Value) = > new MediumDec(Value);
//
//		/// <summary>
//		/// Initialize constructor
//		/// </summary>
//		/// <param name="Value"></param>
//		MediumDec(dynamic Value)
//		{
//			TypeCode typeCode = Type.GetTypeCode(Value.GetType());
//			int typeCodeValue = (int)typeCode;
//#if (!BlazesGlobalCode_MediumDec_AsStruct)
//			if (typeCodeValue >= 3 && typeCodeValue <= 12)//Integer based Value types+Bool
//			{
//				if (Value < 0)
//				{
//					Value *= -1;
//					this.IntValue = Value;
//					this.DecimalStatus = NegativeWholeNumber;
//				}
//				else
//				{
//					this.IntValue = Value;
//					this.DecimalStatus = 0;
//				}
//			}
//			else if (typeCodeValue >= 13 && typeCodeValue <= 15)//Floating Point based Value types
//			{
//				MediumDec NewSelf = new MediumDec();
//				switch (typeCode)
//				{
//				case TypeCode.Single:
//					NewSelf = (MediumDec)(float)Value; break;
//				case TypeCode.Double:
//					NewSelf = (MediumDec)(double)Value; break;
//				case TypeCode.Decimal:
//					NewSelf = (MediumDec)(decimal)Value; break;
//				default:
//					NewSelf = (MediumDec)Value; break;
//				}
//			}
//			else if (typeCode == TypeCode.String)
//			{
//				MediumDec NewSelf = MediumDec.GetValueFromString(Value as string);
//				this.IntValue = NewSelf.IntValue;
//				this.DecimalStatus = NewSelf.DecimalStatus;
//			}
//			else
//#endif
//				if (Value == null)
//				{
//#if (BlazesGlobalCode_MediumDec_AsStruct)
//					this = MediumDec.Zero;
//#else
//					this.IntValue = 0;
//					this.DecimalStatus = 0;
//#endif
//				}
//				else
//				{
//					//Use to to detect different assembly versions of MediumDec class
//					Type ValueType = (Value as object).GetType();
//					string ValueTypeName = ValueType.FullName;
//					if (ValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec" || ValueType == typeof(MediumDec))
//					{
//						this.intValue = Value.IntValue;
//						this.decimalStatus = Value.DecimalStatus;
//					}
//#if (BlazesGlobalCode_MediumDec_AsStruct)
//					else if (ValueType == typeof(string))
//					{
//						this = (string)Value;
//					}
//					else if (ValueType == typeof(float))
//					{
//						this = (float)Value;
//					}
//					else if (ValueType == typeof(double))
//					{
//						this = (double)Value;
//					}
//					else if (ValueType == typeof(decimal))
//					{
//						this = (decimal)Value;
//					}
//					else if (ValueType == typeof(int))
//					{
//						this = (int)Value;
//					}
//					else if (ValueType == typeof(long))
//					{
//						this = (long)Value;
//					}
//					else if (ValueType == typeof(uint))
//					{
//						this = (uint)Value;
//					}
//					else if (ValueType == typeof(ulong))
//					{
//						this = (ulong)Value;
//					}
//					else if (ValueType == typeof(byte))
//					{
//						this = (byte)Value;
//					}
//					else if (ValueType == typeof(sbyte))
//					{
//						this = (sbyte)Value;
//					}
//					else if (ValueType == typeof(short))
//					{
//						this = (short)Value;
//					}
//					else if (ValueType == typeof(ushort))
//					{
//						this = (ushort)Value;
//					}
//					else if (ValueType == typeof(bool))
//					{
//						this = (MediumDec)(bool)Value;
//					}
//					else if (ValueType == typeof(char))
//					{
//						this = (char)(short)Value;
//					}
//#else
//					else if (ValueType == typeof(char))
//					{
//						MediumDec NewSelf = new MediumDec();
//						NewSelf = (MediumDec)(char)(short)Value;
//					}
//#endif
//					else if (ValueType.IsValueType)
//					{
//						dynamic ConvertedValue = Activator.CreateInstance(ValueType);
//						ConvertedValue = System.Convert.ChangeType(Value, ValueType, CultureInfo.CurrentCulture);
//#if (BlazesGlobalCode_MediumDec_AsStruct)
//						this = ConvertedValue;
//#else
//						this.IntValue = 0;
//						this.DecimalStatus = 0;
//#endif
//					}
//					else
//					{
//#if (BlazesGlobalCode_MediumDec_AsStruct)
//#pragma warning disable EA002 // Swallow exceptions considered harmful
//						try
//						{
//							//dynamic changedObj = System.Convert.ChangeType(this.ToOptimalString(), conversionType, provider);
//							//this = changedObj;
//							dynamic ConvertedValue = default(ValueType);
//							ConvertedValue = Value;
//							this = ConvertedValue;
//						}
//						catch
//						{
//							try
//							{
//								this = Value.ToString();
//							}
//							catch
//							{
//								this = MediumDec.Zero;
//							}
//						}
//#pragma warning restore EA002 // Swallow exceptions considered harmful
//#else
//						this.IntValue = 0;
//						this.DecimalStatus = 0;
//#endif
//					}
//				}
//			//((System.Runtime.Remoting.ObjectHandle)Value).Unwrap().GetType().ToString();
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="value"></param>
//		/// <returns></returns>
//		override bool Equals(object value)
//		{
//			//Enable comparisons against other object types
//			if (value == null) { return false; }
//			try
//			{
//				Type valueType = value.GetType();
//				string FullValueTypeName = valueType.FullName;
//				if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec")//MediumDec to MediumDec Comparison
//				{
//					if (value.GetType() != typeof(MediumDec))//Alternative assembly version of MediumDec Detected
//					{
//						dynamic ConvertedValue = Activator.CreateInstance(value.GetType());
//						ConvertedValue = this;
//						return this == (MediumDec)ConvertedValue;
//					}
//					else
//					{
//						return this == (MediumDec)value;
//					}
//				}
//				else
//				{
//					if (valueType == typeof(string))
//					{
//						return this == (string)value;
//					}
//					else if (valueType == typeof(float))
//					{
//						return this == (float)value;
//					}
//					else if (valueType == typeof(double))
//					{
//						return this == (double)value;
//					}
//					else if (valueType == typeof(decimal))
//					{
//						return this == (decimal)value;
//					}
//					else if (valueType == typeof(int))
//					{
//						return this == (int)value;
//					}
//					else if (valueType == typeof(long))
//					{
//						return this == (long)value;
//					}
//					else if (valueType == typeof(uint))
//					{
//						return this == (uint)value;
//					}
//					else if (valueType == typeof(ulong))
//					{
//						return this == (ulong)value;
//					}
//					else if (valueType == typeof(byte))
//					{
//						return this == (byte)value;
//					}
//					else if (valueType == typeof(sbyte))
//					{
//						return this == (sbyte)value;
//					}
//					else if (valueType == typeof(short))
//					{
//						return this == (short)value;
//					}
//					else if (valueType == typeof(ushort))
//					{
//						return this == (ushort)value;
//					}
//					else if (valueType == typeof(bool))
//					{
//						return this == (MediumDec)(bool)value;
//					}
//					else if (valueType == typeof(char))
//					{
//						return this == (char)(short)value;
//					}
//					//Dependency Property
//					else if (FullValueTypeName == "MS.Internal.NamedObject")
//					{
//						return this == MediumDec.Zero;
//					}
//					else
//					{
//						Console.WriteLine("Equals Comparison Test for " + valueType.ToString());
//						dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
//						return this == MediumDec.Initialize(changedObj);
//					}
//				}
//			}
//			catch
//#if (DEBUG)
//				(Exception ex)
//#endif
//			{
//#if (DEBUG)
//				Console.WriteLine("Exception named ");
//				Console.WriteLine(ex.ToString());
//				Console.WriteLine("caught in Equals Method.");
//#endif
//				return false;
//			}
//		}
//
//		/// <summary>
//		/// Override the Object.GetHashCode() method
//		/// </summary>
//		/// <returns></returns>
//		override int GetHashCode()
//		{
//			return DecimalStatus;
//		}
//
//		/// <summary>
//		/// Return value as signed int 32 value
//		/// </summary>
//		/// <returns></returns>
//		int GetIntValueAsInt32()
//		{
//			return (int)intValue;
//		}
//
//		/// <summary>
//		/// Method check that returns if represented number is negative
//		/// </summary>
//		/// <returns></returns>
//		bool IsNegative()
//		{
//			return DecimalStatus < 0;
//		}
//
//		/// <summary>
//		/// Switch from positive to negative and back
//		/// </summary>
//		void SwapNegativeStatus()
//		{
//			DecimalStatus *= -1;
//		}
//
//		/// <summary>
//		/// Returns value of highest non-infinite/Special Decimal State Value that can store
//		/// </summary>
//		/// <returns></returns>
//		private static MediumDec MaximumValue()
//		{
//			return new MediumDec(4294967295, 999999999);
//		}
//
//		/// <summary>
//		/// Returns value of highest non-infinite/Special Decimal State Value that can store
//		/// </summary>
//		static MediumDec Maximum = MaximumValue();
//
//		//Returns value of lowest non-infinite/Special Decimal State Value that can store
//		private static MediumDec MinimumValue()
//		{
//			return new MediumDec(4294967295, -999999999);
//		}
//
//		/// <summary>
//		/// Returns value of lowest non-infinite/Special Decimal State Value that can store
//		/// </summary>
//		static readonly MediumDec Minimum = MinimumValue();
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <returns></returns>
//		bool IsInfinity()
//		{
//			return false;
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="Condition"></param>
//		/// <param name="X"></param>
//		/// <param name="Y"></param>
//		/// <returns></returns>
//		static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
//		{
//			return Condition ? X : Y;
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="Value"></param>
//		/// <returns></returns>
//		static MediumDec DynamicConversionFrom(dynamic Value) = > (MediumDec)Value;
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="self"></param>
//		/// <returns></returns>
//		static MediumDec SumOfList(MediumDec[] self)
//		{
//			var Total = MediumDec.Zero;
//			foreach(MediumDec Element in self)
//			{
//				Total += Element;
//			}
//			return Total;
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="self"></param>
//		/// <returns></returns>
//		static MediumDec SumOfList(IEnumerable<MediumDec> self)
//		{
//			var Total = MediumDec.Zero;
//			foreach(MediumDec Element in self)
//			{
//				Total += Element;
//			}
//			return Total;
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <returns></returns>
//		bool IsNull()
//		{
//#if (BlazesGlobalCode_MediumDec_AsStruct)
//			return false;
//#else
//			return this == null;
//#endif
//		}
//
//		private static MediumDec ZeroValue()
//		{
//			return new MediumDec(0, 0);
//		}
//
//		/// <summary>
//		/// Value at zero
//		/// </summary>
//		static readonly MediumDec Zero = ZeroValue();
//
//		private static MediumDec NaNValue()
//		{
//#if !BlazesGlobalCode_SmallDec_AsStruct && !BlazesGlobalCode_ZeroAtNaN
//			return null;//NaN is Null unless preprocessor switch is set for BlazesGlobalCode_ZeroAtNaN when is class
//#else
//			return new MediumDec(0, 0);
//#endif
//		}
//
//		/// <summary>
//		/// Value at one
//		/// </summary>
//		static readonly MediumDec One = OneValue();
//
//		private static MediumDec OneValue() = > new MediumDec(1, 0);
//
//		/// <summary>
//		/// Value at either zero or NaN (depending on preprocessor settings)
//		/// </summary>
//		static readonly MediumDec NaN = NaNValue();
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="other"></param>
//		/// <returns></returns>
//		int IComparable<MediumDec>.CompareTo(MediumDec other)
//		{
//			if (other == this)
//			{
//				return 0;
//			}
//			else if (this < other)
//			{
//				return -1;
//			}
//			else
//			{
//				return 1;
//			}
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="CompareTarget"></param>
//		/// <param name="RangeWithin"></param>
//		/// <returns></returns>
//		bool AlmostEquals(dynamic CompareTarget, dynamic RangeWithin)
//		{
//			MediumDec ConvertedTarget = (MediumDec)CompareTarget;
//			if (ConvertedTarget == this) { return true; }
//			else
//			{
//				MediumDec LeftRange = ConvertedTarget - RangeWithin;
//				MediumDec RightRange = ConvertedTarget + RangeWithin;
//				return this == LeftRange || this == RightRange ? true : this > LeftRange && this < RightRange ? true : false;
//			}
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="value"></param>
//		/// <returns></returns>
//		int CompareTo(object value)
//		{
//			string FullValueTypeName = value.GetType().FullName;
//			MediumDec OtherAsSelfType = ObjectAsMediumDec(value);
//			switch (FullValueTypeName)
//			{
//			case "MS.Internal.NamedObject":
//				return this.decimalStatus == 0 ? (this == MediumDec.Zero ? 0 : 1) : -1;
//
//			default:
//			{
//				if (FullValueTypeName == "CPlusGlobalCode_ExperimentalCode.MediumDec")//MediumDec comparisons
//				{
//					if (value.GetType() != typeof(MediumDec))//Alternative assembly version of MediumDec
//					{
//						MediumDec ValueAsThisType = MediumDec.ObjectAsMediumDec(value);
//						return this.CompareTo(ValueAsThisType);
//					}
//					else
//					{
//						return this.CompareTo((MediumDec)value);
//					}
//				}
//				else
//				{
//					if (OtherAsSelfType == this)
//					{
//						return 0;
//					}
//					else if (this < OtherAsSelfType)
//					{
//						return -1;
//					}
//					else
//					{
//						return 1;
//					}
//				}
//			}
//			}
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="other"></param>
//		/// <returns></returns>
//		int CompareTo(MediumDec other)
//		{
//			if (other == this)
//			{
//				return 0;
//			}
//			else if (this < other)
//			{
//				return -1;
//			}
//			else
//			{
//				return 1;
//			}
//		}
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="IntValue"></param>
//		/// <param name="DecimalStatus"></param>
//		private MediumDec(uint IntValue, int DecimalStatus)
//		{
//			this.intValue = IntValue;
//			this.decimalStatus = DecimalStatus;
//		}
//
//#if (!BlazesGlobalCode_MediumDec_AsStruct)
//
//		/// <summary>
//		/// Copy Constructor for class
//		/// </summary>
//		/// <param name="value"></param>
//		private MediumDec(MediumDec value)
//		{
//			this.intValue = value.IntValue;
//			this.decimalStatus = value.DecimalStatus;
//		}
//
//		MediumDec()
//		{
//			this.intValue = 0;
//			this.decimalStatus = 0;
//		}
//
//#endif
//
//		/// <summary>
//		///
//		/// </summary>
//		/// <param name="other"></param>
//		/// <returns></returns>
//		bool Equals(MediumDec other)
//		{
//			return this == other;
//		}
//
//		/// <summary>
//		/// Change variable into string with certain formating style with culture info set
//		/// </summary>
//		/// <param name="format"></param>
//		/// <param name="formatProvider"></param>
//		/// <returns></returns>
//		string ToString(string format, IFormatProvider formatProvider)
//		{
//			return String.Format(formatProvider, this.ToOptimalString());
//		}
//
//		/// <summary>
//		/// Convert Object into MediumDec for comparison etc
//		/// </summary>
//		/// <param name="value"></param>
//		/// <returns></returns>
//		static MediumDec ObjectAsMediumDec(object value)
//		{
//			Type valueType = value.GetType();
//			string FullValueTypeName = valueType.FullName;
//			if (valueType == typeof(string))
//			{
//				return (MediumDec)(string)value;
//			}
//			else if (valueType == typeof(float))
//			{
//				return (MediumDec)(float)value;
//			}
//			else if (valueType == typeof(double))
//			{
//				return (MediumDec)(double)value;
//			}
//			else if (valueType == typeof(decimal))
//			{
//				return (MediumDec)(decimal)value;
//			}
//			else if (valueType == typeof(int))
//			{
//				return (MediumDec)(int)value;
//			}
//			else if (valueType == typeof(long))
//			{
//				return (MediumDec)(long)value;
//			}
//			else if (valueType == typeof(uint))
//			{
//				return (MediumDec)(uint)value;
//			}
//			else if (valueType == typeof(ulong))
//			{
//				return (MediumDec)(ulong)value;
//			}
//			else if (valueType == typeof(byte))
//			{
//				return (MediumDec)(byte)value;
//			}
//			else if (valueType == typeof(sbyte))
//			{
//				return (MediumDec)(sbyte)value;
//			}
//			else if (valueType == typeof(short))
//			{
//				return (MediumDec)(short)value;
//			}
//			else if (valueType == typeof(ushort))
//			{
//				return (MediumDec)(ushort)value;
//			}
//			else if (valueType == typeof(bool))
//			{
//				return (MediumDec)(bool)value;
//			}
//			else if (valueType == typeof(char))
//			{
//				return (MediumDec)(char)(short)value;
//			}
//			//Dependency Property with unset value?
//			else if (FullValueTypeName == "MS.Internal.NamedObject")
//			{
//				//if (value._name == "DependencyProperty.UnsetValue")//Initialize at zero
//				//{
//				//    return MediumDec.Zero;
//				//}
//				//else
//				//{
//				//    return (MediumDec)value._name;
//				//}
//				return MediumDec.Zero;
//			}
//#if (GlobalCode_EnableDependencyPropStuff)
//			else if (valueType == typeof(DependencyProperty))
//			{
//				DependencyProperty self = (DependencyProperty)value;
//				return (MediumDec)self;
//			}
//#endif
//			//else if (FullValueTypeName == "CSharpGlobalCode.GlobalCode_ExperimentalCode.MediumDec")//MediumDec conversion
//			//{
//			//    if (typeof(MediumDec) == value.GetType())
//			//    {
//			//        return (MediumDec)value;
//			//    }
//			//    else
//			//    {
//			//        MediumDec OtherValue = MediumDec.Zero;
//			//        dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
//			//        OtherValue.IntValue = changedObj.IntValue;
//			//        OtherValue.DecBoolStatus = changedObj.DecBoolStatus;
//			//        OtherValue.DecimalStatus = changedObj.DecimalStatus;
//			//        return OtherValue;
//			//    }
//			//}
//			else
//			{
//				dynamic changedObj = System.Convert.ChangeType(value, value.GetType(), CultureInfo.InvariantCulture);
//				return (MediumDec)changedObj;
//			}
//		}

        //#region INotifyPropertyChanged Members

        //	event PropertyChangedEventHandler PropertyChanged;

        ///// Need to implement this interface in order to get data binding
        ///// to work properly.
        //private void NotifyPropertyChanged(string propertyName)
        //{
        //	if (PropertyChanged != null)
        //	{
        //		PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
        //	}
        //}

        //#endregion INotifyPropertyChanged Members

        //template <typename ValueType>
        //void ApplyIntAddition(ValueType Value);
        //MediumDec operator+(unsigned int Value) { ApplyIntAddition(Value); };
        //MediumDec operator+(signed int Value) { ApplyIntAddition(Value); };
        //MediumDec operator+(unsigned __int64 Value) { ApplyIntAddition(Value); }
        //MediumDec operator+(signed __int64 Value) { ApplyIntAddition(Value); }
        //MediumDec operator+(unsigned __int16 Value) { ApplyIntAddition(Value); }
        //MediumDec operator+(signed __int16 Value) { ApplyIntAddition(Value); }
        //MediumDec operator+(unsigned __int8 Value) { ApplyIntAddition(Value); }
        //MediumDec operator+(signed __int8 Value) { ApplyIntAddition(Value); }
        ////************************************
        //// Method:    operator+
        //// FullName:  MediumDec::operator+
        //// Access:    private
        //// Returns:   MediumDec
        //// Qualifier:
        //// Parameter: double Value
        ////************************************
        //MediumDec operator+(double Value);
        ////************************************
        //// Method:    operator+
        //// FullName:  MediumDec::operator+
        //// Access:    private
        //// Returns:   MediumDec
        //// Qualifier:
        //// Parameter: std::string Value
        ////************************************
        //MediumDec operator+(std::string Value);
        ////************************************
        //// Method:    ApplySubtraction
        //// FullName:  MediumDec::ApplySubtraction
        //// Access:    private
        //// Returns:   void
        //// Qualifier:
        //// Parameter: ValueType Value
        ////************************************
        //template <typename ValueType>
        //void ApplyIntSubtraction(ValueType Value);
        //MediumDec operator-(unsigned int Value) { ApplyIntSubtraction(Value); };
        //MediumDec operator-(signed int Value) { ApplyIntSubtraction(Value); };
        //MediumDec operator-(unsigned __int64 Value) { ApplyIntSubtraction(Value); }
        //MediumDec operator-(signed __int64 Value) { ApplyIntSubtraction(Value); }
        //MediumDec operator-(unsigned __int16 Value) { ApplyIntSubtraction(Value); }
        //MediumDec operator-(signed __int16 Value) { ApplyIntSubtraction(Value); }
        //MediumDec operator-(unsigned __int8 Value) { ApplyIntSubtraction(Value); }
        //MediumDec operator-(signed __int8 Value) { ApplyIntSubtraction(Value); }
        ////************************************
        //// Method:    ApplyEqual
        //// FullName:  MediumDec::ApplyEqual
        //// Access:    private
        //// Returns:   void
        //// Qualifier:
        //// Parameter: ValueType Value
        ////************************************
        //template <typename ValueType>
        //void ApplyIntEqual(ValueType Value);
        //MediumDec operator=(std::string Value);
        //MediumDec operator=(unsigned int Value) { ApplyIntEqual(Value); };
        //MediumDec operator=(signed int Value) { ApplyIntEqual(Value); };
        //MediumDec operator=(unsigned __int64 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(signed __int64 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(unsigned __int16 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(signed __int16 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(unsigned __int8 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(signed __int8 Value) { ApplyIntEqual(Value); }
        //MediumDec operator=(double Value);
        ////************************************
        //// Method:    ApplyModulus
        //// FullName:  MediumDec::ApplyModulus
        //// Access:    private
        //// Returns:   void
        //// Qualifier:
        //// Parameter: ValueType Value
        ////************************************
        //template <typename ValueType>
        //void ApplyModulus(ValueType Value);
        //MediumDec operator%(unsigned int Value) { ApplyModulus(Value); };
        //MediumDec operator%(signed int Value) { ApplyModulus(Value); };
        //MediumDec operator%(unsigned __int64 Value) { ApplyModulus(Value); }
        //MediumDec operator%(signed __int64 Value) { ApplyModulus(Value); }
        //MediumDec operator%(unsigned __int16 Value) { ApplyModulus(Value); }
        //MediumDec operator%(signed __int16 Value) { ApplyModulus(Value); }
        //MediumDec operator%(unsigned __int8 Value) { ApplyModulus(Value); }
        //MediumDec operator%(signed __int8 Value) { ApplyModulus(Value); }
        ////Value to power of Value
        //MediumDec operator^(unsigned int Value);
        ////************************************
        //// Method:    ApplyIntCompare
        //// FullName:  MediumDec::ApplyIntCompare
        //// Access:    private
        //// Returns:   bool
        //// Qualifier:
        //// Parameter: MediumDec c1
        //// Parameter: ValueType Value
        ////************************************
        //template <typename ValueType>
        //bool ApplyIntCompare(MediumDec c1, ValueType Value);
        ////************************************
        //// Method:    ApplyIntNotEquals
        //// FullName:  MediumDec::ApplyIntNotEquals
        //// Access:    private
        //// Returns:   bool
        //// Qualifier:
        //// Parameter: MediumDec c1
        //// Parameter: ValueType Value
        ////************************************
        //template <typename ValueType>
        //bool ApplyIntNotEquals(MediumDec c1, ValueType Value);
        //friend bool operator== (const MediumDec &c1, unsigned int &c2) { return ApplyIntCompare(c1, c2); };
        //friend bool operator!= (const MediumDec &c1, unsigned int &c2) { return ApplyIntNotEquals(c1, c2); };
        ////************************************
        //// Method:    operator*
        //// FullName:  MediumDec::operator*
        //// Access:    private
        //// Returns:   MediumDec
        //// Qualifier:
        //// Parameter: double Value
        ////************************************
        //MediumDec operator*(double Value);
        //template <typename ValueType>
        //void ApplyIntMultiply(ValueType Value);
        //MediumDec operator*(unsigned int Value) { ApplyIntMultiply(Value); };
        //MediumDec operator*(signed int Value) { ApplyIntMultiply(Value); };
        //MediumDec operator*(unsigned __int64 Value) { ApplyIntMultiply(Value); }
        //MediumDec operator*(signed __int64 Value) { ApplyIntMultiply(Value); }
        //MediumDec operator*(unsigned __int16 Value) { ApplyIntMultiply(Value); }
        //MediumDec operator*(signed __int16 Value) { ApplyIntMultiply(Value); }
        //MediumDec operator*(unsigned __int8 Value) { ApplyIntMultiply(Value); }
        //MediumDec operator*(signed __int8 Value) { ApplyIntMultiply(Value); }
        ////************************************
        //// Method:    operator/
        //// FullName:  MediumDec::operator/
        //// Access:    private
        //// Returns:   MediumDec
        //// Qualifier:
        //// Parameter: double Value
        ////************************************
        //MediumDec operator/(double Value);
        //template <typename ValueType>
        //void ApplyIntDivide(ValueType Value);
        //MediumDec operator/(unsigned int Value) { ApplyIntDivide(Value); };
        //MediumDec operator/(signed int Value) { ApplyIntDivide(Value); };
        //MediumDec operator/(unsigned __int64 Value) { ApplyIntDivide(Value); }
        //MediumDec operator/(signed __int64 Value) { ApplyIntDivide(Value); }
        //MediumDec operator/(unsigned __int16 Value) { ApplyIntDivide(Value); }
        //MediumDec operator/(signed __int16 Value) { ApplyIntDivide(Value); }
        //MediumDec operator/(unsigned __int8 Value) { ApplyIntDivide(Value); }
        //MediumDec operator/(signed __int8 Value) { ApplyIntDivide(Value); }
    };
}

#endif