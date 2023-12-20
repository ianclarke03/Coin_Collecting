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



MyGame::MyGame()
{
	SetKeyPressedCallBack(); //SetKeyPressedCallback([this](const egg::KeyPressed& e) {OnKeyPress(e); });

	mTractor.emplace_back(“../Assets/Pictures/tractor_up.png”);
	mTractor.emplace_back(“../Assets/Pictures/tractor_down.png”);
	mTractor.emplace_back(“../Assets/Pictures/tractor_left.png”);
	mTractor.emplace_back(“../Assets/Pictures/tractor_right.png”);

	mDirection = Direction::Right
	mState = State::Stop;
}


void MyGame::UpdateTractorPosition()
{
	if(mState != State::Move){
		return;
	}

	if(mDirection == Direction::Right){
	mXPos = std::min(mGameWindowWidth - mTractor[(int)Direction::Right].Getwidth(), mCPos + mSpeed); //mSpeed special
	}

	else if(mDirection == Direction::Left){
		mXPos = std::max(0, mXPos - mSpeed);
	}

	else if(mDirection == Direction::Up){
	//repeat above for up and down
	}

}




void MyGame:: OnKeyPress(const bc::KeyPressed& e){ //same as what i already have
if(e.GetKeyCode() == BEAVER_KEY_RIGHT)
{
mDirection = Direction::Right;
mState = State::Move;
}

else if(e.GetKeyCode() == BEAVER_KEY_LEFT)
{
mDirection = Direction::Left;
mState = State::Move;
} //same with up and down
}


void MyGame::OnKeyRelease(const bv::KeyReleased& e)
{
(e.GetKeyCode() == BEAVER_KEY_RIGHT or
e.GetKeyCode() = BEAVER_KEY_LEFT or
//same with up down…

mState = State::Stop;
}


void MyGame::CheckCollisions()
{
auto it = mPumpkins.begin();
while(it != mPumpkins.end()){
	if(CollideWithPumpkinAt(it ->first, it->second)){
		it = mPumpkins.erase(it);
mScore++
}
else
it++
}
}
*/