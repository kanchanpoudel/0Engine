#include "Utility/resource_manager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"
#include "Graphics/raw_images.h"
#include "Debugger/logger.h"
#include <assert.h>

namespace s00nya
{

	bool Resources::instanced = false;

	Resources::Resources()
	{
		assert(!instanced);
		instanced = true;
	}

	bool Resources::LoadRawImage(const Character* path, const Character* name)
	{
		RawImage newImage;
		newImage.m_data = stbi_load(path, &newImage.m_width, &newImage.m_height, &newImage.m_channels, 0);
		if (!newImage.m_data)
		{
			Debug::Add("Image " + std::string(path) + " failed loading", Debug::S00NYA_LOG_WARNING);
			return false;
		}
		m_rawImages[std::string(name)] = newImage;
		return true;
	}

	void Resources::FreeRawImage(const Character* name)
	{
		std::string namestr(name);
		stbi_image_free(m_rawImages[namestr].m_data);
		m_rawImages.erase(namestr);
	}

	const RawImage& Resources::GetRawImage(const Character* name)
	{
		return m_rawImages[std::string(name)];
	}

}