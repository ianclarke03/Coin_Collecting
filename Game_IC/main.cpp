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

		//Draw(x, y, mPic);
		Draw(mUnit);
	}

	void OnKeyPress(const egg::KeyPressed& e)
	{
		if (e.GetKeyCode() == EGG_KEY_RIGHT)
			//x += 50;
			mUnit.UpdateXCoord(50);
		else if (e.GetKeyCode() == EGG_KEY_LEFT)
			//x -= 50;
			mUnit.UpdateXCoord(-50);
	}

private:
	egg::Picture mPic{ "../Assets/Pictures/test.png" };
	egg::Unit mUnit{ "../Assets/Pictures/test.png" , 100, 500 };

	int x{ 100 };
	int y{ 100 };
};

EGG_APPLICATION_START(MyGame);