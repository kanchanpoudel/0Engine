#pragma once

namespace s00nya
{

	struct Vector3;

	struct Vector4
	{
		union { float x; float r; };
		union { float y; float g; };
		union { float z; float b; };
		union { float w; float a; };

		Vector4();	// Initializes eveything to zero
		Vector4(const Vector3& vec, const float& _w); // Construct from Vector3
		Vector4(const Vector4& vec);
		Vector4(const float& _x, const float& _y, const float& _z, const float& _w);
		Vector4& operator=(const Vector4& vec);
		Vector4 operator-() const;

		float Length() const;
		Vector3 GetXYZ() const; // removes the W component changing to Vector3
		static float Dot(const Vector4& lhs, const Vector4& rhs);
		// Ignores the w component and sets as 1.0f
		static Vector4 Cross(const Vector4& lhs, const Vector4& rhs); 
		static Vector4 Normalize(const Vector4& vec);

		Vector4& operator*=(const float& scalar);
		Vector4& operator+=(const Vector4& vec);
		Vector4& operator-=(const Vector4& vec);

		static Vector4 operator*(const Vector4& vec, const float& scalar);
		static Vector4 operator*(const float& scalar, const Vector4& vec);
		static Vector4 operator*(const Vector4& lhs, const Vector4& rhs); // Component wise multiplication
		
		static Vector4 operator+(const Vector4& lhs, const Vector4& rhs);
		static Vector4 operator-(const Vector4& lhs, const Vector4& rhs);
	};

}