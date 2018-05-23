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

		m_spriteSheets[std::string(name)] = SpriteSheet(texID, width, height, horizontal, vertical);
		return true;
	}

	void Resources::FreeSpriteSheet(const Character* name)
	{
		m_spriteSheets.erase(std::string(name));
	}

	const SpriteSheet& Resources::GetSpriteSheet(const Character* name)
	{
		return m_spriteSheets[std::string(name)];
	}

	Boolean Resources::LoadShader(const Character* path, const Character* name)
	{
		std::ifstream file(path, std::ios::in);
		std::stringstream stream;
		stream << file.rdbuf();
		file.close();
		std::string content(stream.str());

		PDUInteger vertexPos = content.find("@Vertex Shader");
		PDUInteger fragmentPos = content.find("@Fragment Shader");
		PDUInteger geometryPos = content.find("@Geometry Shader");
		if (vertexPos == std::string::npos || fragmentPos == std::string::npos)
		{
			Debug::Add("Could not load Shader - " + std::string(path), Debug::S00NYA_LOG_WARNING);
			return false;
		}

		if (geometryPos == std::string::npos)
		{
			std::string vertex(content.substr(vertexPos + 14, fragmentPos - vertexPos - 14));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* fragmentCstr(fragment.c_str());
			m_shaders[std::string(name)] = Shader(vertexCstr, fragmentCstr);
		}
		else
		{
			std::string vertex(content.substr(vertexPos + 14, geometryPos - vertexPos - 14));
			std::string geometry(content.substr(geometryPos + 16, fragmentPos - geometryPos - 16));
			std::string fragment(content.substr(fragmentPos + 16, content.length() - fragmentPos - 16));
			const Character* vertexCstr(vertex.c_str());
			const Character* geometryCstr(geometry.c_str());
			const Character* fragmentCstr(fragment.c_str());
			m_shaders[std::string(name)] = Shader(vertexCstr, fragmentCstr, geometryCstr);
		}
	}

	void Resources::FreeShader(const Character* name)
	{
		m_shaders.erase(std::string(name));
	}

	const Shader& Resources::GetShader(const Character* name)
	{
		return m_shaders[name];
	}

}