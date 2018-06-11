#include "Math/dimension.h"

namespace s00nya
{

	Dimension::Dimension() :
		width(0.0f), height(0.0f)
	{
	}

	Dimension::Dimension(const Float& _width, const Float& _height) :
		width(_width), height(_height)
	{
	}

	Boolean Dimension::Intersect(
		const Vector2& lhsCenter, const Dimension& lhs, 
		const Vector2& rhsCenter, const Dimension& rhs
	)
	{
		Float minx_lhs(lhsCenter.x - lhs.width);
		Float miny_lhs(lhsCenter.y - lhs.height);
		Float maxx_lhs(lhsCenter.x + lhs.width);
		Float maxy_lhs(lhsCenter.y + lhs.height);

		Float minx_rhs(rhsCenter.x - lhs.width);
		Float miny_rhs(rhsCenter.y - lhs.width);
		Float maxx_rhs(rhsCenter.x + rhs.width);
		Float maxy_rhs(rhsCenter.y + rhs.height);

		return maxx_lhs > minx_rhs && minx_lhs < maxx_rhs && maxy_lhs > miny_lhs && miny_lhs < maxy_rhs;
	}

	Boolean Dimension::Contains(
		const Vector2 & lhsCenter, const Dimension & container,
		const Vector2 & rhsCenter, const Dimension & contained
	)
	{
		Float minx_lhs(lhsCenter.x - container.width);
		Float miny_lhs(lhsCenter.y - container.height);
		Float maxx_lhs(lhsCenter.x + container.width);
		Float maxy_lhs(lhsCenter.y + container.height);

		Float minx_rhs(rhsCenter.x - contained.width);
		Float miny_rhs(rhsCenter.y - contained.width);
		Float maxx_rhs(rhsCenter.x + contained.width);
		Float maxy_rhs(rhsCenter.y + contained.height);

		return minx_lhs < minx_rhs && maxx_lhs > maxx_rhs && miny_lhs < miny_rhs && maxy_lhs > maxy_rhs;
	}

}