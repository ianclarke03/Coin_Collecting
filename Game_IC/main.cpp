#include"Egg.h"

#include<iostream>

class MyGame : public egg::EggApp<MyGame>
{
public:

	MyGame()
	{
		SetKeyPressedCallback([this](const egg::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override
	{
		//std::cout << "Egg running" << std::endl;

		Draw(x, y, mPic);
	}

	void OnKeyPress(const egg::KeyPressed& e)
	{
		if (e.GetKeyCode() == EGG_KEY_RIGHT)
			x += 50;
		else if (e.GetKeyCode() == BEAVER_KEY_LEFT)
			x -= 50;
	}

private:
	egg::Picture mPic{ "../Assets/Pictures/test.png" };

	int x{ 100 };
	int y{ 100 };
};

EGG_APPLICATION_START(MyGame);