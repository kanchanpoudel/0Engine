#include "Graphics/raw_images.h"

namespace s00nya
{

	const UCharacter* RawImage::Data() const
	{
		return m_data;
	}

	const Integer& RawImage::Width() const
	{
		return m_width;
	}

	const Integer& RawImage::Height() const
	{
		return m_height;
	}

	const Integer& RawImage::Channels() const
	{
		return m_channels;
	}

}