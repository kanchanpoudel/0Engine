#pragma once
#include "s00nya_defs.h"
#include "Math/matrix4.h"
#include "Math/vector2.h"
#include "Math/vector3.h"

namespace s00nya
{

	class Renderer;

	class S00NYA_API Camera
	{
	public:
		Vector2 position;
		Float rotation;
		Vector2 scale;

		Camera();
		Camera(const Vector2& pos, const Float& rot = 0.0f, const Vector2& sca = { 1.0f, 1.0f });

	private:
		Matrix4 GetModalMatrix() const;

		friend class Renderer;
	};

}