#include <iostream>//include需要在同一文件夹下，不然就要设置路径
#include <Points.h>
#include "Cubes.h"
using namespace std;

//判断点是不是在立方体里面
//point 类必须要放在前面，中间要用到就需要前面说明，不然后面要出错的，
//就算使用class point 类的申明也是没用的，这久体现了使用函数和定义分开的好处


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


