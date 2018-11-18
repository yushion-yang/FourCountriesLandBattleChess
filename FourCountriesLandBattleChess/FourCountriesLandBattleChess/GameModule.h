/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏组件类的声明
备注：
************************************************/
#pragma once
#include <functional>
#include <string>
using namespace std;

class GameModule
{
public:
	GameModule(int x1 = 0,int y1=0);
	virtual ~GameModule();
	virtual void Update();
	virtual void ReStart();
	bool ison;
protected:
	int x;
	int y;
};
