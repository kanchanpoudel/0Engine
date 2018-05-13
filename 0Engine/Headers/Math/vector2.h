#pragma once
#include <sstream>

namespace s00nya
{

	struct Vector3;

	struct Vector2
	{
		union { float x; float u; };
		union { float y; float v; };

		Vector2();	//Initializes everything to zero
		Vector2(const float& _x, const float& _y);
		Vector2(const Vector2& vec);
		Vector2& operator=(const Vector2& vec);
		Vector2 operator-() const;

		float Length() const;
		static float Dot(const Vector2& lhs, const Vector2& rhs);
		static Vector3 Cross(const Vector2& lhs, const Vector2& rhs);
		static Vector2 Normalize(const Vector2& vec);

		Vector2& operator*=(const float& scalar);
		Vector2& operator+=(const Vector2& vec);
		Vector2& operator-=(const Vector2& vec);

		friend Vector2 operator*(const Vector2& vec, const float& scalar);
		friend Vector2 operator*(const float& scalar, const Vector2& vec);
		
		friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
		friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

		std::stringstream GetStringStream() const;
	};

}