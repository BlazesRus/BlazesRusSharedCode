
// TextView.h : interface of the TextView class
//

#pragma once

#include "MFCpch.h"

#include "MFCView.h"
#include "ContextMenu.h"
#include "..\VariableLists\StringVectorList.h"

class TextView : public MFCView
{
protected: // create from serialization only
    TextView() noexcept;
    virtual ~TextView()
    {
        Reset();
        m_Font.DeleteObject();
    }
    DECLARE_DYNCREATE(TextView)

    void CreateFileIfDoesntExist()
    {
        if (FileName == "")
        {
            std::cout << "Filename not set yet!" << std::endl;
        }
        else
        {
            bool FileExists = false;
            //Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
            struct stat buffer;
            FileExists = (stat(FileName.c_str(), &buffer) == 0);
            //Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
            if (!FileExists)
            {
                std::ofstream file(FileName);
                if (!file)
                {
                    std::cout << "File could not be created" << std::endl;
                    return;
                }
            }
        }
    }
    void CreateFileIfDoesntExist(std::string fileName)
    {
        bool FileExists = false;
        //Based on https://www.quora.com/What-is-the-best-way-to-check-whether-a-particular-file-exists-or-not-in-C++
        struct stat buffer;
        FileExists = (stat(FileName.c_str(), &buffer) == 0);
        //Based on http://stackoverflow.com/questions/17818099/how-to-check-if-a-file-exists-before-creating-a-new-file
        if (!FileExists)
        {
            std::ofstream file(FileName);
            if (!file)
            {
                std::cout << "File could not be created" << std::endl;
                return;
            }
        }
    }
// Attributes
public:
    StringVectorList ContentList;
    MFCDoc* GetDocument() const;

protected:
    LOGFONT			m_lgFont;
    CFont			m_Font;
    COLORREF		m_crDefaultTextColor;
    COLORREF		m_TagContentColor = RGB(40, 40, 160);
    COLORREF		m_crConnectingLines;
    const COLORREF	m_ArgColor = RGB(202, 201, 201);//(Lighter Shade of Sonic Silver) https://www.schemecolor.com/sample?getcolor=7a7978

    BOOL			m_bShowLines;

    int				m_iDocHeight;
    BOOL			m_bScrollBarMessage;

    int				m_iLineHeight;
    int				m_iIndent;
    int				m_iPadding;
    //ContextMenu TextMenu(&m_Font);

// Operations
public:
    /// <summary>
    /// Resets the storage of this instance.
    /// </summary>
    void Reset()
    {
        ContentList.clear();
    }

    //-------File Loading Operations-------------------------------------------------------
    
    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    bool LoadDataFromFile(std::string FilePath);

    /// <summary>
    /// Saves the loaded data to file targeting filename stored in MFCDoc?
    /// </summary>
	bool SaveDataToFile();

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

#ifndef _DEBUG  // debug version in TextView.cpp
inline MFCDoc* TextView::GetDocument() const
   { return reinterpret_cast<MFCDoc*>(m_pDocument); }
#endif

