/*	Code Created by James Michael Armstrong (https://github.com/BlazesRus)
    Latest Code Release at https://github.com/BlazesRus/BlazesRusSharedCode
*/

using System;

namespace CSharpSharedCode.ExperimentalCode
{
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.IO;

    // Represents +- 4294967295.999999999 with 100% consistency of accuracy
    //(Aka SuperDec_Int32_9Decimal)
    public
#if (!BlazesSharedCode_MediumDec_AsStruct)
    sealed
#endif
    partial
#if (!BlazesSharedCode_MediumDec_AsStruct)
    class
#else
    struct
#endif
    MediumDec : IFormattable, INotifyPropertyChanged
    {
        public class Coords
        {
            public MediumDec PosX;
            public MediumDec PosY;
            public MediumDec PosZ;
            public Coords()
            {
                PosX = MediumDec.Zero;
                PosY = MediumDec.Zero;
                PosZ = MediumDec.Zero;
            }
            public Coords(MediumDec posX, MediumDec posY, MediumDec posZ)
            {
                PosX = posX;
                PosY = posY;
                PosZ = posZ;
            }
        }

        public class XZAngle
        {
            public MediumDec AngleX;
            public MediumDec AngleZ;
            public XZAngle(MediumDec TempAngleX, MediumDec TempAngleZ) { AngleX = TempAngleX; AngleZ = TempAngleZ; }
            public XZAngle() { }
        };

        /// <summary>
        /// Gets the Euclidean distance between to positions (Based on http://en.wikipedia.org/wiki/Euclidean_distance)
        /// </summary>
        /// <param name="Origin">The origin position on 3d plane.</param>
        /// <param name="Target">The target position on 3d plane.</param>
        /// <returns></returns>
        public MediumDec GetDistance(Coords Origin, Coords Target)
        {
            //Distance = Math.Sqrt((PosX2-PosX1)^2*(PosY2-PosY1)^2*(PosZ2-PosZ1)^2));
            return MediumDec.Sqrt(((Target.PosX - Origin.PosX) * (Target.PosX - Origin.PosX)) * ((Target.PosY - Origin.PosY) * (Target.PosY - Origin.PosY)) * ((Target.PosZ - Origin.PosZ) * (Target.PosZ - Origin.PosZ)));
        }

        public MediumDec GetRedirectAngle(Coords self, Coords target)
        {
            return GetRedirectAngle(self, target);
        }

        public XZAngle GetRedirectAngle(Coords self, Coords target, MediumDec TargetHeightOffset)
        {//X Angle 0 at North
            MediumDec East = new MediumDec(90);
            MediumDec South = new MediumDec(180);
            MediumDec West = new MediumDec(270);
            XZAngle RedirectAngle = new XZAngle();
            MediumDec temp;
            MediumDec temp2;
            MediumDec DifX;
            MediumDec DifY;
            MediumDec DifZ;
            MediumDec Distance;
            MediumDec DistanceSquared;
            int PosType;
            bool OnCenter;
            MediumDec S1;
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
                    //RedirectAngle.AngleX = MediumDec.Zero;
                }
                if (OnCenter)
                {//Target is either above,below, or exactly at actor position(Only adjust ZAngle since does not need to turn on x-y axis since on center)
                    if (PosType == 1)
                    {
                        RedirectAngle.AngleX.IntValue = 90;
                    }
                    else if (PosType == 2)
                    {
                        RedirectAngle.AngleX = new MediumDec(-90);
                    }
                }
                else
                {
                    //----Z AngleRedirection
                    if (DifY < MediumDec.Zero && DifX == MediumDec.Zero)//North
                    {
                        temp = MediumDec.Zero;
                    }
                    else if (DifX < MediumDec.Zero && DifY == MediumDec.Zero)//East(ProjRef is West/Left of TargetRef)
                    {
                        temp = East;
                    }
                    else if (DifY > MediumDec.Zero && DifX == MediumDec.Zero)//South
                    {
                        temp = South;
                    }
                    else if (DifX > MediumDec.Zero && DifY == MediumDec.Zero)//West(ProjRef is East/Right of TargetRef)
                    {
                        temp = West;
                    }
                    else
                    {
                        temp = MediumDec.Abs(DifY);
                        temp2 = MediumDec.Abs(DifX);
                        temp = temp / temp2;
                        temp = MediumDec.ATan(temp);
                        if (DifY < MediumDec.Zero)//North
                        {
                            if (DifX < MediumDec.Zero)//East
                            {
                                temp = East - temp;
                            }
                            else if (DifX > MediumDec.Zero)//West
                            {
                                temp = West + temp;
                            }
                        }
                        else if (DifY > MediumDec.Zero)//South
                        {
                            if (DifX < 0.0)//East
                            {
                                temp = East + temp;
                            }
                            else if (DifX > MediumDec.Zero)//West
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
                        S1 = MediumDec.Sqrt(temp2);
                        if (S1 != MediumDec.Zero)//Avoid Divide by Zero Error
                        {
                            temp = (DifZ * DifZ);//Side 3=DifZ, Side2=Distance
                                                 //Law of Cosines=acos ((S1^2+S2^2-S3^2)/(2*S1*S2));Side3=SideOppositeAngle
                            temp = (temp2 + DistanceSquared + (temp * -1)) / (2 * S1 * Distance);
                            temp = MediumDec.ACos(temp);
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
    }
}
