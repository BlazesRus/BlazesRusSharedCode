#pragma once
#ifndef VariableConversionFunctions_IncludeGuard
#define VariableConversionFunctions_IncludeGuard

#include <string>
#include <stdint.h>

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


class DLL_API VariableConversionFunctions
{
public:
	static int PowerOfTens[10];
	static long PowerOfTens64Bit[19];
	//************************************
	// Method:    NumberOfPlaces
	// FullName:  VariableConversionFunctions::NumberOfPlaces
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: int Value
	//************************************
	static int NumberOfPlaces(int Value);
	//************************************
	// Method:    NumberOfPlaces
	// FullName:  VariableConversionFunctions::NumberOfPlaces
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: unsigned int Value
	//************************************
	static int NumberOfPlaces(unsigned int Value);
	//************************************
	// Method:    NumberOfPlaces
	// FullName:  VariableConversionFunctions::NumberOfPlaces
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: double Value
	//************************************
	static int NumberOfPlaces(double Value);
	//************************************
	// Method:    NumberOfPlaces
	// FullName:  VariableConversionFunctions::NumberOfPlaces
	// Access:    public static
	// Returns:   long long int
	// Qualifier:
	// Parameter: long long int Value
	//************************************
	static long long int NumberOfPlaces(long long int Value);
	//************************************
	// Method:    NumberOfPlacesX
	// FullName:  VariableConversionFunctions::NumberOfPlacesX
	// Access:    public static
	// Returns:   long long int
	// Qualifier:
	// Parameter: size_t Value
	//************************************
	static long long int NumberOfPlacesX(size_t Value);
	//************************************
	// Method:    NumberOfDecimalPlaces
	// FullName:  VariableConversionFunctions::NumberOfDecimalPlaces
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: int Value
	//************************************
	static int NumberOfDecimalPlaces(int Value);
	//************************************
	// Method:    NumberOfDecimalPlaces
	// FullName:  VariableConversionFunctions::NumberOfDecimalPlaces
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: double Value
	//************************************
	static int NumberOfDecimalPlaces(double Value);
	//************************************
	// Method:    CharAsInt
	// FullName:  VariableConversionFunctions::CharAsInt
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: char Temp
	//************************************
	static int CharAsInt(char Temp);
	//************************************
	// Method:    DigitAsChar
	// FullName:  VariableConversionFunctions::DigitAsChar
	// Access:    public static
	// Returns:   char
	// Qualifier:
	// Parameter: int Temp
	//************************************
	static char DigitAsChar(int Temp);
	//************************************
	// Method:    IsDigit
	// FullName:  VariableConversionFunctions::IsDigit
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: char Temp
	//************************************
	static bool IsDigit(char Temp);
	//************************************
	// Method:    IsDigit
	// FullName:  VariableConversionFunctions::IsDigit
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string Temp
	//************************************
	static bool IsDigit(std::string Temp);
	//Returns Double Value version of String
	//************************************
	// Method:    ReadDoubleFromString
	// FullName:  VariableConversionFunctions::ReadDoubleFromString
	// Access:    public static
	// Returns:   double
	// Qualifier:
	// Parameter: std::string TempString
	//************************************
	static double ReadDoubleFromString(std::string TempString);

