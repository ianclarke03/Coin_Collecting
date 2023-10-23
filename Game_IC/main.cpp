#include"Egg.h"

#include<iostream>

class MyGame : public egg::EggApp<MyGame>
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Egg running" << std::endl;
	}
};

EGG_APPLICATION_START(MyGame);