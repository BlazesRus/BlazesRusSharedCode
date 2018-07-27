/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

#pragma once
#ifndef FileName_IncludeGuard
#define FileName_IncludeGuard

//#include <io.h>
//#include <math.h>
//#include <iostream>

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#else
#endif

struct SuperDecHex
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
	static char DLL_API IntToHexChar(ValueType num);
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
	static std::string DLL_API IntToHexString(ValueType num, bool ReversedHex = false)
	{
		if(num == 0)
		{
			return "";
		}
		if(num < 0)
		{
			std::cout << "Negative values not supported by this version of the method.\n";
			return "";
		}
		ValueType rem;
		std::string str = "";
		//Process individual digits
		while(num != 0)
		{
			rem = num % 16;
			str += IntToChar(rem);
			num = num / 16;
		}
		if(ReversedHex)
		{
			std::string TempString = "";
			for(unsigned __int8 Index = str.length(); Index >= 0; ++Index)
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
	struct Hex_8Byte;
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
		void IntTo8ByteHex(ValueType Value);
		Hex_8Byte operator=(signed __int8 Value);
		Hex_8Byte operator=(signed __int16 Value);
		Hex_8Byte operator=(signed __int32 Value);
		Hex_8Byte operator=(signed __int64 Value);
		Hex_8Byte operator=(unsigned __int8 Value);
		Hex_8Byte operator=(unsigned __int16 Value);
		Hex_8Byte operator=(unsigned __int32 Value);
		Hex_8Byte operator=(unsigned __int64 Value);
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
		void IntTo4ByteHex(ValueType Value);
		Hex_4Byte operator=(signed __int8 Value);
		Hex_4Byte operator=(signed __int16 Value);
		Hex_4Byte operator=(signed __int32 Value);
		Hex_4Byte operator=(unsigned __int8 Value);
		Hex_4Byte operator=(unsigned __int16 Value);
		Hex_4Byte operator=(unsigned __int32 Value);
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
		void IntTo2ByteHex(ValueType Value);
		Hex_2Byte operator=(signed __int8 Value);
		Hex_2Byte operator=(signed __int16 Value);
		Hex_2Byte operator=(signed __int32 Value);
		Hex_2Byte operator=(unsigned __int8 Value);
		Hex_2Byte operator=(unsigned __int16 Value);
		Hex_2Byte operator=(unsigned __int32 Value);
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
		void IntTo1ByteHex(ValueType Value);
		Hex_1Byte operator=(signed __int8 Value);
		Hex_1Byte operator=(signed __int16 Value);
		Hex_1Byte operator=(signed __int32 Value);
		Hex_1Byte operator=(unsigned __int8 Value);
		Hex_1Byte operator=(unsigned __int16 Value);
		Hex_1Byte operator=(unsigned __int32 Value);
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

#endif
