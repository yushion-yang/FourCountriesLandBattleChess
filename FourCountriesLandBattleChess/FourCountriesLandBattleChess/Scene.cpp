
#include "Scene.h"
#include "Mediator.h"

Scene::Scene(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetScene(this);
}

Scene::~Scene()
{
}

void Scene::Update()
{
}
