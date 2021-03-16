#pragma once

namespace BlazesRusCode
{
    /// <summary>
    /// (AltNum based Version)Performs remainder/Mod operation then saves division result
    /// C = A – B * (A / B)
    /// </summary>
    template<typename VarType>
    class AltNumModChecker
    {//based on https://embeddedgurus.com/stack-overflow/2011/02/efficient-c-tip-13-use-the-modulus-operator-with-caution/
    public:
        VarType divRes = VarType::Zero;
        VarType C = VarType::Zero;
        /// <summary>
        /// Calculates if remainder is zero.
        /// </summary>
        /// <param name="a">a.</param>
        /// <param name="b">The b.</param>
        /// <returns>bool</returns>
        bool CalcIfZero(VarType a, VarType b)
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
}