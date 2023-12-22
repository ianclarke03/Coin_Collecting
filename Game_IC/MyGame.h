#pragma once

#include"Egg.h"

#include<iostream>
#include <memory>




class Coin
{
public:
	Coin(int x, int y, std::shared_ptr<egg::Picture> picture) : mXCoinCoord(x), mYCoinCoord(y), mPicture(picture) {}

	int GetXCoinCoord() const { return mXCoinCoord; }
	int GetYCoinCoord() const { return mYCoinCoord; }
	std::shared_ptr<egg::Picture> GetPicture() const { return mPicture; }

private:
	int mXCoinCoord;
	int mYCoinCoord;
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
	bool CollideWithCoinAt(int x, int y) const;


	virtual void OnUpdate() override;


	

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

	int mFrameCounter = 0;


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