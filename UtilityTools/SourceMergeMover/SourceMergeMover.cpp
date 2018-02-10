// SourceMergeMover.cpp : Defines the entry point for the console application.
//

//#include <cstdlib>
#include <stdio.h>
#include "StringVectorList.h"
#include "MiscFunctions.h"
#include <iostream>
#include "StringFunctions.h"
#include <string>
#include "IniData.h"

void CreateFilePathData(StringVectorList& LocalFileNames, std::string DirectoryForCopy, std::string TargetDirectory, StringVectorList& FilesToMove, StringVectorList& TargetFileLocations)
{
	std::string FileTarget;
	std::string LineString;
	for(unsigned int Index = 0; Index < LocalFileNames.Size(); ++Index)
	{
		LineString = LocalFileNames.ElementAt(Index);
		FileTarget = DirectoryForCopy;
		FileTarget += LineString;
		FilesToMove.Add(FileTarget);
		FileTarget = TargetDirectory;
		FileTarget += LineString;
		TargetFileLocations.Add(FileTarget);
	}
}

void AddTargetUniqueFileData(StringVectorList& FileTargetNames, StringVectorList& FileTargetNames02, std::string DirectoryForCopy, std::string TargetDirectory, StringVectorList& FilesToMove, StringVectorList& TargetFileLocations)
{
	std::string LineString;
	std::string FileTarget;
	IntegerList ElementsToRemove;
	size_t ElementIndex;
	for(size_t Index = 0; FileTargetNames.StreamLineData(); Index++)
	{
		LineString = FileTargetNames.CurrentStreamedLineString();
		ElementIndex = FileTargetNames02.GetElementIndex(LineString);
		if(ElementIndex != -1)
		{
			//Remove Elements after done comparing StringLists to prevent any annoying element changes in Elements
			ElementsToRemove.Add(Index);
		}
	}
	for(size_t Index = 0; ElementsToRemove.StreamLineData(); Index++)
	{
		ElementIndex = ElementsToRemove.CurrentStreamedLineString();
		FileTargetNames.RemoveElement(ElementIndex);
	}
	for(size_t Index = 0; FileTargetNames.StreamLineData(); Index++)
	{
		LineString = FileTargetNames.CurrentStreamedLineString();
		FileTarget = DirectoryForCopy;
		FileTarget += LineString;
		FilesToMove.Add(FileTarget);
		FileTarget = TargetDirectory;
		FileTarget += LineString;
		TargetFileLocations.Add(FileTarget);
	}
}

void AddRobocopyLine(StringVectorList LocalFileNames, std::string DirectoryForCopy, std::string TargetDirectory, StringVectorList& BatDataFile)
{
	std::string FileTarget;
	std::string LineString;
	for(size_t Index = 0; Index < LocalFileNames.Size(); ++Index)
	{
		LineString = LocalFileNames.ElementAt(Index);
		FileTarget = "ROBOCOPY \"";
		FileTarget += (DirectoryForCopy + "\" \"");
		FileTarget += (TargetDirectory + "\" \"");
		FileTarget += LineString;
		FileTarget += "\" /b";
	}
}

