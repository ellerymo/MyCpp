#pragma once
#include"BitMap.h"

struct _HashFun1
{
	size_t BKDRHash(const char* str)
	{
		 register size_t hash = 0;
		 while (size_t ch = (size_t)*str++)
		 {
		      hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
			        
     	 }
		return hash;
	}
	size_t operator()(const char* str)
	{
		return BKDRHash(str);
	}
};
struct _HashFun2
{
	size_t SDBMHash(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
		hash = 65599 * hash + ch;
		
	    }
	    return hash;
	}

	size_t operator()(const char *str)
	{
		return SDBMHash(str);
	}
};
struct _HashFun3
{
	size_t RSHash(const char* str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
	    while (size_t ch = (size_t)*str++)
		{
		hash = hash * magic + ch;
		magic *= 378551;
		}
		return hash;
	}

	size_t operator()(const char* str)
	{
		return RSHash(str);
	}
};
struct _HashFun4
{
	size_t APHash(const char* str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
}

	size_t operator()(const char* str)
	{
		return APHash(str);
	}
};
struct _HashFun5
{
	size_t JSHash(const char* str)
	{

		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			 hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}

	size_t operator()(const char* str)
	{
		return JSHash(str);
	}
};

template <class _HashFunc1 = _HashFun1
	    , class _HashFunc2 = _HashFun2
	    , class _HashFunc3 = _HashFun3
		, class _HashFunc4 = _HashFun4
		, class _HashFunc5 = _HashFun5>
class BloomFilter
{
private:
	BitMap<> _bm;
	size_t _capacity;
public:
	BloomFilter(int n)
		:_bm(n), _capacity(n)
	{
	}
	void Set(const string& key)
	{
		_bm.Set((_HashFunc1()(key.c_str()))%_capacity);
		_bm.Set((_HashFunc2()(key.c_str())) % _capacity);
		_bm.Set((_HashFunc3()(key.c_str())) % _capacity);
		_bm.Set((_HashFunc4()(key.c_str())) % _capacity);
		_bm.Set((_HashFunc5()(key.c_str())) % _capacity);
	}
	bool Test(const string& key)
	{
		return (_bm.test((_HashFunc1()(key.c_str())) % _capacity) &&
			_bm.test((_HashFunc2()(key.c_str())) % _capacity) &&
			_bm.test((_HashFunc3()(key.c_str())) % _capacity) &&
			_bm.test((_HashFunc4()(key.c_str())) % _capacity) &&
			_bm.test((_HashFunc5()(key.c_str())) % _capacity));
	}
};