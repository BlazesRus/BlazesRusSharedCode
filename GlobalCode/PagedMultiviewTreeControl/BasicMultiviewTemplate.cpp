// MultiView.cpp : Defines the class behaviors for the application.
//

#include "MultiviewPrecompile.h"
#include "BasicMultiviewTemplate.h"

#include "MultiViewDoc.h"
#include "MultiViewView.h"
//#include "MainFrm.h"
//#include "OtherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////Based on AFX BEGIN_TEMPLATE_MESSAGE_MAP
//#if !defined(BEGIN_MULTITEMPLATE_MESSAGE_MAP)
//#define BEGIN_MULTITEMPLATE_MESSAGE_MAP(theClass, type_name, typename02, typename03, typename04, baseClass)			\
//	PTM_WARNING_DISABLE														\
//	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
//	const AFX_MSGMAP* theClass< type_name, typename02, typename03, typename04>::GetMessageMap() const			\
//	{ return GetThisMessageMap(); }										\
//	template < typename type_name, typename typename02, typename typename03, typename typename04 >											\
//	const AFX_MSGMAP* PASCAL theClass< type_name, typename02, typename03, typename04 >::GetThisMessageMap()		\
//	{																		\
//		typedef theClass< type_name, typename02, typename03, typename04 > ThisClass;							\
//		typedef baseClass TheBaseClass;										\
//		__pragma(warning(push))												\
//		__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ \
//		static const AFX_MSGMAP_ENTRY _messageEntries[] =					\
//		{
//#define END_MULTITEMPLATE_MAP() \
//			{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } \
//		}; \
//	__pragma(warning(pop))	\
//	static const AFX_MSGMAP messageMap = \
//	{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; \
//	return &messageMap; \
//	}								  \
//	PTM_WARNING_RESTORE
//#endif

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate

////BEGIN_MULTITEMPLATE_MESSAGE_MAP(BasicMultiviewTemplate, ViewType01, ViewType02, WindowType, FrameWindowType, CWinAppEx)
//PTM_WARNING_DISABLE
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//const AFX_MSGMAP* BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::GetMessageMap() const
//{ return GetThisMessageMap(); }
//\
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//const AFX_MSGMAP* PASCAL BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::GetThisMessageMap()
//{
//typedef BasicMultiviewTemplate< ViewType01, ViewType02, WindowType, FrameWindowType > ThisClass;
//typedef CWinAppEx TheBaseClass;
//__pragma(warning(push))
//__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */
//static const AFX_MSGMAP_ENTRY _messageEntries[] =
//{
//	//{{AFX_MSG_MAP(BasicMultiviewTemplate)

////END_MULTITEMPLATE_MAP()
//	{
//		0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
//	}
//};
//__pragma(warning(pop))
//static const AFX_MSGMAP messageMap =
//		{ &CWinAppEx::GetThisMessageMap, &_messageEntries[0] };
//			return &messageMap;
//}
//PTM_WARNING_RESTORE

/////////////////////////////////////////////////////////////////////////////
// BasicMultiviewTemplate construction
template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType>::BasicMultiviewTemplate()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only BasicMultiviewTemplate object
//template<typename ViewType01, typename ViewType02, typename WindowType, typename FrameWindowType>
//BasicMultiviewTemplate<ViewType01, ViewType02, WindowType, FrameWindowType> theApp;

