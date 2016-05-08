#pragma once
#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
#if 0
//���ڴ�����
template<class T>
struct Big
{
	bool operator() (const T& a, const T& b)
	{
		return a > b;
	}
};
//���ڴ���С��
template<class T>
struct sma
{
	bool operator() (const T& a, const T& b)
	{
		return a < b;
	}
};

template <class T, class Com = Big<T> >
class Heap
{
private:
	vector<T> _a;
	Com com;
public:
	Heap()
	{}
	Heap(const T a[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		for (int i = (_a.size() - 2) / 2; i >= 0; --i)
		{
			_AdjustDown(i);
		}
	}
protected:
	void _AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child <=  _a.size()-1)
		{
			if (child + 1 < _a.size() &&com(_a[child+1], _a[child]))
				++child;
			if (com(_a[child], _a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
			
		}
	}
};

void testBig()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[] = { 6, 7, 3, 2, 1, 4 };
	Heap<int> Bighp(arr, 6);
	Heap<int, sma<int> > Sma(arr2, 6);
}
int main()
{
	testBig();
	return 0;
}
#endif

#if 1
//������
void _AdjustDown(int *arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;
		if (arr[child] > arr[parent])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int *arr,int n)
{
	assert(arr);
	assert(n > 0);
	//1.����
	for (int i = (n - 2)/ 2; i >= 0; --i)
	{
		_AdjustDown(arr, i, n);
	}
	//2.����
	/*
		ÿ��������Сn�ķ�Χ���ҳ�ʣ�����ֵĴ�С
	*/
	for (int i = 0; i < n; i++)
	{
		swap(arr[0], arr[n -i- 1]);
		_AdjustDown(arr, 0, n - i - 1);
	}
}

int main()
{
	int arr[] = { 2, 5, 3, 4, 1, 0, 9, 6, 7 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
#endif
