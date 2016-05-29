#include <iostream>
using namespace std;

void InsertSort(int *arr, int n)
{
	int end = 0;
	int tmp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		end = i;
		tmp = arr[end + 1];
		while (end >= 0 && tmp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		//此处由于已经减出范围所以需要++
		if (tmp < arr[++end])
			arr[end] = tmp;
	}
}
void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 7, 5, 4, 2, 6, 3, 8, 1, 9, 0 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	print(arr, sizeof(arr) / sizeof(arr[0]));
	getchar();
	return 0;
}