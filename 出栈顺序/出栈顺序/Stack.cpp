#include<iostream>
#include<stack>
using namespace std;

bool CheckOrderOfOutStack(int *in,int *out,int size)
{
	stack<int> s1;
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		while(s1.top() != out[i])
		{
			s1.push(in[++index]);
		}
		if (s1.top() == out[i])
		{
			s1.pop();
		}
	}
	if (!s1.empty())
		return false;
	else
		return true;
}

int main()
{
	int in[] = { 1, 2, 3, 4, 5 };
	int out[] = { 5, 4, 3, 2, 1 };
	cout<<CheckOrderOfOutStack(in, out, sizeof(in) / sizeof(in[0]))<<endl;
	getchar();
	return 0;
}