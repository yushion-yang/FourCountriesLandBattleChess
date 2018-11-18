
#include "InitBackGround.h"

InitBackGround::InitBackGround()
{
	initgraph(400, 800, SHOWCONSOLE);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, _T("ËÎÌו"));
	srand((unsigned)time(0));
	BeginBatchDraw();
}

InitBackGround::~InitBackGround()
{

}
