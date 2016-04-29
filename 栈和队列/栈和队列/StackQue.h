#ifndef __STACKQUE_H__
#define __STACKQUE_H__
#endif
#include<iostream>
#include<string>
template<class T>
class Stack
{
private:
	T *_data;
	size_t _top;
	size_t _capacity;
public:
	Stack() :_data(new T[5]), _capacity(3), _top(0)
	{}
	~Stack()
	{
		if (_top != 0)
			delete[] _data;
	}
public:
	T pop()
	{
		if(_top != 0)
			_top--;
		return _data[_top];
	}
	void push(const T data)
	{
		CheckCapacity();
		_data[_top] = data;
		_top++;
	}
	int GetTop()
	{
		return _top;
	}
	void PopPrint()
	{
		while (_top != 0)
		{
			cout << pop() << "<-";
		}
		cout << "Head" << endl;
	}
private:
	void CheckCapacity()
	{
		if (_top + 1 == _capacity)
		{
			int count = _capacity;
			_capacity = _capacity * 2;
			T *tmp = new T[_capacity];
			for (int i = 0; i < _capacity; i++)
			{
				tmp[i] = _data[i];
			}
			delete[] _data;
			_data = tmp;
		}
	}
};

template <class T>
struct Node
{
	T _data;
	Node *_next;
	Node(T data) :_data(data), _next(NULL)
	{}
};
template<class T>
class Queue
{
private:
	Node<T>* _head;
	Node<T>* _tail;
public:
	Queue() :_head(NULL), _tail(NULL)
	{}
	~Queue()
	{
		while(_head != NULL)
		{
			Pop();
		}
	}
public:
	void push(T data)
	{
		Node<T> *tmp=new Node<T>(data);
		if (_head == NULL)
		{
			_head = tmp;
			_tail = _head;

		}
		else
		{
			_tail->_next = tmp;
			_tail = _tail->_next;
		}
	}
	T Pop()
	{
		if (_head == NULL)
			std::cout << "Que is Empty!" << std::endl;
		else
		{
			Node<T> *tmp = _head;
			T ret = _head->_data;
			_head = _head->_next;
			delete tmp;
			return ret;
		}
	}
	int lenth()
	{
		int count = 0;
		Node<T> *cur = _head;
		while (cur)
		{
			count++;
			cur=cur->_next;
		}
		return count;
	}
};