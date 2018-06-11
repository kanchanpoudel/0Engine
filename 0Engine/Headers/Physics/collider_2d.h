#pragma once
#include "s00nya_defs.h"
#include "Math/dimension.h"
#include "Math/vector2.h"
#include <vector>

namespace s00nya
{

	class Collision2D;

	class S00NYA_API Collider2D
	{
	private:
		Dimension aabb;
		std::vector<Vector2> m_vertices;
	
	public:
		Collider2D();
		Collider2D(const Dimension& _aabb, const Character* path);

		friend class Collision2D;
	};

}