#include "Math\vector2.h"
#include "Math\vector3.h"
#include <cmath>

namespace s00nya
{

	Vector2::Vector2() :
		x(0.0f), y(0.0f)
	{
	}

	Vector2::Vector2(const float& _x, const float& _y) :
		x(_x), y(_y)
	{
	}

	Vector2::Vector2(const Vector2& vec)
	{
		if (this == &vec)
			return;

		x = vec.x;
		y = vec.y;
	}

	Vector2& Vector2::operator=(const Vector2& vec)
	{
		if (this == &vec)
			return *this;

		x = vec.x;
		y = vec.y;
		return *this;
	}

	Vector2 Vector2::operator-() const
	{
		return Vector2(-x, -y);
	}

	float Vector2::Length() const
	{
		return sqrt(x * x + y * y);
	}

	float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return(lhs.x * rhs.x + lhs.y * rhs.y);
	}

	Vector3 Vector2::Cross(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector3(0.0f, 0.0f, lhs.x * rhs.y - lhs.y * rhs.x);
	}

	Vector2 Vector2::Normalize(const Vector2& vec)
	{
		float inv_length = 1.0f / vec.Length();
		return Vector2(vec.x * inv_length, vec.y * inv_length);
	}

	Vector2& Vector2::operator*=(const float& scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	Vector2 operator*(const Vector2& vec, const float& scalar)
	{
		return Vector2(scalar * vec.x, scalar * vec.y);
	}

	Vector2 operator*(const float& scalar, const Vector2& vec)
	{
		return Vector2(scalar * vec.x, scalar * vec.y);
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
	}

}