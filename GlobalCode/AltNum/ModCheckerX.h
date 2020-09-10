#pragma once

#include "AltDec.h"

/// <summary>
/// (AltDec Version)Performs remainder/Mod operation then saves division result
/// C = A – B * (A / B)
/// </summary>
class ModCheckerX
{//based on https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/
public:
    AltDec divRes = AltDec::Zero;
    AltDec C = AltDec::Zero;
    /// <summary>
    /// Calculates if remainder is zero.
    /// </summary>
    /// <param name="a">a.</param>
    /// <param name="b">The b.</param>
    /// <returns>bool</returns>
    bool CalcIfZero(AltDec a, AltDec b)
    {
        divRes = a / b;
        C = a - b * divRes;
        if (C == 0)
        {
            return true;
        }
        return false;
    }
};