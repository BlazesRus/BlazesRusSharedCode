/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code release available at http://www.nexusmods.com/skyrim/mods/44884/?
	*/
#pragma once

#include "VariableTypeLists.h"
#include <string>

class VariableVectorFunctions
{
public:
	//Return param of strings from things like havok lists
	static StringVectorList ReadStringParamFromStringList(StringVectorList TempStringList);

	//Return param of strings from things like boneIndices param
	static IntegerList ReadIntParamFromStringList(StringVectorList TempStringList);
	//Return param of strings from things like hkbBoneWeightArray param
	static DoubleList ReadDoubleParamFromStringList(StringVectorList TempStringList);
	//Retrieve ParamInfo StringList from StringList
	static StringVectorList ParamInfoFromStringList(StringVectorList TempStringList);

	/** Retrieve ParamInfo StringList from LineString
	* @param LineString
	* @return
	*/
	static StringVectorList ParamInfoFromString(std::string LineString);

	/** Convert Variable Index from one StringList to Another StringList
	* @param Index
	* @param CurrentVarList
	* @param NewVarList
	* @return integer of new VariableIndex
	*/
	static int ConvertVariableIndex(int Index, StringVectorList CurrentVarList, StringVectorList NewVarList);

	/** Converts Entries in StringList to Rows of 16-entry Strings
	* (Use to convert StringList for BoneEntries back to Lines of Strings)
	* @param TempStringList
	* @return
	*/
	static StringVectorList ConvertStringEntriesToStringRows(StringVectorList TempStringList);

	//Return StringList based on string info
	static StringVectorList IniInfoFromString(std::string LineString);

	/** Find Number of Parameters in LineString
	* @param LineString
	* @return
	*/
	static int GetNumberOfParamsFromString(std::string LineString);
	VariableVectorFunctions();
	~VariableVectorFunctions();
};
