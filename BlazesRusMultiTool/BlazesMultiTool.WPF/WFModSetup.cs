using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_ExperimentalCode;

namespace BlazesMultiTool
{
    public class WFModSetup : List<WFMod>
    {
        /// <summary>
        /// The mod stat total (updated with CalculateModTotal)
        /// </summary>
        public Dictionary<string, SmallDec> TotalStats;
        /// <summary>
        /// Initializes a new instance of the <see cref="WFModSetup"/> class.
        /// </summary>
        public WFModSetup()
        {
            TotalStats = new Dictionary<string, SmallDec>();
        }
        /// <summary>
        /// Calculates the mod stat total.
        /// </summary>
        public void CalculateModTotal()
        {
            TotalStats = new Dictionary<string, SmallDec>();
            WFMod CurrentMod;
            for(int Index=0;Index<this.Count;++Index)
            {
                CurrentMod = this.ElementAt(Index);
                foreach(var Stat in CurrentMod.ModStats.Keys)
                {
                    if(TotalStats.ContainsKey(Stat))
                    {
                        TotalStats[Stat] += CurrentMod.ModStats[Stat];
                    }
                    else
                    {
                        TotalStats.Add(Stat, CurrentMod.ModStats[Stat]);
                    }
                }
            }
        }
    }
}
