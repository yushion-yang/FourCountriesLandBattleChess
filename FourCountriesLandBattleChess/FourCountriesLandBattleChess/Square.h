/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：棋局类的声明
备注：
************************************************/
#pragma once
#include "ChessPieces.h"

class Square
{
public:
	Square();
	~Square();

	int sx;
	int sy;
	int type;
	int direction;
	ChessPieces *chesspieces;
};

