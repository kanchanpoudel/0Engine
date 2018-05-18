#pragma once
#include "Math\vector3.h"

namespace s00nya {

	class Gameobject {

		Vector3 position;
		Vector3 scale;
		float rotation;

		Gameobject();
		Gameobject(Vector3, Vector3,float);

	};
}