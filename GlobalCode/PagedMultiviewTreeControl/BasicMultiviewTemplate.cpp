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

