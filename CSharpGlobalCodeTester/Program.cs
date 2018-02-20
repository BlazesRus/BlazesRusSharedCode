using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_ExperimentalCode;

namespace CSharpGlobalCodeTester
{
    class Program
    {
        static void Main(string[] args)
        {
            SmallDec Self = (SmallDec)1.1;
            SmallDec Value = (SmallDec)"1.1452";
            Self *= Value;
            Self = (SmallDec)"0.1";
            Value = (SmallDec)"0.1";
            Self /= Value;
            Self = (SmallDec)"1.0";
            Value = (SmallDec)"0.1";
            Self *= Value;
        }
    }
}
