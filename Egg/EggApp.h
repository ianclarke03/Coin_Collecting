#pragma once

#include "Utilities.h"
#include"GameWindow.h"

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

		friend typename T;

	private:
		EggApp();

		inline static EggApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };

	};
};


#include"EggApp.cpp"