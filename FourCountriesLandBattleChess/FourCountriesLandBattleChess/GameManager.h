/***********************************************
作者：杨玉胜
时间：2018年11月10日20:36:32
版本：V0.1
概要：游戏管理者类的声明
备注：
************************************************/
#pragma once
#include "InitBackGround.h"
#include "Scene.h"
#include "GlobalData.h"

class Mediator;
class ClientManager;
class FirstInterface;
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Run();
	Mediator* GetMediator();
	void ChangeScene(Scene *scene1);
private:
	MouseInput *mouseinput;
	Mediator *mediator;
	Scene *scene;
	GlobalData *glbdata;
	ClientManager *client;
};
