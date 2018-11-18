/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏准备时类的声明
备注：
************************************************/
#pragma once
#include "Controll.h"
#include "Gaming.h"
#include "PRecord.h"

class GameManager;
class Prepare:public Controll
{
public:
	Prepare(GamingScene *gscene1, Mediator *mediator1);
	~Prepare();
	void Update();
private:
	list<Object*> objects;
};
