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
	cout << "ǰ�����" << endl;
	trOp.PreOrder();
	cout << "�������" << endl;
	trOp.InOrder();
	cout << "�������" << endl;
	trOp.PostOrder();
	cout << "�ǵݹ�ǰ�����" << endl;
	trOp.Pre();
	cout << "�ǵݹ��������" << endl;
	trOp.In();
	cout << "�ǵݹ�������" << endl;
	trOp.Post();

}
int main()
{
	testCopy();
	getchar();
	return 0;
}