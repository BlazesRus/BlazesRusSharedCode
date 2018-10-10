/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef StringFunctions_IncludeGuard
#define StringFunctions_IncludeGuard

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

class DLL_API StringFunctions
{
public:
	//************************************
	// Method:    AddStringInFront
	// FullName:  StringFunctions::AddStringInFront
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string ValueAdded
	// Parameter: std::string TargetString
	//************************************
	static std::string AddStringInFront(std::string ValueAdded, std::string TargetString);
	//************************************
	// Method:    AddStringInFront
	// FullName:  StringFunctions::AddStringInFront
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: char ValueAdded
	// Parameter: std::string TargetString
	//************************************
	static std::string AddStringInFront(char ValueAdded, std::string TargetString);
	//************************************
	// Check if LineString Contains SearchedString
	// Method:    LineStringContains
	// FullName:  StringFunctions::LineStringContains
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string SearchedString
	//************************************
	static bool LineStringContains(std::string LineString, std::string SearchedString);
	//************************************
	// Use to keep tabs aligned on parameters(tab is equal to 4 spaces)
	// Method:    OutputLineStringTabs
	// FullName:  StringFunctions::OutputLineStringTabs
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string OutputLineStringTabs(std::string LineString);
	//************************************
	//Create TabSpace string based on TabSpace amount
	// Method:    CreateTabSpace
	// FullName:  StringFunctions::CreateTabSpace
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: size_t temp
	//************************************
	static std::string CreateTabSpace(size_t temp);
	//************************************
	// Use to keep tabs aligned on parameters
	// Method:    OutputQuadVariableLines
	// FullName:  StringFunctions::OutputQuadVariableLines
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string OutputQuadVariableLines(std::string LineString);
	//************************************
	// Returns the filename from a full file-path
	// Method:    SeparateFilePathIntoFileName
	// FullName:  StringFunctions::SeparateFilePathIntoFileName
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string TempString
	//************************************
	static std::string SeparateFilePathIntoFileName(std::string TempString);
	//************************************
	// Method:    CreateLinkedHTMLString
	// FullName:  StringFunctions::CreateLinkedHTMLString
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string TargetObject
	//************************************
	static std::string CreateLinkedHTMLString(std::string LineString, std::string TargetObject);
	//************************************
	//Remove whitespace from start of line
	// Method:    RemoveStringTabs
	// FullName:  StringFunctions::RemoveStringTabs
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string RemoveStringTabs(std::string LineString);
	//************************************
	// Examines the number of tabs/(equivalent of tabs in spaces) of whitespace before text (TabEquivalent=Amount of spaces is equal to tab)
	// Method:    ExamineTabSpace
	// FullName:  StringFunctions::ExamineTabSpace
	// Access:    public static
	// Returns:   size_t
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: int TabEquivalent
	//************************************
	static size_t ExamineTabSpace(std::string LineString, int TabEquivalent);
	//************************************
	//	Examines the number of tabs / (equivalent of tabs in spaces) of whitespace before text
	//	Rounds up partial amount of spaces leftover as being equivalent as another tab
	//	This is reduced parameter version of the function that uses Netbeans / Programmer's Notepad equivalent for tabs being 4 spaces
	// Method:    ExamineTabSpace
	// FullName:  StringFunctions::ExamineTabSpace
	// Access:    public static
	// Returns:   size_t
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static size_t ExamineTabSpace(std::string LineString);
	//************************************
	// Removes Specific amount of whitespace from front of LineString(AmountOfWhitespaceRemoval=How many tabs worth of whitespace to remove)
	// Method:    RemoveAmountOfTabSpace
	// FullName:  StringFunctions::RemoveAmountOfTabSpace
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: int TabEquivalent
	// Parameter: int AmountOfWhitespaceRemoval
	//************************************
	static std::string RemoveAmountOfTabSpace(std::string LineString, int TabEquivalent, int AmountOfWhitespaceRemoval);
	//************************************
	// Removes all XML/HTML type tags (Things like<XML Data>) from LineString
	// Method:    RemoveXMLTags
	// FullName:  StringFunctions::RemoveXMLTags
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string RemoveXMLTags(std::string LineString);
	//************************************
	// Similar to RemoveXMLTags but only returns data after first tag(only gives data for first tag contents)
	// Method:    ReturnXMLTagContent
	// FullName:  StringFunctions::ReturnXMLTagContent
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string ReturnXMLTagContent(std::string LineString);
	//Replace first matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
	//************************************
	// Method:    ReplaceFirst
	// FullName:  StringFunctions::ReplaceFirst
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string SearchString
	// Parameter: std::string ReplacementString
	//************************************
	static std::string ReplaceFirst(std::string LineString, std::string SearchString, std::string ReplacementString);
	//Replace all matching of SearchString inside LineString with ReplacementString (Functions similar to Java version of same function)
	//************************************
	// Method:    ReplaceAll
	// FullName:  StringFunctions::ReplaceAll
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string SearchString
	// Parameter: std::string ReplacementString
	//************************************
	static std::string ReplaceAll(std::string LineString, std::string SearchString, std::string ReplacementString);
	//Return ParamName of first <hkparam name="ParamName"> tag; if no name found returns ""
	//************************************
	// Method:    ReturnParamName
	// FullName:  StringFunctions::ReturnParamName
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string ReturnParamName(std::string LineString);
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
	static std::string ConvertPointerToStringAddress(const T* obj);
	//************************************
	// Method:    ConvertPointerToStringAddressV2
	// FullName:  StringFunctions::ConvertPointerToStringAddressV2
	// Access:    public
	// Returns:   std::string
	// Qualifier:
	// Parameter: T * obj
	//************************************
	template <typename T>
	static std::string ConvertPointerToStringAddressV2(T* obj);
	//************************************
	// Method:    CheckAndCorrectDirectoryLocation
	// FullName:  StringFunctions::CheckAndCorrectDirectoryLocation
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string Directory
	// Parameter: bool Verbose
	//************************************
	static std::string CheckAndCorrectDirectoryLocation(std::string Directory, bool Verbose = false);
	//************************************
	// Method:    CheckAndCorrectFilepath
	// FullName:  StringFunctions::CheckAndCorrectFilepath
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string FileName
	// Parameter: bool Verbose
	//************************************
	static std::string CheckAndCorrectFilepath(std::string FileName, bool Verbose = false);
	//************************************
	// Reads String to predict ContentType (Refer to TagNodeTreeTemplate for ContentType values)
	// Method:    FindContentType
	// FullName:  StringFunctions::FindContentType
	// Access:    public static
	// Returns:   unsigned __int8
	// Qualifier:
	// Parameter: std::string Content
	//************************************
	static unsigned __int8 FindContentType(std::string Content);

//	/// <summary>
//	/// Converts from LPCTSTR to std::string
//	/// </summary>
//	/// <param name="value">The value.</param>
//	/// <param name="cp">The codepage.Default to (UTF-16 codepage = 1200)(https://docs.microsoft.com/en-us/windows/desktop/Intl/code-page-identifiers)</param>
//	/// <returns></returns>
//	static std::string ConvertFromPString(LPCTSTR value, UINT cp = 1200)
//	{
//#ifdef _UNICODE//https://stackoverflow.com/questions/5513718/how-do-i-convert-from-lpctstr-to-stdstring
//		if(value==nullptr)
//		{
//			return "";
//		}
//		else
//		{
//			int cch = WideCharToMultiByte(cp, WC_NO_BEST_FIT_CHARS, value, -1, 0, 0, NULL, NULL);//Default of dw field of 0 switching to WC_NO_BEST_FIT_CHARS since likely to deal with filenames
//			char* psz = new char[cch];
//
//			WideCharToMultiByte(cp, WC_NO_BEST_FIT_CHARS, value, -1, psz, cch, NULL, NULL);
//
//			std::string st(psz);
//			delete[] psz;
//
//			return st;
//		}
//#else
//		return std::string(str);
//#endif
//	}
};
#endif
