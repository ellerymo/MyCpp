#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T _data;
	Node<T> *_next;
	Node<T> *_random;
	Node(const T& data) :_data(data), _next(NULL), _random(NULL)
	{}
};
template<class T>
class ComList
{
private:
	Node<T> *_head;
	Node<T> *_tail;
public:
	ComList() :_head(NULL), _tail(NULL)
	{}
	~ComList()
	{
		Node<T> *del = _head;
		if (_head != NULL)
		{
			del = _head;
			_head = _head->_next;
			delete del;
		}
	}
	ComList(const ComList<T>& cl)
	{
		Node<T> *cur = cl._head;
		Node<T> *cur2 ;
		while (cur!=cl._tail)
		{
			cur2 = new Node<T>(cur->_data);
			cur2->_next = cur->_next;
			cur->_next = cur2;
			cur = cur->_next->_next;
		}
		cur2 = new Node<T>(cur->_data);
		cur2->_next = cur->_next;
		cur->_next = cur2;
		_head = cl._head;
		//*******************************************
		cur = _head;
		int count = 1;
		while (cur)
		{
			
			if ((count % 2 == 1) && (cur -> _next != NULL))
			{
				cur->_next->_random = cur->_random->_next;
			}
			cur = cur->_next;
			count++;
			
		}
	}
	void pushback(const T& data)
	{
		Node<T> *newNode = new Node<T>(data);
		if (_head == NULL)
		{
			_head = newNode;
			_tail = newNode;
		}
		else
		{
			_tail->_next = newNode;
			_tail = newNode;
		}
	}
	void MakeComList()
	{
		Node<T> *cur = _head;
		while (cur != _tail)
		{
			cur->_random = cur->_next;
			cur = cur->_next;
		}
	}
	void Print()
	{
		Node<T> *cur = _head;
		cout << "链表:" << endl;
		while (cur)
		{
			cout << cur->_data;
			cur = cur->_next;
		}
		cout << endl;
		cout << "链表的random节点:" << endl;
		cur = _head;
		while (cur != _tail)
		{
			cout << cur->_random->_data;
			cur = cur->_next;
		}
	}
private:
	
};
