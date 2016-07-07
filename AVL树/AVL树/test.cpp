#include"AVLTree.h"
void test()
{
	AVLTree<int, int> tree;
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.Insert(arr[i], i);
	}
	cout<<"IsBalance? "<<tree.IsBalance()<<endl;
}
int main()
{
	test();
	getchar();
	return 0;
}