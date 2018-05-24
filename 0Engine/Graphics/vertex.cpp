#include "Graphics/vertex.h"

namespace s00nya
{

	Vertex2D::Vertex2D(
		const Vector3& _position,
		const Vector2& _textureCoords
	) :
		position(_position),
		textureCoords(_textureCoords)
	{
	}

}