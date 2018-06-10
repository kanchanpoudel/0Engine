#pragma once
#include "s00nya.h"
#include "vector3.h"
#include <array>

namespace s00nya
{

	/*
	This struct has been programmed to be used as a Convolution Matrix,
	and some methods may not work as expected
	*/

	struct S00NYA_API Matrix3
	{
		union { Float elements[3 * 3]; Vector3 rows[3]; };

		Matrix3(); // Initializes a Identity Convolution Matrix
		Matrix3(const Float elementsArray[3 * 3]);

		Matrix3(
			const Vector3& row0,
			const Vector3& row1,
			const Vector3& row2
		);	// Construct from 4 rows

		Matrix3(
			const Float& e00, const Float& e10, const Float& e20,
			const Float& e01, const Float& e11, const Float& e21,
			const Float& e02, const Float& e12, const Float& e22
		);

		Matrix3(const Float& diagonalElement); // Diagonal Matrix with given element

		Matrix3(const Matrix3& mat);
		Matrix3& operator=(const Matrix3& mat);
		Matrix3 operator-() const;

		Matrix3& operator*=(const Matrix3& mat);

		Matrix3& operator+=(const Matrix3& mat);
		Matrix3& operator-=(const Matrix3& mat);

		static Matrix3 Identity(); // Not an Identity matrix but identity convolution matrix
		static Matrix3 EdgeDetection();
		static Matrix3 BoxBlur();
		static Matrix3 GaussianBlur();

		friend Matrix3 operator*(const Float& scalar, const Matrix3& mat);
		friend Matrix3 operator*(const Matrix3& mat, const Float& scalar);

		friend Vector3 operator*(const std::array<Vector3, 9>& inputs, const Matrix3& kernal);

		friend Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs);
		friend Matrix3 operator+(const Matrix3& lhs, const Matrix3& rhs);
		friend Matrix3 operator-(const Matrix3& lhs, const Matrix3& rhs);
	};

}