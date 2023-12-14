#pragma once

#include "Utilities.h"
#include"GameWindow.h"
/*
#include"Renderer.h"
#include"Picture.h"
*/

namespace egg
{
	template<typename T>
	class EggApp
	{
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		void Draw(int x, int y, Picture& pic);

		friend typename T;

	private:
		EggApp();

		inline static EggApp* sInstance{ nullptr };

		GameWindow mWindow;

		Renderer mRenderer;

		bool mShouldContinue{ true };

	};
};


#include"EggApp.cpp"