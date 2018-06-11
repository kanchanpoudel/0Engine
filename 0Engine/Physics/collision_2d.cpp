#include "Physics/collision_2d.h"
#include <iostream>
#include "Math/dimension.h"

namespace s00nya
{

	void Collision2D::CollisionResolution(const std::vector<GameObject2D*>& objects)
	{
		for (Integer i(0); i < objects.size(); i++)
		{
			for (Integer j(0); j < objects.size(); j++)
			{
				if (objects[i] == objects[j]) break;
				Vector3 objIPos(objects[i]->transform.position);
				Vector3 objJPos(objects[j]->transform.position);
				if (Dimension::Intersect(
					Vector2(objIPos.x, objIPos.y)+ objects[i]->transform.center, objects[i]->collider.aabb,
					Vector2(objJPos.x, objJPos.y)+ objects[j]->transform.center, objects[j]->collider.aabb
				))
					std::cout << " Objects collided! " << std::endl;
			}
		}
	}

}