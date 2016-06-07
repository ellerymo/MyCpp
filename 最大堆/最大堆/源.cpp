#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

template < class T >
class MixHeap
{
protected:
	vector<T> _a;
public:
	MixHeap()
	{}
	MixHeap(const T* arr, size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(arr[i]);
		}
		/*
		找到第一个非叶子节点
		堆为完全二叉树，第一个非叶子节点为最后一个节点的父亲
		*/
		size_t FirstParent = (_a.size() - 2) / 2;
		for (int i = FirstParent; i >= 0; i--)
		{
			_AdjustDown(i);
		}
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	void Pop()
	{
		//assert(_a);
		swap(_a[_a.size() - 1], _a[0]);
		_a.pop_back();
		_AdjustDown(0);
	}
private:
	//向下调整
	void _AdjustDown(size_t parent)
	{

		int child = parent * 2 + 1;
		while (child < _a.size())
		{
			if ((child + 1) < _a.size() && _a[child] < _a[child + 1])
				swap(_a[child], _a[child + 1]);
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	void _AdjustUp(size_t child)
	{
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				if (parent == 0)
					break;
				child = parent;
				parent = (child-1) / 2;
			}
		}

	}
};

void test()
{
	int arr[] = { 11, 13, 16, 18, 19, 20 };
	MixHeap<int> heap(arr, sizeof(arr) / sizeof(arr[0]));
	heap.Push(30);
	heap.Pop();
}
int main()
{
	test();
	getchar();
	return 0;
}