#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTC;

out vec2 TexCoord;
uniform vec2i ScreenSize;

void main()
{
	gl_Position = vec4((aPos.x*2.0)/ScreenSize.x - 1, (aPos.y*2.0)/ScreenSize.y - 1, 1.0, 1.0);
	TexCoord = aTC;
}