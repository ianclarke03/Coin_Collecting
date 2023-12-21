#include "MyGame.h"

MyGame::MyGame()//implement in MyGame.cpp
{
	SetKeyPressedCallback([this](const egg::KeyPressed& e) {OnKeyPress(e); });

	mRobot.emplace_back("../Assets/Pictures/Robot_up.png");
	mRobot.emplace_back("../Assets/Pictures/Robot_left.png");
	mRobot.emplace_back("../Assets/Pictures/Robot_down.png");
	mRobot.emplace_back("../Assets/Pictures/Robot_right.png");


	mDirection = Direction::Right;
	mState = State::Stop;
	mLastCoinTime = std::chrono::high_resolution_clock::now();
}


/////////////////////// MOVING THE ROBOT //////////////////////////////

void MyGame::OnKeyPress(const egg::KeyPressed& e) {
	if (e.GetKeyCode() == EGG_KEY_RIGHT)
	{
		mDirection = Direction::Right;
		mState = State::Move;
	}

	else if (e.GetKeyCode() == EGG_KEY_LEFT)
	{
		mDirection = Direction::Left;
		mState = State::Move;
	}
	else if (e.GetKeyCode() == EGG_KEY_UP)
	{
		mDirection = Direction::Up;
		mState = State::Move;
	}
	else if (e.GetKeyCode() == EGG_KEY_DOWN)
	{
		mDirection = Direction::Down;
		mState = State::Move;
	}
}


void MyGame::OnKeyRelease(const egg::KeyReleased& e)
{
	if (e.GetKeyCode() == EGG_KEY_RIGHT && mDirection == Direction::Right)
	{
		mState = State::Stop;
	}
	else if (e.GetKeyCode() == EGG_KEY_LEFT && mDirection == Direction::Left)
	{
		mState = State::Stop;
	}
	else if (e.GetKeyCode() == EGG_KEY_UP && mDirection == Direction::Up)
	{
		mState = State::Stop;
	}
	else if (e.GetKeyCode() == EGG_KEY_DOWN && mDirection == Direction::Down)
	{
		mState = State::Stop;
	}
}



void MyGame::UpdateRobotPosition()
{
	if (mState != State::Move) {
		return;
	}

	if (mDirection == Direction::Right) {
		mXPos = std::min(static_cast<float>(GetWidth()) - mRobot[(int)Direction::Right].GetWidth(), mXPos + mSpeed);
	}
	else if (mDirection == Direction::Left) {
		mXPos = std::max(0.0f, mXPos - mSpeed);
	}
	else if (mDirection == Direction::Down) {
		mYPos = std::max(0.0f, mYPos - mSpeed);
	}
	else if (mDirection == Direction::Up) {
		mYPos = std::min(static_cast<float>(GetHeight()) - mRobot[(int)Direction::Down].GetHeight(), mYPos + mSpeed);
	}
}

/////////////////////// MOVING THE ROBOT //////////////////////////////


























void MyGame::CheckCollisions()
{
	auto it = mCoins.begin();
	while (it != mCoins.end()) {
		if (CollideWithCoinAt(it->GetX(), it->GetY())) {
			it = mCoins.erase(it);
			//mScore++;
		}
		else
			it++;
	}
}



void MyGame::GenerateCoin()
{
	// Seed the random number generator (call this once in your program)
	static bool srandInitialized = false;
	if (!srandInitialized)
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		srandInitialized = true;
	}

	// Get the current time
	auto currentTime = std::chrono::high_resolution_clock::now();

	// Calculate the elapsed time since the last coin generation
	auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - mLastCoinTime).count();

	// Check if enough time has passed (2 seconds)
	if (elapsedTime >= 2)
	{
		// Generate random X and Y coordinates within the window
		int coinX = std::rand() % 1000; // Random X in the range [0, 999]
		int coinY = std::rand() % 800;  // Random Y in the range [0, 799]

		// Load the coin picture (assuming mCoinPicture is a shared pointer)
		std::shared_ptr<egg::Picture> coinPicture = std::make_shared<egg::Picture>("../Assets/Pictures/coin.png");

		// Create a new coin with the determined coordinates and shared pointer to the picture
		mCoins.emplace_back(coinX, coinY, coinPicture);

		// Update the last coin generation time
		mLastCoinTime = currentTime;
	}
}



bool MyGame::CollideWithCoinAt(int x, int y) const
{
	for (const auto& coin : mCoins)
	{
		// Check if the provided position collides with the coin's position
		if (x >= coin.GetX() && x <= coin.GetX() + coin.GetPicture()->GetWidth() &&
			y >= coin.GetY() && y <= coin.GetY() + coin.GetPicture()->GetHeight())
		{
			return true; // Collision detected
		}
	}
	return false; // No collision
}








/*
MyGame.cpp:

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
}





void MyGame::CheckCollisions()
{
auto it = mPumpkins.begin();
while(it != mPumpkins.end()){
	if(CollideWithPumpkinAt(it->first, it->second)){
		it = mPumpkins.erase(it);
		mScore++;
		}
	else
		it++;
	}
}
*/