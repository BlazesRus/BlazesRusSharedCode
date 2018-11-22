#ifndef MainFrameView_IncludeGuard
#define MainFrameView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GenericFrameView.h"
#include "MultiViewDoc.h"

class MainFrameView : GenericFrameView<MultiViewDoc>
{
	CRuntime_Base01V2(MainFrameView, GenericFrameView, MultiViewDoc)
public:
	MainFrameView()
	{
		ViewName = "Main View";
	}
	BEGIN_AltMESSAGE_MAP()

	END_AltMESSAGE_MAP_Base01(GenericFrameView, MultiViewDoc)
};
#endif