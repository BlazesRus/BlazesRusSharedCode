// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
/*	Code Created by James Michael Armstrong (NexusName:BlazesRus)(https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/
#pragma once
#ifndef QuadVector_IncludeGuard
#define QuadVector_IncludeGuard

#include <string>

#ifdef BlazesSharedCode_LocalLayout
#ifndef DLL_API
#ifdef UsingBlazesSharedCodeDLL
#define DLL_API __declspec(dllimport)
#elif defined(BLAZESSharedCode_LIBRARY)
#define DLL_API __declspec(dllexport)
#else
#define DLL_API
#endif
#endif
#else
#include "..\DLLAPI.h"
#endif

#ifdef BlazesSharedCode_LocalLayout//(Local version style layout)
#include "StringVectorList.h"
#include "VariableList.h"
#else
#include "..\VariableLists\StringVectorList.h"
#include "..\VariableLists\VariableList.h"
#if defined(IncludeAltDec)
#include "..\AltNum\MediumDec.hpp"
#endif
#endif

/// <summary>
/// Class named QuadVector.
/// </summary>
class DLL_API QuadVector
{
public:
#if defined(IncludeAltDec)//Default to MediumDec if not using excluder preprocessor
    /// <summary>
    /// The position x
    /// </summary>
    MediumDec PositionX = MediumDec::Zero;
    /// <summary>
    /// The position y
    /// </summary>
    MediumDec PositionY = MediumDec::Zero;
    /// <summary>
    /// The position z
    /// </summary>
    MediumDec PositionZ = MediumDec::Zero;
    /// <summary>
    /// The position w
    /// </summary>
    MediumDec PositionW = MediumDec::Zero;
#else
    /// <summary>
    /// The position x
    /// </summary>
    double PositionX = 0.0;
    /// <summary>
    /// The position y
    /// </summary>
    double PositionY = 0.0;
    /// <summary>
    /// The position z
    /// </summary>
    double PositionZ = 0.0;
    /// <summary>
    /// The position w
    /// </summary>
    double PositionW = 0.0;
#endif
    //Store values in Position in vector
/// <summary>
/// Stores the index of the in vector.
/// </summary>
/// <param name="index">The index.</param>
/// <param name="TempValue">The temporary value.</param>
    void StoreInVectorIndex(int index, double TempValue);
    //Get value based on index value
#if defined(IncludeAltDec)
/// <summary>
/// Gets the vector value.
/// </summary>
/// <param name="index">The index.</param>
/// <returns>MediumDec</returns>
    MediumDec
#else
/// <summary>
/// Gets the vector value.
/// </summary>
/// <param name="index">The index.</param>
/// <returns>double</returns>
    double
#endif
        GetVectorValue(int index);
    //Reconstruct as string
    //converts variables back into string format that havok uses in files(0.000000 0.000000 0.000000 0.000000)
/// <summary>
/// Converts to string.
/// </summary>
/// <returns>std.string</returns>
    std::string ConvertToString();
    //Reconstruct as Vector
#if defined(IncludeAltDec)
/// <summary>
/// Converts to list.
/// </summary>
/// <returns>VariableList&lt;VariableType&gt;</returns>
    VariableList<MediumDec>
#else
/// <summary>
/// Converts to list.
/// </summary>
/// <returns>DoubleList</returns>
    DoubleList
#endif
        ConvertToList();
    //Construct QuadVector from String
/// <summary>
/// Reads the quad vector from string.
/// </summary>
/// <param name="LineString">The line string.</param>
    void ReadQuadVectorFromString(std::string LineString);
    /// <summary>
    /// Initializes a new instance of the <see cref="QuadVector"/> class.
    /// </summary>
    /// <param name="TempString">The temporary string.</param>
    QuadVector(std::string TempString);
    /// <summary>
    /// Initializes a new instance of the <see cref="QuadVector"/> class.
    /// </summary>
    QuadVector();
    /// <summary>
    /// Finalizes an instance of the <see cref="QuadVector"/> class.
    /// </summary>
    ~QuadVector();
};

/// <summary>
/// Class named QuadVectorList.
/// Implements the <see cref="VariableList{QuadVector}" />
/// </summary>
/// <seealso cref="VariableList{QuadVector}" />
class DLL_API QuadVectorList : public VariableList < QuadVector >
{
    //************************************
    // Alias for Add(Fix compiler error of thinking Add(TempValue) has TempValue as double)
    // Method:    AddElement
    // FullName:  QuadVectorList::AddElement
    // Access:    private
    // Returns:   void
    // Qualifier:
    // Parameter: QuadVector TempValue
    //************************************
/// <summary>
/// Adds the element.
/// </summary>
/// <param name="TempValue">The temporary value.</param>
    void AddElement(QuadVector TempValue)
    {
        Add(TempValue);
    }
    /// <summary>
    /// Adds the data.
    /// </summary>
    /// <returns>size_t</returns>
    size_t AddData();
    /// <summary>
    /// Converts the string to vector list.
    /// </summary>
    /// <param name="Content">The content.</param>
    void ConvertStringToVectorList(std::string Content);
};

/// <summary>
/// Class named QuadDoubleVector.
/// </summary>
class DLL_API QuadDoubleVector
{
public:
    /// <summary>
    /// The position x
    /// </summary>
    double PositionX = 0.0;
    /// <summary>
    /// The position y
    /// </summary>
    double PositionY = 0.0;
    /// <summary>
    /// The position z
    /// </summary>
    double PositionZ = 0.0;
    /// <summary>
    /// The position w
    /// </summary>
    double PositionW = 0.0;
    //Store values in Position in vector
/// <summary>
/// Stores the index of the in vector.
/// </summary>
/// <param name="index">The index.</param>
/// <param name="TempValue">The temporary value.</param>
    void StoreInVectorIndex(int index, double TempValue);
    //Get value based on index value
/// <summary>
/// Gets the vector value.
/// </summary>
/// <param name="index">The index.</param>
/// <returns>double</returns>
    double GetVectorValue(int index);
    //Reconstruct as string
/// <summary>
/// Converts to string.
/// </summary>
/// <returns>std.string</returns>
    std::string ConvertToString();

    ////Reconstruct as Vector(Causing error C2059 '(' for some reason)
    //DoubleList ConvertToList()
    //{
    //	DoubleList TempValue;
    //	for (int i = 0; i < 4; i++)
    //	{
    //		TempValue.Add(GetVectorValue(i));
    //	}
    //	return TempValue;
    //}

/// <summary>
/// Construct QuadDoubleVector from String
/// </summary>
/// <param name="LineString">The string.</param>
    void ReadQuadVectorFromString(std::string LineString);
    /// <summary>
    /// Initializes a new instance of the <see cref="QuadDoubleVector"/> class.
    /// </summary>
    /// <param name="TempString">The temporary string.</param>
    QuadDoubleVector(std::string TempString);
    /// <summary>
    /// Initializes a new instance of the <see cref="QuadDoubleVector"/> class.
    /// </summary>
    QuadDoubleVector();
    /// <summary>
    /// Finalizes an instance of the <see cref="QuadDoubleVector"/> class.
    /// </summary>
    ~QuadDoubleVector();
};

/// <summary>
/// Class named QuadDoubleVectorList.
/// Implements the <see cref="VariableList{QuadDoubleVector}" />
/// </summary>
/// <seealso cref="VariableList{QuadDoubleVector}" />
class DLL_API QuadDoubleVectorList : public VariableList < QuadDoubleVector >
{
    //************************************
    // Alias for Add(Fix compiler error of thinking Add(TempValue) has TempValue as double)
    // Method:    AddElement
    // FullName:  QuadDoubleVectorList::AddElement
    // Access:    private
    // Returns:   void
    // Qualifier:
    // Parameter: QuadDoubleVector TempValue
    //************************************
/// <summary>
/// Adds the element.
/// </summary>
/// <param name="TempValue">The temporary value.</param>
    void AddElement(QuadDoubleVector TempValue)
    {
        Add(TempValue);
    }
    /// <summary>
    /// Adds the data.
    /// </summary>
    /// <returns>size_t</returns>
    size_t AddData();
    /// <summary>
    /// Converts the string to vector list.
    /// </summary>
    /// <param name="Content">The content.</param>
    void ConvertStringToVectorList(std::string Content);
};
#endif
