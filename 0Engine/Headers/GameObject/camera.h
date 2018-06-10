#pragma once
#include "s00nya_defs.h"
#include "Math/matrix4.h"
#include "Math/vector2.h"
#include "Math/vector3.h"
#include "Math/transform_2d.h"

namespace s00nya
{

	class Renderer;

	class S00NYA_API Camera
	{
	public:
		Transform2D transform;

	private:
		Matrix4 m_projection;

	public:
		Camera();
		Camera(const Transform2D& transform, const Vector4& ltrb, const Vector2& nearFar = Vector2(-1.0f, 1.0f));
		Camera(const Transform2D& transform, const Float& fov, const Float& aspectRatio, const Vector2& nearFar);

		void ChangeCameraProperties(const Vector4& ltrb, const Vector2& nearFar = Vector2(-1.0f, 1.0f));
		void ChangeCameraProperties(const Float& fov, const Float& aspectRatio, const Vector2& nearFar);

		virtual void FixedUpdate();
		virtual void Update();

		friend class Renderer;
	};

}