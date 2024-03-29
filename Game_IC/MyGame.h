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

	void GenerateCoin();
	void CheckCollisions();
	bool CollideWithCoinAt(int x, int y) const;


	virtual void OnUpdate() override;


	void DrawDigitCounter(int x, int y, int score); //draws scoreboard


	

private:
	egg::Picture mCoin{ "../Assets/Pictures/coin.png" };
	std::vector<Coin> mCoins;
	egg::Picture mBackground{ "../Assets/Pictures/bg5.png" };
	std::vector<egg::Picture> mRobot; //character unit (vector of pictures)


	enum class Direction { Up = 0, Left = 1, Down = 2, Right = 3 } mDirection;
	enum class State { Stop, Move } mState;
	float mSpeed = 15.0f;
	//std::chrono::high_resolution_clock::time_point mLastCoinTime;

	int mFrameCounter = 0;

	//coords of robot
	int mXPos{ 0 };
	int mYPos{ 0 };

	int mScore{ 0 }; //keeps track of score
	std::vector<egg::Picture> mDigitImages; // PNG images of digits





};