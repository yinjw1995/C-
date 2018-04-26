对C++基础课和提高课中的一些程序进行记录，这里大部分为程序，只有少数一些原理

---

### ch1. 类的申明和实现分开

### ch2. 数组类的封装

目的：训练构造函数、赋值构造函数等，为操作符重载准备

对数组进行赋值，并且可以取值，还能用数值给数值传值

步骤：

1. 添加类.cpp 类.h，和主函数

2. 要知道.h文件里面所包含的属性，比如，有参构造函数，无参构造函数，析构函数等基础构造函数，再就是要明确自己需要定义的函数，比如取值，赋值等。还需要明确private中的参数。

   ```
   public:
   	Array();
   	Array(const Array& obj);
   	~Array();

   public:
   	void setData(int index, int data);
   	int getData(int index);
   	int length();
   ```

3. 然后将.h文件里面定了的复制到.cpp文件里面，详细定义

   ```
   里面的参数不用给，但是结构基本设计出，即设计出类的框架
   如果需要修改函数的结构，需要同步相关.h，.cpp文件
   void Array::setData(int index, int data)
   {
   	
   }
   int Array::getData(int index)
   {
   	return 0;
   }
   int Array::length()
   {
   	return 0;
   }
   ```

   然后运行，跑一把，看有没有错误

4. **然后再开始设计类的测试案例**，首先先想好自己的目标是什么，并且设计出测试程序：

   ```
       Array a1(10);
   	cout << "打印数组a2" << endl;
   	for (int i = 0; i < a.length(); i++)
   	{
   		 a.setData(i, i);
   	}
   	for (int i = 0; i < a.length(); i++)
   	{
   		cout << a.getData(i);
   	}

   	Array a2 = a1;
   	cout << "打印数组a2" << endl;
   ```

   保证可以运行的情况下，并且开始完善里面的功能需求

   首先需要增加的就是保存在类里面的参数，即private

   然后对自己定义的函数进行功能设计，具体是干嘛的

   ```
   构造函数完成初始化，拷贝函数完成辅助，析构函数释放内存（如果有指针）
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
   ```

5. 测试优化，看是不是自己想要的结果，否则进行改进





## 小知识

1. ​

