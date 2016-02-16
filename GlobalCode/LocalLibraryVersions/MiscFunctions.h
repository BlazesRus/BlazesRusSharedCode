/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef MiscFunctions_IncludeGuard
#define MiscFunctions_IncludeGuard

#include "VariableTypeLists.h"
#include <string>

class MiscFunctions
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
	static bool FindWrappedText(std::string LineString, std::string SearchedString);
	static bool TextNotFound(std::string LineString, std::string SearchedString);
	static bool RearrangedVariableDataFromFile(std::string FileName, std::string OutputFileName);
	static std::string ConvertFileToString(std::string FileName);
	static void ConvertStringToFile(std::string FileName, std::string TargetString);
	static bool IsRecordedHavokClassType(std::string HavokClass);
	static std::string ExtractFirstTagContents(std::string LineString);
	//Removes extra spacing,tabs, and new lines between characters
	static std::string RemoveExcessSpacing(std::string LineString);
	//Near Text match of text that ignores extra spacing/tabs separating text
	static bool FindTextWithNearMatch(std::string LineString, std::string SearchedString);
	std::string RetrieveTopLevelObjectFromString(std::string LineString);
	MiscFunctions();
	~MiscFunctions();
};
#endif