// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once

#include "MFCpch.h"
#include "../Databases/IndexedDictionary.h"
#include "../VariableLists/VariableList.h"

template <typename NodeType>
class NodeData
{//Partially based on (https://www.codeproject.com/Articles/9887/CStaticTreeCtrl-A-CStatic-derived-custom-Tree-con) Node storage but attempting to optimize to find nodes stored deep inside big xml files(without running out of memory in program)
private:
	class NodeDictionary : public IndexedDictionary<NodeType>;
public:
	NodeData()
	{
	}
	~NodeData(){}
	NodeDictionary NodeStore;
private:
	class InnerLocationStorage
	{public:
		InnerLocationStorage(unsigned _int64 rootIndex)
		{
		
		}
		unsigned _int64 RootNodeIndex;
		//Only full RootLocation will be stored on Draw Updates instead of storing every node
		CRect	RootLocation;
		//To-Do Store Dictionary Variant storing Nodes within with key refering to X position and potentially storing Y offset data
	}
	VariableList<InnerLocationStorage> LocationStore;
public:
	void Reset()
	{
		NodeStore.clear();
	}
	
};