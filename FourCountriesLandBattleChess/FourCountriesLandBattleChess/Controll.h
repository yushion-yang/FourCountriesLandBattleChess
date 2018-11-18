/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏控制基类的声明
备注：
************************************************/
#pragma once
#include "Object.h"
#include "RectangleModule.h"

class Mediator;
class GamingScene;
class Controll:public Object
{
public:
	Controll(GamingScene *gscene1,Mediator *mediator1);
	virtual ~Controll();
	virtual void Update();
protected:
	Mediator *mediator;
	GamingScene *gscene;
};
