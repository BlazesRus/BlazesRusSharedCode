/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/
#ifdef BlazesGlobalCode_UsePreprocessor
#ifdef BlazesGlobalCode_LocalLayout
	#include "stdafx.h"
#else
	#include "..\stdafx.h"
#endif
#endif

#pragma once
#ifndef MiscFunctions_IncludeGuard
#define MiscFunctions_IncludeGuard

#include "VariableTypeLists.h"
#include <string>

//Inside this ifdef block holds GlobalCode Environment library version of header structure (preprocessor defined inside all GlobalCode library configs)
#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
//Local Version of headers here(within else block)
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
#ifndef DLL_API
#define DLL_API
#endif
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
