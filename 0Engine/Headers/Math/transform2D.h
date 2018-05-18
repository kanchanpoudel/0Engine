#pragma once
#include "Math\vector3.h"

namespace s00nya {

	class Transform2D {

		Vector3 position;
		Vector3 scale;
		float rotation;

		Transform2D();
		Transform2D(Vector3, Vector3, float);

	};
}