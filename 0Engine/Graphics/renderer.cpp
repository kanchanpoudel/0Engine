#include "Graphics/renderer.h"
#include "Graphics/sprite_2d.h"
#include "GL/glew.h"

namespace s00nya
{

	Renderer::Renderer() :
		m_vertexBufferObject2D(), m_active(Type::GAME_OBJECT_2D), m_activeShader(nullptr)
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glGenTextures(1, &m_diffuseTexture);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Initialize(const Scene& scene, const Type& type, const Shader& shader)
	{
		m_activeShader = (Shader*)&shader;
		shader.Bind();
		shader.SetMatrix4("view", &scene.camera.GetModalMatrix().elements[0]);
		shader.SetMatrix4("projection", &scene.m_projectionMatrix.elements[0]);

		if (m_active != type)
		{
			m_active = type;
			m_vertexBufferObject2D.Bind();
		}
	}

	void Renderer::Draw(const GameObject2D& renderable, const SpriteSheet& spriteSheet) const
	{
		m_activeShader->SetMatrix4("modal", renderable.transform.GetModalMatrix());
		m_activeShader->SetTexture2D("diffuse", 0);
		
		glBindTexture(GL_READ_BUFFER, spriteSheet.m_id);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_diffuseTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, renderable.material.type);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, renderable.material.type);
		UInteger frame = renderable.material.frame;
		glCopyTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			spriteSheet.Horizontal(frame),
			spriteSheet.Vertical(frame),
			spriteSheet.Width(),
			spriteSheet.Height(),
			0
		);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

}