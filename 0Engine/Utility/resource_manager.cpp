#include "Utility/resource_manager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"
#include "Debugger/logger.h"
#include "GL/glew.h"
#include <fstream>
#include <sstream>
#include <assert.h>

#include <iostream>

namespace s00nya
{

	Boolean Resources::instanced = false;

	Resources::Resources()
	{
		assert(!instanced);
		instanced = true;
	}

	Boolean Resources::LoadRawImage(const Character* path, const Character* name)
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

	void Resources::FreeRawImage(const std::string& name)
	{
		stbi_image_free(m_rawImages[name].m_data);
		m_rawImages.erase(name);
	}

	const RawImage& Resources::GetRawImage(const std::string& name)
	{
		return m_rawImages[name];
	}

	Boolean Resources::LoadSpriteSheet(
		const Character* path, 
		const UInteger& horizontal, 
		const UInteger& vertical,
		const Character* name
	)
	{
		Integer width, height, channels;
		UCharacter* data = stbi_load(path, &width, &height, &channels, 0);
		if (!data)
		{
			Debug::Add("Image " + std::string(path) + " failed loading", Debug::S00NYA_LOG_WARNING);
			return false;
		}

		UInteger texID;
		glGenTextures(1, &texID);
		glBindTexture(GL_TEXTURE_2D, texID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		GLenum format;
		switch (channels)
		{
		case 1: format = GL_RED; break;
		case 3: format = GL_RGB; break;
		case 4: format = GL_RGBA; break;
		default:
			Debug::Add("Image Format not supported!", Debug::S00NYA_LOG_WARNING);
			return false;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		m_spriteSheets[std::string(name)] = SpriteSheet(texID, width, height, horizontal, vertical);
		return true;
	}

	void Resources::FreeSpriteSheet(const std::string& name)
	{
		m_spriteSheets.erase(name);
	}

	const SpriteSheet& Resources::GetSpriteSheet(const std::string& name)
	{
		return m_spriteSheets[name];
	}

}