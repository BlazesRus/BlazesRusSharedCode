//Code Created by James Michael Armstrong(Skyrim nexus name:BlazesRus)
#pragma once
#ifndef IniData_IncludeGuard
#define IniData_IncludeGuard

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



//Non-Alternating headers above (Structure based headers in this section)
#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0//(library style  layout)
	#include "..\GlobalCode_VariableLists\VariableList.h"
	#include "..\GlobalCode_VariableLists\StringVectorList.h"
#elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
	#include "VariableList.h"
	#include "StringVectorList.h"
#endif


class DLL_API IniDataElement
{
public:
	bool IsIniCategory = false;
	std::string ScriptArg01;
	std::string ScriptArg02;
	IniDataElement();
	~IniDataElement();
};

class DLL_API IniData : public VariableList <IniDataElement>
{
public:
	unsigned __int8 IniType = 0;
	//************************************
	// Method:    LoadIniData
	// FullName:  IniData::LoadIniData
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FileName
	//************************************
	void LoadIniData(std::string FileName);
	bool CheckIfElementExists(std::string Value)
	{
		const size_t ListSize = Size();
		IniDataElement ElementData;
		bool ElementExists = false;
		for(size_t Index=0;Index<ListSize&&ElementExists==false;++Index)
		{
			ElementData = ElementAt(Index);
			if(ElementData.ScriptArg01==Value)
			{
				ElementExists = true;
			}
		}
		return ElementExists;
	}
	std::string GetElementData(std::string Value)
	{
		const size_t ListSize = Size();
		std::string ElementValue="";
		IniDataElement ElementData;
		bool ElementExists = false;
		for(size_t Index=0; Index < ListSize && ElementExists == false; ++Index)
		{
			ElementData = ElementAt(Index);
			if(ElementData.ScriptArg01 == Value)
			{
				ElementExists = true;
				ElementValue = ElementData.ScriptArg02;
			}
		}
		if(ElementExists == false)
		{
			std::cout << "Ini setting named "<<Value<<"not found.\n";
		}
		return ElementValue;
	}
	IniData();
	~IniData();
};
#endif