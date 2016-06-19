#include"SearchBTree.h"

void test()
{
	SrBTree<int,int> tree;
	int arr[] = { 2, 4, 7, 1, 3, 0, 5, 8, 6, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.Insert(arr[i], i);
	}
	tree.InOrder();
	cout << "Key:" << tree.Find(2)->_key <<" "<< "Value:" << tree.Find(2)->_value << endl;
	tree.Remove(2);
	tree.Remove(3);
	tree.InOrder();
	/*
	tree.Remove(4);
	tree.Remove(5);
	tree.Remove(6);
	tree.Remove(7);
	tree.Remove(8);
	tree.Remove(9);
	tree.Remove(0);
	*/
	//tree.InOrder();
}
int main()
{
	test();
	getchar();
 	return 0;
}