#include<iostream>
#define _CRT_SECURE_NO_WARNINGS 1
//**************Method.1***********
template<class T,class Del=Delete<T> >
class SharedPtr
{
public:
	/*SharedPtr(T *ptr, Del del) :_ptr(ptr), _del(del), _pCount(new int(1))
	{}*/
	SharedPtr(T *ptr) :_ptr(ptr), _pCount(new int(1))
	{}
	SharedPtr(const SharedPtr& sp)
	{
		_ptr = sp._ptr;
		_pCount = sp._pCount;
		(*_pCount)++;
	}
	SharedPtr& operator =(SharedPtr  sp)
	{
		swap(_ptr, sp._ptr);
		swap(_ptr, sp._pCount);
		return *this;
	}
	~SharedPtr()
	{
		_Relese();
	}
private:
	T *_ptr;
	T *_pCount;
	Del _del;
	void  _Relese()
	{
		if (--(*_pCount) == 0)
		{
			_del(_ptr);
			_del(_pCount);
		}
	}
};
template <class T>
struct Free
{
	void operator() (void *sp)
	{
		free(sp);
		sp = NULL;
	}
};
template <class T>
struct Delete
{
	void operator() (const T*sp)
	{
		delete sp;
	}
};
template <class T>
struct Fclose
{
	void operator() (void *sp)
	{
		fclose(sp);
		sp = NULL;
	}
};
void testSharePtrDelete()
{
	SharedPtr<int> sp1(new int(5));
	SharedPtr<int> sp2(sp1);
}
void testSharePtrFree()
{
	SharedPtr<int,Free<int>> sp1((int *)malloc(sizeof(int)*10));
	SharedPtr<int,Free<int>> sp2(sp1);
}
//void testSharePtrFclose()
//{
//	FILE *pf = fopen("","r");
//	SharedPtr<FILE, Fclose<FILE>> sp1(pf);
//	SharedPtr<FILE, Fclose<FILE>> sp2(sp1);
//}
