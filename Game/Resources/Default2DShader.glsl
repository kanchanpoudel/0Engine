@Vertex Shader

#version 420 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec2 vTexCoords;

out vec2 fTexCoords;

uniform mat4 modal;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = vec4(vPosition, 1.0f) * modal * view * projection;
	fTexCoords = vTexCoords;
}

@Fragment Shader

#version 420 core

out vec4 fColor;
in vec2 fTexCoords;

uniform sampler2D diffuse;

void main()
{
	fColor = texture(diffuse, fTexCoords).rgba;
}