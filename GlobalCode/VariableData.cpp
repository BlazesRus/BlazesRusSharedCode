/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#include "VariableData.h"

VariableData::VariableData(std::string StringData)
{
	unsigned int LineSize = StringData.length();
	char LineChar;
	unsigned int DataStage = 0;
	for(unsigned int i = 0; i < LineSize; i++)
	{
		LineChar = StringData.at(i);
		if(LineChar == ',')
		{
			DataStage++;
		}
		else if(LineChar != '(' || LineChar != ')' || LineChar != '\t' || LineChar != ' ' || LineChar != '\n')
		{
			if(DataStage == 0)
			{
				VariableName += LineChar;
			}
			else if(DataStage == 1)
			{
				VariableType += LineChar;
			}
			else if(DataStage == 2)
			{
				VariableValue_String += LineChar;
			}
		}
	}
}