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
	void EggApp<T>::Run() // void EggApp::Run()
	{

		while (mShouldContinue)
		{
			OnUpdate();
		}
	}

	template<typename T>
	void EggApp<T>::OnUpdate()
	{
	}





}