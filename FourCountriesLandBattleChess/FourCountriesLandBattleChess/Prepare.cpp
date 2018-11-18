#include "Prepare.h"
#include "GameManager.h"
#include "Mediator.h"
#include "GamingScene.h"
//在运行过程中将自身给删除了，但是自身还剩余一部分逻辑没有运行完毕
Prepare::Prepare(GamingScene *gscene1, Mediator *mediator1):Controll(gscene1,mediator1)
{
	objects.push_back(new RectangleModule(550, 500, 100, 50, _T("完成布局"), [&]()->void {
		gscene->ChangeControll(new Gaming(gscene ,mediator));
	}));
	objects.push_back(new RectangleModule(550, 570, 100, 50, _T("保存棋盘"), [&]()->void {
		mediator->SaveChessPosition();
	}));
	objects.push_back(new RectangleModule(550, 640, 100, 50, _T("重置棋盘"), [&]()->void {
		mediator->ReSetSquare();
	}));
	objects.push_back(new RectangleModule(550, 710, 100, 50, _T("快速换桌"), [&]()->void {

	}));

	objects.push_back(new RectangleModule(670, 50, 100, 50, _T("返回大厅"), [&]()->void {
		mediator->ReturnLobby();
	}));

	objects.push_back(new PRecord(mediator));
}

Prepare::~Prepare()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
}

void Prepare::Update()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		(*o)->Update();
	}
}
