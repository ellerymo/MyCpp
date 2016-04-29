#include<iostream>
#include<cassert>
using namespace std;
#if 0
/*
	面试题1：找出数组里只第一个没有重复的元素
	解题思路：鉴于数组的下标访问的时间复杂度仅为O(1)，我们利用数组实现简单的哈希表
			  数组下标（key） 数组元素（value）
			  char型字符串可能含有的元素种类:256 -> 哈希表长度
			  形成哈希表：遍历对象：目标数组；并将哈希表中相应位置++
			  寻找目标字符：遍历对象：目标数组；只要某一项的value仅为1就返回
	**注意：空字符串的判断
*/
char FindFirstOnceElem(char *str)
{
	assert(str);
	const int HashLen = 256;
	char hash[HashLen] = { '0' };
	char *cur = str;
	while (*cur != '\0')
	{
		hash[(*cur)]++;
		cur++;
	}
	cur = str;
	while (*cur != '\0')
	{
		if (hash[(*cur)] == 1)
			return *cur;
		cur++;
	}
	return '\0';
}
int main()
{
	char *str = "abaeffec";
	char c = FindFirstOnceElem(str);
	cout << "只出现了一次的字符是：" << c << endl;
	getchar();
	return 0;
}
#endif
#if 1
int FindTheNumInYang(int *str,int col,int row,int key)
{
	assert(str&&row>0&&col>0);
	int my_row = row;
	int my_col = col;
	while (row > 0 &&str[my_row*my_col-1]>key)
	{
		my_row--;
	}
	if (row <= 0)
		return -1;
	for (int i = 0; i < col - 1; i++)
	{
		if (str[my_row*my_col + i] == key)
			return my_row*my_col + i;
	}
	return -1;
}
int main()
{
	int arr[4][4] = { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 5, 6, 7, 8 }, { 10, 11, 12, 13 } };
	int index = FindTheNumInYang(&arr[0][0],4,4,3);
	if (index == -1)
		cout << "目标数字不再数组里！" << endl;
	cout << "查找的数字的下标是：" << index << endl;
	getchar();
	return 0;
}
#endif
