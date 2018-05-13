#include "Math\vector2.h"
#include "Math\vector3.h"
#include <cmath>

namespace s00nya
{

	Vector3::Vector3() :
		x(0.0f), y(0.0f), z(0.0f)
	{
	}

	Vector3::Vector3(const Vector2& vec, const float& _z) :
		x(vec.x), y(vec.y), z(_z)
	{
	}

	Vector3::Vector3(const Vector3& vec)
	{
		if (this == &vec)
			return;

		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	Vector3::Vector3(const float& _x, const float& _y, const float& _z) :
		x(_x), y(_y), z(_z)
	{
	}

	Vector3& Vector3::operator=(const Vector3& vec)
	{
		if (this == &vec)
			return *this;

		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}

	Vector3 Vector3::operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	float Vector3::Length()const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}

	Vector3 Vector3::Normalize(const Vector3& vec)
	{
		float inverse_length(1.0f / vec.Length());
		return Vector3(vec.x * inverse_length, vec.y * inverse_length, vec.z * inverse_length);

	}

	Vector3& Vector3::operator*=(const float& scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
	}

	Vector3& Vector3::operator+=(const Vector3& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;
		return *this;
	}

	Vector3 operator*(const Vector3& vec, const float& scalar)
	{
		return Vector3(
			vec.x * scalar,
			vec.y * scalar,
			vec.z * scalar
		);

	}
	Vector3 operator*(const float& scalar, const Vector3& vec)
	{
		return Vector3(
			vec.x * scalar,
			vec.y * scalar,
			vec.z * scalar
		);

	}

	Vector3 operator*(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.x * rhs.x,
			lhs.y * rhs.y,
			lhs.z * rhs.z
		);

	}

	Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.x + rhs.x,
			lhs.y + rhs.y,
			lhs.z + rhs.z
		);
	}

	Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
	{
		return Vector3(
			lhs.x - rhs.x,
			lhs.y - rhs.y,
			lhs.z - rhs.z
		);
	}

	std::stringstream Vector3::GetStringStream() const
	{
		std::stringstream vecStr;
		vecStr << "Vector3 (" << x << ", " << y << ", " << z << ")";
		return vecStr;
	}

}
