#pragma once
#include "Math\vector3.h"

namespace s00nya 
{

	struct Transform2D 
	{
		Vector3 position;
		float rotation;
		Vector3 scale;

		Transform2D();
		Transform2D(Vector3 pos, Vector3 sc, float rot);
	};

}