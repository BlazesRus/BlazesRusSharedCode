/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/

#include "SuperDecHex.h"


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(std::string HexValue)
{
	unsigned int HexSize = HexValue.length();
	//Store at function scope to use for setting rest of half-bytes to zero
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
			case 4:
				Byte3_a = IntToHexChar(HexValue.at(Index)); break;
			case 5:
				Byte3_b = IntToHexChar(HexValue.at(Index)); break;
			case 6:
				Byte4_a = IntToHexChar(HexValue.at(Index)); break;
			case 7:
				Byte4_b = IntToHexChar(HexValue.at(Index)); break;
			case 8:
				Byte5_a = IntToHexChar(HexValue.at(Index)); break;
			case 9:
				Byte5_b = IntToHexChar(HexValue.at(Index)); break;
			case 10:
				Byte6_a = IntToHexChar(HexValue.at(Index)); break;
			case 11:
				Byte6_b = IntToHexChar(HexValue.at(Index)); break;
			case 12:
				Byte7_a = IntToHexChar(HexValue.at(Index)); break;
			case 13:
				Byte7_b = IntToHexChar(HexValue.at(Index)); break;
			case 14:
				Byte8_a = IntToHexChar(HexValue.at(Index)); break;
			case 15:
				Byte8_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
			case 4:
				Byte3_a = 0; break;
			case 5:
				Byte3_b = 0; break;
			case 6:
				Byte4_a = 0; break;
			case 7:
				Byte4_b = 0; break;
			case 8:
				Byte5_a = 0; break;
			case 9:
				Byte5_b = 0; break;
			case 10:
				Byte6_a = 0; break;
			case 11:
				Byte6_b = 0; break;
			case 12:
				Byte7_a = 0; break;
			case 13:
				Byte7_b = 0; break;
			case 14:
				Byte8_a = 0; break;
			case 15:
				Byte8_b = 0; break;
		}
	}
}


