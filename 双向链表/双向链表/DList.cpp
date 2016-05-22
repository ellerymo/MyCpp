#include"DList.h"
ostream& operator <<(ostream &os, DList& d)
{
	Node *cur = d._head;
	while (cur != NULL)
	{
		os << cur->_data << "->";
		cur = cur->_next;
	}
	os << "Over" << endl;
	return os;
}
void DList::PushBack(DataType d)
{
	Node *newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}

}

void DList::PopBack()
{
	if (_head == NULL)
		return;
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
	}
}

void DList::PushFront(DataType d)
{
	Node *newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		newNode->_next = _head;
		_head->_prev = newNode;
		_head = newNode;
	}
}

void DList::PopFront()
{
	if (_head == NULL)
		return;
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		
		_head = _head->_next;
		delete _head->_prev;
		_head->_prev = NULL;
	}
}

void DList::insert(int pos, DataType d)
{
	Node *cur = _head;
	if (pos == 0)
	{
		PushFront(d);
		return;
	}
	while (pos -- >0)
	{
		if (cur == NULL)
			return;
		cur = cur->_next;
	}
	(cur->_prev)->_next = cur->_next;
	delete cur;
	cur = NULL;
}

int DList::Find(DataType d)
{
	Node *cur = _head;
	int count = 0;
	while (cur)
	{
		if (cur->_data == d)
			break;
		cur = cur->_next;
		count++;
	}
	if (cur == NULL)
		return -1;
	return count;
}
void DList::Remove(DataType d)
{
	Node *cur = _head;
	int ret = Find(d);
	if (ret == 0)
	{
		PopFront();
		return;
	}
	while (ret--)
	{
		if (cur == NULL)
			return;
		cur = cur->_next;
	}
	if (cur != NULL)
	{
		if (cur == _tail)
		{
			PopBack();
		}
		else
		{
			Node *tmp = cur;
			(cur->_prev)->_next = cur->_next;
			delete tmp;
			tmp = NULL;
		}
	}
}
void DList::RemoveAll(DataType d)
{
	
	while (Find(d) != -1)
	{
		Node *cur = _head;
		Remove(d);
	}

}
void DList::sort()
{
	/*int ret = getLen();
	Node *cur = _head;
	for (int i = 0; i < ret - 1; i++)
	{
		Node * p = cur;
		for (int j = 0; j < ret - 1 - i; j++)
		{
			if (p->_data > (p->_next)->_data)
				swap(p->_data,(p->_next)->_data);
			p = p->_next;
		}
	}*/
	Node *end = NULL;
	Node *cur = _head;
	while (cur != end)
	{
		while (cur->_next && cur->_next != end)
		{
			if (cur->_data > (cur->_next)->_data)
				swap(cur->_data, (cur->_next)->_data);
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}
void DList::Reverse()
{
	int left = 0;
	int Right = getLen() - 1;
	Node * _left = _head;
	Node * _right = _tail;
	while (left < Right)
	{
		swap(_left->_data, _right->_data);
		_left = _left->_next;
		_right = _right->_prev;
		left++;
		Right--;
	}
}
int  DList::getLen()
{
	Node *cur = _head;
	int count = 0;
	while (cur)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

