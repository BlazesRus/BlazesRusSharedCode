/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/MultiPlatformGlobalCode
*/

using System;

namespace CSharpGlobalCode.ExperimentalCode
{
    using System.Collections.Generic;
    using System.Globalization;
    using System.Windows;
    using static VariableConversionFunctions.VariableConversionFunctions;

    /// <summary>
    /// GlobalCode to reuse between SuperDec type names
    /// </summary>
    public static class SuperDecGlobalCode
    {
        // SuperDec generic reused code section

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Condition"></param>
        /// <param name="X"></param>
        /// <param name="Y"></param>
        /// <returns></returns>
        public static dynamic ConditionalReturn(bool Condition, dynamic X, dynamic Y)
        {
            return Condition ? X : Y;
        }


        //End of SuperDec generic reused code section

        //Trigonometrical method section

        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static double RadianToAngleAsDouble(dynamic Value)
        {
            var ConvertedValue = (double)Value;

            return 0.0;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static double AngleToRadianAsDouble(dynamic Value)
        {
            var ConvertedValue = (double)Value;

            return 0.0;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static double SinFromAngleAsDouble(dynamic Value)
        {
            var ConvertedValue = (double)Value%360.0;

            return 0.0;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static double ConFromAngleAsDouble(dynamic Value)
        {
            var ConvertedValue = (double)Value%360.0;

            return 0.0;
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="Value"></param>
        /// <returns></returns>
        public static double TransFromAngleAsDouble(dynamic Value)
        {
            var ConvertedValue = (double)Value%360.0;

            return 0.0;
        }
        //end of Trigonometrical method section
        public static int[] PowerOfTens = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
        public static long[] PowerOfTens64Bit = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000 };
        /// <summary>
        /// Returns the factorial Number from N
        /// (From https://stackoverflow.com/questions/38917692/sin-cos-funcs-without-math-h Answer for using in Taylor series)
        /// </summary>
        /// <param name="n">The n.</param>
        /// <returns></returns>
        public static int Fact(int n)
        {
            return n <= 0 ? 1 : n * Fact(n - 1);
        }
    }
    //public interface SuperDecBase
    //{
    //    //public static SuperDecBase Sum(IEnumerable<SuperDecBase> Value);
    //}
}