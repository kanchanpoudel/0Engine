#include "Graphics/vertex_buffer_object_2d.h"
#include "Graphics/vertex.h"
#include "GL/glew.h"
#include <vector>

namespace s00nya
{

	VertexBufferObject2D::VertexBufferObject2D() :
		VertexBufferObject()
	{
		std::vector<Vertex2D> vertices
		{
			{ Vector3(0.0f, 0.0f, 0.0f), Vector2(0.0f, 0.0f) },
			{ Vector3(1.0f, 0.0f, 0.0f), Vector2(1.0f, 0.0f) },
			{ Vector3(1.0f, 1.0f, 0.0f), Vector2(1.0f, 1.0f) },
			{ Vector3(0.0f, 1.0f, 0.0f), Vector2(0.0f, 1.0f) }
		};

		UInteger indices[]
		{
			0, 1, 2,
			2, 3, 0
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2D) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(UInteger) * 6, indices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(Vertex2D::POSITION);
		glEnableVertexAttribArray(Vertex2D::TEXTURE_COORDS);

		glVertexAttribPointer(Vertex2D::POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, Vertex2D::position));
		glVertexAttribPointer(Vertex2D::TEXTURE_COORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, Vertex2D::textureCoords));
	}

	VertexBufferObject2D::~VertexBufferObject2D()
	{
	}

}