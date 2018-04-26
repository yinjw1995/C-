#pragma once
#include <iostream>
#include "Points.h" //用到什么头文件就写什么
class Cubes
{
private:
	int x1, x2;
	int y1, y2;
	int z1, z2;
public:
	void setXYZ(int _x1, int _y1, int _z1, int _x2 = 0, int _y2 = 0, int _z2 = 0);
	//注意，这里的初始值只能设置以便，.cpp文件里面就不需要在=0 了
	int judge(Points &p);

};

