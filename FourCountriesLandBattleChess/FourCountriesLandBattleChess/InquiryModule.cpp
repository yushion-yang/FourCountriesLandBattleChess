#include "InquiryModule.h"

const int KEEP_TIME = 30000;

InquiryModule::InquiryModule(const TCHAR *str1, function<void(void)> yes, function<void(void)>no)
{
	x = 520;
	y = 120;
	str = str1;
	keeptime = timeGetTime();
	lasttime = keeptime;
	yesmodule = new RectangleModule(x+30, y+70, 60, 50, _T("同意"), yes);
	nomodule = new RectangleModule(x+120, y+70, 60, 50, _T("拒绝"), no);
}

InquiryModule::~InquiryModule()
{
	delete(yesmodule);
	delete(nomodule);
}

void InquiryModule::Update()
{

	if (ison)
	{
		Draw();
		yesmodule->Update();
		nomodule->Update();
	}
	keeptime = timeGetTime();
	if (keeptime - lasttime > KEEP_TIME)
	{
		ison = false;
	}
}

void InquiryModule::Draw()
{
	fillrectangle(x, y, x + 210, y + 150);
	outtextxy(x + 35, y + 10, _T("其他玩家发起请求"));
	TCHAR ch[20];
	_stprintf_s(ch, _T("%s%2d s"), str, (KEEP_TIME - keeptime + lasttime) / 1000);
	outtextxy(x + 35, y + 40, ch);
}

void InquiryModule::ReStart()
{
	ison = true;
	lasttime = keeptime;
}
