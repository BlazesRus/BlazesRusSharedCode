using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


/* Requires Assembly references of:
PresenationCore.dll,
PresenationFramework.dll,
WindowsBase.dll 
System.Xaml.dll
*/
namespace CSharpGlobalCodeTester
{
    using CSharpGlobalCode.GlobalCode_ExperimentalCode;
    class Program
    {
        static void Main(string[] args)
        {
            SmallDec Value01 = 1.5;
            Value01 *= Value01;
            Value01 *= Value01;
            Value01 *= 2;
            Value01 *= 1.5;
            float FloatTest = 1.5f;
            FloatTest *= 1.5f;
            MediumSuperDec Value02 = (MediumSuperDec)Value01;
            Console.WriteLine("CurrentValue=" + (string)Value02);

            System.Threading.Thread.Sleep(4000);
        }
    }
}
