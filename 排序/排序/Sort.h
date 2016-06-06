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
//��λȡ�з�
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
//���������ڿӷ�
void QuikSort_OP1(int *arr, int start, int end)
{
	SelectMid(arr, start, end);
	if (start >=  end)
		return;
	int key = arr[end];
	int hoop = end;
	int left = start;
	int right = end;

	while (left < right)
	{
		while (right >left && arr[left] < key)
			++left;
		if (right >left)
		{
			arr[hoop] = arr[left];
			hoop = left;
		}
		while (right > left && arr[right] > key)
			--right;
		if (right > left)
		{
			arr[hoop] = arr[right];
			hoop = right;
		}
	}
	arr[hoop] = key;
	
	QuikSort_OP1(arr, start, hoop-1);
	QuikSort_OP1(arr, hoop+1,  end);
}
//�����������������㷨3
void QuikSort_OP2(int *arr, int start, int end)
{
	SelectMid(arr, start, end);
	int  prev = start -1;
	int cur = start;
	while (cur < end)
	{
		while (arr[cur] > arr[end])
			cur++;
		if (cur < end )
			swap(arr[++prev], arr[cur++]);
	}
	swap(arr[end], arr[++prev]);
	QuikSort(arr, start, prev);
	QuikSort(arr, prev, end);
}
//��������ķǵݹ�
void QuikSort_OP3(int *arr, int start, int end)
{

}
//�鲢����
void  _Merge(int *arr, int start, int mid,int end)
{
	int  i = start, j = mid + 1, p = 0;
	//�����ݴ�ռ�
	int *tmp = (int *)malloc((end - start + 1)*sizeof (int));
	//�ϲ��������䲢��tmp������
	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
			tmp[p++] = arr[i++];
		else
			tmp[p++] = arr[j++];
	}
	while (i <= mid)
		tmp[p++] = arr[i++];
	while (j <= end)
		tmp[p++] = arr[j++];
	//��tmp�����ݿ�����ԭ����
	for (i = start, p = 0; p < (end - start + 1); i++, p++)
	{
		arr[i] = tmp[p];
	}
	free(tmp);
}
void MergeSort(int *arr,int start,int end)
{
		int mid = 0;
		if (start<end)
		{
			mid = (start + end) / 2;
			MergeSort(arr, start, mid);
			MergeSort(arr, mid + 1, end);
			_Merge(arr, start, mid, end);
		}
}
//��������
void CountSort(int *arr, int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	int *count = new int[max+1];
	memset(count, 0, 10*sizeof(int));
	for (int i = 0; i <size; i++)
	{
		count[arr[i]]++;
	}
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			cout << i << " ";
			count[i]--;
		}
	}
	cout << endl;
	delete[] count;
}