
#include "FirstInterface.h"
#include "GameManager.h"

FirstInterface::FirstInterface(GameManager *gmanager1):Scene(gmanager1->GetMediator())
{
	Resize(NULL, 400, 800);
	gmanager = gmanager1;
	objects.push_back(new RectangleModule(150, 200, 100, 50, _T("快速加入"), [&]()->void {
		gmanager->ChangeScene(new GamingScene(gmanager));
	}));
	objects.push_back(new RectangleModule(150, 300, 100, 50, _T("操作说明"), [&]()->void {
		
	}));
	objects.push_back(new RectangleModule(150, 400, 100, 50, _T("退出游戏"), [&]()->void {
		exit(0);
	}));
}

FirstInterface::~FirstInterface()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
}
void FirstInterface::Update()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		(*o)->Update();
	}
}
