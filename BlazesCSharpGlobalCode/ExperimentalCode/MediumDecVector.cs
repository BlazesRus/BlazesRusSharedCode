namespace CSharpGlobalCode.ExperimentalCode
{
    /// <summary>
    /// MediumDec version of a 2 Point based Vector<para/>
    /// Some code based on https://www.codeproject.com/Articles/17425/A-Vector-Type-for-C
    /// and https://gist.github.com/chafdev/dcffdd38ab4097df5c36f94e609d58b0
    /// </summary>
    public
#if (!BlazesGlobalCode_VectorAsStruct)
    class
#else
    struct
#endif
    MediumDecVector2
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

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecVector{MediumDec}"/> class.
        /// </summary>
        /// <param name="x">The MediumDecVector.X-offset of the new MediumDecVector.</param>
        /// <param name="y">The MediumDecVector.Y-offset of the new MediumDecVector.</param>
        public MediumDecVector2(MediumDec x, MediumDec y)
        {
            X = x;
            Y = y;
        }

        /// <summary>
        /// Return the Vector as an array
        /// </summary>
        /// <value>
        /// The array.
        /// </value>
        public MediumDec[] Array
        {
            get { return new MediumDec[] { X, Y }; }
        }

        public static MediumDecVector2 operator +(MediumDecVector2 mv1, MediumDecVector2 mv2)
        {
            return new MediumDecVector2(mv1.X + mv2.X, mv1.Y + mv2.Y);
        }

        public static MediumDecVector2 operator -(MediumDecVector2 mv1, MediumDecVector2 mv2)
        {
            return new MediumDecVector2(mv1.X - mv2.X, mv1.Y - mv2.Y);
        }

        public static MediumDecVector2 operator -(MediumDecVector2 mv1, MediumDec var)
        {
            return new MediumDecVector2(mv1.X - var, mv1.Y - var);
        }

        public static MediumDecVector2 operator *(MediumDecVector2 mv1, MediumDecVector2 mv2)
        {
            return new MediumDecVector2(mv1.X * mv2.X, mv1.Y * mv2.Y);
        }

        public static MediumDecVector2 operator *(MediumDecVector2 mv, MediumDec var)
        {
            return new MediumDecVector2(mv.X * var, mv.Y * var);
        }

        //public static MediumDecVector2 operator %(MediumDecVector2 mv1, MediumDecVector2 mv2)
        //{
        //	return new MediumDecVector2(mv1.Y * mv2.Z - mv1.Z * mv2.Y,
        //						 mv1.Z * mv2.X - mv1.X * mv2.Z,
        //						 mv1.X * mv2.Y - mv1.Y * mv2.X);
        //}

        public MediumDec this[int key]
        {
            get
            {
                return GetValueByIndex(key);
            }
            set { SetValueByIndex(key, value); }
        }

        private void SetValueByIndex(int key, MediumDec value)
        {
            if (key == 0) X = value;
            else Y = value;
        }

        private MediumDec GetValueByIndex(int key)
        {
            if (key == 0) return X;
            return Y;
        }

        public MediumDec DotProduct(MediumDecVector2 mv)
        {
            return X * mv.X + Y * mv.Y;
        }

        public MediumDecVector2 ScaleBy(MediumDec value)
        {
            return new MediumDecVector2(X * value, Y * value);
        }

        public MediumDecVector2 ComponentProduct(MediumDecVector2 mv)
        {
            return new MediumDecVector2(X * mv.X, Y * mv.Y);
        }

        public void ComponentProductUpdate(MediumDecVector2 mv)
        {
            X *= mv.X;
            Y *= mv.Y;
        }

        //public MediumDecVector2 VectorProduct(MediumDecVector2 mv)
        //{
        //	return new MediumDecVector2(Y * mv.Z - Z * mv.Y,
        //						 Z * mv.X - X * mv.Z,
        //						 X * mv.Y - Y * mv.X);
        //}

        public MediumDec ScalarProduct(MediumDecVector2 mv)
        {
            return X * mv.X + Y * mv.Y;
        }

        public void AddScaledVector(MediumDecVector2 mv, MediumDec scale)
        {
            X += mv.X * scale;
            Y += mv.Y * scale;
        }

        public MediumDec Magnitude()
        {
            return MediumDec.Sqrt(X * X + Y * Y);
        }

        public MediumDec SquareMagnitude()
        {
            return X * X + Y * Y;
        }

        public void Trim(MediumDec size)
        {
            if (SquareMagnitude() > size * size)
            {
                Normalize();
                X *= size;
                Y *= size;
            }
        }

        public void Normalize()
        {
            MediumDec m = Magnitude();
            if (m > 0)
            {
                X = X / m;
                Y = Y / m;
            }
            else
            {
                X = MediumDec.Zero;
                Y = MediumDec.Zero;
            }
        }

        public MediumDecVector2 Inverted()
        {
            return new MediumDecVector2(-X, -Y);
        }

        public MediumDecVector2 Unit()
        {
            MediumDecVector2 result = this;
            result.Normalize();
            return result;
        }

        public void Clear()
        {
            X = MediumDec.Zero;
            Y = MediumDec.Zero;
        }

        public static MediumDec Distance(MediumDecVector2 mv1, MediumDecVector2 mv2)
        {
            return (mv1 - mv2).Magnitude();
        }

        public static MediumDecVector2 Zero()
        {
            return new MediumDecVector2(MediumDec.Zero, MediumDec.Zero);
        }
    }

    /// <summary>
    /// MediumDec version of a 3 Point based Vector with Cartesian coordinate system in three-dimensions and Euclidean geometry.<para/>
    /// Some code based on https://www.codeproject.com/Articles/17425/A-Vector-Type-for-C and https://gist.github.com/chafdev/dcffdd38ab4097df5c36f94e609d58b0
    /// </summary>
    public
