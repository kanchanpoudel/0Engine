#pragma once
#include "s00nya_defs.h"
#include "vector2.h"

namespace s00nya
{

	struct S00NYA_API Dimension
	{
		Vector2 pivot;
		Float width;
		Float height;

		Dimension();
		Dimension(const Vector2& _pivot, const Float& _width, const Float& _height);
	};

}