#include <iostream>
using namespace std;
//判断两个立方体是否是一样的

class Cube
{
public:
	void setXYZ(int x, int y,int z)
	{
		_x = x;
		_y = y;
		_z = z;
		return;
	}
	int getX()
	{
		return _x;
	}
	int getY()
	{
		return _y;
	}
	int getZ()
	{
		return _z;
	}
	int getS()
	{
		_s = 2 * (_x * _y + _x * _z + _y * _z);
		cout << "面积S=:" << _s << endl;
		return _s;
	}
	int getV()
	{
		_v = _x * _y*_z;
		cout << "体积V=:" <<_v<< endl;
		return _v;
	}
	int juge(Cube &a)
	{
		if (_x == a.getX() &&
			_y == a.getY() &&
			_z == a.getZ())
		{
			cout << "两个立方体相同" << endl;
			return 1;
		}
		else
		{
			cout << "两个立方体不相同" << endl;
			return 0;
		}
	}
private:
	int _x;
	int _y;
	int _z;
	int _s;
	int _v;
};
	

void main1()
{
	Cube c1, c2;
	c1.setXYZ(1, 2, 3);
	c2.setXYZ(2, 3, 4);
	c1.juge(c2);
	int c1s = c1.getS();
	int c2v = c2.getV();
	cout << "hello..." << endl;
	system("pause");
	return;
}


