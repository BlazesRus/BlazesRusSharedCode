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
}
