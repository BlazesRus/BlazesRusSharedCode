/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#pragma once
#ifndef MiscFunctions_IncludeGuard
#define MiscFunctions_IncludeGuard

#include <string>

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

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
#include "VariableList.h"
#include "StringVectorList.h"
#else
#include "..\VariableLists\VariableList.h"
#include "..\VariableLists\StringVectorList.h"
#endif

class DLL_API MiscFunctions
{
public:
	class VariableScanning
	{
	public:
		bool VariableTypeScanned = false;
		bool VariableNameScanned = false;
		std::string VariableTypeName = "";
		std::string VariableName = "";
		// true = LineComments; false = Multi-line comments
		bool LineCommentType = false;
		bool ScanningComments = false;
		std::string CommentStringBuffer;
		size_t TabLevel = 0;
		size_t StringLength;
		size_t TempInt;
		char StringChar;
		bool DisplayCommentsToConsole = true;
		bool SaveCommentData = true;
		std::string CommentDataString = "";
		StringVectorList CommentDataBuffer;
		//CommentData is sent here when sending variable data
		StringVectorList LinkedCommentData;
		bool CreateGetFunctions = false;
		StringVectorList VariableNameList;
		StringVectorList VariableTypeList;
		std::string ReconstructVariableAssignment(std::string Name, std::string Type);
		void CreateFileWithVariableData(std::string FileName);
		void SendVariableAssignmentInfo();
		void ScanData(std::string LineString);
	};
	//************************************
	// Method:    FindWrappedText
	// FullName:  MiscFunctions::FindWrappedText
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string SearchedString
	//************************************
	static bool FindWrappedText(std::string LineString, std::string SearchedString);
	//************************************
	// Method:    TextNotFound
	// FullName:  MiscFunctions::TextNotFound
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string LineString
	// Parameter: std::string SearchedString
	//************************************
	static bool TextNotFound(std::string LineString, std::string SearchedString);
	//************************************
	// Method:    RearrangedVariableDataFromFile
	// FullName:  MiscFunctions::RearrangedVariableDataFromFile
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string FileName
	// Parameter: std::string OutputFileName
	//************************************
	static bool RearrangedVariableDataFromFile(std::string FileName, std::string OutputFileName);
	//************************************
	// Method:    ConvertFileToString
	// FullName:  MiscFunctions::ConvertFileToString
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	static std::string ConvertFileToString(std::string FileName);
	//************************************
	// Method:    ConvertStringToFile
	// FullName:  MiscFunctions::ConvertStringToFile
	// Access:    public static
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	// Parameter: std::string TargetString
	//************************************
	static void ConvertStringToFile(std::string FileName, std::string TargetString);
	//************************************
	// Method:    IsRecordedHavokClassType
	// FullName:  MiscFunctions::IsRecordedHavokClassType
	// Access:    public static
	// Returns:   bool
	// Qualifier:
	// Parameter: std::string HavokClass
	//************************************
	static bool IsRecordedHavokClassType(std::string HavokClass);
	//************************************
	// Method:    ExtractFirstTagContents
	// FullName:  MiscFunctions::ExtractFirstTagContents
	// Access:    public static
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	static std::string ExtractFirstTagContents(std::string LineString);
	//Removes extra spacing,tabs, and new lines between characters
	static std::string RemoveExcessSpacing(std::string LineString);
	//Near Text match of text that ignores extra spacing/tabs separating text
	static bool FindTextWithNearMatch(std::string LineString, std::string SearchedString);
	//************************************
	// Method:    RetrieveTopLevelObjectFromString
	// FullName:  MiscFunctions::RetrieveTopLevelObjectFromString
	// Access:    public
	// Returns:   std::string
	// Qualifier:
	// Parameter: std::string LineString
	//************************************
	std::string RetrieveTopLevelObjectFromString(std::string LineString);
	MiscFunctions();
	~MiscFunctions();
};
#endif
