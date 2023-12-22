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

	
	/*
	// Initialize the positions for each coin
	// Adjust these coordinates based on your desired starting positions
	int coinX1 = 100;
	int coinY1 = 200;

	int coinX2 = 300;
	int coinY2 = 400;

	// Create shared pointers for the coin pictures
	std::shared_ptr<egg::Picture> coinPicture = std::make_shared<egg::Picture>("../Assets/Pictures/coin.png");

	// Create instances of the Coin class with specified positions
	Coin coin1(coinX1, coinY1, coinPicture);
	Coin coin2(coinX2, coinY2, coinPicture);

	// Add the coins to the vector
	mCoins.push_back(coin1);
	mCoins.push_back(coin2);
	*/
	GenerateCoin();
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
		mYPos = std::min(static_cast<float>(GetHeight()) - mRobot[(int)Direction::Up].GetHeight(), mYPos + mSpeed);
	}
}

/////////////////////// MOVING THE ROBOT //////////////////////////////

























/*
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
*/

void MyGame::CheckCollisions()
{

	//auto it = mCoins.begin();
	/*
	while (it != mCoins.end()) {

		Coin& coin = *it;

		if (CollideWithCoinAt(coin.GetXCoinCoord(), coin.GetYCoinCoord())) {
			std::cout << "Collision detected with coin at (" << it->GetXCoinCoord() << ", " << it->GetYCoinCoord() << ")" << std::endl;
			
			it = mCoins.erase(it);
			// Handle collision logic (e.g., increase score)
		}
		else
			++it;
	}
	*/

	for (auto it = mCoins.begin(); it != mCoins.end();) {
		if (CollideWithCoinAt(it->GetXCoinCoord(), it->GetYCoinCoord())) {
			it = mCoins.erase(it);  // Erase and get the iterator to the next element
		}
		else {
			++it;  // Move to the next element
		}
	}
	std::cout << mCoins.size() << std::endl;
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
	/*
	// Get the current time
	auto currentTime = std::chrono::high_resolution_clock::now();

	// Calculate the elapsed time since the last coin generation
	auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - mLastCoinTime).count();
	*/
	//mFrameCounter = 60;
	// Check if enough time has passed (2 seconds)
	if (mFrameCounter == 60)
	{
		// Generate random X and Y coordinates within the window
		int coinX = std::rand() % 1000; // Random X in the range [0, 999]
		int coinY = std::rand() % 800;  // Random Y in the range [0, 799]

		// Load the coin picture (assuming mCoinPicture is a shared pointer)
		std::shared_ptr<egg::Picture> coinPicture = std::make_shared<egg::Picture>("../Assets/Pictures/coin.png");

		// Create a new coin with the determined coordinates and shared pointer to the picture
		mCoins.emplace_back(coinX, coinY, coinPicture);

		// Update the last coin generation time
		//mLastCoinTime = currentTime;
		mFrameCounter = 0;
	}
}


/*
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
*/

bool MyGame::CollideWithCoinAt(int x, int y) const
{
	// Calculate the bounding box of the robot
	int robotLeft = mXPos + 10; //mXPos + mRobot[(int)mDirection].GetWidth() - 10;
	int robotRight = mXPos + mRobot[(int)mDirection].GetWidth() - 10;; // Assuming the robot is 100 pixels wide
	int robotTop = mYPos + 10;
	int robotBottom = mYPos + mRobot[(int)mDirection].GetWidth() - 10;; // Assuming the robot is 100 pixels tall //mYPos + mRobot[(int)mDirection].GetWidth() - 10;

	for (const auto& coin : mCoins)
	{
		// Calculate the bounding box of the coin
		int coinLeft = coin.GetXCoinCoord();
		int coinRight = coin.GetXCoinCoord() + coin.GetPicture()->GetWidth();
		int coinTop = coin.GetYCoinCoord();
		int coinBottom = coin.GetYCoinCoord() + coin.GetPicture()->GetHeight();

		// Debugging output
		std::cout << "Robot: (" << robotLeft << ", " << robotTop << ") to (" << robotRight << ", " << robotBottom << ")" << std::endl;
		std::cout << "Coin: (" << coinLeft << ", " << coinTop << ") to (" << coinRight << ", " << coinBottom << ")" << std::endl;

		if (robotRight > coinLeft && robotLeft < coinRight &&
			robotBottom > coinTop && robotTop < coinBottom)
		{
			return true; // Collision detected
		}
	}

	return false; // No collision
}









void MyGame::OnUpdate()
{
	std::cout << "Robot: (" << mXPos << ", " << mYPos << ")" << std::endl;
	for (const auto& coords : mCoins)
		std::cout << "Coin: (" << coords.GetXCoinCoord() << ", " << coords.GetYCoinCoord() << ")" << std::endl;

	Draw(0, 0, mBackground);
	GenerateCoin();
	for (auto& coords : mCoins)
		Draw(coords.GetXCoinCoord(), coords.GetYCoinCoord(), mCoin);

	UpdateRobotPosition();

	// Draw the robot based on the current direction
	Draw(mXPos, mYPos, mRobot[(int)mDirection]);
	CheckCollisions();

	mFrameCounter++;
	//std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Adjust the delay as needed
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