#include "MediumDec.h"
#include <math.h>

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "VariableConversionFunctions.h"
#else
#include "..\GlobalCode_VariableConversionFunctions\VariableConversionFunctions.h"
#endif

MediumDec MediumDec::Zero = ZeroValue();
MediumDec MediumDec::One = OneValue();
MediumDec MediumDec::NegativeOne = NegativeOneValue();
MediumDec MediumDec::Maximum = MaximumValue();
MediumDec MediumDec::Minimum = MinimumValue();

//MediumDec MediumDec::Coords::PosX = MediumDec::Zero;
//MediumDec MediumDec::Coords::PosY = MediumDec::Zero;
//MediumDec MediumDec::Coords::PosZ = MediumDec::Zero;

/// <summary>
///
/// </summary>
/// <param name="Value"></param>

/// <summary>
///
/// </summary>
/// <param name="Value"></param>


/*	static MediumDec GetValueFromString(std::string Value)
{
MediumDec NewSelf = MediumDec::Zero;
bool IsNegative = false;
__int8 PlaceNumber;
//var StringLength = (unsigned __int8)Value.Length;
std::string WholeNumberBuffer = "";
std::string DecimalBuffer = "";

bool ReadingDecimal = false;
int TempInt;
int TempInt02;
var Decimalbuilder = new System.Text.StringBuilder("");
var WholeNumberbuilder = new System.Text.StringBuilder("");
foreach(char StringChar in Value)
{
if (IsDigit(StringChar))
{
if (ReadingDecimal)
{
Decimalbuilder.Append(StringChar);
}
else
{
WholeNumberbuilder.Append(StringChar);
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
WholeNumberBuffer = WholeNumberbuilder.ToString();
DecimalBuffer = Decimalbuilder.ToString();
PlaceNumber = (__int8)(WholeNumberBuffer.Length - 1);
foreach(char StringChar in WholeNumberBuffer)
{
TempInt = CharAsInt(StringChar);
TempInt02 = (TempInt * SuperDecGlobalCode.PowerOfTens[PlaceNumber]);
if (StringChar != '0')
{
NewSelf.IntValue += (unsigned int)TempInt02;
}
PlaceNumber--;
}
PlaceNumber = 8;
foreach(char StringChar in DecimalBuffer)
{
//Limit stored decimal numbers to the amount it can store
if (PlaceNumber > -1)
{
TempInt = CharAsInt(StringChar);
TempInt02 = (TempInt * SuperDecGlobalCode.PowerOfTens[PlaceNumber]);
if (StringChar != '0')
{
NewSelf.DecimalStatus += (int)TempInt02;
}
PlaceNumber--;
}
}
return NewSelf;
}

/// <summary>
/// Display std::std::string with empty decimal places removed
/// </summary>
/// <returns></returns>
std::string ToOptimalString()
{
//std::string Value = "";
var builder = new System.Text.StringBuilder("");
unsigned int IntegerHalf = IntValue;
unsigned __int8 CurrentDigit;
bool IsNegative = DecimalStatus < 0;
if (IsNegative)
{
builder.Append("-");
}

for (__int8 Index = NumberOfPlaces(IntegerHalf); Index >= 0; --Index)
{
CurrentDigit = (unsigned __int8)(IntegerHalf / Math.Pow(10, Index));
IntegerHalf -= (unsigned int)(CurrentDigit * Math.Pow(10, Index));
//Value += DigitAsChar(CurrentDigit);
builder.Append(DigitAsChar(CurrentDigit));
}
if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
{
unsigned int DecimalHalf = (unsigned int)DecimalStatus;
//Value += ".";
builder.Append(".");
for (__int8 Index = 8; Index >= 0; --Index)
{
if (DecimalStatus != 0)
{
CurrentDigit = (unsigned __int8)(DecimalHalf / Math.Pow(10, Index));
DecimalHalf -= (unsigned int)(CurrentDigit * Math.Pow(10, Index));
//Value += DigitAsChar(CurrentDigit);
builder.Append(DigitAsChar(CurrentDigit));
}
}
}
//return Value;
return builder.ToString();
}

/// <summary>
/// Display std::std::string with empty decimal places show
/// </summary>
/// <returns></returns>
std::string ToFullString()
{
std::string Value = "";
unsigned int IntegerHalf = IntValue;
unsigned __int8 CurrentDigit;
bool IsNegative = DecimalStatus < 0;
if (IsNegative)
{
Value += "-";
}
for (__int8 Index = NumberOfPlaces(IntegerHalf); Index >= 0; Index--)
{
CurrentDigit = (unsigned __int8)(IntegerHalf / SuperDecGlobalCode.PowerOfTens[Index]);
IntegerHalf -= (unsigned int)(CurrentDigit * SuperDecGlobalCode.PowerOfTens[Index]);
Value += DigitAsChar(CurrentDigit);
}
if (DecimalStatus != 0 && DecimalStatus != NegativeWholeNumber)
{
Value += ".";
int DecimalHalf =
DecimalStatus;
for (__int8 Index = 8; Index >= 0; --Index)
{
CurrentDigit = (unsigned __int8)(DecimalHalf / SuperDecGlobalCode.PowerOfTens[Index]);
DecimalHalf -= (CurrentDigit * SuperDecGlobalCode.PowerOfTens[Index]);
Value += DigitAsChar(CurrentDigit);
}
}
else
{
Value += ".000000000";
}
return Value;
}

/// <summary>
///
/// </summary>
/// <param name="provider"></param>
/// <returns></returns>
std::string ToString(IFormatProvider provider)
{
return String.Format(provider, this->ToOptimalString());
}

/// <summary>
/// Change variable to std::string with certain formating style
/// </summary>
/// <param name="FormatStyle"></param>
/// <returns></returns>
std::string ToString(std::string FormatStyle)
{
return ToOptimalString();
}



///// <summary>
///// Change variable into std::std::string with certain formating style with culture info set
///// </summary>
///// <param name="FormatStyle"></param>
///// <param name="culture"></param>
///// <returns></returns>
//std::string ToString(std::string FormatStyle, CultureInfo culture)
//{
//    return String.Format(culture, this->ToOptimalString());//Ensure to reformat std::std::string based on culture
//}

/// <summary>
///
/// </summary>
/// <param name="culture"></param>
/// <returns></returns>
std::string ToString(CultureInfo culture)
{
return String.Format(culture, this->ToOptimalString());//Ensure to reformat std::std::string based on culture
}

/// <summary>
///
/// </summary>
/// <param name="numberFormat"></param>
/// <returns></returns>
std::string ToString(NumberFormatInfo numberFormat)
{
return String.Format(numberFormat, this->ToOptimalString());//Ensure to reformat std::std::string based on format type
}*/

