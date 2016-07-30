#include<iostream>
using namespace std;
class A
{
private:
	void* operator new(size_t size);
	void operator delete(void *p);
};

int main()
{
	A *a = new A();
}