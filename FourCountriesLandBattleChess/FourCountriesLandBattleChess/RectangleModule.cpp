
#include "RectangleModule.h"

RectangleModule::RectangleModule(int x1, int y1, int width1, int height1, const TCHAR * str1, function< void(void)> cbfunc1)
	:Module(x1, y1, str1, cbfunc1)
{
	width = width1;											//组件宽度
	height = height1;										//组建高度
}

RectangleModule::~RectangleModule()
{

}


void RectangleModule::Update()
{
	ismouseon = false;
	if (MouseInput::RsOn(x, y, width, height))
	{
		ismouseon = true;
	}
	if (MouseInput::RsLButtonDown() && MouseInput::RsOn(x, y, width, height))
	{
		cbfunc();
	}
	Draw();
}

void RectangleModule::Draw()
{
	rectangle(x, y, x + width, y + height);
	if (ismouseon)
	{
		rectangle(x + 1, y + 1, x + width - 1, y + height - 1);
		rectangle(x + 2, y + 2, x + width - 2, y + height - 2);
	}
	outtextxy(x + 15, y + height * 0.5f - 10, str);
}

void RectangleModule::SetStr(TCHAR * str1)
{
	str = str1;
}