	static float ReadFloatFromString(std::string TempString);
	//Returns Integer value version of String
	//************************************
	// Method:    ReadIntFromString
	// FullName:  VariableConversionFunctions::ReadIntFromString
	// Access:    public static
	// Returns:   int
	// Qualifier:
	// Parameter: std::string TempString
	//************************************
	static int ReadIntFromString(std::string TempString);
	//Returns first std::string of either true,false,1, or 0 in string; if no value found returns false
	//************************************
	// Method:    ReadBoolFromString
	// FullName:  VariableConversionFunctions::ReadBoolFromString
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static bool ReadBoolFromString(std::string LineString);
	//Returns long long int value from string(int 64 bit)
	//************************************
	// Method:    ReadXIntFromString
	// FullName:  VariableConversionFunctions::ReadXIntFromString
	// Access:    public static
	// Returns:   long long int
	// Qualifier:
	// Parameter: std::string TempString
	//************************************
	static long long int ReadXIntFromString(std::string TempString);
	//************************************
	// Scan int for bool value
	// Method:    ReadBoolFromInt
	// FullName:  VariableConversionFunctions::ReadBoolFromInt
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: int Temp
	//************************************
	static bool ReadBoolFromInt(int Temp);
	//************************************
	// Method:    DoubleAsString
	// FullName:  VariableConversionFunctions::DoubleAsString
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: double TempValue
	//************************************
	static std::string DoubleAsString(double TempValue);
	//************************************
	// Method:    BoolAsString
	// FullName:  VariableConversionFunctions::BoolAsString
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: bool TempValue
	//************************************
	static std::string BoolAsString(bool TempValue);
	//************************************
	// Method:    DoubleToStringConversion
	// FullName:  VariableConversionFunctions::DoubleToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: double TempValue
	//************************************
	static std::string DoubleToStringConversion(double TempValue);
	//************************************
	// Method:    IntToStringConversion
	// FullName:  VariableConversionFunctions::IntToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: int TempValue
	//************************************
	static std::string IntToStringConversion(int TempValue);
	//************************************
	// Method:    IntToStringConversion
	// FullName:  VariableConversionFunctions::IntToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: unsigned int TempValue
	//************************************
	static std::string IntToStringConversion(unsigned int TempValue);
	//************************************
	// Method:    XIntToStringConversion
	// FullName:  VariableConversionFunctions::XIntToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: long long TempValue
	//************************************
	static std::string XIntToStringConversion(long long TempValue);
	//************************************
	// Method:    XIntToStringConversion
	// FullName:  VariableConversionFunctions::XIntToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: size_t TempValue
	//************************************
	static std::string XIntToStringConversion(size_t TempValue);

	//************************************
	//FloatToDouble code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c
	// Method:    float_to_double
	// FullName:  VariableConversionFunctions::float_to_double
	// Access:    public static
	// Returns:   uint64_t
	// Qualifier:
	// Parameter: float value
	//************************************
	static uint64_t float_to_double(float value);
	//************************************
	//FloatToDouble code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c
	// Method:    double_to_float
	// FullName:  VariableConversionFunctions::double_to_float
	// Access:    public static
	// Returns:   float
	// Qualifier:
	// Parameter: uint64_t value
	//************************************
	static float double_to_float(uint64_t value);
	//************************************
	// Uses code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c to convert from Double To Float
	// Method:    DoubleToFloat
	// FullName:  StringFunctions::DoubleToFloat
	// Access:    public static
	// Returns:   float
	// Qualifier:
	// Parameter: double TempValue
	//************************************
	static float DoubleToFloat(double TempValue);
	//************************************
	// Uses code from https://github.com/PIlin/nanopb/blob/master/example_avr_double/double_conversion.c to convert from Float to Double
	// Method:    FloatToDouble
	// FullName:  StringFunctions::FloatToDouble
	// Access:    public static
	// Returns:   double
	// Qualifier:
	// Parameter: float TempValue
	//************************************
	static double FloatToDouble(float TempValue);
	//************************************
	// Method:    FloatToStringConversion
	// FullName:  VariableConversionFunctions::FloatToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: float TempValue
	//************************************
	static std::string FloatToStringConversion(float TempValue);
	//************************************
	// Method:    Int32ToFloat
	// FullName:  VariableConversionFunctions::Int32ToFloat
	// Access:    public
	// Returns:   float
	// Qualifier:
	// Parameter: int32_t Value
	//************************************
	float Int32ToFloat(int32_t Value);
	std::string DisplayFullValues_Vector(float x, float y, float z, float w);
	std::string DisplayFullValues_Vector(float x, float y, float z);
	std::string DisplayFullValues_Vector(float x, float y);
	std::string DisplayFullValues(float x, float y, float z, float w);
	std::string DisplayFullValues(float x, float y, float z);
	std::string DisplayFullValues(float x, float y);
};
#endif