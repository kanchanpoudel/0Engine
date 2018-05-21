#include "Math/vector2.h"
#include "Math/vector3.h"
#include <cmath>

namespace s00nya
{

	Vector2::Vector2() :
		x(0.0f), y(0.0f)
	{
	}

	Vector2::Vector2(const Float& _x, const Float& _y) :
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

	Float Vector2::Length() const
	{
		return sqrt(x * x + y * y);
	}

	Float Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return(lhs.x * rhs.x + lhs.y * rhs.y);
	}

	Vector3 Vector2::Cross(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector3(0.0f, 0.0f, lhs.x * rhs.y - lhs.y * rhs.x);
	}

	Vector2 Vector2::Normalize(const Vector2& vec)
	{
		Float inv_length = 1.0f / vec.Length();
		return Vector2(vec.x * inv_length, vec.y * inv_length);
	}

	Vector2& Vector2::operator*=(const Float& scalar)
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

	Vector2 operator*(const Vector2& vec, const Float& scalar)
	{
		return Vector2(scalar * vec.x, scalar * vec.y);
	}

	Vector2 operator*(const Float& scalar, const Vector2& vec)
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

	std::string Vector2::GetString() const
	{
		std::stringstream vecStr;
		vecStr << "Vector2 (" << x << ", " << y << ")";
		return vecStr.str();
	}

}