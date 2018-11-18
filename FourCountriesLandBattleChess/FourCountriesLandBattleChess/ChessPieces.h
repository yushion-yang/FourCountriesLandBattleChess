/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:28
版本：V0.1
概要：棋子类的声明
备注：
************************************************/
#pragma once

class ChessPieces
{
public:
	ChessPieces();
	~ChessPieces();

	int cx;
	int cy;
	int camp;
	int number;
	int label;
	bool viable;
	bool ismove;
};
