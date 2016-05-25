#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const unsigned long Prime[] =
{
	53ul, 97ul, 193ul, 389ul, 769ul,
	1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	1610612741ul, 3221225473ul, 4294967291ul
};
template <class K = int>
struct _FuncHash
{
	long operator () (const K& key,int cap)
	{
		return  key%cap;
	}
};

template<>
struct _FuncHash<string>
{
	long operator () (const string& key, int cap)
	{
		long sum = 0;
		for (int i = 0; i < key.size(); i++)
		{
			sum += key[i];
		}
		return sum%cap;

	}
};

template <class K,class V>
struct Node
{
	K _key;
	V _value;
	Node *_next;
	Node(const K& key, const V& value)
		:_key(key),
		 _value(value),
		 _next(NULL)
	{}
};

template <class K, class V, class FuncHash = _FuncHash<K> >
class Hash
{
	typedef Node<V, K> Node;
private:
	vector< Node* > _v;
	size_t _size;
public:
	Hash(const int cap = FindInPrime(0))
		:_size(0)
	{
		_v.resize(cap);
	}
	void push(const K key, const V value)
	{
		CheckCap();
		Node*New = new Node(key, value);
		FuncHash fun;
		long index = fun(key, _v.size());
		Node **cur = &(_v[index]);
		//头插
		if (*cur == NULL)
			*cur = New;
		else
		{
			New->_next = _v[index];
			_v[index] = New;
		}
		_size++;
	}
	Node* find(const K& key)
	{
		for (int i = 0; i < _v.size(); i++)
		{
			Node *cur = _v[i];
			while (cur)
			{
				if (cur->_key == key)
				{
					cout << "查找结果:" << cur->_value << endl;
					return cur;
				}		
				cur = cur->_next;
			}
		}

	}
	void display()
	{
		for (int i = 0; i < _v.size(); i++)
		{
			Node *cur = _v[i];
			cout << "[" <<i << "]" << ":";
			while (cur)
			{
				cout << cur->_key << ":" << cur->_value << " ->";
				cur = cur->_next;
			}
			cout << "end";
			cout << endl;
		}
	}
	void Remove(const K key)
	{
		for (int i = 0; i < _v.size(); i++)
		{
			Node *cur = _v[i];
			while (cur)
			{
				if (cur->_key == key)
				{
					Node *del = cur;
					_v[i] = cur->_next;
					delete del;
					_size--;
					return;
				}
				else if (cur->_next && (cur->_next)->_key == key)
				{
					Node *del = cur->_next;
					cur->_next = del->_next;
					delete del;
					_size--;
					return;
				}
				cur = cur->_next;
			}
		}
	}

private:
	void CheckCap()
	{
		
		//负载因子为1
		if (_size / _v.size() == 1)
		{
			vector<Node*> tmp;
			tmp.resize(FindInPrime(_v.size()));
			//摘节点 头插
			for (int i = 0; i < _v.size(); i++)
			{
				Node**cur = &_v[i];
				while (*cur)
				{
					//查找其在新表里的位置
					FuncHash fun;
					long index = fun((_v[i])->_key, _v.size());
					Node *node = (*cur);
					(*cur) = (*cur)->_next;
					_v[i] = *cur;
					if (tmp[index] == NULL)
						tmp[index] = node;
					else
					{
						node->_next = tmp[index];
						tmp[index] = node;
					}
				}
			}
			_v.swap(tmp);
		}
	}
	static long long FindInPrime(int key)
	{
		int index = 0;
		while (key >= Prime[index])
		{
			index++;
		}
		return Prime[index];
	}
};
