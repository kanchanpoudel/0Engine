#include "Math\vector3.h"
#include "Math\vector4.h"
#include <cmath>

namespace s00nya
{

	Vector4::Vector4():
		x(0.0f),
		y(0.0f),
		z(0.0f),
		w(0.0f)
	{
	}

	Vector4::Vector4(const Vector3& vec, const float& _w):
		 x(vec.x), 
		 y(vec.y), 
		 z(vec.z),
		 w(_w)
	{
	}

	Vector4::Vector4(const Vector4& vec)
	{
		if (this == &vec)
			return;

		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
	}

	Vector4::Vector4(const float& _x, const float& _y, const float& _z, const float& _w)
		: x(_x), y(_y), z(_z), w(_w)
	{
	}

	Vector4& Vector4::operator=(const Vector4& vec)
	{
		if (this == &vec)
			return *this;

		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
		return *this;
	}

	Vector4 Vector4::operator-() const
	{
		return Vector4(-x, -y, -z, -w);
	}

	float Vector4::Length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	Vector3 Vector4::GetXYZ() const
	{
		return Vector3(x , y , z);
	}

	float Vector4::Dot(const Vector4& lhs, const Vector4& rhs)
	{
		return (
			lhs.x * rhs.x +
			lhs.y * rhs.y + 
			lhs.z * rhs.z +
			lhs.w * rhs.w
		);
	}

	Vector4 Vector4::Cross(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(
			lhs.y*rhs.z - rhs.y*lhs.z,
			lhs.z*rhs.x - rhs.z*lhs.x,
			lhs.x*rhs.y - rhs.x*lhs.y,
			1.0f
		);
	}

	Vector4 Vector4::Normalize(const Vector4& vec)
	{
		float inv_length = 1.0f / vec.Length();
		return Vector4(
			vec.x * inv_length,
			vec.y * inv_length,
			vec.z * inv_length,
			vec.w * inv_length
		);
	}

	Vector4& Vector4::operator*=(const float& scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;
		return *this;
	}

	Vector4& Vector4:: operator+=(const Vector4& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		w += vec.w;
		return *this;
	}

	Vector4& Vector4:: operator-=(const Vector4& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		w -= vec.w;
		return *this;
	}

	Vector4 operator*(const Vector4& vec, const float& scalar)
	{
		return Vector4(
			scalar * vec.x, 
			scalar * vec.y, 
			scalar * vec.z,
			scalar * vec.w
		);
	}

	Vector4 operator*(const float& scalar, const Vector4& vec)
	{
		return Vector4(
			scalar * vec.x,
			scalar * vec.y, 
			scalar * vec.z,
			scalar * vec.w
		);
	}

	Vector4 operator*(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(
			lhs.x * rhs.x,
			lhs.y * rhs.y,
			lhs.z * rhs.z,
			lhs.w * rhs.w
		);
	}

	Vector4 operator+(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(
			lhs.x + rhs.x,
			lhs.y + rhs.y,
			lhs.z + rhs.z,
			lhs.w + rhs.w
		);
	}

	Vector4 operator-(const Vector4& lhs, const Vector4& rhs)
	{
		return Vector4(
			lhs.x - rhs.x,
			lhs.y - rhs.y,
			lhs.z - rhs.z,
			lhs.w - rhs.w
		);
	}

	std::stringstream Vector4::GetStringStream() const
	{
		std::stringstream vecStr;
		vecStr << "Vector4 (" << x << ", " << y << ", " << z << ", " << w << ")";
		return vecStr;
	}

}