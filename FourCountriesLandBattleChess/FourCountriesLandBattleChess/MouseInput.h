/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：鼠标输入类的声明
备注：
************************************************/
#pragma once
#include "Object.h"

class MouseInput :public Object
{
public:
	MouseInput();
	~MouseInput();
	void Update();
	static bool RsMosueMove();
	static bool RsLButtonDown();
	static bool RsMButtonDown();
	static bool RsRButtonDown();
	static bool RsOn(int x1, int y1, int width1, int height1);
	static void GetMxy(int &x1, int &y1);
	void ClearInput();
private:
	static MOUSEMSG m;
};
