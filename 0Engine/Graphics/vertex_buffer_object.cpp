#include "Graphics/vertex_buffer_object.h"
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