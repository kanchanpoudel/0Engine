#pragma once
#include "Math/vector2.h"
#include "Math/vector3.h"
#include "s00nya_defs.h"

namespace s00nya 
{

	struct S00NYA_API Transform2D
	{
		Vector3 position;
		Float rotation;
		Vector2 scale;
		Vector2 pivot;

		Transform2D();
		Transform2D(Vector3 pos, Vector2 sc, Float rot);

		// TO-DO : Other methods required
	};

}