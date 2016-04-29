#include"StackQue.h"
using namespace std;
void stack_test()
{
	Stack<int> s1;
	Stack<string> s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s2.push("this");
	s2.push("is");
	s2.push("a");
	s2.push("test");
	s1.PopPrint();
	s2.PopPrint();
}
void queue_test()
{
	Queue<string> q1;
	q1.push("this");
	q1.push("is");
	q1.push("a");
	q1.push("test");
	cout << "Lenth:" << q1.lenth() << endl;
	cout << q1.Pop()<<" " ;
	cout << q1.Pop()<<" " ;
	cout << q1.Pop()<<" " ;
	cout << q1.Pop() << endl;
	cout << "Lenth:" << q1.lenth() << endl;
}
int main()
{
	queue_test();
	getchar();
	return 0;
}