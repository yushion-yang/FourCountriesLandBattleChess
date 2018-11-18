/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏结束类的声明
备注：
************************************************/
#pragma once
#include "Controll.h"

class GameManager;
class GameEnd :public Controll
{
public:
	GameEnd(GamingScene *gscene1, Mediator *mediator1);
	~GameEnd();
	void Update();
private:
	list<Object*> objects;
};
