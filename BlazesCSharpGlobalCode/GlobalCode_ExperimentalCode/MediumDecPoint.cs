using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
{
    /// <summary>
    /// Represents an x- and y-coordinate pair in two-dimensional space. (MediumDec version of System.Windows.Point)
    /// </summary>
    class MediumDecPoint
    {
        /// <summary>
        /// Gets or sets the MediumDecVector.X component of this MediumDecVector.
        /// </summary>
        /// <value>
        /// The MediumDecVector.X component of this MediumDecVector. The default value is 0.
        /// </value>
        public MediumDec X { get; set; }
        /// <summary>
        /// Gets or sets the MediumDecVector.Y component of this MediumDecVector.
        /// </summary>
        /// <value>
        /// The MediumDecVector.Y component of this MediumDecVector. The default value is 0.
        /// </value>
        public MediumDec Y { get; set; }

        ////
        //// Summary:
        ////     Creates a new MediumDecPoint structure that contains the specified coordinates.
        ////
        //// Parameters:
        ////   x:
        ////     The x-coordinate of the new MediumDecPoint structure.
        ////
        ////   y:
        ////     The y-coordinate of the new MediumDecPoint structure.
        //public MediumDecPoint(MediumDec x, MediumDec y);

        ////
        //// Summary:
        ////     Adds a System.Windows.Vector to a MediumDecPoint and returns the result
        ////     as a MediumDecPoint structure.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint structure to add.
        ////
        ////   vector:
        ////     The System.Windows.Vector structure to add.
        ////
        //// Returns:
        ////     Returns the sum of MediumDecPoint and vector.
        //public static MediumDecPoint Add(MediumDecPoint MediumDecPoint, Vector vector);
        ////
        //// Summary:
        ////     Compares two MediumDecPoint structures for equality.
        ////
        //// Parameters:
        ////   MediumDecPoint1:
        ////     The first MediumDecPoint to compare.
        ////
        ////   MediumDecPoint2:
        ////     The second MediumDecPoint to compare.
        ////
        //// Returns:
        ////     true if MediumDecPoint1 and MediumDecPoint2 contain the same MediumDecPoint.X and MediumDecPoint.Y
        ////     values; otherwise, false.
        //public static bool Equals(MediumDecPoint MediumDecPoint1, MediumDecPoint MediumDecPoint2);
        ////
        //// Summary:
        ////     Transforms the specified MediumDecPoint structure by the specified System.Windows.Media.Matrix
        ////     structure.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint to transform.
        ////
        ////   matrix:
        ////     The transformation matrix.
        ////
        //// Returns:
        ////     The transformed MediumDecPoint.
        //public static MediumDecPoint Multiply(MediumDecPoint MediumDecPoint, Matrix matrix);
        ////
        //// Summary:
        ////     Constructs a MediumDecPoint from the specified System.String.
        ////
        //// Parameters:
        ////   source:
        ////     A string representation of a MediumDecPoint.
        ////
        //// Returns:
        ////     The equivalent MediumDecPoint structure.
        ////
        //// Exceptions:
        ////   T:System.FormatException:
        ////     source is not composed of two comma- or space-delimited MediumDec values.
        ////
        ////   T:System.InvalidOperationException:
        ////     source does not contain two numbers.-or- source contains too many delimiters.
        //public static MediumDecPoint Parse(string source);
        ////
        //// Summary:
        ////     Subtracts the specified MediumDecPoint from another specified MediumDecPoint
        ////     and returns the difference as a System.Windows.Vector.
        ////
        //// Parameters:
        ////   MediumDecPoint1:
        ////     The MediumDecPoint from which MediumDecPoint2 is subtracted.
        ////
        ////   MediumDecPoint2:
        ////     The MediumDecPoint to subtract from MediumDecPoint1.
        ////
        //// Returns:
        ////     The difference between MediumDecPoint1 and MediumDecPoint2.
        //public static Vector Subtract(MediumDecPoint MediumDecPoint1, MediumDecPoint MediumDecPoint2);
        ////
        //// Summary:
        ////     Subtracts the specified System.Windows.Vector from the specified MediumDecPoint
        ////     and returns the resulting MediumDecPoint.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint from which vector is subtracted.
        ////
        ////   vector:
        ////     The vector to subtract from MediumDecPoint.
        ////
        //// Returns:
        ////     The difference between MediumDecPoint and vector.
        //public static MediumDecPoint Subtract(MediumDecPoint MediumDecPoint, Vector vector);
        ////
        //// Summary:
        ////     Determines whether the specified System.Object is a MediumDecPoint and
        ////     whether it contains the same coordinates as this MediumDecPoint.
        ////
        //// Parameters:
        ////   o:
        ////     The System.Object to compare.
        ////
        //// Returns:
        ////     true if o is a MediumDecPoint and contains the same MediumDecPoint.X
        ////     and MediumDecPoint.Y values as this MediumDecPoint; otherwise, false.
        //public override bool Equals(object o);
        ////
        //// Summary:
        ////     Compares two MediumDecPoint structures for equality.
        ////
        //// Parameters:
        ////   value:
        ////     The MediumDecPoint to compare to this instance.
        ////
        //// Returns:
        ////     true if both MediumDecPoint structures contain the same MediumDecPoint.X
        ////     and MediumDecPoint.Y values; otherwise, false.
        //public bool Equals(MediumDecPoint value);
        ////
        //// Summary:
        ////     Returns the hash code for this MediumDecPoint.
        ////
        //// Returns:
        ////     The hash code for this MediumDecPoint structure.
        //public override int GetHashCode();
        ////
        //// Summary:
        ////     Offsets a MediumDecPoint's MediumDecPoint.X and MediumDecPoint.Y coordinates
        ////     by the specified amounts.
        ////
        //// Parameters:
        ////   offsetX:
        ////     The amount to offset the MediumDecPoint's MediumDecPoint.X coordinate.
        ////
        ////   offsetY:
        ////     The amount to offset theMediumDecPoint's MediumDecPoint.Y coordinate.
        //public void Offset(MediumDec offsetX, MediumDec offsetY);
        ////
        //// Summary:
        ////     Creates a System.String representation of this MediumDecPoint.
        ////
        //// Returns:
        ////     A System.String containing the MediumDecPoint.X and MediumDecPoint.Y
        ////     values of this MediumDecPoint structure.
        //public override string ToString();
        ////
        //// Summary:
        ////     Creates a System.String representation of this MediumDecPoint.
        ////
        //// Parameters:
        ////   provider:
        ////     Culture-specific formatting information.
        ////
        //// Returns:
        ////     A System.String containing the MediumDecPoint.X and MediumDecPoint.Y
        ////     values of this MediumDecPoint structure.
        //public string ToString(IFormatProvider provider);

        ////
        //// Summary:
        ////     Translates the specified MediumDecPoint by the specified System.Windows.Vector
        ////     and returns the result.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint to translate.
        ////
        ////   vector:
        ////     The amount by which to translate MediumDecPoint.
        ////
        //// Returns:
        ////     The result of translating the specified MediumDecPoint by the specified vector.
        //public static MediumDecPoint operator +(MediumDecPoint MediumDecPoint, Vector vector);
        ////
        //// Summary:
        ////     Subtracts the specified System.Windows.Vector from the specified MediumDecPoint
        ////     and returns the resulting MediumDecPoint.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint from which vector is subtracted.
        ////
        ////   vector:
        ////     The vector to subtract from MediumDecPoint1
        ////
        //// Returns:
        ////     The difference between MediumDecPoint and vector.
        //public static MediumDecPoint operator -(MediumDecPoint MediumDecPoint, Vector vector);
        ////
        //// Summary:
        ////     Subtracts the specified MediumDecPoint from another specified MediumDecPoint
        ////     and returns the difference as a System.Windows.Vector.
        ////
        //// Parameters:
        ////   MediumDecPoint1:
        ////     The MediumDecPoint from which MediumDecPoint2 is subtracted.
        ////
        ////   MediumDecPoint2:
        ////     The MediumDecPoint to subtract from MediumDecPoint1.
        ////
        //// Returns:
        ////     The difference between MediumDecPoint1 and MediumDecPoint2.
        //public static Vector operator -(MediumDecPoint MediumDecPoint1, MediumDecPoint MediumDecPoint2);
        ////
        //// Summary:
        ////     Transforms the specified MediumDecPoint by the specified System.Windows.Media.Matrix.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint to transform.
        ////
        ////   matrix:
        ////     The transformation matrix.
        ////
        //// Returns:
        ////     The result of transforming the specified MediumDecPoint using the specified matrix.
        //public static MediumDecPoint operator *(MediumDecPoint MediumDecPoint, Matrix matrix);
        ////
        //// Summary:
        ////     Compares two MediumDecPoint structures for equality.
        ////
        //// Parameters:
        ////   MediumDecPoint1:
        ////     The first MediumDecPoint structure to compare.
        ////
        ////   MediumDecPoint2:
        ////     The second MediumDecPoint structure to compare.
        ////
        //// Returns:
        ////     true if both the MediumDecPoint.X and MediumDecPoint.Y coordinates
        ////     of MediumDecPoint1 and MediumDecPoint2 are equal; otherwise, false.
        //public static bool operator ==(MediumDecPoint MediumDecPoint1, MediumDecPoint MediumDecPoint2);
        ////
        //// Summary:
        ////     Compares two MediumDecPoint structures for inequality.
        ////
        //// Parameters:
        ////   MediumDecPoint1:
        ////     The first MediumDecPoint to compare.
        ////
        ////   MediumDecPoint2:
        ////     The second MediumDecPoint to compare.
        ////
        //// Returns:
        ////     true if MediumDecPoint1 and MediumDecPoint2 have different MediumDecPoint.X or MediumDecPoint.Y
        ////     coordinates; false if MediumDecPoint1 and MediumDecPoint2 have the same MediumDecPoint.X
        ////     and MediumDecPoint.Y coordinates.
        //public static bool operator !=(MediumDecPoint MediumDecPoint1, MediumDecPoint MediumDecPoint2);

        ////
        //// Summary:
        ////     Creates a System.Windows.Size structure with a System.Windows.Size.Width equal
        ////     to this MediumDecPoint's MediumDecPoint.X value and a System.Windows.Size.Height
        ////     equal to this MediumDecPoint's MediumDecPoint.Y value.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint to convert.
        ////
        //// Returns:
        ////     A System.Windows.Size structure with a System.Windows.Size.Width equal to this
        ////     MediumDecPoint's MediumDecPoint.X value and a System.Windows.Size.Height equal to
        ////     this MediumDecPoint's MediumDecPoint.Y value.
        //public static explicit operator Size(MediumDecPoint MediumDecPoint);
        ////
        //// Summary:
        ////     Creates a System.Windows.Vector structure with an System.Windows.Vector.X value
        ////     equal to the MediumDecPoint's MediumDecPoint.X value and a System.Windows.Vector.Y
        ////     value equal to the MediumDecPoint's MediumDecPoint.Y value.
        ////
        //// Parameters:
        ////   MediumDecPoint:
        ////     The MediumDecPoint to convert.
        ////
        //// Returns:
        ////     A vector with an System.Windows.Vector.X value equal to the MediumDecPoint's MediumDecPoint.X
        ////     value and a System.Windows.Vector.Y value equal to the MediumDecPoint's MediumDecPoint.Y
        ////     value.
        //public static explicit operator MediumDecVector(MediumDecPoint MediumDecPoint);
    }
}
