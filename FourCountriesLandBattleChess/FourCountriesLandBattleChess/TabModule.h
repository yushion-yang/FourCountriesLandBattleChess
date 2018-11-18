/***********************************************
作者：杨玉胜
时间：2018年11月18日14:27:09
版本：V0.1
概要：标签组件类的声明
备注：给棋子添加标签
************************************************/
#pragma once
#include <graphics.h>
#include "MouseInput.h"
#include "ChessPieces.h"

class Mediator;
class TabModule
{
public:
	TabModule(Mediator *mediator1);
	~TabModule();
	bool Update();
	void SetXy(int x1, int y1);
	void Draw();
	int RsPoint(int x1, int y1);
	void ReStart();
private:
	Mediator *mediator;
	ChessPieces *cps;
	int x;
	int y;
	bool ison;
	int height;
	int width;
};