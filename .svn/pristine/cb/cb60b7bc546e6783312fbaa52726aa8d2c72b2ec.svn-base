#pragma once
#include<iostream>
#include<cassert>
enum Type
{
	VALUE,
	SUBLIST,
	HEAD,
};
struct GenNode
{

	Type _type;
	GenNode *_next;

	char _value;
	GenNode *_sublist;

	GenNode(Type type = HEAD, char value = 0)
		:_next(NULL), _type(type)
	{
		if (type == VALUE)
			_value = value;
		else if (type == SUBLIST)
			_sublist = NULL;
	}
	
};

class GenList
{
public:
	GenList() :_head(new GenNode(HEAD))
	{}
	GenList(const char *sub)
	{
		_head = _CreateList(sub);
	}
	GenList(const GenList&glist)
	{
		_head = _Copy(glist._head);
	}
	void Print()
	{
		using namespace std;
		GenNode *cur = _head;
		if (_head == NULL)
			return;
		if (_head->_next == NULL)
			return;
		cout << "(";
		while (1)
		{	
			
		    if (cur == NULL)
			{
				cout << ")";
				return;
			}
			else if (cur->_type == HEAD)
			{
				cur = cur->_next;
				continue;
			}
			else if (cur->_type == SUBLIST)
			{
				GenList sub;
				sub._head = cur->_sublist;
				sub.Print();
				cur = cur->_next;
				if (cur)
					cout << ",";
				continue;
			}
		
			else if (cur->_type == VALUE)
			{
				
				cout << cur->_value;
				cur = cur->_next;
				if (cur == NULL)
					continue;
				cout << ",";
			}	

		}
	}
	int Depth()
	{
		int deep = 0;
		if (_head != NULL)
			deep = 1;
		else
			return 0;
		GenNode *cur = _head;
		while (1)
		{
			if (cur == NULL)
			{
				return deep;
			}
			else if (cur->_type == SUBLIST)
			{
				
				GenList sub;
				sub._head = cur->_sublist;
				int ret = sub.Depth();
				if ((ret + 1) >= deep)
					deep = ret + 1;
				cur = cur->_next;
			}
			else if (cur == NULL)
			{
				return deep;
			}
			else
			{
				cur = cur->_next;
			}
			
		}
	}
protected:
	GenNode * _CreateList(const char *& sub)
	{
		++sub;
		GenNode *Head = new GenNode(HEAD);
		GenNode *cur = Head;
		while (*sub)
		{
			if (*sub == '(')
			{
				cur->_next = new GenNode(SUBLIST);
				cur = cur->_next;
				cur->_sublist = _CreateList(sub);
				continue;

			}
			else if (_IsValue(*sub))
			{
				cur->_next = new GenNode(VALUE, *sub);
				cur = cur->_next;
				sub++;
				continue;
			}
			else if (*sub == ')')
			{
				++sub;
				return Head;
			}
			else
			{
				++sub;
				continue;
			}
			assert(false);
		}
	}
	bool _IsValue(const char str)
	{
		if (((str >= '0') && (str <= '9')) ||
			((str >= 'a') && (str <= 'z')) ||
			((str >= 'A') && (str <=  'Z')))
			return true;
		else
			return false;
	}
	GenNode *_Copy(GenNode *head)
	{
		GenNode *newHead = new GenNode((HEAD));
		GenNode *cur1 = head;
		GenNode *cur2 = newHead;
		cur1 = cur1->_next;
		while (cur1)
		{
			if (cur1->_type == VALUE)
			{
				cur2->_next = new GenNode(VALUE, cur1->_value);
				cur2 = cur2->_next;
			}
			else if (cur1->_type == SUBLIST)
			{
				cur2->_next = new GenNode((SUBLIST));
				cur2 = cur2->_next;
				cur2->_sublist = _Copy(cur1);
			}
			cur1 = cur1 ->_next;
		}
		return newHead;
	}
protected:
	GenNode * _head;
};