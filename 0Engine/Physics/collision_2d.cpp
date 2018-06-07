#include "Physics/collision_2d.h"
#include <iostream>
#include "Math/dimension.h"

namespace s00nya
{

	void Collision2D::CollisionResolution(const std::vector<GameObject2D*> gameObjects2D)
	{
		for (UInteger outer(0); outer<gameObjects2D.size(); outer++)
		{
			for (UInteger inner(0); inner<gameObjects2D.size(); inner++)
			{
				if (gameObjects2D[outer] == gameObjects2D[inner]) break;
				if (DimensionCollisionDetection(*gameObjects2D[outer], *gameObjects2D[inner]))
					std::cout << "Collided!" << std::endl;
			}
		}
	}

	Boolean Collision2D::DimensionCollisionDetection(const GameObject2D& lhs, const GameObject2D& rhs)
	{
		Vector2 temp;
		return Dimension::Intersect(
			lhs.dimension, 
			rhs.dimension, 
			{ lhs.transform.position.x, lhs.transform.position.y },
			{ rhs.transform.position.x, rhs.transform.position.y }
		);
	}

	void Collision2D::DimensionCollisionDetectionResolution(const GameObject2D & lhs, const GameObject2D & rhs)
	{
	}

}