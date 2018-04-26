#pragma once
#include <iostream> //用到什么.h就要写什么
class Points
{
private:
	int x;
	int y;
	int z;
public:
	void setXYZ(int _x, int _y, int _z);
	
	
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getZ()
	{
		return z;
	}
};

