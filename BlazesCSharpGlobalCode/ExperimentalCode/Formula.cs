using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpGlobalCode.ExperimentalCode
{
    class FormulaDatabase
    {
        Dictionary<string, MediumDec> VariableStorage = new Dictionary<string, MediumDec>();
        class Formula
        {
        }
        Dictionary<string, Formula> FormulaStorage = new Dictionary<string, Formula>();
    }
}
