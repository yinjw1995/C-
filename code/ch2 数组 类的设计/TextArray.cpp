#include <iostream>
using namespace std;
#include "Array.h"

void main()
{
	Array a1(10);
	cout << "打印数组a2" << endl;
	for (int i = 0; i < a1.length(); i++)
	{
		 a1.setData(i, i);
	}
	for (int i = 0; i < a1.length(); i++)
	{
		cout << a1.getData(i)<<" ";
	}

	Array a2 = a1;
	cout << "打印数组a2" << endl;
	for (int i = 0; i < a1.length(); i++)
	{
		cout << a2.getData(i) << " ";
	}
	

	cout<<"hello..."<<endl;
	system("pause");
	return ;
}