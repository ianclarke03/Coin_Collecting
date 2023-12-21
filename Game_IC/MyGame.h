#pragma once

#include"Egg.h"

#include<iostream>
#include <memory>




class Coin
{
public:
	Coin(int x, int y, std::shared_ptr<egg::Picture> picture) : mX(x), mY(y), mPicture(picture) {}

	int GetX() const { return mX; }
	int GetY() const { return mY; }
	std::shared_ptr<egg::Picture> GetPicture() const { return mPicture; }

private:
	int mX;
	int mY;
	std::shared_ptr<egg::Picture> mPicture;
};





class MyGame : public egg::EggApp<MyGame>
{
public:

	MyGame();
	void OnKeyPress(const egg::KeyPressed& e);
	void UpdateRobotPosition();
	void OnKeyRelease(const egg::KeyReleased& e);



	//void CheckCollisions(); //defined
	//void PlantPumpkin();
	//bool CollideWithPumpkinAt(int xPum, int yPum) const;

	void GenerateCoin();
	void CheckCollisions();
	bool CollideWithCoinAt(int xPum, int yPum) const;



	virtual void OnUpdate() override
	{
		
		Draw(0, 0, mBackground);
		GenerateCoin();
		for (auto& coords : mCoins)
			Draw(coords.GetX(), coords.GetY(), mCoin); //either mCoin or mCoins idk yet
		//Draw(0, 0, mCoin);
		//Draw(mUnit);
		UpdateRobotPosition();

		// Draw the robot based on the current direction
		Draw(mXPos, mYPos, mRobot[(int)mDirection]);
		//CheckCollisions();

	}


	/*
	voidMyGame::OnUpdate(){ //draws the game
	draw(0,0,mbackground)

	plantPumpkin();

	for(auto&coords : mpumpkins)
		Draw(Coords.first, coords.secomd, mPumpkin);

	UpdateTractorPosition();
	draw(mXPos, mTPos, mTractor[(int)mDirection]);
	checkcollsions();
	mCounter,drawcounter(mscore);
	mFrameCounter++;
}*/

private:
	egg::Picture mCoin{ "../Assets/Pictures/coin.png" };
	//std::vector<egg::Picture> mCoins;
	std::vector<Coin> mCoins;
	egg::Picture mBackground{ "../Assets/Pictures/bg5.png" };
	//egg::Unit mUnit{ "../Assets/Pictures/Robot_right.png" , 200, 400 };
	std::vector<egg::Picture> mRobot; //character unit (vector of pictures)


	enum class Direction { Up = 0, Left = 1, Down = 2, Right = 3 } mDirection;
	enum class State { Stop, Move } mState;
	float mSpeed = 5.0f;
	std::chrono::high_resolution_clock::time_point mLastCoinTime;


	int mXPos{ 0 };
	int mYPos{ 0 };


};





/*
MyGame.h:

class MyGame : public egg::EggApp<MyGame>
{
	public:
		void OnKeyPress(const egg::KeyPressed& e)
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
}

*/