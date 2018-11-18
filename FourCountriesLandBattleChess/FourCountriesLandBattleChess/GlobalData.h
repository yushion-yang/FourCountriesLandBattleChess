/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：全局数据类的声明
备注：
************************************************/
#pragma once
class Mediator;

class GlobalData
{
public:
	GlobalData(Mediator *mediator1);
	~GlobalData();
	int GetOrdernum();
	void SetOrdernum(int ordernum1);
private:
	Mediator *mediator;
	int ordernum;
};
