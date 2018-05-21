#pragma once
#include <sstream>
#include "s00nya_defs.h"

namespace s00nya
{

	struct Vector3;

	struct S00NYA_API Vector4
	{
		union { Float x; Float r; };
		union { Float y; Float g; };
		union { Float z; Float b; };
		union { Float w; Float a; };

		Vector4();	// Initializes everything to zero
		Vector4(const Vector3& vec, const Float& _w); // Construct from Vector3
		Vector4(const Vector4& vec);
		Vector4(const Float& _x, const Float& _y, const Float& _z, const Float& _w);
		Vector4& operator=(const Vector4& vec);
		Vector4 operator-() const;

		Float Length() const;
		Vector3 GetXYZ() const; // removes the W component changing to Vector3
		static Float Dot(const Vector4& lhs, const Vector4& rhs);
		// Ignores the w component and sets as 1.0f
		static Vector4 Cross(const Vector4& lhs, const Vector4& rhs); 
		static Vector4 Normalize(const Vector4& vec);

		Vector4& operator*=(const Float& scalar);
		Vector4& operator+=(const Vector4& vec);
		Vector4& operator-=(const Vector4& vec);

		friend Vector4 operator*(const Vector4& vec, const Float& scalar);
		friend Vector4 operator*(const Float& scalar, const Vector4& vec);
		friend Vector4 operator*(const Vector4& lhs, const Vector4& rhs); // Component wise multiplication
		
		friend Vector4 operator+(const Vector4& lhs, const Vector4& rhs);
		friend Vector4 operator-(const Vector4& lhs, const Vector4& rhs);

		std::string GetString() const;
	};

}