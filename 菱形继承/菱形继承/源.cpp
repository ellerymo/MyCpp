#include<iostream>
using namespace std;
class Base
{
protected:
	int _base;
public:
	void fun()
	{
		cout << "Base::fun" << endl;
	}
};

class A:public Base
{
protected:
	int _a;
};

class B : public Base
{
protected:
	int _b;
};
class D :public A, public B
{
private:
	int _d;
};
int main()
{
	D d;
	//d.fun();
	getchar();
}
