#pragma once
#include<iostream>
#include<string>
using namespace std;
#define INC (_capcity+3)
#define DEFUALT 10
template<typename T>
class SeqList
{
public:
	SeqList():
		_size(0), _capacity(DEFUALT), _data(new T[DEFUALT])
	{}
	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
		}
	}
public:
	void CheckCapacity();
	void PushBack(const T& data);
	void PopBack();
	void PushFront(const T& data);
	void PopFront();
	void Insert(int pos,const T& data);
	void Sort();
	void display();
private:
	T *_data;
	int _size;
	int _capacity;
};
