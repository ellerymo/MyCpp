#include"FileCompress.h"


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
int main()
{
	testCompress();
	return 0;
}