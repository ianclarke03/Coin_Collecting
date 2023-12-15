#include"pch.h"

#include"OpenGLPicture.h"

#include"../glad/include/glad/glad.h"
#include"../glfw/include/GLFW/glfw3.h"

#include"../Utilities.h"
#include"../stbi/stb_image.h"


namespace egg
{
	OpenGLPicture::OpenGLPicture(const std::string& pictureFile)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		/* //maybe necessary
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(pictureFile.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			EGG_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}



	OpenGLPicture::OpenGLPicture(std::string&& pictureFile)
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		/* //maybe necessary
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(pictureFile.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			EGG_ERROR("Failed to load a picture from the file!!!");
		}
		stbi_image_free(data);
	}



	OpenGLPicture::~OpenGLPicture()
	{
		if (texture)
			glDeleteTextures(1, &texture);
	}



	void OpenGLPicture::Bind()
	{
		glActiveTexture(texture); // activate the texture unit first before binding texture
		glBindTexture(GL_TEXTURE_2D, texture);
	}




	int OpenGLPicture::GetWidth()
	{
		return height;
	}
	int OpenGLPicture::GetHeight()
	{
		return width;
	}
}