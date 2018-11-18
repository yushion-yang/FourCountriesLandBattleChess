/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：游戏运行时场景类的声明
备注：
************************************************/
#pragma once
#include "Scene.h"
#include "GamingData.h"
#include "ChessComposition.h"
#include "Controll.h"
#include "Prepare.h"
#include "TipsManager.h"

class GamingScene :public Scene
{
public:
	GamingScene(GameManager *gmanager1);
	~GamingScene();
	void Update();
	void ChangeControll(Controll *controll1);
private:
	Controll *controll;
	list<Object*> objects;
};

