/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
	*/
#pragma once
#ifndef SuperDec_IncludeGuard
#define SuperDec_IncludeGuard

#include <io.h>
#include <math.h>
#include <iostream>
#include "..\DLLAPI.h"
#include <string>

//Preprocessor for enabling Fractional Storage & such with left over unused bits (once I create the code for it);Use SuperDecHex to help find left over bits
////#define SuperDec_EnableFractionalStorage

namespace SuperDecHex
{
	//************************************
	// Method:    IntToHexChar
	// FullName:  SuperDecHex::IntToHexChar
	// Access:    public static 
	// Returns:   char DLL_API
	// Qualifier:
	// Parameter: ValueType num
	//************************************
	template <typename ValueType>
	static char DLL_API IntToHexChar(ValueType num)
	{
		switch(num)
		{
			case 1:
				return '1';
			case 2:
				return '2';
			case 3:
				return '3';
			case 4:
				return '4';
			case 5:
				return '5';
			case 6:
				return '6';
			case 7:
				return '7';
			case 8:
				return '8';
			case 9:
				return '9';
			case 10:
				return 'A';
			case 11:
				return 'B';
			case 12:
				return 'C';
			case 13:
				return 'D';
			case 14:
				return 'E';
			case 15:
				return 'F';
			default:
				return '0';
		}
	}
	//************************************
	// Method:    HexCharToInt
	// FullName:  SuperDecHex::HexCharToInt
	// Access:    public static 
	// Returns:   unsigned __int8
	// Qualifier:
	// Parameter: int num
	//************************************
	static unsigned __int8 HexCharToInt(int num);
	//Takes any type of unsigned Int value and converts to hex Equavalent
	//Based on http://www.geeksforgeeks.org/implement-itoa/
	//************************************
	// Method:    IntToHexString
	// FullName:  SuperDecHex::IntToHexString
	// Access:    public static 
	// Returns:   std::string DLL_API
	// Qualifier:
	// Parameter: ValueType num
	// Parameter: bool ReversedHex
	//************************************
	template <typename ValueType>
	static std::string DLL_API IntToHexString(ValueType num, bool ReversedHex=false)
	{
		if(num==0)
		{
			return "";
		}
		if(num<0)
		{
			std::cout<<"Negative values not supported by this version of the method.\n";
			return "";
		}
		ValueType rem;
		std::string str="";
		//Process individual digits
		while(num!=0)
		{
			rem =num%16;
			str += IntToChar(rem);
			num = num/16;
		}
		if(ReversedHex)
		{
			std::string TempString="";
			for(unsigned __int8 Index=str.length();Index>=0;++Index)
			{
				TempString += str.at(Index);
			}
			return TempString;
		}
		else
		{
			return str;
		}
	}
	//Holds 16 HalfByte int values of between 0-15 (0-F as char) (Represents 8 Byte as Hex)
	//HalfByte refers to 0-15 value (Half of Hex chars of a byte);Example Hex String "FFFFFFFFFFFFFFFF"
	//Main use here is for splitting remaining digits of value for using for other purposes
	struct DLL_API Hex_8Byte
	{
		unsigned __int8 Byte1_a = 0;
		unsigned __int8 Byte1_b = 0;
		unsigned __int8 Byte2_a = 0;
		unsigned __int8 Byte2_b = 0;
		unsigned __int8 Byte3_a = 0;
		unsigned __int8 Byte3_b = 0;
		unsigned __int8 Byte4_a = 0;
		unsigned __int8 Byte4_b = 0;
		unsigned __int8 Byte5_a = 0;
		unsigned __int8 Byte5_b = 0;
		unsigned __int8 Byte6_a = 0;
		unsigned __int8 Byte6_b = 0;
		unsigned __int8 Byte7_a = 0;
		unsigned __int8 Byte7_b = 0;
		unsigned __int8 Byte8_a = 0;
		unsigned __int8 Byte8_b = 0;
		//************************************
		// Assign values based 8 Byte Hex String (16 HalfBytes)
		// Method:    operator=
		// FullName:  SuperDecHex::Hex_8Byte::operator=
		// Access:    public
		// Returns:   SuperDecHex::Hex_8Byte
		// Qualifier:
		// Parameter: std::string HexValue
		//************************************
		Hex_8Byte operator=(std::string HexValue);
		template <typename ValueType>
		void IntTo8ByteHex(ValueType Value)
		{
			std::string HexValue = IntToHexString(Value,true);
			unsigned int HexSize = HexValue.length();
			unsigned __int8 Index;
			for(Index=0;Index<HexSize;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = IntToHexChar(HexValue.at(Index));break;
					case 1:
						Byte1_b = IntToHexChar(HexValue.at(Index));break;
					case 2:
						Byte2_a = IntToHexChar(HexValue.at(Index));break;
					case 3:
						Byte2_b = IntToHexChar(HexValue.at(Index));break;
					case 4:
						Byte3_a = IntToHexChar(HexValue.at(Index));break;
					case 5:
						Byte3_b = IntToHexChar(HexValue.at(Index));break;
					case 6:
						Byte4_a = IntToHexChar(HexValue.at(Index));break;
					case 7:
						Byte4_b = IntToHexChar(HexValue.at(Index));break;
					case 8:
						Byte5_a = IntToHexChar(HexValue.at(Index));break;
					case 9:
						Byte5_b = IntToHexChar(HexValue.at(Index));break;
					case 10:
						Byte6_a = IntToHexChar(HexValue.at(Index));break;
					case 11:
						Byte6_b = IntToHexChar(HexValue.at(Index));break;
					case 12:
						Byte7_a = IntToHexChar(HexValue.at(Index));break;
					case 13:
						Byte7_b = IntToHexChar(HexValue.at(Index));break;
					case 14:
						Byte8_a = IntToHexChar(HexValue.at(Index));break;
					case 15:
						Byte8_b = IntToHexChar(HexValue.at(Index));break;
				}
			}
			//Set rest of HalfBytes to value of zero
			for(++Index;Index<16;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = 0;break;
					case 1:
						Byte1_b = 0;break;
					case 2:
						Byte2_a = 0;break;
					case 3:
						Byte2_b = 0;break;
					case 4:
						Byte3_a = 0;break;
					case 5:
						Byte3_b =0;break;
					case 6:
						Byte4_a = 0;break;
					case 7:
						Byte4_b = 0;break;
					case 8:
						Byte5_a = 0;break;
					case 9:
						Byte5_b = 0;break;
					case 10:
						Byte6_a = 0;break;
					case 11:
						Byte6_b = 0;break;
					case 12:
						Byte7_a = 0;break;
					case 13:
						Byte7_b = 0;break;
					case 14:
						Byte8_a = 0;break;
					case 15:
						Byte8_b = 0;break;
				}
			}
		}
		Hex_8Byte operator=(signed __int8 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(signed __int16 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(signed __int32 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(signed __int64 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(unsigned __int8 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(unsigned __int16 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(unsigned __int32 Value){IntTo8ByteHex(Value);}
		Hex_8Byte operator=(unsigned __int64 Value){IntTo8ByteHex(Value);}
		//************************************
		// Method:    GetAsInt64
		// FullName:  SuperDecHex::Hex_8Byte::GetAsInt64
		// Access:    public 
		// Returns:   unsigned __int64
		// Qualifier:
		//************************************
		unsigned __int64 GetAsInt64();
	};
	struct DLL_API Hex_4Byte
	{
		unsigned __int8 Byte1_a = 0;
		unsigned __int8 Byte1_b = 0;
		unsigned __int8 Byte2_a = 0;
		unsigned __int8 Byte2_b = 0;
		unsigned __int8 Byte3_a = 0;
		unsigned __int8 Byte3_b = 0;
		unsigned __int8 Byte4_a = 0;
		unsigned __int8 Byte4_b = 0;
		//************************************
		// Assign values based 4 Byte Hex String (8 HalfBytes)
		// Method:    operator=
		// FullName:  SuperDecHex::Hex_8Byte::operator=
		// Access:    public
		// Returns:   SuperDecHex::Hex_8Byte
		// Qualifier:
		// Parameter: std::string HexValue
		//************************************
		Hex_4Byte operator=(std::string HexValue);
		template <typename ValueType>
		void IntTo4ByteHex(ValueType Value)
		{
			std::string HexValue = IntToHexString(Value,true);
			unsigned int HexSize = HexValue.length();
			//Store at function scope to use for setting rest of half-bytes to zero
			unsigned __int8 Index;
			for(Index=0;Index<HexSize;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = IntToHexChar(HexValue.at(Index));break;
					case 1:
						Byte1_b = IntToHexChar(HexValue.at(Index));break;
					case 2:
						Byte2_a = IntToHexChar(HexValue.at(Index));break;
					case 3:
						Byte2_b = IntToHexChar(HexValue.at(Index));break;
					case 4:
						Byte3_a = IntToHexChar(HexValue.at(Index));break;
					case 5:
						Byte3_b = IntToHexChar(HexValue.at(Index));break;
					case 6:
						Byte4_a = IntToHexChar(HexValue.at(Index));break;
					case 7:
						Byte4_b = IntToHexChar(HexValue.at(Index));break;
				}
			}
			//Set rest of HalfBytes to value of zero
			for(++Index;Index<16;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = 0;break;
					case 1:
						Byte1_b = 0;break;
					case 2:
						Byte2_a = 0;break;
					case 3:
						Byte2_b = 0;break;
					case 4:
						Byte3_a = 0;break;
					case 5:
						Byte3_b =0;break;
					case 6:
						Byte4_a = 0;break;
					case 7:
						Byte4_b = 0;break;
				}
			}
		}
		Hex_4Byte operator=(signed __int8 Value){IntTo4ByteHex(Value);}
		Hex_4Byte operator=(signed __int16 Value){IntTo4ByteHex(Value);}
		Hex_4Byte operator=(signed __int32 Value){IntTo4ByteHex(Value);}
		Hex_4Byte operator=(unsigned __int8 Value){IntTo4ByteHex(Value);}
		Hex_4Byte operator=(unsigned __int16 Value){IntTo4ByteHex(Value);}
		Hex_4Byte operator=(unsigned __int32 Value){IntTo4ByteHex(Value);}
		//************************************
		// Method:    GetAsInt32
		// FullName:  SuperDecHex::Hex_4Byte::GetAsInt32
		// Access:    public 
		// Returns:   unsigned __int64
		// Qualifier:
		//************************************
		unsigned __int32 GetAsInt32();
	};
	struct DLL_API Hex_2Byte
	{
		unsigned __int8 Byte1_a = 0;
		unsigned __int8 Byte1_b = 0;
		unsigned __int8 Byte2_a = 0;
		unsigned __int8 Byte2_b = 0;
		//************************************
		// Assign values based 2 Byte Hex String (4 HalfBytes)
		// Method:    operator=
		// FullName:  SuperDecHex::Hex_8Byte::operator=
		// Access:    public
		// Returns:   SuperDecHex::Hex_8Byte
		// Qualifier:
		// Parameter: std::string HexValue
		//************************************
		Hex_2Byte operator=(std::string HexValue);
		template <typename ValueType>
		void IntTo2ByteHex(ValueType Value)
		{
			std::string HexValue = IntToHexString(Value,true);
			unsigned int HexSize = HexValue.length();
			unsigned __int8 Index;
			for(Index=0;Index<HexSize;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = IntToHexChar(HexValue.at(Index));break;
					case 1:
						Byte1_b = IntToHexChar(HexValue.at(Index));break;
					case 2:
						Byte2_a = IntToHexChar(HexValue.at(Index));break;
					case 3:
						Byte2_b = IntToHexChar(HexValue.at(Index));break;
				}
			}
			//Set rest of HalfBytes to value of zero
			for(++Index;Index<4;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = 0;break;
					case 1:
						Byte1_b = 0;break;
					case 2:
						Byte2_a = 0;break;
					case 3:
						Byte2_b = 0;break;
				}
			}
		}
		Hex_2Byte operator=(signed __int8 Value){IntTo2ByteHex(Value);}
		Hex_2Byte operator=(signed __int16 Value){IntTo2ByteHex(Value);}
		Hex_2Byte operator=(signed __int32 Value){IntTo2ByteHex(Value);}
		Hex_2Byte operator=(unsigned __int8 Value){IntTo2ByteHex(Value);}
		Hex_2Byte operator=(unsigned __int16 Value){IntTo2ByteHex(Value);}
		Hex_2Byte operator=(unsigned __int32 Value){IntTo2ByteHex(Value);}
		unsigned __int16 GetAsInt16();
	};
	struct DLL_API Hex_1Byte
	{
		unsigned __int8 Byte1_a = 0;
		unsigned __int8 Byte1_b = 0;
		//************************************
		// Assign values based 1 Byte Hex String (2 HalfBytes)
		// Method:    operator=
		// FullName:  SuperDecHex::Hex_8Byte::operator=
		// Access:    public
		// Returns:   SuperDecHex::Hex_8Byte
		// Qualifier:
		// Parameter: std::string HexValue
		//************************************
		Hex_1Byte operator=(std::string HexValue);
		template <typename ValueType>
		void IntTo1ByteHex(ValueType Value)
		{
			std::string HexValue = IntToHexString(Value,true);
			unsigned int HexSize = HexValue.length();
			//Store at function scope to use for setting rest of half-bytes to zero
			unsigned __int8 Index;
			for(Index=0;Index<HexSize;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = IntToHexChar(HexValue.at(Index));break;
					case 1:
						Byte1_b = IntToHexChar(HexValue.at(Index));break;
				}
			}
			//Set rest of HalfBytes to value of zero
			for(++Index;Index<2;++Index)
			{
				switch(Index)
				{
					case 0:
						Byte1_a = 0;break;
					case 1:
						Byte1_b = 0;break;
				}
			}
		}
		Hex_1Byte operator=(signed __int8 Value){IntTo1ByteHex(Value);}
		Hex_1Byte operator=(signed __int16 Value){IntTo1ByteHex(Value);}
		Hex_1Byte operator=(signed __int32 Value){IntTo1ByteHex(Value);}
		Hex_1Byte operator=(unsigned __int8 Value){IntTo1ByteHex(Value);}
		Hex_1Byte operator=(unsigned __int16 Value){IntTo1ByteHex(Value);}
		Hex_1Byte operator=(unsigned __int32 Value){IntTo1ByteHex(Value);}
		//************************************
		// Method:    GetAsInt8
		// FullName:  SuperDecHex::Hex_1Byte::GetAsInt8
		// Access:    public 
		// Returns:   unsigned __int8
		// Qualifier:
		//************************************
		unsigned __int8 GetAsInt8();
	};
};

