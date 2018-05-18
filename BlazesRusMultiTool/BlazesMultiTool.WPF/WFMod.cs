using CSharpGlobalCode.GlobalCode_ExperimentalCode;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlazesMultiTool
{
    public enum WFPolarity: byte
    {
        Undefined = 0, Offensive = 1, Defensive = 2, Utility = 3, Augment = 4
    };
    public class WFMod
    {
        public Dictionary<string, SmallDec> ModStats;
        public string ModName = "";
        /// <summary>
        /// The cost of the mod
        /// </summary>
        public int Cost;
        /// <summary>
        /// The rank of the mod (Mods start at Rank 0)
        /// </summary>
        public int Rank;
        public WFPolarity Polarity;
        public WFMod()
        {
            ModStats = new Dictionary<string, SmallDec>();
            Cost = 0;
            Rank = 0;
            Polarity = WFPolarity.Undefined;
        }
        public WFMod(string FileName)
        {
            ModStats = new Dictionary<string, SmallDec>();
            Polarity = WFPolarity.Undefined;
            List<string> FileData = CSharpGlobalCode.GlobalMiscCode.FileAccessCommands.ReturnFileContentsAsList(FileName);
            string LineData;
            string AttributeName="";
            var builder = new StringBuilder();
            for (int Index = 0; Index < FileData.Count; ++Index)
            {
                LineData = FileData.ElementAt(Index);
                //Formating per line= (Name/Cost/StatName):Value;
                foreach (char StringChar in LineData)
                {
                    if(StringChar==':')
                    {
                        AttributeName = builder.ToString();
                        builder.Clear();
                    }
                    else if(StringChar==';'||StringChar=='%')
                    {
                        if (AttributeName == "Name")
                        {
                            ModName = builder.ToString();
                        }
                        else if(AttributeName == "Cost")
                        {
                            Cost = CSharpGlobalCode.GlobalCode_VariableConversionFunctions.VariableConversionFunctions.ReadIntFromString(builder.ToString());
                        }
                        else if (AttributeName == "Rank")
                        {
                            Rank = CSharpGlobalCode.GlobalCode_VariableConversionFunctions.VariableConversionFunctions.ReadIntFromString(builder.ToString());
                        }
                        else if(AttributeName== "Increased Attack Speed"||AttributeName== "Increased Fire Rate" || AttributeName == "Fire Rate" || AttributeName == "Fire Rate")
                        {//Treat all varieties of Increased speed as one name
                            ModStats.Add("Increased Speed", (SmallDec)builder.ToString());
                        }
                        else if (AttributeName == "Critical Damage" || AttributeName == "Increased Critical Damage")
                        {
                            ModStats.Add("Increased Critical Damage", (SmallDec)builder.ToString());
                        }
                        else if (AttributeName == "Critical Chance" || AttributeName == "Increased Critical Chance")
                        {
                            ModStats.Add("Increased Critical Chance", (SmallDec)builder.ToString());
                        }
                        else
                        {
                            ModStats.Add(AttributeName, (SmallDec)builder.ToString());
                        }
                    }
                    else
                    {
                        builder.Append(StringChar);
                    }
                }
            }
        }
    }
}
