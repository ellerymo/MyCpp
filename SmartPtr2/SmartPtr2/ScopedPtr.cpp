#include<iostream>
template<class T>
class ScopedPtrWithOwner
{
public:
	ScopedPtrWithOwner(T* ptr) :_ptr(ptr), _owner(true)
	{}
	ScopedPtrWithOwner(ScopedPtrWithOwner& sp)
	{
		_ptr = sp._ptr;
		_owner = true;
		sp._owner = false;
	}
	ScopedPtrWithOwner& operator=(ScopedPtrWithOwner& sp)
	{
		if (sp._owner == false)
		{
			std::cout << "实参没有管理权限！请勿非法操作！" << std::endl;
		}
		else if (_ptr != sp._ptr)
		{
			if (_owner == true)
				delete _ptr;
			_ptr = sp._ptr;
			_owner = true;
			sp._owner = false;
		}
		return *this;
	}
	~ScopedPtrWithOwner()
	{
		if (_owner == true)
			delete _ptr;
	}
private:
	T *_ptr;
	bool _owner;
};
int main()
{
	ScopedPtrWithOwner<int> sp1(new int(1));
	ScopedPtrWithOwner<int> sp2(sp1);
	ScopedPtrWithOwner<int> sp3 = sp2;
	sp3 = sp1;
	getchar();
	return 0;
}