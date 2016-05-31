#include <iostream>
using namespace std;
//ֱ�Ӳ�������
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
		//�˴������Ѿ�������Χ������Ҫ++
		if (tmp < arr[++end])
			arr[end] = tmp;
	}
}

//ϣ������
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

//ѡ������
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

//������
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

//ð������
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

//��������
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
	//���ñȽϵĻ�׼ֵ
	int base = arr[left];
	//һ�ν�������ֱ��������ͣ
	while (i != j)
	{
		//�Ҵ��ұ߿�ʼС��keyֵ����
		while (arr[j] >= base && i < j)
			j--;
		//�������ҵ�һ������keyֵ����
		while (arr[i] <= base && i < j)
			i++;
	
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	//��keyֵ��λ
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