/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#pragma once

#include "VariableList.h"
#include <string>

class StringVectorList : public VariableList < std::string >
{
private:
	//	bool FileStreamOpen = false;
public:
	//************************************
	// Alternate Version of SaveDataToFileV2 that creates file if doesn't exist
	// Method:    SaveDataToFileV3
	// FullName:  StringVectorList::SaveDataToFileV3
	// Access:    public
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	void SaveDataToFileV3(std::string FileName);
	//************************************
	// Attempt to workaround the rare case of the Link2001 Error (essentially the same as SaveDataToFile but more directly coded)
	// Method:    SaveDataToFileV2
	// FullName:  StringVectorList::SaveDataToFileV2
	// Access:    public
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	void SaveDataToFileV2(std::string FileName);
	//Link2001 Error found in one case
	void SaveDataToFile(std::string FileName);
	//Function Designed to be overwritten to use Loaded File Data
	bool ScanData(std::string LineString);
	//Load XML format file data without Comments stored
	void LoadXMLFileWithoutComments(std::string InputFile);
	//Load file data
	bool LoadFileData(std::string FileName);
	//Load additional file data into StringVectorList
	bool AddFileData(std::string FileName);
	//Load file data without XML/C++ style comments stored
	void LoadFileWithoutComments(std::string InputFile);
	//Load file data(if ConfigSetting is greater than 0 acts like LoadFileWithoutComments)
	void LoadFileDataV2(std::string FileName, unsigned short ConfigSetting=0);
	std::string ConvertToString();
	int AddData();
};