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

	};

}