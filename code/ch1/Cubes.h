#pragma once
#include <iostream>
#include "Points.h" //�õ�ʲôͷ�ļ���дʲô
class Cubes
{
private:
	int x1, x2;
	int y1, y2;
	int z1, z2;
public:
	void setXYZ(int _x1, int _y1, int _z1, int _x2 = 0, int _y2 = 0, int _z2 = 0);
	//ע�⣬����ĳ�ʼֵֻ�������Ա㣬.cpp�ļ�����Ͳ���Ҫ��=0 ��
	int judge(Points &p);

};

