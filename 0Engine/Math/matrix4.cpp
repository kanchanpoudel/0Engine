#include "Math/matrix4.h"
#include <cmath>

namespace s00nya
{

	Matrix4::Matrix4() :
		elements{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	}
	{
	}

	Matrix4::Matrix4(const Float elementsArray[4 * 4])
	{
		for (Integer i = 0; i < 16; i++)
			this->elements[i] = elementsArray[i];
	}

	Matrix4::Matrix4(
		const Vector4& row0,
		const Vector4& row1,
		const Vector4& row2,
		const Vector4& row3
	):
		rows{ row0, row1, row2, row3 }
	{
	}

	Matrix4::Matrix4(
		const Float& e00, const Float& e10, const Float& e20, const Float& e30,
		const Float& e01, const Float& e11, const Float& e21, const Float& e31,
		const Float& e02, const Float& e12, const Float& e22, const Float& e32,
		const Float& e03, const Float& e13, const Float& e23, const Float& e33
	) :
		elements{
		e00, e10, e20, e30,
		e01, e11, e21, e31,
		e02, e12, e22, e32,
		e03, e13, e23, e33
	}
	{
	}

	Matrix4::Matrix4(const Float& diagonalElement) :
		elements{
		diagonalElement,0.0f,0.0f,0.0f,
		0.0f,diagonalElement,0.0f,0.0f,
		0.0f,0.0f,diagonalElement,0.0f,
		0.0f,0.0f,0.0f,diagonalElement
	}
	{
	}

	Matrix4::Matrix4(const Matrix4& mat)
	{
		if (this == &mat)
			return;
		this->elements[0] = mat.elements[0];
		this->elements[1] = mat.elements[1];
		this->elements[2] = mat.elements[2];
		this->elements[3] = mat.elements[3];
		this->elements[4] = mat.elements[4];
		this->elements[5] = mat.elements[5];
		this->elements[6] = mat.elements[6];
		this->elements[7] = mat.elements[7];
		this->elements[8] = mat.elements[8];
		this->elements[9] = mat.elements[9];
		this->elements[10] = mat.elements[10];
		this->elements[11] = mat.elements[11];
		this->elements[12] = mat.elements[12];
		this->elements[13] = mat.elements[13];
		this->elements[14] = mat.elements[14];
		this->elements[15] = mat.elements[15];
	}

	Matrix4& Matrix4::operator=(const Matrix4& mat)
	{
		if (this == &mat)
			return *this;
		elements[0] = mat.elements[0];
		elements[1] = mat.elements[1];
		elements[2] = mat.elements[2];
		elements[3] = mat.elements[3];
		elements[4] = mat.elements[4];
		elements[5] = mat.elements[5];
		elements[6] = mat.elements[6];
		elements[7] = mat.elements[7];
		elements[8] = mat.elements[8];
		elements[9] = mat.elements[9];
		elements[10] = mat.elements[10];
		elements[11] = mat.elements[11];
		elements[12] = mat.elements[12];
		elements[13] = mat.elements[13];
		elements[14] = mat.elements[14];
		elements[15] = mat.elements[15];
		return *this;
	}

	Matrix4 Matrix4::operator-() const
	{
		return Matrix4(
			-elements[0],
			-elements[1],
			-elements[2],
			-elements[3],
			-elements[4],
			-elements[5],
			-elements[6],
			-elements[7],
			-elements[8],
			-elements[9],
			-elements[10],
			-elements[11],
			-elements[12],
			-elements[13],
			-elements[14],
			-elements[15]
		);
	}

	Matrix4& Matrix4::operator*=(const Matrix4& mat)
	{
		Matrix4 temp(*this);

		for (Integer x = 0; x < 4; x++)
		{
			for (Integer j = 0; j < 4; j++)
			{
				this->elements[j + 4 * x] = 0;
				for (Integer k = 0; k < 4; k++)
				{
					this->elements[j + 4 * x] += temp.elements[k + 4 * x] * mat.elements[j + 4 * k];
				}
			}
		}
		return *this;
	}

