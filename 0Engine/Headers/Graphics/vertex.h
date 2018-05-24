#pragma once
#include "Graphics/vertex_buffer_object.h"
#include "Math/vector2.h"
#include "Math/vector3.h"

namespace s00nya
{

	struct S00NYA_API Vertex2D
	{
		enum 
		{
			POSITION,
			TEXTURE_COORDS
		};

		Vector3 position;
		Vector2 textureCoords;

		Vertex2D(const Vector3& _position, const Vector2& _textureCoords);
	};

}