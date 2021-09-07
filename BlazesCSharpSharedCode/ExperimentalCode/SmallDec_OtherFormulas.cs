/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/

using System;

//Does not need BigMath library to compile

//CSharpSharedCode.ExperimentalCode.SmallDec
namespace CSharpSharedCode.ExperimentalCode
{
    using System.ComponentModel;
    using System.Globalization;
    using static VariableConversionFunctions.VariableConversionFunctions;

    // Represent +- 65535.999999999(Can only represent +- 65535.9999 if SmallDec_ReducedSize or SmallDec_UseLegacyStorage set) with 100% consistency of accuracy
    //(Aka SuperDec_Int16_9Decimal Or SuperDec_Int16_4Decimal)
    public
#if (!BlazesSharedCode_SmallDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesSharedCode_SmallDec_AsStruct)
    class
#else
    struct
#endif
    SmallDec : IFormattable, INotifyPropertyChanged
    {
        public class Coords
        {
            public SmallDec PosX;
            public SmallDec PosY;
            public SmallDec PosZ;
            public Coords()
            {
                PosX = SmallDec.Zero;
                PosY = SmallDec.Zero;
                PosZ = SmallDec.Zero;
            }
            public Coords(SmallDec posX, SmallDec posY, SmallDec posZ)
            {
                PosX = posX;
                PosY = posY;
                PosZ = posZ;
            }
        }

        public class XZAngle
        {
            public SmallDec AngleX;
            public SmallDec AngleZ;
            public XZAngle(SmallDec TempAngleX, SmallDec TempAngleZ) { AngleX = TempAngleX; AngleZ = TempAngleZ; }
            public XZAngle() { }
        };

#if (!SmallDec_ReducedSize && !SmallDec_UseLegacyStorage)//Only enable for current implementation of SmallDec
        /// <summary>
        /// Gets the Euclidean distance between to positions (Based on http://en.wikipedia.org/wiki/Euclidean_distance)
        /// </summary>
        /// <param name="Origin">The origin position on 3d plane.</param>
        /// <param name="Target">The target position on 3d plane.</param>
        /// <returns></returns>
        public SmallDec GetDistance(Coords Origin, Coords Target)
        {
            //Distance = Math.Sqrt((PosX2-PosX1)^2*(PosY2-PosY1)^2*(PosZ2-PosZ1)^2));
            return SmallDec.Sqrt(((Target.PosX - Origin.PosX)* (Target.PosX - Origin.PosX)) * ((Target.PosY - Origin.PosY)* (Target.PosY - Origin.PosY)) * ((Target.PosZ - Origin.PosZ)* (Target.PosZ - Origin.PosZ)));
        }

        public SmallDec GetRedirectAngle(Coords self, Coords target)
        {
            return GetRedirectAngle(self, target);
        }

        public XZAngle GetRedirectAngle(Coords self, Coords target, SmallDec TargetHeightOffset)
        {//X Angle 0 at North
            SmallDec East = new SmallDec(90);
            SmallDec South = new SmallDec(180);
            SmallDec West = new SmallDec(270);
            XZAngle RedirectAngle = new XZAngle();
            SmallDec temp;
            SmallDec temp2;
            SmallDec DifX;
            SmallDec DifY;
            SmallDec DifZ;
            SmallDec Distance;
            SmallDec DistanceSquared;
            int PosType;
            bool OnCenter;
            SmallDec S1;
            DifX = self.PosX - target.PosX;
            DifY = self.PosY - target.PosY;
            DifZ = self.PosZ - target.PosZ + TargetHeightOffset;
            Distance = GetDistance(self, target);
            DistanceSquared = Distance * Distance;
            ////-----------------------------
            if (Distance != 0.0)
            {
                OnCenter = (DifX == 0.0 && DifY == 0.0);
                if (DifZ > 0.0)//ProjRef Above Target(XAngle between 0 and 90, looks down)
                {
                    PosType = 1;
                }
                else if (DifZ < 0.0)//Below Target(XAngle between -90 and 0, looks up)
                {
                    PosType = 2;
                }
                else//(ZDif==0.0)
                {
                    PosType = 3;
                    //RedirectAngle.AngleX = SmallDec.Zero;
                }
                if (OnCenter)
                {//Target is either above,below, or exactly at actor position(Only adjust ZAngle since does not need to turn on x-y axis since on center)
                    if (PosType == 1)
                    {
                        RedirectAngle.AngleX.IntValue = 90;
                    }
                    else if (PosType == 2)
                    {
                        RedirectAngle.AngleX = new SmallDec(-90);
                    }
                }
                else
                {
                    //----Z AngleRedirection
                    if (DifY < SmallDec.Zero && DifX == SmallDec.Zero)//North
                    {
                        temp = SmallDec.Zero;
                    }
                    else if (DifX < SmallDec.Zero && DifY == SmallDec.Zero)//East(ProjRef is West/Left of TargetRef)
                    {
                        temp = East;
                    }
                    else if (DifY > SmallDec.Zero && DifX == SmallDec.Zero)//South
                    {
                        temp = South;
                    }
                    else if (DifX > SmallDec.Zero && DifY == SmallDec.Zero)//West(ProjRef is East/Right of TargetRef)
                    {
                        temp = West;
                    }
                    else
                    {
                        temp = SmallDec.Abs(DifY);
                        temp2 = SmallDec.Abs(DifX);
                        temp = temp / temp2;
                        temp = SmallDec.ATan(temp);
                        if (DifY < SmallDec.Zero)//North
                        {
                            if (DifX < SmallDec.Zero)//East
                            {
                                temp = East - temp;
                            }
                            else if (DifX > SmallDec.Zero)//West
                            {
                                temp = West + temp;
                            }
                        }
                        else if (DifY > SmallDec.Zero)//South
                        {
                            if (DifX < 0.0)//East
                            {
                                temp = East + temp;
                            }
                            else if (DifX > SmallDec.Zero)//West
                            {
                                temp = West - temp;
                            }
                        }
                    }
                    RedirectAngle.AngleZ = temp;
                    if (PosType != 3)
                    {
                        //----Z AngleRedirection
                        //Side1=((TargetRef.GetPos x), (TargetRef.GetPos y), (ProjRef.GetPos z))
                        temp2 = ((DifX * DifX) + (DifY * DifY));
                        S1 = SmallDec.Sqrt(temp2);
                        if (S1 != SmallDec.Zero)//Avoid Divide by Zero Error
                        {
                            temp = (DifZ * DifZ);//Side 3=DifZ, Side2=Distance
                                                 //Law of Cosines=acos ((S1^2+S2^2-S3^2)/(2*S1*S2));Side3=SideOppositeAngle
                            temp = (temp2 + DistanceSquared + (temp * -1)) / (2 * S1 * Distance);
                            temp = SmallDec.ACos(temp);
                            //temp2 = XAngle;
                            if (temp < 0.0 && PosType == 1)//Angle Correction Code(temp is angle)--flips angle if angle set on wrong side
                            {
                                temp *= -1;
                            }
                            else
                            {
                                temp *= -1;
                            }
                            RedirectAngle.AngleX = temp;
                        }
                    }
                }
            }
            return RedirectAngle;
        }
#endif
    }
}