	Matrix4& Matrix4::operator+=(const Matrix4& mat)
	{
		elements[0] += mat.elements[0];
		elements[1] += mat.elements[1];
		elements[2] += mat.elements[2];
		elements[3] += mat.elements[3];
		elements[4] += mat.elements[4];
		elements[5] += mat.elements[5];
		elements[6] += mat.elements[6];
		elements[7] += mat.elements[7];
		elements[8] += mat.elements[8];
		elements[9] += mat.elements[9];
		elements[10] += mat.elements[10];
		elements[11] += mat.elements[11];
		elements[12] += mat.elements[12];
		elements[13] += mat.elements[13];
		elements[14] += mat.elements[14];
		elements[15] += mat.elements[15];
		return *this;
	}

	Matrix4& Matrix4:: operator-=(const Matrix4& mat)
	{
		elements[0] -= mat.elements[0];
		elements[1] -= mat.elements[1];
		elements[2] -= mat.elements[2];
		elements[3] -= mat.elements[3];
		elements[4] -= mat.elements[4];
		elements[5] -= mat.elements[5];
		elements[6] -= mat.elements[6];
		elements[7] -= mat.elements[7];
		elements[8] -= mat.elements[8];
		elements[9] -= mat.elements[9];
		elements[10] -= mat.elements[10];
		elements[11] -= mat.elements[11];
		elements[12] -= mat.elements[12];
		elements[13] -= mat.elements[13];
		elements[14] -= mat.elements[14];
		elements[15] -= mat.elements[15];
		return *this;
	}

	Matrix4 operator*(const Float& scalar, const Matrix4& mat)
	{
		return Matrix4(
			mat.elements[0] * scalar,
			mat.elements[1] * scalar,
			mat.elements[2] * scalar,
			mat.elements[3] * scalar,
			mat.elements[4] * scalar,
			mat.elements[5] * scalar,
			mat.elements[6] * scalar,
			mat.elements[7] * scalar,
			mat.elements[8] * scalar,
			mat.elements[9] * scalar,
			mat.elements[10] * scalar,
			mat.elements[11] * scalar,
			mat.elements[12] * scalar,
			mat.elements[13] * scalar,
			mat.elements[14] * scalar,
			mat.elements[15] * scalar);
	}

