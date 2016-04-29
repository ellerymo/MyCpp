#include<iostream>
#include<cassert>
using namespace std;
#if 0
/*
	������1���ҳ�������ֻ��һ��û���ظ���Ԫ��
	����˼·������������±���ʵ�ʱ�临�ӶȽ�ΪO(1)��������������ʵ�ּ򵥵Ĺ�ϣ��
			  �����±꣨key�� ����Ԫ�أ�value��
			  char���ַ������ܺ��е�Ԫ������:256 -> ��ϣ����
			  �γɹ�ϣ����������Ŀ�����飻������ϣ������Ӧλ��++
			  Ѱ��Ŀ���ַ�����������Ŀ�����飻ֻҪĳһ���value��Ϊ1�ͷ���
	**ע�⣺���ַ������ж�
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
	cout << "ֻ������һ�ε��ַ��ǣ�" << c << endl;
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
		cout << "Ŀ�����ֲ��������" << endl;
	cout << "���ҵ����ֵ��±��ǣ�" << index << endl;
	getchar();
	return 0;
}
#endif
