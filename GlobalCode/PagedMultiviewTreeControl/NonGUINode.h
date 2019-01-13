// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest BlazesGlobalCode Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#pragma once
#if !defined(NonGUINode_IncludeGuard)
#define NonGUINode_IncludeGuard

#include "GlobalCode_IniData/IniDataV2.h"

/// <summary>
/// Class named NonGUINode.
/// </summary>
class NonGUINode
{
public:
	/// <summary>
	/// The node name
	/// </summary>
	std::string DisplayName;

	/// <summary>
	/// Initializes a new instance of the <see cref="NonGUINode" /> struct.
	/// </summary>
	/// <param name="name">The NodeName.</param>
	NonGUINode(std::string name)
	{
		DisplayName = name;
	}


	/// <summary>
	/// Initializes a new instance of the <see cref="NonGUINode" /> class.
	/// </summary>
	NonGUINode()
	{
		DisplayName = "";
	}
};

/// <summary>
/// Class named TaggedNode.
/// Implements the <see cref="NonGUINode" />
/// </summary>
/// <seealso cref="NonGUINode" />
class TaggedNode : public NonGUINode
{public:
	/// <summary>
	/// The tag content
	/// </summary>
	std::string TagContent;
	/// <summary>
	/// The addition tag options
	/// </summary>
	IniDataV2 AdditionTagOptions;
	/// <summary>
	/// Initializes a new instance of the <see cref="TaggedNode"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	TaggedNode(std::string name)
	{
		DisplayName = name;
		TagContent = "";
	}
	/// <summary>
	/// Initializes a new instance of the <see cref="TaggedNode"/> class.
	/// </summary>
	TaggedNode()
	{
		DisplayName = "";
		TagContent = "";
	}

	/// <summary>
	/// Converts to tag string.
	/// </summary>
	/// <param name="TagType">Type of the tag.</param>
	/// <returns>std::string</returns>
	std::string ConvertToTagString(int TagType = 0)
	{
		std::string TagStr = "<";
		if (TagType == 3) { TagStr += "?"; }
		TagStr += DisplayName;
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
#endif