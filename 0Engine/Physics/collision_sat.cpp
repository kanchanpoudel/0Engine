#include "Physics/collision_sat.h"
#include "Physics/collider_sat.h"
#include "GameObject/game_object_2d.h"

namespace s00nya
{

	void CollisionSAT::CollsionResolution(const std::vector<GameObject2D>& objects)
	{
		// TO-DO : Collision Detector and Resolution loop
	}
	
	bool CollisionSAT::DetectCollision(const GameObject2D& lhs, const GameObject2D& rhs)
	{
		// TO-DO : 2 objects collision detection
		return false;
	}

	void CollisionSAT::ResolveCollision(const GameObject2D& lhs, const GameObject2D& rhs)
	{
		// TO-DO : 2 objects collision resolution
	}

}