#include "Physics/collision_sat.h"
#include "Physics/collider_sat.h"
#include "GameObject/game_object_2d.h"
#include <iostream>

namespace s00nya
{
	void minmax(Vector2& min, Vector2& max, Vector2 *point)
	{
		min = max = point[0];
		for (int i = 1; i < 4; i++) {
			if (min.x > point[i].x) min.x = point[i].x;
			if (max.x > point[i].x) max.x = point[i].x;
			if (min.y > point[i].y) min.y = point[i].y;
			if (max.y > point[i].y) max.y = point[i].y;
		}
	}

	void CollisionSAT::CollsionResolution(const std::vector<GameObject2D*>& objects)
	{
		// TO-DO : Collision Detector and Resolution loop
		if (!DetectCollision(*objects[0], *objects[1]))
			std::cout << "Collides" << std::endl;
	}
	
	bool CollisionSAT::DetectCollision(const GameObject2D& lhs, const GameObject2D& rhs)
	{
		//for rectangle objects
		float th1 = atan(lhs.collider.height / lhs.collider.width);
		float th2 = atan(rhs.collider.height / rhs.collider.width);

		float diagonal1 = sqrt(lhs.collider.width*lhs.collider.width + lhs.collider.height*lhs.collider.height);
		float diagonal2 = sqrt(rhs.collider.width*rhs.collider.width + rhs.collider.height*rhs.collider.height);

		Vector2 min1, min2, max1, max2;


		Vector2 pointl[4];
		pointl[0] = Vector2(lhs.transform.position.x, lhs.transform.position.y);
		pointl[1] = Vector2(lhs.transform.position.x+lhs.collider.width*cos(lhs.transform.rotation), lhs.transform.position.y+ lhs.collider.width*sin(lhs.transform.rotation));
		pointl[2] = Vector2(lhs.transform.position.x - lhs.collider.height*sin(lhs.transform.rotation), lhs.transform.position.y + lhs.collider.height*cos(lhs.transform.rotation));
		pointl[3] = Vector2(lhs.transform.position.x + diagonal1*cos(lhs.transform.rotation+th1), lhs.transform.position.y + diagonal1*sin(lhs.transform.rotation+th1));

		Vector2 pointr[4];
		pointr[0] = Vector2(rhs.transform.position.x, rhs.transform.position.y);
		pointr[1] = Vector2(rhs.transform.position.x + rhs.collider.width*cos(rhs.transform.rotation), rhs.transform.position.y + rhs.collider.width*sin(rhs.transform.rotation));
		pointr[2] = Vector2(rhs.transform.position.x - rhs.collider.height*sin(rhs.transform.rotation), rhs.transform.position.y + rhs.collider.height*cos(rhs.transform.rotation));
		pointr[3] = Vector2(rhs.transform.position.x + diagonal2 * cos(rhs.transform.rotation + th2), rhs.transform.position.y + diagonal2 * sin(rhs.transform.rotation + th2));

		minmax(min1, max1, pointl);
		minmax(min2, max2, pointr);

		return ((min1.x < min2.x && max1.x < min2.x) || (min1.x > max2.x && max1.x > max2.x) && (min1.y < min2.y && max1.y < min2.y) || (min1.y > max2.y && max1.y > max2.y));
	}

	void CollisionSAT::ResolveCollision(const GameObject2D& lhs, const GameObject2D& rhs)
	{
		// TO-DO : 2 objects collision resolution
	}

}