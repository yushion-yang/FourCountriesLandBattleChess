/***********************************************
作者：杨玉胜
时间：2018年11月11日17:40:53
版本：V0.1
概要：客户端类的声明
备注：
************************************************/
#pragma once
#include <winsock2.h>
#pragma comment (lib, "ws2_32")
#pragma warning(disable:4996)
//注意：要将系统的文件放在自定义的文件前面
//遇到问题：文件包含错误2018年11月11日16:49:08 找不到怎么样的相互包含错误问题
//解决问题：2018年11月11日20:57:59 耗费时间很长 winsock2文件需要放在自定义文件的前面才行 注意！！！
//替补方法：将所有头文件集中起来一起引用

class Mediator;
class ClientManager
{
public:
	ClientManager(Mediator *mediator1);
	~ClientManager();
	void Update();
private:
	Mediator *mediator;
	SOCKET s;
};
