/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏运行时控制类的声明
备注：
************************************************/
#pragma once
#include "Controll.h"
#include "GameEnd.h"
#include "GRecord.h"
#include "GameModuleManager.h"
#include "TabModule.h"

class GameManager;
class Gaming:public Controll
{
public:
	Gaming(GamingScene *gscene1, Mediator *mediator1);
	~Gaming();
	void Update();
private:
	list<Object*> objects;
	TabModule *tabmodule;
};
