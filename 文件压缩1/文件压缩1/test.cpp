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
	com.Compree("1");
}
void testUnCompress()
{
	FileCompress com;
	com.UnCompress("1");
}
int main()
{
	clock_t  a = clock();
	testCompress();
	clock_t  b = clock();
	cout << "压缩时间：" << (b - a)/1000 <<"s"<< endl;
	clock_t  c = clock();
	testUnCompress();
	clock_t  d = clock();
	cout << "解压时间：" << (d - c)/1000 << "s"<<endl;
	getchar();
	return 0;
}