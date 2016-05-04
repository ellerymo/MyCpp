#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct Node
{
	T _data;
	Node<T> *_next;
	Node<T> *_prev;
	Node(const T& data)
		:_data(data), _next(NULL), _prev(NULL)
	{}

};
template <typename T>
class Dlist
{
public:
	Dlist() :_head(NULL), _tail(NULL)
	{}
	~Dlist()
	{
		if (typeid(T) != typeid(string))
		{
			if (_head && _head != _tail)
			{
				Node<T> *del = _head;
				_head = _head->_next;
				delete[] del;
				del = NULL;
			}
			delete[] _head;
		}
		_head = NULL;
		_tail = NULL;
	}
	void Display() const
	{
		Node<T> *cur = _head;
		while (cur != NULL)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout << "over" << endl;
	}
public:
	void PushBack(const T& data);
	void PopBack();
	void PushFront(const T& data);
	void PopFront();
	void sort();
	void Insert(int pos, T data);
	void Remove(T data);
	void RemoveAll(T data);
	void Reverse();
	bool find(T data);

private:
	Node<T> *_head;
	Node<T> *_tail;

};
template <typename T>
void Dlist<T>::PushBack(const T& data)
{
	Node<T> *newNode = new Node<T>(data);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
		return;
	}
	if (_head == _tail)
	{
		_head->_next = newNode;
		_tail = newNode;
		newNode->_prev = _head;
		return;
	}
	_tail->_next = newNode;
	newNode->_prev = _tail;
	_tail = newNode;
}
template <typename T>
void Dlist<T>::PopBack()
{
	Node<T> *cur = _head;
	if (_head == NULL)
	{
		return;
	}
	if (_head == _tail)
	{
		if (typeid(T) != typeid(string))
			delete[] _head;
		_tail = NULL;
		_head = NULL;
		return;
	}
	Node<T> *del = _tail;
	_tail = _tail->_prev;
	if (typeid(T) != typeid(string))
		delete[] del;
	del = NULL;
}
template <typename T>
void Dlist<T>::PushFront(const T& data)
{
	Node<T> *newNode = new Node<T>(data);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
		return;
	}
	if (_head == _tail)
	{
		_tail->_prev = newNode;
		newNode->_next = _tail;
		_head = newNode;
		return;
	}
	newNode->_next = _head;
	_head->_prev = newNode;
	_head = newNode;
}
template <typename T>
void Dlist<T>::PopFront()
{
	if (_head == NULL)
		return;
	if (_head == _tail)
	{
		if (typeid(T) != typeid(string))
			delete[] _head;
		_head = NULL;
		_tail = NULL;
		return;
	}
	Node<T> *del = _head;
	_head = _head->_next;
	if (typeid(T) != typeid(string))
		delete[] del;
	del = NULL;
}
template <typename T>
void Dlist<T>::sort()
{
	//Node<T> *move = _head;
	//Node<T> *end = _tail;
	//while (move)
	//{
	//	Node<T> *cur = _head;	
	//	while (cur != end && cur->_next)
	//	{
	//		
	//		if ((cur->_next)->_data < cur->_data)
	//			swap((cur->_next)->_data, cur->_data);
	//		cur = cur->_next;
	//		
	//	}
	//	move = move->_next;
	//	end = end->_prev;
	//}
	Node<T> *cur = _head;
	Node<T> *end = NULL;
	while (cur != end)
	{
		while (cur &&cur->_next != end)
		{
			if (cur->_data > (cur->_next)->_data)
				swap((cur->_data), (cur->_next)->_data);
			cur = cur->_next;
		}
		end = cur;
		cur = _head;

	}
}
template <typename T>
void Dlist<T>::Insert(int pos, T data)
{
	Node<T> *newNode = new Node<T>(data);
	Node<T> *cur = _head;
	if (_head == NULL)
	{
		_head = newNode;
		_tail = newNode;
	}
	int count = pos;
	while (count-- &&cur)
	{
		cur = cur->_next;
	}
	Node<T> *pre = cur->_prev;

	newNode->_next = cur;
	cur->_prev = newNode;
	newNode->_prev = pre;
	pre->_next = newNode;
}
template <typename T>
void Dlist<T>::Remove(T data)
{
	Node<T> *cur = _head;
	if (_head->_data == data)
	{
		PopFront();
		return;
	}
	if (_tail->_data == data)
	{
		PopBack();
		return;
	}
	while (cur && (cur->_data != data))
	{
		cur = cur->_next;
	}
	(cur->_prev)->_next = cur->_next;
	(cur->_next)->_prev = (cur->_prev);
	if (typeid(T) != typeid(string))
		delete[] cur;
	cur = NULL;
}
template <typename T>
bool Dlist<T>::find(T data)
{
	Node<T> *cur = _head;
	bool findit = false;
	while (cur)
	{
		if (cur->_data == data)
		{
			findit = true;
			break;
		}
		cur = cur->_next;
	}
	return findit;
}
template <typename T>
void Dlist<T>::RemoveAll(T data)
{
	Node<T> *cur = _head;
	while (find(data))
	{
		Node<T> *cur = _head;
		if (_head->_data == data)
		{
			PopFront();
			continue;
		}
		if (_tail->_data == data)
		{
			PopBack();
			return;
		}

		while (cur && (cur->_data != data))
		{
			cur = cur->_next;
		}
		(cur->_prev)->_next = cur->_next;
		(cur->_next)->_prev = (cur->_prev);
		if (typeid(T) != typeid(string))
			delete[] cur;
		cur = NULL;
	}
}



void test()
{
	Dlist<string> s1;
	s1.PushFront("4");
	s1.PushFront("5");
	s1.PushFront("2");
	s1.PushFront("7");
	s1.PushFront("3");
	cout << "正确顺序：37254" << endl;
	s1.Display();
	s1.sort();
	cout << "排序" << endl;
	s1.Display();
	s1.Insert(1, "2");
	cout << "第二个元素处插入2" << endl;
	s1.Display();
	s1.RemoveAll("2");
	cout << "删除所有2" << endl;
	s1.Display();
	s1.Reverse();
	cout << "逆序" << endl;
	s1.Display();
}
int main()
{
	test();
	getchar();
	return 0;
}