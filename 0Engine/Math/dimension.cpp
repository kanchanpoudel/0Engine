#include "Math/dimension.h"

namespace s00nya
{

	Dimension::Dimension() :
		pivot(0.0f, 0.0f), width(10.0f), height(10.0f)
	{
	}

	Dimension::Dimension(const Vector2& _pivot, const Float& _width, const Float& _height) :
		pivot(_pivot), width(_width), height(_height)
	{
	}

}