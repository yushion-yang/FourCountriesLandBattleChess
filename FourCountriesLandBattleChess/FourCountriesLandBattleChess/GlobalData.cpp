
#include "GlobalData.h"
#include "Mediator.h"
GlobalData::GlobalData(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetGlobalData(this);
	ordernum = 0;		//≤‚ ‘
}

GlobalData::~GlobalData()
{

}

int GlobalData::GetOrdernum()
{
	return ordernum;
}

void GlobalData::SetOrdernum(int ordernum1)
{
	ordernum = ordernum1;
}

