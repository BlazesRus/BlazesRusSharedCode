/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#if !defined(MediumDec_IncludeGuard) && !defined(ExcludeGlobalCode_ExperimentalCode)
#define MediumDec_IncludeGuard

#ifdef BlazesGlobalCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesGlobalCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESGLOBALCODE_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#include <string>

class MediumDec;
class MediumDecDefines;

/// <summary>
/// Represent +- 4294967295.999999999 with 100% consistency of accuracy
/// </summary>
class DLL_API MediumDec
{
public:
	/// <summary>
	/// Stores whole half of number
	/// </summary>
	unsigned int IntValue = 0;
	/// <summary>
	/// Stores decimal section info and Negative/Positive Status(9 Decimal places stored for MediumDec)
	/// </summary>
	signed int DecimalStatus;
	MediumDec(unsigned int intVal, signed int decVal)
	{
		IntValue = intVal;
		DecimalStatus = decVal;
	}
	MediumDec()
	{
		IntValue = 0;
		DecimalStatus = 0;
	}
	~MediumDec() {}
private:
	static signed int const NegativeWholeNumber = -1000000000;
	static signed int const DecimalOverflow = 1000000000;

public:
#pragma region ValueDefines
	static MediumDec ZeroValue()
	{
		MediumDec NewSelf = MediumDec(0, 0);
		return NewSelf;
	}
	static MediumDec OneValue()
	{
		MediumDec NewSelf = MediumDec(1, 0);
		return NewSelf;
	}
	static MediumDec NegativeOneValue()
	{
		MediumDec NewSelf = MediumDec(1, 1000000000);
		return NewSelf;
	}
	//Returns value of lowest non-infinite/Special Decimal State Value that can store
	static MediumDec MinimumValue()
	{
		//return MediumDec(4294967295, -999999999);
		return MediumDec((std::numeric_limits<unsigned int>::max)(), -1000000000 + 1);
	}
	/// <summary>
	/// Returns value of highest non-infinite/Special Decimal State Value that can store
	/// </summary>
	/// <returns></returns>
	static MediumDec MaximumValue()
	{
		//return MediumDec(4294967295, 999999999);
		return MediumDec((std::numeric_limits<unsigned int>::max)(), 1000000000 - 1);
	}

	static MediumDec Zero;

	static MediumDec One;

	static MediumDec NegativeOne;

	/// <summary>
	/// Returns value of highest non-infinite/Special Decimal State Value that can store
	/// </summary>
	static MediumDec Maximum;

	/// <summary>
	/// Returns value of lowest non-infinite/Special Decimal State Value that can store
	/// </summary>
	static MediumDec Minimum;
#pragma endregion ValueDefines

	bool IsNegative()
	{
		return DecimalStatus < 0;
	}

