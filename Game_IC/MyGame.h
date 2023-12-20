#pragma once

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
	//egg::Picture mPic{ "../Assets/Pictures/bxcbiiu1wxa71.png" };
	egg::Unit mUnit{ "../Assets/Pictures/bxcbiiu1wxa71.png" , 200, 400 };

	int x{ 100 };
	int y{ 100 };
};





/*
MyGame.h:

public:
	void updateTractorPosition();
	MyGame();
	void PlantPumpkin();
	void CheckCollisions();
	bool CollideWithPumpkinAt(int xPum, int yPum) const;

private:
	std::vector<bv::Picture> mTractor; //character unit (vector of pictures)
	enum class Direction(Up = 0, Left = 1, Down = 2, Right = 3) mDirection;
	enum class State(Stop, Move) mState;

	int mXPos{ 0 };
	int mYPos{ 0 };

	//maybe add more here like an unmovable object or an enemy
	bv::Picture mBackground{“../Assets/Pictures/Background.png” };
	bv::Picture mPumpkin{“../Assets/Pictures/Pumpkin.png” };  //replaces mUnit

*/