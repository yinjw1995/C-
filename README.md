对C++基础课和提高课中的一些程序进行记录，这里大部分为程序，只有少数一些原理

---

### 类的申明和实现分开

classmain.cpp

```cpp
#include <iostream>
using namespace std;
#include "MyTeacher.h"

void main()
{
	MyTeacher t1;
	t1.setAge(36);
	cout << t1.getAge() << endl;
	cout << "hello..." << endl;
	system("pause");
	return;
}

```

MyTeacher.cpp

```
#include "MyTeacher.h"

void MyTeacher::setAge(int age)
{
	m_age = age;
}
int MyTeacher::getAge()
{
	return m_age;
}
```

MyTeacher.h

```
#pragma once  //只包含一次
/*
#ifndef _MYTEACHER_   //ctrl + shift + u 转换大写
#defin _MYTEACHER_

#endif
*/
class MyTeacher 
{
private:
	int m_age;
	char name[32];

public:
	void setAge(int age);
	int getAge();
};

```

### 案例1，两个立方体的比较，使用类

```cpp
#include <iostream>
using namespace std;
class Cube
{
private:
	int m_a;
	int m_b;
	int m_c;
	int m_v;
	int m_s;
public:
	void setA(int a)
	{
		m_a = a;
	}
	void setB(int b)
	{
		m_b = b;
	}
	void setC(int c)
	{
		m_c = c;
	}
	void setABC(int a = 0, int b = 0, int c = 0)
	{
		m_a = a; m_b = b;
		m_c = c;
	}

 

public:
	int getV()
	{
		m_v = m_a * m_b*m_c;
		return m_v;
	}
	int getS()
	{
		m_s = 2 * (m_a*m_b + m_a * m_c + m_b * m_c);
		return m_s;
	}
	int getA()
	{
		return m_a;
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_c;
	}
	//这里可以在参数里面定义比较函数，有两种，
	//v1.judgecub(v1,v2),v1.judgecube(v2)
	int judgecube(Cube &v1, Cube &v2)
	{
		if (
			(v1.getA() == v2.getA()) &&
			(v1.getB() == v2.getB()) &&
			(v1.getC() == v2.getC())
			)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int judgecube(Cube &v2)  //成员函数 重载函数
	{
		//一定要分清这个场景下的m_a是属于v1还是v2的
		if (
			(m_a == v2.getA()) &&
			(m_b == v2.getB()) &&
			(m_c == v2.getC())
			)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

};
//这里是使用全局函数来进行比较的，这个就没用到类的思想
int judgeCube(Cube &v1, Cube &v2)
{
	if ((v1.getA() == v2.getA()) &&
		(v1.getB() == v2.getB()) &&
		(v1.getC() == v2.getC()) )
		{
			return 1;
		}
	else
	{
		return 0;
	}
}

void main()
{
	Cube v1, v2;
	v1.setABC(1, 2, 3);
	cout << v1.getS() << endl;
	cout << v1.getV() << endl;
	cout << "hello..." << endl;

	v2.setABC(1, 2, 4);
	int targ = v1.judgecube(v2);
	if (judgeCube(v1, v2) == 1)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;

	}
	cout << targ << endl;
	system("pause");
	return;
}
```

