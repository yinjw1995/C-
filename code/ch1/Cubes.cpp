#include "Cubes.h"
#include "Points.h"
#include <iostream>

//Cubes:: 表示在Cubes环境下定义函数，所定义的环境与.h文件中的变量共用。
int Cubes::judge(Points &p)
{
	int targ = ((x1<p.getX()) && (p.getX()<x2) &&
		(y1<p.getY()) && (p.getY()<y2) &&
		(z1<p.getZ()) && (p.getZ()<z2));
	if (targ == 1)
	{
		std::cout << "点在立方体里面" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "点不在立方体里面" << std::endl;
		return 0;
	}
}

void Cubes::setXYZ(int _x1, int _y1, int _z1, int _x2 , int _y2 , int _z2 )
{

	x1 = _x1, x2 = _x2;
	y1 = _y1, y2 = _y2;
	z1 = _z1, z2 = _z2;
	return;
}
