#include <iostream>
using namespace std;
//�жϵ��ǲ���������������
//point �����Ҫ����ǰ�棬�м�Ҫ�õ�����Ҫǰ��˵������Ȼ����Ҫ����ģ�
//����ʹ��class point �������Ҳ��û�õģ����������ʹ�ú����Ͷ���ֿ��ĺô�
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
			cout << "��������������" << endl;
			return 1;
		}
		else
		{
			cout << "�㲻������������" << endl;
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


