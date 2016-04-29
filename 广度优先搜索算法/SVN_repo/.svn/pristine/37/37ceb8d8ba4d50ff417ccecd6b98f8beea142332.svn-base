#include"SeqList.h"
template<typename T>
void SeqList<T>::CheckCapacity()
{
	if (_size == _capacity)
	{
		T *tmp = new T[INC];
		memcpy(tmp, _data,_size*sizeof(T));
		delete[] _data;
		_data = tmp;
		_capcity = INC;
	}
}

template<typename T>
void SeqList<T>::PushBack(const T& data)
{
	CheckCapacity();
	_data[_size] = data;
	_size++;
}

template<typename T>
void SeqList<T>::PopBack()
{
	if (_size == 0)
		return;
	_size--;
}

template<typename T>
void SeqList<T>::PushFront(const T& data)
{
	CheckCapacity();
	T *tmp = new T[_capacity];
	memcpy(tmp+1,_data,_size*sizeof(T));
	tmp[0] = data;
	delete[] _data;
	_data = tmp;
	_size++;
}

template<typename T>
void SeqList<T>::PopFront()
{
	for (int i = 0; i < _size - 1;i++)
	{
		_data[i] = _data[i + 1];
	}
	_size--;
}

template<typename T>
void SeqList<T>::Insert(int pos,const T& data)
{
	CheckCapacity();
	if (pos > _size-1)
	{
		cout << "This add didn't find!" << endl;
		return;
	}
	for (int i = _size; i > pos; i--)
	{
		_data[i] = _data[i - 1];
	}
	_data[pos] = data;
	_size++;
}

template<typename T>
void SeqList<T>::Sort()
{
	for (int i = 0; i < _size - 1; i++)
	{
		for (int j = 0; j < _size - 1 - i; j++)
		{
			if (_data[j]>_data[j + 1])
			{
				T tmp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = tmp;
			}
		}
	}
}

template<typename T>
void SeqList<T>::display()
{
	for (int i = 0; i < _size;i++)
	{
		cout << _data[i] << "->";
	}
	cout << "over" << endl;
}