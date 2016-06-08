#include<iostream>
using namespace std;

//简单工厂模式
class Api
{
public:
	virtual  void Print() = 0;
};
class A :public Api
{
public:
	void Print()
	{
		cout << "This is class A" << endl;
	}
};
class B :public Api
{
public:
	 void Print()
	{
		cout << "This is class B" << endl;
	}
};
class Imp 
{
public:
	//我们使用函数指针接收子类对象			
	static Api* createApi(int condition)
	{
		if (condition == 1)
			return new A();
		else
			return new B();
	}
};

int main()
{
	Api *api = Imp().createApi(2);
	api->Print();
	getchar();
	return 0;
}
