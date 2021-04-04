// ***********************************************************************
// Code Created by James Michael Armstrong (https://github.com/BlazesRus)
// ***********************************************************************
#pragma once

#include "..\DLLAPI.h"

#include "AltFormula.hpp"
#include "..\AltNum\AltDec.hpp"

namespace BlazesRusCode
{
    template<typename VarType, typename FormulaType>
    class DLL_API DualAltFormula : public DualFormula<AltDec, AltFormula>
    {
    public:
    };
}