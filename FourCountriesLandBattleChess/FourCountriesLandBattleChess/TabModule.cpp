#include "TabModule.h"
#include "Mediator.h"

TCHAR str[18][5] = {
	_T("大"),
	_T("中"),
	_T("小"),

	_T("！"),
	_T("？"),
	_T("-"),

	_T("兵"),
	_T("排"),
	_T("连"),

	_T("营"),
	_T("团"),
	_T("旅"),

	_T("师"),
	_T("军"),
	_T("司"),

	_T("炸"),
	_T("雷"),
	_T("旗")
};

TabModule::TabModule(Mediator *mediator1)
{
	mediator = mediator1;
	x = 0;
	y = 0;
	height = 180;
	width = 90;
	cps = NULL;
}

TabModule::~TabModule()
{

}

bool TabModule::Update()
{
	ReStart();
	if (ison)
	{
		Draw();
		if (MouseInput::RsLButtonDown())
		{
			int px, py;
			MouseInput::GetMxy(px, py);
			int label = RsPoint(px, py);
			ison = false;
			if (label>=0)
			{
				cps->label = label;
			}
			return true;
		}
	}
	return false;
}

void TabModule::SetXy(int x1, int y1)
{
	x = x1;
	y = y1;
	if (y1 > 600)
	{
		y = y1 - height;
	}
	if (x1 > 700)
	{
		x = x1 - width;
	}
}

void TabModule::Draw()
{
	setfillcolor(WHITE);
	int currentcolor = getcolor();
	setcolor(BLACK);
	fillrectangle(x, y, x + width, y + height);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			rectangle(x + i * 30, y + j * 30, x + (i + 1) * 30, y + (j + 1) * 30);
			outtextxy(x + 8 + i * 30, y + 8 + j * 30, str[j * 3 + i]);
		}
	}
	setcolor(currentcolor);
}

int TabModule::RsPoint(int x1,int y1)
{
	if (x1<x || x1>x + width || y1<y || y>y + height)
	{
		return -1;
	}
	int n = (x1 - x) / 30 + ((y1 - y) / 30 * 3);
	if (n < 18)
	{
		return n;
	}
	return -1;
}

void TabModule::ReStart()
{
	if (MouseInput::RsRButtonDown())
	{
		int px, py;
		MouseInput::GetMxy(px, py);
		cps = mediator->GetChess(px, py);
		if (cps && cps->camp != mediator->GetOrdernum())
		{
			SetXy(px, py);
			ison = true;
		}
		else
		{
			ison = false;
		}
	}
}
