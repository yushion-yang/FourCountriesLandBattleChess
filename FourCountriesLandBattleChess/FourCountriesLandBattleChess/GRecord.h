/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：运行时记录类的声明
备注：
************************************************/
#pragma once
#include "Mediator.h"
#include "ChessPieces.h"
#include "Object.h"
#include "Arithmetic.h"

class GRecord :public Object
{
public:
	GRecord(Mediator *mediator1);
	~GRecord();
	bool ChoospChess();					//选棋
	void MoveChess();					//换棋
	void Update();
	void CancleChoose();
	void Draw();
private:
	Mediator *mediator;
	ChessPieces *chesspieces;
	int ordernum;
};