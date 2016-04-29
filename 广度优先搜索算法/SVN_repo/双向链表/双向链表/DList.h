#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node * _next;
	Node * _prev;
	DataType _data;
	Node(DataType d) :_next(NULL), _data(d), _prev(NULL)
	{}
};
class  DList
{
	friend ostream& operator <<(ostream &os, DList& s);
public:
	DList() :_head(NULL), _tail(NULL)
	{}
	DList(const DList & d) :_head(NULL), _tail(NULL)
	{
		Node *cur = d._head;
		while (cur && cur->_next)
		{
			PushBack(cur->_data);
		}
	}
	~DList()
	{
		if (_head != NULL)
		{
			Node *cur = _head;
			while (cur->_next != NULL)
			{
				Node *tmp = cur;
				cur = cur->_next;
				delete tmp;
				tmp = NULL;
			}
			delete cur;
			_head = NULL;
			_tail = NULL;
		}
	}

public:
	void PushBack(DataType d);
	void PopBack();
	void PushFront(DataType d);
	void PopFront();
	void insert(int pos, DataType d);
	int  Find(DataType d);
	void Remove(DataType d);
	void RemoveAll(DataType d);
	void sort();
	void Reverse();
	int  getLen();
private:
	Node *_head;
	Node *_tail;
};

