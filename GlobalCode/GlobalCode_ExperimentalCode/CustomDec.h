/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#ifndef CustomDec_IncludeGuard
#define CustomDec_IncludeGuard

#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
#endif

#include <io.h>
#include <math.h>
#include <iostream>
#include <string>
#include <limits>

/// <summary>
/// Non-Floating Non-WholeNumber Base Class for MediumDec, SmallDec, etc 
/// <para/>DerivedSelf refers to typename derived from this base class
/// <para/>(Requires unsigned integer for IntType; signed integer for DecimalStatusType; signed type with minimum size of  IntType+DecimalStatusType for CombinedStorageType;
/// <para/>NegativeWholeNumberVal with value of (10^NumberOfDecimalStorage)*-1; DecimalOverflowVal with value 10^NumberOfDecimalStorage)
/// </summary>
template <typename DerivedSelf=CustomDec, typename IntType = unsigned int, typename DecimalStatusType = signed int, typename CombinedStorageType = long, DecimalStatusType NegativeWholeNumberVal = -1000000000, DecimalStatusType DecimalOverflowVal = 1000000000>
class DLL_API CustomDec
{
public:
    /// <summary>
    /// Stores whole half of number
    /// </summary>
	IntType IntValue = 0;
	/// <summary>
    /// Stores decimal section info and Negative/Positive Status(9 Decimal places stored for MediumDec)
    /// </summary>
	DecimalStatusType DecimalStatus;
	DerivedSelf(IntType intVal, DecimalStatusType decVal) 
	{
		IntValue = intVal;
		DecimalStatus = decVal;
	}
	DerivedSelf()
	{
		IntValue = 0;
		DecimalStatus = 0;
	}
	~DerivedSelf() {}
private:
	static DecimalStatusType const NegativeWholeNumber = NegativeWholeNumberVal;
	static DecimalStatusType const DecimalOverflow = DecimalOverflowVal;
	static DerivedSelf ZeroValue()
	{
		CustomDec NewSelf = CustomDec(0, 0);
		return NewSelf;
	}
	static DerivedSelf OneValue()
	{
		CustomDec NewSelf = CustomDec(1, 0);
		return NewSelf;
	}
	static DerivedSelf NegativeOneValue()
	{
		CustomDec NewSelf = CustomDec(1, DecimalOverflowVal);
		return NewSelf;
	}
	//Returns value of lowest non-infinite/Special Decimal State Value that can store
	static DerivedSelf MinimumValue()
	{
		//return DerivedSelf(4294967295, -999999999);
		return DerivedSelf(std::numeric_limits<IntType>::max(), NegativeWholeNumberVal+1);
	}
	/// <summary>
	/// Returns value of highest non-infinite/Special Decimal State Value that can store
	/// </summary>
	/// <returns></returns>
	static DerivedSelf MaximumValue()
	{
		//return DerivedSelf(4294967295, 999999999);
		return DerivedSelf(std::numeric_limits<IntType>::max(), DecimalOverflowVal-1);
	}
public:
	static DerivedSelf const Zero =  ZeroValue();
//
		/// <summary>
		/// Returns value of highest non-infinite/Special Decimal State Value that can store
		/// </summary>
		static readonly DerivedSelf Maximum = MaximumValue();

		/// <summary>
		/// Returns value of lowest non-infinite/Special Decimal State Value that can store
		/// </summary>
		static readonly DerivedSelf Minimum = MinimumValue();
		
		bool IsNegative()
        {
			return DecimalStatus<0;
		}
		
		void SwapNegativeStatus()
		{
			if(DecimalStatus==NegativeWholeNumberVal)
			{
				DecimalStatus = 0;
			}
			else if(DecimalStatus==0)
			{
				DecimalStatus = NegativeWholeNumberVal;
			}
			else
			{
				DecimalStatus *= -1;
			}
		}
#region OperationTemplate
	template <typename ValueType>
	void ApplyUnsignedIntAddition(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyIntAddition(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyUnsignedIntSubtraction(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyIntSubtraction(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyIntMultiplication(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyIntDivision(ValueType Value)
	{
	}
	template <typename ValueType>
	void ApplyIntModulus(ValueType Value)
	{
		if(DecimalStatus==0)
		{
			IntValue %= Value;
		}
		else
		{
		
		}
	}
#endregion OperationTemplate
#region Operations
	DerivedSelf operator+(IntType Value) 
	{
		if(DecimalStatus<0)
		{
			if(Value>IntValue)
			{
				DecimalStatus *= -1;
				Value -= IntValue;
			}
			else if(Value==IntValue)
			{
				if(DecimalStatus==NegativeWholeNumber)
				{
					DecimalStatus=0;
				}
				IntValue = 0;
			}
			else
			{
				IntValue -= Value;
			}
		}
		else
		{
			IntValue += Value;
		}
	}
	DerivedSelf operator-(IntType Value) 
	{
		if(DecimalStatus<0)
		{
			IntValue += Value;
		}
		else
		{
		
		}
	}
	//CustomDec operator+(double Value){}
	//CustomDec operator+(std::string Value);

	//CustomDec operator=(double Value){}
	//CustomDec operator=(float Value) { ApplyEqualFloatValueOperation(&Value); }
	//CustomDec operator=(std::string Value);
	//CustomDec operator=(unsigned int Value);
	//CustomDec operator=(int Value);
	//template <typename ValueType>
	//CustomDec operator%(ValueType Value) {  }

//	template <typename ValueType>
//	void ApplyIntValueDivideOperation(ValueType Value)
//	{

//	}

	//CustomDec operator*(signed int Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator*(unsigned int Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator*(signed __int8 Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator*(unsigned __int8 Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator*(signed __int64 Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator*(unsigned __int64 Value) { ApplyIntValueMultOperation(&Value); }
	//CustomDec operator%(signed int Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator%(unsigned int Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator%(signed __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator%(unsigned __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator%(signed __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator%(unsigned __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	//CustomDec operator=(signed __int64 Value);
	//CustomDec operator=(unsigned __int64 Value);
#endregion Operation
	DerivedSelf(CustomDec const& copy) = default;
	DerivedSelf& operator=(CustomDec const& copy) = default;
#region Math/Trigonomic Etc Functions
	static DerivedSelf Abs()
	{
		if(DecimalStatus<0)
		{
			DecimalStatus*=-1;
		}
		return this;
	}
	static DerivedSelf Floor()
	{
		if(DecimalStatus==NegativeWholeNumber)
		{
			return this;
		}
		if(DecimalStatus<0)
		{
			DecimalStatus = 0;
			IntValue += 1;
		}
		else
		{
			DecimalStatus = 0;
		}
		return this;
	}
	static DerivedSelf Trunc()
	{
		if(DecimalStatus!=NegativeWholeNumber)
		{
			DecimalStatus = 0;
		}
		return this;
	}
#endregion Math/Trigonomic Etc Functions
#region SpecialStatus based functions
		bool IsInfinity()
		{
			return false;
		}
#endregion SpecialStatus based functions
};

#endif