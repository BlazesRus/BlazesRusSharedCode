/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#pragma once

#include "..\GlobalCode\VariableTypeLists.h"
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
		string VariableName = "";
		// true = LineComments; false = Multi-line comments
		bool LineCommentType = false;
		bool ScanningComments = false;
		string CommentStringBuffer;
		int TabLevel = 0;
		int StringLength;
		int TempInt;
		char StringChar;
		bool DisplayCommentsToConsole = true;
		bool SaveCommentData = true;
		string CommentDataString = "";
		StringVectorList CommentDataBuffer;
		//CommentData is sent here when sending variable data
		StringVectorList LinkedCommentData;
		bool CreateGetFunctions = false;
		StringVectorList VariableNameList;
		StringVectorList VariableTypeList;
		string ReconstructVariableAssignment(string Name, string Type);
		void CreateFileWithVariableData(string FileName);
		void SendVariableAssignmentInfo();
		void ScanData(string LineString);
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
