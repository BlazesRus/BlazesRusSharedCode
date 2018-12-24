// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#if !defined(BasicXMLNode_IncludeGuard)
#define BasicXMLNode_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GlobalCode_VariableLists/VariableList.h"
#include "GlobalCode_IniData/IniDataV2.h"
#include <string>
//#include "XMLTagViewNode.h"


/// <summary>
/// Struct named BasicXMLNode
/// </summary>
class BasicXMLNode
{public:
	/// <summary>
	/// The node name
	/// </summary>
	std::string NodeName;
	std::string TagContent;
		/// <summary>
	/// Initializes a new instance of the <see cref="BasicXMLNode"/> struct.
	/// </summary>
	/// <param name="name">The NodeName.</param>
	BasicXMLNode(std::string name)
	{
		NodeName = name;
		TagContent = "";
	}

	/// <summary>
	/// Initializes a new instance of the <see cref="BasicXMLNode"/> class.
	/// </summary>
	BasicXMLNode()
	{
		NodeName = "";
		TagContent = "";
	}
	/// <summary>
	/// Converts to tag string.
	/// </summary>
	/// <returns>std::string</returns>
	std::string ConvertToTagString(IniDataV2 AdditionTagOptions, int TagType = 0)
	{
		std::string TagStr = "<";
		if (TagType == 3) { TagStr += "?"; }
		TagStr += NodeName;
		size_t TagSize = AdditionTagOptions.Size();
		if (TagSize > 0)
		{
			for (auto it = AdditionTagOptions.self.begin(); it != AdditionTagOptions.self.end(); ++it) {
				TagStr += " ";
				TagStr += it.key();
				TagStr += "=\"";
				TagStr += it.value();
				TagStr += "\"";
			}
		}
		if (TagType == 1)
		{
			TagStr += "/>";
		}
		else if (TagType == 3)
		{
			TagStr += "?>";
		}
		else
		{
			TagStr += ">";
		}
		return TagStr;
	}
};

/// <summary>
/// Class named BasicNodeList(Mainly for temporally storing information about nodes before sending information to tree)
/// </summary>
class BasicNodeList : public VariableList<BasicXMLNode>
{
public:
	/// <summary>
	/// Adds the specified name.
	/// </summary>
	/// <param name="name">The name.</param>
	void Add(std::string name)
	{
		int Index = this->AddData();
		this->at(Index).NodeName = name;
	}
	BasicXMLNode& LastNode()
	{
		return this->at(size()-1);
	}
};

#endif
