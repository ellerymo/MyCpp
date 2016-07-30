#include<iostream>
using namespace std;
class UnionSet
{
private:
	int *_Set;

public:
	UnionSet(const int& n) :_Set(new int[n+1])
	{
		//�����鼯�е����ݳ�ʼ��Ϊ-1
		for (int i = 0; i < n+1; i++)
		{
			_Set[i] = -1;
		}
	}
	void SetJoinNum(int x, int y)
	{
		//���Ҹ��ڵ㡣
		y = FindRoot(y);
		x = FindRoot(x);
		if (_Set[y] != x && y != x)
		{
			_Set[x] += _Set[y];
			_Set[y] = x;
		}
	}
	int FindRoot(int x)
	{
		int r = x;
		while (_Set[r] > 0)
			r = _Set[r];
		return r;
	}
	int CountRoot(int n)
	{
		int  k = 0;
		for (int i = 1; i < n+1; i++)
		{
			if (_Set[i] < 0)
				++k;
		}
		return k;

	}
};
int FindFriends(int n,int m,int arr[][2])
{
	UnionSet _Set(n);
	for (int i = 0; i < m;i++)
	{
		_Set.SetJoinNum(arr[i][0],arr[i][1]);
	}
	int Ret = _Set.CountRoot(n);
	return Ret;
}
int main()
{
	int ret[][2] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, {1,3} };
	cout <<" ����Ȧ��"<<FindFriends(5, 4, ret) << endl;
	getchar();
	return 0;
	
}