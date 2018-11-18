/***********************************************
作者：杨玉胜
时间：2018年11月10日20:57:47
版本：V0.1
概要：组件基类的声明
备注：
************************************************/
#pragma once
#include "Object.h"
#include "MouseInput.h"

class Module :public Object
{
public:
	Module(int x1, int y1, const TCHAR *str1, function< void(void)> cbfunc1);
	virtual ~Module();
	virtual void Update();
protected:
	int x;												//坐标x
	int y;												//坐标x
	const TCHAR *str;									//显示的字符串
	bool ismouseon;										//是否被触及
	function< void(void)> cbfunc;						//回调方法
};