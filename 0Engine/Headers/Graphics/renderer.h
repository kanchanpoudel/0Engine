#pragma once
#include "s00nya_defs.h"
#include "vertex_buffer_object_2d.h"
#include "Graphics/shader.h"
#include "GameObject/scene_2d.h"
#include "GameObject/game_object_2d.h"
#include "Math/transform_2d.h"

namespace s00nya
{

	class Game2D;
	class Locator;
	class Shader;
	class SpriteSheet;

	class S00NYA_API Renderer
	{
	public:

	private:
		Integer m_frameWidth;
		Integer m_frameHeight;
		Integer m_displayWidth;
		Integer m_displayHeight;
		VertexBufferObject2D m_vertexBufferObject2D;
		Shader* m_activeShader;
		UInteger m_frameBuffer;
		UInteger m_frameColorBuffer;

	private:
		Renderer(const Integer& frameWidth, const Integer& frameHeight, const Integer& displayWidth, const Integer& displayHeight);

	public:
		~Renderer();

	private:
		void Initialize(const Scene& scene, const Shader* shader);
		void Draw(const GameObject2D& renderable, const SpriteSheet& spriteSheet) const;
		void Display(const Shader* shader, const SpriteSheet& spriteSheet) const;

	public:
		void SetClearColor(const Float& r, const Float& g, const Float& b);

		friend class Game2D;
		friend class Locator;
	};

}