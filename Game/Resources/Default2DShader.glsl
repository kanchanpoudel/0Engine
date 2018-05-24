@Vertex Shader

#version 420 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec2 vTexCoords;

out vec2 fTexCoords;

uniform mat4 modal;
uniform mat4 view;
uniform mat4 projection;

int main()
{
	gl_Position = projection * view * modal * vec4(vPosition, 1.0f);
	fTexCoords = vTexCoords;
}

@fragment Shader

#version 420 core

out vec4 fColor;
in vec2 fTexCoords;

uniform sampler2D diffuse;

int main()
{
	fColor = texture(diffuse, fTexCoords);
}