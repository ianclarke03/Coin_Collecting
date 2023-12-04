#include"pch.h"
#include "EggApp.h"

namespace egg
{
	template<typename T>
	EggApp<T>::EggApp()
	{
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

		mWindow.Create("Game_IC", 1000, 800);

		while (mShouldContinue)
		{
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}

	template<typename T>
	void EggApp<T>::OnUpdate() //called in main.cpp
	{
	}





}