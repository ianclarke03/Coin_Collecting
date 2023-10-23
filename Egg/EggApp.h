#pragma once

#include "Utilities.h"

namespace egg
{
	template<typename T>
	class EGG_API EggApp
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

		bool mShouldContinue{ true };

	};
};


#include"EggApp.cpp"