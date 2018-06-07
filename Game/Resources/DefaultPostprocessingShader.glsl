@Vertex Shader

#version 420 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec2 vTexCoords;

out vec2 fTexCoords;

void main()
{
	gl_Position = vec4(vPosition, 1.0f);
	fTexCoords = vTexCoords;
}

@Fragment Shader

#version 420 core

layout (location = 0) out vec4 fColor;
in vec2 fTexCoords;

uniform sampler2D textureMap;

uniform bool greyscale;

void main()
{
	vec4 initialColor = texture(textureMap, fTexCoords).rgba;

	if(greyscale)
	{
		float average = 0.2126 * initialColor.r + 0.7152 * initialColor.g + 0.0722 * initialColor.b;
		initialColor.rgb = vec3(average, average, average);
	}

	fColor = initialColor;
}