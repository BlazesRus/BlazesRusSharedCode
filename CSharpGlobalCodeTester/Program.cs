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
            SmallDec Self = (SmallDec)"0.1";
            SmallDec Value = (SmallDec)"0.1";
            Self /= Value;//Should equal 1
            Console.WriteLine("0.1 / 0.1 =" + Self.ToOptimalString());
            Self = (SmallDec)"1.9";
            Value = (SmallDec)"0.9";
            Self *= Value;//Should equal 1.71(success)
            Console.WriteLine("1.9 x 0.9=" + Self.ToOptimalString());
            Self = (SmallDec)"0.1";
            Value = (SmallDec)"0.5";
            Self /= Value;//Should equal 0.2
            Console.WriteLine("0.1 / 0.5 =" + Self.ToOptimalString());
            Self = (SmallDec)"0.95";
            Value = (SmallDec)"0.9";
            Self /= Value;//Should equal 1.055555555555556
            Console.WriteLine("0.95 / 0.9 =" + Self.ToOptimalString());
            Self = (SmallDec)"1.5";
            Value = (SmallDec)"0.25";
            Self /= Value;//Should equal 6
            Console.WriteLine("0.95 / 0.9 =" + Self.ToOptimalString());
            Self = (SmallDec)"0.5";
            Value = (SmallDec)"0.5";
            Self *= Value;//Should equal 0.25
            Console.WriteLine("0.5 x 0.5=" + Self.ToOptimalString());
            Console.ReadLine();
        }
    }
}
