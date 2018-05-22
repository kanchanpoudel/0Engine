#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	struct S00NYA_API Material
	{
		UInteger albedo;
		UInteger normal;
		UInteger height;
		UInteger metallic;
		Float smoothness;
		bool emission;

		Material();

		// TO-DO : Other methods required
	};

}