#include <iostream>
using namespace std;
//直接插入排序
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

//希尔排序
void ShellSort(int *arr, int n)
{
	int end = 0;
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && tmp < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int *arr, int n)
{
	int left = 0;
	int right = n - 1;
	int max = 0;
	int min = 0;
	while (left < right)
	{
		for (int i = left; i <= right; i++)
		{
			if (arr[i] > arr[max])
				max = i;
			if (arr[i] < arr[min])
				min = i;
		}
		swap(arr[left], arr[min]);
		if (max == left)
			max = min; 
		swap(arr[right], arr[max]);
		left++;
		right--;
	}
}

//堆排序
void AdjustDown(int *arr,int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *arr, int n)
{
	int index = (n - 2) / 2;
	for (int i = index; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, 0, end);
		--end;
	}
}

//冒泡排序
void BubbleSort(int *arr,int n)
{
	bool chage = false;
	int end = n - 1;
	for (int i = 0; i < n; i++)
	{
		chage = false;
		for (int j = 0; j < end-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				chage = true;
			}
		}
		if (chage = false)
			break;
	}

}

//快速排序
void SelectMid(int *arr,int left,int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		if (arr[left] < arr[mid] && arr[mid] < arr[right])
			swap(arr[left], arr[left]);
		else if (arr[right] < arr[mid])
			swap(arr[left], arr[right]);
	}
	else
	{
		if (arr[mid] > arr[right] && arr[mid] <arr[left])
			swap(arr[left], arr[mid]);
	}
}
void QuikSort(int *arr, int left, int right)
{
	SelectMid(arr, left, right);
	if (right < left)
	{
		return;
	}
	int j = right;
	int i = left;
	//设置比较的基准值
	int base = arr[left];
	//一次交换必须直到相遇即停
	while (i != j)
	{
		//找从右边开始小于key值得数
		while (arr[j] >= base && i < j)
			j--;
		//从左起找第一个大于key值的数
		while (arr[i] <= base && i < j)
			i++;
	
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	//将key值归位
	swap(arr[left], arr[i]);
	QuikSort(arr, left, i - 1);
	QuikSort(arr, i + 1, right);
}

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}