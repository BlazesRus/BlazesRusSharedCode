/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef StringFunctions_IncludeGuard
#define StringFunctions_IncludeGuard

#include <string>
#include <stdint.h>

class StringFunctions
{
public:
	static int NumberOfPlaces(int Value);
	static int NumberOfPlaces(double Value);
	static long long int NumberOfPlaces(long long int Value);
	static int NumberOfDecimalPlaces(int Value);
	static int NumberOfDecimalPlaces(double Value);
	static std::string AddStringInFront(std::string ValueAdded, std::string TargetString);
	static std::string AddStringInFront(char ValueAdded, std::string TargetString);
	static int CharAsInt(char Temp);
	static char DigitAsChar(int Temp);
	static bool IsDigit(char Temp);
	static bool IsDigit(std::string Temp);
	//Returns Double Value version of String
	static double ReadDoubleFromString(std::string TempString);
	//Returns Integer value version of String
	static int ReadIntFromString(std::string TempString);
	//Returns long long int value from string(int 64 bit)
	static long long int ReadXIntFromString(std::string TempString);
	//************************************
	// Scan string for bool value
	// Method:    ReadBoolFromInt
	// FullName:  StringFunctions::ReadBoolFromInt
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: int Temp
	//************************************
	static bool ReadBoolFromInt(int Temp);
	static std::string DoubleAsString(double TempValue);
	static std::string BoolAsString(bool TempValue);

	//Returns first std::string of either true,false,1, or 0 in string; if no value found returns false
	static bool ReadBoolFromString(std::string LineString);

	/**Check if LineString Contains SearchedString
	 * @param LineString
	 * @param SearchedString
	 * @return
	 */
	static bool LineStringContains(std::string LineString, std::string SearchedString);

	/** Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
	 * @param LineString @return StringContaining Tabs*/
	static std::string OutputLineStringTabs(std::string LineString);

	//Create TabSpace string based on TabSpace amount
	static std::string CreateTabSpace(int temp);

	/** Use to keep tabs aligned on parameters
	 * @param LineString
	 * @return
	 */
	static std::string OutputQuadVariableLines(std::string LineString);

	/** Returns the filename from a full file-path
	 * @param TempString
	 * @return
	 */
	static std::string SeparateFilePathIntoFileName(std::string TempString);
	/**
	 * @param LineString
	 * @param TargetObject
	 * @return
	 */
	static std::string CreateLinkedHTMLString(std::string LineString, std::string TargetObject);

	/** Remove whitespace from start of line
	 * @param LineString @return String*/
	static std::string RemoveStringTabs(std::string LineString);

	/** Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text
	 * Rounds up partial amount of spaces leftover as being equivalent as another tab
	 * @param LineString
	 * @param TabEquivalent:Amount of spaces is equal to tab
	 * @return
	 */
	static int ExamineTabSpace(std::string LineString, int TabEquivalent);

	/** Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text<br>
	 * Rounds up partial amount of spaces leftover as being equivalent as another tab<br>
	 * This is reduced parameter version of the function that uses Netbeans/Programmer's Notepad equivalent for tabs being 4 spaces<br>
	 * @param LineString
	 * @return
	 */
	static int ExamineTabSpace(std::string LineString);

	/** Removes Specific amount of whitespace from front of LineString
	 * @param LineString
	 * @param TabEquivalent:How much spaces equal to tab(most cases equal to 4)
	 * @param AmountOfWhitespaceRemoval:How many tabs worth of whitespace to remove
	 * @return Line-string minus removed whitespace
	 */
	static std::string RemoveAmountOfTabSpace(std::string LineString, int TabEquivalent, int AmountOfWhitespaceRemoval);

	/** Removes all XML/HTML type tags (Things like<XML Data>) from LineString
	 * @param LineString
	 * @return
	 */
	static std::string RemoveXMLTags(std::string LineString);

	/** Similar to RemoveXMLTags but only returns data after first tag(only gives data for first tag contents)
	 * @param LineString
	 * @return
	 */
	static std::string ReturnXMLTagContent(std::string LineString);

	//Replace first matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
	static std::string ReplaceFirst(std::string LineString, std::string SearchString, std::string ReplacementString);
	//Replace all matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
	static std::string ReplaceAll(std::string LineString, std::string SearchString, std::string ReplacementString);
	//Return ParamName of first <hkparam name="ParamName"> tag; if no name found returns ""
	static std::string ReturnParamName(std::string LineString);
	//************************************
	// Convert Double to String
	// Method:    DoubleToStringConversion
	// FullName:  StringFunctions::DoubleToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: double TempValue
	//************************************
	static std::string DoubleToStringConversion(double TempValue);
	//************************************
	// Convert Int to String
	// Method:    IntToStringConversion
	// FullName:  StringFunctions::IntToStringConversion
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: int TempValue
	//************************************
	static std::string IntToStringConversion(int TempValue);
	static std::string XIntToStringConversion(long long TempValue);
	//************************************
	// Converts Pointer into String Address(Code from http://www.cplusplus.com/forum/general/8597/)
	// Method:    ConvertPointerToStringAddress
	// FullName:  StringFunctions::ConvertPointerToStringAddress
	// Access:    public
	// Returns:   std::string
	// Qualifier:
	// Parameter: const T * obj
	//************************************
	template <typename T>
	std::string ConvertPointerToStringAddress(const T* obj);
	template <typename T>
	std::string ConvertPointerToStringAddressV2(T* obj);
	static uint64_t float_to_double(float value);
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
	static std::string FloatToStringConversion(float TempValue);
	static std::string DisplayFullValues_Vector(float x, float y, float z, float w);
	static std::string DisplayFullValues_Vector(float x, float y, float z);
	static std::string DisplayFullValues_Vector(float x, float y);
	static std::string DisplayFullValues(float x, float y, float z, float w);
	static std::string DisplayFullValues(float x, float y, float z);
	static std::string DisplayFullValues(float x, float y);
	float Int32ToFloat(int32_t Value);
	//************************************
	// Method:    CheckAndCorrectDirectoryLocation
	// FullName:  StringFunctions::CheckAndCorrectDirectoryLocation
	// Access:    public static 
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string Directory
	// Parameter: bool Verbose
	//************************************
	static std::string CheckAndCorrectDirectoryLocation(std::string Directory, bool Verbose=false);
	//************************************
	// Method:    CheckAndCorrectFilepath
	// FullName:  StringFunctions::CheckAndCorrectFilepath
	// Access:    public static 
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string FileName
	// Parameter: bool Verbose
	//************************************
	static std::string CheckAndCorrectFilepath(std::string FileName, bool Verbose=false);
	StringFunctions();
	~StringFunctions();
};
#endif