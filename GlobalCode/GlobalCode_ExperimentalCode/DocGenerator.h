#pragma once
#ifndef DocGenerator_IncludeGuard
#define DocGenerator_IncludeGuard

#include <string>
#ifdef BLAZESGLOBALCODE_LIBRARY
#include "..\DLLAPI.h"
#include "..\GlobalCode_VariableLists\VariableList.h"
#include "..\GlobalCode_VariableLists\StringVectorList.h"
#include "..\GlobalCode_NodeTrees\LooseNodeTreeTemplate.h"
#ifndef DLL_API
	#define DLL_API
#endif
#else
#include "VariableList.h"
#include "StringVectorList.h"
#include "LooseNodeTreeTemplate.h"
#endif
//Generator HTML Code Documentation via reading headers(Mainly for Visual Studio C++)
class DLL_API DocGenerator
{
private:
	//constexp StringVectorList AutoDetectedContainerModifiers()
	//{
	//	StringVectorList DetectedContainers;
	//	DetectedContainers.Add("DLL_API");
	//	DetectedContainers.Add("NIFLIB_API");
	//	DetectedContainers.Add("static");
	//	return DetectedContainers;
	//}
public:
	struct DocGeneratorElementData : public LooseNodeTreeTemplate::Node
	{
		//ContainerTypes:
		//0 = Class
		//1 = Struct
		//2 = Method
		//100 = Variable (Detect methods via encountering "(" and ")" 
		unsigned __int8 ContainerType = 0;
		//Modifiers such as DLL_API, static, NIFLIB_API etc (for classes and structures detect DLL_API and NIFLIB_API as ContainerModifier)
		StringVectorList ContainerModifiers;
		//This is the parameter content within methods(String of characters between within "(" and ")"). (Maybe use for storing initialyzer of variables later?)
		std::string ParameterContent;
		//This is the class/struct/method/variable name
		std::string ContainerName;
	};
	class DLL_API DocGeneratorTree : public LooseNodeTreeTemplate::NodeTree <DocGeneratorElementData>
	{
		void TestContainedIfStatement()
		{
			unsigned __int8 ContainerType = 0;
			std::string TestContainerType = (ContainerType == 0 ? "class" : (ContainerType == 1 ? "struct" : (ContainerType == 2 ? "Method" : "Variable")));
		}
	};
	/*
		Example Tree Content Output:
		class Class01
		{

		}
	*/
	/* Example Tree variable Data from above example:
		(ContainerType==0?"class":(ContainerType==1?"struct":(ContainerType==2?"Method":"Variable"))) 
	*/
	/*
		--Separate classes and functions
		--Optional to create documentation of Variables
		--By default don't document private methods/Functions
		--Ignore content of methods (by default ignore all content methods starting from { and ending from next } at same tablevel
		--Save all single-line comments before method/class
		--clear comment store on blank lines
		--Maybe save Multiline comments as long as don't have any single-line comments before method/class
	*/
	//************************************
	//CodeLanguage Options:"C++","Java" (Defaults to C++ if none of those selected)
	// Method:    ReadHeaderFile
	// FullName:  DocGenerator::ReadHeaderFile
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: std::string FilePath
	// Parameter: std::string CodeLanguage
	// Parameter: unsigned __int8 ScanFormat
	//************************************
	void ReadHeaderFile(std::string FilePath,std::string CodeLanguage="C++", unsigned __int8 ScanFormat=0)
	{

	}
};

#endif