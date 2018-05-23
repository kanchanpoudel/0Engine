#pragma once
#include "s00nya_defs.h"
#include "Graphics/raw_images.h"
#include "Graphics/sprite_2d.h"
#include "Graphics/shader.h"
#include <map>
#include <string>

namespace s00nya
{

	class Locator;

	class S00NYA_API Resources
	{
	private:
		std::map<std::string, RawImage> m_rawImages;
		std::map<std::string, SpriteSheet> m_spriteSheets;
		std::map<std::string, Shader> m_shaders;

	private:
		static Boolean instanced;

		Resources();
		Resources(const Resources& resources) = delete;
		Resources& operator=(const Resources& resources) = delete;

	public:
		Boolean LoadRawImage(const Character* path, const Character* name);
		void FreeRawImage(const Character* name);
		const RawImage& GetRawImage(const Character* name);

		Boolean LoadSpriteSheet(const Character* path, const UInteger& horizontal, const UInteger& vertical, const Character* name);
		void FreeSpriteSheet(const Character* name);
		const SpriteSheet& GetSpriteSheet(const Character* name);

		Boolean LoadShader(const Character* path, const Character* name);
		void FreeShader(const Character* name);
		const Shader& GetShader(const Character* name);

		friend class Locator;
	};

}