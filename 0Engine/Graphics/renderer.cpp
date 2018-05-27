#include "Graphics/renderer.h"
#include "Graphics/sprite_2d.h"
#include "Debugger/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Graphics/vertex.h"

namespace s00nya
{

	Renderer::Renderer() :
		m_vertexBufferObject2D(), m_active(Type::GAME_OBJECT_2D), m_activeShader(nullptr)
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glGenTextures(1, &m_diffuseTexture);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Initialize(const Scene& scene, const Type& type, const Shader* shader)
	{
		m_activeShader = (Shader*)shader;
		shader->Bind();
		shader->SetMatrix4("view", scene.camera.GetModalMatrix());
		shader->SetMatrix4("projection", scene.m_projectionMatrix);

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
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, spriteSheet.m_id);

		UInteger frame = renderable.material.frame;
		Float x = spriteSheet.XPosition(frame);
		Float y = spriteSheet.YPosition(frame);
		Float offX = spriteSheet.Width();
		Float offY = spriteSheet.Height();

		Vertex2D* data = (Vertex2D*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		(data + 0)->position = Vector3(0.0f, 0.0f, 0.0f);
		(data + 1)->position = Vector3(renderable.dimension.halfWidth * 2.0f, 0.0f, 0.0f);
		(data + 2)->position = Vector3(renderable.dimension.halfWidth * 2.0f, renderable.dimension.halfHeight * 2.0f, 0.0f);
		(data + 3)->position = Vector3(0.0f, renderable.dimension.halfHeight * 2.0f, 0.0f);
		(data + 0)->textureCoords = Vector2(x, y);
		(data + 1)->textureCoords = Vector2(x + offX, y);
		(data + 2)->textureCoords = Vector2(x + offX, y + offY);
		(data + 3)->textureCoords = Vector2(x, y + offY);
		glUnmapBuffer(GL_ARRAY_BUFFER);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

}