#include"SeqList.h"
void test()
{
	SeqList<int> s1;
	cout << "尾插12345" << endl;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.display();
	cout << "" << endl;
	s1.PopBack();
	s1.PopBack();
	s1.PopBack();
	s1.display();
	cout << "前插5678" << endl;
	s1.PushFront(5);
	s1.PushFront(6);
	s1.PushFront(7);
	s1.PushFront(8);
	cout << "按位置插入：第三个元素处插入5" << endl;
	s1.Insert(2,5);
	cout << "排序" << endl;
	s1.Sort();
}

int main()
{
	test();
	getchar();
	return 0;
}