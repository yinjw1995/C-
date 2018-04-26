#include <iostream>
using namespace std;
//判断点是不是在立方体里面
//point 类必须要放在前面，中间要用到就需要前面说明，不然后面要出错的，
//就算使用class point 类的申明也是没用的，这久体现了使用函数和定义分开的好处
class point
{
private:
	int x;
	int y;
	int z;

public:
	void setXYZ(int _x, int _y, int _z)
	{
		x = _x;
		y = _y;
		z = _z;
		return;
	}
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

class Cube
{
private:

	int x1, x2;
	int y1, y2;
	int z1, z2;


public:
	void setXYZ(int _x1, int _y1,int _z1, int _x2=0, int _y2=0, int _z2=0)
	{
		
		x1 = _x1,x2=_x2;
		y1 = _y1,y2=_y2;
		z1 = _z1,z2=_z2;
		return;
	}

	int judge(point &p)
	{
		int targ = ((x1<p.getX())&& (p.getX()<x2) &&
			(y1<p.getY())&&( p.getY()<y2) &&
			(z1<p.getZ())&& (p.getZ()<z2));
		if (targ==1)
		{
			cout << "点在立方体里面" << endl;
			return 1;
		}
		else
		{
			cout << "点不在立方体里面" << endl;
			return 0;
		}
	}
};



void main2()
{
	Cube c1;
	point p1, p2, p3;
	c1.setXYZ(0,0,0,4, 4, 3);
	p1.setXYZ(1, 1, 1);
	p2.setXYZ(3, 3, 1);
	p3.setXYZ(5, 1, 1);
	c1.judge(p1);
	c1.judge(p2);
	c1.judge(p3);

	cout << "hello..." << endl;
	system("pause");
	return;
}


