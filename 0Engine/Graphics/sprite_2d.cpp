#include "Graphics/sprite_2d.h"

namespace s00nya
{

	SpriteSheet::SpriteSheet(
		const UInteger& texID, 
		const Float& width,
		const Float& height,
		const Float& widthNorm,
		const Float& heightNorm,
		const UInteger& horizontal,
		const UInteger& vertical
		):
		m_id(texID), 
		m_width(width), m_height(height),
		m_spriteWidth(widthNorm), m_spriteHeight(heightNorm), 
		m_horizontal(horizontal), m_vertical(vertical)
	{
	}

	const Float& SpriteSheet::Width() const
	{
		return m_width;
	}

	const Float& SpriteSheet::Height() const
	{
		return m_height;
	}

	const Float& SpriteSheet::WidthNorm() const
	{
		return m_spriteWidth;
	}

	const Float& SpriteSheet::HeightNorm() const
	{
		return m_spriteHeight;
	}

	Float SpriteSheet::XPosition(UInteger index) const
	{
		// Remainder gives the X value in 2D array of the given size and index of 1D array
		// (X value in 2D array) = (Index in 1D array) % (X size of 2D array)
		return (Float)(index % m_horizontal) * m_spriteWidth;
	}
	
	Float SpriteSheet::YPosition(UInteger index) const
	{
		// Quotient gives the Y value in 2D array of the given size and index of 1D array
		// (Y value in 2D array) = (Index in 1D array) / (Y size of 2D array)
		return (Float)(index / m_vertical) * m_spriteHeight;
	}

}