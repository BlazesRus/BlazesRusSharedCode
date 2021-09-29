// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once

#include "MFCpch.h"
#include "../VariableLists/VariableTypeLists.h"
	
class XMLNode
{
protected:
public:
	/// <summary>
	/// The addition tag options
	/// </summary>
	ArgList tagArgData;
	//0=NormalTag; 1:SelfContainedTag; 2:TagIsClosing; 3:XMLVersionTag; 4:SingleLine TagContent; 5:Separated TagContent
	int8_t TagType = 0;
#ifndef BlazesMFCApp_IncludeCurrentNodeIndex
	unsigned _int64 CurrentIndexPos;
#endif
	
	/// <summary>
	/// The indexes of all child nodes
	/// </summary>
	UXIntList ChildNodes;

#ifndef BlazesMFCApp_ExcludeParentNodeIndex
	/// <summary>
	/// Index position of ParentNode (EmptyNode=inside Root Level by default)
	/// </summary>
	unsigned __int64 ParentIndex;
#endif
#ifdef BlazesMFCApp_UseLegacyNodeSearch
	unsigned _int64 ParentIndex;
	//Determine if Node is open(New Search code auto-closes child nodes from tracking)
	bool isOpen;
#endif
};