#if (!BlazesGlobalCode_VectorAsStruct)
    class
#else
    struct
#endif
    MediumDecVector3
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

        /// <summary>
        /// Gets or sets the MediumDecVector.Z component of this MediumDecVector.
        /// </summary>
        /// <value>
        /// The MediumDecVector.Z component of this MediumDecVector. The default value is 0.
        /// </value>
        public MediumDec Z { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="MediumDecVector{MediumDec}"/> class.
        /// </summary>
        /// <param name="x">The MediumDecVector.X-offset of the new MediumDecVector.</param>
        /// <param name="y">The MediumDecVector.Y-offset of the new MediumDecVector.</param>
        public MediumDecVector3(MediumDec x, MediumDec y, MediumDec z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        /// <summary>
        /// Return the Vector as an array
        /// </summary>
        /// <value>
        /// The array.
        /// </value>
        public MediumDec[] Array
        {
            get { return new MediumDec[] { X, Y, Z }; }
        }

        public static MediumDecVector3 operator +(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return new MediumDecVector3(mv1.X + mv2.X, mv1.Y + mv2.Y, mv1.Z + mv2.Z);
        }

        public static MediumDecVector3 operator -(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return new MediumDecVector3(mv1.X - mv2.X, mv1.Y - mv2.Y, mv1.Z - mv2.Z);
        }

        public static MediumDecVector3 operator -(MediumDecVector3 mv1, MediumDec var)
        {
            return new MediumDecVector3(mv1.X - var, mv1.Y - var, mv1.Z - var);
        }

        public static MediumDecVector3 operator *(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return new MediumDecVector3(mv1.X * mv2.X, mv1.Y * mv2.Y, mv1.Z * mv2.Z);
        }

        public static MediumDecVector3 operator *(MediumDecVector3 mv, MediumDec var)
        {
            return new MediumDecVector3(mv.X * var, mv.Y * var, mv.Z * var);
        }

        public static MediumDecVector3 operator %(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return new MediumDecVector3(mv1.Y * mv2.Z - mv1.Z * mv2.Y,
                                 mv1.Z * mv2.X - mv1.X * mv2.Z,
                                 mv1.X * mv2.Y - mv1.Y * mv2.X);
        }

        public MediumDec this[int key]
        {
            get
            {
                return GetValueByIndex(key);
            }
            set { SetValueByIndex(key, value); }
        }

        private void SetValueByIndex(int key, MediumDec value)
        {
            if (key == 0) X = value;
            else if (key == 1) Y = value;
            else if (key == 2) Z = value;
        }

        private MediumDec GetValueByIndex(int key)
        {
            if (key == 0) return X;
            if (key == 1) return Y;
            return Z;
        }

        public MediumDec DotProduct(MediumDecVector3 mv)
        {
            return X * mv.X + Y * mv.Y + Z * mv.Z;
        }

        public MediumDecVector3 ScaleBy(MediumDec value)
        {
            return new MediumDecVector3(X * value, Y * value, Z * value);
        }

        public MediumDecVector3 ComponentProduct(MediumDecVector3 mv)
        {
            return new MediumDecVector3(X * mv.X, Y * mv.Y, Z * mv.Z);
        }

        public void ComponentProductUpdate(MediumDecVector3 mv)
        {
            X *= mv.X;
            Y *= mv.Y;
            Z *= mv.Z;
        }

        public MediumDecVector3 VectorProduct(MediumDecVector3 mv)
        {
            return new MediumDecVector3(Y * mv.Z - Z * mv.Y,
                                 Z * mv.X - X * mv.Z,
                                 X * mv.Y - Y * mv.X);
        }

        public MediumDec ScalarProduct(MediumDecVector3 mv)
        {
            return X * mv.X + Y * mv.Y + Z * mv.Z;
        }

        public void AddScaledVector(MediumDecVector3 mv, MediumDec scale)
        {
            X += mv.X * scale;
            Y += mv.Y * scale;
            Z += mv.Z * scale;
        }

        public MediumDec Magnitude
        {
            get
            {
                return MediumDec.Sqrt(X * X + Y * Y + Z * Z);
            }
        }

        public static bool IsUnitVector(MediumDecVector3 v1)
        {
            return v1.Magnitude == 1;
        }

        public bool IsUnitVector()
        {
            return IsUnitVector(this);
        }

        //public bool IsUnitVector(MediumDec tolerance)
        //{
        //	return IsUnitVector(this, tolerance);
        //}

        //public static bool IsUnitVector(MediumDecVector3 v1, MediumDec tolerance)
        //{
        //	return AlmostEqualsWithAbsTolerance(v1.Magnitude, 1, tolerance);
        //}

        public MediumDec SquareMagnitude()
        {
            return X * X + Y * Y + Z * Z;
        }

        public void Trim(MediumDec size)
        {
            if (SquareMagnitude() > size * size)
            {
                Normalize();
                X *= size;
                Y *= size;
                Z *= size;
            }
        }

        public void Normalize()
        {
            MediumDec m = Magnitude;
            if (m == MediumDec.Zero)
            {
                throw new System.Exception(NORMALIZE_0);
            }
            else if (m > 0)
            {
                X = X / m;
                Y = Y / m;
                Z = Z / m;
            }
            else
            {
                X = MediumDec.Zero;
                Y = MediumDec.Zero;
                Z = MediumDec.Zero;
            }
        }

        //public static MediumDecVector3 Normalize(MediumDecVector3 v1)
        //{
        //	var magnitude = v1.Magnitude;

        //	// Check that we are not attempting to normalize a vector of magnitude 0
        //	if (magnitude == 0)
        //	{
        //		throw new System.Exception("NORMALIZE Magnitude Zero Exception");
        //	}

        //	// Check that we are not attempting to normalize a vector of magnitude NaN
        //	if (MediumDec.IsNaN(magnitude))
        //	{
        //		throw new System.Exception("NORMALIZE Magnitude Zero Exception");
        //	}

        //	// Special Cases
        //	if (MediumDec.IsInfinity(v1.Magnitude))
        //	{
        //		var x =
        //			v1.X == 0 ? 0 :
        //				v1.X == -0 ? -0 :
        //					double.IsPositiveInfinity(v1.X) ? 1 :
        //						double.IsNegativeInfinity(v1.X) ? -1 :
        //							double.NaN;
        //		var y =
        //			v1.Y == 0 ? 0 :
        //				v1.Y == -0 ? -0 :
        //					double.IsPositiveInfinity(v1.Y) ? 1 :
        //						double.IsNegativeInfinity(v1.Y) ? -1 :
        //							double.NaN;
        //		var z =
        //			v1.Z == 0 ? 0 :
        //				v1.Z == -0 ? -0 :
        //					double.IsPositiveInfinity(v1.Z) ? 1 :
        //						double.IsNegativeInfinity(v1.Z) ? -1 :
        //							double.NaN;

        //		var result = new Vector3(x, y, z);

        //		// If this wasn't a special case throw an exception
        //		if (result.IsNaN())
        //		{
        //			throw new System.Exception("NORMALIZE Magnitude Zero Exception");
        //		}

        //		// If this was a special case return the special case result
        //		return result;
        //	}

        //	// Run the normalization as usual
        //	return NormalizeOrNaN(v1);
        //}

        private static MediumDecVector3 NormalizeOrNaN(MediumDecVector3 v1)
        {
            // find the inverse of the vectors magnitude
            MediumDec inverse = 1 / v1.Magnitude;

            return new MediumDecVector3(
                // multiply each component by the inverse of the magnitude
                v1.X * inverse,
                v1.Y * inverse,
                v1.Z * inverse);
        }

        private const string NORMALIZE_0 =
            "Cannot normalize a vector when it's magnitude is zero";

        private const string NORMALIZE_NaN =
            "Cannot normalize a vector when it's magnitude is NaN";

        public MediumDecVector3 Inverted()
        {
            return new MediumDecVector3(-X, -Y, -Z);
        }

        public MediumDecVector3 Unit()
        {
            MediumDecVector3 result = this;
            result.Normalize();
            return result;
        }

        public void Clear()
        {
            X = MediumDec.Zero;
            Y = MediumDec.Zero;
            Z = MediumDec.Zero;
        }

        //public static MediumDec Distance(MediumDecVector3 v1, MediumDecVector3 v2)
        //{
        //	return
        //	   MediumDec.Sqrt
        //	   (
        //		   (v1.X - v2.X) * (v1.X - v2.X) +
        //		   (v1.Y - v2.Y) * (v1.Y - v2.Y) +
        //		   (v1.Z - v2.Z) * (v1.Z - v2.Z)
        //	   );
        //}

        public static MediumDec Distance(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return (mv1 - mv2).Magnitude;
        }

        public MediumDec Distance(MediumDecVector3 other)
        {
            return Distance(this, other);
        }

        public static MediumDecVector3 Zero => new MediumDecVector3(MediumDec.Zero, MediumDec.Zero, MediumDec.Zero);

        public static MediumDec Abs(MediumDecVector3 v1)
        {
            return v1.Magnitude;
        }

        public MediumDec Abs()
        {
            return this.Magnitude;
        }

        //public static double Angle(MediumDecVector3 v1, MediumDecVector3 v2)
        //{
        //	if (v1 == v2)
        //	{
        //		return 0;
        //	}

        //	return
        //		MediumDec.Acos(
        //			MediumDec.Min(MediumDec.One, NormalizeOrDefault(v1).DotProduct(NormalizeOrDefault(v2))));
        //}

        //public double Angle(MediumDecVector3 other)
        //{
        //	return Angle(this, other);
        //}

        /// <summary>
        /// This method interprets a vector as a face normal and determines whether the normal represents a back facing plane given a line-of-sight vector.<para/>
        /// A back facing plane will be invisible in a rendered scene and as such can be except from many scene calculations.
        /// </summary>
        /// <param name="normal">The normal.</param>
        /// <param name="lineOfSight">The line of sight.</param>
        /// <returns>
        ///   <c>true</c> if [is back face] [the specified normal]; otherwise, <c>false</c>.
        /// </returns>
        public static bool IsBackFace(MediumDecVector3 normal, MediumDecVector3 lineOfSight)
        {
            return normal.DotProduct(lineOfSight) < 0;
        }

        /// <summary>
        /// This method interprets a vector as a face normal and determines whether the normal represents a back facing plane given a line-of-sight vector.<para/>
        /// A back facing plane will be invisible in a rendered scene and as such can be except from many scene calculations.
        /// </summary>
        /// <param name="lineOfSight">The line of sight.</param>
        /// <returns>
        ///   <c>true</c> if [is back face] [the specified line of sight]; otherwise, <c>false</c>.
        /// </returns>
        public bool IsBackFace(MediumDecVector3 lineOfSight)
        {
            return IsBackFace(this, lineOfSight);
        }

        //public static bool IsPerpendicular(MediumDecVector3 v1, MediumDecVector3 v2, MediumDec tolerance)
        //{
        //	// Use normalization of special cases to handle special cases of IsPerpendicular
        //	v1 = NormalizeSpecialCasesOrOrigional(v1);
        //	v2 = NormalizeSpecialCasesOrOrigional(v2);

        //	// If either vector is vector(0,0,0) the vectors are not perpendicular
        //	if (v1 == Zero || v2 == Zero)
        //	{
        //		return false;
        //	}

        //	// Is perpendicular
        //	return v1.DotProduct(v2).AlmostEqualsWithAbsTolerance(0, tolerance);
        //}

        //public bool IsPerpendicular(MediumDecVector3 other, MediumDec tolerance)
        //{
        //	return IsPerpendicular(this, other, tolerance);
        //}

        //// Helpers
        //private static bool AlmostEqualsWithAbsTolerance(this MediumDec a, MediumDec b, MediumDec maxAbsoluteError)
        //{
        //	MediumDec diff = MediumDec.Abs(a - b);

        //	if (a.Equals(b))
        //	{
        //		// shortcut, handles infinities
        //		return true;
        //	}

        //	return diff <= maxAbsoluteError;
        //}
    }
}