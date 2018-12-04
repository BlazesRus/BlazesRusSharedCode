// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#if !defined(XMLTagView_IncludeGuard)
#define XMLTagView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "TemplateMacros.h"
#include "XMLTagViewNode.h"
#include <typeinfo>
#include <string>

/// <summary>
/// Class named XMLTagView.
/// Implements the <see cref="CustomTreeView{XMLTagViewNode}" />
/// </summary>
/// <seealso cref="CustomTreeView{XMLTagViewNode}" />
class XMLTagView : public CustomTreeView<XMLTagViewNode>
{
	CRuntime_Base01V2(XMLTagView, CustomTreeView, XMLTagViewNode)
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="XMLTagView"/> class.
	/// </summary>
	/// <param name="FilePath">The file path.</param>
	XMLTagView(std::string FilePath);
	/// <summary>
	/// Prevents a default instance of the <see cref="XMLTagView"/> class from being created.
	/// </summary>
	XMLTagView();
	/// <summary>
	/// Loads the data from file.
	/// </summary>
	/// <param name="FilePath">The file path.</param>
	/// <returns>bool</returns>
	bool LoadDataFromFile(std::string FilePath);
protected://BEGIN_AltMESSAGE_MAP()
	/// <summary>
	/// Gets the this message map.
	/// </summary>
	/// <returns>const AFX_MSGMAP*</returns>
	static const AFX_MSGMAP* PASCAL GetThisMessageMap()
	{
		typedef XMLTagView ThisClass;
		typedef CustomTreeView<XMLTagViewNode> TheBaseClass;
		__pragma(warning(push))
		__pragma(warning(disable: 4640))
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
			//END_AltMESSAGE_MAP_Base01(CustomTreeView, XMLTagViewNode)
			{ 0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 }
		};
		__pragma(warning(pop))
		static const AFX_MSGMAP messageMap =
		{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
		return &messageMap;
	}
public:
	/// <summary>
	/// Gets the message map.
	/// </summary>
	/// <returns>const AFX_MSGMAP *</returns>
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
};

inline AFX_COMDAT const CRuntimeClass XMLTagView::classXMLTagView = { "XMLTagView", sizeof(XMLTagView), 0xFFFF, NULL,&XMLTagView::_GetBaseClass, NULL, NULL };

#endif
