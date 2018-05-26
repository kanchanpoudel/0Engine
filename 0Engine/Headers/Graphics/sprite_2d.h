#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Resources;
	class Renderer;

	class SpriteSheet
	{
	private:
		UInteger m_id;
		Float m_spriteWidth;
		Float m_spriteHeight;
		UInteger m_horizontal;
		UInteger m_vertical;
		Float m_rWidth;
		Float m_rHeight;

	private:
		SpriteSheet(const UInteger& texID, const Float& width, const Float& height, const UInteger& horizontal, const UInteger& vertical, const Float& rWidth, const Float& rHeight);

	public:
		SpriteSheet() = default;
		SpriteSheet(const SpriteSheet& spriteSheet) = delete;
		SpriteSheet& operator=(const SpriteSheet& spriteSheet) = default;

	public:
		const Float& Width() const;
		const Float& Height() const;
		Float XPosition(UInteger index) const;
		Float YPosition(UInteger index) const;

		friend class Resources;
		friend class Renderer;
	};

}