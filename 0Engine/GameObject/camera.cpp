#include "GameObject/camera.h"

namespace s00nya
{

	Camera::Camera() :
		transform(), m_projection(Matrix4::Orthographic(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f))
	{
	}

	Camera::Camera(const Transform2D& transform, const Vector4& ltrb, const Vector2& nearFar) :
		transform(transform), m_projection(Matrix4::Orthographic(ltrb.x, ltrb.z, ltrb.w, ltrb.y, nearFar.x, nearFar.y))
	{
	}

	Camera::Camera(const Transform2D & transform, const Float & fov, const Float & aspectRatio, const Vector2 & nearFar):
		transform(transform), m_projection(Matrix4::Perspective(fov, aspectRatio, nearFar.x, nearFar.y))
	{
	}

	void Camera::ChangeCameraProperties(const Vector4& ltrb, const Vector2& nearFar)
	{
		m_projection = Matrix4::Orthographic(ltrb.x, ltrb.z, ltrb.w, ltrb.y, nearFar.x, nearFar.y);
	}

	void Camera::ChangeCameraProperties(const Float & fov, const Float & aspectRatio, const Vector2 & nearFar)
	{
		m_projection = Matrix4::Perspective(fov, aspectRatio, nearFar.x, nearFar.y);
	}

	void Camera::FixedUpdate()
	{
	}

	void Camera::Update()
	{
	}

}