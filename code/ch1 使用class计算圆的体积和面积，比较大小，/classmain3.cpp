#include <iostream>//include��Ҫ��ͬһ�ļ����£���Ȼ��Ҫ����·��
#include <Points.h>
#include "Cubes.h"
using namespace std;

//�жϵ��ǲ���������������
//point �����Ҫ����ǰ�棬�м�Ҫ�õ�����Ҫǰ��˵������Ȼ����Ҫ����ģ�
//����ʹ��class point �������Ҳ��û�õģ����������ʹ�ú����Ͷ���ֿ��ĺô�


void main()
{
	Cubes c1;
	Points p1, p2, p3;
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


