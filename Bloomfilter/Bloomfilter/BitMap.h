#pragma once

#include<iostream>
#include<vector>
using namespace std;

template<class K = size_t>
class BitMap
{
private:
	vector<K> _a;
public:
	BitMap(size_t size)
	{
		_a.resize((size >> 5) + 1);
	}
	void Set(const K& key)
	{
		size_t index = key >> 5;
		_a[index] |= (1 << (key%32));
	}
	void Reset(const K& key)
	{
		size_t index = key >> 5;
		_a[index] &= (~(1 << (key %32)));
	}
	bool test(const K& key)
	{
		size_t index = key >> 5;
		return  _a[index] & (1 << (key % 32));
	}
};