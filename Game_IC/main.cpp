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
		//new addition by me
		else if (e.GetKeyCode() == EGG_KEY_UP)
			mUnit.UpdateYCoord(50);
		else if (e.GetKeyCode() == EGG_KEY_DOWN)
			mUnit.UpdateYCoord(-50);
	}

private:
	egg::Picture mPic{ "../Assets/Pictures/bxcbiiu1wxa71.png" };
	egg::Unit mUnit{ "../Assets/Pictures/bxcbiiu1wxa71.png" , 200, 400 };

	int x{ 100 };
	int y{ 100 };
};

EGG_APPLICATION_START(MyGame);