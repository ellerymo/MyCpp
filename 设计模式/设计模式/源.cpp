#include<iostream>
using namespace std;

//�򵥹���ģʽ
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
	//����ʹ�ú���ָ������������			
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
