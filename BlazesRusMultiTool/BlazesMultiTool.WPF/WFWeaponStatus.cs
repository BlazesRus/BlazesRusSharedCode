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
        /// <summary>
        /// The charge rate of Weapon (Zero means not used)
        /// </summary>
        public SmallDec ChargeRate = SmallDec.Zero;
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
        public WFWeaponStatus(string FileName)
        {
            EquippedWeapon = new WFBaseWeapon(FileName);
            EquippedMods = new WFModSetup();
        }
        public WFWeaponStatus()
        {
            EquippedWeapon = new WFBaseWeapon();
            EquippedMods = new WFModSetup();
        }
        public WFBaseWeapon EquippedWeapon;
        public WFBaseWeapon AlternativeWeaponMode;
        /// <summary>
        /// Weapon Damage+Multi-shot effective multiplier to damage
        /// </summary>
        public SmallDec EffectiveMultiplier;
        /// <summary>
        /// Shots per second (or Attack Speed in case of Melee)
        /// </summary>
        public SmallDec Speed;
        public SmallDec ChargeRate = SmallDec.Zero;
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
        /// The combined infinite magazine DPS without critical damage or accuracy calculated in 
        /// </summary>
        public SmallDec RawDPSWithoutReload;

        /// <summary>
        /// The combined infinite magazine DPS with smeeta 200% critical chance buff applied without accuracy etc calculated in
        /// </summary>
        public SmallDec SmeetaRawCritDPSOnInfMag;

        /// <summary>
        /// The combined infinite magazine DPS with smeeta 200% critical chance buff applied without accuracy etc calculated in for Alternative fire mode
        /// </summary>
        public SmallDec AlternativeSmeetaRawCritDPSOnInfMag;

        /// <summary>
        /// Shots per second (or Attack Speed in case of Melee)
        /// </summary>
        public SmallDec AlternativeSpeed;
        public SmallDec AlternativeCritMultiplier;
        public SmallDec AlternativeCritChance;
        public SmallDec AlternativePunctureDamage;
        public SmallDec AlternativeImpactDamage;
        public SmallDec AlternativeSlashDamage;

        //Primary Elemental Damages
        public SmallDec AlternativePoisonDamage;
        /// <summary>
        /// Electricity Damage
        /// </summary>
        public SmallDec AlternativeLightningDamage;
        public SmallDec AlternativeFireDamage;
        public SmallDec AlternativeColdDamage;

        //Secondary Elemental Damages
        /// <summary>
        /// (Fire+Cold)
        /// </summary>
        public SmallDec AlternativeBlastDamage;
        /// <summary>
        /// (Fire+Poison)
        /// </summary>
        public SmallDec AlternativeGasDamage;
        /// <summary>
        /// (Cold+Poison)
        /// </summary>
        public SmallDec AlternativeViralDamage;
        /// <summary>
        /// (Lightning+Poison)
        /// </summary>
        public SmallDec AlternativeCorrosiveDamage;
        /// <summary>
        /// (Lightning+Cold)
        /// </summary>
        public SmallDec AlternativeMagneticDamage;
        /// <summary>
        /// (Lightning+Fire)
        /// </summary>
        public SmallDec AlternativeRadiationDamage;
        /// <summary>
        /// The effective status chance after Multishot mods applied
        /// </summary>
        public SmallDec AlternativeEffectiveStatusChance;
        /// <summary>
        /// Base damage of weapon determines added elemental damage to weapon
        /// </summary>
        public SmallDec AlternativeBaseDamage;
        public SmallDec AlternativeCombinedRawDamage;
        /// <summary>
        /// The combined infinite magazine DPS without critical damage or accuracy calculated in for Alternative fire mode
        /// </summary>
        public SmallDec AlternativeRawDPSWithoutReload;
        public WFModSetup EquippedMods;
        private PreferedSecondaryCombination primaryPref = PreferedSecondaryCombination.CorrosiveDamage;

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
            if(EquippedMods.TotalStats.ContainsKey("Increased Speed"))
            {
                Speed = (SmallDec.One + EquippedMods.TotalStats["Increased Speed"] / 100)*EquippedWeapon.Speed;
            }
            else
            {
                Speed = EquippedWeapon.Speed;
            }
            if (EquippedMods.TotalStats.ContainsKey("Increased Critical Damage"))
            {
                CritMultiplier = (SmallDec.One + EquippedMods.TotalStats["Increased Critical Damage"] / 100) * EquippedWeapon.CritMultiplier;
            }
            else
            {
                CritMultiplier = EquippedWeapon.CritMultiplier;
            }
            if (EquippedMods.TotalStats.ContainsKey("Increased Critical Chance"))
            {
                CritChance = (SmallDec.One + EquippedMods.TotalStats["Increased Critical Chance"] / 100) * EquippedWeapon.CritChance;
            }
            else
            {
                CritChance = EquippedWeapon.CritChance;
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
            //Smeeta 200% Critical Chance applied (http://warframe.wikia.com/wiki/Critical#Orange_.26_Red_Crits)
            SmeetaRawCritDPSOnInfMag = RawDPSWithoutReload * (2*(CritMultiplier-1)+1);
            //Calculate Alternative Fire DPS as well if weapon has alternative fire mode
            if (AlternativeWeaponMode != null)
            {
                AlternativeEffectiveStatusChance = EffectiveStatusChance * AlternativeWeaponMode.StatusChance;
                if (EquippedMods.TotalStats.ContainsKey("Increased Speed"))
                {
                    AlternativeSpeed = (SmallDec.One + EquippedMods.TotalStats["Increased Speed"] / 100) * AlternativeWeaponMode.Speed;
                }
                else
                {
                    AlternativeSpeed = AlternativeWeaponMode.Speed;
                }
                if (EquippedMods.TotalStats.ContainsKey("Increased Critical Damage"))
                {
                    AlternativeCritMultiplier = (SmallDec.One + EquippedMods.TotalStats["Increased Critical Damage"] / 100) * AlternativeWeaponMode.CritMultiplier;
                }
                else
                {
                    AlternativeCritMultiplier = AlternativeWeaponMode.CritMultiplier;
                }
                if (EquippedMods.TotalStats.ContainsKey("Increased Critical Chance"))
                {
                    AlternativeCritChance = (SmallDec.One + EquippedMods.TotalStats["Increased Critical Chance"] / 100) * AlternativeWeaponMode.CritChance;
                }
                else
                {
                    AlternativeCritChance = AlternativeWeaponMode.CritChance;
                }
                AlternativeBaseDamage = AlternativeWeaponMode.SlashDamage + AlternativeWeaponMode.ImpactDamage + AlternativeWeaponMode.PunctureDamage;
                AlternativeBaseDamage += AlternativeWeaponMode.PoisonDamage + AlternativeWeaponMode.LightningDamage + AlternativeWeaponMode.FireDamage + AlternativeWeaponMode.ColdDamage;
                AlternativeBaseDamage += AlternativeWeaponMode.BlastDamage + AlternativeWeaponMode.CorrosiveDamage + AlternativeWeaponMode.GasDamage
                + AlternativeWeaponMode.MagneticDamage + AlternativeWeaponMode.RadiationDamage + AlternativeWeaponMode.ViralDamage;
                AlternativeSlashDamage = EquippedMods.TotalStats.ContainsKey("Increased Slash Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Slash Damage"] / 100) * AlternativeWeaponMode.SlashDamage : AlternativeWeaponMode.SlashDamage;
                AlternativeImpactDamage = EquippedMods.TotalStats.ContainsKey("Increased Impact Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Impact Damage"] / 100) * AlternativeWeaponMode.ImpactDamage : AlternativeWeaponMode.ImpactDamage;
                AlternativePunctureDamage = EquippedMods.TotalStats.ContainsKey("Increased Puncture Damage") ? (SmallDec.One + EquippedMods.TotalStats["Increased Puncture Damage"] / 100) * AlternativeWeaponMode.PunctureDamage : AlternativeWeaponMode.PunctureDamage;
                AlternativeSlashDamage *= EffectiveMultiplier; AlternativeImpactDamage *= EffectiveMultiplier; AlternativePunctureDamage *= EffectiveMultiplier;
                //Add Elemental Damage based on Base Damage
                AlternativePoisonDamage = EquippedMods.TotalStats.ContainsKey("Increased Poison Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Poison Damage"] / 100) * AlternativeBaseDamage) + AlternativeWeaponMode.PoisonDamage : AlternativeWeaponMode.PoisonDamage;
                AlternativeLightningDamage = EquippedMods.TotalStats.ContainsKey("Increased Lightning Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Lightning Damage"] / 100) * AlternativeBaseDamage) + AlternativeWeaponMode.LightningDamage : AlternativeWeaponMode.LightningDamage;
                AlternativeFireDamage = EquippedMods.TotalStats.ContainsKey("Increased Fire Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Lightning Damage"] / 100) * AlternativeBaseDamage) + AlternativeWeaponMode.LightningDamage : AlternativeWeaponMode.LightningDamage;
                AlternativeColdDamage = EquippedMods.TotalStats.ContainsKey("Increased Cold Damage") ? ((SmallDec.One + EquippedMods.TotalStats["Increased Cold Damage"] / 100) * AlternativeBaseDamage) + AlternativeWeaponMode.ColdDamage : AlternativeWeaponMode.ColdDamage;
                AlternativePoisonDamage *= EffectiveMultiplier; AlternativeLightningDamage *= EffectiveMultiplier; AlternativeFireDamage *= EffectiveMultiplier; AlternativeColdDamage *= EffectiveMultiplier;
                AlternativeBlastDamage = AlternativeWeaponMode.BlastDamage * EffectiveMultiplier; AlternativeRadiationDamage = AlternativeWeaponMode.RadiationDamage * EffectiveMultiplier; AlternativeViralDamage = AlternativeWeaponMode.ViralDamage * EffectiveMultiplier;
                AlternativeCorrosiveDamage = AlternativeWeaponMode.CorrosiveDamage * EffectiveMultiplier; AlternativeGasDamage = AlternativeWeaponMode.GasDamage * EffectiveMultiplier; AlternativeMagneticDamage = AlternativeWeaponMode.MagneticDamage * EffectiveMultiplier;
                AlternativeCombinedRawDamage = AlternativeSlashDamage + AlternativeImpactDamage + AlternativePunctureDamage + AlternativePoisonDamage + AlternativeLightningDamage + AlternativeFireDamage + AlternativeColdDamage + AlternativeBlastDamage + AlternativeRadiationDamage + AlternativeCorrosiveDamage + AlternativeGasDamage + AlternativeViralDamage + AlternativeMagneticDamage;
                AlternativeRawDPSWithoutReload = AlternativeCombinedRawDamage * AlternativeSpeed;
                AlternativeSmeetaRawCritDPSOnInfMag = RawDPSWithoutReload * (2 * (AlternativeCritMultiplier - 1) + 1);
                CurrentPref = PrimaryPref;
                for (int PrefNum = 0; PrefNum < 2; ++PrefNum)
                {
                    switch (PrefNum)
                    {
                        case 1:
                            CurrentPref = SecondaryPref;
                            break;
                    }
                    if (CurrentPref == PreferedSecondaryCombination.BlastDamage && AlternativeFireDamage > SmallDec.Zero && AlternativeColdDamage > SmallDec.Zero)
                    {
                        AlternativeBlastDamage += AlternativeFireDamage + AlternativeColdDamage;
                        AlternativeFireDamage = SmallDec.Zero; AlternativeColdDamage = SmallDec.Zero;
                    }
                    else if (CurrentPref == PreferedSecondaryCombination.CorrosiveDamage && AlternativeLightningDamage > SmallDec.Zero && AlternativePoisonDamage > SmallDec.Zero)
                    {
                        AlternativeCorrosiveDamage += AlternativeLightningDamage + AlternativePoisonDamage;
                        AlternativeLightningDamage = SmallDec.Zero; AlternativePoisonDamage = SmallDec.Zero;
                    }
                    else if (CurrentPref == PreferedSecondaryCombination.GasDamage && AlternativeFireDamage > SmallDec.Zero && AlternativePoisonDamage > SmallDec.Zero)
                    {
                        AlternativeGasDamage += AlternativeFireDamage + AlternativePoisonDamage;
                        AlternativeFireDamage = SmallDec.Zero; AlternativePoisonDamage = SmallDec.Zero;
                    }
                    else if (CurrentPref == PreferedSecondaryCombination.MagneticDamage && AlternativeLightningDamage > SmallDec.Zero && AlternativeColdDamage > SmallDec.Zero)
                    {
                        AlternativeMagneticDamage += AlternativeLightningDamage + AlternativeColdDamage;
                        AlternativeLightningDamage = SmallDec.Zero; AlternativeColdDamage = SmallDec.Zero;
                    }
                    else if (CurrentPref == PreferedSecondaryCombination.RadiationDamage && AlternativeFireDamage > SmallDec.Zero && AlternativeLightningDamage > SmallDec.Zero)
                    {
                        AlternativeRadiationDamage += AlternativeFireDamage + AlternativeLightningDamage;
                        AlternativeFireDamage = SmallDec.Zero; AlternativeLightningDamage = SmallDec.Zero;
                    }
                    else if (CurrentPref == PreferedSecondaryCombination.ViralDamage && AlternativePoisonDamage > SmallDec.Zero && AlternativeColdDamage > SmallDec.Zero)
                    {
                        AlternativeViralDamage += AlternativePoisonDamage + AlternativeColdDamage;
                        AlternativePoisonDamage = SmallDec.Zero; AlternativeColdDamage = SmallDec.Zero;
                    }
                }
            }
        }
    }
}
