#include "Sort.h"
void testInsert()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
}
void testShell()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
}
void testSelect()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
}
void testHeap()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
}
void testBubble()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
}

void testMerge()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	print(arr, sizeof(arr) / sizeof(arr[0]));
}
void testCount()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
//	print(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	testCount();
	getchar();
	return 0;
}
