// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#if !defined(XMLTreeView_IncludeGuard)
#define XMLTreeView_IncludeGuard

//#include "MultiviewPrecompile.h"
//#include "CustomTreeView.h"
//#include "TemplateMacros.h"
//#include "XMLTreeViewNode.h"
#include <typeinfo>
#include <string>

/// <summary>
/// Class named XMLTreeView.
/// Implements the <see cref="CustomTreeView{XMLTreeViewNode}" />
/// </summary>
/// <seealso cref="CustomTreeView{XMLTreeViewNode}" />
class XMLTreeView : public CustomTreeView<XMLTreeViewNode>
{
	CRuntime_Base01V2(XMLTreeView, CustomTreeView, XMLTreeViewNode)
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="XMLTreeView"/> class.
	/// </summary>
	/// <param name="FilePath">The file path.</param>
	XMLTreeView(std::string FilePath);
	/// <summary>
	/// Prevents a default instance of the <see cref="XMLTreeView"/> class from being created.
	/// </summary>
	XMLTreeView();
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
		typedef XMLTreeView ThisClass;
		typedef CustomTreeView<XMLTreeViewNode> TheBaseClass;
		__pragma(warning(push))
		__pragma(warning(disable: 4640))
		static const AFX_MSGMAP_ENTRY _messageEntries[] =
		{
			//END_AltMESSAGE_MAP_Base01(CustomTreeView, XMLTreeViewNode)
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

inline AFX_COMDAT const CRuntimeClass XMLTreeView::classXMLTreeView = { "XMLTreeView", sizeof(XMLTreeView), 0xFFFF, NULL,&XMLTreeView::_GetBaseClass, NULL, NULL };

#endif
