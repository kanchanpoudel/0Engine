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

uniform sampler2D inTexture;

void main()
{
	fColor = texture(inTexture, fTexCoords).rgba;
	//fColor.a = 1.0f;
}