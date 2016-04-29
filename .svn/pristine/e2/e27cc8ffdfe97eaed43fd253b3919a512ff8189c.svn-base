#include<iostream>
using namespace std;
void order(int *str,int left, int right)
{
	if (right < left)
	{
		return;
	}
	int j = right;
	int i = left;
	//设置比较的基准值
	int base = str[left];
	//一次交换必须直到相遇即停
	while (i != j)
	{
		while (str[j] >= base && i < j)
			j--;
		while (str[i] <= base && i < j)
			i++;
		if (i < j)
		{
			swap(str[i], str[j]);
		}
	}
	swap(str[left],str[i]);
	order(str,left, i - 1);
	order(str, i+1, right);
}
int main()
{
	int str[] = { 3, 5, 1, 4, 7, 2, 0, 9 };
	int size = sizeof(str) / sizeof(str[0]) - 1;
	order(str, 0, size);
	for (int i = 0; i <= size; i++)
	{
		cout << str[i] << "->";
	}
	cout << "over" << endl;
	getchar();
	return 0;
}