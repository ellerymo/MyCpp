#include<vector>
#include<iostream>
#include<cassert>
using  namespace std;

template<class T >
struct Com
{
	bool operator()(const T a, const T b)
	{
		return a < b;
	}
};

template<class T = int,class Compare = Com<T> >
class Heap
{
private:
	vector<T>  _a;
public:
	Heap()
	{}
	Heap(const T *arr,const int size)
	{
		_create(arr,size);
	}
	void _create(const T*arr, const int size)
	{
		for (int i = 0; i < size; i++)
		{
			_a.push_back(arr[i]);
		}
		int j = (size - 2) / 2;
		for (; j >= 0; j--)
		{
			_AdjustDown(j);
		}
	}
	void push(const T x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	void pop()
	{
		if (_a.size() == 0)
			return;
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}
	T top()
	{
		return _a[0];
	}
	int size()
	{
		return _a.size();
	}
	void _AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if ((child + 1) <  _a.size() && Compare()(_a[child + 1], _a[child]))
				child++;
			if (Compare()(_a[child], _a[parent]))
			{
				swap(_a[parent], _a[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	void _AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (child + 1 < _a.size() && Compare()(_a[child + 1], _a[child]))
				child++;
			if (Compare()(_a[child], _a[parent]))
			{
				swap(_a[parent], _a[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
};