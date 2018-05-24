#include "Math\transform_2d.h"

namespace s00nya 
{

	Transform2D::Transform2D() :
		position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f), rotation(0.0f)
	{
	}

	Transform2D::Transform2D(Vector3 pos, Vector2 sc, Float rot = 0.0f) :
		position(pos), scale(sc), rotation(rot)
	{
	}

	Matrix4 Transform2D::GetModalMatrix() const
	{
		return 
			Matrix4::Scale(Vector3(scale, 0.0f)) * 
			Matrix4::Rotation(rotation, { 0.0f, 0.0f, -1.0f }) * 
			Matrix4::Translation(position);
	}

}