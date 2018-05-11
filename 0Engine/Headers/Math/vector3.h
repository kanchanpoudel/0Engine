#pragma once

namespace s00nya
{

	struct Vector2;

	struct Vector3
	{
		union { float x; float r; };
		union { float y; float g; };
		union { float z; float b; };

		Vector3();	// Initializes eveything to zero
		Vector3(const Vector2& vec, const float& _z); // Construct from Vector2
		Vector3(const Vector3& vec);
		Vector3(const float& _x, const float& _y, const float& _z);
		Vector3& operator=(const Vector3& vec);
		Vector3 operator-() const;

		float Length() const;
		static float Dot(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);
		static Vector3 Normalize(const Vector3& vec);

		Vector3& operator*=(const float& scalar);
		Vector3& operator+=(const Vector3& vec);
		Vector3& operator-=(const Vector3& vec);

		friend Vector3 operator*(const Vector3& vec, const float& scalar);
		friend Vector3 operator*(const float& scalar, const Vector3& vec);
		friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs); // Component wise multiplication
		
		friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
		friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
	};

}