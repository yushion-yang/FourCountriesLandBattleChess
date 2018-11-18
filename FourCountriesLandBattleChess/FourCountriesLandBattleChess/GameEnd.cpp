
#include "GameEnd.h"
#include "GameManager.h"
#include "Mediator.h"

GameEnd::GameEnd(GamingScene * gscene1, Mediator * mediator1) :Controll(gscene1, mediator1)
{
	objects.push_back(new RectangleModule(550, 670, 100, 50, _T("快速换桌"), [&]()->void {

	}));

	objects.push_back(new RectangleModule(670, 50, 100, 50, _T("返回大厅"), [&]()->void {
		mediator->ReturnLobby();
	}));
}

GameEnd::~GameEnd()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
}

void GameEnd::Update()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		(*o)->Update();
	}
}
