/***********************************************
作者：杨玉胜
时间：2018年11月18日14:29:26
版本：V0.1
概要：询问组件类的声明
备注：包括了投降询问、和棋询问
************************************************/
#pragma once
#include "GameModule.h"
#include "RectangleModule.h"

class InquiryModule:public GameModule
{
public:
	InquiryModule(const TCHAR *str1, function<void(void)> yes,function<void(void)>no);
	~InquiryModule();
	void Update();
	void Draw();
	void ReStart();
private:
	const TCHAR *str;
	int keeptime;
	int lasttime;
	RectangleModule *yesmodule;
	RectangleModule *nomodule;
};
