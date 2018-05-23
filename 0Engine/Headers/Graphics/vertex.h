#pragma once
#include "Graphics/vertex_buffer_object.h"
#include "Math/vector2.h"
#include "Math/vector3.h"
#include "Math/matrix4.h"

namespace s00nya
{

	struct S00NYA_API Vertex
	{
		enum 
		{
			POSITION,
			TEXTURE_COORDS,
			MODAL
		};

		Vector3 position;
		Vector2 textureCoords;
		Matrix4 modal;

		Vertex(const Vector3& _position, const Vector2& _textureCoords, const Matrix4& _modal);
	};

}