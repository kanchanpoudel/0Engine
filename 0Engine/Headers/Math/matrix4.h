#pragma once
#include "vector3.h"
#include "vector4.h"
#include <sstream>
#include "s00nya_defs.h"

/*
	Matrix4x4 (Matrix4) uses Row Major Matrix System which basically means
	the rows of the matrix are arranged in following way
	| Memory Layout	   |  Rows      | Mathematical|
	-----------------------------------------------
	| 00	01	02	03 |  row[0]    | 00 10 20 30 |
	| 04	05	06	07 |  row[1]	| 01 11 21 31 |
	| 08	09	10	11 |  row[2]	| 02 12 22 32 |
	| 12	13	14	15 |  row[3]	| 03 13 23 33 |

	Element [a, b] can be accessed by [a * 4 + b]

	Matrix4x4 (Matrix4) uses Right Hand Co-ordinate System basically that means
	Right vector points to the right
	Up vector points to up the screen
	Front vector points outside of the screen
*/

namespace s00nya
{

	struct S00NYA_API Matrix4
	{
		union { Float elements[4 * 4]; Vector4 rows[4]; };

		Matrix4(); // Initializes a Identity Matrix
		Matrix4(const Float elementsArray[4 * 4]);

		Matrix4(
			const Vector4& row0,
			const Vector4& row1,
			const Vector4& row2,
			const Vector4& row3
		);	// Construct from 4 rows

		Matrix4(
			const Float& e00, const Float& e10, const Float& e20, const Float& e30,
			const Float& e01, const Float& e11, const Float& e21, const Float& e31,
			const Float& e02, const Float& e12, const Float& e22, const Float& e32,
			const Float& e03, const Float& e13, const Float& e23, const Float& e33
		);

		Matrix4(const Float& diagonalElement); // Diagonal Matrix with given element

		Matrix4(const Matrix4& mat);
		Matrix4& operator=(const Matrix4& mat);
		Matrix4 operator-() const;

		Matrix4& operator*=(const Matrix4& mat);
		Matrix4& operator+=(const Matrix4& mat);
		Matrix4& operator-=(const Matrix4& mat);

		friend Matrix4 operator*(const Float& scalar, const Matrix4& mat);
		friend Matrix4 operator*(const Matrix4& mat, const Float& scalar);
		
		friend Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs);
		friend Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs);
		friend Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs);

		Matrix4& Transform(const Matrix4& mat);

		static Matrix4 Transpose(const Matrix4& mat);
		static Matrix4 Inverse(const Matrix4& mat);

		static Matrix4 Identity();
		static Matrix4 Scale(const Vector3& vec);
		static Matrix4 Translation(const Vector3& vec);
		static Matrix4 Rotation(const Float& angle, const Vector3& axis); // Does not normalize axis
		static Matrix4 LookAt(const Vector3& position, const Vector3& target, const Vector3& up);

		static Matrix4 Orthographic(
			const Float& left,
			const Float& right,
			const Float& bottom,
			const Float& top,
			const Float& near,
			const Float& far
		);
		static Matrix4 Perspective(
			const Float& fov,
			const Float& aspectRatio,
			const Float& near,
			const Float& far
		);

		// Vector and Matrix multiplies one way only
		friend Vector4 operator*(const Vector4& vec, const Matrix4& mat);

		std::string GetString() const;
	};

}