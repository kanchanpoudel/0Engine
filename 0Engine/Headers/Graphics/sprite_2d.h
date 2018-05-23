#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	class Resources;

	class SpriteSheet
	{
	private:
		UInteger m_id;
		Integer m_spriteWidth;
		Integer m_spriteHeight;
		UInteger m_horizontal;
		UInteger m_vertical;

	private:
		SpriteSheet(const UInteger& texID, const Integer& width, const Integer& height, const UInteger& horizontal, const UInteger& vertical);

	public:
		SpriteSheet() = default;
		SpriteSheet(const SpriteSheet& spriteSheet) = delete;
		SpriteSheet& operator=(const SpriteSheet& spriteSheet) = default;

	public:
		const Integer& Width() const;
		const Integer& Height() const;
		Integer Horizontal(UInteger index) const;
		Integer Vertical(UInteger index) const;

		friend class Resources;
	};

}