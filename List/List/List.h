#pragma once
#include<iostream>
using namespace std;
template<class T>
struct ListNode
{
	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _data;

	ListNode(const T& data = T())
		:_data(data), _next(NULL), _prev(NULL)
	{}
};
template<class T, class Pon, class Ref>
struct Iterator
{
	ListNode<T>*  _node;

	Iterator(ListNode<T> *node) :_node(node)
	{}

	Ref operator *()
	{
		return (_node->_data);
	}
	Iterator<T, Pon, Ref> operator++()
	{
		_node = _node->_next;
		return (*this);
	}
	Iterator<T, Pon, Ref> operator--()
	{
		_node = _node->_prev;
		return (*this);
	}
	bool operator !=(Iterator<T, Pon, Ref> it)
	{
		return _node != it._node;
	}
	bool operator==(Iterator<T, Pon, Ref> it)
	{
		return _node == it._node;
	}
	Iterator<T, Pon, Ref> operator++( int )
	{
		ListNode<T>* prev = _node;
		_node = _node->_next;
		
		return Iterator<T,Pon,Ref> (prev);
	}
	Iterator<T, Pon, Ref> operator--(int)
	{
		ListNode<T>* prev = _node;
		_node = _node->_prev;

		return Iterator<T, Pon, Ref>(prev);
	}
	Iterator<T, Pon, Ref>&  operator= (const Iterator<T, Pon, Ref> _it)
	{
		_node = _it._node;
		return *this;
	}
};
template<class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Iterator<T, T*, T&> _Iterator;
private:
	//_head不存储数据仅作为迭代器判断位置使用
	Node * _head;
public:
	List() 
	{
		_head = new ListNode<T>;
		_head->_next = _head;
		_head->_prev = _head;
	}
	//前插
	void Insert(const T& data, Iterator<T, T*, T&> it)
	{
		Node *cur = it._node;
		Node *prev = (it._node)->_prev;
		Node *newNode = new Node(data);
		
		newNode->_next = cur;
		cur->_prev = newNode;

		prev->_next = newNode;
		newNode->_prev = prev;
	}
	Iterator<T, T*, T&> erase(Iterator<T, T*, T&> it)
	{
		Node*del = it._node;
		Node*prev = (it._node)->_prev;
		Node*next = (it._node)->_next;

		prev->_next = next;
		next->_prev = prev;
		delete del;
		it._node = next;
		return it;
	}
	void PushBack(const T& data)
	{
		Insert(data, End());
	}
	void PopBack()
	{
		erase(_head->_prev);
	}
	void PushFront(const T& data)
	{
		Insert(_head->_next);
	}
	void PopFront()
	{
		erase(_head->_next);
	}

	Iterator<T, T*, T&> Begin()
	{
		return  Iterator<T, T*, T&>(_head->_next);
	}

	Iterator<T, T*, T&> End()
	{
		return Iterator<T,T*,T&>(_head);
	}
};
