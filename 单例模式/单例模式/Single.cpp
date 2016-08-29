#include <iostream>
#include <mutex>
#include <assert.h>
using namespace std;
class single
{
protected:
	single()
	{}

	static single* _instance;
	single(const single& s);
	static mutex mtx;
public:
	//懒汉模式：第一次调用时才产生实例对象
	static single* GetIns()
	{
		//双重检查->效率
		if (_instance == NULL)
		{
			//加锁->线程安全
			//mtx.lock();
			//C++11 提供的RAII机制 
			lock_guard<mutex> lock(mtx);
			if (_instance == NULL)
				_instance = new single;
			//mtx.unlock();
		}
		return _instance;
	}
};

single*single::_instance = NULL;
mutex single::mtx;/*mutex有其自己的默认构造函数不需要初始化*/



//饿汉模式
//在初始化静态变量时就new对象
class HungrySingle
{
protected:
	HungrySingle()
	{}
	static HungrySingle* _Instance;
	HungrySingle(const HungrySingle & h);
public:
	static HungrySingle*GetIns()
	{
		/*
			assert(_Instance);
			return _Instance;
		*/
		static HungrySingle h;
		return &h;
	}
};
HungrySingle* HungrySingle::_Instance = new HungrySingle;

class NotHeapIns
{
protected:
	~NotHeapIns();
};
int main()
{
	single::GetIns();
	NotHeapIns* Ins = new NotHeapIns;
	getchar();
	return 0;
}
