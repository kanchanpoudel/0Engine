#pragma once
#include <vector>
#include "s00nya_defs.h"
#include "Math/vector2.h"

namespace s00nya
{

	struct S00NYA_API Collider2D
	{
	private:
		std::vector<Vector2> m_points;
	public:
		bool isTrigger;

	public:
		Collider2D();
		// TO-DO : Other methods required
	};

}