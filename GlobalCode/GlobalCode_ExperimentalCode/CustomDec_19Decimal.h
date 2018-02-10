/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#ifndef CustomDec_IncludeGuard
#define CustomDec_IncludeGuard

#ifndef BlazesGlobalCode_FileStructureVersion
#	define BlazesGlobalCode_FileStructureVersion 0
//FileStructureVersion 0 = Refers to required files set up similar/same as Library Versions of files
//FileStructureVersion 1 = All required files from GlobalCode within same folder locally
#endif

#ifdef BLAZESGLOBALCODE_LIBRARY
#	include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#	ifndef DLL_API
#		define DLL_API
#	endif
#endif

#if !defined BlazesGlobalCode_CSharpCode
#	include <io.h>
#	include <math.h>
#	include <iostream>
#	include <string>
#	include "SuperDecHex.h"

//Non-Alternating headers above (Structure based headers in this section)
#	if BlazesGlobalCode_FileStructureVersion == 0 || !defined BlazesGlobalCode_FileStructureVersion//(library style  layout)
//Place  library Style  layout here
#		if BlazesGlobalCode_Int128Version == 0 || !defined BlazesGlobalCode_Int128Version
		#include "..\ThirdPartyCode\bigint\bigint.h"
#		endif
#	elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
//Place Local version layout here
#		if BlazesGlobalCode_Int128Version == 0 || !defined BlazesGlobalCode_Int128Version
		#include ".ThirdPartyCode\bigint\bigint.h"
#		endif
#	endif
#endif

template <typename IntValueType=unsigned __int32>
class DLL_API CustomDec_19Decimal
{
	unsigned IntValueType IntValue;
	unsigned __int8 DecBoolStatus = 0;
	unsigned __int64 DecimalStatus;
	//************************************
	// Method:    AsInt32
	// FullName:  CustomDec_ExtraDec64_19Decimal::AsInt32
	// Access:    private
	// Returns:   signed __int32
	// Qualifier:
	//************************************
	signed __int32 AsInt32();
	//************************************
	// Method:    AsSignedInt64
	// FullName:  CustomDec_ExtraDec64_19Decimal::AsSignedInt64
	// Access:    private
	// Returns:   signed __int64
	// Qualifier:
	//************************************
	signed __int64 AsSignedInt64();
	//************************************
	// Method:    AsDouble
	// FullName:  CustomDec_ExtraDec64_19Decimal::AsDouble
	// Access:    private
	// Returns:   double
	// Qualifier:
	//************************************
	double AsDouble();
	//************************************
	// Method:    AsString
	// FullName:  CustomDec_ExtraDec64_19Decimal::AsString
	// Access:    private
	// Returns:   std::string
	// Qualifier:
	//************************************
	std::string AsString();
	
