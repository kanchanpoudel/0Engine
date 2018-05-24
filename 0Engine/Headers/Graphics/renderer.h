#pragma once
#include "s00nya_defs.h"
#include "vertex_buffer_object_2d.h"
#include "Graphics/shader.h"
#include "GameObject/game_object_2d.h"

namespace s00nya
{

	class Locator;

	class S00NYA_API Renderer
	{
	public:
		enum class Type : UInteger
		{
			GAME_OBJECT_2D,
			LINES
		};

	private:
		VertexBufferObject2D m_vertexBufferObject2D;
		Type m_active;

	private:
		Renderer();

	public:
		~Renderer();

		void Initialize(const Type& type, const Shader& shader);
		void Draw(const GameObject2D& renderable) const;

		friend class Locator;
	};

}