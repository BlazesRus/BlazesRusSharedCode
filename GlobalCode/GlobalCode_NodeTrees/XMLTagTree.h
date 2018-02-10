/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagTreeData_IncludeGuard
#define TagTreeData_IncludeGuard

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

#include "TagNodeTreeTemplate.h"
#include "XMLOption.h"

//Non-Alternating headers above (Structure based headers in this section)
#ifndef BlazesGlobalCode_FileStructureVersion || BlazesGlobalCode_FileStructureVersion == 0//(library style  layout)
	#include "..\GlobalCode_QuadVector\QuadVectorFunctions.h"
#elif BlazesGlobalCode_FileStructureVersion == 1//(Local version style layout)
	#include "QuadVectorFunctions.h"
#endif

struct DLL_API TagTreeData
{
	class TagTree;
	class TagNode : public TagNodeTreeTemplateData::Node
	{
	public:
		/* loosely connected functions for HkBhvNodeData.h*/
		//void StreamDataToBHVTree(HkBhvNodeData::HkBhvNodeTree* TargetBHVTree, HkBhvNodeData::BHVTreeSharedData& SharedData)



		/*End of Loosely connected functions for HkBhvNodeData.h*/
	};
	class TagTree : public TagNodeTreeTemplateData::NodeTree <TagNode>
	{
	public:
		/* loosely connected functions for HkBhvNodeData.h*/
		//void CreateUnknownTagNodeTree(HkBhvNodeData::BHVTreeSharedData& SharedData, TagNode* TargetNode)
		/*End of Loosely connected functions for HkBhvNodeData.h*/
	};
};
#endif
