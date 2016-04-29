#include<iostream>
using namespace std;
typedef void(*PTR)();
class Base1
{
private:
	int _base1;
public:
	Base1()
		:_base1(0)
	{}
	virtual void show()
	{
		cout << "Base1::show()" << endl;
	}
};
class Base2
{
private:
	int _base2;
public:
	Base2()
		:_base2(2)
	{}
	virtual void show()
	{
		cout << "Base2::show()" << endl;
	}
	virtual void fun2()
	{
		cout << "Base2::fun2()" << endl;
	}
};
class D:public Base1,public Base2
{
public:
	D()
		:_d(1)
	{}
	void show()
	{
		cout << "D::show()" << endl;
	}
	void fun2()
	{
		cout << "D::fun2()" << endl;
	}
	virtual void fun3()
	{
		cout << "D::fun3()" << endl;
	}
	virtual void fun4()
	{
		cout << "D::fun4()" << endl;
	}
private:
	int _d;
};
void PrintVT(int p)
	//实参是每个类存储虚函数指针的地址，解引用之后代表该类的虚函数指针
{
	PTR ptr = NULL;
	//现在让pi能访问类的虚函数指针
	int *pi = (int *)p;
	int i = 0;
	while (pi[i])
	{
		ptr = (PTR)pi[i];
		ptr();
		i++;
	}
}
int main()
{
	Base1 b1;
	Base2 b2;
	D d;
	//PrintVT(*(int *)&b);
	//cout << "--------------------" << endl;
	//PrintVT(*(int *)&b2);
	//cout << "--------------------" << endl;
	//PrintVT(*(int *)&d);
	cout << "--------------------" << endl;
	Base1 *pb1 = &(b1);
	Base2 *pb2 = &(b2);
	D *pd = &d;
	int *ptr = (int *)pd;
	int *ptb1 = (int *)pb1;
	int *ptb2 = (int *)pb2;
	//通过以下代码我们可以拿到虚表的地址
	cout << "Base1 :VitualTable ADDR:" <<hex<< (int)*ptb1 << endl;
	cout << "Base2 :VitualTable ADDR:" <<hex<< (int)*ptb2 << endl;
	cout <<"D->Base1 :VitualTable ADDR:" <<hex<< (int)*ptr << endl;
	cout <<"D->Base2 :VitualTable ADDR:"<<hex<<(int)*(ptr + 2) << endl;
	getchar();
	return 0;
}