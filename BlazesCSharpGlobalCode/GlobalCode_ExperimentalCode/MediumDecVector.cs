namespace CSharpGlobalCode.GlobalCode_ExperimentalCode
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
    /// MediumDec version of a 3 Point based Vector with Cartesian coordinate system in three-dimensions and Euclidian geometry.<para/>
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

        public MediumDec Magnitude()
        {
            return MediumDec.Sqrt(X * X + Y * Y + Z * Z);
        }

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
            MediumDec m = Magnitude();
            if (m > 0)
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

        public static MediumDec Distance(MediumDecVector3 mv1, MediumDecVector3 mv2)
        {
            return (mv1 - mv2).Magnitude();
        }

        public static MediumDecVector3 Zero()
        {
            return new MediumDecVector3(MediumDec.Zero, MediumDec.Zero, MediumDec.Zero);
        }
    }
}