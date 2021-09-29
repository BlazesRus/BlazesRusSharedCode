// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once

#include "MFCpch.h"
	
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
	//unsigned _int64 IndexPos;
	unsigned _int64 ParentIndex;
	bool isOpen;
};