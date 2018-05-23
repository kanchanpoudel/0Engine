#include "Graphics/vertex.h"

namespace s00nya
{

	Vertex::Vertex(
		const Vector3& _position,
		const Vector2& _textureCoords,
		const Matrix4& _modal
	) :
		position(_position),
		textureCoords(_textureCoords),
		modal(_modal)
	{
	}

}