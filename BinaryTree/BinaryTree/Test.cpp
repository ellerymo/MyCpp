#include"BinaryTree.h"
void test()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 2,'#','#',6};
	BinaryTree b1(arr,sizeof(arr)/sizeof(arr[0]),'#');
	BinaryTree b2(b1);
	BinaryTree b3 = b1;
	cout << "PrevOrder:";
	b3.PrevOrder();
	cout << "InOrder:";
	b3.InOrder();
	cout << "PostOrder:";
	b3.PostOrder();
	cout <<"Size:"<< b3.Size() << endl;
	cout << "Depth:"<<b3.Depth() << endl;
	cout << "LeafSize:"<<b3.LeafSize() << endl;
	b3.LevelOrder();
	b3.PrevOrderNoInDegrees();
	b3.InOrderNoInDegrees();
	b3.PostOrderNoInDegrees();
	cout << "GetNodeInK:" << b3.NodeInklevel(3) << endl;
	cout<<b3.Find(3)<<endl;
	cout << b3.Find(9) << endl;

}
void test2()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', '#', 6 };
	BinaryTree b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b1.LevelOrder();
}
void test3()
{
	int arr[] = { 1, 2, '#', 3, '#', '#', 4, 1, '#', '#', 6 };
	BinaryTree b1(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b1.FindIt(6);
}
void test4()
{
	int arr[] = { 10, 8, 6, '#', '#', 9, '#', '#', 12, 11, '#', '#', 13 };
	BinaryTree b(arr, sizeof(arr) / sizeof(arr[0]), '#');
	b.Change();
}
int main()
{
	test4();
	getchar();
	return 0;
}