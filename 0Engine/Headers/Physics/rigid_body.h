#pragma once
#include "s00nya_defs.h"

namespace s00nya
{

	struct RigidBody
	{
		Float mass;
		Float drag;
		Float angularDrag;
		Float gravity;

		RigidBody();

		// TO-DO : Other required methods
	};

}