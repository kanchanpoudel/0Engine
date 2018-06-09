#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Resources;
	class Renderer;

	class SpriteSheet
	{
	private:
		UInteger m_id;				// ID to the texture
		Float m_spriteWidth;		// Width of the single sprite in normalized form
		Float m_spriteHeight;		// Height of the single sprite in normalized form
		UInteger m_horizontal;		// NUmber of sprites in X Axis
		UInteger m_vertical;		// Number of sprites in Y Axis

	private:
		SpriteSheet(const UInteger& texID, const Float& width, const Float& height, const UInteger& horizontal, const UInteger& vertical);

	public:
		SpriteSheet() = default;
		SpriteSheet(const SpriteSheet& spriteSheet) = delete;
		SpriteSheet& operator=(const SpriteSheet& spriteSheet) = default;

	public:
		// Returns Width / Height of the sprite in Normalized form
		const Float& Width() const;
		const Float& Height() const;
		
		// Normalized X value of the sprite of the given index origin being the bottom-left
		Float XPosition(UInteger index) const;
		// Normalized Y value of the sprite of the given index origin being the bottom-left
		Float YPosition(UInteger index) const;

		friend class Resources;
		friend class Renderer;
	};

}