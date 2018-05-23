#pragma once
#include "s00nya_defs.h"
#include "Graphics/raw_images.h"
#include <map>
#include <string>

namespace s00nya
{

	class Locator;

	class S00NYA_API Resources
	{
	private:
		std::map<std::string, RawImage> m_rawImages;

	private:
		static bool instanced;

		Resources();
		Resources(const Resources& resources) = delete;
		Resources& operator=(const Resources& resources) = delete;

	public:
		bool LoadRawImage(const Character* path, const Character* name);
		void FreeRawImage(const Character* name);
		const RawImage& GetRawImage(const Character* name);

		friend class Locator;
	};

}