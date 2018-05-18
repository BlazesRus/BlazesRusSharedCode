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
        /// <summary>
        /// Defines the entry point of the application.
        /// </summary>
        /// <param name="args">The arguments.</param>
        public static void Main(string[] args)
        {
            WFWeaponStatus ConsoleStatusInfo = new WFWeaponStatus("WeaponInfo.txt");
            ConsoleStatusInfo.CalculateFinalModifiers();
            //system("PAUSE");
        }
#endif
    }
}