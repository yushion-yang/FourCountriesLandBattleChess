/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏场景基类的声明
备注：
************************************************/
#pragma once
#include "Object.h"
#include "RectangleModule.h"

class Mediator;
class Scene:public Object
{
public:
	Scene(Mediator *mediator1);
	virtual ~Scene();
	virtual void Update();
protected:
	Mediator *mediator;
};
