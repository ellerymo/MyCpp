#include<iostream>
using namespace std;
template<class T>
class AutoPtr
{
	friend ostream& operator <<(ostream&os, const AutoPtr& ap)
	{
		os << ap._ptr;
		return os;
	}
public:
	AutoPtr(T * p) :_ptr(p)
	{}
	AutoPtr(AutoPtr & ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}
	AutoPtr& operator =(AutoPtr & ap)
	{
		if (ap._ptr != _ptr)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}
	T& operator *()
	{
		return *_ptr;
	}
	T* operator ->()
	{
		return _ptr;
	}
	~AutoPtr()
	{
		if (_ptr != NULL)
		{
			delete _ptr;
		}
	}
private:
	T* _ptr;
};

template<class T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr) :_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr != NULL)
			delete _ptr;
	}
	T& operator *()
	{
		return *_ptr;
	}
	T* operator ->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	ScopedPtr(ScopedPtr<T>& sp);
	ScopedPtr& operator =(ScopedPtr<T>& sp);
};

template <class T>
class SharedPtr
{
public:
	SharedPtr(T * p) :_ptr(p), _pCount(new int(1))
	{
	}
	SharedPtr(SharedPtr& sp)
	{
		_ptr = sp._ptr;
		(*sp._pCount)++;
		_pCount = sp._pCount;
	}
	SharedPtr& operator=(SharedPtr sp)
	{
		swap(_ptr,sp._ptr);
		swap(_pCount, sp._pCount);
		return *this;
	}
	T* operator ->()
	{
		return _ptr;
	}
	T& operator *()
	{
		return *_ptr;
	}
	~SharedPtr()
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
		}
	}
	int GetCount()
	{
		return *_pCount;
	}
private:
	T * _ptr;
	int *_pCount;
};