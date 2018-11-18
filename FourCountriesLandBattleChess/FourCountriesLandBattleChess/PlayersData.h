/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：玩家信息类的声明
备注：
************************************************/
#pragma once

class PlayersData
{
public:
	PlayersData();
	~PlayersData();

	bool online;			//是否在线
	bool ready;				//是否准备
	bool survival40;		//是否存活司令
	int chessx41;			//41代表军棋 x
	int chessy41;			//41代表军棋 y
};
