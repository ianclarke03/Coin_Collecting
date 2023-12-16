#pragma once

#include"PictureImplementation.h"

namespace egg
{
	class OpenGLPicture : public PictureImplementation
	{
	public:

		//found here and implmented in OpenGlPicture.cpp
		OpenGLPicture(const std::string& pictureFile);
		OpenGLPicture(std::string&& pictureFile);
		~OpenGLPicture();


		// implmented in OpenGlPicture.cpp
		void Bind() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

	private:
		int width;
		int height;
		unsigned int texture;
		//unsigned int mShaderProgram; //maybe used in OpenGLPicture.cpp similar to shader (gl funcs used that need this)
	};
}