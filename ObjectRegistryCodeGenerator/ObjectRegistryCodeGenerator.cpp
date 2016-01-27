#include <string>
#include <iostream>
#include "StringVectorList.h"

int main(int ConsoleParamNumber, char *CommandArgs [])
{
	StringVectorList LoadedFile;
	if(ConsoleParamNumber == 2)
	{
		const std::string Command(CommandArgs[1]);
		std::cout << "FilePath:" << Command << "\n";
		LoadedFile.LoadFileDataV2(Command);
	}
	else
	{
		std::cout << "No File Loaded";
		//LoadedFile;
		//system("pause");
	}
	//File Created for ObjectRegistryClasses
	StringVectorList CraftedFile01;
	//File Created for ObjectRegistry
	StringVectorList CraftedFile02;
	std::string LineString;
	std::string TempString;
	const size_t FileSize = LoadedFile.Size();
	std::cout << "LinesLoaded:" << FileSize << "\n";//Debug check to make sure loaded file
	for(size_t LineNumber=0; LineNumber < FileSize;++LineNumber)
	{
		LineString = LoadedFile.ElementAt(LineNumber);
		TempString = "class ";
		TempString += LineString;
		TempString += " : public ";
		TempString += "NifNode,Niflib::";
		TempString += LineString;
		TempString += "{};";
		CraftedFile01.Add(TempString);
		TempString = "class ";
		TempString += LineString;
		TempString += "_Storage : public ObjectStorage <";
		TempString += LineString;
		TempString += "> {};";
		CraftedFile01.Add(TempString);
		TempString = "ObjectRegistryClasses::";
		TempString += LineString;
		TempString += "_Storage ";
		TempString += LineString;
		TempString += "_Registry;";
		CraftedFile02.Add(TempString);
	}
	CraftedFile01.SaveDataToFileV3("ObjectRegistryClasses.txt");
	CraftedFile02.SaveDataToFileV3("ObjectRegistry.txt");
	system("pause");
}