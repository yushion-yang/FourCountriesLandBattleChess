#include "Tip.h"
#include "TipsManager.h"
const int KEEP_TIME = 5000;

Tip::Tip(const TCHAR * str1,TipsManager *tipsmanager1)
{
	str = str1;
	tipsmanager = tipsmanager1;
	keeptime = 0;
}

Tip::~Tip()
{

}

void Tip::Update(int x1,int y1)
{
	Draw(x1, y1);
	if (keeptime > KEEP_TIME)
	{
		tipsmanager->DeleteTip(this);
	}
}

void Tip::Draw(int x1, int y1)
{
	int currentcolor = getcolor();
	setcolor(RED);
	outtextxy(x1, y1, str);
	setcolor(currentcolor);
}