inline MediumDec::MediumDec(double Value)
{
	bool IsNegative = Value < 0;
	if (IsNegative) { Value *= -1.0; }
	unsigned __int64 WholeValue = (unsigned __int64)std::floor(Value);
	//Cap value if too big on initialize (preventing overflow on conversion)
	if (Value > 4294967295)
	{
		Value = 4294967295;
	}
	Value -= WholeValue;
	IntValue = (unsigned int)WholeValue;
	DecimalStatus = (int)(Value * 10000000000);
}

inline MediumDec::MediumDec(float Value)
{
	bool IsNegative = Value < 0;
	if (IsNegative) { Value *= -1.0f; }
	unsigned __int64 WholeValue = (unsigned __int64)std::floor(Value);
	//Cap value if too big on initialize (preventing overflow on conversion)
	if (Value > 4294967295)
	{
		Value = 4294967295;
	}
	Value -= WholeValue;
	IntValue = (unsigned int)WholeValue;
	DecimalStatus = (int)(Value * 10000000000);
}

/// <summary>
/// Initialize constructor
/// </summary>
/// <param name="Value"></param>

/// <summary>
///	Convert to String with Trimmed Digits or ending of .0 if no decimal places stored
/// </summary>
/// <returns></returns>
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

/// <summary>
///	Convert to String with only Decimal places with stored numbers displayed
/// </summary>
/// <returns></returns>
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

inline MediumDec MediumDec::GetValueFromString(std::string Value)
{
	MediumDec NewSelf = MediumDec::Zero;
	bool IsNegative = false;
	__int8 PlaceNumber;
	//var StringLength = (unsigned __int8)Value.Length;
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
	PlaceNumber = (__int8)(WholeNumberBuffer.length - 1);
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
	__int8 PlaceNumber;
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
	PlaceNumber = (__int8)(WholeNumberBuffer.length - 1);
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
	int StartingDigit = (Decimalbuilder.length - 1);
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