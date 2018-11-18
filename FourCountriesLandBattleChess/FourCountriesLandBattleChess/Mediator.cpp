#include "ClientManager.h"
#include "Mediator.h"
#include "GameManager.h"

Mediator::Mediator(GameManager *gmanager1)
{
	gmanager = gmanager1;
}

Mediator::~Mediator()
{
}

void Mediator::SetScene(Scene * scene1)
{
	scene = scene1;
}

void Mediator::SetGlobalData(GlobalData * glbdata1)
{
	glbdata = glbdata1;
}

void Mediator::SetGamingData(GamingData * gmdata1)
{
	gmdata = gmdata1;
}

void Mediator::SetClient(ClientManager * client1)
{
	clientmanager = client1;
}

void Mediator::SetCCst(ChessComposition * ccst1)
{
	ccst = ccst1;
}

void Mediator::SetTipsManager(TipsManager * tipsmanager1)
{
	tipsmanager = tipsmanager1;
}

void Mediator::SetGMManager(GameModuleManager * gmmanager1)
{
	gmmanager = gmmanager1;
}

int Mediator::GetOrdernum()
{
	return glbdata->GetOrdernum();
}

ChessPieces * Mediator::GetChess(int x1, int y1)
{
	return ccst->GetChess(x1, y1);
}

Square * Mediator::GetSquare(int x1, int y1)
{
	return ccst->GetSquare(x1, y1);
}

bool Mediator::RsActing()
{
	return gmdata->RsActing();
}

bool Mediator::RsPlayerReady(int n)
{
	return gmdata->RsPlayerReady(n);
}

bool Mediator::RsPlayerOnline(int n)
{
	return gmdata->RsPlayerOnline(n);
}

bool Mediator::RsShowPlayer41(int n, int & x, int & y)
{
	return gmdata->RsShowPlayer41(n,x,y);
}

void Mediator::TurnOnModule(int monum)
{
	gmmanager->TurnOnModule(monum);
}

bool Mediator::CanMoveChess(ChessPieces * cps1, Square * square1)
{
	return ccst->CanMoveChess(cps1, square1);
}

bool Mediator::ChangeChess(ChessPieces * cps1, ChessPieces * cps2)
{
	if ( ccst->ExchangeChess(cps1, cps2))
	{
		return true;
	}
	return false;
}

void Mediator::SaveChessPosition()
{
	ccst->SaveChessPosition();
	tipsmanager->AddTip(_T("±£¥Ê∆Â≈Ã"));
}

void Mediator::ReturnLobby()
{
	gmanager->ChangeScene(new FirstInterface(gmanager));
}

void Mediator::AddTip(const TCHAR * str1)
{
	tipsmanager->AddTip(str1);
}

void Mediator::ReRun()
{
	gmanager->Run();
}

void Mediator::ReSetSquare()
{
	ccst->InitChessPieces();
	tipsmanager->AddTip(_T("÷ÿ÷√∆Â≈Ã"));
}

void Mediator::SetControll(Controll * controll1)
{
	controll = controll1;
}