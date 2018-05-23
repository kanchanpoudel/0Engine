#include "Graphics/vertex_buffer_object.h"
#include "Graphics/vertex.h"
#include "GL/glew.h"

namespace s00nya
{

	VertexBufferObject::VertexBufferObject()
	{
		glGenVertexArrays(1, &m_id);
		glGenBuffers(1, &m_bufferID);
		glGenBuffers(1, &m_indexID);

		glBindVertexArray(m_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexID);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * MAX_RENDER_VERTEX, nullptr, GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(UInteger) * MAX_RENDER_VERTEX * 4, nullptr, GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(Vertex::POSITION);
		glEnableVertexAttribArray(Vertex::TEXTURE_COORDS);
		glEnableVertexAttribArray(Vertex::MODAL);

		glVertexAttribPointer(Vertex::POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(0));
		glVertexAttribPointer(Vertex::TEXTURE_COORDS, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::textureCoords)));
		glVertexAttribPointer(Vertex::MODAL, 4 * 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, Vertex::modal)));
	}

	void VertexBufferObject::Bind() const
	{
		glBindVertexArray(m_id);
	}

	VertexBufferObject::~VertexBufferObject()
	{
		glDeleteBuffers(1, &m_bufferID);
		glDeleteBuffers(1, &m_indexID);
		glDeleteVertexArrays(1, &m_id);
	}

}