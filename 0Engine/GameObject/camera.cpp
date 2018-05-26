#include "GameObject/camera.h"

namespace s00nya
{

	Camera::Camera() :
		position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f)
	{
	}

	Camera::Camera(const Vector2& pos, const Float& rot, const Vector2& sca) :
		position(pos), rotation(rot), scale(sca)
	{
	}

	Matrix4 Camera::GetModalMatrix() const
	{
		return Matrix4::Inverse(
			Matrix4::Scale(Vector3(scale, 1.0f)) * 
			Matrix4::Rotation(rotation, { 0.0f, 0.0f, -1.0f }) *
			Matrix4::Translation(Vector3(position, 0.0f))
		);
	}

}