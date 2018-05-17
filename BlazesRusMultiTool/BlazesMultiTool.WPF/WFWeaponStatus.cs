using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharpGlobalCode.GlobalCode_ExperimentalCode;

namespace BlazesMultiTool
{
    public enum WeaponTypeStatus : byte
    {
        Primary = 0, Secondary = 1, Pistol = 2, Melee=3, Sniper, Rifle, Shotgun, Secondary_Shotgun
    };
    public enum PreferedSecondaryCombination
    {
        /// <summary>
        /// Armor reduction on Status chance(Lightning+Poison)
        /// </summary>
        CorrosiveDamage = 0,
        /// <summary>
        /// Half Base Hp debuff on status chance(Cold+Poison)
        /// </summary>
        ViralDamage = 1,
        /// <summary>
        /// (Fire+Cold)
        /// </summary>
        BlastDamage = 2,
        /// <summary>
        /// (Lightning+Cold)
        /// </summary>
        MagneticDamage = 3,
        /// <summary>
        /// (Lightning+Fire)
        /// </summary>
        RadiationDamage = 4,
        /// <summary>
        /// Toxin Area of Effect Damage on Status(Fire+Poison)
        /// </summary>
        GasDamage = 5
    }
    public class WFBaseWeapon
    {
        string Name;
        public WeaponTypeStatus WeaponType;
        public SmallDec Speed;
        public SmallDec PunctureDamage;
        public SmallDec ImpactDamage;
        public SmallDec SlashDamage;
        /// <summary>
        /// Toxin damage (DOT on Status Chance)
        /// </summary>
        public SmallDec PoisonDamage;
        public SmallDec FireDamage;
        public SmallDec ColdDamage;
        /// <summary>
        /// Electricity Damage (Stun and shock arc on Status Chance)
        /// </summary>
        public SmallDec LightningDamage;

        /// <summary>
        /// (Fire+Cold)
        /// </summary>
        public SmallDec BlastDamage;
        /// <summary>
        /// Toxin Area of Effect Damage on Status(Fire+Poison)
        /// </summary>
        public SmallDec GasDamage;
        /// <summary>
        /// Half Base Hp debuff on status chance (Cold+Poison)
        /// </summary>
        public SmallDec ViralDamage;
        /// <summary>
        /// Armor reduction on Status chance(Lightning+Poison)
        /// </summary>
        public SmallDec CorrosiveDamage;
        /// <summary>
        /// (Lightning+Cold)
        /// </summary>
        public SmallDec MagneticDamage;
        /// <summary>
        /// (Lightning+Fire)
        /// </summary>
        public SmallDec RadiationDamage;


