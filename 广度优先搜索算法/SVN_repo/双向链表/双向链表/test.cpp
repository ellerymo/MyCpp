#include "DList.h"
void test1()
{
	DList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	cout << list;
	list.PopBack();
	list.PopBack();
	list.PopBack();
	list.PopBack();
	cout << list;
	list.PushFront(1);
	list.PushFront(2);
	list.PushFront(3);
	list.PushFront(4);
	cout << list;
	list.PopFront();
	list.PopFront();
	list.PopFront();
	list.PopFront();
	cout << list;
}
void test2()
{
	DList list;
	list.insert(0,1);
	list.insert(0,2);
	list.insert(0,3);
	list.insert(0,4);
	cout << list;
	cout << list.Find(2)<< endl;
	list.Remove(2);
	list.Remove(4);
	cout << list;
}
void test3()
{
	DList list;
	list.insert(0, 1);
	list.insert(0, 2);
	list.insert(0, 1);
	list.insert(0, 1);
	cout << list;
	list.RemoveAll(1);
	cout << list;
}
void test4()
{
	DList list;
	list.PushBack(1);
	list.PushBack(3);
	list.PushBack(5);
	list.PushBack(7);
	list.PushBack(9);
	list.PushBack(2);
	list.PushBack(4);
	list.PushBack(6);
	cout << list;
	list.sort();
	cout << list;
	list.Reverse();
	cout << list;
}

int main()
{
	test4();
	getchar();
	return 0;
}