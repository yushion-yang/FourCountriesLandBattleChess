/***********************************************
作者：杨玉胜
时间：2018年11月16日20:29:18
版本：V0.1
概要：提示类的声明
备注：
************************************************/
#pragma once
#include <graphics.h>

class TipsManager;
class Tip
{
public:
	Tip(const TCHAR *str1,TipsManager *tipmanager1);
	~Tip();
	void Update(int x1,int y1);
	void Draw(int x1,int y1);

	int keeptime;
private:
	TipsManager *tipsmanager;
	const TCHAR *str;
};
