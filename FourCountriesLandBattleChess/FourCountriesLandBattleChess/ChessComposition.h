/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:18
版本：V0.1
概要：棋盘类的声明
备注：
************************************************/
#pragma once
#include <graphics.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "Object.h"
#include "ChessPieces.h"
#include "Arithmetic.h"
#include "Square.h"

constexpr auto WIDTH = 4;
#define space setw(WIDTH)
constexpr auto NEWLINE = "\r\n";
using namespace std;

class Mediator;
const int SQUARE_ROW = 19;
class ChessComposition:public Object
{
public:
	ChessComposition(Mediator *mediator1);
	~ChessComposition();
	void Update();
	void Draw();
	void InitSquare();
	void InitChessPieces();
	void LposiToPposi(int lx, int ly, int &px, int &py);
	void PposiToLposi(int px, int py, int &lx, int &ly);
	ChessPieces *GetChess(int px1, int py1);
	Square *GetSquare(int x1,int y1);
	bool ExchangeChess(ChessPieces *cps1, ChessPieces *cps2);
	bool RsPutChess41(int x1, int y1);
	bool RsPutChess00(int x1, int y1);
	bool RsPutChess31(int x1, int y1);
	void SaveChessPosition();
	bool CanMoveChess(ChessPieces *cps1, Square *square1);
	bool CanArrivePosition(ChessPieces * cps1, Square * square1);
	bool CommonFindWay(int ox1, int oy1, int tox2, int toy2);
	bool Chess32FindWay(int map[SQUARE_ROW][SQUARE_ROW], int ox1, int oy1, int tox2, int toy2);
	void MoveChess(ChessPieces *cps1, Square *square1,int movetype);
	int CompareChess(int attack1, int defence1);
private:
	IMAGE img;									//棋盘的图片
	int ordernum;								//玩家顺序号
	Mediator *mediator;							//中介者	
	ChessPieces chesspieces[4][25];				//棋子
	Square squares[SQUARE_ROW][SQUARE_ROW];		//棋格
};
