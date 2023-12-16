#include"pch.h"
#include"Picture.h"
#include"GLFWCode/OpenGLPicture.h"




egg::Picture::Picture(const std::string& pictureFile)
{
#ifdef EGG_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pictureFile) };
#elif EGG_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pictureFile) };
#elif EGG_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(pictureFile) };
#endif
}

void egg::Picture::Bind()
{
	mImplementation->Bind();
}

int egg::Picture::GetWidth() const
{
	return mImplementation->GetWidth();
}

int egg::Picture::GetHeight() const
{
	return mImplementation->GetHeight();
}
