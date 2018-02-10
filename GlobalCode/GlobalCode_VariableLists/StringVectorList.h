/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef StringVectorList_IncludeGuard
#define StringVectorList_IncludeGuard

#ifndef BlazesGlobalCode_FileStructureVersion
	#define BlazesGlobalCode_FileStructureVersion 0
	//FileStructureVersion 0 = Refers to required files set up similar/same as Library Versions of files
	//FileStructureVersion 1 = All required files from GlobalCode within same folder locally
#endif

#ifdef BLAZESGLOBALCODE_LIBRARY
	#include "..\DLLAPI.h"
#else
//Dummy define of DLL_API to prevent requiring 2 separate Defines of initial class headers(without needing the DLL_API define)
	#ifndef DLL_API
		#define DLL_API
	#endif
#endif

#include "VariableList.h"
#include <string>

class DLL_API StringVectorList : public VariableList < std::string >
{
private:
	//	bool FileStreamOpen = false;
public:
	//************************************
	// Method:    CreateFileIfDoesntExist
	// FullName:  StringVectorList::CreateFileIfDoesntExist
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	void CreateFileIfDoesntExist(std::string FileName);
	//************************************
	// Alternate Version of SaveDataToFileV2 that creates file if doesn't exist
	// Method:    SaveDataToFileV3
	// FullName:  StringVectorList::SaveDataToFileV3
	// Access:    public
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	void SaveDataToFileV3(std::string FileName, bool Verbose=false);
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
	std::string ConvertToString();
	size_t AddData();
	//************************************
	// Method:    ConvertStringToStringVectorList
	// FullName:  StringVectorList::ConvertStringToStringVectorList
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: std::string Content
	//************************************
	void ConvertStringToStringVectorList(std::string Content);
};
#endif