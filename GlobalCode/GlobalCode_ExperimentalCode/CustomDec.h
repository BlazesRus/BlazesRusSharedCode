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
#	elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
//Place Local version layout here
#	endif
#endif

//Attempt to auto-detect if compiling code as C#
#if !defined BlazesGlobalCode_CSharpCode && !defined __cplusplus
	#define BlazesGlobalCode_CSharpCode true
#endif

//Shortcut Templates here
#ifdef CustomDec_AngleDec
#	define SuperDec_sInt16 true
#	define SuperDec_AngleDecimal true
#endif

#ifdef CustomDec_sInt32_9Dec
#	define SuperDec_sInt32 true
#	define SuperDec_9Decimal true
#endif

//Detect If using SignedIntStatus
#ifndef SuperDec_Int32 && #ifndef (SuperDec_Int64) && #ifndef (SuperDec_Int16) && #ifndef (SuperDec_Int8)
#	define SuperDec_SignedIntStatus true
#	if !defined SuperDec_sInt64 && !defined SuperDec_sInt16 && !defined SuperDec_sInt32
#		define SuperDec_sInt32 true
#	endif
//Auto-Define Decimal Storage to 9 decimal storage unless specified
#	if !defined SuperDec_AngleDecimal && !defined SuperDec_9Decimal && !defined SuperDec_4Decimal && !defined SuperDec_2Decimal
#		define SuperDec_9Decimal true
#	endif
#endif

#if defined CustomDec_LargeDec_28Decimal
#	define SuperDec_RequiresMoreThan64BitCalculation
#	define SuperDec_Enable128BitUsage (1)
#endif

#if !defined SuperDec_PreventTruncationToZero
#	define SuperDec_PreventTruncationToZero 1
#endif

#ifdef BlazesGlobalCode_CSharpCode//C# version of code

