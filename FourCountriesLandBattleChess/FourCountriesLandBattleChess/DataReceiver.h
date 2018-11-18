/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：数据接收者类的声明
备注：
************************************************/
#pragma once
#include <winsock2.h>
#include <thread>
#pragma comment (lib, "ws2_32")

class Mediator;
class DataReceiver
{
public:
	DataReceiver(Mediator * mediator1,SOCKET clientsocket);
	~DataReceiver();
private:
	std::thread *thread;
	Mediator *mediator;
};
