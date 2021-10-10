// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#if !defined(XMLTagView_IncludeGuard)
#define XMLTagView_IncludeGuard

#include "MultiviewPrecompile.h"
#include "CustomTreeView.h"
#include "../OtherFunctions/MFCMacrosV3.h"
#include "XMLTagViewNode.h"
#include <typeinfo>
#include <string>
#include "MultiViewDoc.h"

/// <summary>
/// Class named XMLTagView.
/// Implements the <see cref="CustomTreeView{XMLTagViewNode}" />
/// </summary>
/// <seealso cref="CustomTreeView{XMLTagViewNode}" />
class XMLTagView : public CustomTreeView<XMLTagViewNode, MultiViewDoc>
{
    /// <summary>
    /// Initializes a new instance of the <see cref="XMLTagView"/> class.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    XMLTagView(std::string FilePath);
    /// <summary>
    /// Prevents a default instance of the <see cref="XMLTagView"/> class from being created.
    /// </summary>
    XMLTagView();
    /// <summary>
    /// Loads the data from file.
    /// </summary>
    /// <param name="FilePath">The file path.</param>
    /// <returns>bool</returns>
    bool LoadDataFromFile(std::string FilePath);

    MFC_RuntimeExtPart01Base02(XMLTagView, CustomTreeView, XMLTagViewNode, MultiViewDoc)
    //Any message map messages here
    MFC_RuntimeExtPart02(XMLTagView, CustomTreeView, XMLTagViewNode, MultiViewDoc)
};

MFC_RuntimeImplimentation(XMLTagView)

#endif