	void SwapNegativeStatus()
	{
		if (DecimalStatus == -1000000000)
		{
			DecimalStatus = 0;
		}
		else if (DecimalStatus == 0)
		{
			DecimalStatus = -1000000000;
		}
		else
		{
			DecimalStatus *= -1;
		}
	}
#pragma region From Standard types to this type
	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(__int8 Value)
	{
		if (Value < 0) { this->DecimalStatus = NegativeWholeNumber; Value *= -1; }
		this->IntValue = (unsigned int)Value;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(short Value)
	{
		if (Value < 0) { this->DecimalStatus = NegativeWholeNumber; Value *= -1; }
		this->IntValue = (unsigned int)Value;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(int Value)
	{
		if (Value < 0) { this->DecimalStatus = NegativeWholeNumber; Value *= -1; }
		this->IntValue = (unsigned int)Value;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(unsigned __int8 Value)
	{
		this->IntValue = (unsigned int)Value;
		this->DecimalStatus = 0;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(unsigned short Value)
	{
		this->IntValue = Value;
		this->DecimalStatus = 0;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(unsigned int Value)
	{
		this->IntValue = Value;
		this->DecimalStatus = 0;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(unsigned __int64 Value)
	{
		//Cap value if too big on initialize
		if (Value > 4294967295)
		{
			Value = 4294967295;
		}
		this->IntValue = (unsigned int)Value;
		this->DecimalStatus = 0;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(__int64 Value)
	{
		if (Value < 0) { DecimalStatus = NegativeWholeNumber; Value *= -1; }
		//Cap value if too big on initialize
		if (Value > 4294967295)
		{
			Value = 4294967295;
		}
		this->IntValue = (unsigned int)Value;
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(double Value)
	{
		bool IsNegative = Value < 0.0;
		if (IsNegative) { Value *= -1.0; }
		//Cap value if too big on initialize (preventing overflow on conversion)
		if (Value > 4294967295.0)
		{
			IntValue = 4294967295;
			if (IsNegative)
			{
				DecimalStatus = -999999999;
			}
			else
			{
				DecimalStatus = 999999999;
			}
		}
		else
		{
			unsigned __int64 WholeValue = (unsigned __int64)std::floor(Value);
			Value -= (double)WholeValue;
			IntValue = (unsigned int)WholeValue;
			if (IsNegative)
			{
				DecimalStatus = (int)Value * -10000000000;
			}
			else
			{
				DecimalStatus = (int)Value * 10000000000;
			}
		}
	}

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(float Value)
	{
		bool IsNegative = Value < 0.0f;
		if (IsNegative) { Value *= -1.0f; }
		//Cap value if too big on initialize (preventing overflow on conversion)
		if (Value > 4294967295.0f)
		{
			IntValue = 4294967295;
			if (IsNegative)
			{
				DecimalStatus = -999999999;
			}
			else
			{
				DecimalStatus = 999999999;
			}
		}
		else
		{
			unsigned __int64 WholeValue = (unsigned __int64)std::floor(Value);
			Value -= (float)WholeValue;
			IntValue = (unsigned int)WholeValue;
			if (IsNegative)
			{
				DecimalStatus = (int)Value * -10000000000;
			}
			else
			{
				DecimalStatus = (int)Value * 10000000000;
			}
		}
	}

	///// <summary>
	/////
	///// </summary>
	///// <param name="Value"></param>
	//MediumDec(decimal Value)
	//{
	//	bool IsNegative = Value < 0;
	//	if (IsNegative) { Value *= -1.0m; }
	//	unsigned __int64 WholeValue = (unsigned __int64)Math.Floor(Value);
	//	//Cap value if too big on initialize (preventing overflow on conversion)
	//	if (Value > 4294967295)
	//	{
	//		Value = 4294967295;
	//	}
	//	Value -= WholeValue;
	//	IntValue = (unsigned int)WholeValue;
	//	DecimalStatus = (int)(Value * 10000000000);
	//	if (IsNegative)
	//	{
	//		if (DecimalStatus == 0)
	//		{
	//			DecimalStatus = NegativeWholeNumber;
	//		}
	//		else
	//		{
	//			DecimalStatus *= -1;
	//		}
	//	}
	//}

	/// <summary>
	/// Initialize constructor
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(std::string Value);

	/// <summary>
	///
	/// </summary>
	/// <param name="Value"></param>
	MediumDec(bool Value)
	{
		if (Value == true)
		{
			this->IntValue = 1;
		}
		else
		{
			this->IntValue = 0;
		}
		this->DecimalStatus = 0;
	}

#pragma endregion From Standard types to this type
#pragma region From this type to Standard types

	///// <summary>
	/////
	///// </summary>
	//explicit operator decimal()
	//{
	//	decimal Value = (decimal)IntValue;
	//	if (DecimalStatus < 0)
	//	{
	//		if (DecimalStatus == NegativeWholeNumber)
	//		{
	//			Value *= -1;
	//		}
	//		else
	//		{
	//			DecimalStatus *= -1;
	//			Value += (decimal)(DecimalStatus * 0.000000001M);
	//			Value *= -1.0M;
	//		}
	//	}
	//	else
	//	{
	//		Value += (decimal)(DecimalStatus * 0.000000001M);
	//	}
	//	return Value;
	//}

	/// <summary>
	/// MediumDec to double explicit conversion
	/// </summary>
	explicit operator double()
	{
		double Value = (double)IntValue;
		if (DecimalStatus < 0)
		{
			if (DecimalStatus == NegativeWholeNumber)
			{
				Value *= -1;
			}
			else
			{
				DecimalStatus *= -1;
				Value += (double)(DecimalStatus * 0.000000001);
				Value *= -1.0;
			}
		}
		else
		{
			Value += (double)(DecimalStatus * 0.000000001);
		}
		return Value;
	}

	/// <summary>
	/// MediumDec to float explicit conversion
	/// </summary>
	explicit operator float()
	{
		float Value = (float)IntValue;
		if (DecimalStatus < 0)
		{
			if (DecimalStatus == NegativeWholeNumber)
			{
				Value *= -1;
			}
			else
			{
				DecimalStatus *= -1;
				Value += (float)(DecimalStatus * 0.000000001f);
				Value *= -1.0f;
			}
		}
		else
		{
			Value += (float)(DecimalStatus * 0.000000001f);
		}
		return Value;
	}

	/// <summary>
	///
	/// </summary>
	explicit operator int()
	{
		int Value = (int)IntValue;
		if (DecimalStatus < 0) { Value *= -1; }
		return Value;
	}

	/// <summary>
	/// MediumDec to int64 explicit conversion
	/// </summary>
	explicit operator __int64()
	{
		__int64 Value = IntValue;
		if (DecimalStatus < 0) { Value *= -1; }
		return Value;
	}

	/// <summary>
	///
	/// </summary>
	explicit operator unsigned int()
	{
		return IntValue;
	}

	/// <summary>
	///MediumDec to unsigned int64 explicit conversion
	/// </summary>
	explicit operator unsigned __int64()
	{
		return IntValue;
	}

	/// <summary>
	/// MediumDec to byte explicit conversion
	/// </summary>
	explicit operator unsigned __int8()
	{
		unsigned __int8 Value = (unsigned __int8)IntValue;
		return Value;
	}

	/// <summary>
	/// MediumDec to signed byte explicit conversion
	/// </summary>
	/// <param name="self"></param>
	explicit operator __int8()
	{
		__int8 Value = (__int8)IntValue;
		if (DecimalStatus < 0) { Value *= -1; }
		return Value;
	}

	/// <summary>
	///MediumDec to unsigned int16 explicit conversion
	/// </summary>
	/// <param name="self"></param>
	explicit operator unsigned short()
	{
		unsigned short Value = (unsigned int)IntValue;
		return Value;
	}

	/// <summary>
	/// MediumDec to int16 explicit conversion
	/// </summary>
	/// <param name="self"></param>
	explicit operator short()
	{
		short Value = (short)IntValue;
		if (DecimalStatus < 0) { Value *= -1; }
		return Value;
	}

	///// <summary>
	/////
	///// </summary>
	///// <param name="self"></param>
	////explicit operator string() => ToOptimalString();
	explicit operator std::string();

	/// <summary>
	///
	/// </summary>
	/// <param name="self"></param>
	explicit operator bool()
	{
		return (int)*this == 1;
	}

	///// <summary>
	/////
	///// </summary>
	///// <param name="self"></param>
	//explicit operator dynamic() => MediumDec.Initialize(self);

#pragma endregion From this type to Standard types
#pragma region OperationTemplate
	template <typename ValueType>
	static MediumDec& ApplyUnsignedIntAddition(MediumDec& self, ValueType Value)
	{
		if (self.DecimalStatus < 0)
		{
			if (Value > self.IntValue)
			{
				self.DecimalStatus *= -1;
				Value -= (unsigned int)self.IntValue;
				self.IntValue = (unsigned int)Value;
			}
			else if (Value == self.IntValue)
			{
				if (self.DecimalStatus == NegativeWholeNumber)
				{
					self.DecimalStatus = 0;
				}
				self.IntValue = 0;
			}
			else
			{
				self.IntValue -= Value;
			}
		}
		else
		{
			self.IntValue += Value;
		}
		return self;
	}
	template <typename ValueType>
	MediumDec& ApplyUnsignedIntAddition(ValueType Value)
	{
		return ApplyUnsignedIntAddition(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyIntAddition(MediumDec& self, ValueType Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool ValueIsNegative = Value < 0;
		if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
		{
			self.IntValue += (unsigned int)Value;
		}
		else if (SelfIsNegative)//-X + Y
		{
			if (self.IntValue == Value)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value)
			{
				self.IntValue -= (unsigned int)Value;
			}
			else
			{
				self.IntValue = (unsigned int)Value - self.IntValue;
				SelfIsNegative = false;
			}
		}
		else// X - Y
		{
			if (self.IntValue == Value)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value)
			{
				self.IntValue -= (unsigned int)Value;
			}
			else
			{
				self.IntValue = (unsigned int)Value - self.IntValue;
				SelfIsNegative = true;
			}
		}
		if (self.DecimalStatus > 0 && SelfIsNegative)
		{
			self.DecimalStatus *= -1;
		}
		else if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		return self;
	}
	template <typename ValueType>
	MediumDec& ApplyIntAddition(ValueType Value)
	{
		return ApplyIntAddition(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyUnsignedIntSubtraction(MediumDec& self, ValueType Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
		if (SelfIsNegative)//(-X) - Y
		{
			self.IntValue += (unsigned int)Value;
		}
		else//X - Y
		{
			if (self.IntValue == Value)
			{
				self.IntValue = 0;
			}
			else if (Value > self.IntValue)
			{
				self.IntValue = (unsigned int)Value - self.IntValue;
				SelfIsNegative = true;
			}
			else
			{
				self.IntValue -= (unsigned int)Value;
			}
		}
		if (self.DecimalStatus > 0 && SelfIsNegative)
		{
			self.DecimalStatus *= -1;
		}
		else if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		return self;
	}
	template <typename ValueType>
	MediumDec& ApplyUnsignedIntSubtraction(ValueType Value)
	{
		return ApplyUnsignedIntSubtraction(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyIntSubtraction(MediumDec& self, ValueType Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool ValueIsNegative = Value < 0;
		if (SelfIsNegative)
		{
			if (ValueIsNegative == false)//(-X) - (Y)
			{
				self.IntValue += (unsigned int)Value;
			}
			else//(-X) - (-Y)
			{
				if (self.IntValue == Value)
				{
					self.IntValue = 0;
				}
				else if (Value > self.IntValue)
				{
					self.IntValue = (unsigned int)Value - self.IntValue;
					SelfIsNegative = false;
				}
				else
				{
					self.IntValue -= (unsigned int)(Value*-1);
				}
			}
		}
		else
		{
			if (ValueIsNegative)//X - (-Y)
			{
				self.IntValue += (unsigned int)(Value*-1);
			}
			else//X - (Y)
			{
				if (self.IntValue == Value)
				{
					self.IntValue = 0;
				}
				else if (Value > self.IntValue)
				{
					self.IntValue = (unsigned int)Value - self.IntValue;
					SelfIsNegative = true;
				}
				else
				{
					self.IntValue -= (unsigned int)Value;
				}
			}
		}
		if (self.DecimalStatus > 0 && SelfIsNegative)
		{
			self.DecimalStatus *= -1;
		}
		else if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		return self;
	}
	template <typename ValueType>
	MediumDec& ApplyIntSubtraction(ValueType Value)
	{
		return ApplyIntSubtraction(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyIntMultiplication(MediumDec& self, ValueType Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
#if defined(EnableMediumDecSpecialStates)
		if(self.DecimalStatus== INT64_MAX)//Positive Infinity
		{

		}
		else if (self.DecimalStatus == INT64_MIN)//Negative Infinity
		{

		}
		else if(self.DecimalStatus>MediumDec::DecimalOverflow)//Positive Fractional
		{

		}
		else if(self.DecimalStatus<MediumDec::NegativeWholeNumber)//Negative Fractional
		{

		}
#endif
		if (self.DecimalStatus == 0)
		{
			if (Value < 0)
			{
				self.IntValue *= (Value * -1);
				self.DecimalStatus = NegativeWholeNumber;
			}
			else
			{
				self.IntValue *= Value;
			}
		}
		else if (self.DecimalStatus == NegativeWholeNumber)
		{
			if (Value < 0)
			{
				self.IntValue *= (Value * -1);
				self.DecimalStatus = 0;
			}
			else
			{
				self.IntValue *= Value;
			}
		}
		else
		{
			if (SelfIsNegative)
			{
				self.DecimalStatus *= -1;
			}
			self.IntValue *= Value;
			long TempDec = (long)self.DecimalStatus;
			TempDec *= Value;
			if (TempDec >= DecimalOverflow)
			{
				long OverflowVal = TempDec / DecimalOverflow;
				TempDec -= OverflowVal * DecimalOverflow;
				self.IntValue += (unsigned int)OverflowVal;
			}
			if (TempDec == 0) { self.DecimalStatus = 0; }
			else
			{
				if (SelfIsNegative) { TempDec *= -1; }
				self.DecimalStatus = (int)TempDec;
			}
		}
		return self;
	}
	template <typename ValueType>
	MediumDec& ApplyIntMultiplication(ValueType Value)
	{
		return ApplyIntMultiplication(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyIntDivision(MediumDec& self, ValueType Value);
	template <typename ValueType>
	MediumDec& ApplyIntDivision(ValueType Value)
	{
		return ApplyIntDivision(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyIntModulus(MediumDec& self, ValueType Value);
	template <typename ValueType>
	static MediumDec& ApplyNegModulus(MediumDec& self, ValueType Value);
	template <typename ValueType>
	MediumDec& ApplyIntModulus(ValueType Value)
	{
		return ApplyIntModulus(&this, Value)
	}
	template <typename ValueType>
	static MediumDec& ApplyNegPow(MediumDec& self, ValueType NumOfTimes);
	template <typename ValueType>
	static MediumDec& ApplyIntPow(MediumDec& self, ValueType Value);
	template <typename ValueType>
	MediumDec& ApplyIntPow(ValueType Value)
	{
		return ApplyIntPow(&this, Value)
	}
	template <typename ValueType>
	static bool SelfIsEqual(MediumDec& self, ValueType Value)
	{
		return self == (MediumDec)Value;
	}
	template <typename ValueType>
	static bool SelfIsNotEqual(MediumDec& self, ValueType Value)
	{
		return self != (MediumDec)Value;
	}
	template <typename ValueType>
	static bool SelfIsLessor(MediumDec& self, ValueType Value)
	{
		return self < (MediumDec)Value;
	}
	template <typename ValueType>
	static bool SelfIsGreator(MediumDec& self, ValueType Value)
	{
		return self > (MediumDec)Value;
	}
	template <typename ValueType>
	static bool SelfIsLessorOrEqual(MediumDec& self, ValueType Value)
	{
		return self <= (MediumDec)Value;
	}
	template <typename ValueType>
	static bool SelfIsGreatorOrEqual(MediumDec& self, ValueType Value)
	{
		return self >= (MediumDec)Value;
	}
#pragma endregion OperationTemplate
#pragma region Operations
	//https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
	//Addition Operations
	friend MediumDec operator+(MediumDec& self, MediumDec& Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
		if (SelfIsNegative)
		{
			if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = Value.DecimalStatus < 0;
		if (ValueIsNegative)
		{
			if (Value.DecimalStatus == NegativeWholeNumber) { Value.DecimalStatus = 0; }
			else { Value.DecimalStatus *= -1; }
		}
		bool PerformDecimalHalf = true;
		if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
		{
			self.IntValue += Value.IntValue;
			self.DecimalStatus += Value.DecimalStatus;
			if (self.DecimalStatus >= DecimalOverflow)
			{
				self.DecimalStatus -= DecimalOverflow;
				++self.IntValue;
			}
			PerformDecimalHalf = false;
		}
		else if (SelfIsNegative)//-X + Y
		{
			if (self.IntValue == Value.IntValue)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value.IntValue)
			{
				self.IntValue -= Value.IntValue;
			}
			else
			{
				self.IntValue = (unsigned int)(Value.IntValue - self.IntValue);
				SelfIsNegative = false;
			}
		}
		else// X - Y
		{
			if (self.IntValue == Value.IntValue)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value.IntValue)
			{
				self.IntValue -= Value.IntValue;
			}
			else
			{
				self.IntValue = (unsigned int)(Value.IntValue - self.IntValue);
				SelfIsNegative = true;
			}
		}
		if (PerformDecimalHalf)
		{
			if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
			{
				self.DecimalStatus += Value.DecimalStatus;
				if (self.DecimalStatus >= DecimalOverflow)
				{
					self.DecimalStatus -= DecimalOverflow;
					++self.IntValue;
				}
			}
			else if (SelfIsNegative)
			{
				if (self.DecimalStatus == Value.DecimalStatus)
				{
					self.DecimalStatus = NegativeWholeNumber;
				}
				else if (self.DecimalStatus > Value.DecimalStatus)
				{
					self.DecimalStatus -= Value.DecimalStatus;
				}
				else
				{
					self.DecimalStatus = Value.DecimalStatus - self.DecimalStatus;
					SelfIsNegative = false;
				}
			}
			else
			{
				if (self.DecimalStatus == Value.DecimalStatus)
				{
					self.DecimalStatus = NegativeWholeNumber;
				}
				else if (self.DecimalStatus > Value.DecimalStatus)
				{
					self.DecimalStatus -= Value.DecimalStatus;
				}
				else
				{
					self.DecimalStatus = Value.DecimalStatus - self.DecimalStatus;
					SelfIsNegative = true;
				}
			}
		}
		if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		if (self.DecimalStatus > 0 && SelfIsNegative)
		{
			self.DecimalStatus *= -1;
		}
		return self;
	}
	friend MediumDec operator+(MediumDec& self, unsigned int Value) { return ApplyUnsignedIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, signed int Value) { return ApplyIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, unsigned __int8 Value) { return ApplyUnsignedIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, signed __int8 Value) { return ApplyIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, unsigned __int16 Value) { return ApplyUnsignedIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, signed __int16 Value) { return ApplyIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, unsigned __int64 Value) { return ApplyUnsignedIntAddition(self, Value); }
	friend MediumDec operator+(MediumDec& self, signed __int64 Value) { return ApplyIntAddition(self, Value); }
	friend MediumDec operator+=(MediumDec& self, MediumDec& Value)
	{
		self = self + Value;
		return self;
	}
	//friend MediumDec operator+(MediumDec& self, double Value)
	//{
	//}
	//friend MediumDec operator+(MediumDec& self, std::std::string Value)
	//{
	//}

	//Subtraction Operations
	friend MediumDec operator-(MediumDec& self, MediumDec Value)
	{
		bool SelfIsNegative = self.DecimalStatus < 0;
		if (SelfIsNegative)
		{
			if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = Value.DecimalStatus < 0;
		if (ValueIsNegative)
		{
			if (Value.DecimalStatus == NegativeWholeNumber) { Value.DecimalStatus = 0; }
			else { Value.DecimalStatus *= -1; }
		}
		if (ValueIsNegative) { ValueIsNegative = false; }
		bool PerformDecimalHalf = true;
		if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
		{
			self.IntValue += Value.IntValue;
			self.DecimalStatus += Value.DecimalStatus;
			if (self.DecimalStatus >= DecimalOverflow)
			{
				self.DecimalStatus -= DecimalOverflow;
				++self.IntValue;
			}
			PerformDecimalHalf = false;
		}
		else if (SelfIsNegative)//-X + Y
		{
			if (self.IntValue == Value.IntValue)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value.IntValue)
			{
				self.IntValue -= Value.IntValue;
			}
			else
			{
				self.IntValue = (unsigned int)(Value.IntValue - self.IntValue);
				SelfIsNegative = false;
			}
		}
		else// X - Y
		{
			if (self.IntValue == Value.IntValue)
			{
				self.IntValue = 0;
			}
			else if (self.IntValue > Value.IntValue)
			{
				self.IntValue -= Value.IntValue;
			}
			else
			{
				self.IntValue = (unsigned int)(Value.IntValue - self.IntValue);
				SelfIsNegative = true;
			}
		}
		if (PerformDecimalHalf)
		{
			if ((SelfIsNegative && ValueIsNegative) || (SelfIsNegative == false && ValueIsNegative == false))
			{
				self.DecimalStatus += Value.DecimalStatus;
				if (self.DecimalStatus >= DecimalOverflow)
				{
					self.DecimalStatus -= DecimalOverflow;
					++self.IntValue;
				}
			}
			else if (SelfIsNegative)
			{
				if (self.DecimalStatus == Value.DecimalStatus)
				{
					self.DecimalStatus = NegativeWholeNumber;
				}
				else if (self.DecimalStatus > Value.DecimalStatus)
				{
					self.DecimalStatus -= Value.DecimalStatus;
				}
				else
				{
					self.DecimalStatus = Value.DecimalStatus - self.DecimalStatus;
					SelfIsNegative = false;
				}
			}
			else
			{
				if (self.DecimalStatus == Value.DecimalStatus)
				{
					self.DecimalStatus = NegativeWholeNumber;
				}
				else if (self.DecimalStatus > Value.DecimalStatus)
				{
					self.DecimalStatus -= Value.DecimalStatus;
				}
				else
				{
					self.DecimalStatus = Value.DecimalStatus - self.DecimalStatus;
					SelfIsNegative = true;
				}
			}
		}
		if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		if (self.DecimalStatus > 0 && SelfIsNegative)
		{
			self.DecimalStatus *= -1;
		}
		return self;
	}
	friend MediumDec operator-(MediumDec& self, unsigned int Value) { return ApplyUnsignedIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, signed int Value) { return ApplyIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, unsigned __int8 Value) { return ApplyUnsignedIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, signed __int8 Value) { return ApplyIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, unsigned __int16 Value) { return ApplyUnsignedIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, signed __int16 Value) { return ApplyIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, unsigned __int64 Value) { return ApplyUnsignedIntSubtraction(self, Value); }
	friend MediumDec operator-(MediumDec& self, signed __int64 Value) { return ApplyIntSubtraction(self, Value); }
	//friend MediumDec operator-(MediumDec& self, double Value)
	//{
	//}
	//friend MediumDec operator-(MediumDec& self, std::std::string Value)
	//{
	//}

	//Multiplication Operations
	friend MediumDec operator*(MediumDec& self, unsigned int Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, signed int Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, unsigned __int8 Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, signed __int8 Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, unsigned __int16 Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, signed __int16 Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, unsigned __int64 Value) { return ApplyIntMultiplication(self, Value); }
	friend MediumDec operator*(MediumDec& self, signed __int64 Value) { return ApplyIntMultiplication(self, Value); }
	static MediumDec MultiplyOperation(MediumDec& self, MediumDec Value)
	{
		if (Value.IntValue == 0 && Value.DecimalStatus == 0)
		{
			self.IntValue = 0;
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
		bool ValueIsNegative = Value.DecimalStatus < 0;
		bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
		if (ValueIsNegative)
		{
			if (ValueIsWholeN) { Value.DecimalStatus = 0; }
			else { Value.DecimalStatus *= -1; }
		}
		if (self.DecimalStatus == 0 && Value.DecimalStatus == 0)
		{
			self.IntValue *= Value.IntValue;
		}
		else if (Value.DecimalStatus == 0)//Y is integer
		{
			ApplyIntMultiplication(self, Value.IntValue);//self *= Value.IntValue;
		}
		else if (self.DecimalStatus == 0)
		{
			ApplyIntMultiplication(Value, self.IntValue);//Value *= self.IntValue;
			self = Value;
		}
		else if (Value.IntValue == 0 && self.IntValue == 0)
		{
			__int64 Temp04 = (__int64)self.DecimalStatus * (__int64)Value.DecimalStatus;
			Temp04 /= DecimalOverflow;
			self.DecimalStatus = (signed int)Temp04;
		}
		else
		{
			//X.Y * Z.V == ((X * Z) + (X * .V) + (.Y * Z) + (.Y * .V))
			__int64 Temp02 = (__int64)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
			Temp02 *= Value.IntValue;//Temp02 holds __int64 version of X.Y * Z
			//X.Y *.V
			__int64 Temp03 = (__int64)self.IntValue * Value.DecimalStatus;//Temp03 holds __int64 version of X *.V
			__int64 Temp04 = (__int64)self.DecimalStatus * (__int64)Value.DecimalStatus;
			Temp04 /= DecimalOverflow;
			//Temp04 holds __int64 version of .Y * .V
			__int64 IntegerRep = Temp02 + Temp03 + Temp04;
			__int64 IntHalf = IntegerRep / DecimalOverflow;
			IntegerRep -= IntHalf * (__int64)DecimalOverflow;
			self.IntValue = (unsigned int)IntHalf;
			self.DecimalStatus = (signed int)IntegerRep;
		}
		if (ValueIsNegative)
		{
			SelfIsNegative = !SelfIsNegative;
		}
		if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
		return self;
	}
	friend MediumDec operator*(MediumDec& self, MediumDec Value)
	{
		return MultiplyOperation(self, Value);
	}

	//Division Operations
	friend MediumDec operator/(MediumDec& self, unsigned int Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, signed int Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, unsigned __int8 Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, signed __int8 Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, unsigned __int16 Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, signed __int16 Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, unsigned __int64 Value) { return ApplyIntDivision(self, Value); }
	friend MediumDec operator/(MediumDec& self, signed __int64 Value) { return ApplyIntDivision(self, Value); }
	static MediumDec DivisionOperation(MediumDec& self, MediumDec Value)
	{
		if (Value.IntValue == 0 && Value.DecimalStatus == 0)
		{
#if (MediumDec_PreventDivideByZeroException)
			std::cout << "Prevented dividing by zero exception by returning self instead";
			return self;
#else
			throw "Value can not be divided by zero";
#endif
		}
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
		if (SelfIsNegative)
		{
			if (SelfIsWholeN) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = Value.DecimalStatus < 0;
		bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
		if (ValueIsNegative)
		{
			if (ValueIsWholeN) { Value.DecimalStatus = 0; }
			else { Value.DecimalStatus *= -1; }
		}
		if (self.DecimalStatus == 0 && Value.DecimalStatus == 0)
		{
			__int64 SRep = self.IntValue * DecimalOverflow;
			__int64 YRep = Value.IntValue;
			SRep /= Value.IntValue;
			if (SRep >= DecimalOverflow)
			{
				__int64 OverflowVal = SRep / DecimalOverflow;
				SRep -= OverflowVal * DecimalOverflow;
				self.IntValue = (unsigned int)OverflowVal;
				self.DecimalStatus = (signed int)SRep;
			}
		}
		else if (Value.DecimalStatus == 0)//Y is integer
		{
			ApplyIntDivision(self, Value.IntValue);//self /= Value.IntValue;
		}
		else if (self.IntValue < 10 && Value.IntValue == 0)//Using self method would cause overflow of SelfRep if more in most cases
		{//self part seems to work unless Value.int is more than 0 for some reason
			__int64 SelfRep = (__int64)(self.IntValue * DecimalOverflow) + self.DecimalStatus;
			SelfRep *= DecimalOverflow;
			__int64 ValueRep = (__int64)(Value.IntValue * DecimalOverflow) + Value.DecimalStatus;
			SelfRep /= ValueRep;
			__int64 IntHalf = SelfRep / DecimalOverflow;
			SelfRep -= IntHalf * (__int64)DecimalOverflow;
			self.IntValue = (unsigned int)IntHalf;
			self.DecimalStatus = (signed int)SelfRep;
		}
		else
		{
			__int64 SelfRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			__int64 ValueRep = ((__int64)Value.IntValue * DecimalOverflow) + Value.DecimalStatus;
			SelfRep /= ValueRep;
			unsigned int IntResult = (unsigned int)SelfRep;
			SelfRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalStatus;
			__int64 Temp01 = (__int64)IntResult * ValueRep;
			SelfRep -= Temp01;
			SelfRep *= DecimalOverflow;
			SelfRep /= ValueRep;
			self.IntValue = IntResult;
			self.DecimalStatus = (signed int)SelfRep;
		}
		if (ValueIsNegative)
		{
			SelfIsNegative = !SelfIsNegative;
		}
		if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
		return self;
	}
	friend MediumDec operator/(MediumDec& self, MediumDec Value)
	{
		return DivisionOperation(self, Value);
	}
	//Modulus Operations
	friend MediumDec operator%(MediumDec& self, unsigned int Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, signed int Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, unsigned __int8 Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, signed __int8 Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, unsigned __int16 Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, signed __int16 Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, unsigned __int64 Value) { return ApplyIntModulus(self, Value); }
	friend MediumDec operator%(MediumDec& self, signed __int64 Value) { return ApplyIntModulus(self, Value); }
	static MediumDec ModulusOperation(MediumDec& self, MediumDec Value)
	{
		if (Value.IntValue == 0 && Value.DecimalStatus == 0)
		{
			return MediumDec::Zero;//Return zero instead of N/A
		}
		if (self.DecimalStatus == 0 || self.DecimalStatus == NegativeWholeNumber)
		{
			if (Value.DecimalStatus == NegativeWholeNumber)
			{
				self = ApplyNegModulus(self, Value.IntValue);
				return self;
			}
			else
			{
				self = ApplyIntModulus(self, Value.IntValue);//self %= Value.IntValue;//Fix for error C2676 occurring
				return self;
			}
		}
		bool SelfIsNegative = self.DecimalStatus < 0;
		bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
		if (SelfIsNegative)
		{
			if (SelfIsWholeN) { self.DecimalStatus = 0; }
			else { self.DecimalStatus *= -1; }
		}
		bool ValueIsNegative = Value.DecimalStatus < 0;
		bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
		if (ValueIsNegative)
		{
			if (ValueIsWholeN) { Value.DecimalStatus = 0; }
			else { Value.DecimalStatus *= -1; }
		}
		__int64 SelfRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalStatus;
		__int64 ValueRep = ((__int64)Value.IntValue * DecimalOverflow) + Value.DecimalStatus;
		SelfRep /= ValueRep;
		__int64 IntResult = SelfRep;
		SelfRep = ((__int64)self.IntValue * DecimalOverflow) + self.DecimalStatus;
		SelfRep -= IntResult * ValueRep;
		__int64 IntHalf = SelfRep / DecimalOverflow;
		SelfRep -= IntHalf * (__int64)DecimalOverflow;
		self.IntValue = (unsigned int)IntHalf;
		self.DecimalStatus = (int)SelfRep;
		if (SelfIsNegative)
		{
			self = Value - self;
			if (ValueIsNegative == false)
			{
				SelfIsNegative = false;
			}
		}
		else
		{
			if (ValueIsNegative)
			{
				self = Value - self;
			}
		}
		if (SelfIsNegative) { if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; } else { self.DecimalStatus *= -1; } }
		return self;
	}
	friend MediumDec operator%(MediumDec& self, MediumDec Value)
	{
		return ModulusOperation(self, Value);
	}
	//Power of Operations
	friend MediumDec operator^(MediumDec& self, MediumDec Value);
	friend MediumDec operator^(MediumDec& self, unsigned int Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, signed int Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, unsigned __int8 Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, signed __int8 Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, unsigned __int16 Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, signed __int16 Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, unsigned __int64 Value) { return ApplyIntPow(self, Value); }
	friend MediumDec operator^(MediumDec& self, signed __int64 Value) { return ApplyIntPow(self, Value); }

	//MediumDec operator=(double Value){}
	//MediumDec operator=(float Value) { ApplyEqualFloatValueOperation(&Value); }
	//MediumDec operator=(std::std::string Value);
	//MediumDec operator=(unsigned int Value);
	//MediumDec operator=(int Value);
	//MediumDec operator=(signed __int64 Value);
	//MediumDec operator=(unsigned __int64 Value);
	MediumDec operator ++()
	{
		return *this + 1;
	}

	MediumDec operator --()
	{
		return *this - 1;
	}

	MediumDec operator-() { SwapNegativeStatus(); return *this; }
	MediumDec operator!() { SwapNegativeStatus(); return *this; }
#pragma endregion Operation
	//MediumDec(MediumDec const& copy) = default;
	//MediumDec& operator=(MediumDec const& copy) = default;
#pragma region Math/Trigonomic Etc Functions
	MediumDec Abs()
	{
		if (DecimalStatus < 0)
		{
			DecimalStatus *= -1;
		}
		return *this;
	}
	MediumDec Floor()
	{
		if (DecimalStatus == NegativeWholeNumber)
		{
			return *this;
		}
		if (DecimalStatus < 0)
		{
			DecimalStatus = 0;
			IntValue += 1;
		}
		else
		{
			DecimalStatus = 0;
		}
		return *this;
	}
	MediumDec Ceil()
	{
		if (DecimalStatus == NegativeWholeNumber)
		{
			return *this;
		}
		if (DecimalStatus < 0)
		{
			DecimalStatus = 0;
		}
		else
		{
			DecimalStatus = 0;
			IntValue += 1;
		}
		return *this;
	}

	MediumDec Trunc()
	{
		if (DecimalStatus != NegativeWholeNumber)
		{
			DecimalStatus = 0;
		}
		return *this;
	}
#pragma endregion Math/Trigonomic Etc Functions
#pragma region SpecialStatus based functions
	bool IsInfinity()
	{
		return false;
	}
#pragma endregion SpecialStatus based functions

	std::string ToString();
	std::string ToFullString();
	std::string ToTrimmedString();

	static MediumDec GetValueFromString(std::string Value);

#pragma region Comparison Operators
	friend bool operator==(MediumDec& self, MediumDec Value)
	{
		return (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus);
	}
	friend bool operator!=(MediumDec& self, MediumDec Value)
	{
		return (self.IntValue != Value.IntValue || self.DecimalStatus != Value.DecimalStatus);
	}
	friend bool operator<=(MediumDec& self, MediumDec Value)
	{
		if (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
		else
		{
			bool SelfIsNegative = self.DecimalStatus < 0;
			bool ValueIsNegative = Value.DecimalStatus < 0;
			bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
			bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
			if (SelfIsNegative)
			{
				if (SelfIsWholeN) { self.DecimalStatus = 0; }
				else { self.DecimalStatus *= -1; }
			}
			if (ValueIsNegative)
			{
				if (ValueIsWholeN) { Value.DecimalStatus = 0; }
				else { Value.DecimalStatus *= -1; }
			}
			if (ValueIsNegative && SelfIsNegative == false) { return false; }
			else if (ValueIsNegative == false && SelfIsNegative) { return true; }
			else
			{//Both are either positive or negative
				if (SelfIsNegative)
				{//Larger number = farther down into negative
					if (self.IntValue > Value.IntValue)
					{
						return true;
					}
					else if (self.IntValue == Value.IntValue)
					{
						return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus > Value.DecimalStatus;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if (self.IntValue < Value.IntValue)
					{
						return true;
					}
					else if (self.IntValue == Value.IntValue)
					{
						return SelfIsWholeN && ValueIsWholeN ? false : self.DecimalStatus < Value.DecimalStatus;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
	friend bool operator<(MediumDec& self, MediumDec Value)
	{
		if (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
		else
		{
			bool SelfIsNegative = self.DecimalStatus < 0;
			bool ValueIsNegative = Value.DecimalStatus < 0;
			bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
			bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
			if (SelfIsNegative)
			{
				if (SelfIsWholeN) { self.DecimalStatus = 0; }
				else { self.DecimalStatus *= -1; }
			}
			if (ValueIsNegative)
			{
				if (ValueIsWholeN) { Value.DecimalStatus = 0; }
				else { Value.DecimalStatus *= -1; }
			}
			if (ValueIsNegative && SelfIsNegative == false) { return false; }
			else if (ValueIsNegative == false && SelfIsNegative) { return true; }
			else
			{//Both are either positive or negative
				if (SelfIsNegative)
				{//Larger number = farther down into negative
					if (self.IntValue > Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus > Value.DecimalStatus;
					}
				}
				else
				{
					if (self.IntValue < Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus < Value.DecimalStatus;
					}
				}
			}
		}
	}
	friend bool operator>=(MediumDec& self, MediumDec Value)
	{
		if (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return true; }
		else
		{
			bool SelfIsNegative = self.DecimalStatus < 0;
			bool ValueIsNegative = Value.DecimalStatus < 0;
			bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
			bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
			if (SelfIsNegative)
			{
				if (SelfIsWholeN) { self.DecimalStatus = 0; }
				else { self.DecimalStatus *= -1; }
			}
			if (ValueIsNegative)
			{
				if (ValueIsWholeN) { Value.DecimalStatus = 0; }
				else { Value.DecimalStatus *= -1; }
			}
			if (ValueIsNegative && SelfIsNegative == false) { return true; }
			else if (ValueIsNegative == false && SelfIsNegative) { return false; }
			else
			{//Both are either positive or negative
				if (SelfIsNegative)
				{//Larger number = farther down into negative
					if (self.IntValue < Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus < Value.DecimalStatus;
					}
				}
				else
				{
					if (self.IntValue > Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus > Value.DecimalStatus;
					}
				}
			}
		}
	}
	friend bool operator>(MediumDec& self, MediumDec Value)
	{
		if (self.IntValue == Value.IntValue && self.DecimalStatus == Value.DecimalStatus) { return false; }
		else
		{
			bool SelfIsNegative = self.DecimalStatus < 0;
			bool ValueIsNegative = Value.DecimalStatus < 0;
			bool SelfIsWholeN = self.DecimalStatus == NegativeWholeNumber;
			bool ValueIsWholeN = Value.DecimalStatus == NegativeWholeNumber;
			if (SelfIsNegative)
			{
				if (SelfIsWholeN) { self.DecimalStatus = 0; }
				else { self.DecimalStatus *= -1; }
			}
			if (ValueIsNegative)
			{
				if (ValueIsWholeN) { Value.DecimalStatus = 0; }
				else { Value.DecimalStatus *= -1; }
			}
			if (ValueIsNegative && SelfIsNegative == false) { return true; }
			else if (ValueIsNegative == false && SelfIsNegative) { return false; }
			else
			{//Both are either positive or negative
				if (SelfIsNegative)
				{//Larger number = farther down into negative
					if (self.IntValue < Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus < Value.DecimalStatus;
					}
				}
				else
				{
					if (self.IntValue > Value.IntValue)
					{
						return true;
					}
					else
					{
						return self.DecimalStatus > Value.DecimalStatus;
					}
				}
			}
		}
	}
	friend bool operator<(MediumDec& self, unsigned int Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, signed int Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, unsigned __int8 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, signed __int8 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, unsigned __int16 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, signed __int16 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, unsigned __int64 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<(MediumDec& self, signed __int64 Value) { return SelfIsLessor(self, Value); }
	friend bool operator<=(MediumDec& self, unsigned int Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, signed int Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, unsigned __int8 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, signed __int8 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, unsigned __int16 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, signed __int16 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, unsigned __int64 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator<=(MediumDec& self, signed __int64 Value) { return SelfIsLessorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, unsigned int Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, signed int Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, unsigned __int8 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, signed __int8 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, unsigned __int16 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, signed __int16 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, unsigned __int64 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>=(MediumDec& self, signed __int64 Value) { return SelfIsGreatorOrEqual(self, Value); }
	friend bool operator>(MediumDec& self, unsigned int Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, signed int Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, unsigned __int8 Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, signed __int8 Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, unsigned __int16 Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, signed __int16 Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, unsigned __int64 Value) { return SelfIsGreator(self, Value); }
	friend bool operator>(MediumDec& self, signed __int64 Value) { return SelfIsGreator(self, Value); }
	friend bool operator==(MediumDec& self, unsigned int Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, signed int Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, unsigned __int8 Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, signed __int8 Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, unsigned __int16 Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, signed __int16 Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, unsigned __int64 Value) { return SelfIsEqual(self, Value); }
	friend bool operator==(MediumDec& self, signed __int64 Value) { return SelfIsEqual(self, Value); }
	friend bool operator!=(MediumDec& self, unsigned int Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, signed int Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, unsigned __int8 Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, signed __int8 Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, unsigned __int16 Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, signed __int16 Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, unsigned __int64 Value) { return SelfIsNotEqual(self, Value); }
	friend bool operator!=(MediumDec& self, signed __int64 Value) { return SelfIsNotEqual(self, Value); }
#pragma endregion
};

MediumDec operator^(MediumDec& self, MediumDec Value);//Prototype for Pow operation

#ifdef EnableMediumDecExtras
public class MediumDecCode
{
public:
#pragma region OtherFormulas
	class Coords
	{
		MediumDec PosX;
		MediumDec PosY;
		MediumDec PosZ;
		Coords()
		{
			PosX = MediumDec::Zero;
			PosY = MediumDec::Zero;
			PosZ = MediumDec::Zero;
		}
		Coords(MediumDec posX, MediumDec posY, MediumDec posZ)
		{
			PosX = posX;
			PosY = posY;
			PosZ = posZ;
		}
	};

	class XZAngle
	{
		MediumDec AngleX;
		MediumDec AngleZ;
		XZAngle(MediumDec TempAngleX, MediumDec TempAngleZ) { AngleX = TempAngleX; AngleZ = TempAngleZ; }
		XZAngle() { AngleX = MediumDec::Zero; AngleZ = MediumDec::Zero; }
	};

	/// <summary>
	/// Gets the Euclidean distance between to positions (Based on http://en.wikipedia.org/wiki/Euclidean_distance)
	/// </summary>
	/// <param name="Origin">The origin position on 3d plane.</param>
	/// <param name="Target">The target position on 3d plane.</param>
	/// <returns></returns>
	MediumDec GetDistance(Coords Origin, Coords Target)
	{
		//Distance = Math.Sqrt((PosX2-PosX1)^2*(PosY2-PosY1)^2*(PosZ2-PosZ1)^2));
		return MediumDec.Sqrt(((Target.PosX - Origin.PosX) * (Target.PosX - Origin.PosX)) * ((Target.PosY - Origin.PosY) * (Target.PosY - Origin.PosY)) * ((Target.PosZ - Origin.PosZ) * (Target.PosZ - Origin.PosZ)));
	}

	MediumDec GetRedirectAngle(Coords self, Coords target)
	{
		return GetRedirectAngle(self, target);
	}

	XZAngle GetRedirectAngle(Coords self, Coords target, MediumDec TargetHeightOffset)
	{//X Angle 0 at North
		MediumDec East = MediumDec(90);
		MediumDec South = new MediumDec(180);
		MediumDec West = new MediumDec(270);
		XZAngle RedirectAngle = new XZAngle();
		MediumDec temp;
		MediumDec temp2;
		MediumDec DifX;
		MediumDec DifY;
		MediumDec DifZ;
		MediumDec Distance;
		MediumDec DistanceSquared;
		int PosType;
		bool OnCenter;
		MediumDec S1;
		DifX = self.PosX - target.PosX;
		DifY = self.PosY - target.PosY;
		DifZ = self.PosZ - target.PosZ + TargetHeightOffset;
		Distance = GetDistance(self, target);
		DistanceSquared = Distance * Distance;
		////-----------------------------
		if (Distance != 0.0)
		{
			OnCenter = (DifX == 0.0 && DifY == 0.0);
			if (DifZ > 0.0)//ProjRef Above Target(XAngle between 0 and 90, looks down)
			{
				PosType = 1;
			}
			else if (DifZ < 0.0)//Below Target(XAngle between -90 and 0, looks up)
			{
				PosType = 2;
			}
			else//(ZDif==0.0)
			{
				PosType = 3;
				//RedirectAngle.AngleX = MediumDec::Zero;
			}
			if (OnCenter)
			{//Target is either above,below, or exactly at actor position(Only adjust ZAngle since does not need to turn on x-y axis since on center)
				if (PosType == 1)
				{
					RedirectAngle.AngleX.IntValue = 90;
				}
				else if (PosType == 2)
				{
					RedirectAngle.AngleX = new MediumDec(-90);
				}
			}
			else
			{
				//----Z AngleRedirection
				if (DifY < MediumDec::Zero && DifX == MediumDec::Zero)//North
				{
					temp = MediumDec::Zero;
				}
				else if (DifX < MediumDec::Zero && DifY == MediumDec::Zero)//East(ProjRef is West/Left of TargetRef)
				{
					temp = East;
				}
				else if (DifY > MediumDec::Zero && DifX == MediumDec::Zero)//South
				{
					temp = South;
				}
				else if (DifX > MediumDec::Zero && DifY == MediumDec::Zero)//West(ProjRef is East/Right of TargetRef)
				{
					temp = West;
				}
				else
				{
					temp = MediumDec.Abs(DifY);
					temp2 = MediumDec.Abs(DifX);
					temp = temp / temp2;
					temp = MediumDec.ATan(temp);
					if (DifY < MediumDec::Zero)//North
					{
						if (DifX < MediumDec::Zero)//East
						{
							temp = East - temp;
						}
						else if (DifX > MediumDec::Zero)//West
						{
							temp = West + temp;
						}
					}
					else if (DifY > MediumDec::Zero)//South
					{
						if (DifX < 0.0)//East
						{
							temp = East + temp;
						}
						else if (DifX > MediumDec::Zero)//West
						{
							temp = West - temp;
						}
					}
				}
				RedirectAngle.AngleZ = temp;
				if (PosType != 3)
				{
					//----Z AngleRedirection
					//Side1=((TargetRef.GetPos x), (TargetRef.GetPos y), (ProjRef.GetPos z))
					temp2 = ((DifX * DifX) + (DifY * DifY));
					S1 = MediumDec.Sqrt(temp2);
					if (S1 != MediumDec::Zero)//Avoid Divide by Zero Error
					{
						temp = (DifZ * DifZ);//Side 3=DifZ, Side2=Distance
											 //Law of Cosines=acos ((S1^2+S2^2-S3^2)/(2*S1*S2));Side3=SideOppositeAngle
						temp = (temp2 + DistanceSquared + (temp * -1)) / (2 * S1 * Distance);
						temp = MediumDec.ACos(temp);
						//temp2 = XAngle;
						if (temp < 0.0 && PosType == 1)//Angle Correction Code(temp is angle)--flips angle if angle set on wrong side
						{
							temp *= -1;
						}
						else
						{
							temp *= -1;
						}
						RedirectAngle.AngleX = temp;
					}
				}
			}
		}
		return RedirectAngle;
	}
#pragma endregion
};
#endif
#endif

template<typename ValueType>
inline MediumDec& MediumDec::ApplyIntDivision(MediumDec& self, ValueType Value)
{
#if defined(EnableMediumDecSpecialStates)
	if (self.DecimalStatus == INT64_MAX)//Positive Infinity
	{

	}
	else if (self.DecimalStatus == INT64_MIN)//Negative Infinity
	{

	}
	else if (self.DecimalStatus > MediumDec::DecimalOverflow)//Positive Fractional
	{

	}
	else if (self.DecimalStatus < MediumDec::NegativeWholeNumber)//Negative Fractional
	{

	}
#endif
	bool SelfIsNegative = self.DecimalStatus < 0;
	if (Value < 0)
	{
		if (SelfIsNegative) { SelfIsNegative = false; }
		else { SelfIsNegative = true; }
		if (self.DecimalStatus == NegativeWholeNumber) { self.DecimalStatus = 0; }
		else if (self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
		Value *= -1;
	}
	if (self.DecimalStatus == 0 || self.DecimalStatus == NegativeWholeNumber)//Only need to deal with Integer half of value
	{
		long ValueRep = (__int64)self.IntValue * DecimalOverflow;
		ValueRep /= Value;
		long WholeHalf = ValueRep / DecimalOverflow;
		self.IntValue = (unsigned int)WholeHalf;
		ValueRep -= WholeHalf;
		self.DecimalStatus = (int)WholeHalf;
	}
	else
	{
		DivisionOperation(self, (MediumDec)Value);//return self /= (MediumDec)Value;
	}
	if (SelfIsNegative && self.DecimalStatus == 0) { self.DecimalStatus = NegativeWholeNumber; }
	return self;
}

template<typename ValueType>
inline MediumDec& MediumDec::ApplyIntModulus(MediumDec& self, ValueType Value)
{//https://www.quora.com/How-does-the-modulo-operation-work-with-negative-numbers-and-why
	if (self.DecimalStatus == 0)
	{
		self.IntValue %= Value;
		if (Value<0)
		{
			self.DecimalStatus = NegativeWholeNumber;
			self.IntValue = (unsigned int)(Value - (ValueType)self.IntValue);
		}
	}
	else if (self.DecimalStatus == NegativeWholeNumber)
	{
		self.IntValue %= Value;
		self.IntValue = (unsigned int)(Value - (ValueType)self.IntValue);
		if (Value > 0)//https://www.medcalc.org/manual/mod_function.php
		{
			self.DecimalStatus = 0;
		}
	}
	else
	{
		ModulusOperation(self, (MediumDec)Value);//self %= (MediumDec)Value;
	}
	return self;
}

template<typename ValueType>
inline MediumDec & MediumDec::ApplyNegModulus(MediumDec & self, ValueType Value)
{
	if (self.DecimalStatus == 0)
	{
		self.IntValue %= Value;
		self.DecimalStatus = NegativeWholeNumber;
		self.IntValue = (unsigned int)(Value - (ValueType)self.IntValue);
	}
	else if (self.DecimalStatus == NegativeWholeNumber)
	{
		self.IntValue %= Value;
		self.IntValue = (unsigned int)(Value - (ValueType)self.IntValue);
	}
	else
	{
		ModulusOperation(self, (MediumDec)Value);//self %= (MediumDec)Value;
	}
	return self;
}

template<typename ValueType>
inline MediumDec & MediumDec::ApplyNegPow(MediumDec & self, ValueType NumOfTimes)
{
	MediumDec ValueMult = self;
	self = One;
	for (ValueType Num = 0; Num < NumOfTimes; Num++)
	{
		DivisionOperation(self, ValueMult);//self /= ValueMult;
	}
	return self;
}

template<typename ValueType>
inline MediumDec& MediumDec::ApplyIntPow(MediumDec & self, ValueType Value)
{
	if (self.DecimalStatus == 0 && self.IntValue == 10)
	{
		if (Value == 0)
		{
			self.IntValue = 1;
		}
		if (Value > 0)
		{
			self.IntValue = VariableConversionFunctions::PowerOfTens[Value];
		}
		else if (Value >= -9)
		{
			self.IntValue = 0;
			self.DecimalStatus = DecimalOverflow / VariableConversionFunctions::PowerOfTens[Value*-1];
		}
		else
		{
			self.IntValue = 0;
		}
	}
	else
	{
		if (Value>0)
		{
			ValueType NumOfTimes = Value - 1;
			MediumDec ValueMult = self;
			for (ValueType Num = 0; Num<NumOfTimes; Num++)
			{
				MultiplyOperation(self, ValueMult);//self *= ValueMult;
			}
		}
		else
		{
			if (Value == 0)
			{
				self = One;
			}
			else
			{
				ValueType NumOfTimes = Value * -1;
				return ApplyNegPow(self, NumOfTimes);
			}
		}
	}
	return self;
}

