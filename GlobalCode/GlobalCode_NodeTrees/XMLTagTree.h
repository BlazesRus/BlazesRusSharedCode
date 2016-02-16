/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)
	Latest Code Release at https://github.com/BlazesRus/NifLibEnvironment
*/
#pragma once
#ifndef TagTreeData_IncludeGuard
#define TagTreeData_IncludeGuard

#include "TagNodeTreeTemplate.h"
#include "XMLOption.h"
//#include "..\..\BlazesBehaviorFileMerger\HkBhvNodeTree.h"
#include "QuadVectorFunctions.h"
#include "..\DLLAPI.h"

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
