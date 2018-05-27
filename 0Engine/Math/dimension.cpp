#include "Math/dimension.h"

namespace s00nya
{

	Dimension::Dimension() :
		pivot(0.0f, 0.0f), halfWidth(10.0f), halfHeight(10.0f)
	{
	}

	Dimension::Dimension(const Vector2& _pivot, const Float& _halfWidth, const Float& _halfHeight) :
		pivot(_pivot), halfWidth(_halfWidth), halfHeight(_halfHeight)
	{
	}

}