#pragma once
#include <iostream>
using namespace std;

class Array
{
public:
	Array(int length);
	Array(const Array& obj);
	~Array();

public:
	void setData(int index, int data);
	int getData(int index);
	int length();
private:
	int m_len;
	int* m_Space;

};

