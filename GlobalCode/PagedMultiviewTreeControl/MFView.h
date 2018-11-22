#ifndef MainFrameView_IncludeGuard
#define MainFrameView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GenericFrameView.h"
#include "MultiViewDoc.h"

class MFView : public GenericFrameView<MultiViewDoc>
{
	//CRuntime_Base01V2(MainFrameView, GenericFrameView, MultiViewDoc)
private:
	typedef GenericFrameView<MultiViewDoc> TheBaseClass;
	typedef MFView ThisClass;
protected:
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); }
public:\
	static const CRuntimeClass classMFView;
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(MFView); }\
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(MFView); }
	MFView()
	{
		ViewName = "Main View";
	}
	BEGIN_AltMESSAGE_MAP()

	END_AltMESSAGE_MAP_Base01(GenericFrameView, MultiViewDoc)
};

CRuntimeImplimentation_Base01(MFView, GenericFrameView, MultiViewDoc)
#endif