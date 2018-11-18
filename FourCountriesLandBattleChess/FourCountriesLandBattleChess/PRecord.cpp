#include "PRecord.h"
#include <time.h>
#pragma comment( lib,"winmm.lib" )

PRecord::PRecord(Mediator * mediator1)
{
	mediator = mediator1;
	ordernum = mediator->GetOrdernum();
	chesspieces = NULL;
}

PRecord::~PRecord()
{

}

bool PRecord::ChoospChess()
{
	//如果还没有选择 并且点击到了自己的棋则选择成功
	if (chesspieces)
	{
		return false;
	}
	if (MouseInput::RsLButtonDown())
	{
		int x, y;
		MouseInput::GetMxy(x, y);
		ChessPieces *cps =  mediator->GetChess(x, y);
		if (cps && cps->camp == ordernum)
		{
			chesspieces = cps;
			mediator->AddTip(_T("选取棋子"));
			return true;
		}
	}
	return false;
}

void PRecord::ChangeChess()
{
	if (!chesspieces)
	{
		return;
	}
	if (MouseInput::RsLButtonDown())
	{
		int x, y;
		MouseInput::GetMxy(x, y);
		ChessPieces *cps = mediator->GetChess(x, y);
		if (!cps)
		{
			return;
		}
		if (cps == chesspieces)
		{
			chesspieces = NULL;
			return;
		}
		if (cps->camp == ordernum && mediator->ChangeChess(chesspieces, cps))
		{
			mediator->AddTip(_T("移动棋子"));
			chesspieces = NULL;
		}
	}
}

void PRecord::Update()
{
	if (!ChoospChess())
	{
		ChangeChess();
	}
	CancleChoose();
	Draw();
}

void PRecord::CancleChoose()
{
	if (MouseInput::RsRButtonDown())
	{
		mediator->AddTip(_T("取消选棋子"));
		chesspieces = NULL;
	}
}

void PRecord::Draw()
{
	if (!chesspieces)
	{
		return;
	}
	if (timeGetTime() % 1000 < 550)
	{
		return;
	}
	int hang, lie;
	PpToLp(ordernum,chesspieces->cx, chesspieces->cy, hang, lie);

	setfillcolor(BLACK);
	if (lie < 7 || lie>11)
	{
		fillrectangle(20 + lie * 40, 15 + hang * 40, 40 + lie * 40, 45 + hang * 40);//纵向的矩形
		rectangle(18 + lie * 40, 13 + hang * 40, 38 + lie * 40, 43 + hang * 40);
	}
	else
	{
		fillrectangle(15 + lie * 40, 20 + hang * 40, 45 + lie * 40, 40 + hang * 40);//横向的矩形
		rectangle(13 + lie * 40, 18 + hang * 40, 43 + lie * 40, 38 + hang * 40);
	}
}
