#pragma once
#include "s00nya_defs.h"
#include "vector2.h"

namespace s00nya
{

	class Collision2D;

	struct S00NYA_API Dimension
	{
		Float width;
		Float height;

		Dimension();
		Dimension(const Float& _width, const Float& _height);
		
	private:
		static Boolean Intersect(
			const Vector2& lhsCenter, const Dimension& lhs, 
			const Vector2& rhsCenter, const Dimension& rhs
		);

		static Boolean Contains(
			const Vector2& lhsCenter, const Dimension& container, 
			const Vector2& rhsCenter, const Dimension& contained
		);

		friend class Collision2D;
	};

}