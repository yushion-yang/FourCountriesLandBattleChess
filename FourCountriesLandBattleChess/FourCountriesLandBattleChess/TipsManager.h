/***********************************************
作者：杨玉胜
时间：2018年11月16日20:28:58
版本：V0.1
概要：提示管理类的声明
备注：
************************************************/
#pragma once
#include "Object.h"
#include "Tip.h"

class Mediator;
class TipsManager:public Object
{
public:
	TipsManager(Mediator *mediator1);
	~TipsManager();
	void Update();
	void AddTip(const TCHAR *str1);
	void DeleteTip(Tip *tip1);
private:
	Mediator *mediator;
	list<Tip*> tips;
	list<Tip*>::iterator iterator;
	int lastftime;
};
