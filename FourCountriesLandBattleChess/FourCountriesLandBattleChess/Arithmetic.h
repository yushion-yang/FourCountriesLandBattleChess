/***********************************************
作者：杨玉胜
时间：2018年11月15日21:06:03
版本：V0.1
概要：算法类的声明
备注：包括逻辑物理坐标相互转换、
************************************************/
#pragma once
void LpToPp(int ordernum, int lx, int ly, int &px, int &py);
void PpToLp(int ordernum, int px, int py, int &lx, int &ly);