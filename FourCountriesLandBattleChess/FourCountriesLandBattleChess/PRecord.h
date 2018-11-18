/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：准备时信息记录类的声明
备注：
************************************************/
#pragma once
#include "Mediator.h"
#include "ChessPieces.h"
#include "Object.h"
#include "Arithmetic.h"

class PRecord:public Object
{
public:
	PRecord(Mediator *mediator1);
	~PRecord();
	bool ChoospChess();					//选棋
	void ChangeChess();					//换棋
	void Update();
	void CancleChoose();
	void Draw();
private:
	Mediator *mediator;
	ChessPieces *chesspieces;
	int ordernum;
};
