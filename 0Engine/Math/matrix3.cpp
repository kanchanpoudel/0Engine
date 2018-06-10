#include "Math/matrix3.h"

namespace s00nya
{

	Matrix3::Matrix3():
		elements{
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	}
	{
	}

	Matrix3::Matrix3(const Float elementsArray[3 * 3])
	{
		for (Integer i = 0; i < 9; i++)
			elements[i] = elementsArray[i];
	}

	Matrix3::Matrix3(const Vector3 & row0, const Vector3 & row1, const Vector3 & row2):
		rows{row0, row1, row2}
	{
	}

	Matrix3::Matrix3(
		const Float & e00, const Float & e10, const Float & e20, 
		const Float & e01, const Float & e11, const Float & e21, 
		const Float & e02, const Float & e12, const Float & e22
	):
		elements{
		e00, e10, e20,
		e01, e11, e21,
		e02, e12, e22
	}
	{
	}

	Matrix3::Matrix3(const Float & diagonalElement):
		elements{
		diagonalElement, 0.0f, 0.0f,
		0.0f, diagonalElement, 0.0f,
		0.0f, 0.0f, diagonalElement
	}
	{
	}

	Matrix3::Matrix3(const Matrix3 & mat)
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
	}

	Matrix3& Matrix3::operator=(const Matrix3 & mat)
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

		return *this;
	}

	Matrix3 Matrix3::operator-() const
	{
		return Matrix3(
			-elements[0], -elements[1], -elements[2],
			-elements[3], -elements[4], -elements[5],
			-elements[6], -elements[7], -elements[8]
		);
	}

	Matrix3& Matrix3::operator*=(const Matrix3& mat)
	{
		Matrix3 temp(*this);

		for (Integer x = 0; x < 3; x++)
		{
			for (Integer j = 0; j < 3; j++)
			{
				this->elements[j + 3 * x] = 0;
				for (Integer k = 0; k < 3; k++)
				{
					this->elements[j + 3 * x] += temp.elements[k + 3 * x] * mat.elements[j + 3 * k];
				}
			}
		}
		return *this;
	}

	Matrix3& Matrix3::operator+=(const Matrix3& mat)
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

		return *this;
	}

	Matrix3& Matrix3::operator-=(const Matrix3& mat)
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

		return *this;
	}

	Matrix3 Matrix3::Identity()
	{
		return Matrix3();
	}

	Matrix3 Matrix3::EdgeDetection()
	{
		return Matrix3(
			-1.0f, -1.0f, -1.0f,
			-1.0f,  9.0f, -1.0f,
			-1.0f, -1.0f, -1.0f
		);
	}

	Matrix3 Matrix3::BoxBlur()
	{
		return (1.0f / 9.0f) * Matrix3(
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f
		);
	}

	Matrix3 Matrix3::GaussianBlur()
	{
		return (1.0f / 16.0f) * Matrix3(
			1.0f, 2.0f, 1.0f,
			2.0f, 4.0f, 2.0f,
			1.0f, 2.0f, 1.0f
		);
	}

	Matrix3 operator*(const Float & scalar, const Matrix3 & mat)
	{
		return Matrix3(
			mat.elements[0] * scalar,
			mat.elements[1] * scalar,
			mat.elements[2] * scalar,
			mat.elements[3] * scalar,
			mat.elements[4] * scalar,
			mat.elements[5] * scalar,
			mat.elements[6] * scalar,
			mat.elements[7] * scalar,
			mat.elements[8] * scalar 
		);
	}

	Matrix3 operator*(const Matrix3 & mat, const Float & scalar)
	{
		return Matrix3(
			mat.elements[0] * scalar,
			mat.elements[1] * scalar,
			mat.elements[2] * scalar,
			mat.elements[3] * scalar,
			mat.elements[4] * scalar,
			mat.elements[5] * scalar,
			mat.elements[6] * scalar,
			mat.elements[7] * scalar,
			mat.elements[8] * scalar
		);
	}

	Vector3 operator*(const std::array<Vector3, 9>& inputs, const Matrix3 & kernal)
	{
		return
			kernal.elements[8] * inputs[0] +
			kernal.elements[7] * inputs[1] +
			kernal.elements[6] * inputs[2] +

			kernal.elements[5] * inputs[3] +
			kernal.elements[4] * inputs[4] +
			kernal.elements[3] * inputs[5] +

			kernal.elements[2] * inputs[6] +
			kernal.elements[1] * inputs[7] +
			kernal.elements[0] * inputs[9];
	}

	Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs)
	{
		Matrix3 temp;
		for (Integer i = 0; i < 3; i++)
		{
			for (Integer j = 0; j < 3; j++)
			{
				temp.elements[j + 3 * i] = 0;
				for (Integer k = 0; k < 3; k++)
				{
					temp.elements[j + 3 * i] += lhs.elements[k + 3 * i] * rhs.elements[j + 3 * k];
				}
			}
		}
		return temp;
	}

	Matrix3 operator+(const Matrix3 & lhs, const Matrix3 & rhs)
	{
		return Matrix3(
			lhs.elements[0] + rhs.elements[0],
			lhs.elements[1] + rhs.elements[1],
			lhs.elements[2] + rhs.elements[2],
			lhs.elements[3] + rhs.elements[3],
			lhs.elements[4] + rhs.elements[4],
			lhs.elements[5] + rhs.elements[5],
			lhs.elements[6] + rhs.elements[6],
			lhs.elements[7] + rhs.elements[7],
			lhs.elements[8] + rhs.elements[8]
		);
	}

	Matrix3 operator-(const Matrix3 & lhs, const Matrix3 & rhs)
	{
		return Matrix3(
			lhs.elements[0] - rhs.elements[0],
			lhs.elements[1] - rhs.elements[1],
			lhs.elements[2] - rhs.elements[2],
			lhs.elements[3] - rhs.elements[3],
			lhs.elements[4] - rhs.elements[4],
			lhs.elements[5] - rhs.elements[5],
			lhs.elements[6] - rhs.elements[6],
			lhs.elements[7] - rhs.elements[7],
			lhs.elements[8] - rhs.elements[8]
		);
	}

}