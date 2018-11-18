
#include "Controll.h"
#include "Mediator.h"
#include "GamingScene.h"

Controll::Controll(GamingScene *gscene1, Mediator *mediator1)
{
	gscene = gscene1;
	mediator = mediator1;
	mediator->SetControll(this);
}

Controll::~Controll()
{

}

void Controll::Update()
{

}
