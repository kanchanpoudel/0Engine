#include "Graphics/renderer.h"
#include "Graphics/sprite_2d.h"
#include "Debugger/logger.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Graphics/vertex.h"

namespace s00nya
{

	Renderer::Renderer(const Integer& frameWidth, const Integer& frameHeight, const Integer& displayWidth, const Integer& displayHeight) :
		m_frameWidth(frameWidth),
		m_frameHeight(frameHeight),
		m_displayWidth(displayWidth),
		m_displayHeight(displayHeight),
		m_vertexBufferObject2D(), 
		m_activeShader(nullptr)
	{
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glGenFramebuffers(1, &m_frameBuffer);
		glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);

		glGenTextures(1, &m_frameColorBuffer);
		glBindTexture(GL_TEXTURE_2D, m_frameColorBuffer);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_frameWidth, m_frameHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_frameColorBuffer, 0);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			Debug::Add("FrameBuffer not Complete", Debug::S00NYA_LOG_WARNING);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Initialize(const Scene& scene, const Shader* shader)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
		glViewport(0, 0, m_frameWidth, m_frameHeight);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		m_activeShader = (Shader*)shader;

		m_vertexBufferObject2D.Bind();

		shader->Bind();
		shader->SetMatrix4("view", scene.camera.GetModalMatrix());
		shader->SetMatrix4("projection", scene.m_projectionMatrix);

		glClear(GL_COLOR_BUFFER_BIT);
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

	void Renderer::Display(const Shader* shader, const SpriteSheet& spriteSheet) const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glViewport(0, 0, m_displayWidth, m_displayHeight);

		shader->Bind();
		shader->SetTexture2D("textureMap", 0);

		shader->SetSwitches("greyscale", true);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_frameColorBuffer);

		Vertex2D* data = (Vertex2D*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		(data + 0)->position = Vector3(-1.0f, -1.0f, 0.0f);
		(data + 1)->position = Vector3( 1.0f, -1.0f, 0.0f);
		(data + 2)->position = Vector3( 1.0f,  1.0f, 0.0f);
		(data + 3)->position = Vector3(-1.0f,  1.0f, 0.0f);
		(data + 0)->textureCoords = Vector2(0.0f, 0.0f);
		(data + 1)->textureCoords = Vector2(1.0f, 0.0f);
		(data + 2)->textureCoords = Vector2(1.0f, 1.0f);
		(data + 3)->textureCoords = Vector2(0.0f, 1.0f);
		glUnmapBuffer(GL_ARRAY_BUFFER);

		glClear(GL_COLOR_BUFFER_BIT);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

}