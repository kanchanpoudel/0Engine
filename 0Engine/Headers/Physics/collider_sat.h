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
		float width, height;

		Collider2D(float w, float h) :
			width(w),height(h)
	{

	}

	public:
		Collider2D();
		// TO-DO : Other methods required
	};

}