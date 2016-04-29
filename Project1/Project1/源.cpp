#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

#if 0
//String类的复制运算符重载
class CMyString{
public:
	//考虑到一场的安全性我选择使用现代写法
	CMyString& operator=(CMyString str)
	{
		if (&str != this)
			swap(_pData, str._pData);
		return *this;
	}
private:
	char *_pData;
};
#endif

#if 0
//将字符串里的空格替换成20%
char* Inst(char *str)
{
	char *cur = str;
	size_t Blank = 0;
	while (*cur != '\0')
	{
		if (*cur == ' ')
			Blank++;
		cur++;
	}
	char *newPtr = cur + (Blank * 2);
	while (1)
	{
		if (*cur == ' ')
		{
			*newPtr-- = '0';
			*newPtr-- = '2';
			*newPtr = '%';
		}
		else
			*newPtr = *cur;
		if (cur == str)
			return str;
		newPtr--;
		cur--;
	}
}
int main()
{
	char str[25] = { "We are bits!" };
	cout << Inst(str) << endl;
	getchar();
	return 0;

}
#endif
#if 0
//两个栈实现队列
template<class T>
class Myqueque
{
private:
	stack<T> s1;
	stack<T> s2;
public:
	Myqueque()
	{}
	~Myqueque()
	{
		while (!s1.empty())
		{
			while (!s2.empty())
			{
				s2.pop();
			}
			s1.pop();
		}
	}
	void Push(const T& data)
	{
		s1.push(data);
	}
	void Pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
};
int main()
{
	Myqueque<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Pop();
	q1.Pop();
	getchar();
	return 0;
}
#endif
#if 0
int findInYangs(int * arr, size_t Row, size_t Col,int key)
{
	size_t MyRow = 0;
	size_t MyCol = Col - 1;
	while (MyCol <= Col-1 && MyRow <= Row-1)
	{
		if (arr[MyRow*Col + MyCol] == key)
			return arr[MyRow*Col + MyCol];
		else if (arr[MyRow*Col + MyCol] > key)
			MyCol--;
		else if (arr[MyRow*Col + MyCol] < key)
			MyRow++;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 2, 4, 5, 3, 5, 7 };
	cout << findInYangs(arr, 3, 3, 8) << endl;
	getchar();
	return 0;
}
#endif

#if 1
//单例模式
class CSingleton
{
private:
	CSingleton() //构造函数是私有的
	{
	}
public:
	static CSingleton * GetInstance()
	{
		static CSingleton *m_pInstance;
		if (m_pInstance == NULL) //判断是否第一次调用
			m_pInstance = new CSingleton();
		return m_pInstance;
	}
};

int main()
{
	CSingleton::GetInstance();
	getchar();
	return 0;
}
#endif