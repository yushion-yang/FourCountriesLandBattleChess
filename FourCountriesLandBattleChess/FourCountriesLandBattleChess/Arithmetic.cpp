#include "Arithmetic.h"

void LpToPp(int ordernum, int lx, int ly, int & px, int & py)
{
	px = lx;
	py = ly;
	switch (ordernum)
	{
	case 1:
		py = 9 - (lx - 9);
		px = 9 + (ly - 9);
		break;
	case 0:
		py = 9 - (ly - 9);
		px = 9 - (lx - 9);
		break;
	case 3:
		py = 9 + (lx - 9);
		px = 9 - (ly - 9);
		break;
	}
}

void PpToLp(int ordernum, int px, int py, int & lx, int & ly)
{
	lx = px;
	ly = py;
	switch (ordernum)
	{
	case 1:
		ly = 9 + (px - 9);
		lx = 9 - (py - 9);
		break;
	case 0:
		ly = 9 - (py - 9);
		lx = 9 - (px - 9);
		break;
	case 3:
		ly = 9 - (px - 9);
		lx = 9 + (py - 9);
		break;
	}
}