unsigned __int64 SuperDecHex::Hex_8Byte::GetAsInt64()
{
	unsigned __int64 CalcValue = 0;
	for(unsigned __int8 Index = 0; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				CalcValue += pow(16, Index) * Byte1_a; break;
			case 1:
				CalcValue += pow(16, Index) * Byte1_b; break;
			case 2:
				CalcValue += pow(16, Index) * Byte2_a; break;
			case 3:
				CalcValue += pow(16, Index) * Byte2_b; break;
			case 4:
				CalcValue += pow(16, Index) * Byte3_a; break;
			case 5:
				CalcValue += pow(16, Index) * Byte3_b; break;
			case 6:
				CalcValue += pow(16, Index) * Byte4_a; break;
			case 7:
				CalcValue += pow(16, Index) * Byte4_b; break;
			case 8:
				CalcValue += pow(16, Index) * Byte5_a; break;
			case 9:
				CalcValue += pow(16, Index) * Byte5_b; break;
			case 10:
				CalcValue += pow(16, Index) * Byte6_a; break;
			case 11:
				CalcValue += pow(16, Index) * Byte6_b; break;
			case 12:
				CalcValue += pow(16, Index) * Byte7_a; break;
			case 13:
				CalcValue += pow(16, Index) * Byte7_b; break;
			case 14:
				CalcValue += pow(16, Index) * Byte8_a; break;
			case 15:
				CalcValue += pow(16, Index) * Byte8_b; break;
		}
	}
	return CalcValue;
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(std::string HexValue)
{
	unsigned int HexSize = HexValue.length();
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
			case 4:
				Byte3_a = IntToHexChar(HexValue.at(Index)); break;
			case 5:
				Byte3_b = IntToHexChar(HexValue.at(Index)); break;
			case 6:
				Byte4_a = IntToHexChar(HexValue.at(Index)); break;
			case 7:
				Byte4_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
			case 4:
				Byte3_a = 0; break;
			case 5:
				Byte3_b = 0; break;
			case 6:
				Byte4_a = 0; break;
			case 7:
				Byte4_b = 0; break;
		}
	}
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(unsigned __int32 Value)
{
	IntTo4ByteHex(Value);
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(unsigned __int16 Value)
{
	IntTo4ByteHex(Value);
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(unsigned __int8 Value)
{
	IntTo4ByteHex(Value);
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(signed __int32 Value)
{
	IntTo4ByteHex(Value);
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(signed __int16 Value)
{
	IntTo4ByteHex(Value);
}

SuperDecHex::Hex_4Byte SuperDecHex::Hex_4Byte::operator=(signed __int8 Value)
{
	IntTo4ByteHex(Value);
}

template <typename ValueType>
void SuperDecHex::Hex_4Byte::IntTo4ByteHex(ValueType Value)
{
	std::string HexValue = IntToHexString(Value, true);
	unsigned int HexSize = HexValue.length();
	//Store at function scope to use for setting rest of half-bytes to zero
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
			case 4:
				Byte3_a = IntToHexChar(HexValue.at(Index)); break;
			case 5:
				Byte3_b = IntToHexChar(HexValue.at(Index)); break;
			case 6:
				Byte4_a = IntToHexChar(HexValue.at(Index)); break;
			case 7:
				Byte4_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
			case 4:
				Byte3_a = 0; break;
			case 5:
				Byte3_b = 0; break;
			case 6:
				Byte4_a = 0; break;
			case 7:
				Byte4_b = 0; break;
		}
	}
}

unsigned __int32 SuperDecHex::Hex_4Byte::GetAsInt32()
{
	unsigned __int32 CalcValue = 0;
	for(unsigned __int8 Index = 0; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				CalcValue += pow(16, Index) * Byte1_a; break;
			case 1:
				CalcValue += pow(16, Index) * Byte1_b; break;
			case 2:
				CalcValue += pow(16, Index) * Byte2_a; break;
			case 3:
				CalcValue += pow(16, Index) * Byte2_b; break;
			case 4:
				CalcValue += pow(16, Index) * Byte3_a; break;
			case 5:
				CalcValue += pow(16, Index) * Byte3_b; break;
			case 6:
				CalcValue += pow(16, Index) * Byte4_a; break;
			case 7:
				CalcValue += pow(16, Index) * Byte4_b; break;
		}
	}
	return CalcValue;
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(std::string HexValue)
{
	unsigned int HexSize = HexValue.length();
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 4; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
		}
	}
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(unsigned __int32 Value)
{
	IntTo2ByteHex(Value);
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(unsigned __int16 Value)
{
	IntTo2ByteHex(Value);
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(unsigned __int8 Value)
{
	IntTo2ByteHex(Value);
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(signed __int32 Value)
{
	IntTo2ByteHex(Value);
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(signed __int16 Value)
{
	IntTo2ByteHex(Value);
}

SuperDecHex::Hex_2Byte SuperDecHex::Hex_2Byte::operator=(signed __int8 Value)
{
	IntTo2ByteHex(Value);
}

template <typename ValueType>
void SuperDecHex::Hex_2Byte::IntTo2ByteHex(ValueType Value)
{
	std::string HexValue = IntToHexString(Value, true);
	unsigned int HexSize = HexValue.length();
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 4; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
		}
	}
}

unsigned __int16 SuperDecHex::Hex_2Byte::GetAsInt16()
{
	unsigned __int16 CalcValue = 0;
	for(unsigned __int8 Index = 0; Index < 4; ++Index)
	{
		switch(Index)
		{
			case 0:
				CalcValue += pow(16, Index) * Byte1_a; break;
			case 1:
				CalcValue += pow(16, Index) * Byte1_b; break;
			case 2:
				CalcValue += pow(16, Index) * Byte2_a; break;
			case 3:
				CalcValue += pow(16, Index) * Byte2_b; break;
		}
	}
	return CalcValue;
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(std::string HexValue)
{
	unsigned int HexSize = HexValue.length();
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 2; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
		}
	}
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(unsigned __int32 Value)
{
	IntTo1ByteHex(Value);
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(unsigned __int16 Value)
{
	IntTo1ByteHex(Value);
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(unsigned __int8 Value)
{
	IntTo1ByteHex(Value);
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(signed __int32 Value)
{
	IntTo1ByteHex(Value);
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(signed __int16 Value)
{
	IntTo1ByteHex(Value);
}

SuperDecHex::Hex_1Byte SuperDecHex::Hex_1Byte::operator=(signed __int8 Value)
{
	IntTo1ByteHex(Value);
}

template <typename ValueType>
void SuperDecHex::Hex_1Byte::IntTo1ByteHex(ValueType Value)
{
	std::string HexValue = IntToHexString(Value, true);
	unsigned int HexSize = HexValue.length();
	//Store at function scope to use for setting rest of half-bytes to zero
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 2; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
		}
	}
}

unsigned __int8 SuperDecHex::Hex_1Byte::GetAsInt8()
{
	unsigned __int8 CalcValue = 0;
	for(unsigned __int8 Index = 0; Index < 2; ++Index)
	{
		switch(Index)
		{
			case 0:
				CalcValue += pow(16, Index) * Byte1_a; break;
			case 1:
				CalcValue += pow(16, Index) * Byte1_b; break;
		}
	}
	return CalcValue;
}

unsigned __int8 SuperDecHex::HexCharToInt(int num)
{
	switch(num)
	{
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			return 0;
	}
}

template <typename ValueType>
char DLL_API SuperDecHex::IntToHexChar(ValueType num)
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


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(unsigned __int64 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(unsigned __int32 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(unsigned __int16 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(unsigned __int8 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(signed __int64 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(signed __int32 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(signed __int16 Value)
{
	IntTo8ByteHex(Value);
}


SuperDecHex::Hex_8Byte SuperDecHex::Hex_8Byte::operator=(signed __int8 Value)
{
	IntTo8ByteHex(Value);
}


template <typename ValueType>
void SuperDecHex::Hex_8Byte::IntTo8ByteHex(ValueType Value)
{
	std::string HexValue = IntToHexString(Value, true);
	unsigned int HexSize = HexValue.length();
	unsigned __int8 Index;
	for(Index = 0; Index < HexSize; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = IntToHexChar(HexValue.at(Index)); break;
			case 1:
				Byte1_b = IntToHexChar(HexValue.at(Index)); break;
			case 2:
				Byte2_a = IntToHexChar(HexValue.at(Index)); break;
			case 3:
				Byte2_b = IntToHexChar(HexValue.at(Index)); break;
			case 4:
				Byte3_a = IntToHexChar(HexValue.at(Index)); break;
			case 5:
				Byte3_b = IntToHexChar(HexValue.at(Index)); break;
			case 6:
				Byte4_a = IntToHexChar(HexValue.at(Index)); break;
			case 7:
				Byte4_b = IntToHexChar(HexValue.at(Index)); break;
			case 8:
				Byte5_a = IntToHexChar(HexValue.at(Index)); break;
			case 9:
				Byte5_b = IntToHexChar(HexValue.at(Index)); break;
			case 10:
				Byte6_a = IntToHexChar(HexValue.at(Index)); break;
			case 11:
				Byte6_b = IntToHexChar(HexValue.at(Index)); break;
			case 12:
				Byte7_a = IntToHexChar(HexValue.at(Index)); break;
			case 13:
				Byte7_b = IntToHexChar(HexValue.at(Index)); break;
			case 14:
				Byte8_a = IntToHexChar(HexValue.at(Index)); break;
			case 15:
				Byte8_b = IntToHexChar(HexValue.at(Index)); break;
		}
	}
	//Set rest of HalfBytes to value of zero
	for(++Index; Index < 16; ++Index)
	{
		switch(Index)
		{
			case 0:
				Byte1_a = 0; break;
			case 1:
				Byte1_b = 0; break;
			case 2:
				Byte2_a = 0; break;
			case 3:
				Byte2_b = 0; break;
			case 4:
				Byte3_a = 0; break;
			case 5:
				Byte3_b = 0; break;
			case 6:
				Byte4_a = 0; break;
			case 7:
				Byte4_b = 0; break;
			case 8:
				Byte5_a = 0; break;
			case 9:
				Byte5_b = 0; break;
			case 10:
				Byte6_a = 0; break;
			case 11:
				Byte6_b = 0; break;
			case 12:
				Byte7_a = 0; break;
			case 13:
				Byte7_b = 0; break;
			case 14:
				Byte8_a = 0; break;
			case 15:
				Byte8_b = 0; break;
		}
	}
}
