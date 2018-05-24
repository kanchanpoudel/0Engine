#pragma once
#include "s00nya_defs.h"
#include "Math/vector3.h"
#include <string>

namespace s00nya
{

	struct S00NYA_API Material
	{
		enum Type : int
		{
			CLAMP_TO_EDGE = 0x812F,
			REPEAT = 0x2901
		};

		UInteger frame;
		Type type;
		Vector3 color;
		std::string diffuse;
		std::string normal;
		std::string height;
		std::string metallic;
		Float smoothness;
		Float colorBlend;
		bool emission;

		Material();

		// TO-DO : Other methods required
	};

}