#include "Physics/collider_2d.h"

namespace s00nya
{

	Collider2D::Collider2D() :
		aabb()
	{
	}

	Collider2D::Collider2D(const Dimension& _aabb, const Character* path):
		aabb(_aabb)
	{
	}

}