using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_ExperimentalCode;

namespace BlazesMultiTool
{
    class MultitoolConsole
    {
#if EnableToolConsole
        public static void Main(string[] args)
        {
            WFWeaponStatus ConsoleStatusInfo = new WFWeaponStatus("WeaponInfo.txt");
            ConsoleStatusInfo.CalculateFinalModifiers();
            //system("PAUSE");
        }
#endif
    }
}