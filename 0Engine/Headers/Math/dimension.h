#pragma once
#include "s00nya_defs.h"
#include "vector2.h"

namespace s00nya
{

	class Collision2D;

	struct S00NYA_API Dimension
	{
		Float halfWidth;
		Float halfHeight;

		Dimension();
		Dimension(const Float& _halfWidth, const Float& _halfHeight);
		
	private:
		static Boolean Intersect(const Dimension& lhs, const Dimension& rhs, const Vector2& lhspivot, const Vector2& rhspivot);
		static Boolean Intersect(const Dimension& lhs, const Dimension& rhs, const Vector2& lhspivot, const Vector2& rhspivot, Vector2& outMTV);
		static Boolean Contains(const Dimension& container, const Dimension& contained, const Vector2& containerpivot, const Vector2& containedpivot);

		friend class Collision2D;
	};

}