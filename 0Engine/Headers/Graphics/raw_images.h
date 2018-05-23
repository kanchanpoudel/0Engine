#pragma once
#include "s00nya_defs.h"

namespace s00nya
{
	
	class Resources;

	struct S00NYA_API RawImage
	{
	private:
		UCharacter* m_data;
		Integer m_width;
		Integer m_height;
		Integer m_channels;

	public:
		RawImage() = default;
		RawImage(const RawImage& image) = delete;
		RawImage& operator=(const RawImage& image) = default;

	public:
		const UCharacter* Data() const;
		const Integer& Width() const;
		const Integer& Height() const;
		const Integer& Channels() const;

		friend class Resources;
	};

}