	Matrix4 operator*(const Matrix4& mat, const Float& scalar)
	{
		return Matrix4(
			mat.elements[0] * scalar,
			mat.elements[1] * scalar,
			mat.elements[2] * scalar,
			mat.elements[3] * scalar,
			mat.elements[4] * scalar,
			mat.elements[5] * scalar,
			mat.elements[6] * scalar,
			mat.elements[7] * scalar,
			mat.elements[8] * scalar,
			mat.elements[9] * scalar,
			mat.elements[10] * scalar,
			mat.elements[11] * scalar,
			mat.elements[12] * scalar,
			mat.elements[13] * scalar,
			mat.elements[14] * scalar,
			mat.elements[15] * scalar);
	}

	Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 temp;
		for (Integer i = 0; i < 4; i++)
		{
			for (Integer j = 0; j < 4; j++)
			{
				temp.elements[j + 4 * i] = 0;
				for (Integer k = 0; k < 4; k++)
				{
					temp.elements[j + 4 * i] += lhs.elements[k + 4 * i] * rhs.elements[j + 4 * k];
				}
			}
		}
		return temp;
	}

	Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs)
	{
		return Matrix4(
			lhs.elements[0] + rhs.elements[0],
			lhs.elements[1] + rhs.elements[1],
			lhs.elements[2] + rhs.elements[2],
			lhs.elements[3] + rhs.elements[3],
			lhs.elements[4] + rhs.elements[4],
			lhs.elements[5] + rhs.elements[5],
			lhs.elements[6] + rhs.elements[6],
			lhs.elements[7] + rhs.elements[7],
			lhs.elements[8] + rhs.elements[8],
			lhs.elements[9] + rhs.elements[9],
			lhs.elements[10] + rhs.elements[10],
			lhs.elements[11] + rhs.elements[11],
			lhs.elements[12] + rhs.elements[12],
			lhs.elements[13] + rhs.elements[13],
			lhs.elements[14] + rhs.elements[14],
			lhs.elements[15] + rhs.elements[15]
			);
	}

	Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs)
	{
		return Matrix4(
			lhs.elements[0] - rhs.elements[0],
			lhs.elements[1] - rhs.elements[1],
			lhs.elements[2] - rhs.elements[2],
			lhs.elements[3] - rhs.elements[3],
			lhs.elements[4] - rhs.elements[4],
			lhs.elements[5] - rhs.elements[5],
			lhs.elements[6] - rhs.elements[6],
			lhs.elements[7] - rhs.elements[7],
			lhs.elements[8] - rhs.elements[8],
			lhs.elements[9] - rhs.elements[9],
			lhs.elements[10] - rhs.elements[10],
			lhs.elements[11] - rhs.elements[11],
			lhs.elements[12] - rhs.elements[12],
			lhs.elements[13] - rhs.elements[13],
			lhs.elements[14] - rhs.elements[14],
			lhs.elements[15] - rhs.elements[15]
			);
	}

	Matrix4& Matrix4::Transform(const Matrix4& mat)
	{

		*this *= mat;
		return *this;
	}

	Matrix4 Matrix4::Transpose(const Matrix4& mat)
	{
		Matrix4 temp;
		for (Integer i = 0; i < 4; i++)
		{
			for (Integer j = 0; j < 4; j++)
				temp.elements[4 * i + j] = mat.elements[4 * j + i];
		}
		return temp;
	}

	Matrix4 Matrix4::Identity()
	{
		return Matrix4();
	}

	Matrix4 Matrix4::Scale(const Vector3& vec)
	{
		return Matrix4(
			vec.x, 0.0f, 0.0f, 0.0f,
			0.0f, vec.y, 0.0f, 0.0f,
			0.0f, 0.0f, vec.z, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	}

	Matrix4 Matrix4::Translation(const Vector3& vec)
	{
		return Matrix4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			vec.x, vec.y, vec.z, 1.0f
		);
	}

	Matrix4 Matrix4::Rotation(const Float& angle, const Vector3& axis)
	{
		Float c = cosf(angle);
		Float s = sinf(angle);
		Float xx = axis.x * axis.x;
		Float xy = axis.x *axis.y;
		Float xz = axis.x *axis.z;
		Float yy = axis.y *axis.y;
		Float yz = axis.y *axis.z;
		Float zz = axis.z *axis.z;

		return Matrix4(xx * (1.0f - c) + c, xy * (1.0f - c) - axis.z * s, xz * (1.0f - c) + axis.y * s, 0.0f,
			xy * (1.0f - c) + axis.z * s, yy * (1.0f - c) + c, yz * (1.0f - c) - axis.x * s, 0.0f,
			xz * (1.0f - c) - axis.y * s, yz * (1.0f - c) + axis.x * s, zz *(1.0f - c) + c, zz *(1.0f - c) + c,
			0.0f, 0.0f, 0.0f, 1.0f);
	}

	Vector4 operator*(const Vector4& vec, const Matrix4& mat)
	{
		return Vector4(
			vec.x*mat.elements[0] + vec.y*mat.elements[4] + vec.z*mat.elements[8] + vec.w*mat.elements[12],
			vec.x*mat.elements[1] + vec.y*mat.elements[5] + vec.z*mat.elements[9] + vec.w*mat.elements[13],
			vec.x*mat.elements[2] + vec.y*mat.elements[6] + vec.z*mat.elements[10] + vec.w*mat.elements[14],
			vec.x*mat.elements[3] + vec.y*mat.elements[7] + vec.z*mat.elements[11] + vec.w*mat.elements[15]
		);
	}

	Matrix4 Matrix4::Inverse(const Matrix4& mat)
	{
		Matrix4 INV;

		INV.elements[0] = mat.elements[5] * mat.elements[10] * mat.elements[15] -
			mat.elements[5] * mat.elements[11] * mat.elements[14] -
			mat.elements[9] * mat.elements[6] * mat.elements[15] +
			mat.elements[9] * mat.elements[7] * mat.elements[14] +
			mat.elements[13] * mat.elements[6] * mat.elements[11] -
			mat.elements[13] * mat.elements[7] * mat.elements[10];

		INV.elements[4] = -mat.elements[4] * mat.elements[10] * mat.elements[15] +
			mat.elements[4] * mat.elements[11] * mat.elements[14] +
			mat.elements[8] * mat.elements[6] * mat.elements[15] -
			mat.elements[8] * mat.elements[7] * mat.elements[14] -
			mat.elements[12] * mat.elements[6] * mat.elements[11] +
			mat.elements[12] * mat.elements[7] * mat.elements[10];

		INV.elements[8] = mat.elements[4] * mat.elements[9] * mat.elements[15] -
			mat.elements[4] * mat.elements[11] * mat.elements[13] -
			mat.elements[8] * mat.elements[5] * mat.elements[15] +
			mat.elements[8] * mat.elements[7] * mat.elements[13] +
			mat.elements[12] * mat.elements[5] * mat.elements[11] -
			mat.elements[12] * mat.elements[7] * mat.elements[9];

		INV.elements[12] = -mat.elements[4] * mat.elements[9] * mat.elements[14] +
			mat.elements[4] * mat.elements[10] * mat.elements[13] +
			mat.elements[8] * mat.elements[5] * mat.elements[14] -
			mat.elements[8] * mat.elements[6] * mat.elements[13] -
			mat.elements[12] * mat.elements[5] * mat.elements[10] +
			mat.elements[12] * mat.elements[6] * mat.elements[9];

		INV.elements[1] = -mat.elements[1] * mat.elements[10] * mat.elements[15] +
			mat.elements[1] * mat.elements[11] * mat.elements[14] +
			mat.elements[9] * mat.elements[2] * mat.elements[15] -
			mat.elements[9] * mat.elements[3] * mat.elements[14] -
			mat.elements[13] * mat.elements[2] * mat.elements[11] +
			mat.elements[13] * mat.elements[3] * mat.elements[10];

		INV.elements[5] = mat.elements[0] * mat.elements[10] * mat.elements[15] -
			mat.elements[0] * mat.elements[11] * mat.elements[14] -
			mat.elements[8] * mat.elements[2] * mat.elements[15] +
			mat.elements[8] * mat.elements[3] * mat.elements[14] +
			mat.elements[12] * mat.elements[2] * mat.elements[11] -
			mat.elements[12] * mat.elements[3] * mat.elements[10];

		INV.elements[9] = -mat.elements[0] * mat.elements[9] * mat.elements[15] +
			mat.elements[0] * mat.elements[11] * mat.elements[13] +
			mat.elements[8] * mat.elements[1] * mat.elements[15] -
			mat.elements[8] * mat.elements[3] * mat.elements[13] -
			mat.elements[12] * mat.elements[1] * mat.elements[11] +
			mat.elements[12] * mat.elements[3] * mat.elements[9];

		INV.elements[13] = mat.elements[0] * mat.elements[9] * mat.elements[14] -
			mat.elements[0] * mat.elements[10] * mat.elements[13] -
			mat.elements[8] * mat.elements[1] * mat.elements[14] +
			mat.elements[8] * mat.elements[2] * mat.elements[13] +
			mat.elements[12] * mat.elements[1] * mat.elements[10] -
			mat.elements[12] * mat.elements[2] * mat.elements[9];

		INV.elements[2] = mat.elements[1] * mat.elements[6] * mat.elements[15] -
			mat.elements[1] * mat.elements[7] * mat.elements[14] -
			mat.elements[5] * mat.elements[2] * mat.elements[15] +
			mat.elements[5] * mat.elements[3] * mat.elements[14] +
			mat.elements[13] * mat.elements[2] * mat.elements[7] -
			mat.elements[13] * mat.elements[3] * mat.elements[6];

		INV.elements[6] = -mat.elements[0] * mat.elements[6] * mat.elements[15] +
			mat.elements[0] * mat.elements[7] * mat.elements[14] +
			mat.elements[4] * mat.elements[2] * mat.elements[15] -
			mat.elements[4] * mat.elements[3] * mat.elements[14] -
			mat.elements[12] * mat.elements[2] * mat.elements[7] +
			mat.elements[12] * mat.elements[3] * mat.elements[6];

		INV.elements[10] = mat.elements[0] * mat.elements[5] * mat.elements[15] -
			mat.elements[0] * mat.elements[7] * mat.elements[13] -
			mat.elements[4] * mat.elements[1] * mat.elements[15] +
			mat.elements[4] * mat.elements[3] * mat.elements[13] +
			mat.elements[12] * mat.elements[1] * mat.elements[7] -
			mat.elements[12] * mat.elements[3] * mat.elements[5];

		INV.elements[14] = -mat.elements[0] * mat.elements[5] * mat.elements[14] +
			mat.elements[0] * mat.elements[6] * mat.elements[13] +
			mat.elements[4] * mat.elements[1] * mat.elements[14] -
			mat.elements[4] * mat.elements[2] * mat.elements[13] -
			mat.elements[12] * mat.elements[1] * mat.elements[6] +
			mat.elements[12] * mat.elements[2] * mat.elements[5];

		INV.elements[3] = -mat.elements[1] * mat.elements[6] * mat.elements[11] +
			mat.elements[1] * mat.elements[7] * mat.elements[10] +
			mat.elements[5] * mat.elements[2] * mat.elements[11] -
			mat.elements[5] * mat.elements[3] * mat.elements[10] -
			mat.elements[9] * mat.elements[2] * mat.elements[7] +
			mat.elements[9] * mat.elements[3] * mat.elements[6];

		INV.elements[7] = mat.elements[0] * mat.elements[6] * mat.elements[11] -
			mat.elements[0] * mat.elements[7] * mat.elements[10] -
			mat.elements[4] * mat.elements[2] * mat.elements[11] +
			mat.elements[4] * mat.elements[3] * mat.elements[10] +
			mat.elements[8] * mat.elements[2] * mat.elements[7] -
			mat.elements[8] * mat.elements[3] * mat.elements[6];

		INV.elements[11] = -mat.elements[0] * mat.elements[5] * mat.elements[11] +
			mat.elements[0] * mat.elements[7] * mat.elements[9] +
			mat.elements[4] * mat.elements[1] * mat.elements[11] -
			mat.elements[4] * mat.elements[3] * mat.elements[9] -
			mat.elements[8] * mat.elements[1] * mat.elements[7] +
			mat.elements[8] * mat.elements[3] * mat.elements[5];

		INV.elements[15] = mat.elements[0] * mat.elements[5] * mat.elements[10] -
			mat.elements[0] * mat.elements[6] * mat.elements[9] -
			mat.elements[4] * mat.elements[1] * mat.elements[10] +
			mat.elements[4] * mat.elements[2] * mat.elements[9] +
			mat.elements[8] * mat.elements[1] * mat.elements[6] -
			mat.elements[8] * mat.elements[2] * mat.elements[5];

		Float det(mat.elements[0] * INV.elements[0] + mat.elements[1] * INV.elements[4] + mat.elements[2] * INV.elements[8] + mat.elements[3] * INV.elements[12]);
		det = 1.0f / det;

		for (Integer i = 0; i < 16; i++)
			INV.elements[i] = INV.elements[i] * det;
		return INV;
	}

	Matrix4 Matrix4::LookAt(const Vector3& position, const Vector3& target, const Vector3& worldUp)
	{
		Vector3 fwd = Vector3::Normalize(position - target);
		Vector3 right = Vector3::Normalize((Vector3::Cross(worldUp, fwd)));
		Vector3 up = Vector3::Cross(fwd, right);
		return Matrix4(
			right.x, right.y, right.z, 0.0f,
			up.x,	 up.y,	  up.z,	   0.0f,
			fwd.x,	 fwd.y,	  fwd.z,   0.f,
			0.0f,    0.0f,    0.0f,    1.0f
		);
	}

	Matrix4 Matrix4::Orthographic(
		const Float& left,
		const Float& right,
		const Float& bottom,
		const Float& top,
		const Float& near,
		const Float& far
	)
	{
		return Matrix4(
			2.0f / (right - left), 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
			0.0f, 0.0f, -2.0f / (far - near), 0.0f,
			-(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f
		);
	}

	Matrix4 Matrix4::Perspective(

		const Float& fov,
		const Float& aspectRatio,
		const Float& near,
		const Float& far
	)
	{
		Float cot = 1.0f / tanf(fov / 2.0f);
		return Matrix4(
			cot / aspectRatio, 0.0f, 0.0f, 0.0f,
			0.0f, cot, 0.0f, 0.0f,
			0.0f, 0.0f, -(far + near) / (far - near), -1.0f,
			0.0f, 0.0f, (-2 * far*near) / (far - near), 0.0f
			);
	}

	std::string Matrix4::GetString() const
	{
		std::stringstream MatStr;
		MatStr << "Matrix4 (" << elements[0] << ", " << elements[1] << ", " << elements[2] << ", " << elements[3] << '\n'
			<< elements[4] << ", " << elements[5] << ", " << elements[6] << ", " << elements[7] << '\n'
			<< elements[8] << ", " << elements[9] << ", " << elements[10] << ", " << elements[11] << '\n'
			<< elements[12] << ", " << elements[13] << ", " << elements[14] << ", " << elements[15] << ")";
		return MatStr.str();
	}

}
