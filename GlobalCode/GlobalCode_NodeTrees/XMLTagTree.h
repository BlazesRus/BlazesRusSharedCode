/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagTreeData_IncludeGuard
#define TagTreeData_IncludeGuard

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

#ifdef BlazesGlobalCode_LocalLayout//(Local version style layout)
	#include "QuadVectorFunctions.h"
#else
	#include "..\GlobalCode_QuadVector\QuadVectorFunctions.h"
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
