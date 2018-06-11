#include "Math\transform_2d.h"

namespace s00nya 
{

	Transform2D::Transform2D() :
		position(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f), center(0.0f, 0.0f), rotation(0.0f)
	{
	}

	Transform2D::Transform2D(
		const Vector3& pos, 
		const Vector2& sc, 
		const Vector2& center, 
		const Float& rot
	) :
		position(pos), scale(sc), rotation(rot)
	{
	}

	Matrix4 Transform2D::GetModalMatrix() const
	{
		return 
			Matrix4::Scale(Vector3(scale, 1.0f)) * 
			Matrix4::Rotation(rotation, { 0.0f, 0.0f, -1.0f }) * 
			Matrix4::Translation(position);
	}

}