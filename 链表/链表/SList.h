#pragma once
#include <iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node * _next;
	DataType _data;
	Node(DataType d) :_next(NULL), _data(d)
	{}
};
class  SList
{
	friend ostream& operator <<(ostream &os, SList& s);
public:
	SList() :_head(NULL), _tail(NULL)
	{}
	SList(const SList & s) :_head(NULL), _tail(NULL)
	{
		Node *cur = _head;
		while (cur && cur->_next)
		{
			PushBack(cur->_data);
		}
	}
	~SList()
	{
		if (_head != NULL)
		{
			Node *cur = _head;
			while (cur&&cur->_next)
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
	Node *GetHead()
	{
		return _head;
	}
	Node *GetTail()
	{
		return _tail;
	}
	void Circle()
	{
		_tail->_next = (_head->_next)->_next;
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
	void EraseNotTail(Node *pos);
	void DelNonTailNode(Node *pos);
	void InsertFrontNode(Node *pos, DataType x);
	void Merge(Node* l1, Node* l2);
	Node* FindMidNode();
	void DelKNode( int k);
	Node* CheckCycle();
	int GetCircleLength(Node* meet);
	Node* GetCycleEntryNode(Node* meetNode);

private:
	Node *_head;
	Node *_tail;
};
int CheckCross(Node* list1, Node* list2);
