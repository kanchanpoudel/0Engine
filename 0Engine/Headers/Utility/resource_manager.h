#pragma once
#include "s00nya_defs.h"
#include "Graphics/raw_images.h"
#include "Graphics/sprite_2d.h"
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

	private:
		static Boolean instanced;	// Allow this class to be instanced only once

		Resources();
		Resources(const Resources& resources) = delete;
		Resources& operator=(const Resources& resources) = delete;

	public:
		Boolean LoadRawImage(const Character* path, const Character* name);
		void FreeRawImage(const std::string& name);
		const RawImage& GetRawImage(const std::string& name);

		Boolean LoadSpriteSheet(const Character* path, const UInteger& horizontal, const UInteger& vertical, const Character* name);
		void FreeSpriteSheet(const std::string& name);
		const SpriteSheet& GetSpriteSheet(const std::string& name);

		friend class Locator;
	};

}