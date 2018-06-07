#pragma once
#include "s00nya_defs.h"
#include "Math/vector2.h"
#include <vector>

namespace s00nya
{

	class S00NYA_API Collider2D
	{
		std::vector<Vector2> m_vertices;
	public:
		Collider2D() = default;
	};

}