#include "Graphics/sprite_2d.h"

namespace s00nya
{

	SpriteSheet::SpriteSheet(
		const UInteger& texID, 
		const Float& width,
		const Float& height,
		const UInteger& horizontal,
		const UInteger& vertical
		):
		m_id(texID), 
		m_spriteWidth(width), m_spriteHeight(height), 
		m_horizontal(horizontal), m_vertical(vertical)
	{
	}

	const Float& SpriteSheet::Width() const
	{
		return m_spriteWidth;
	}

	const Float& SpriteSheet::Height() const
	{
		return m_spriteHeight;
	}

	Float SpriteSheet::XPosition(UInteger index) const
	{
		return (Float)(index % m_horizontal) * m_spriteWidth;
	}
	
	Float SpriteSheet::YPosition(UInteger index) const
	{
		return (Float)(index / m_vertical) * m_spriteHeight;
	}

}