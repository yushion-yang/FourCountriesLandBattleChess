/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：单局数据类的声明
备注：
************************************************/
#pragma once
#include <graphics.h>
#include "Object.h"
#include "PlayersData.h"

class Mediator;
class GamingData:public Object
{
public:
	GamingData(Mediator *mediator1);
	~GamingData();
	bool RsPlayerReady(int n);
	bool RsPlayerOnline(int n);
	bool RsShowPlayer41(int n, int &x, int &y);

	void Update();
	bool RsActing();
	void ShowPlayerData();
	void ShowTime();
private:
	Mediator *mediator;
	bool acting;					//是否正到自己活动
	int skiptimes;					//跳过次数
	int leftime;					//剩余时间
	PlayersData playersdata[4];		//玩家数据
};
