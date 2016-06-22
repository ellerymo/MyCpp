#include"RBTree.h"
void test()
{
	RBTree<int, int> tree;
	int arr[] = { 2, 4, 7, 1, 3, 0, 5, 8, 6, 9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.Insert(arr[i], i);
	}
}
int main()
{
	test();
	getchar();
	return 0;
}