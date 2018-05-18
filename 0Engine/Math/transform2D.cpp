#include "Math\transform2D.h"

namespace s00nya {

	Transform2D::Transform2D() :
		position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f), rotation(0.0f)
	{
	}

	Transform2D::Transform2D(Vector3 pos, Vector3 sc, float rot = 0.0f) :
		position(pos), scale(sc), rotation(rot)
	{
	}
}