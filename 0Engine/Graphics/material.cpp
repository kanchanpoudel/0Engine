#include "Graphics/material.h"

namespace s00nya
{

	Material::Material():
		frame(0),
		type(Type::CLAMP_TO_EDGE),
		color(0.0f, 0.0f, 0.0f), 
		diffuse(), 
		normal(), 
		height(), 
		metallic(), 
		smoothness(0.0f),
		colorBlend(0.0f),
		emission(false)
	{
	}

}