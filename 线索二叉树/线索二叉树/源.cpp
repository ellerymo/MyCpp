#include"TreadingBinaryTree.h"
void test()
{
	int arr1[] = { 1, 2, 3, '#', '#', 4,'#', '#',5, 6 };
	TreadingBinaryTree<int> b1(arr1, sizeof(arr1) / sizeof(arr1[0]), '#');
	int arr2[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', '#', 6 };
	TreadingBinaryTree<int> b2(arr2, sizeof(arr2) / sizeof(arr2[0]), '#');
	int arr3[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', '#', 6 };
	TreadingBinaryTree<int> b3(arr3, sizeof(arr3) / sizeof(arr3[0]), '#');
	b1.PrevOrderTh();
	b1.PreOrderThd();    
	b2.InOrderTh();
	b2.InOrderThd();
	b3.PostOrderTh();
}

int main()
{
	test();
	getchar();
	return 0;
}