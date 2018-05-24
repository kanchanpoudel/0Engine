#include "Graphics/renderer.h"
#include "GL/glew.h"

namespace s00nya
{

	Renderer::Renderer() :
		m_vertexBufferObject2D(), m_active(Type::GAME_OBJECT_2D)
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Initialize(const Type& type, const Shader& shader)
	{
		static Shader* lastBind = (Shader*)&shader;

		if (lastBind != &shader)
		{
			lastBind = (Shader*)&shader;
			shader.Bind();
		}

		if (m_active != type)
		{
			m_active = type;
			m_vertexBufferObject2D.Bind();
		}
	}

	void Renderer::Draw(const GameObject2D& renderable) const
	{

	}

}