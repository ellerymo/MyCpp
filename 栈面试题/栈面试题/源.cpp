#include<iostream>
#include<stack>
using namespace std;
#if 0
//两个栈实现一个队列
template<class T>
class MyQue
{
private:
	stack<int> st1;
	stack<int> st2;
public:
	void pushback(const T& data)
	{
		st1.push(data);
	}
	T popfront()
	{
		if (st1.empty()&&st2.empty())
		{
			cout << "This Que is empty!" << endl;
			return -100;
		}
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		T ret = st2.top();
		st2.pop();
		return ret;
	}
};
int main()
{
	MyQue<int> q;
	q.pushback(1);
	q.pushback(2);
	q.pushback(3);
	q.pushback(4);
	cout << q.popfront() << endl;
	cout << q.popfront() << endl;
	cout << q.popfront() << endl;
	cout << q.popfront() << endl;
	cout << q.popfront() << endl;
	getchar();
	return 0;
}
#endif

#if 0
//动态增长的栈实现查找最小元素时间复杂度是O（1）
#define DEFUALT 3 
template <class T>
class Mystack
{
private:
	T* _base;
	T* _top;
	size_t _capacity;
	size_t _size;
public:
	Mystack() :_base(new T[DEFUALT]), _capacity(DEFUALT), _top(NULL), _size(0)
	{
	}
	void push(const T& data)
	{
		Check();
		if (_top == NULL)
		{
			_top = _base;
			*_top = data;
			_top++;
			*_top = data;
		}
		else
		{
			T Min = data;
			if (data < *_top)
				Min = data;
			else
				Min = *_top;
			_top++;
			*_top = data;
			_top++;
			*_top = Min;
		}
		_size += 2;
	}
	T pop()
	{
		  T ret = *_top;
		if (_top != NULL )
		{
			
			if (_size % 2 == 0)
			{
				_top--;
				ret = *_top;
				_top--;
				_size -= 2;
			}
			else
			{
				ret = *_top;
				_top--;
				_size--;
			}
		}
		else
		{
			cout << "empty!" << endl;
		}
		return ret;
	}
	T min()
	{
		T ret = *_top;
		return ret;
	}
private:
	void Check()
	{
		if (_size == _capacity)
		{
			_capacity *= 2;
			T *tmp = new T[_capacity];
			size_t count = _size;
			_base = tmp;
			while (count--)
			{
				*tmp = *_top;
				T *del = _top;
				_top ++;
				delete del;
			}
			_top = tmp;
		}
	}
};
int main()
{
	Mystack<int> ms;
	ms.push(5);
	ms.push(4);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	cout << ms.min() << endl;
	ms.pop();
	cout << ms.min() << endl;
	ms.pop();
	cout << ms.min() << endl;
	ms.pop(); 
	cout << ms.min() << endl;
	ms.pop();
	cout << ms.min() << endl;
	getchar();
	return 0;
}

#endif

#if 0
int main()
{
	getchar();
	return 0;
}

#endif
#if 0
int main()
{
	getchar();
	return 0;
}

#endif
#if 0
int main()
{
	getchar();
	return 0;
}

#endif