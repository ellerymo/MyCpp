#include"SearchBTree.h"

void testRemove()
{
	SrBTree<int,int> tree;
	int arr[] = { 2, 4, 7, 1, 3, 0, 5, 8, 6, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.Insert(arr[i], i);
	}
	tree.InOrder();
	cout << "Key:" << tree.Find(2)->_key <<" "<< "Value:" << tree.Find(2)->_value << endl;
	tree.Remove(3);
	tree.InOrder();
	tree.Remove(4);
	tree.InOrder();
	tree.Remove(5);
	tree.InOrder();
	tree.Remove(6);
	tree.InOrder();
	tree.Remove(7);
	tree.InOrder();
	tree.Remove(8);
	tree.InOrder();
	tree.Remove(9);
	tree.InOrder();
	tree.Remove(0);
	tree.InOrder();
	tree.Remove(1);
	tree.InOrder();
 	tree.Remove(2);
	tree.InOrder();
}
void testR()
{
	SrBTree<int, int> tree;
	int arr[] = { 2, 4, 7, 1, 3, 0, 5, 8, 6, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.InsertR(arr[i], i);
	}
	tree.InOrder();
	cout << "Key:" << tree.FindR(2)->_key << " " << "Value:" << tree.FindR(2)->_value << endl;
	tree.RemoveR(3);
	tree.InOrder();
	tree.RemoveR(4);
	tree.InOrder();
	tree.RemoveR(5);
	tree.InOrder();
	tree.RemoveR(6);
	tree.InOrder();
	tree.RemoveR(7);
	tree.InOrder();
	tree.RemoveR(8);
	tree.InOrder();
	tree.RemoveR(9);
	tree.InOrder();
	tree.RemoveR(0);
	tree.InOrder();
	tree.RemoveR(1);
	tree.InOrder();
	tree.RemoveR(5);
	tree.InOrder();
}
int main()
{
	testRemove();
	getchar();
 	return 0;
}