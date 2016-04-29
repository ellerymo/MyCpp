#include"ComList.h"
void test()
{
	ComList<int> l1;
	l1.pushback(1);
	l1.pushback(2);
	l1.pushback(3);
	l1.pushback(4);
	l1.pushback(5);
	l1.MakeComList();
	l1.Print();
	ComList<int> l2(l1);
	l2.Print();

}
int main()
{
	test();
	getchar();
	return 0;
}