int main(int ConsoleParamNumber, char *CommandArgs [])
{
	IniData TargetSettingsIni;
	if(ConsoleParamNumber==2)
	{
		const std::string Command(CommandArgs[1]);
		std::cout << "FilePath:" << Command<<"\n";
		TargetSettingsIni.LoadIniData(Command);
		system("pause");
	}
	else
	{
		const std::string TargetSettingsPath = "TargetSettings.txt";
		TargetSettingsIni.LoadIniData(TargetSettingsPath);
	}
	const std::string ListOfFilesToMerge_IncludeGen = TargetSettingsIni.CheckIfElementExists("ListOfFilesToMerge_IncludeGen") ? TargetSettingsIni.GetElementData("ListOfFilesToMerge_IncludeGen"):"IncludesToMergeGen.txt";
	const std::string ListOfFilesToMerge_IncludeObj = TargetSettingsIni.CheckIfElementExists("ListOfFilesToMerge_IncludeObj") ? TargetSettingsIni.GetElementData("ListOfFilesToMerge_IncludeObj"): "IncludesToMergeObj.txt";
	const std::string DirectoryForCopy_IncludeGen = TargetSettingsIni.CheckIfElementExists("DirectoryForCopy_IncludeGen") ? TargetSettingsIni.GetElementData("DirectoryForCopy_IncludeGen"): "";
	const std::string DirectoryForCopy_IncludeObj = TargetSettingsIni.CheckIfElementExists("DirectoryForCopy_IncludeObj") ? TargetSettingsIni.GetElementData("DirectoryForCopy_IncludeObj"): "";
	const std::string TargetDirectory_IncludeGen = TargetSettingsIni.CheckIfElementExists("TargetDirectory_IncludeGen") ? TargetSettingsIni.GetElementData("TargetDirectory_IncludeGen"): "";
	const std::string TargetDirectory_IncludeObj = TargetSettingsIni.CheckIfElementExists("TargetDirectory_IncludeObj") ? TargetSettingsIni.GetElementData("TargetDirectory_IncludeObj"): "";
	const std::string ListOfFilesToMerge_SourceGen = TargetSettingsIni.CheckIfElementExists("ListOfFilesToMerge_SourceGen") ? TargetSettingsIni.GetElementData("ListOfFilesToMerge_SourceGen"): "";
	const std::string ListOfFilesToMerge_SourceObj = TargetSettingsIni.CheckIfElementExists("ListOfFilesToMerge_SourceObj") ? TargetSettingsIni.GetElementData("ListOfFilesToMerge_SourceObj"): "";
	const std::string DirectoryForCopy_SourceGen = TargetSettingsIni.CheckIfElementExists("DirectoryForCopy_SourceGen") ? TargetSettingsIni.GetElementData("DirectoryForCopy_SourceGen"): "";
	const std::string DirectoryForCopy_SourceObj = TargetSettingsIni.CheckIfElementExists("DirectoryForCopy_SourceObj") ? TargetSettingsIni.GetElementData("DirectoryForCopy_SourceObj"): "";
	const std::string TargetDirectory_SourceGen = TargetSettingsIni.CheckIfElementExists("TargetDirectory_SourceGen") ? TargetSettingsIni.GetElementData("TargetDirectory_SourceGen"): "";
	const std::string TargetDirectory_SourceObj = TargetSettingsIni.CheckIfElementExists("TargetDirectory_SourceObj") ? TargetSettingsIni.GetElementData("TargetDirectory_SourceObj"): "";
	const std::string BranchList01_IncludeGen = TargetSettingsIni.CheckIfElementExists("BranchList01_IncludeGen") ? TargetSettingsIni.GetElementData("BranchList01_IncludeGen"): "";
	const std::string BranchList01_IncludeObj = TargetSettingsIni.CheckIfElementExists("BranchList01_IncludeObj") ? TargetSettingsIni.GetElementData("BranchList01_IncludeObj"): "";
	const std::string BranchList01_SourceGen = TargetSettingsIni.CheckIfElementExists("BranchList01_SourceGen") ? TargetSettingsIni.GetElementData("BranchList01_SourceGen"): "";
	const std::string BranchList01_SourceObj = TargetSettingsIni.CheckIfElementExists("BranchList01_SourceObj") ? TargetSettingsIni.GetElementData("BranchList01_SourceObj"): "";
	const std::string TargetUniqueFilesDirectory_IncludeGen = TargetSettingsIni.CheckIfElementExists("TargetUniqueFilesDirectory_IncludeGen") ? TargetSettingsIni.GetElementData("TargetUniqueFilesDirectory_IncludeGen"): "";
	const std::string TargetUniqueFilesDirectory_IncludeObj = TargetSettingsIni.CheckIfElementExists("TargetUniqueFilesDirectory_IncludeObj") ? TargetSettingsIni.GetElementData("TargetUniqueFilesDirectory_IncludeObj"): "";
	const std::string TargetUniqueFilesDirectory_SourceGen = TargetSettingsIni.CheckIfElementExists("TargetUniqueFilesDirectory_SourceGen") ? TargetSettingsIni.GetElementData("TargetUniqueFilesDirectory_SourceGen"): "";
	const std::string TargetUniqueFilesDirectory_SourceObj = TargetSettingsIni.CheckIfElementExists("TargetUniqueFilesDirectory_SourceObj") ? TargetSettingsIni.GetElementData("TargetUniqueFilesDirectory_SourceObj"): "";
	const std::string BranchList02_IncludeGen = TargetSettingsIni.CheckIfElementExists("BranchList02_IncludeGen") ? TargetSettingsIni.GetElementData("BranchList02_IncludeGen"): "";
	const std::string BranchList02_IncludeObj = TargetSettingsIni.CheckIfElementExists("BranchList02_IncludeObj") ? TargetSettingsIni.GetElementData("BranchList02_IncludeObj"): "";
	const std::string BranchList02_SourceGen = TargetSettingsIni.CheckIfElementExists("BranchList02_SourceGen") ? TargetSettingsIni.GetElementData("BranchList02_SourceGen"): "";
	const std::string BranchList02_SourceObj = TargetSettingsIni.CheckIfElementExists("BranchList02_SourceObj") ? TargetSettingsIni.GetElementData("BranchList02_SourceObj"): "";
	system("pause");
	//Perform folder checks
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetDirectory_IncludeGen,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetUniqueFilesDirectory_IncludeGen,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(DirectoryForCopy_IncludeObj,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetDirectory_IncludeObj,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetUniqueFilesDirectory_IncludeObj,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(DirectoryForCopy_SourceGen,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetDirectory_SourceGen,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetUniqueFilesDirectory_SourceGen,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(DirectoryForCopy_SourceObj,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetDirectory_SourceObj,true);
	StringFunctions::CheckAndCorrectDirectoryLocation(TargetUniqueFilesDirectory_SourceObj,true);
	system("pause");
	system("cls");
	//Perform Filepath checks
	//StringFunctions::CheckAndCorrectFilepath("IncludesToMergeGen.txt",true);//Working
	//system("pause");
	StringFunctions::CheckAndCorrectFilepath(BranchList01_IncludeGen,true);
	StringFunctions::CheckAndCorrectFilepath(BranchList01_IncludeObj,true);
	StringFunctions::CheckAndCorrectFilepath(BranchList01_SourceGen,true);
	StringFunctions::CheckAndCorrectFilepath(BranchList01_SourceObj,true);
	StringFunctions::CheckAndCorrectFilepath(BranchList02_IncludeGen, true);
	StringFunctions::CheckAndCorrectFilepath(BranchList02_IncludeObj, true);
	StringFunctions::CheckAndCorrectFilepath(BranchList02_SourceGen, true);
	StringFunctions::CheckAndCorrectFilepath(BranchList02_SourceObj, true);
	StringFunctions::CheckAndCorrectFilepath(TargetUniqueFilesDirectory_IncludeGen, true);
	StringFunctions::CheckAndCorrectFilepath(TargetUniqueFilesDirectory_IncludeObj, true);
	StringFunctions::CheckAndCorrectFilepath(TargetUniqueFilesDirectory_SourceGen, true);
	StringFunctions::CheckAndCorrectFilepath(TargetUniqueFilesDirectory_SourceObj, true);
	StringFunctions::CheckAndCorrectFilepath(ListOfFilesToMerge_IncludeGen, true);
	StringFunctions::CheckAndCorrectFilepath(ListOfFilesToMerge_IncludeObj, true);
	StringFunctions::CheckAndCorrectFilepath(ListOfFilesToMerge_SourceGen, true);
	StringFunctions::CheckAndCorrectFilepath(ListOfFilesToMerge_SourceObj, true);
	system("pause");
	system("cls");
	//Now perform stuff with directory info
	StringVectorList LocalFileNames;
	StringVectorList FilesToMove;
	StringVectorList TargetFileLocations;
	//Create bat file with Robocopy commands for files
	StringVectorList BatDataFile;
	LocalFileNames.LoadFileDataV2(ListOfFilesToMerge_IncludeGen);
	CreateFilePathData(LocalFileNames, DirectoryForCopy_IncludeGen, TargetDirectory_IncludeGen, FilesToMove, TargetFileLocations);
	AddRobocopyLine(LocalFileNames, DirectoryForCopy_IncludeGen, TargetDirectory_IncludeGen, BatDataFile);
	LocalFileNames.LoadFileDataV2(ListOfFilesToMerge_IncludeObj);
	CreateFilePathData(LocalFileNames, DirectoryForCopy_IncludeObj, TargetDirectory_IncludeObj, FilesToMove, TargetFileLocations);
	AddRobocopyLine(LocalFileNames, DirectoryForCopy_IncludeObj, TargetDirectory_IncludeObj, BatDataFile);
	LocalFileNames.LoadFileDataV2(ListOfFilesToMerge_SourceGen);
	CreateFilePathData(LocalFileNames, DirectoryForCopy_SourceGen, TargetDirectory_SourceGen, FilesToMove, TargetFileLocations);
	AddRobocopyLine(LocalFileNames, DirectoryForCopy_SourceGen, TargetDirectory_SourceGen, BatDataFile);
	LocalFileNames.LoadFileDataV2(ListOfFilesToMerge_SourceObj);
	CreateFilePathData(LocalFileNames, DirectoryForCopy_SourceObj, TargetDirectory_SourceObj, FilesToMove, TargetFileLocations);
	AddRobocopyLine(LocalFileNames, DirectoryForCopy_SourceObj, TargetDirectory_SourceObj, BatDataFile);
	//Now create bat lines for copying Unique files
	StringVectorList FileTargetNames;
	StringVectorList FileTargetNames02;
	StringVectorList UniqueFileTargets;
	StringVectorList UniqueFileTarget_CopyLocations;
	FileTargetNames.LoadFileDataV2(BranchList02_IncludeGen);
	FileTargetNames02.LoadFileDataV2(BranchList01_IncludeGen);
	AddTargetUniqueFileData(FileTargetNames, FileTargetNames02, DirectoryForCopy_IncludeGen, TargetUniqueFilesDirectory_IncludeGen, UniqueFileTargets, UniqueFileTarget_CopyLocations);
	AddRobocopyLine(FileTargetNames, DirectoryForCopy_IncludeGen, TargetUniqueFilesDirectory_IncludeGen, BatDataFile);
	FileTargetNames.LoadFileDataV2(BranchList02_IncludeObj);
	FileTargetNames02.LoadFileDataV2(BranchList01_IncludeObj);
	AddTargetUniqueFileData(FileTargetNames, FileTargetNames02, DirectoryForCopy_IncludeGen, TargetUniqueFilesDirectory_IncludeObj, UniqueFileTargets, UniqueFileTarget_CopyLocations);
	AddRobocopyLine(FileTargetNames, DirectoryForCopy_IncludeObj, TargetUniqueFilesDirectory_IncludeObj, BatDataFile);
	FileTargetNames.LoadFileDataV2(BranchList02_SourceGen);
	FileTargetNames02.LoadFileDataV2(BranchList01_SourceGen);
	AddTargetUniqueFileData(FileTargetNames, FileTargetNames02, DirectoryForCopy_IncludeGen, TargetUniqueFilesDirectory_SourceGen, UniqueFileTargets, UniqueFileTarget_CopyLocations);
	AddRobocopyLine(FileTargetNames, DirectoryForCopy_SourceGen, TargetUniqueFilesDirectory_SourceGen, BatDataFile);
	FileTargetNames.LoadFileDataV2(BranchList02_SourceObj);
	FileTargetNames02.LoadFileDataV2(BranchList01_SourceObj);
	AddTargetUniqueFileData(FileTargetNames, FileTargetNames02, DirectoryForCopy_IncludeGen, TargetUniqueFilesDirectory_SourceObj, UniqueFileTargets, UniqueFileTarget_CopyLocations);
	AddRobocopyLine(FileTargetNames, DirectoryForCopy_SourceObj, TargetUniqueFilesDirectory_SourceObj, BatDataFile);
	//Now copy FilesToMove to TargetFileLocations
	BatDataFile.SaveDataToFileV3("MoveSourceCode.bat");
	system("pause");
}