	#ifdef BlazesGlobalCode_VS2015FeaturesOn
		CustomDec_19Decimal operator+(dynamic Value) 
		{
		
		};
		/*
		public static CustomDec_19Decimal operator +(CustomDec_19Decimal self, dynamic y)
		{
			if (self.GetDecBoolStatus() == 1 && y < 0)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + (uint)Math.Abs(y);
			}
			else if (self.GetDecBoolStatus() == 0 && y >= 0)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + (uint)y;
			}
			else
			{
				// -X + Y
				if (self.GetDecBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y > self.GetIntValue())
					{
						self.IntValue = (uint)y - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - (uint)y;
					}
				}// X-Y
				else
				{
					uint TempY = Math.Abs(y);
					if (self.GetIntValue() > TempY)
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - TempY;
					}
					else
					{//ex. 9 + -10
						self.IntValue = TempY - self.GetIntValue();
						self.DecBoolStatus = 1;
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}
		*/
	#else
		//************************************
		// Method:    ApplyAddition
		// FullName:  CustomDec_ExtraDec64_19Decimal::ApplyAddition
		// Access:    private
		// Returns:   void
		// Qualifier:
		// Parameter: ValueType Value
		//************************************
		template <typename ValueType>
		void ApplyIntAddition(ValueType Value);
		CustomDec_19Decimal operator+(unsigned int Value) { ApplyIntAddition(Value); };
		CustomDec_19Decimal operator+(signed int Value) { ApplyIntAddition(Value); };
		CustomDec_19Decimal operator+(unsigned __int64 Value) { ApplyIntAddition(Value); }
		CustomDec_19Decimal operator+(signed __int64 Value) { ApplyIntAddition(Value); }
		CustomDec_19Decimal operator+(unsigned __int16 Value) { ApplyIntAddition(Value); }
		CustomDec_19Decimal operator+(signed __int16 Value) { ApplyIntAddition(Value); }
		CustomDec_19Decimal operator+(unsigned __int8 Value) { ApplyIntAddition(Value); }
		CustomDec_19Decimal operator+(signed __int8 Value) { ApplyIntAddition(Value); }
	#endif
	

	
	//************************************
	// Method:    operator+
	// FullName:  CustomDec_ExtraDec64_19Decimal::operator+
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec_19Decimal operator+(double Value)
	{
	
	}
	//************************************
	// Method:    operator+
	// FullName:  CustomDec_ExtraDec64_19Decimal::operator+
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: std::string Value
	//************************************
	CustomDec_19Decimal operator+(std::string Value)
	{
	
	}
	//************************************
	// Method:    ApplySubtraction
	// FullName:  CustomDec_ExtraDec64_19Decimal::ApplySubtraction
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyIntSubtraction(ValueType Value);
	CustomDec_19Decimal operator-(unsigned int Value) { ApplyIntSubtraction(Value); };
	CustomDec_19Decimal operator-(signed int Value) { ApplyIntSubtraction(Value); };
	CustomDec_19Decimal operator-(unsigned __int64 Value) { ApplyIntSubtraction(Value); }
	CustomDec_19Decimal operator-(signed __int64 Value) { ApplyIntSubtraction(Value); }
	CustomDec_19Decimal operator-(unsigned __int16 Value) { ApplyIntSubtraction(Value); }
	CustomDec_19Decimal operator-(signed __int16 Value) { ApplyIntSubtraction(Value); }
	CustomDec_19Decimal operator-(unsigned __int8 Value) { ApplyIntSubtraction(Value); }
	CustomDec_19Decimal operator-(signed __int8 Value) { ApplyIntSubtraction(Value); }
	//************************************
	// Method:    ApplyEqual
	// FullName:  CustomDec_ExtraDec64_19Decimal::ApplyEqual
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyIntEqual(ValueType Value);
	CustomDec_19Decimal operator=(std::string Value);
	CustomDec_19Decimal operator=(unsigned int Value) { ApplyIntEqual(Value); };
	CustomDec_19Decimal operator=(signed int Value) { ApplyIntEqual(Value); };
	CustomDec_19Decimal operator=(unsigned __int64 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(signed __int64 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(unsigned __int16 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(signed __int16 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(unsigned __int8 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(signed __int8 Value) { ApplyIntEqual(Value); }
	CustomDec_19Decimal operator=(double Value);
	//************************************
	// Method:    ApplyModulus
	// FullName:  CustomDec_ExtraDec64_19Decimal::ApplyModulus
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyModulus(ValueType Value);
	CustomDec_19Decimal operator%(unsigned int Value) { ApplyModulus(Value); };
	CustomDec_19Decimal operator%(signed int Value) { ApplyModulus(Value); };
	CustomDec_19Decimal operator%(unsigned __int64 Value) { ApplyModulus(Value); }
	CustomDec_19Decimal operator%(signed __int64 Value) { ApplyModulus(Value); }
	CustomDec_19Decimal operator%(unsigned __int16 Value) { ApplyModulus(Value); }
	CustomDec_19Decimal operator%(signed __int16 Value) { ApplyModulus(Value); }
	CustomDec_19Decimal operator%(unsigned __int8 Value) { ApplyModulus(Value); }
	CustomDec_19Decimal operator%(signed __int8 Value) { ApplyModulus(Value); }
	//Value to power of Value
	CustomDec_19Decimal operator^(unsigned int Value);
	//************************************
	// Method:    ApplyIntCompare
	// FullName:  CustomDec_ExtraDec64_19Decimal::ApplyIntCompare
	// Access:    private
	// Returns:   bool
	// Qualifier:
	// Parameter: CustomDec c1
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	bool ApplyIntCompare(CustomDec c1, ValueType Value);
	//************************************
	// Method:    ApplyIntNotEquals
	// FullName:  CustomDec_ExtraDec64_19Decimal::ApplyIntNotEquals
	// Access:    private
	// Returns:   bool
	// Qualifier:
	// Parameter: CustomDec c1
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	bool ApplyIntNotEquals(CustomDec_19Decimal c1, ValueType Value);
	friend bool operator== (const CustomDec_19Decimal &c1, unsigned int &c2) { return ApplyIntCompare(c1, c2); };
	friend bool operator!= (const CustomDec_19Decimal &c1, unsigned int &c2) { return ApplyIntNotEquals(c1, c2); };
	//************************************
	// Method:    operator*
	// FullName:  CustomDec_ExtraDec64_19Decimal::operator*
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec_19Decimal operator*(double Value);
	template <typename ValueType>
	void ApplyIntMultiply(ValueType Value);
	CustomDec_19Decimal operator*(unsigned int Value) { ApplyIntMultiply(Value); };
	CustomDec_19Decimal operator*(signed int Value) { ApplyIntMultiply(Value); };
	CustomDec_19Decimal operator*(unsigned __int64 Value) { ApplyIntMultiply(Value); }
	CustomDec_19Decimal operator*(signed __int64 Value) { ApplyIntMultiply(Value); }
	CustomDec_19Decimal operator*(unsigned __int16 Value) { ApplyIntMultiply(Value); }
	CustomDec_19Decimal operator*(signed __int16 Value) { ApplyIntMultiply(Value); }
	CustomDec_19Decimal operator*(unsigned __int8 Value) { ApplyIntMultiply(Value); }
	CustomDec_19Decimal operator*(signed __int8 Value) { ApplyIntMultiply(Value); }
	//************************************
	// Method:    operator/
	// FullName:  CustomDec_ExtraDec64_19Decimal::operator/
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec_19Decimal operator/(double Value);
	template <typename ValueType>
	void ApplyIntDivide(ValueType Value);
	CustomDec_19Decimal operator/(unsigned int Value) { ApplyIntDivide(Value); };
	CustomDec_19Decimal operator/(signed int Value) { ApplyIntDivide(Value); };
	CustomDec_19Decimal operator/(unsigned __int64 Value) { ApplyIntDivide(Value); }
	CustomDec_19Decimal operator/(signed __int64 Value) { ApplyIntDivide(Value); }
	CustomDec_19Decimal operator/(unsigned __int16 Value) { ApplyIntDivide(Value); }
	CustomDec_19Decimal operator/(signed __int16 Value) { ApplyIntDivide(Value); }
	CustomDec_19Decimal operator/(unsigned __int8 Value) { ApplyIntDivide(Value); }
	CustomDec_19Decimal operator/(signed __int8 Value) { ApplyIntDivide(Value); }
};



#ifndef  BlazesGlobalCode_VS2015FeaturesOn
	template <typename ValueType>
	void CustomDec::ApplyModulus(ValueType Value)
	{
	#	if defined SuperDec_SignedIntStatus
		IntValue %= Value;
	#	else//Unsigned Version (Stored data in Decimal Status)

	#	endif
	}

	template <typename ValueType>
	bool CustomDec::ApplyIntCompare(CustomDec c1, ValueType Value)
	{
	#	if defined SuperDec_SignedIntStatus
	#	ifdef CustomDec_AngleDec

	#	else
		return c1.IntValue == Value&&c1.DecimalStatus == 0;
	#	endif
	#	else//Unsigned Version (Stored data in Decimal Status)
		//Write code for this later
		return false;
	#	endif
	}

	template <typename ValueType>
	bool CustomDec::ApplyIntNotEquals(CustomDec c1, ValueType Value)
	{
		return !ApplyIntCompare(c1, Value);
	}

	template <typename ValueType>
	void CustomDec::ApplyIntAddition(ValueType Value)
	{
	#	if defined SuperDec_SignedIntStatus
		IntValue += Value;
	#	elif defined SuperDec_UnsignedBoolean
		if(DecBoolStatus==0)
		{
			if(Value<0)
			{
				if(Value>IntValue)
				{
					IntValue = Value - IntValue;
					DecBoolStatus = 1;
				}
				else
				{
				}
			}
			else
			{
			}
		}
		else if(DecBoolStatus==1)
		{
		}
		else//Other Values used for special Decimal Statuses etc
		{
		}
		if(IntValue==0&&DecBoolStatus==1)//Fix so negative zero is positive zero
		{
			DecBoolStatus = 0;
		}
	#	else//Unsigned Version (Stored data in Decimal Status)

	#	endif
	}

	template <typename ValueType>
	void CustomDec::ApplyIntSubtraction(ValueType Value)
	{
	#	if defined SuperDec_SignedIntStatus
		IntValue -= Value;
	#	elif defined SuperDec_UnsignedBoolean
		if(DecBoolStatus==0)
		{
			if(Value>0)
			{
				if(Value>IntValue)
				{
					IntValue = Value - IntValue;
					DecBoolStatus = 1;
				}
				else
				{
					IntValue -= Value;
				}
			}
			else
			{
			}
		}
		else if(DecBoolStatus == 1)
		{
		}
		else//Other Values used for special Decimal Statuses etc
		{
		}
		if(IntValue==0&&DecBoolStatus==1)//Fix so negative zero is positive zero
		{
			DecBoolStatus = 0;
		}
	#	else//Unsigned Version (Stored data in Decimal Status)

	#	endif
	}

	template <typename ValueType>
	void CustomDec::ApplyIntMultiply(ValueType Value)
	{
		if(Value == 0)
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else if(Value == 1) {}
		else if(Value ==-1)
		{
			if(DecimalStatus==0&&IntValue==0){}
	#	if defined SuperDec_SignedIntStatus
	#		if defined SuperDec_sInt32
			else if(IntValue == -2147483648)
			{
	#		elif defined SuperDec_sInt8
			else if(IntValue==-128)
			{
	#		elif defined SuperDec_sInt16
			else if(IntValue == -32768)
			{
	#		elif defined SuperDec_sInt64
			else if(IntValue == -9223372036854775808)
			{
	#		endif
				IntValue = 0;
			}
			else if(IntValue==0)
			{//Set to representation -Zero.XX.....
	#		if defined SuperDec_sInt32
				IntValue = -2147483648;
	#		elif defined SuperDec_sInt8
				IntValue = -128;
	#		elif defined SuperDec_sInt16
				IntValue = -32768;
	#		elif defined SuperDec_sInt64
				IntValue = -9223372036854775808;
	#		endif
			}
			else
			{
				IntValue *= -1;
			}
	#	elif defined SuperDec_UnsignedBoolean
			if(DecBoolStatus == 1)
			{
				DecBoolStatus = 0;
			}
			else if(DecBoolStatus == 0)
			{
				DecBoolStatus = 1;
			}
	#		if defined SuperDec_EnableSpecialDecimalStatus
			else
			{

			}
	#		endif
	#	else
			if(DecimalStatus==0)
			{
				if(IntValue==0){}
				else
				{
	#		if defined SuperDec_9Decimal
					DecimalStatus = -2147483648;
	#		elif defined SuperDec_2Decimal
					DecimalStatus = -128;
	#		elif defined SuperDec_4Decimal
					DecimalStatus = -32768;
	#		elif defined SuperDec_18Decimal
					DecimalStatus = -9223372036854775808;
	#		endif
				}
			}
	#		if defined SuperDec_9Decimal
			else if(DecimalStatus == -2147483648)
			{
	#		elif defined SuperDec_2Decimal
			else if(DecimalStatus==-128)
			{
	#		elif defined SuperDec_4Decimal
			else if(DecimalStatus == -32768)
			{
	#		elif defined SuperDec_18Decimal
			else if(DecimalStatus == -9223372036854775808)
			{
	#		endif
				DecimalStatus = 0;
			}
			else
			{
				DecimalStatus *= -1;
			}
	#	endif
		}
		else
		{
			bool ResultIsNegative = false;
			if(Value < 0)
			{
	#		if defined SuperDec_UnsignedBoolean
				if(DecBoolStatus == 1)
				{
					ResultIsNegative = true;
				}
	#		elif defined SuperDec_SignedIntStatus
				if(IntValue > 0)
				{
					ResultIsNegative = true;
				}
	#		else
				if(DecimalStatus > 0)
				{
					ResultIsNegative = true;
				}
	#		endif
			}
			else
			{
	#		if defined SuperDec_UnsignedBoolean
				if(DecBoolStatus < 0)
				{
					ResultIsNegative = true;
				}
	#		elif defined SuperDec_SignedIntStatus
				if(IntValue < 0)
				{
					ResultIsNegative = true;
				}
	#		else
				if(DecimalStatus < 0)
				{
					ResultIsNegative = true;
				}
	#		endif
			}
			unsigned __int64 DecRep = DecAsUnsignedInt();
	#	if SuperDec_PreventTruncationToZero == 2
			//DecRep is multiplied by 10 to allow rounding up remaining value
			DecRep *= 10;
	#	endif
			DecRep *= Value;
	#	if SuperDec_PreventTruncationToZero == 2//Place code here for extra rounding up feature
	#	endif
			ConvertFromDecRep(DecRep);
			if(ResultIsNegative)
			{
	#		if defined SuperDec_UnsignedBoolean
				DecBoolStatus = 1;
	#		elif defined SuperDec_SignedIntStatus
				if(IntValue == 0 && ResultIsNegative)
				{
	#			if defined SuperDec_sInt32
					IntValue = -2147483648;
	#			elif defined SuperDec_sInt8
					IntValue = -128;
	#			elif defined SuperDec_sInt16
					IntValue = -32768;
	#			elif defined SuperDec_sInt64
					IntValue = -9223372036854775808;
	#			endif
				}
				else { IntValue *= -1; }
	#		elif !defined SuperDec_AngleDecimal
				DecimalStatus *= -1;
	#		endif
			}
			else
			{
	#		if defined SuperDec_UnsignedBoolean
				DecBoolStatus = 0;
	#		endif
			}
		}
		//#		if defined SuperDec_SignedIntStatus
		//		if(DecimalStatus == 0)
		//		{
		//			IntValue *= Value;
		//		}
		//		else
		//		{
		//			signed __int64 DecRep = DecAsSignedInt();
		//			DecRep *= Value;
		//			ConvertFromDecRep(DecRep);
		//		}
		//#		else
		//		signed __int64 DecRep = DecAsSignedInt();
		//		DecRep *= Value;
		//		ConvertFromDecRep(DecRep);
		//#		endif
	}

	template <typename ValueType>
	void CustomDec::ApplyIntDivide(ValueType Value)
	{
		//signed __int64 DecRep = DecAsSignedInt();
		//DecRep /= Value;
		//ConvertFromDecRep(DecRep);
	}

	template <typename ValueType>
	void CustomDec::ApplyIntEqual(ValueType Value)
	{}
#endif

#endif
/*using System;

//Requires BigMath library to compile

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
	using static GlobalCode_VariableConversionFunctions.VariableConversionFunctions;

	public struct CustomDec_19Decimal
	{
		//0 = Positive;1=Negative;Other states at higher then 1
		private byte DecBoolStatus;

		//Stores decimal section info
		private ulong DecimalStatus;

		private uint IntValue;

		public CustomDec_19Decimal Abs()
		{
			this.DecBoolStatus = 0;
			return this;
		}

		public CustomDec_19Decimal Floor()
		{
			this.DecimalStatus = 0;
			return this;
		}

		public CustomDec_19Decimal Ceil()
		{
			if (this.DecimalStatus!=0)
			{
				this.DecimalStatus = 0;
				this.IntValue += 1;
			}
			return this;
		}

		public CustomDec_19Decimal(double Value)
		{
			if (Value < 0)
			{
				Value *= -1;
				DecBoolStatus = 1;
			}
			else
			{
				DecBoolStatus = 0;
			}
			IntValue = (uint)System.Math.Floor(Value);
			Value -= IntValue;
			DecimalStatus = ExtractDecimalHalf(Value);
		}

		public CustomDec_19Decimal(int Value)
		{
			if (Value < 0)
			{
				DecBoolStatus = 1;
			}
			else
			{
				DecBoolStatus = 0;
			}
			IntValue = (uint)Value;
			DecimalStatus = 0;
		}

		public CustomDec_19Decimal(uint Value)
		{
			this.DecBoolStatus = 0;
			this.IntValue = Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(long Value)
		{
			//Cap value if too big on initialize
			if (Value > 2147483647)
			{
				Value = 2147483647;
			}//Cap Value also if too small
			else if (Value < -2147483648)
			{
				Value = -2147483648;
			}
			if (Value < 0)
			{
				this.DecBoolStatus = 1;
			}
			else
			{
				this.DecBoolStatus = 0;
			}
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(ulong Value)
		{
			//Cap value if too big on initialize
			if (Value > 4294967295)
			{
				Value = 4294967295;
			}
			this.DecBoolStatus = 0;
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(short Value)
		{
			if (Value < 0)
			{
				this.DecBoolStatus = 1;
			}
			else
			{
				this.DecBoolStatus = 0;
			}
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(ushort Value)
		{
			this.DecBoolStatus = 0;
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(sbyte Value)
		{
			if (Value < 0)
			{
				this.DecBoolStatus = 1;
			}
			else
			{
				this.DecBoolStatus = 0;
			}
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public CustomDec_19Decimal(byte Value)
		{
			this.DecBoolStatus = 0;
			this.IntValue = (uint)Value;
			this.DecimalStatus = 0;
		}

		public static explicit operator double(CustomDec_19Decimal self)
		{
			double Value = 0.0;
			Value += self.IntValue;
			Value += (self.DecimalStatus * 0.0000000000000000001);
			if (self.DecBoolStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to int
		public static explicit operator int(CustomDec_19Decimal self)
		{
			int Value = (int)self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to int 64
		public static explicit operator long(CustomDec_19Decimal self)
		{
			long Value = self.IntValue;
			if (self.DecimalStatus == 1) { Value *= -1; }
			return Value;
		}

		//Explicit Conversion from this to uint
		public static explicit operator uint(CustomDec_19Decimal self)
		{
			return self.IntValue;
		}

		//Explicit Conversion from this to unsigned int 64
		public static explicit operator ulong(CustomDec_19Decimal self)
		{
			return self.IntValue;
		}

		public static ulong ForceConvertFromInt256(BigMath.Int256 Value)
		{
			ulong ConvertedValue = 0;
			//Larger than ulong (default to zero)
			if (Value > 18446744073709551615)
			{
				Console.WriteLine("Overflow Detected");
			}
			else
			{
				BigMath.Int128 Value02 = (BigMath.Int128)Value;
				ConvertedValue = (ulong)Value02;
			}
			return ConvertedValue;
		}

		static public implicit operator string(CustomDec_19Decimal self)
		{
			System.String Value = "";
			uint IntegerHalf = self.IntValue;
			byte CurrentDigit;
			if (self.DecBoolStatus == 1) { Value += "-"; }
			for (sbyte Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
			{
				CurrentDigit = (byte)(IntegerHalf / Math.Pow(10, Index));
				IntegerHalf -= (uint)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			Value += ".";
			ulong DecimalHalf = self.DecimalStatus;
			for (sbyte Index = 18; Index >= 0; Index--)
			{
				CurrentDigit = (byte)(DecimalHalf / Math.Pow(10, Index));
				DecimalHalf -= (ulong)(CurrentDigit * Math.Pow(10, Index));
				Value += DigitAsChar(CurrentDigit);
			}
			return Value;
		}

		public static implicit operator CustomDec_19Decimal(double Value)
		{
			return new CustomDec_19Decimal(Value);
		}

		public static implicit operator CustomDec_19Decimal(int Value)
		{
			return new CustomDec_19Decimal(Value);
		}

		public static implicit operator CustomDec_19Decimal(uint Value)
		{
			return new CustomDec_19Decimal(Value);
		}

		public static implicit operator CustomDec_19Decimal(long Value)
		{
			return new CustomDec_19Decimal(Value);
		}

		public static implicit operator CustomDec_19Decimal(ulong Value)
		{
			return new CustomDec_19Decimal(Value);
		}

		public static CustomDec_19Decimal operator -(CustomDec_19Decimal self, double y)
		{
			bool IsYNegative = (y < 0) ? true : false;
			y = Math.Abs(y);
			uint WholeHalfOfY = (uint)Math.Floor(y);
			y -= WholeHalfOfY;
			if (WholeHalfOfY == 0) { }
			//ex. -9 - 9
			else if (self.GetDecBoolStatus() == 1 && IsYNegative == false)
			{// -X - Y
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}//ex. 9 - (-1)
			else if (self.GetDecBoolStatus() == 0 && IsYNegative)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else
			{
				// X - (Y)
				if (self.GetDecBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (WholeHalfOfY > self.GetIntValue())
					{
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - WholeHalfOfY;
					}
				}// -X - (Y)
				else
				{
					// ex. -8 - (-9)
					if (self.IntValue > WholeHalfOfY)
					{
						self.IntValue = WholeHalfOfY - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
				}
			}
			//Decimal Calculation Section
			ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
			if (self.GetDecimalStatus() != 0 || SecondDec != 0)
			{
				// ex. -0.5 - 0.6
				if (self.GetDecBoolStatus() == 1 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}// ex. 0.5 - (-0.6)
				else if (self.GetDecBoolStatus() == 0 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{// ex. -0.7 - (-0.6)
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{ //ex  0.6 - 0.5
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static CustomDec_19Decimal operator -(CustomDec_19Decimal self, CustomDec_19Decimal y)
		{
			bool IsYNegative = (y.GetDecBoolStatus() == 1) ? true : false;
			//ex. -9 - 9
			if (self.GetDecBoolStatus() == 1 && IsYNegative == false)
			{// -X - Y
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}//ex. 9 - (-1)
			else if (self.GetDecBoolStatus() == 0 && IsYNegative == true)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else
			{
				// X - (Y)
				if (self.GetDecBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (y.GetIntValue() > self.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - y.GetIntValue();
					}
				}// -X - (Y)
				else
				{
					// ex. -8 - (-9)
					if (self.IntValue > y.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
				}
			}
			//Decimal Section
			if (self.GetDecimalStatus() != 0 || y.GetDecimalStatus() != 0)
			{
				//ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
				// ex. -0.5 - 0.6
				if (self.GetDecBoolStatus() == 1 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}// ex. 0.5 - (-0.6)
				else if (self.GetDecBoolStatus() == 0 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{// ex. -0.7 - (-0.6)
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{ //ex  0.6 - 0.5
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static CustomDec_19Decimal operator -(CustomDec_19Decimal self, dynamic y)
		{
			//ex. -9 - 9
			if (self.GetDecBoolStatus() == 1 && y >= 0)
			{// -X - Y
				self.IntValue = self.GetIntValue() + (uint)y;
			}//ex. 9 - (-1)
			else if (self.GetDecBoolStatus() == 0 && y < 0)
			{
				//X - (-Y)
				self.IntValue = self.GetIntValue() + (uint)Math.Abs(y);
			}
			else
			{
				// X - (Y)
				if (self.GetDecBoolStatus() == 0)
				{
					// ex. 8 - 9
					if (y > self.GetIntValue())
					{
						self.IntValue = (uint)y - self.GetIntValue();
						self.DecBoolStatus = 1;
					} //ex. 8 - 7
					else
					{
						self.IntValue = self.IntValue - (uint)y;
					}
				}// -X - (Y)
				else
				{
					uint TempY = (uint)Math.Abs(y);
					// ex. -8 - (-9)
					if (self.IntValue > TempY)
					{
						self.IntValue = TempY - self.IntValue;
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 - (-5)
						self.IntValue = self.GetIntValue() - TempY;
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0)
			{
				self.DecBoolStatus = 0;
			}
			return self;
		}

		public static CustomDec_19Decimal operator %(CustomDec_19Decimal self, int y)
		{
			if (y == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
				if (self.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue %= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 %= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static CustomDec_19Decimal operator %(CustomDec_19Decimal self, double y)
		{
			if (y == 0.0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
				uint WholeHalf = (uint)y;
				//Use x Int Operation instead if y has no decimal places
				if (WholeHalf == y)
				{
					if (self.DecimalStatus == 0)
					{
						//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue %= (uint)y;
					}
					else
					{
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 *= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static CustomDec_19Decimal operator %(CustomDec_19Decimal self, CustomDec_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.GetDecBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue %= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 %= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 %= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static CustomDec_19Decimal operator *(CustomDec_19Decimal self, CustomDec_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y.GetDecBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue *= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 *= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static CustomDec_19Decimal operator *(CustomDec_19Decimal self, int y)
		{
			if (y == 0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
				if (self.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue *= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 *= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static CustomDec_19Decimal operator *(CustomDec_19Decimal self, double y)
		{
			if (y == 0.0)
			{
				self.IntValue = 0;
				self.DecimalStatus = 0;
				self.DecBoolStatus = 0;
			}
			else
			{
				if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
				uint WholeHalf = (uint)y;
				//Use x Int Operation instead if y has no decimal places
				if (WholeHalf == y)
				{
					if (self.DecimalStatus == 0)
					{
						//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue *= (uint)y;
					}
					else
					{
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 *= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 *= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}

			return self;
		}

		public static CustomDec_19Decimal operator /(CustomDec_19Decimal self, CustomDec_19Decimal y)
		{
			if (y.GetIntValue() == 0 && y.GetDecimalStatus() == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y.GetDecBoolStatus() == 1) { self.SwapNegativeStatus(); }
				if (self.DecimalStatus == 0 && y.GetDecimalStatus() == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue /= y.IntValue;
				}
				else if (y.GetDecimalStatus() == 0)
				{
					BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 /= y.IntValue;
					self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
					SelfAsInt128 -= self.IntValue * 10000000000000000000;
					self.DecimalStatus = (uint)SelfAsInt128;
				}
				else
				{
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)/(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = y.IntValue;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += y.DecimalStatus;
					SelfAsInt256 /= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static CustomDec_19Decimal operator /(CustomDec_19Decimal self, int y)
		{
			if (y == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y < 0) { self.SwapNegativeStatus(); y *= -1; }
				if (self.DecimalStatus == 0)
				{//Use normal simple (int value) * (int value) if not dealing with any decimals
					self.IntValue *= (uint)y;
				}
				else
				{
					BigMath.Int128 SelfAsInt128 = (BigMath.Int128)self.DecimalStatus;
					SelfAsInt128 += self.IntValue * 10000000000000000000;
					SelfAsInt128 /= y;
					BigMath.Int128 TempStorage = SelfAsInt128 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage *= 10000000000000000000;
					SelfAsInt128 -= TempStorage;
					self.DecimalStatus = (ulong)SelfAsInt128;
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static CustomDec_19Decimal operator /(CustomDec_19Decimal self, double y)
		{
			if (y == 0)
			{
				Console.WriteLine("Prevented dividing by zero");
			}
			else
			{
				if (y < 0.0) { self.SwapNegativeStatus(); y *= -1.0; }
				uint WholeHalf = (uint)y;
				//Use x Int Operation instead if y has no decimal places
				if (WholeHalf == y)
				{
					if (self.DecimalStatus == 0)
					{
						//Use normal simple (int value) * (int value) if not dealing with any decimals
						self.IntValue /= WholeHalf;
					}
					else
					{
						BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
						SelfAsInt128 += self.IntValue * 10000000000000000000;
						SelfAsInt128 /= WholeHalf;
						self.IntValue = (uint)(SelfAsInt128 / 10000000000000000000);
						SelfAsInt128 -= self.IntValue * 10000000000000000000;
						self.DecimalStatus = (uint)SelfAsInt128;
					}
				}
				else
				{
					y -= WholeHalf;
					ulong Decimalhalf;
					if (y == 0.25)
					{
						Decimalhalf = 2500000000000000000;
					}
					else if (y == 0.5)
					{
						Decimalhalf = 5000000000000000000;
					}
					else
					{
						Decimalhalf = ExtractDecimalHalf(y);
					}
					//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
					BigMath.Int256 SelfAsInt256 = self.IntValue;
					SelfAsInt256 *= 10000000000000000000;
					SelfAsInt256 += self.DecimalStatus;
					BigMath.Int256 YAsInt256 = WholeHalf;
					YAsInt256 *= 10000000000000000000;
					YAsInt256 += Decimalhalf;
					SelfAsInt256 /= YAsInt256;
					SelfAsInt256 /= 10000000000000000000;
					BigMath.Int256 TempStorage = SelfAsInt256 / 10000000000000000000;
					self.IntValue = (uint)TempStorage;
					TempStorage = self.IntValue;
					TempStorage *= 10000000000000000000;
					SelfAsInt256 -= TempStorage;
					self.DecimalStatus = ForceConvertFromInt256(SelfAsInt256);
				}
				//Prevent dividing/multiplying value into nothing by dividing too small (set to .0000000000000000001 instead of having value set as zero)
				if (self.IntValue == 0 && self.DecimalStatus == 0) { self.DecimalStatus = 1; }
			}
			return self;
		}

		public static CustomDec_19Decimal operator +(CustomDec_19Decimal self, double y)
		{
			bool IsYNegative = (y < 0) ? true : false;
			y = Math.Abs(y);
			uint WholeHalfOfY = (uint)Math.Floor(y);
			y -= WholeHalfOfY;
			if (WholeHalfOfY == 0) { }
			else if (self.GetDecBoolStatus() == 1 && IsYNegative)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else if (self.GetDecBoolStatus() == 0 && IsYNegative == false)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + WholeHalfOfY;
			}
			else
			{
				// -X + Y
				if (self.GetDecBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y > self.GetIntValue())
					{
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
				}// X-Y
				else
				{
					if (self.GetIntValue() > WholeHalfOfY)
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - WholeHalfOfY;
					}
					else
					{//ex. 9 + -10
						self.IntValue = WholeHalfOfY - self.GetIntValue();
						self.DecBoolStatus = 1;
					}
				}
			}
			//Decimal Calculation Section
			if (self.GetDecBoolStatus() != 0 || y != 0)
			{
				ulong SecondDec = (ulong)(System.Math.Abs(y) - System.Math.Abs(WholeHalfOfY)) * 10000000000000000000;
				// ?.XXXXXX + ?.YYYYYY
				if (self.GetDecBoolStatus() == 0 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				// -?.XXXXXX - ?.YYYYYY
				else if (self.GetDecBoolStatus() == 1 && IsYNegative == true)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + SecondDec;
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{
						// ex. 0.6 + -0.5
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}// ex. 0.6 + -.7
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{
						if (self.GetDecimalStatus() >= SecondDec)
						{
							self.DecimalStatus = self.GetDecimalStatus() - SecondDec;
						}// ex. -1.6 + 0.7
						else
						{
							self.DecimalStatus = SecondDec - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		public static CustomDec_19Decimal operator +(CustomDec_19Decimal self, CustomDec_19Decimal y)
		{
			bool IsYNegative = (y.GetDecBoolStatus() == 1) ? true : false;
			if (self.GetDecBoolStatus() == 1 && IsYNegative)
			{// -X - Y (ex. -8 + -6)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else if (self.GetDecBoolStatus() == 0 && IsYNegative == false)
			{
				//X + Y (ex. 8 + 6)
				self.IntValue = self.GetIntValue() + y.GetIntValue();
			}
			else
			{
				// -X + Y
				if (self.GetDecBoolStatus() == 1)
				{   //ex. -8 + 9
					if (y.GetIntValue() > self.GetIntValue())
					{
						self.IntValue = y.GetIntValue() - self.GetIntValue();
						self.DecBoolStatus = 0;
					}
					else
					{//ex. -8 +  4
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
				}// X + -Y
				else
				{
					if (self.GetIntValue() > y.GetIntValue())
					{//ex. 9 + -6
						self.IntValue = self.GetIntValue() - y.GetIntValue();
					}
					else
					{//ex. 9 + -10
						self.IntValue = y.GetIntValue() - self.IntValue;
						self.DecBoolStatus = 1;
					}
				}
			}
			//Decimal Section
			if (self.GetDecimalStatus() != 0 || y.GetDecimalStatus() != 0)
			{
				// ?.XXXXXX + ?.YYYYYY (ex. 0.9 + 0.2)
				if (self.GetDecBoolStatus() == 0 && IsYNegative == false)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue += 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				// -?.XXXXXX - ?.YYYYYY (ex. -0.9 + -0.2)
				else if (self.GetDecBoolStatus() == 1 && IsYNegative)
				{
					//Potential Overflow check
					BigMath.Int128 DecimalStatusTemp = self.GetDecimalStatus() + y.GetDecimalStatus();
					if (DecimalStatusTemp > 999999999999999999)
					{
						DecimalStatusTemp -= 999999999999999999;
						self.IntValue -= 1;
					}
					self.DecimalStatus = (ulong)DecimalStatusTemp;
				}
				else
				{
					if (IsYNegative)
					{
						// ex. 0.6 + -0.5
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}// ex. 0.6 + -.7
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 1;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
					else
					{ //ex -0.6 + 0.5
						if (self.GetDecimalStatus() >= y.GetDecimalStatus())
						{
							self.DecimalStatus = self.GetDecimalStatus() - y.GetDecimalStatus();
						}// ex. -1.6 + 0.7
						else
						{
							self.DecimalStatus = y.GetDecimalStatus() - self.GetDecimalStatus();
							if (self.IntValue == 0)
							{
								self.DecBoolStatus = 0;
							}
							else
							{
								self.IntValue -= 1;
							}
						}
					}
				}
			}
			//Fix potential negative zero
			if (self.IntValue == 0 && self.DecBoolStatus == 1 && self.DecimalStatus == 0) { self.DecBoolStatus = 0; }
			return self;
		}

		// Equality operator for comparing self to int type value
		public static bool operator ==(CustomDec_19Decimal self, dynamic Value)
		{
			if (Value is CustomDec_19Decimal)
			{
				if (self.DecBoolStatus == Value.DecBoolStatus && self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
				else { return false; }
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					uint WholeHalf = (uint)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							return self.IntValue == WholeHalf;
						}
						else
						{
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							return SelfAsInt128 == (WholeHalf * 10000000000000000000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
						BigMath.Int256 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int256 ValueAsInt256 = WholeHalf;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Decimalhalf;
						return SelfAsInt256 == ValueAsInt256;
					}
				}
			}
			else if (Value is String)
			{
				return (String) Value==(String) self;
			}
			else
			{
				if (self.DecimalStatus != 0) { return false; }
				else if (Value < 0 && self.DecBoolStatus == 0) { return false; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return false; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return true; }
					else { return false; }
				}
			}
		}

		// Inequality operator for comparing self to multiple value types
		public static bool operator !=(CustomDec_19Decimal self, dynamic Value)
		{
			if (Value is CustomDec_19Decimal)
			{
				if (self.DecBoolStatus != Value.DecBoolStatus || self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus) { return true; }
				else { return false; }
			}
			else if (Value is double)
			{
				if (Value < 0.0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0.0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					uint WholeHalf = (uint)Value;
					//Use x Int Operation instead if Value has no decimal places
					if (WholeHalf == Value)
					{
						if (self.DecimalStatus == 0)
						{
							//Use normal simple (int value) * (int value) if not dealing with anValue decimals
							return self.IntValue != WholeHalf;
						}
						else
						{
							BigMath.Int128 SelfAsInt128 = self.DecimalStatus;
							SelfAsInt128 += self.IntValue * 10000000000000000000;
							return SelfAsInt128 != (WholeHalf * 10000000000000000000);
						}
					}
					else
					{
						Value -= WholeHalf;
						ulong Decimalhalf;
						if (Value == 0.25)
						{
							Decimalhalf = 2500000000000000000;
						}
						else if (Value == 0.5)
						{
							Decimalhalf = 5000000000000000000;
						}
						else
						{
							Decimalhalf = ExtractDecimalHalf(Value);
						}
						//((self.IntValue * 10000000000000000000)+self.DecimalStatus)*(DecimalAsInt+(WholeHalf*10000000000000000000))/10000000000000000000 = ((self.IntValue*10000000000000000000)+self.DecimalStatus))
						BigMath.Int256 SelfAsInt256 = self.IntValue;
						SelfAsInt256 *= 10000000000000000000;
						SelfAsInt256 += self.DecimalStatus;
						BigMath.Int256 ValueAsInt256 = WholeHalf;
						ValueAsInt256 *= 10000000000000000000;
						ValueAsInt256 += Decimalhalf;
						return SelfAsInt256 != ValueAsInt256;
					}
				}
			}
			else if (Value is String)
			{
				return (String)Value != (String)self;
			}
			else
			{
				if (self.DecimalStatus != 0) { return true; }
				else if (Value < 0 && self.DecBoolStatus == 0) { return true; }
				else if (Value >= 0 && self.DecBoolStatus == 1) { return true; }
				else
				{
					Value = Math.Abs(Value);
					if (Value == self.IntValue) { return false; }
					else { return true; }
				}
			}
		}

		public override bool Equals(object obj)
		{
			if (obj == null || GetType() != obj.GetType()) { return false; }

			try
			{
				return this == (CustomDec_19Decimal)obj;
			}
			catch
			{
				return false;
			}
		}

		public byte GetDecBoolStatus()
		{
			return DecBoolStatus;
		}

		public ulong GetDecimalStatus()
		{
			return DecimalStatus;
		}

		// Override the Object.GetHashCode() method:
		public override int GetHashCode()
		{
			if (DecBoolStatus == 1)
			{
				return (int)(IntValue / 2 - 2147483648);
			}
			else
			{
				return (int)(IntValue / 2);
			}
		}

		/// <summary>
		///
		/// </summary>
		/// <returns></returns>
		public uint GetIntValue()
		{
			return IntValue;
		}

		public int GetIntValueAsInt32()
		{
			return (int)IntValue;
		}

		public void SwapNegativeStatus()
		{
			if (DecBoolStatus == 1) { DecBoolStatus = 0; }
			else { DecBoolStatus = 1; }
		}
	}
}*/