#include "Math/dimension.h"

namespace s00nya
{

	Dimension::Dimension() :
		halfWidth(10.0f), halfHeight(10.0f)
	{
	}

	Dimension::Dimension(const Float& _halfWidth, const Float& _halfHeight) :
		halfWidth(_halfWidth), halfHeight(_halfHeight)
	{
	}

	Boolean Dimension::Intersect(const Dimension& lhs, const Dimension& rhs, const Vector2& lhspivot, const Vector2& rhspivot)
	{
		Boolean xcol = (
			(lhspivot.x + lhs.halfWidth) >= (rhspivot.x - rhs.halfWidth) &&
			((rhspivot.x + rhs.halfWidth) >= (lhspivot.x - lhs.halfWidth))
			);
		Boolean ycol = 
			(
			(lhspivot.y + lhs.halfHeight) >= (rhspivot.y - rhs.halfHeight) && 
			((rhspivot.y + rhs.halfHeight) >= (lhspivot.y - lhs.halfHeight))
			);
		return xcol && ycol;
	}

	Boolean Dimension::Intersect(const Dimension& lhs, const Dimension& rhs, const Vector2& lhspivot, const Vector2& rhspivot, Vector2& outMTV)
	{
		if (lhspivot.x < rhspivot.x)
		{
			if (!(lhspivot.x + lhs.halfWidth > rhspivot.x - rhs.halfWidth)) return false;
			outMTV.x = lhspivot.x + lhs.halfWidth - rhspivot.x + rhs.halfWidth;
		}
		else if (lhspivot.x > rhspivot.x)
		{
			if (!(rhspivot.x + rhs.halfWidth > lhspivot.x - lhs.halfWidth)) return false;
			outMTV.x = rhspivot.x + rhs.halfWidth - lhspivot.x + lhs.halfWidth;
		}
		else
			outMTV.x = 0.0f;

		if (lhspivot.y < rhspivot.y)
		{
			if (!(lhspivot.y + lhs.halfHeight > rhspivot.y - rhs.halfHeight)) return false;
			outMTV.y = lhspivot.y + lhs.halfHeight - rhspivot.y + rhs.halfHeight;
		}
		else if (lhspivot.y > rhspivot.y)
		{
			if (!(rhspivot.y + rhs.halfHeight > lhspivot.y - lhs.halfHeight)) return false;
			outMTV.y = rhspivot.y + rhs.halfHeight- lhspivot.y + lhs.halfHeight;
		}
		else
			outMTV.y = 0.0f;

		return true;
	}

	Boolean Dimension::Contains(const Dimension& container, const Dimension& contained, const Vector2& containerpivot, const Vector2& containedpivot)
	{
		return
			(containerpivot.x + container.halfWidth > containedpivot.x + contained.halfWidth) &&
			(containerpivot.y + container.halfHeight > containedpivot.y + contained.halfHeight);
	}

}