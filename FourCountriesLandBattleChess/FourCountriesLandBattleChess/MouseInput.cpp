
#include "MouseInput.h"

MOUSEMSG MouseInput::m;									

MouseInput::MouseInput()
{

}

MouseInput::~MouseInput()
{

}

void MouseInput::Update()
{
	while (MouseHit())		//获取更新鼠标信息
	{
		m = GetMouseMsg();
	}
}

bool MouseInput::RsMosueMove()
{
	if (m.uMsg == WM_MOUSEMOVE)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsLButtonDown()
{
	if (m.uMsg == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}
bool MouseInput::RsMButtonDown()
{
	if (m.uMsg == WM_MBUTTONDOWN)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsRButtonDown()
{
	if (m.uMsg == WM_RBUTTONDOWN)
	{
		return true;
	}
	return false;
}

bool MouseInput::RsOn(int x1, int y1, int width1, int height1)
{
	if (m.x > x1&&m.x<x1 + width1 && m.y>y1&&m.y < y1 + height1)
	{
		return true;
	}
	return false;
}

void MouseInput::GetMxy(int & x1, int & y1)
{
	x1 = m.x;
	y1 = m.y;
}

void MouseInput::ClearInput()
{
	m.uMsg = NULL;
}
