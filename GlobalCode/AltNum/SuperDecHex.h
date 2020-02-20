// ***********************************************************************
// Assembly         :
// Author           : BlazesRus
// Created          : 02-09-2018
//
// Last Modified By : BlazesRus
// Last Modified On : 10-10-2018
// ***********************************************************************
// <copyright file="SuperDecHex.h" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

#pragma once
#if !defined(FileName_IncludeGuard) && !defined(ExcludeAltNum)
#define FileName_IncludeGuard

//#include <io.h>
//#include <math.h>
//#include <iostream>

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

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)

#else
#endif

/// <summary>
/// static accessed struct named SuperDecHex
/// </summary>
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
/// <summary>
/// Ints to hexadecimal character.
/// </summary>
/// <param name="num">The number.</param>
/// <returns>char DLL_API.</returns>
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
/// <summary>
/// Hexadecimals the character to int.
/// </summary>
/// <param name="num">The number.</param>
/// <returns>unsigned __int8.</returns>
	static unsigned __int8 HexCharToInt(int num);
	//Takes any type of unsigned Int value and converts to hex Equivalent
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
/// <summary>
/// Ints to hexadecimal string.
/// </summary>
/// <param name="num">The number.</param>
/// <param name="ReversedHex">The reversed hexadecimal.</param>
/// <returns>std.string DLL_API.</returns>
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
	/// <summary>
	/// Struct Hex_8Byte
	/// </summary>
	/// Holds 16 HalfByte int values of between 0-15 (0-F as char) (Represents 8 Byte as Hex)
	/// HalfByte refers to 0-15 value (Half of Hex chars of a byte);Example Hex String "FFFFFFFFFFFFFFFF"
	/// Main use here is for splitting remaining digits of value for using for other purposes
	struct DLL_API Hex_8Byte
	{
		/// <summary>
		/// The byte1 a
		/// </summary>
		unsigned __int8 Byte1_a = 0;
		/// <summary>
		/// The byte1 b
		/// </summary>
		unsigned __int8 Byte1_b = 0;
		/// <summary>
		/// The byte2 a
		/// </summary>
		unsigned __int8 Byte2_a = 0;
		/// <summary>
		/// The byte2 b
		/// </summary>
		unsigned __int8 Byte2_b = 0;
		/// <summary>
		/// The byte3 a
		/// </summary>
		unsigned __int8 Byte3_a = 0;
		/// <summary>
		/// The byte3 b
		/// </summary>
		unsigned __int8 Byte3_b = 0;
		/// <summary>
		/// The byte4 a
		/// </summary>
		unsigned __int8 Byte4_a = 0;
		/// <summary>
		/// The byte4 b
		/// </summary>
		unsigned __int8 Byte4_b = 0;
		/// <summary>
		/// The byte5 a
		/// </summary>
		unsigned __int8 Byte5_a = 0;
		/// <summary>
		/// The byte5 b
		/// </summary>
		unsigned __int8 Byte5_b = 0;
		/// <summary>
		/// The byte6 a
		/// </summary>
		unsigned __int8 Byte6_a = 0;
		/// <summary>
		/// The byte6 b
		/// </summary>
		unsigned __int8 Byte6_b = 0;
		/// <summary>
		/// The byte7 a
		/// </summary>
		unsigned __int8 Byte7_a = 0;
		/// <summary>
		/// The byte7 b
		/// </summary>
		unsigned __int8 Byte7_b = 0;
		/// <summary>
		/// The byte8 a
		/// </summary>
		unsigned __int8 Byte8_a = 0;
		/// <summary>
		/// The byte8 b
		/// </summary>
		unsigned __int8 Byte8_b = 0;
		/// <summary>
		/// Operator=s the specified hexadecimal value.
		/// </summary>
		/// <param name="HexValue">The hexadecimal value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		/// ************************************
		/// Assign values based 8 Byte Hex String (16 HalfBytes)
		/// Method:    operator=
		/// FullName:  SuperDecHex::Hex_8Byte::operator=
		/// Access:    public
		/// Returns:   SuperDecHex::Hex_8Byte
		/// Qualifier:
		/// Parameter: std::string HexValue
		/// ************************************
		Hex_8Byte operator=(std::string HexValue);
		/// <summary>
		/// Ints the to8 byte hexadecimal.
		/// </summary>
		/// <param name="Value">The value.</param>
		template <typename ValueType>
		void IntTo8ByteHex(ValueType Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(signed __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(signed __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(signed __int32 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(signed __int64 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(unsigned __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(unsigned __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(unsigned __int32 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_8Byte.</returns>
		Hex_8Byte operator=(unsigned __int64 Value);
		/// <summary>
		/// Gets as int64.
		/// </summary>
		/// <returns>unsigned __int64.</returns>
		unsigned __int64 GetAsInt64();
	};
	/// <summary>
	/// Struct Hex_4Byte
	/// </summary>
	struct DLL_API Hex_4Byte
	{
		/// <summary>
		/// The byte1 a
		/// </summary>
		unsigned __int8 Byte1_a = 0;
		/// <summary>
		/// The byte1 b
		/// </summary>
		unsigned __int8 Byte1_b = 0;
		/// <summary>
		/// The byte2 a
		/// </summary>
		unsigned __int8 Byte2_a = 0;
		/// <summary>
		/// The byte2 b
		/// </summary>
		unsigned __int8 Byte2_b = 0;
		/// <summary>
		/// The byte3 a
		/// </summary>
		unsigned __int8 Byte3_a = 0;
		/// <summary>
		/// The byte3 b
		/// </summary>
		unsigned __int8 Byte3_b = 0;
		/// <summary>
		/// The byte4 a
		/// </summary>
		unsigned __int8 Byte4_a = 0;
		/// <summary>
		/// The byte4 b
		/// </summary>
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
/// <summary>
/// Operator=s the specified hexadecimal value.
/// </summary>
/// <param name="HexValue">The hexadecimal value.</param>
/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(std::string HexValue);
		/// <summary>
		/// Ints the to4 byte hexadecimal.
		/// </summary>
		/// <param name="Value">The value.</param>
		template <typename ValueType>
		void IntTo4ByteHex(ValueType Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(signed __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(signed __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(signed __int32 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(unsigned __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(unsigned __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_4Byte.</returns>
		Hex_4Byte operator=(unsigned __int32 Value);
		//************************************
		// Method:    GetAsInt32
		// FullName:  SuperDecHex::Hex_4Byte::GetAsInt32
		// Access:    public
		// Returns:   unsigned __int64
		// Qualifier:
		//************************************
/// <summary>
/// Gets as int32.
/// </summary>
/// <returns>unsigned __int32.</returns>
		unsigned __int32 GetAsInt32();
	};
	/// <summary>
	/// Struct Hex_2Byte
	/// </summary>
	struct DLL_API Hex_2Byte
	{
		/// <summary>
		/// The byte1 a
		/// </summary>
		unsigned __int8 Byte1_a = 0;
		/// <summary>
		/// The byte1 b
		/// </summary>
		unsigned __int8 Byte1_b = 0;
		/// <summary>
		/// The byte2 a
		/// </summary>
		unsigned __int8 Byte2_a = 0;
		/// <summary>
		/// The byte2 b
		/// </summary>
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
/// <summary>
/// Operator=s the specified hexadecimal value.
/// </summary>
/// <param name="HexValue">The hexadecimal value.</param>
/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(std::string HexValue);
		/// <summary>
		/// Ints the to2 byte hexadecimal.
		/// </summary>
		/// <param name="Value">The value.</param>
		template <typename ValueType>
		void IntTo2ByteHex(ValueType Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(signed __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(signed __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(signed __int32 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(unsigned __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(unsigned __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_2Byte.</returns>
		Hex_2Byte operator=(unsigned __int32 Value);
		/// <summary>
		/// Gets as int16.
		/// </summary>
		/// <returns>unsigned __int16.</returns>
		unsigned __int16 GetAsInt16();
	};
	/// <summary>
	/// Struct Hex_1Byte
	/// </summary>
	struct DLL_API Hex_1Byte
	{
		/// <summary>
		/// The byte1 a
		/// </summary>
		unsigned __int8 Byte1_a = 0;
		/// <summary>
		/// The byte1 b
		/// </summary>
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
/// <summary>
/// Operator=s the specified hexadecimal value.
/// </summary>
/// <param name="HexValue">The hexadecimal value.</param>
/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(std::string HexValue);
		/// <summary>
		/// Ints the to1 byte hexadecimal.
		/// </summary>
		/// <param name="Value">The value.</param>
		template <typename ValueType>
		void IntTo1ByteHex(ValueType Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(signed __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(signed __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(signed __int32 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(unsigned __int8 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(unsigned __int16 Value);
		/// <summary>
		/// Operator=s the specified value.
		/// </summary>
		/// <param name="Value">The value.</param>
		/// <returns>SuperDecHex.Hex_1Byte.</returns>
		Hex_1Byte operator=(unsigned __int32 Value);
		//************************************
		// Method:    GetAsInt8
		// FullName:  SuperDecHex::Hex_1Byte::GetAsInt8
		// Access:    public
		// Returns:   unsigned __int8
		// Qualifier:
		//************************************
/// <summary>
/// Gets as int8.
/// </summary>
/// <returns>unsigned __int8.</returns>
		unsigned __int8 GetAsInt8();
	};
};

#endif
