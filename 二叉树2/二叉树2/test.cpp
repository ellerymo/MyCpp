#include"Tree.h"
void testCreate()
{
	int arr[] = { 1, 2, 3, '#', '#', '#', 4, 5, 6};
	Tree tr(arr, sizeof(arr) / sizeof(arr[0]), '#');

}
void testCopy()
{
	int arr[] = { 1, 2, 3, '#', '#', '#', 4, 5, 6 };
	Tree tr(arr, sizeof(arr) / sizeof(arr[0]), '#');
	Tree trCopy(tr);
	int arr2[] = { 1, 2, 3, '#', '#', '#', 4, 5,'#', 6 };
	Tree trOp(arr2, sizeof(arr2) / sizeof(arr2[0]), '#');
	trOp = tr;
	cout << "前序遍历" << endl;
	trOp.PreOrder();
	cout << "中序遍历" << endl;
	trOp.InOrder();
	cout << "后序遍历" << endl;
	trOp.PostOrder();
	cout << "非递归前序遍历" << endl;
	trOp.Pre();
	cout << "非递归中序遍历" << endl;
	trOp.In();
	cout << "非递归后序遍历" << endl;
	trOp.Post();

}
int main()
{
	testCopy();
	getchar();
	return 0;
}