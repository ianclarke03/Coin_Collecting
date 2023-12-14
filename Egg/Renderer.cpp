#include"pch.h"
#include"Renderer.h"
#include"GLFWCode/OpenGLRenderer.h"


egg::Renderer::Renderer()
{
#ifdef EGG_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif EGG_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif EGG_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void egg::Renderer::Init()
{
	mImplementation->Init();
}

void egg::Renderer::Draw(int x, int y, Picture& pic)
{
	mImplementation->Draw(x, y, pic);
}

void egg::Renderer::Clear()
{
	mImplementation->Clear();
}