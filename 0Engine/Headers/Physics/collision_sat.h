#pragma once
#include "s00nya_defs.h"
#include <vector>

namespace s00nya
{

	class GameObject2D;

	class S00NYA_API CollisionSAT
	{
	public:
		static void CollsionResolution(const std::vector<GameObject2D*>& objects);
	private:
		static bool DetectCollision(const GameObject2D& lhs, const GameObject2D& rhs);
		static void ResolveCollision(const GameObject2D& lhs, const GameObject2D& rhs);
	};

}