#else//C++ version of code
class DLL_API CustomDec
{
#	ifdef SuperDec_sInt64
	signed __int64 IntValue;
#	elif defined (SuperDec_sInt16)
	signed __int16 IntValue;
#	elif defined (SuperDec_sInt8)
	signed __int8 IntValue;
#	elif defined (SuperDec_Int64)
	unsigned __int16 IntValue;
#	elif defined (SuperDec_Int32)
	unsigned __int8 IntValue;
#	elif defined (SuperDec_Int16)
	unsigned __int16 IntValue;
#	elif defined (SuperDec_Int8)
	unsigned __int8 IntValue;
#	else//Default to SuperDec_sInt32
	signed __int32 IntValue;
#	endif
#	ifdef SuperDec_UnsignedBoolean
	unsigned __int8 DecBoolStatus = 0;
#	endif
#	ifdef SuperDec_AngleDecimal
	unsigned __int32 DecimalStatus;
	unsigned __int16 DecimalStatus01;
#	elif defined SuperDec_SignedIntStatus
	unsigned __int32 DecimalStatus;
#	else
	unsigned __int32 DecimalStatus;
#	endif
	//************************************
	// Method:    DecAsSignedInt
	// FullName:  CustomDec::DecAsSignedInt
	// Access:    private
	// Returns:   signed __int64
	// Qualifier:
	//************************************
	signed __int64 DecAsSignedInt();
	unsigned __int64 DecAsUnsignedInt();
	//************************************
	// Convert Decimal Int Representation into actual storage values(after performing calculations etc)
	// Method:    ConvertFromDecRep
	// FullName:  CustomDec::ConvertFromDecRep
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: signed __int64 Value
	//************************************
	void ConvertFromDecRep(signed __int64 Value);
	//************************************
	// Method:    ConvertFromDecRep
	// FullName:  CustomDec::ConvertFromDecRep
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: unsigned __int64 Value
	//************************************
	void ConvertFromDecRep(unsigned __int64 Value);
	//************************************
	// Method:    AsInt32
	// FullName:  CustomDec::AsInt32
	// Access:    private
	// Returns:   signed __int32
	// Qualifier:
	//************************************
	signed __int32 AsInt32();
	//************************************
	// Method:    AsSignedInt64
	// FullName:  CustomDec::AsSignedInt64
	// Access:    private
	// Returns:   signed __int64
	// Qualifier:
	//************************************
	signed __int64 AsSignedInt64();
	//************************************
	// Method:    AsDouble
	// FullName:  CustomDec::AsDouble
	// Access:    private
	// Returns:   double
	// Qualifier:
	//************************************
	double AsDouble();
	//************************************
	// Method:    AsString
	// FullName:  CustomDec::AsString
	// Access:    private
	// Returns:   std::string
	// Qualifier:
	//************************************
	std::string AsString();
	//************************************
	// Method:    ApplyAddition
	// FullName:  CustomDec::ApplyAddition
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyIntAddition(ValueType Value);
	CustomDec operator+(unsigned int Value) { ApplyIntAddition(Value); };
	CustomDec operator+(signed int Value) { ApplyIntAddition(Value); };
	CustomDec operator+(unsigned __int64 Value) { ApplyIntAddition(Value); }
	CustomDec operator+(signed __int64 Value) { ApplyIntAddition(Value); }
	CustomDec operator+(unsigned __int16 Value) { ApplyIntAddition(Value); }
	CustomDec operator+(signed __int16 Value) { ApplyIntAddition(Value); }
	CustomDec operator+(unsigned __int8 Value) { ApplyIntAddition(Value); }
	CustomDec operator+(signed __int8 Value) { ApplyIntAddition(Value); }
	//************************************
	// Method:    operator+
	// FullName:  CustomDec::operator+
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec operator+(double Value);
	//************************************
	// Method:    operator+
	// FullName:  CustomDec::operator+
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: std::string Value
	//************************************
	CustomDec operator+(std::string Value);
	//************************************
	// Method:    ApplySubtraction
	// FullName:  CustomDec::ApplySubtraction
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyIntSubtraction(ValueType Value);
	CustomDec operator-(unsigned int Value) { ApplyIntSubtraction(Value); };
	CustomDec operator-(signed int Value) { ApplyIntSubtraction(Value); };
	CustomDec operator-(unsigned __int64 Value) { ApplyIntSubtraction(Value); }
	CustomDec operator-(signed __int64 Value) { ApplyIntSubtraction(Value); }
	CustomDec operator-(unsigned __int16 Value) { ApplyIntSubtraction(Value); }
	CustomDec operator-(signed __int16 Value) { ApplyIntSubtraction(Value); }
	CustomDec operator-(unsigned __int8 Value) { ApplyIntSubtraction(Value); }
	CustomDec operator-(signed __int8 Value) { ApplyIntSubtraction(Value); }
	//************************************
	// Method:    ApplyEqual
	// FullName:  CustomDec::ApplyEqual
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyIntEqual(ValueType Value);
	CustomDec operator=(std::string Value);
	CustomDec operator=(unsigned int Value) { ApplyIntEqual(Value); };
	CustomDec operator=(signed int Value) { ApplyIntEqual(Value); };
	CustomDec operator=(unsigned __int64 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(signed __int64 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(unsigned __int16 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(signed __int16 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(unsigned __int8 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(signed __int8 Value) { ApplyIntEqual(Value); }
	CustomDec operator=(double Value);
	//************************************
	// Method:    ApplyModulus
	// FullName:  CustomDec::ApplyModulus
	// Access:    private
	// Returns:   void
	// Qualifier:
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	void ApplyModulus(ValueType Value);
	CustomDec operator%(unsigned int Value) { ApplyModulus(Value); };
	CustomDec operator%(signed int Value) { ApplyModulus(Value); };
	CustomDec operator%(unsigned __int64 Value) { ApplyModulus(Value); }
	CustomDec operator%(signed __int64 Value) { ApplyModulus(Value); }
	CustomDec operator%(unsigned __int16 Value) { ApplyModulus(Value); }
	CustomDec operator%(signed __int16 Value) { ApplyModulus(Value); }
	CustomDec operator%(unsigned __int8 Value) { ApplyModulus(Value); }
	CustomDec operator%(signed __int8 Value) { ApplyModulus(Value); }
	//Value to power of Value
	CustomDec operator^(unsigned int Value);
	//************************************
	// Method:    ApplyIntCompare
	// FullName:  CustomDec::ApplyIntCompare
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
	// FullName:  CustomDec::ApplyIntNotEquals
	// Access:    private
	// Returns:   bool
	// Qualifier:
	// Parameter: CustomDec c1
	// Parameter: ValueType Value
	//************************************
	template <typename ValueType>
	bool ApplyIntNotEquals(CustomDec c1, ValueType Value);
	friend bool operator== (const CustomDec &c1, unsigned int &c2) { return ApplyIntCompare(c1, c2); };
	friend bool operator!= (const CustomDec &c1, unsigned int &c2) { return ApplyIntNotEquals(c1, c2); };
	//************************************
	// Method:    operator*
	// FullName:  CustomDec::operator*
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec operator*(double Value);
	template <typename ValueType>
	void ApplyIntMultiply(ValueType Value);
	CustomDec operator*(unsigned int Value) { ApplyIntMultiply(Value); };
	CustomDec operator*(signed int Value) { ApplyIntMultiply(Value); };
	CustomDec operator*(unsigned __int64 Value) { ApplyIntMultiply(Value); }
	CustomDec operator*(signed __int64 Value) { ApplyIntMultiply(Value); }
	CustomDec operator*(unsigned __int16 Value) { ApplyIntMultiply(Value); }
	CustomDec operator*(signed __int16 Value) { ApplyIntMultiply(Value); }
	CustomDec operator*(unsigned __int8 Value) { ApplyIntMultiply(Value); }
	CustomDec operator*(signed __int8 Value) { ApplyIntMultiply(Value); }
	//************************************
	// Method:    operator/
	// FullName:  CustomDec::operator/
	// Access:    private
	// Returns:   CustomDec
	// Qualifier:
	// Parameter: double Value
	//************************************
	CustomDec operator/(double Value);
	template <typename ValueType>
	void ApplyIntDivide(ValueType Value);
	CustomDec operator/(unsigned int Value) { ApplyIntDivide(Value); };
	CustomDec operator/(signed int Value) { ApplyIntDivide(Value); };
	CustomDec operator/(unsigned __int64 Value) { ApplyIntDivide(Value); }
	CustomDec operator/(signed __int64 Value) { ApplyIntDivide(Value); }
	CustomDec operator/(unsigned __int16 Value) { ApplyIntDivide(Value); }
	CustomDec operator/(signed __int16 Value) { ApplyIntDivide(Value); }
	CustomDec operator/(unsigned __int8 Value) { ApplyIntDivide(Value); }
	CustomDec operator/(signed __int8 Value) { ApplyIntDivide(Value); }
};

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
#endif

#endif