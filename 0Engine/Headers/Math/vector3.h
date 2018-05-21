#pragma once
#include <sstream>
#include "s00nya_defs.h"

namespace s00nya
{

	struct Vector2;

	struct S00NYA_API Vector3
	{
		union { Float x; Float r; };
		union { Float y; Float g; };
		union { Float z; Float b; };

		Vector3();	// Initializes everything to zero
		Vector3(const Vector2& vec, const Float& _z); // Construct from Vector2
		Vector3(const Vector3& vec);
		Vector3(const Float& _x, const Float& _y, const Float& _z);
		Vector3& operator=(const Vector3& vec);
		Vector3 operator-() const;

		Float Length() const;
		static Float Dot(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Normalize(const Vector3& vec);

		Vector3& operator*=(const Float& scalar);
		Vector3& operator+=(const Vector3& vec);
		Vector3& operator-=(const Vector3& vec);

		friend Vector3 operator*(const Vector3& vec, const Float& scalar);
		friend Vector3 operator*(const Float& scalar, const Vector3& vec);
		friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Component wise multiplication
		
		friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
		friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);

		std::string GetString() const;
	};

}