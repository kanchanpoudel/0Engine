#pragma once
#include "s00nya_defs.h"
#include "vector2.h"

namespace s00nya
{

	struct S00NYA_API Dimension
	{
		Vector2 pivot;
		Float halfWidth;
		Float halfHeight;

		Dimension();
		Dimension(const Vector2& _pivot, const Float& _halfWidth, const Float& _halfHeight);
		
	private:
		static Boolean Intersect(const Dimension& lhs, const Dimension& rhs);
		static Boolean Intersect(const Dimension& lhs, const Dimension& rhs, Vector2& outMTV);
		static Boolean Contains(const Dimension& container, const Dimension& contained);
	};

}