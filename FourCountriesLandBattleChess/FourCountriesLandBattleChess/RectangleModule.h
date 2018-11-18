/***********************************************
作者：杨玉胜
时间：2018年11月10日20:57:47
版本：V0.1
概要：矩形组件类的声明
备注：
************************************************/
#pragma once
#include "Module.h"

class RectangleModule :public Module
{
public:
	RectangleModule(int x1, int y1, int width1, int height1, const TCHAR *str1, function< void(void)> cbfunc1);
	~RectangleModule();
	void Update();
	void Draw();
	void SetStr(TCHAR *str1);
private:
	int width;											//组件宽度
	int height;											//组件高度
};

