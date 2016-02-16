/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef BinaryVectorList_IncludeGuard
#define BinaryVectorList_IncludeGuard

#include "VariableList.h"
#include <string>

//Alternative version of StringVectorList that holds Binary data from file instead (Designed of hold Nif File Binary)(Incomplete)
class BinaryVectorList : VariableList<char>
{
public:
	/*//************************************
	//// Alternate Version of SaveDataToFileV2 that creates file if doesn't exist
	//// Method:    SaveDataToFileV3
	//// FullName:  BinaryVectorList::SaveDataToFileV3
	//// Access:    public
	//// Returns:   void
	//// Qualifier:
	//// Parameter: std::string FileName
	////************************************
	void SaveDataToFileV3(std::string FileName);*/
	//Load file data(if ConfigSetting is greater than 0 acts like LoadFileWithoutComments)
	//************************************
	// Method:    LoadFileDataV2
	// FullName:  StringVectorList::LoadFileDataV2
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	// Parameter: unsigned short ConfigSetting
	// Parameter: bool Verbose
	//************************************
	void LoadFileDataV2(std::string FileName, unsigned short ConfigSetting=0, bool Verbose=false);
	BinaryVectorList();
	~BinaryVectorList();
};
#endif
