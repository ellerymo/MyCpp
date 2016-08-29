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
	//����ģʽ����һ�ε���ʱ�Ų���ʵ������
	static single* GetIns()
	{
		//˫�ؼ��->Ч��
		if (_instance == NULL)
		{
			//����->�̰߳�ȫ
			//mtx.lock();
			//C++11 �ṩ��RAII���� 
			lock_guard<mutex> lock(mtx);
			if (_instance == NULL)
				_instance = new single;
			//mtx.unlock();
		}
		return _instance;
	}
};

single*single::_instance = NULL;
mutex single::mtx;/*mutex�����Լ���Ĭ�Ϲ��캯������Ҫ��ʼ��*/



//����ģʽ
//�ڳ�ʼ����̬����ʱ��new����
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
