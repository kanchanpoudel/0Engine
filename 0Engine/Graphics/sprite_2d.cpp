#include "Graphics/sprite_2d.h"

namespace s00nya
{

	SpriteSheet::SpriteSheet(
		const UInteger& texID, 
		const Integer& width,
		const Integer& height,
		const UInteger& horizontal,
		const UInteger& vertical
		):
		m_id(texID), 
		m_spriteWidth(width), m_spriteHeight(height), 
		m_horizontal(horizontal), m_vertical(vertical)
	{
	}

	const Integer& SpriteSheet::Width() const
	{
		return m_spriteWidth;
	}

	const Integer& SpriteSheet::Height() const
	{
		return m_spriteHeight;
	}

	Integer SpriteSheet::Horizontal(UInteger index) const
	{
		while (index > m_horizontal) index %= m_horizontal;
		return index * m_spriteWidth;
	}
	
	Integer SpriteSheet::Vertical(UInteger index) const
	{
		while (index > m_vertical) index %= m_vertical;
		return index * m_spriteHeight;
	}

}