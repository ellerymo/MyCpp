#pragma once
#include<iostream>
#include<string>
using namespace std;

enum States
{
	EMPTY,
	DEL,
	EXITS,
};
template<class T = int>
struct FuncHash
{
	int operator() (const T& x)
	{
		return x;
	}
};
template<>
struct FuncHash<string>
{
	int operator() (const string& x)
	{
		int size = 0;
		for (int i = 0; i < x.size(); i++)
		{
			size += (int)x[i];
		}
		return size;
	}
};

template<class T,class V>
struct Node
{
	T _value;
	V _key;
};

template<class T, class V,class Func = FuncHash<T>>
class HashTable
{
private:
	Node<T,V> *_hash;
	States *_state;

	int _size;
	int _capcity;
public:
	HashTable() :_size(0), _capcity(10), _hash(new Node<T,V>[10]), _state(new States[10])
	{
		for (int i = 0; i < _capcity; i++)
		{
			_state[i] = EMPTY;
		}
	}
	HashTable(const HashTable<T, V>& hash) 
		:_hash(new Node<T,V>[hash._capcity]),
		_size(hash._size),
		_capcity(hash._capcity),
		_state(new States[hash._capcity])
	{
		for (int i = 0; i < _capcity; i++)
		{
			_hash[i]._value = (hash._hash[i])._value;
			_hash[i]._key = (hash._hash[i])._key;
			_state[i] = hash._state[i];
		}
	}
	HashTable<T, V> operator= (HashTable<T, V> hash)
	{
		this->Swap(hash);
		return *this;
	}
	~HashTable()
	{
		delete[] _hash;
	}
	bool push(const T& x, const V& v)
	{
		CheckCap();
		FuncHash<T> fun;
		int Index = fun(x);
		Index %= _capcity;
		int Start = Index;
		int i = 1;
		while (_state[Index] != EMPTY)
		{
			Index = Index + i*i;
			if (Index == Start)
				return false;
			i++;
		}
		_hash[Index]._value = v;
		_hash[Index]._key = x;
		_state[Index] = EXITS;

		_size++;
		return true;
	}
	void Display()
	{
		for (int i = 0; i < _capcity; i++)
		{
			if (_state[i] == EXITS)
				cout << _hash[i]._key << ":" << _hash[i]._value << "->";
			else if (_state[i] == DEL)
				cout << "DEL-> ";
			else if (_state[i] == EMPTY)
				cout << "EMPTY-> ";
		}
		cout << "end" << endl;
	}
	Node<T,V>* find(const T& data)
	{
		FuncHash<T> fun;
		int Index = fun(data);
		Index %= _capcity;
		int i = 1;
		int start = Index;
		while (_state[Index] != EXITS)
		{	
			Index += i*i;
			i++;
			if (start == Index)
				return NULL;
		}
		return _hash+Index;

	}
private:
	void CheckCap()
	{
		if (_size == _capcity)
		{
			HashTable<T,V> tmp;
			tmp._hash = new Node<T,V>[_capcity + 10];
			tmp._capcity = _capcity + 10;
			tmp._size = _size;
			tmp._state = new States[_capcity + 10];
			for (int i = 0; i < tmp._size; i++)
			{
				tmp.push(_hash[i]._key,_hash[i]._value);
			}
			tmp.Swap(*this);
		}
	}
	void Swap(HashTable<T,V>& hash)
	{
		swap(_size, hash._size);
		swap(_capcity, hash._capcity);
		swap(_hash, hash._hash);
		swap(_state, hash._state);
	}
};