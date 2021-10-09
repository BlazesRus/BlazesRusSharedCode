
// DFBody2DView.h : interface of the DFBody2DView class
//

#pragma once

#include "MFCpch.h"

#include "MFCView.h"
#include "ContextMenu.h"

#ifndef BlazesMFCApp_UseLegacyNodeSearch
//#include "../Databases/ArgList.h"
#include "XMLNodeData.hpp"
#else

#endif

class DFBody2DView : public MFCView
{
protected: // create from serialization only
    DFBody2DView() noexcept;
    virtual ~DFBody2DView()
    {
        Reset();
        m_Font.DeleteObject();
    }
    DECLARE_DYNCREATE(DFBody2DView)

    void CreateFileIfDoesntExist(std::string fileName)
    {
        bool FileExists = false;
        //Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
        struct stat buffer;
        FileExists = (stat(fileName.c_str(), &buffer) == 0);
        //Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
        if (!FileExists)
        {
            std::ofstream file(fileName);
            if (!file)
            {
                std::cout << "File could not be created" << std::endl;
                return;
            }
        }
    }
protected:

// Attributes
public:
    //Name of File(if blank then not saved/loaded yet into view)
    //std::string FileName="";

    MFCDoc* GetDocument() const;

protected:
    LOGFONT			m_lgFont;
    CFont			m_Font;
    //COLORREF		m_DefaultTextColor;
	
    /// <summary>
    /// (Lighter Shade of Sonic Silver) https://www.schemecolor.com/sample?getcolor=7a7978
    /// </summary>
    const COLORREF	lightSonicSilver = RGB(202, 201, 201);
    /// <summary>
    /// Pitch Black (rgb of (0,0,0))
    /// </summary>
    const COLORREF	pureBlack = RGB(0, 0, 0);

    BOOL			m_bShowLines;

    int				m_iDocHeight;
    BOOL			m_bScrollBarMessage;

    int				m_iLineHeight;
    int				m_iIndent;
    int				m_iPadding;

// Operations
public:
    unsigned _int64 AddNodeByFullTag(std::string TagContent, int parentIndex=0)
    {
    
    }

    /// <summary>
    /// Resets the storage of this instance.
    /// </summary>
    void Reset()
    {

    }

    //-------File Loading Operations-------------------------------------------------------
    
    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    bool LoadDataFromFile(std::string FilePath);

    /// <summary>
    /// Saves the loaded data to file. (if / or \ is last character(Targeting Directory instead of file), will instead create/replace TextFile.xml)
    /// </summary>
    /// <param name="FilePath">The file path. or file name </param>
    void SaveDataToFile(std::string FilePath);
//--------------------------------------------------------------------------------------

// Overrides
public:
    virtual void OnDraw(CDC* pDC);  // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DFBody2DView.cpp
inline MFCDoc* DFBody2DView::GetDocument() const
   { return reinterpret_cast<MFCDoc*>(m_pDocument); }
#endif

