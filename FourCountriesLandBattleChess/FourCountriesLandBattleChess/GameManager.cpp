#include "ClientManager.h"
#include "GameManager.h"
#include "Mediator.h"
#include "FirstInterface.h"

//遇到问题：指针this无法传递给首界面 2018年11月11日10:03:24
//解决问题：其实是有传递给，但是没有使用成员变量保存下来导致lambda调用使用时出错

//遇到问题：2018年11月11日15:40:44 delete链表元素再赋值 再次遍历链表时为空
//解决方法：暂时不清楚链表内部结构，改用简单成员
GameManager::GameManager()
{
	InitBackGround initbkg;
	mediator = new Mediator(this);
	glbdata = new GlobalData(mediator);
	mouseinput = new MouseInput();
	scene = new FirstInterface(this);
	client = new ClientManager(mediator);
}
 
GameManager::~GameManager()
{
	delete(mediator);
	delete(glbdata);
	delete(mouseinput);
	delete(scene);
	delete(client);
}

void GameManager::Run()
{
	while (true)
	{
		mouseinput->Update();
		scene->Update();
		client->Update();
		mouseinput->ClearInput();
		Sleep(20);
		FlushBatchDraw();
		cleardevice();
	}
}

Mediator * GameManager::GetMediator()
{
	return mediator;
}

void GameManager::ChangeScene(Scene * scene1)
{
	delete(scene);
	scene = scene1;
	Run();
}
