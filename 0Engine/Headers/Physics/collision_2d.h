#pragma once
#include "s00nya_defs.h"
#include "GameObject/scene_2d.h"
#include "GameObject/game_object_2d.h"
#include <vector>

namespace s00nya
{

	class Collision2D
	{
	public:
		static void CollisionResolution(const std::vector<GameObject2D*> gameObjects2D);
	private:
		static Boolean DimensionCollisionDetection(const GameObject2D& lhs, const GameObject2D& rhs);
		static void DimensionCollisionDetectionResolution(const GameObject2D& lhs, const GameObject2D& rhs);
	};

}