#include"SList.h"
void test1()
{
	SList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	cout << list1;
	list1.PopBack();
	list1.PopBack();
	list1.PopBack();
	list1.PopBack();
	cout << list1;
	list1.PushFront(1);
	list1.PushFront(2);
	list1.PushFront(3);
	list1.PushFront(4);
	cout << list1;
	list1.PopFront();
	list1.PopFront();
	list1.PopFront();
	list1.PopFront();
	cout << list1;

}
void test2()
{
	SList list2;
	list2.insert(0, 2);
	list2.insert(1, 1);
	list2.insert(0, 3);
	cout << list2;
	cout << list2.Find(4) << endl;
}

void test3()
{
	SList list3;
	list3.PushBack(1);
	list3.PushBack(2);
	list3.PushBack(3);
	list3.PushBack(4);
	list3.Remove(3);
	cout << list3;
	list3.PushBack(4);
	list3.PushBack(2);
	list3.PushBack(6);
	list3.PushBack(4);
	cout << list3;
	list3.RemoveAll(4);
	cout << list3;
}

void test4()
{
	SList list4;
	list4.PushBack(5);
	list4.PushBack(2);
	list4.PushBack(4);
	list4.PushBack(3);
	list4.PushBack(1);
	list4.PushBack(7);
	list4.PushBack(6);
	list4.PushBack(9);
	list4.PushBack(8);
	list4.sort();
	cout << list4;
	list4.Reverse();
	cout << list4;
	list4.getLen();
}

void test5()
{
	SList list4;
	list4.PushBack(5);
	list4.PushBack(2);
	list4.PushBack(4);
	list4.PushBack(3);
	list4.PushBack(1);
	list4.PushBack(7);
	list4.PushBack(6);
	list4.PushBack(9);
	list4.PushBack(8); 
	list4.EraseNotTail(list4.GetHead());
	cout << list4;
	list4.InsertFrontNode(list4.GetTail(),5);
	cout << list4;
	cout <<(list4.FindMidNode())->_data << endl;
	list4.DelKNode(2);
	cout << list4;
}
void test6()
{
	SList list1;
	list1.PushBack(1);
	list1.PushBack(4);
	list1.PushBack(7);
	list1.PushBack(9);
	cout << list1;
	SList list2;
	list2.PushBack(2);
	list2.PushBack(3);
	list2.PushBack(5);
	list2.PushBack(8);
	cout << list2;
	SList list3;
	list3.Merge(list1.GetHead(), list2.GetHead());
	cout << list3;
}
void test7()
{
	SList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.Circle();
	cout << (list.CheckCycle())->_data << endl;
	cout << (list.GetCycleEntryNode(list.CheckCycle()))->_data << endl;
	cout << (list.GetCircleLength(list.CheckCycle())) << endl;
}

void test8()
{
	SList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.PushBack(5);
	list1.PushBack(6);
	SList list2;
	list2.PushBack(4);
	list2.PushBack(5);
	list2.PushBack(6);
	Node *p = list2.GetTail();
	p->_next = list1.GetHead();
	cout << CheckCross(list1.GetHead(), list2.GetHead()) << endl;
}
int main()
{
	test4();
	getchar();
	return 0;
}