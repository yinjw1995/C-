#include "Array.h"


Array::Array(int length)
{
	if (length < 0)
	{
		m_len = 0;
	}

	m_len = length;
	m_Space = new int[m_len]; //初始化

}

Array::Array(const Array& obj)
{
	this->m_len = obj.m_len;
	this->m_Space = new int[this->m_len];  //分配内存

	for (int i = 0; i < obj.m_len; i++)
	{
		this->m_Space[i] = obj.m_Space[i];
	}
}
Array::~Array()
{
	if (m_Space != NULL)
	{
		delete [] m_Space;
		m_len = 0;
	}
}

void Array::setData(int index, int data)
{
	m_Space[index] = data;
}
int Array::getData(int index)
{
	return m_Space[index];
}
int Array::length()
{
	return m_len;
}
