#include"pch.h"
#include "EggApp.h"
#include "Utilities.h"
#include "Egg.h"
#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"

namespace egg
{
	template<typename T>
	EggApp<T>::EggApp()
	{
		mWindow.Create("Game_IC", 1000, 800);

		mRenderer.Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	template<typename T>
	void EggApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T;
	}

	template<typename T>
	void EggApp<T>::RunInterface()
	{
		sInstance->Run();
	}

	template<typename T>
	void EggApp<T>::Run()
	{
		egg::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue)
		{
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}
	

	template<typename T>
	void EggApp<T>::OnUpdate()
	{
	}


	template<typename T>
	void EggApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void EggApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}


	template<typename T>
	void EggApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}


	template<typename T>
	void EggApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}


	template<typename T>
	void EggApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}

	template<typename T>
	void EggApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}

	template<typename T>
	int EggApp<T>::GetWidth() {
		return mWindow.GetWidth();
	}

	template<typename T>
	int EggApp<T>::GetHeight() {
		return mWindow.GetHeight();
	}

}