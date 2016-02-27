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
	//File Created for Create Node lines data (lines of code for NifNodeTree::AddNodeToTree)
	StringVectorList CraftedFile03;
	//File Created for Destroying Actual NodeData
	StringVectorList CraftedFile04;
	//File Created for NifNodeTree::CopyNodeToTree
	StringVectorList CraftedFile05;
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
		TempString += "NifNode, public Niflib::";
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
		TempString = "if(TargetNodeType == ";
		TempString += "\"";
		TempString += LineString;
		TempString += "\")";
		CraftedFile03.Add(TempString);
		CraftedFile03.Add("{");
		TempString = "\tIndex = TargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.AddData();";
		CraftedFile03.Add(TempString);
		TempString = "\tTargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;";
		CraftedFile03.Add(TempString);
		CraftedFile03.Add("}");
		TempString = "if(NodeType == ";
		TempString += "\"";
		TempString += LineString;
		TempString += "\")";
		CraftedFile04.Add(TempString);
		CraftedFile04.Add("{");
		TempString = "\tTargetObjectRegistry->";
		TempString += LineString;
		TempString += "_Registry.Remove(IndexInRegistry);";
		CraftedFile04.Add(TempString);
		CraftedFile04.Add("}");
		TempString = "if(TargetNodeType == ";
		TempString += "\"";
		TempString += LineString;
		TempString += "\")";
		CraftedFile05.Add(TempString);
		CraftedFile05.Add("{");
		TempString = "\tIndex = TargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.AddDataCopy(TargetNode);";
		CraftedFile05.Add(TempString);
		TempString = "\tTargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.GetElementPointerV2(Index)->InternalName = CurrentNode->InternalName;";
		CraftedFile05.Add(TempString);
		CraftedFile05.Add("}");
	}
	CraftedFile01.SaveDataToFileV3("ObjectRegistryClasses.txt");
	CraftedFile02.SaveDataToFileV3("ObjectRegistry.txt");
	CraftedFile03.SaveDataToFileV3("GenerateNodeLines.txt");
	CraftedFile04.SaveDataToFileV3("DestroyActualNodeLines.txt");
	CraftedFile05.SaveDataToFileV3("CopyNodeToTree.txt");
	system("pause");
}