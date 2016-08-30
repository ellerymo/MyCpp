#include <iostream>
#include <mutex>
#include <assert.h>
#include <Windows.h>
using namespace std;

//����ģʽ����һ�ε���ʱ�Ų���ʵ������
class single
{
protected:
	single()
	{}

	static single* _instance;
	single(const single& s);
	static mutex mtx;
public:
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
			{
				single * tmp;
				tmp = new single;
				//ʹ���ڴ�դ����ֹ����������ָ����ˮ˳��
				MemoryBarrier();
				_instance = tmp;
			}
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
		static HungrySingle h = *_Instance;
		return &h;
	}
};
HungrySingle* HungrySingle::_Instance = new HungrySingle;

//����һ��ֻ���ڶ������ɶ������ ����������˽�л�
class NotHeapIns
{
protected:
	~NotHeapIns();
};
int main()
{
	single::GetIns();
	//NotHeapIns Ins;
	getchar();
	return 0;
}
