#if !defined(CViewP_IncludeGuard)
#define CViewP_IncludeGuard

#include "MultiviewPrecompile.h"

#ifndef __AFXWIN_H__
#error "include 'MultiviewPrecompile.h' before including this file for PCH"
#endif

/// <summary>
/// Pointer storage for type derived from CView
/// </summary>
template <typename ViewType>
class CViewP
{
public:
	ViewType* self = nullptr;
	/// <summary>
	/// Type name contained within class
	/// </summary>
	/// <returns></returns>
	typename ViewT() { return ViewType; }
	CViewP* PointerContainer = this;

	/// <summary>
	/// Initializes a new instance of the <see cref="CViewP"/> class from class derived from CView
	/// </summary>
	/// <param name="Value">The value.</param>
	CViewP(ViewType* Value)
	{
		if(self!=nullptr)
		{
			delete self;
		}
		self = Value;
	}

	explicit operator CView*()
	{
		return static_cast<CView*>(self);
	}

	explicit operator ViewType*()
	{
		return self;
	}
};

/// <summary>
/// Pointer storage for type derived from CView
/// </summary>
template <typename ViewType>
class CFrameP
{
public:
	ViewType* self = nullptr;
	/// <summary>
	/// Type name contained within class
	/// </summary>
	/// <returns></returns>
	typename ViewT() { return ViewType; }
	CFrameP* PointerContainer = this;

	/// <summary>
	/// Initializes a new instance of the <see cref="CViewP"/> class from class derived from CFrameWnd
	/// </summary>
	/// <param name="Value">The value.</param>
	CFrameP(ViewType* Value)
	{
		if (self != nullptr)
		{
			delete self;
		}
		self = Value;
	}

	explicit operator CFrameWnd*()
	{
		return static_cast<CFrameWnd*>(self);
	}

	explicit operator ViewType*()
	{
		return self;
	}
};

#endif
