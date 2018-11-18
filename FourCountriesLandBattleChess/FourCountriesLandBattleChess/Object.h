/***********************************************
作者：杨玉胜
时间：2018年11月10日20:29:28
版本：V0.1
概要：对象基类的声明
备注：
************************************************/
#pragma once
#include <graphics.h>
#include <functional>
#include <vector>
#include <list>
using namespace std;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Update();
protected:

};