// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#if !defined(BasicXMLNode_IncludeGuard)
#define BasicXMLNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GlobalCode_VariableLists/VariableList.h"
#include "NonGUINode.h"

/// <summary>
/// Class named BasicNodeList(Mainly for temporally storing information about nodes before sending information to tree)
/// </summary>
class BasicNodeList : public VariableList<BufferNode>
{
public:
	/// <summary>
	/// Adds the specified name.
	/// </summary>
	/// <param name="name">The name.</param>
	void Add(std::string name)
	{
		int Index = this->AddData();
		this->at(Index).DisplayName = name;
	}
	///<summary>
	/// Reference to last node in List
	///</summary>
	///<returns>BufferNode&</returns>
	BufferNode& LastNode()
	{
		return this->at(size() - 1);
	}
};

#endif
