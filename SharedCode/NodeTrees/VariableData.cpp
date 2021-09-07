/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#include "VariableData.h"

VariableData::VariableData(std::string StringData)
{
    size_t LineSize = StringData.length();
    char LineChar;
    unsigned __int8 DataStage = 0;
    for(size_t i = 0; i < LineSize; i++)
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
