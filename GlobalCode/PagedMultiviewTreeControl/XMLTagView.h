#if !defined(XMLTagView_IncludeGuard)
#define XMLTagView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "TemplateMacros.h"
#include "XMLTagViewNode.h"
#include <typeinfo>

/////////////////////////////////////////////////////////////////////////////
// XMLTagView window

class XMLTagView : public CustomTreeView<XMLTagViewNode>
{
	CRuntime_Base01V2(XMLTagView, CustomTreeView, XMLTagView)
	XMLTagView(string FilePath) : CustomTreeView()
	{

	}
protected://BEGIN_AltMESSAGE_MAP()
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
	virtual const AFX_MSGMAP* GetMessageMap() const
	{
		return GetThisMessageMap();
	}
};

inline AFX_COMDAT const CRuntimeClass XMLTagView::classXMLTagView = { "XMLTagView", sizeof(XMLTagView), 0xFFFF, NULL,&XMLTagView::_GetBaseClass, NULL, NULL };

#endif
