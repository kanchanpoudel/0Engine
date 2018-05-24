@Vertex Shader
#version 420 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec2 vTextureCoords;
layout (location = 2) in mat4 vModal;

out vec2 fTextureCoords;

void main()
{
	gl_Position = vec4(vPosition, 1.0f);
	fTextureCoords = vTextureCoords;
}

@Fragment Shader
#version 420 core

out vec4 oColor;
in vec2 fTextureCoords;

void main()
{
	oColor = texture(fTextureID, fTextureCoords).rgba;
}