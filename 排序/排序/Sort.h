#include <iostream>
#include<stack>
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
//三位取中法
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
	while (i < j)
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
	if (arr[i] < arr[left])
	{
		swap(arr[left], arr[i]);
		QuikSort(arr, left, i - 1);
		QuikSort(arr, i + 1, right);
	}
	else
	{
		QuikSort(arr, left + 1,right);
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
//快速排序挖坑法
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
//快速排序难以理解的算法3
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
//快速排序的非递归
void QuikSort_OP3(int *arr, int start, int end)
{
	stack<int> st;
	st.push(end);
	st.push(start);
	 while ( !st.empty())
	{
		int left = st.top();
		st.pop();
		int right = st.top();
		int key = right;
		st.pop();
		int my_start = left;
		int my_end = right;
		while (left < right)
		{
			while (left < right&&arr[left] <= arr[key])
				++left;
			while (left < right&&arr[right] >= arr[key])
				--right;
			if (arr[right] < arr[left])
				swap(arr[left],arr[right]);
		}
		if (arr[right] > arr[key])
		{
			swap(arr[right], arr[key]);
			if (my_end - right - 1 >= 1 && right != 0)
			{
				st.push(right-1);
				st.push(my_start);
			}
			if (my_end - (right + 1) >= 1)
			{
				st.push(my_end);
				st.push(right+1);
			}
		}
		else
		{
			if (my_end - 1 - my_start >= 1)
			{
				st.push(key - 1);
				st.push(my_start);
			}
		}
	}	
}
//归并排序
void  _Merge(int *arr, int start, int mid,int end)
{
	int  i = start, j = mid + 1, p = 0;
	//申请暂存空间
	int *tmp = (int *)malloc((end - start + 1)*sizeof (int));
	//合并两个区间并在tmp里排序
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
	//将tmp的内容拷贝回原数组
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
//计数排序
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
//基数排序
void LSDSort(int *arr,int n)
{
	int base = 10;
	int base2 = 1;
	int count[10] = { 0 };
	int start[10] = { 0 };
	int *bucket = new int[n];
	//找出最大的数计算需要统计多少位
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	int digit = 0;
	while (max)
	{
		max /= 10;
		digit++;
	}
	while (digit)
	{
		//构造记录每个尾数有几个数字
		for (int i = 0; i < n; i++)
		{
			count[(arr[i] /base2) % base]++;
		}
		//构造存储开始位置的数组
		for (int i = 1; i < 10; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		
		for (int i = 0; i < n; i++)
		{	
			int num = arr[i];
			num = (num/base2 )% base;
			bucket[start[num]++] =arr[i];
		}
		memcpy(arr, bucket, sizeof(int)*n);
		memset(start, 0, 10*sizeof(int));
		memset(count, 0, 10 * sizeof(int));
		base2 *= 10;
		digit --;
	}
}