        public SmallDec StatusChance;
        public SmallDec CritMultiplier;
        public SmallDec CritChance;
        /// <summary>
        /// Initializes a new instance of the <see cref="WFBaseWeapon"/> class.
        /// </summary>
        public WFBaseWeapon()
        {
            Name = "";
            WeaponType = WeaponTypeStatus.Primary;
            Speed = SmallDec.One;
            PunctureDamage = SmallDec.Zero;
            ImpactDamage = SmallDec.Zero;
            SlashDamage = SmallDec.Zero;
            PoisonDamage = SmallDec.Zero;
            FireDamage = SmallDec.Zero;
            ColdDamage = SmallDec.Zero;
            LightningDamage = SmallDec.Zero;
            BlastDamage = SmallDec.Zero;
            GasDamage = SmallDec.Zero;
            ViralDamage = SmallDec.Zero;
            CorrosiveDamage = SmallDec.Zero;
            MagneticDamage = SmallDec.Zero;
            RadiationDamage = SmallDec.Zero;
            StatusChance = SmallDec.Zero;
            CritMultiplier = SmallDec.Zero;
            CritChance = SmallDec.Zero;
        }
        /// <summary>
        /// Loads the weapon data.
        /// </summary>
        /// <param name="FileName">Name of the file to load data from.</param>
        public void LoadWeaponData(string FileName)
        {
            List<string> FileData = CSharpGlobalCode.GlobalMiscCode.FileAccessCommands.ReturnFileContentsAsList(FileName);
            string LineData;
            string AttributeName = "";
            string ValueData;
            var builder = new StringBuilder();
            for (int Index = 0; Index < FileData.Count; ++Index)
            {
                LineData = FileData.ElementAt(Index);
                //Formating per line= (Name/Cost/StatName):Value;
                foreach (char StringChar in LineData)
                {
                    if (StringChar == ':')
                    {
                        AttributeName = builder.ToString();
                        builder.Clear();
                    }
                    else if (StringChar == ';' || StringChar == '%')
                    {
                        ValueData = builder.ToString();
                        switch(AttributeName)
                        {
                            case "Name":
                                Name = ValueData;
                                break;
                            case "WeaponType":
                                if (ValueData == "Secondary")
                                {
                                    WeaponType = WeaponTypeStatus.Secondary;
                                }
                                else if (ValueData == "Melee")
                                {
                                    WeaponType = WeaponTypeStatus.Melee;
                                }
                                else
                                {
                                    WeaponType = WeaponTypeStatus.Primary;
                                }
                                break;
                            case "Speed":
                                Speed = (SmallDec)ValueData;
                                break;
                            case "StatusChance":
                                StatusChance = (SmallDec)ValueData;
                                break;
                            case "CritChance":
                                CritChance = (SmallDec)ValueData;
                                break;
                            case "CritMultiplier":
                                CritMultiplier = (SmallDec)ValueData;
                                break;
                            //Physical Damage Types
                            case "PunctureDamage":
                                PunctureDamage = (SmallDec)ValueData;
                                break;
                            case "ImpactDamage":
                                ImpactDamage = (SmallDec)ValueData;
                                break;
                            case "SlashDamage":
                                SlashDamage = (SmallDec)ValueData;
                                break;
                            //Primary Elemental Damage Types
                            case "PoisonDamage":
                                PoisonDamage = (SmallDec)ValueData;
                                break;
                            case "LightningDamage":
                                LightningDamage = (SmallDec)ValueData;
                                break;
                            case "FireDamage":
                                PunctureDamage = (SmallDec)ValueData;
                                break;
                            case "ColdDamage":
                                PunctureDamage = (SmallDec)ValueData;
                                break;
                            //Secondary Elemental Damage Types
                            case "BlastDamage":
                                BlastDamage = (SmallDec)ValueData;
                                break;
                            case "GasDamage":
                                GasDamage = (SmallDec)ValueData;
                                break;
                            case "ViralDamage":
                                ViralDamage = (SmallDec)ValueData;
                                break;
                            case "CorrosiveDamage":
                                CorrosiveDamage = (SmallDec)ValueData;
                                break;
                            case "MagneticDamage":
                                MagneticDamage = (SmallDec)ValueData;
                                break;
                            case "RadiationDamage":
                                RadiationDamage = (SmallDec)ValueData;
                                break;
                        }
                    }
                    else
                    {
                        builder.Append(StringChar);
                    }
                }
            }
        }
        /// <summary>
        /// Initializes a new instance of the <see cref="WFBaseWeapon"/> class.
        /// </summary>
        /// <param name="FileName">Name of the file to load data from.</param>
        public WFBaseWeapon(string FileName)
        {
            PunctureDamage = SmallDec.Zero;
            ImpactDamage = SmallDec.Zero;
            SlashDamage = SmallDec.Zero;
            PoisonDamage = SmallDec.Zero;
            FireDamage = SmallDec.Zero;
            ColdDamage = SmallDec.Zero;
            LightningDamage = SmallDec.Zero;
            BlastDamage = SmallDec.Zero;
            GasDamage = SmallDec.Zero;
            LoadWeaponData(FileName);
        }
    }
    /// <summary>
    /// 
    /// </summary>
    public class WFWeaponStatus
    {
        public WFBaseWeapon EquippedWeapon;
        /// <summary>
        /// Weapon Damage+Multi-shot effective multiplier to damage
        /// </summary>
        public SmallDec EffectiveMultiplier;
        /// <summary>
        /// Shots per second (or Attack Speed in case of Melee)
        /// </summary>
        public SmallDec Speed;
        public SmallDec CritMultiplier;
        public SmallDec CritChance;
        public SmallDec PunctureDamage;
        public SmallDec ImpactDamage;
        public SmallDec SlashDamage;

