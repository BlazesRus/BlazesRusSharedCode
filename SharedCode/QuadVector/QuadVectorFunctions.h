// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
// ***********************************************************************
#pragma once
#ifndef QuadVectorFunctions_IncludeGuard
#define QuadVectorFunctions_IncludeGuard

#include "QuadVector.h"
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

/// <summary>
/// Class named QuadVectorFunctions.
/// </summary>
class QuadVectorFunctions
{
public:
    //Returns QuadValue from string;returns value of (0.0,0.0,0.0,0.0) if either invalid string sent
/// <summary>
/// Reads the quad vector from string.
/// </summary>
/// <param name="LineString">The line string.</param>
/// <returns>QuadVector</returns>
    static QuadVector ReadQuadVectorFromString(std::string LineString);
    /// <summary>
    /// Quads the vector to string conversion.
    /// </summary>
    /// <param name="TempValue">The temporary value.</param>
    /// <returns>std.string</returns>
    static std::string QuadVectorToStringConversion(QuadVector TempValue);
    /// <summary>
    /// Reads the quad vector list from string.
    /// </summary>
    /// <param name="LineString">The line string.</param>
    /// <returns>QuadVectorList</returns>
    static QuadVectorList ReadQuadVectorListFromString(std::string LineString);
    /// <summary>
    /// Initializes a new instance of the <see cref="QuadVectorFunctions"/> class.
    /// </summary>
    QuadVectorFunctions();
    /// <summary>
    /// Finalizes an instance of the <see cref="QuadVectorFunctions"/> class.
    /// </summary>
    ~QuadVectorFunctions();
};
#endif
