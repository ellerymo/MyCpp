#include"SList.h"
ostream& operator <<(ostream &os, SList& s)
{
	Node *cur = s._head;
	while (cur != NULL)
	{
		os << cur->_data << "->";
		cur = cur->_next;
	}
	os << "Over" << endl;
	return os;
}
void SList::PushBack(DataType d)
{
	Node * newNode = new Node(d);
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

void SList::PopBack()
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
		Node *cur = _head;
		while ((cur->_next)->_next != NULL)
		{
			cur = cur->_next;
		}
		delete _tail;
		_tail = cur;
		_tail->_next = NULL;
	}
}

void SList::PushFront(DataType d)
{
	Node * newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	else
	{
		newNode->_next = _head;
		_head = newNode;
	}
}

void SList::PopFront()
{
	if (_head == NULL)
	{
		return;
	}
	if (_head == _tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		Node *del = _head;
		_head = _head->_next;
		delete del;
		del = NULL;
	}
}

void SList::insert(int pos, DataType d)
{
	Node * newNode = new Node(d);
	Node *cur = _head;
	if (cur == NULL)
	{
		_head = newNode;
		_tail = newNode;
		return;
	}
	if (pos == 0)
	{
		newNode->_next = _head;
		_head = newNode;
		return;
	}
	while (pos != 0)
	{
		if (cur->_next == NULL)
			break;
		cur = cur->_next;
		pos--;
	}
	if (cur != _tail)
	{
		newNode->_next = cur->_next;
		cur->_next = newNode;
	}
	else if (cur == _tail)
	{
		_tail->_next = newNode;
		_tail = newNode;
	}
}

int SList::Find(DataType d)
{
	int cout = 0;
	if (_head == NULL)
		return -1;
	Node *cur = _head;
	while (cur && cur->_data != d)
	{
		cur = cur->_next;
		cout++;
	}
	if (cur != NULL)
		return cout;
	else
		return -1;
}

void SList::Remove(DataType d)
{
	if (_head == NULL)
		return;
	Node *cur = _head;
	while (cur->_next && ((cur->_next)->_data) != d)
	{
		cur = cur->_next;
	}
	if ((cur->_next)->_data == d)
	{
		if (cur->_next != _tail)
		{
			Node *tmp = cur->_next;
			cur->_next = tmp->_next;
			delete tmp;
			tmp = NULL;
		}
		else
		{
			delete _tail;
			_tail = cur;
			cur->_next = NULL;
		}
	}
}

void SList::RemoveAll(DataType d)
{
	while (Find(d) != -1)
	{
		Remove(d);
	}
}

void SList::sort()
{
	if (_head == NULL)
		return;
	Node *cur = _head;
	/*int count = getLen();
	cur = _head;
	for (int i = 0; i < count-1; i++)
	{
		Node * p = cur;
		for (int j = 0; j < count - i-1; j++)
		{
			if (p->_data > (p->_next)->_data)
			{
				swap(p->_data,(p->_next)->_data);
			}
			p = p->_next;
		}
	}*/
	Node *end = NULL;
	while (cur != end)
	{
		while (cur->_next&&cur->_next != end)
		{
			if (cur->_data > (cur->_next)->_data)
				swap(cur->_data, (cur->_next)->_data);
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}

void SList::Reverse()
{
	if (_head == NULL)
	{
		return;
	}
	else
	{
		SList list;
		Node *cur = _head;
		while (cur != NULL)
		{
			list.PushFront(cur ->_data);
			cur = cur->_next;
		}
		swap(_tail ,list._tail);
		swap(_head , list._head);
	}
}

int SList::getLen()
{
	Node *cur = _head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

//删除非尾节点-----1
void SList::EraseNotTail(Node *pos)
{
	DataType tmp = (pos->_next)->_data;
	(pos->_next)->_data = pos->_data;
	pos->_data = tmp;
	Node *del = pos->_next;
	pos->_next = del->_next;
	delete del;
	del = NULL;
}



// 在当前节点前插入一个数据x-----5
void SList::InsertFrontNode(Node *pos, DataType x)
{
	Node *newNode = new Node(x);
	newNode->_next = pos->_next;
	pos->_next = newNode;
	DataType tmp = pos->_data;
	pos->_data = newNode->_data;
	newNode->_data = tmp;
}

//合并两个有序列表-----6
void SList::Merge(Node* l1, Node* l2)
{
	Node *newNode = NULL;
	if (l1 == NULL || l2 == NULL)
		return;
	if (l1->_data < l2->_data)
	{
		newNode = l1;
		l1=l1->_next;
	}
	else if (l2->_data <= l1->_data)
	{
		newNode = l2;
		l2 = l2->_next;
	}
	Node **cur = &(newNode->_next);
	while (l1&&l2)
	{
		if (l1->_data < l2->_data)
		{
			*cur = l1;
			l1 = l1->_next;
		}
		else if (l2->_data <= l1->_data)
		{
			*cur = l2;        
			l2 = l2->_next;
		 }
		cur = &((*cur)->_next);
	}
	if (l1 == NULL)
		*cur = l2;
	else
		*cur = l1;
	_head = newNode;

}

//查找链表的中间节点---7
Node* SList::FindMidNode()
{
	Node * fast=_head;
	Node *slow = _head;
	if (fast == NULL)
		return NULL;
	while (fast->_next)
	{
		slow = slow->_next;
		fast = (fast->_next)->_next;
	}
	return slow;
}

// 删除单链表的倒数第k个节点(k > 1 && k < 链表的总长度)----9
// 时间复杂度O(N)
void SList::DelKNode(int k)
{
	Node * fast = _head;
	Node *slow = _head;
	if (fast == NULL)
		return;
	while (k-- && fast)
	{
		fast = fast->_next;
	}
	while (fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	Node *del = slow->_next;
	slow->_next = del->_next;
	delete del;
	del = NULL;
}

// 【链表带环问题】-----10
// 判断链表是否带环, 若链表带环则求环的长度和相遇节点，不带环返回-1
Node* SList::CheckCycle()
{
	Node * fast = _head;
	Node * slow  = _head;
	if (fast == NULL)
		return NULL;
	do
	{
		slow = slow->_next;
		fast = (fast->_next)->_next;
	} while ((fast != slow) && fast->_next);
	if (fast == slow)
		return fast;
}
int SList::GetCircleLength(Node* meet)
{
	Node *cur = meet->_next;
	int count = 1;
	while (meet != cur)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

Node* SList::GetCycleEntryNode(Node* meetNode)
{
	Node *Newmeet = meetNode;
	Node *entry = _head;
	while (entry != Newmeet)
	{
		entry = entry->_next;
		Newmeet = Newmeet->_next;
	}
	return entry;
}

// 【链表相交问题】
int CheckCross(Node* list1, Node* list2)
{
	Node *ptr1 = list1;
	Node *ptr2 = list2;
	while (ptr1 == NULL || ptr2 == NULL)
		return -1;
	while (ptr1->_next)
	{
		ptr1 = ptr1->_next;
	}
	while (ptr2->_next)
	{
		ptr2 = ptr2->_next;
	}
	if (ptr1 == ptr2)
		return 0;
	else
		return -1;
}