        //Primary Elemental Damages
        public SmallDec PoisonDamage;
        /// <summary>
        /// Electricity Damage
        /// </summary>
        public SmallDec LightningDamage;
        public SmallDec FireDamage;
        public SmallDec ColdDamage;

        //Secondary Elemental Damages
        /// <summary>
        /// (Fire+Cold)
        /// </summary>
        public SmallDec BlastDamage;
        /// <summary>
        /// (Fire+Poison)
        /// </summary>
        public SmallDec GasDamage;
        /// <summary>
        /// (Cold+Poison)
        /// </summary>
        public SmallDec ViralDamage;
        /// <summary>
        /// (Lightning+Poison)
        /// </summary>
        public SmallDec CorrosiveDamage;
        /// <summary>
        /// (Lightning+Cold)
        /// </summary>
        public SmallDec MagneticDamage;
        /// <summary>
        /// (Lightning+Fire)
        /// </summary>
        public SmallDec RadiationDamage;
        /// <summary>
        /// The effective status chance after Multishot mods applied
        /// </summary>
        public SmallDec EffectiveStatusChance;
        /// <summary>
        /// Base damage of weapon determines added elemental damage to weapon
        /// </summary>
        public SmallDec BaseDamage;
        public SmallDec CombinedRawDamage;
        /// <summary>
        /// The combined raw DPS without accounting for accuracy or reloading(assuming have infinite magazine buff)
        /// </summary>
        public SmallDec RawDPSWithoutReload;
        public WFModSetup EquippedMods;
        private PreferedSecondaryCombination primaryPref = PreferedSecondaryCombination.CorrosiveDamage;
        private PreferedSecondaryCombination secondaryPref = PreferedSecondaryCombination.BlastDamage;

        /// <summary>
        /// Gets or sets the primary elemental combination preference
        /// </summary>
        /// <value>
        /// The secondary elemental combination preference
        /// </value>
        public PreferedSecondaryCombination PrimaryPref
        { get => primaryPref;
            set
            {
                primaryPref = value;
                //Determine Secondary Preference based on remaining combinations
                switch(value)
                {
                    case PreferedSecondaryCombination.BlastDamage:
                        SecondaryPref = PreferedSecondaryCombination.CorrosiveDamage;
                        break;
                    case PreferedSecondaryCombination.CorrosiveDamage:
                        SecondaryPref = PreferedSecondaryCombination.BlastDamage;
                        break;
                    case PreferedSecondaryCombination.GasDamage:
                        SecondaryPref = PreferedSecondaryCombination.MagneticDamage;
                        break;
                    case PreferedSecondaryCombination.MagneticDamage:
                        SecondaryPref = PreferedSecondaryCombination.GasDamage;
                        break;
                    case PreferedSecondaryCombination.RadiationDamage:
                        SecondaryPref = PreferedSecondaryCombination.ViralDamage;
                        break;
                    case PreferedSecondaryCombination.ViralDamage:
                        SecondaryPref = PreferedSecondaryCombination.RadiationDamage;
                        break;
                }
            }
        }
        /// <summary>
        /// The secondary elemental combination preference (automatically set when PrimaryPref is set with remaining possible dual combinations of elements)
        /// </summary>
        public PreferedSecondaryCombination SecondaryPref = PreferedSecondaryCombination.BlastDamage;

