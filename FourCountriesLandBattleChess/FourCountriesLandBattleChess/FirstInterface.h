/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏首界面类的声明
备注：
************************************************/
#pragma once
#include "Scene.h"
#include "GamingScene.h"

class GameManager;
class FirstInterface:public Scene
{
public:
	FirstInterface(GameManager *gmanager1);
	~FirstInterface();
	void Update();
private:
	list<Object*> objects;
	GameManager *gmanager;
};

