// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once
#if !defined(BasicDataNode_IncludeGuard)
#define BasicDataNode_IncludeGuard

#include "ArgList.h"
#include "..\BasicXMLGUI\UIntVector.h"
#include "TagContentVector.h"

/// <summary>
/// Class named BasicDataNode(derive into DataNode subclass into view). (Node links to other nodes in node bank)
/// Held within NodeDictionary with int key
/// </summary>
class BasicDataNode
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

    //0 = Default
	//1 = ClassNode root
	//2 = NonClassNode Level tag
	//3 = XMLVersion tag likely as <?xml version="1.0" encoding="ascii"?>
	//4 = hkpackfile tag with toplevelobject arg (normally second tag in .bhv file) (save first found to linked key "hkpackfile")
	//50 = hkparam named node with TagContent QuadVector format such as (1.000000 0.000000 0.000000 0.000000) ; Only numbers configurable
	//-------Arg Data Stored as Separate nodes-------------------
	//-------90 = Arg Field
	//91 = Arg Element
    //92 = EventNode Link(From ArgData)
    //93 = VariableNode Link(From ArgData)
	//94 = ClassNode Link(From ArgData)
    //95 = Character Property Link(From ArgData)
	//96 = Attribute Name Link(From ArgData)
	//------Any at or above 100 reserved for TagContent------
	//100 = SingleLine TagContent
	//101 = SingleLine Event Target
	//102 = SingleLine Variable Target
	//103 = SingleLine ClassNode Target
	//104 = SingleLine Character Property Target
	//105 = SingleLine Attribute Name Target
	//------------------------------------------------------------------------
	//110 = Multiline TagContentElement
    //111 = Multiline Event Target
    //112 = Multiline Variable Target
    //113 = Multiline ClassNode Target
	//114 = Multiline Character Property Target
	//115 = Multiline Attribute Name Target
    char NodeType;

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