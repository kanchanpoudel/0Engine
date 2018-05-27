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

	Boolean Dimension::Intersect(const Dimension& lhs, const Dimension& rhs)
	{
		return
			(
			(lhs.pivot.x + lhs.halfWidth) >= (rhs.pivot.x - rhs.halfWidth) &&
			((rhs.pivot.x + rhs.halfWidth) > (lhs.pivot.x - lhs.halfWidth))
			) 
			&&
			(
			(lhs.pivot.y + lhs.halfHeight) >= (rhs.pivot.y - rhs.halfHeight) && 
			((rhs.pivot.y + rhs.halfHeight) > (lhs.pivot.y - lhs.halfHeight))
			);
	}

	Boolean Dimension::Intersect(const Dimension& lhs, const Dimension& rhs, Vector2& outMTV)
	{
		if (lhs.pivot.x < rhs.pivot.x)
		{
			if (!(lhs.pivot.x + lhs.halfWidth > rhs.pivot.x - rhs.halfWidth)) return false;
			outMTV.x = lhs.pivot.x + lhs.halfWidth - rhs.pivot.x + rhs.halfWidth;
		}
		else if (lhs.pivot.x > rhs.pivot.x)
		{
			if (!(rhs.pivot.x + rhs.halfWidth > lhs.pivot.x - lhs.halfWidth)) return false;
			outMTV.x = rhs.pivot.x + rhs.halfWidth - lhs.pivot.x + lhs.halfWidth;
		}
		else
			outMTV.x = 0.0f;

		if (lhs.pivot.y < rhs.pivot.y)
		{
			if (!(lhs.pivot.y + lhs.halfHeight > rhs.pivot.y - rhs.halfHeight)) return false;
			outMTV.y = lhs.pivot.y + lhs.halfHeight - rhs.pivot.y + rhs.halfHeight;
		}
		else if (lhs.pivot.y > rhs.pivot.y)
		{
			if (!(rhs.pivot.y + rhs.halfHeight > lhs.pivot.y - lhs.halfHeight)) return false;
			outMTV.y = rhs.pivot.y + rhs.halfHeight- lhs.pivot.y + lhs.halfHeight;
		}
		else
			outMTV.y = 0.0f;

		return true;
	}

	Boolean Dimension::Contains(const Dimension& container, const Dimension& contained)
	{
		return
			(container.pivot.x + container.halfWidth > contained.pivot.x + contained.halfWidth) &&
			(container.pivot.y + container.halfHeight > contained.pivot.y + contained.halfHeight);
	}

}