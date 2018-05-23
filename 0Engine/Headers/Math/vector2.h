#pragma once
#include <sstream>
#include "s00nya_defs.h"

namespace s00nya
{

	struct Vector3;

	struct S00NYA_API Vector2
	{
		union
		{
			struct { Float x; Float y; };
			struct { Float u; Float v; };
			Float values[2];
		};

		Vector2();	//Initializes everything to zero
		Vector2(const Float& _x, const Float& _y);
		Vector2(const Vector2& vec);
		Vector2& operator=(const Vector2& vec);
		Vector2 operator-() const;

		Float Length() const;
		static Float Dot(const Vector2& lhs, const Vector2& rhs);
		static Vector3 Cross(const Vector2& lhs, const Vector2& rhs);
		static Vector2 Normalize(const Vector2& vec);

		Vector2& operator*=(const Float& scalar);
		Vector2& operator+=(const Vector2& vec);
		Vector2& operator-=(const Vector2& vec);

		friend Vector2 operator*(const Vector2& vec, const Float& scalar);
		friend Vector2 operator*(const Float& scalar, const Vector2& vec);
		
		friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
		friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

		std::string GetString() const;
	};

}