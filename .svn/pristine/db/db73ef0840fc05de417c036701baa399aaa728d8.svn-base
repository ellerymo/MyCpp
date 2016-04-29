#include<iostream>
using namespace std;
int n = 0;
int book[10];
int a[10];
void dfs(int step)
{
	//step表示已经进行到了第几步
	if (step > n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i];
		}
		cout << endl;
		//递归在此处跳出
		return;
	}
	//如果我们还没有满足边界判断条件则尝试每种可能
	for (int i = 1; i <= n; i++)
	{
		//book[i]表示数字i的状态，如果为0则表示还没被使用，所以我们可以使用它
		if (book[i] == 0)
		{
			//我们将这一位放置还没有被使用的数字i
			a[step] = i;
			//将数字状态置成：已使用
			book[i] = 1;
			//继续放置下一位
			dfs(step + 1);
			//当跳出递归时，我们必须将每一位的状态修改成没有使用
			book[i] = 0;
		}
	}
	return;
}
int main()
{
	n = 2;
	dfs(1);
	getchar();
	return 0;
}