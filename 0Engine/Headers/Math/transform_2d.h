#pragma once
#include "Math/matrix4.h"
#include "Math/vector2.h"
#include "Math/vector3.h"
#include "s00nya_defs.h"

namespace s00nya 
{

	class Renderer;

	struct S00NYA_API Transform2D
	{
		Vector3 position;
		Float rotation;
		Vector2 center;
		Vector2 scale;

		Transform2D();
		Transform2D(const Vector3& pos, const Vector2& sc, const Vector2& center = Vector2(0.0f, 0.0f), const Float& rot = 0.0f);

	private:
		Matrix4 GetModalMatrix() const;

		friend class Renderer;

		// TO-DO : Other methods required
	};

}