//High Precision Decimal Class (BaseClass defaults to up to 32 Bit unsigned int of whole numbers, plus negative modifier and 2 decimal places of stored digits;5 Bytes Total Stored for Base class if using Unsigned __int32 for wholenumber half(default))
template <typename IntType = unsigned __int32>
class DLL_API SuperDec_BaseClass
{
public:
	IntType IntValue = 0;

#ifdef SuperDec_EnableOverflowStorage
	unsigned __int64 ExtraIntValue01;
#endif

	//0 = IntValue.000
	//1 - 99 = IntValue.XX
	//100 = -IntValue
	//100-199 = -IntValue.XX
	//200 = Positive Infinity
	//201 = IntValue+1/3
	//202 = IntValue+2/3
	//203 = IntValue+1/6
	//204 = IntValue+5/6
	//205 = pi
	//206 = -IntValue-1/3
	//207 = -IntValue-2/3
	//208 = -IntValue-1/6
	//209 = -IntValue-5/6
	//210 = -pi
	//211 = Negative Infinity
	//212 = IntValue/pi
	//213 = -IntValue/pi
	//214 = IntValue*pi
	//215 = -IntValue*pi
	//216 = IntValue/3
	//217 = -IntValue/3
	//218 = -IntValue/6
	//219 = -IntValue/7
	//220 = -IntValue/9
	//221 = -IntValue/11
	//222 = -IntValue/13
	//223 = IntValue/6
	//224 = IntValue/7
	//225 = IntValue/9
	//226 = IntValue/11
	//227 = IntValue/13
	//250 = Undefined Value Flag (Usable without SuperDec_EnableFractionalStorage but only for status of not setting actual value)
	//251 = N/A
	//Holds first 2 places in Decimal as perfect Accuracy (plus some other specific values if optional preprocessor switch SuperDec_EnableFractionalStorage is on)
	//All statuses here above 199(except value 250) require SuperDec_EnableFractionalStorage on to be used right now
	unsigned __int8 DecimalStatus;
	template <typename ValueType>
	void ApplyUnsignedAddition(ValueType Value)
	{
		if(DecimalStatus < 100)//IntValue is Positive
		{
			if(Value > 0)
			{
				IntValue += Value;
			}
			else
			{
				Value *= -1;
				if(Value > IntValue)
				{
					IntValue = Value - IntValue;
					DecimalStatus += 100;
				}
				else
				{
					IntValue -= Value;
				}
			}
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)//IntValue is Negative
		{
			if(Value < 0)
			{
				IntValue -= Value;
			}
			else
			{
				if(Value > IntValue)
				{
					IntValue = Value - IntValue;
					DecimalStatus -= 100;
				}
				else
				{
					IntValue -= Value;
				}
			}
		}
	}
	template <typename ValueType>
	void ApplySignedAddition(ValueType Value)
	{
		if(DecimalStatus < 100)
		{
			IntValue += Value;
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)
		{
			if(Value > IntValue)
			{
				IntValue = Value - IntValue;
				DecimalStatus -= 100;
			}
			else
			{
				IntValue -= Value;
			}
		}
	}
	SuperDec_BaseClass operator+(unsigned int Value) { ApplyUnsignedAddition(&Value); }
	SuperDec_BaseClass operator+(signed int Value) { ApplySignedAddition(&Value); }
	SuperDec_BaseClass operator+(unsigned __int64 Value) { ApplyUnsignedAddition(&Value); }
	SuperDec_BaseClass operator+(signed __int64 Value) { ApplySignedAddition(&Value); }
	void PlusOperation_AddDecimalBuffer(unsigned __int8 DecimalBuffer)
	{
		if(IsNegative)
		{
			if(DecimalStatus == 0) { DecimalStatus = DecimalBuffer*-1; }
			else if(DecimalStatus < 100)
			{//Positive Value Minus Negative Value
				if(DecimalStatus > DecimalBuffer)
				{
					DecimalStatus -= DecimalBuffer;
				}
				else
				{
					DecimalStatus -= DecimalBuffer;
					//Minus 1 from Int part
					if(IntValue == 1)
					{
						IntValue = 0;
					}
					else if(IntValue == 0)
					{
						DecimalStatus += 100;
						IntValue = 1;
					}
					else
					{
						--IntValue;
					}
				}
			}
			else if(DecimalStatus < 199)
			{//Negative Value - Negative Value
				DecimalStatus += DecimalBuffer;
				if(DecimalStatus > 199)
				{
					DecimalStatus -= 100;
					++IntValue;
				}
			}
		}
		else
		{
			if(DecimalStatus == 0) { DecimalStatus = DecimalBuffer; }
			else if(DecimalStatus < 100)
			{//Positive Value + Positive Value
				DecimalStatus += DecimalBuffer;
				if(DecimalStatus > 99)
				{
					DecimalStatus -= 100;
					++IntValue;
				}
			}
			else if(DecimalStatus < 199)
			{//Negative Value + Positive Value
				//DecimalStatus -= DecimalBuffer;
				if(DecimalBuffer = DecimalStatus)
					(
					DecimalBuffer = 0;
			}
			else if(DecimalBuffer > DecimalStatus)
			{//-.2+..3
				//DecimalStatus = DecimalBuffer-DecimalStatus;
				DecimalStatus -= DecimalBuffer;
				if(DecimalStatus < 100)
				{
					if(IntValue == 0)
					{//Moves from negative to positive
						IntValue = 1;
					}
					else if(IntValue == 1)
					{//Still Negative ??.??
						IntValue = 0;
						DecimalBuffer += 100;
					}
					else
					{//Still Negative but closer to positive now
						DecimalBuffer += 100;
						--IntValue;
					}
				}
			}
		}
	}
	SuperDec_BaseClass operator+(double Value)
	{
		unsigned __int64 WholeNumberPart = floor(Value);
		/* Start of WholeNumberPart of Calculations */
		if(DecimalStatus < 100)//IntValue is Positive
		{
			if(WholeNumberPart > 0)
			{
				IntValue += WholeNumberPart;
			}
			else
			{
				WholeNumberPart *= -1;
				if(WholeNumberPart > IntValue)
				{
					IntValue = WholeNumberPart - IntValue;
					DecimalStatus += 100;
				}
				else
				{
					IntValue -= WholeNumberPart;
				}
			}
		}
		else if(DecimalStatus == 211 || DecimalStatus == 200)
		{
			std::cout << "Can't add to Infinity\n";
		}
		else if(DecimalStatus < 199)//IntValue is Negative
		{
			if(WholeNumberPart < 0)
			{
				IntValue -= WholeNumberPart;
			}
			else
			{
				if(Value > IntValue)
				{
					IntValue = WholeNumberPart - IntValue;
					DecimalStatus -= 100;
				}
				else
				{
					IntValue -= WholeNumberPart;
				}
			}
		}
		/* End of WholeNumberPart of Calculations*/
		//Now perform decimal half of calculations
		//Convert Value to String to prevent multiple minor floating-point inaccuracies from adding extra potential error
		std::string DecimalPart = VariableConversionFunctions::DoubleToStringConversion(Value);
		bool IsNegative;
		if(DecimalPart.at(0) == '-')
		{
			IsNegative = true;
		}
		else
		{
			IsNegative = false;
		}
		unsigned int SizeTemp = DecimalPart.length();
		bool InsideDecimal = false;
		unsigned __int8 DecimalBuffer = 0;
		unsigned __int8 DecimalIndex = 0;
		for(unsigned __int8 Index = 0; Index < SizeTemp; ++Index)
		{
			if(InsideDecimal)
			{
				++DecimalIndex;
				if(DecimalIndex == 1)
				{
					DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index));
				}
				else if(DecimalIndex == 2)
				{
					DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index)) * 10;
					PlusOperation_AddDecimalBuffer(DecimalBuffer);
				}
				else
				{/*--Placeholder for Extra Digit Calculations--*/
				}
			}
			else if(DecimalPart.at(Index) == '.')
			{
				InsideDecimal = true;
			}
		}
		//Calculate Buffer difference if haven't yet
		if(DecimalIndex < 2)
		{
			PlusOperation_AddDecimalBuffer(DecimalBuffer);
		}
	}
	SuperDec_BaseClass operator+(std::string Value);
	SuperDec_BaseClass operator=(double Value)
	{
		SuperDec_BaseClass::operator=((signed __int64) floor(Value));
		std::string DecimalPart = VariableConversionFunctions::DoubleToStringConversion(Value);
		bool IsNegative;
		if(DecimalPart.at(0) == '-')
		{
			IsNegative = true;
		}
		else
		{
			IsNegative = false;
		}
		unsigned int SizeTemp = DecimalPart.length();
		bool InsideDecimal = false;
		unsigned __int16 DecimalBuffer = 0;
		unsigned __int8 DecimalIndex = 0;
		for(unsigned __int8 Index = 0; Index < SizeTemp; ++Index)
		{
			if(InsideDecimal)
			{
				++DecimalIndex;
				if(DecimalIndex == 1)
				{
					DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index));
				}
				else if(DecimalIndex == 2)
				{
					DecimalBuffer += VariableConversionFunctions::CharAsInt(DecimalPart.at(Index)) * 10;
					if(IsNegative)
					{
						DecimalStatus = DecimalBuffer + 100;
					}
					else
					{
						DecimalStatus = DecimalBuffer;
					}
					DecimalBuffer = 0;
				}
				else//For Decimal Places higher than 2
				{
				}
			}
		}
		//Calculate Buffer difference if haven't yet
		if(DecimalIndex < 2)
		{
			if(IsNegative) { DecimalStatus = DecimalBuffer + 100; }
			else { DecimalStatus = DecimalBuffer; }
		}
	}
	SuperDec_BaseClass operator=(std::string Value);
	SuperDec_BaseClass operator=(unsigned int Value);
	SuperDec_BaseClass operator=(int Value);
	template <typename ValueType>
	SuperDec_BaseClass operator%(ValueType Value) { IntValue %= Value; }
	template <typename ValueType>
	void ApplyIntValueMultOperation(ValueType Value)
	{
		if(Value == 0 || (DecimalStatus == 0 && IntValue == 0))
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
#ifdef SuperDec_EnableFractionalStorage
#endif
		else
		{
			//bool ValueIsNegative = Value < 0;
			if(Value < 0)
			{
				Value *= -1;
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
				else
				{
					DecimalStatus -= 100;
				}
			}
			if(Value == IntValue)
			{
				IntValue = 1;
			}
			else
			{
				IntValue *= Value;
			}
			bool StatusIsNegative = DecimalStatus>100;
			unsigned __int64 DecimalBuffer = DecimalStatus;
			if(StatusIsNegative)
			{
				DecimalBuffer -= 100;
			}
			for(DecimalBuffer *= Value; DecimalBuffer > 100; DecimalBuffer -= 100;)
			{
				++IntValue;
			}
			if(StatusIsNegative)
			{
				DecimalBuffer += 100;
			}
			DecimalStatus = DecimalBuffer;
		}
		//IntValue *= Value;
	}
	template <typename ValueType>
	void ApplyFloatValueMultOperation(ValueType Value)
	{
		if(Value == 0 || (DecimalStatus == 0 && IntValue == 0))
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			//bool ValueIsNegative = Value < 0;
			if(Value < 0)
			{
				Value *= -1;
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
			}
			//ValueType WholeHalfOfValue = floor(Value);
			//double DecimalHalfTemp = 0.0;
			//DecimalHalfTemp = Value - WholeHalfOfValue;
			////DecimalHalfOfValue = Value - 
			//unsigned __int64 DecimalBuffer = DecimalStatus;
		}
		//IntValue *= Value;
	}
	template <typename ValueType>
	void ApplySuperDecValueMultOperation(ValueType Value)
	{
		if(Value == 0 || (DecimalStatus == 0 && IntValue == 0))
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			//bool ValueIsNegative = Value < 0;
			if(Value < 0)
			{
				Value *= -1;
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
			}
			//ValueType WholeHalfOfValue = floor(Value);
			//double DecimalHalfTemp = 0.0;
			//DecimalHalfTemp = Value - WholeHalfOfValue;
			////DecimalHalfOfValue = Value - 
			//unsigned __int64 DecimalBuffer = DecimalStatus;
			
		}
		//IntValue *= Value;
	}
	template <typename ValueType>
	void ApplyIntValueDivideOperation(ValueType Value)
	{
		if(Value == 0)
		{//Return similar to N/A result
			DecimalStatus = 251;
		}
		else if(DecimalStatus == 0 && IntValue == 0)
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			if(Value < 0)
			{
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
				Value *= -1;
			}
			//Create rest of the code here later
		}
	}
	template <typename ValueType>
	void ApplyFloatValueDivideOperation(ValueType Value)
	{
		if(Value == 0)
		{//Return similar to N/A result
			DecimalStatus = 251;
		}
		else if(DecimalStatus == 0 && IntValue == 0)
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			if(Value < 0)
			{
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
				Value *= -1;
			}
			//Create rest of the code here later
		}
	}
	template <typename ValueType>
	void ApplySuperDecValueDivideOperation(ValueType Value)
	{
		if(Value == 0)
		{//Return similar to N/A result
			DecimalStatus = 251;
		}
		else if(DecimalStatus == 0 && IntValue == 0)
		{
			IntValue = 0;
			DecimalStatus = 0;
		}
		else
		{
			if(Value < 0)
			{
				if(DecimalStatus < 100)//Flip positive to negative
				{
					DecimalStatus += 100;
				}
#ifdef SuperDec_EnableFractionalStorage
#endif
				else
				{
					DecimalStatus -= 100;
				}
				Value *= -1;
			}
			//Create rest of the code here later
		}
	}
	SuperDec_BaseClass operator*(signed int Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned int Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(signed __int8 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned __int8 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(signed __int64 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator*(unsigned __int64 Value) { ApplyIntValueMultOperation(&Value); }
	SuperDec_BaseClass operator%(signed int Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned int Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(signed __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned __int8 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(signed __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator%(unsigned __int64 Value) { ApplyIntValueDivideOperation(&Value); }
	SuperDec_BaseClass operator=(signed __int64 Value);
	SuperDec_BaseClass operator=(unsigned __int64 Value);
	SuperDec_BaseClass(SuperDec_BaseClass const& copy) = default;
	SuperDec_BaseClass& operator=(SuperDec_BaseClass const& copy) = default;
	SuperDec_BaseClass() {}
	~SuperDec_BaseClass() {}
};

class SuperDec_Basic : public SuperDec_BaseClass <unsigned __int64>
{};

class SuperDec : public SuperDec_BaseClass <unsigned __int32>
{
	//Base::operator=(d);
	SuperDec operator=(double Value);
};

//78 Perfect Digits Decimal,Holds 64Bt unsigned int worth of whole numbers, holds Negative/Positive Status, Holds optional Fractionals/things like pi, Total Storage space used = 42 Bytes Used
class SuperDec_64Bit78Dec : public  SuperDec_Basic
{
	//Holds data for Digits(3-21)
	//Value 1 = Digit # 3 has value of 1 and Digits #4-21 have values of zero
	unsigned __int64 ExtraDecimal00;
	//Holds data for Digits(22-40)
	unsigned __int64 ExtraDecimal01;
	//Holds data for Digits(41-59)
	unsigned __int64 ExtraDecimal00;
	//Holds data for Digits(60-78)
	unsigned __int64 ExtraDecimal01;
};

//Store Global Functions for SuperDec here
struct DLL_API SuperDec_Globals
{
	//************************************
	// Method:    MaxWholeValue
	// FullName:  SuperDec_Globals::MaxWholeValue
	// Access:    public static
	// Returns:   unsigned __int64
	// Qualifier:
	// Parameter: unsigned __int8 NumBytes
	//************************************
	static unsigned __int64 MaxWholeValue(unsigned __int8 NumBytes)
	{
		return pow(256, NumBytes) - 1;
	}
};

#endif