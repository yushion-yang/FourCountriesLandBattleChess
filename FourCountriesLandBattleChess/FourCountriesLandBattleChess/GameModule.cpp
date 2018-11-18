#include "GameModule.h"

GameModule::GameModule(int x1 , int y1):x(x1),y(y1)
{
	ison = false;
}

GameModule::~GameModule()
{

}

void GameModule::Update()
{

}

void GameModule::ReStart()
{
	ison = true;
}
