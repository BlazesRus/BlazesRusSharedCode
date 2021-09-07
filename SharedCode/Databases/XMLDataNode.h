// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(BasicDataNode_IncludeGuard)
#define BasicDataNode_IncludeGuard

#include "..\DLLAPI.h"

#include "ArgList.h"
#include "UIntVector.h"
#include "TagContentVector.h"

#if defined(BlazesRusCode_UseTemplatedNode)
#include "BasicDataNode.h"
#endif

/// <summary>
/// Class named XMLDataNode(derive into DataNode subclass into view). (Node links to other nodes in node bank)
/// Held within NodeDictionary with int key
/// </summary>
#if !defined(BlazesRusCode_UseTemplatedNode)
class XMLDataNode
{public:
	/// <summary>
	/// Index position of ParentNode (EmptyNode=inside Root Level by default)
	/// </summary>
	int ParentIndex;
	
	/// <summary>
	/// The indexes of all child nodes (Is closed tag if has no children)
	/// </summary>
	UIntVector ChildNodes;

	/// <summary>
	/// The tag name
	/// </summary>
	std::string TagName;
	
	/// <summary>
	/// The argument data
	/// </summary>
	ArgList ArgData;

	/// <summary>
	/// The node content
	/// </summary>
	TagContentVector NodeContent;

	/// <summary>
	/// Is Node Open
	/// </summary>
	BOOL    bOpen;
	
	/// <summary>
	/// Node Coordinate Data(Current Position of Node in Tree)
	/// </summary>
	CRect		CoordData;
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name)
	{
		TagName = name;
		CoordData.SetRectEmpty();
		bOpen = FALSE;
		NodeType = 0;
		ParentIndex = 0;
	}
	
	/// <summary>
	/// Finalizes an instance of the <see cref="DataNode"/> class.
	/// </summary>
	~DataNode(){}
};
#else
class XMLDataNode : public BasicDataNode
{public:
	/// <summary>
	/// Index position of ParentNode (EmptyNode=inside Root Level by default)
	/// </summary>
	int ParentIndex;
	
	/// <summary>
	/// The indexes of all child nodes (Is closed tag if has no children)
	/// </summary>
	UIntVector ChildNodes;

	/// <summary>
	/// The tag name
	/// </summary>
	std::string TagName;
	
	/// <summary>
	/// The argument data
	/// </summary>
	ArgList ArgData;

	/// <summary>
	/// The node content
	/// </summary>
	TagContentVector NodeContent;

	/// <summary>
	/// Is Node Open
	/// </summary>
	BOOL    bOpen;
	
	/// <summary>
	/// Node Coordinate Data(Current Position of Node in Tree)
	/// </summary>
	CRect		CoordData;
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="DataNode"/> class. (All Data Nodes must have display names)
	/// </summary>
	/// <param name="name">The NodeName.</param>
	DataNode(std::string name)
	{
		TagName = name;
		CoordData.SetRectEmpty();
		bOpen = FALSE;
		NodeType = 0;
		ParentIndex = 0;
	}
	
	/// <summary>
	/// Finalizes an instance of the <see cref="DataNode"/> class.
	/// </summary>
	~DataNode(){}
};
#endif

#endif