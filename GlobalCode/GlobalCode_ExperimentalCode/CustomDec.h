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
template <typename DerivedSelf, typename IntType = unsigned int, typename DecimalStatusType = signed int, typename CombinedStorageType = long, DecimalStatusType NegativeWholeNumberVal = -1000000000, DecimalStatusType DecimalOverflowVal = 1000000000>
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
#pragma region OperationTemplate
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
#pragma endregion OperationTemplate
#pragma region Operations
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
	DerivedSelf operator ++()
	{
		this += 1;
		return this;
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
	DerivedSelf operator --()
	{
		this -= 1;
		return this;
	}
	//DerivedSelf operator+(double Value){}
	//DerivedSelf operator+(std::string Value);

	//DerivedSelf operator=(double Value){}
	//DerivedSelf operator=(float Value) { ApplyEqualFloatValueOperation(&Value); }
	//DerivedSelf operator=(std::string Value);
	//DerivedSelf operator=(unsigned int Value);
	//DerivedSelf operator=(int Value);
	//template <typename ValueType>
	//DerivedSelf operator%(ValueType Value) {  }


	//DerivedSelf operator*(signed int Value) { ApplyIntValueMultOperation(&Value); }
	//DerivedSelf operator*(unsigned int Value) { ApplyIntValueMultOperation(&Value); }
	//DerivedSelf operator*(signed __int8 Value) { ApplyIntValueMultOperation(&Value); }
	//DerivedSelf operator*(unsigned __int8 Value) { ApplyIntValueMultOperation(&Value); }
	//DerivedSelf operator*(signed __int64 Value) { ApplyIntValueMultOperation(&Value); }
	//DerivedSelf operator*(unsigned __int64 Value) { ApplyIntValueMultOperation(&Value); }
	DerivedSelf operator*(DerivedSelf& self, DerivedSelf Value)
	{
		if (y.intValue == 0 && y.DecimalStatus == 0)
		{
			self.intValue = 0;
			self.DecimalStatus = 0;
			return self;
		}
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
		if (SelfIsNegative)
		{
			if (SelfIsWholeN) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = y.DecimalStatus < 0;
		bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
		if (ValueIsNegative)
		{
			if (ValueIsWholeN) { y.DecimalStatus = 0; }
			else { y.DecimalStatus *= -1; }
		}
		if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
		{
			self.IntValue *= y.IntValue;
		}
		else if (y.DecimalStatus == 0)//Y is integer
		{
			self *= y.IntValue;
		}
		else if (self.DecimalStatus == 0)
		{
			y *= self.IntValue;
			self = y;
		}
		else if (y.IntValue == 0 && self.IntValue == 0)
		{
			CombinedStorageType Temp04 = (CombinedStorageType)self.DecimalStatus * (CombinedStorageType)y.DecimalStatus;
			Temp04 /= DecimalOverflow;
			self.DecimalStatus = (DecimalStatusType)Temp04;
		}
		else
		{
			//X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
			CombinedStorageType Temp02 = (CombinedStorageType)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
			Temp02 *= y.IntValue;//Temp02 holds CombinedStorageType version of X.Y * Z
			//X.Y *.V
			CombinedStorageType Temp03 = (CombinedStorageType)self.IntValue * y.DecimalStatus;//Temp03 holds CombinedStorageType version of X *.V
			CombinedStorageType Temp04 = (CombinedStorageType)self.DecimalStatus * (CombinedStorageType)y.DecimalStatus;
			Temp04 /= DecimalOverflow;
			//Temp04 holds CombinedStorageType version of .Y * .V
			CombinedStorageType IntegerRep = Temp02 + Temp03 + Temp04;
			CombinedStorageType IntHalf = IntegerRep / DecimalOverflow;
			IntegerRep -= IntHalf * (CombinedStorageType)DecimalOverflow;
			self.IntValue = (IntType)IntHalf;
			self.DecimalStatus = (DecimalStatusType)IntegerRep;
		}
		if (ValueIsNegative)
		{
			SelfIsNegative = !SelfIsNegative;
		}
		if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
		return self;
	}
	//DerivedSelf operator/(signed int Value) { ApplyIntValueDivideOperation(&Value); }
	//DerivedSelf operator/(unsigned int Value) { ApplyIntValueDivideOperation(&Value); }
	//DerivedSelf operator/(signed __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	//DerivedSelf operator/(unsigned __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	//DerivedSelf operator/(signed __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	//DerivedSelf operator/(unsigned __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	DerivedSelf operator/(DerivedSelf& self, DerivedSelf Value)
	{
		if (y.intValue == 0 && y.DecimalStatus == 0)
		{
#if (DerivedSelf_PreventDivideByZeroException)
			Console.WriteLine("Prevented dividing by zero");
			return self;
#else
			throw new DivideByZeroException("Value can not be divided by zero");
#endif
		}
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
		if (SelfIsNegative)
		{
			if (SelfIsWholeN) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = y.DecimalStatus < 0;
		bool ValueIsWholeN = y.DecimalStatus == NegativeWholeNumber;
		if (ValueIsNegative)
		{
			if (ValueIsWholeN) { y.DecimalStatus = 0; }
			else { y.DecimalStatus *= -1; }
		}
		if (self.DecimalStatus == 0 && y.DecimalStatus == 0)
		{
			CombinedStorageType SRep = self.IntValue * DecimalOverflow;
			CombinedStorageType YRep = y.IntValue;
			SRep /= y.IntValue;
			if (SRep >= DecimalOverflow)
			{
				CombinedStorageType OverflowVal = SRep / DecimalOverflow;
				SRep -= OverflowVal * DecimalOverflow;
				self.IntValue = (IntType)OverflowVal;
				self.DecimalStatus = (DecimalStatusType)SRep;
			}
		}
		else if (y.DecimalStatus == 0)//Y is integer
		{
			self /= y.IntValue;
		}
		else if (self.IntValue < 10 && y.IntValue == 0)//Using self method would cause overflow of SelfRep if more in most cases
		{//self part seems to work unless y.int is more than 0 for some reason
			CombinedStorageType SelfRep = (CombinedStorageType)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
			SelfRep *= DecimalOverflow;
			CombinedStorageType ValueRep = (CombinedStorageType)(y.IntValue * DecimalOverflow) + y.DecimalStatus;
			SelfRep /= ValueRep;
			CombinedStorageType IntHalf = SelfRep / DecimalOverflow;
			SelfRep -= IntHalf * (CombinedStorageType)DecimalOverflow;
			self.IntValue = (IntType)IntHalf;
			self.DecimalStatus = (DecimalStatusType)SelfRep;
		}
		else
		{
			CombinedStorageType SelfRep = ((CombinedStorageType)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			CombinedStorageType ValueRep = ((CombinedStorageType)y.IntValue * DecimalOverflow) + y.DecimalStatus;
			SelfRep /= ValueRep;
			IntType IntResult = (IntType)SelfRep;
			SelfRep = ((CombinedStorageType)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			CombinedStorageType Temp01 = (CombinedStorageType)IntResult * ValueRep;
			SelfRep -= Temp01;
			SelfRep *= DecimalOverflow;
			SelfRep /= ValueRep;
			self.IntValue = IntResult;
			self.DecimalStatus = (DecimalStatusType)SelfRep;
		}
		if (ValueIsNegative)
		{
			SelfIsNegative = !SelfIsNegative;
		}
		if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
		return self;
	}
	//DerivedSelf operator=(signed __int64 Value);
	//DerivedSelf operator=(unsigned __int64 Value);
	DerivedSelf operator-() { SwapNegativeStatus(); return this; }
	DerivedSelf operator!() { SwapNegativeStatus(); return this; }
#pragma endregion Operation
	//DerivedSelf(DerivedSelf const& copy) = default;
	//DerivedSelf& operator=(DerivedSelf const& copy) = default;
#pragma region Math/Trigonomic Etc Functions
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
#pragma endregion Math/Trigonomic Etc Functions
#pragma region SpecialStatus based functions
		bool IsInfinity()
		{
			return false;
		}
#pragma endregion SpecialStatus based functions
};

#endif