#include "TipsManager.h"
#include "Mediator.h"

const int MAX_TIP_NUM = 5;
TipsManager::TipsManager(Mediator * mediator1)
{
	mediator = mediator1;
	mediator->SetTipsManager(this);
	lastftime = timeGetTime();
}

TipsManager::~TipsManager()
{
	for (auto tip = tips.begin(); tip != tips.end(); ++tip)
	{
		delete(*tip);
	}
}

void TipsManager::Update()
{
	int x = 100;
	int y = 700;
	int tipn = 0;
	int newtime = timeGetTime();
	for (iterator = tips.begin(); iterator != tips.end();)
	{
		(*iterator)->keeptime += newtime - lastftime;
		(*iterator)->Update(x, y - tipn * 40);
		if (iterator != tips.end())
		{
			++iterator;
		}
		tipn++;
	}
	lastftime = newtime;
}

void TipsManager::AddTip(const TCHAR * str1)
{
	if (tips.size() < MAX_TIP_NUM)
	{
		tips.push_front(new Tip(str1, this));
	}
}

void TipsManager::DeleteTip(Tip * tip1)
{
	for (auto tip = tips.begin(); tip != tips.end(); ++tip)
	{
		if (*tip == tip1)
		{
			delete(*tip);
			iterator = tips.erase(tip);
			break;
		}
	}
}
