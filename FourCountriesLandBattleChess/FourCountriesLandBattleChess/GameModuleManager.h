/***********************************************
作者：杨玉胜
时间：2018年11月18日14:30:58
版本：V0.1
概要：游戏组件管理者类的声明
备注：
************************************************/
#pragma once
#include "GameModule.h"
#include "Object.h"
#include "InquiryModule.h"

enum ModuleType{SURRENDER,DRAW,MAX_MODULE_NUM};
class Mediator;
class GameModuleManager :public Object
{
public:
	GameModuleManager(Mediator *mediator1);
	~GameModuleManager();
	void TurnOnModule(int monum);
	void TurnOffModule(int monum);
	void Update();
private:
	Mediator *mediator;
	GameModule *gmodules[MAX_MODULE_NUM];
};
