// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
// ***********************************************************************
#ifndef MainFrameView_IncludeGuard
#define MainFrameView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "GenericFrameView.h"
#include "MultiViewDoc.h"

/// <summary>
/// Class MFView.
/// Implements the <see cref="GenericFrameView{MultiViewDoc}" />
/// </summary>
/// <seealso cref="GenericFrameView{MultiViewDoc}" />
class MFView : public GenericFrameView<MultiViewDoc>
{
	//CRuntime_Base01V2(MainFrameView, GenericFrameView, MultiViewDoc)
private:
	typedef GenericFrameView<MultiViewDoc> TheBaseClass;
	typedef MFView ThisClass;
protected:

	/// <summary>
	/// Gets the base class.
	/// </summary>
	/// <returns>*.</returns>
	static CRuntimeClass* PASCAL _GetBaseClass() { return TheBaseClass::GetThisClass(); }
public:\
	/// <summary>
	/// The runtime object version of class named MFView
	/// </summary>
	static const CRuntimeClass classMFView;

	/// <summary>
	/// Returns the runtime call of this class
	/// </summary>
	/// <returns>*.</returns>
	static CRuntimeClass* PASCAL GetThisClass() { return _RUNTIME_CLASS(MFView); }\

	/// <summary>
	/// Gets the runtime class.
	/// </summary>
	/// <returns>*.</returns>
	virtual CRuntimeClass* GetRuntimeClass() const { return _RUNTIME_CLASS(MFView); }

	/// <summary>
	/// Initializes a new instance of the <see cref="MFView" /> class.
	/// </summary>
	MFView()
	{
		ViewName = "Main View";
	}
	BEGIN_AltMESSAGE_MAP()

	END_AltMESSAGE_MAP_Base01(GenericFrameView, MultiViewDoc)
};

CRuntimeImplimentation_Base01(MFView, GenericFrameView, MultiViewDoc)
#endif