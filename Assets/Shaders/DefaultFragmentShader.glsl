#version 330 core

in vec2 TexCoord;
uniform sampler 2D picture;

out vec4 FragColor;

void main()
{
	FragColor = texture(picture, TexCoord);
}