using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;

namespace ConsoleApplication1
{
	using CSharpGlobalCode.GlobalCode_ExperimentalCode;
	class Program
    {
        static void Main(string[] args)
        {
			////Console.WriteLine("Extraction Test=" + CSharpGlobalCode.GlobalCode_VariableConversionFunctions.VariableConversionFunctions.ExtractDecimalHalf(0.5));
			//SuperDec_ExtraDec32_19Decimal Value01 = (SuperDec_ExtraDec32_19Decimal)1.5;
			//Console.WriteLine("CurrentValue=" + Value01);
			//SmallDec Value02 = (SmallDec) Value01;
			//Console.WriteLine("CurrentValue=" + Value02);
			//Value02 += Value01;
			//Console.WriteLine("CurrentValue=" + Value02);
			SmallDec Value01 = (SmallDec)1.5;
			SuperDec_Int32_9Decimal Value02 = (SuperDec_Int32_9Decimal)Value01;
			Console.WriteLine("CurrentValue=" + (string) Value02);
			//SuperDec_ExtraDec32_19Decimal Value01 = BaseValue;
			//Value01 *= 2;
			//Console.WriteLine("CurrentValue=" + Value01);
			//Value01 = 10.5;
			//Value01 *= 10.25;
			//Console.WriteLine("CurrentValue=" + Value01);
			System.Threading.Thread.Sleep(4000);
        }
    }
}
