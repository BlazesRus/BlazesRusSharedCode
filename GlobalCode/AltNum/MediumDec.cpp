#include "MediumDec.h"
#include <math.h>

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "VariableConversionFunctions.h"
#else
#include "..\VariableConversionFunctions\VariableConversionFunctions.h"
#endif

/// <summary>
/// 0
/// </summary>
MediumDec MediumDec::Zero = ZeroValue();
/// <summary>
/// 1
/// </summary>
MediumDec MediumDec::One = OneValue();
/// <summary>
/// -1
/// </summary>
MediumDec MediumDec::NegativeOne = NegativeOneValue();
/// <summary>
/// Returns value of highest non-infinite/Special Decimal State Value that can store
/// </summary>
MediumDec MediumDec::Maximum = MaximumValue();
/// <summary>
/// Returns value of lowest non-infinite/Special Decimal State Value that can store
/// </summary>
MediumDec MediumDec::Minimum = MinimumValue();

//MediumDec MediumDec::Coords::PosX = MediumDec::Zero;
//MediumDec MediumDec::Coords::PosY = MediumDec::Zero;
//MediumDec MediumDec::Coords::PosZ = MediumDec::Zero;

inline std::string MediumDec::ToString()
{
	std::string Value = "";
	unsigned int IntegerHalf = IntValue;
	unsigned __int8 CurrentDigit;
	bool IsNegative = DecimalStatus < 0;
	if (IsNegative)
	{
		Value += "-";
	}
	for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
	{
		CurrentDigit = (unsigned __int8)(IntegerHalf / VariableConversionFunctions::PowerOfTens[Index]);
		IntegerHalf -= (unsigned int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
		Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
	}
	if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
	{
		Value += ".";
		bool HasDigitsUsed = false;
		int DecimalHalf = DecimalStatus;
		for (__int8 Index = 8; Index >= 0; --Index)
		{
			CurrentDigit = (unsigned __int8)(DecimalHalf / VariableConversionFunctions::PowerOfTens[Index]);
			DecimalHalf -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
			if (HasDigitsUsed == false)
			{
				if (CurrentDigit != 0)
				{
					HasDigitsUsed = true;
					Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
				}
			}
			else
			{
				Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
			}
		}
	}
	else
	{
		Value += ".0";
	}
	return Value;
}

inline std::string MediumDec::ToFullString()
{
	std::string Value = "";
	unsigned int IntegerHalf = IntValue;
	unsigned __int8 CurrentDigit;
	bool IsNegative = DecimalStatus < 0;
	if (IsNegative)
	{
		Value += "-";
	}
	for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
	{
		CurrentDigit = (unsigned __int8)(IntegerHalf / VariableConversionFunctions::PowerOfTens[Index]);
		IntegerHalf -= (unsigned int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
		Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
	}
	if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
	{
		Value += ".";
		int DecimalHalf = DecimalStatus;
		for (__int8 Index = 8; Index >= 0; --Index)
		{
			CurrentDigit = (unsigned __int8)(DecimalHalf / VariableConversionFunctions::PowerOfTens[Index]);
			DecimalHalf -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
			Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
		}
	}
	else
	{
		Value += ".000000000";
	}
	return Value;
}

inline std::string MediumDec::ToTrimmedString()
{
	std::string Value = "";
	unsigned int IntegerHalf = IntValue;
	unsigned __int8 CurrentDigit;
	bool IsNegative = DecimalStatus < 0;
	if (IsNegative)
	{
		Value += "-";
	}
	for (__int8 Index = VariableConversionFunctions::NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
	{
		CurrentDigit = (unsigned __int8)(IntegerHalf / VariableConversionFunctions::PowerOfTens[Index]);
		IntegerHalf -= (unsigned int)(CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
		Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
	}
	bool HasDigitsUsed = false;
	int DecimalHalf = DecimalStatus;
	for (__int8 Index = 8; Index >= 0; --Index)
	{
		CurrentDigit = (unsigned __int8)(DecimalHalf / VariableConversionFunctions::PowerOfTens[Index]);
		DecimalHalf -= (CurrentDigit * VariableConversionFunctions::PowerOfTens[Index]);
		if (HasDigitsUsed == false)
		{
			if (CurrentDigit != 0)
			{
				HasDigitsUsed = true;
				Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
			}
		}
		else
		{
			Value += VariableConversionFunctions::DigitAsChar(CurrentDigit);
		}
	}
	return Value;
}

/// <summary>
/// Gets the value from string.
/// </summary>
/// <param name="Value">The value.</param>
/// <returns>MediumDec.</returns>
inline MediumDec MediumDec::GetValueFromString(std::string Value)
{
	MediumDec NewSelf = MediumDec::Zero;
	bool IsNegative = false;
	int PlaceNumber;
	std::string WholeNumberBuffer = "";
	std::string DecimalBuffer = "";

	bool ReadingDecimal = false;
	int TempInt;
	int TempInt02;
	for each(char StringChar in Value)
	{
		if (VariableConversionFunctions::IsDigit(StringChar))
		{
			if (ReadingDecimal)
			{
				DecimalBuffer += StringChar;
			}
			else
			{
				WholeNumberBuffer += StringChar;
			}
		}
		else if (StringChar == '-')
		{
			IsNegative = true;
		}
		else if (StringChar == '.')
		{
			ReadingDecimal = true;
		}
	}
	PlaceNumber = WholeNumberBuffer.length() - 1;
	for each(char StringChar in WholeNumberBuffer)
	{
		TempInt = VariableConversionFunctions::CharAsInt(StringChar);
		TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
		if (StringChar != '0')
		{
			NewSelf.IntValue += (unsigned int)TempInt02;
		}
		PlaceNumber--;
	}
	PlaceNumber = 8;
	for each(char StringChar in DecimalBuffer)
	{
		//Limit stored decimal numbers to the amount it can store
		if (PlaceNumber > -1)
		{
			TempInt = VariableConversionFunctions::CharAsInt(StringChar);
			TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
			if (StringChar != '0')
			{
				NewSelf.DecimalStatus += (int)TempInt02;
			}
			PlaceNumber--;
		}
	}
	return NewSelf;
}

inline MediumDec::MediumDec(std::string Value)
{
	IntValue = 0;
	DecimalStatus = 0;
	bool IsNegative = false;
	int PlaceNumber;
	//var StringLength = (unsigned __int8)Value.Length;
	std::string WholeNumberBuffer = "";
	std::string DecimalBuffer = "";

	bool ReadingDecimal = false;
	int TempInt;
	int TempInt02;
	std::string Decimalbuilder = "";
	std::string WholeNumberbuilder = "";
	for each(char StringChar in Value)
	{
		if (VariableConversionFunctions::IsDigit(StringChar))
		{
			if (ReadingDecimal)
			{
				Decimalbuilder += StringChar;
			}
			else
			{
				WholeNumberbuilder += StringChar;
			}
		}
		else if (StringChar == '-')
		{
			IsNegative = true;
		}
		else if (StringChar == '.')
		{
			ReadingDecimal = true;
		}
	}
	WholeNumberBuffer = WholeNumberbuilder;
	DecimalBuffer = Decimalbuilder;
	PlaceNumber = WholeNumberBuffer.length() - 1;
	for each(char StringChar in WholeNumberBuffer)
	{
		TempInt = VariableConversionFunctions::CharAsInt(StringChar);
		TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
		if (StringChar != '0')
		{
			IntValue += (unsigned int)TempInt02;
		}
		PlaceNumber--;
	}
	PlaceNumber = 8;
	int StartingDigit = Decimalbuilder.length() - 1;
	for each(char StringChar in DecimalBuffer)
	{
		//Limit stored decimal numbers to the amount it can store
		if (PlaceNumber > -1)
		{
			TempInt = VariableConversionFunctions::CharAsInt(StringChar);
			TempInt02 = (TempInt * VariableConversionFunctions::PowerOfTens[PlaceNumber]);
			if (StringChar != '0')
			{
				DecimalStatus += TempInt02;
			}
			PlaceNumber--;
		}
	}
	if (IsNegative)
	{
		DecimalStatus *= -1;
	}
}


inline MediumDec::operator std::string()
{
	return ToString();
}

MediumDec operator^(MediumDec& self, MediumDec Value)
{
	if (Value.DecimalStatus == 0)
	{
		self = self ^ Value.IntValue;
	}
	else if (Value.DecimalStatus == MediumDec::NegativeWholeNumber)//Negative WholeNumber
	{
		return MediumDec::ApplyNegPow(self, ((int)Value.IntValue)*-1);
	}
	else
	{
		//Have Math.Pow deal with other pow operations for now (might lose some precision in many cases since both self&Value are converted to double to apply)
		double SelfAsDouble = (double)self;
		SelfAsDouble = std::pow(SelfAsDouble, (double)Value);
		self = (MediumDec)SelfAsDouble;
	}
	return self;
}
