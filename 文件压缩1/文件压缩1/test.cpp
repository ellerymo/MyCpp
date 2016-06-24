#include"FileCompress.h"
#include<time.h>
#include<windows.h>

void testHuffman()
{
	int arr[] = { 4, 7, 5, 8, 9, 3, 0, 1 };
	HuffmanTree<int> tree(arr, sizeof(arr) / sizeof(arr[0]), -1);
}
void testCompress()
{
	FileCompress com;
	com.Compree("file.dat");
}
void testUnCompress()
{
	FileCompress com;
	com.UnCompress("file.huff");
}
int main()
{
	int a = clock();
	testCompress();
	int b = clock();
	cout << "压缩时间：" << b - a <<"ms"<< endl;
	int c = clock();
	testUnCompress();
	int d = clock();
	cout << "解压时间：" << d - c << "ms"<<endl;
	getchar();
	return 0;
}