/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：中介者类的声明
备注：
************************************************/
#pragma once
#include "Scene.h"
#include "Controll.h"
#include "GlobalData.h"
#include "GamingData.h"
#include "FirstInterface.h"
#include "ChessComposition.h"
#include "TipsManager.h"
#include "GameModuleManager.h"

class ClientManager;
class GameManager;
class Mediator 
{
public:
	Mediator(GameManager *gmanager1);
	~Mediator();

	void SetScene(Scene *scene1);
	void SetControll(Controll *controll1);
	void SetGlobalData(GlobalData *glbdata1);
	void SetGamingData(GamingData *gmdata1);
	void SetClient(ClientManager *client1);
	void SetCCst(ChessComposition *ccst1);
	void SetTipsManager(TipsManager *tipsmanager1);
	void SetGMManager(GameModuleManager *gmmanager1);

	int GetOrdernum();
	ChessPieces *GetChess(int x1, int y1);
	Square *GetSquare(int x1, int y1);

	bool RsActing();
	bool RsPlayerReady(int n);
	bool RsPlayerOnline(int n);
	bool RsShowPlayer41(int n, int &x, int &y);
	void TurnOnModule(int monum);
	bool CanMoveChess(ChessPieces *cps1, Square *square1);
	bool ChangeChess(ChessPieces * cps1, ChessPieces * cps2);
	void SaveChessPosition();
	void ReturnLobby();
	void AddTip(const TCHAR *str1);
	void ReRun();
	void ReSetSquare();
private:
	GameManager *gmanager;
	Scene *scene;
	Controll *controll;
	GlobalData *glbdata;
	GamingData *gmdata;
	ChessComposition *ccst;
	TipsManager *tipsmanager;
	ClientManager *clientmanager;
	GameModuleManager *gmmanager;
};
