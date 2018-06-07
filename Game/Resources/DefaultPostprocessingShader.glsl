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

uniform bool greyscale_switch;

uniform bool filterSlot0_switch;
uniform bool filterSlot1_switch;
uniform bool filterSlot2_switch;

uniform mat3 filterSlot0;
uniform mat3 filterSlot1;
uniform mat3 filterSlot2;

const float offset = 1.0f / 300.0f;

void main()
{
	vec4 initialColor = texture(textureMap, fTexCoords).rgba;

	vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // top-left
        vec2( 0.0f,    offset), // top-center
        vec2( offset,  offset), // top-right
        vec2(-offset,  0.0f),   // center-left
        vec2( 0.0f,    0.0f),   // center-center
        vec2( offset,  0.0f),   // center-right
        vec2(-offset, -offset), // bottom-left
        vec2( 0.0f,   -offset), // bottom-center
        vec2( offset, -offset)  // bottom-right    
    );

	vec3 sampleTextures[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTextures[i] = vec3(texture(textureMap, fTexCoords.st + offsets[i]));
    }

	if(filterSlot0_switch)
	{
		vec3 color = vec3(0.0);
		for(int i = 0; i < 9; i++)
			color += sampleTextures[i] * filterSlot0[i];
		initialColor.rgb = color;
	}

	if(filterSlot1_switch)
	{
		vec3 color = vec3(0.0);
		for(int i = 0; i < 9; i++)
			color += sampleTextures[i] * filterSlot1[i];
		initialColor.rgb = color;
	}

	if(filterSlot2_switch)
	{
		vec3 color = vec3(0.0);
		for(int i = 0; i < 9; i++)
			color += sampleTextures[i] * filterSlot2[i];
		initialColor.rgb = color;
	}

	if(greyscale_switch)
	{
		float average = 0.2126 * initialColor.r + 0.7152 * initialColor.g + 0.0722 * initialColor.b;
		initialColor.rgb = vec3(average, average, average);
	}

	fColor = initialColor;
}