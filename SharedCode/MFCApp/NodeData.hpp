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
	{
		//Includes all child nodes from Root node except for those that are closed
		//X position Calculated by CRect::BottomRight.x
		//Remove Tracking Of Nodes from storage when close them, and readd when open the nodes
		//All Child nodes removed from tracking as well when parent closes
	public:
		InnerLocationStorage(unsigned _int64 rootIndex)
		{
		}
		unsigned _int64 RootNodeIndex;
		//Store CRect::TopLeft.y position of Root Node
		int RootYPosition;
		//To-Do Store Dictionary Variant storing Nodes within with key refering to X position
	}
	VariableList<InnerLocationStorage> LocationStore;
public:
	unsigned _int64 FindNodeFromPoint(CPoint point)
	{
		ScreenToClient(&cp);
		
	}
	void Reset()
	{
		NodeStore.clear();
	}
	
};