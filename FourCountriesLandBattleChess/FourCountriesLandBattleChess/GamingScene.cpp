
#include "GamingScene.h"
#include "GameManager.h"
#include "Mediator.h"

GamingScene::GamingScene(GameManager *gmanager1):Scene(gmanager1->GetMediator())
{
	Resize(NULL, 800, 800);
	objects.push_back(new ChessComposition(mediator));
	objects.push_back(new TipsManager(mediator));
	objects.push_back(new GamingData(mediator));
	controll = new Prepare(this, mediator);
}

GamingScene::~GamingScene()
{
	delete(controll);
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		delete(*o);
	}
}

void GamingScene::Update()
{
	for (auto o = objects.begin(); o != objects.end(); ++o)
	{
		(*o)->Update();
	}
	controll->Update();
}

void GamingScene::ChangeControll(Controll * controll1)
{
	delete(controll);
	controll = controll1;
	mediator->ReRun();
}
