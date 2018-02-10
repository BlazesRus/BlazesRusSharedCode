#include <string>
#include <iostream>
#include "StringVectorList.h"

namespace CodeTestingSpace
{
	bool DetectIfFunctionExists()
	{
		bool FunctionDetected = false;
		return FunctionDetected;
	}
};



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
	//Reset ObjectRegistry
	StringVectorList CraftedFile06;
	//Using statements for ObjectRegistryNodes (Create aliases to reference the niflib and ObjectRegistry classes) 
	StringVectorList CraftedFile07;
	//Read Object Lines
	StringVectorList CraftedFile08;
	//RetrieveInternalNames
	StringVectorList CraftedFile09;
	std::string LineString;
	std::string TempString;
	const size_t FileSize = LoadedFile.Size();
	std::cout << "LinesLoaded:" << FileSize << "\n";//Debug check to make sure loaded file
	for(size_t LineNumber=0; LineNumber < FileSize;++LineNumber)
	{
		LineString = LoadedFile.ElementAt(LineNumber);
		TempString = "using ";
		TempString += LineString;
		TempString += " = Niflib::";
		TempString += LineString;
		TempString += ";";
		CraftedFile01.Add(TempString);
		TempString = "class DLL_API ";
		TempString += LineString;
		TempString += "Node : public BasicNode <";
		TempString += LineString;
		TempString += "> {};";
		CraftedFile01.Add(TempString);
		TempString = "class DLL_API ";
		TempString += LineString;
		TempString += "_Storage : public ObjectStorage <";
		TempString += LineString;
		TempString += "Node> {};";
		CraftedFile01.Add(TempString);
		TempString = "ObjectRegistryClasses::";
		TempString += LineString;
		TempString += "_Storage ";
		TempString += LineString;
		TempString += "_Registry;";
		CraftedFile02.Add(TempString);
		TempString += "if(TargetNodeType == ";
		TempString += "\"";
		TempString += LineString;
		TempString += "\")";
		TempString += "{";
		TempString += "\tIndex = TargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.AddData(this, CurrentNode->InternalName);";
		TempString += "}";
		CraftedFile03.Add(TempString);
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
		TempString += "_Registry.AddData(TargetNode.InternalName, TargetNodeData);";
		CraftedFile05.Add(TempString);
		CraftedFile05.Add("}");
		TempString = LineString;
		TempString += "_Registry.Reset();";
		CraftedFile06.Add(TempString);
		TempString = "using Niflib";
		TempString += LineString;
		TempString += "= Niflib::";
		TempString += LineString;
		TempString += ";";
		CraftedFile07.Add(TempString);
		TempString = "using ";
		TempString += LineString;
		TempString += " = ObjectRegistryClasses::";
		TempString += LineString;
		TempString += ";";
		CraftedFile07.Add(TempString);
		TempString = "if(ObjectType == \"";
		TempString += LineString;
		TempString += "\"){TargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.Read(in, link_stack, info);}";
		CraftedFile08.Add(TempString);
		TempString = "if(NodeType == \"";
		TempString += LineString;
		TempString += "\" || NodeType == \"";
		TempString += LineString;
		TempString += "Node\")";
		CraftedFile09.Add(TempString);
		CraftedFile09.Add("{");
		TempString = "\tListSize = TargetObjectRegistry.";
		TempString += LineString;
		TempString += "_Registry.Size();";
		CraftedFile09.Add(TempString);
		TempString = "\tObjectRegistryClasses::";
		TempString += LineString;
		TempString += "Node* ElementData = nullptr;";
		CraftedFile09.Add(TempString);
		CraftedFile09.Add("\tfor(size_t Index = 0; Index < ListSize&&RetrievedData == \"\"; ++Index)");
		CraftedFile09.Add("\t{");
		CraftedFile09.Add("\t\tElementData = GetElementPointerV2(Index);");
		CraftedFile09.Add("\t\tif(ElementData->InternalName == DataPointerString) { RetrievedData = ElementData->InternalName; }");
		CraftedFile09.Add("\t\telse if(ElementData->Data == DataNode) { RetrievedData = ElementData->InternalName; }");
		CraftedFile09.Add("\t}");
		CraftedFile09.Add("}");
	}
	CraftedFile01.SaveDataToFileV3("ObjectRegistryClasses.txt");
	CraftedFile02.SaveDataToFileV3("ObjectRegistry.txt");
	CraftedFile03.SaveDataToFileV3("GenerateNodeLines.txt");
	CraftedFile04.SaveDataToFileV3("DestroyActualNodeLines.txt");
	CraftedFile05.SaveDataToFileV3("CopyNodeToTree.txt");
	CraftedFile06.SaveDataToFileV3("ResetObjectRegistry.txt");
	CraftedFile07.SaveDataToFileV3("Object Registry Aliases.txt");
	CraftedFile08.SaveDataToFileV3("LoadStreamToObject.txt");
	CraftedFile09.SaveDataToFileV3("RetrieveInternalNames.txt");
	system("timeout /t 1");
}