        public void CalculateFinalModifiers()
        {
            EquippedMods.CalculateModTotal();
            EffectiveMultiplier = EquippedMods.TotalStats.ContainsKey("Multishot")?(SmallDec.One+EquippedMods.TotalStats["Damage"]/100) * (SmallDec.One + EquippedMods.TotalStats["Multishot"]/100) : SmallDec.One + EquippedMods.TotalStats["Damage"] / 100;
            EffectiveStatusChance = EquippedMods.TotalStats.ContainsKey("Multishot") ? (SmallDec.One + EquippedMods.TotalStats["Multishot"] / 100) * (1+EquippedMods.TotalStats["Status Chance"]/100): (1 + EquippedMods.TotalStats["Status Chance"] / 100);
            //Combined EffectiveStatusMultiplier from mods to weapon status
            EffectiveStatusChance *= EquippedWeapon.StatusChance;
            if(EquippedMods.TotalStats.ContainsKey("Increased Fire Rate")&& EquippedWeapon.WeaponType!= WeaponTypeStatus.Melee)
            {
                Speed = (SmallDec.One + EquippedMods.TotalStats["Increased Fire Rate"] / 100)*EquippedWeapon.Speed;
            }
            else if (EquippedMods.TotalStats.ContainsKey("Increased Attack Speed") && EquippedWeapon.WeaponType == WeaponTypeStatus.Melee)
            {
                Speed = (SmallDec.One + EquippedMods.TotalStats["Increased Attack Speed"] / 100) * EquippedWeapon.Speed;
            }
            else
            {
                Speed = EquippedWeapon.Speed;
            }
            BaseDamage = EquippedWeapon.SlashDamage + EquippedWeapon.ImpactDamage + EquippedWeapon.PunctureDamage;
            BaseDamage += EquippedWeapon.PoisonDamage + EquippedWeapon.LightningDamage + EquippedWeapon.FireDamage + EquippedWeapon.ColdDamage;
            BaseDamage += EquippedWeapon.BlastDamage + EquippedWeapon.CorrosiveDamage + EquippedWeapon.GasDamage 
            + EquippedWeapon.MagneticDamage + EquippedWeapon.RadiationDamage + EquippedWeapon.ViralDamage;
            SlashDamage = EquippedMods.TotalStats.ContainsKey("Increased Slash Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Slash Damage"] / 100) * EquippedWeapon.SlashDamage : EquippedWeapon.SlashDamage;
            ImpactDamage = EquippedMods.TotalStats.ContainsKey("Increased Impact Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Impact Damage"] / 100) * EquippedWeapon.ImpactDamage : EquippedWeapon.ImpactDamage;
            PunctureDamage = EquippedMods.TotalStats.ContainsKey("Increased Puncture Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Puncture Damage"] / 100) * EquippedWeapon.PunctureDamage : EquippedWeapon.PunctureDamage;
            SlashDamage *= EffectiveMultiplier; ImpactDamage *= EffectiveMultiplier; PunctureDamage *= EffectiveMultiplier;
            //Add Elemental Damage based on Base Damage
            PoisonDamage = EquippedMods.TotalStats.ContainsKey("Increased Poison Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Poison Damage"] / 100) * BaseDamage) + EquippedWeapon.PoisonDamage : EquippedWeapon.PoisonDamage;
            LightningDamage = EquippedMods.TotalStats.ContainsKey("Increased Lightning Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Lightning Damage"] / 100) * BaseDamage) + EquippedWeapon.LightningDamage : EquippedWeapon.LightningDamage;
            FireDamage = EquippedMods.TotalStats.ContainsKey("Increased Fire Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Lightning Damage"] / 100) * BaseDamage) + EquippedWeapon.LightningDamage : EquippedWeapon.LightningDamage;
            ColdDamage = EquippedMods.TotalStats.ContainsKey("Increased Cold Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Cold Damage"] / 100) * BaseDamage) + EquippedWeapon.ColdDamage : EquippedWeapon.ColdDamage;
            PoisonDamage *= EffectiveMultiplier; LightningDamage *= EffectiveMultiplier; FireDamage *= EffectiveMultiplier; ColdDamage *= EffectiveMultiplier;
            BlastDamage = EquippedWeapon.BlastDamage * EffectiveMultiplier; RadiationDamage = EquippedWeapon.RadiationDamage * EffectiveMultiplier; ViralDamage = EquippedWeapon.ViralDamage * EffectiveMultiplier;
            CorrosiveDamage = EquippedWeapon.CorrosiveDamage * EffectiveMultiplier; GasDamage = EquippedWeapon.GasDamage * EffectiveMultiplier; MagneticDamage = EquippedWeapon.MagneticDamage * EffectiveMultiplier;
            CombinedRawDamage = SlashDamage + ImpactDamage + PunctureDamage + PoisonDamage + LightningDamage + FireDamage + ColdDamage + BlastDamage + RadiationDamage + CorrosiveDamage + GasDamage + ViralDamage + MagneticDamage;
            RawDPSWithoutReload = CombinedRawDamage * Speed;
            //Calculate Final Secondary Elemental Damage based on mod order preference etc
            PreferedSecondaryCombination CurrentPref = PrimaryPref;
            for (int PrefNum=0;PrefNum<2;++PrefNum)
            {
                switch(PrefNum)
                {
                    case 1:
                        CurrentPref = SecondaryPref;
                        break;
                }
                //if (EquippedWeapon.CorrosiveDamage > SmallDec.Zero){}
                //else if (EquippedWeapon.BlastDamage > SmallDec.Zero){}
                //else if (EquippedWeapon.RadiationDamage > SmallDec.Zero){}
                //else if (EquippedWeapon.ViralDamage > SmallDec.Zero){}
                //else if (EquippedWeapon.GasDamage > SmallDec.Zero){}
                //else if (EquippedWeapon.MagneticDamage > SmallDec.Zero){}
                if(CurrentPref== PreferedSecondaryCombination.BlastDamage&&FireDamage>SmallDec.Zero&&ColdDamage>SmallDec.Zero)
                {
                    BlastDamage += FireDamage + ColdDamage;
                    FireDamage = SmallDec.Zero; ColdDamage = SmallDec.Zero;
                }
                else if (CurrentPref == PreferedSecondaryCombination.CorrosiveDamage && LightningDamage > SmallDec.Zero && PoisonDamage > SmallDec.Zero)
                {
                    CorrosiveDamage += LightningDamage + PoisonDamage;
                    LightningDamage = SmallDec.Zero; PoisonDamage = SmallDec.Zero;
                }
                else if (CurrentPref == PreferedSecondaryCombination.GasDamage && FireDamage > SmallDec.Zero && PoisonDamage > SmallDec.Zero)
                {
                    GasDamage += FireDamage + PoisonDamage;
                    FireDamage = SmallDec.Zero; PoisonDamage = SmallDec.Zero;
                }
                else if (CurrentPref == PreferedSecondaryCombination.MagneticDamage && LightningDamage > SmallDec.Zero && ColdDamage > SmallDec.Zero)
                {
                    MagneticDamage += LightningDamage + ColdDamage;
                    LightningDamage = SmallDec.Zero; ColdDamage = SmallDec.Zero;
                }
                else if (CurrentPref == PreferedSecondaryCombination.RadiationDamage && FireDamage > SmallDec.Zero && LightningDamage > SmallDec.Zero)
                {
                    RadiationDamage += FireDamage + LightningDamage;
                    FireDamage = SmallDec.Zero; LightningDamage = SmallDec.Zero;
                }
                else if (CurrentPref == PreferedSecondaryCombination.ViralDamage && PoisonDamage > SmallDec.Zero && ColdDamage > SmallDec.Zero)
                {
                    ViralDamage += PoisonDamage + ColdDamage;
                    PoisonDamage = SmallDec.Zero; ColdDamage = SmallDec.Zero;
                }
            }

        }
    }
}
