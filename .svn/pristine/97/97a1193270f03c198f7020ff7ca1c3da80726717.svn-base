#include<iostream>
#define DEFUALT 10
using namespace std;
template<class T>
class Seqlist
{
private:
	T *_data;
	int _size;
	int _cap;
public:
	Seqlist() :_data(new T[DEFUALT]), _size(0), _cap(DEFUALT)
	{}
	~Seqlist()
	{
		if (_data != NULL)
		{
			delete[] _data;
		}
	}
	void PushBack(const T& data)
	{
		//..
	}
	void PopBack()
	{
		//..
	}
};
template <typename T, class Container = Seqlist<T> >
class Stack
{
private:
	T *_base;
	T *_top;
	Container con;
public:
	void push(const T& data)
	{
		con.PushBack(data);
	}
};
int main()
{
	Stack<int> st;
	st.push(2);
	getchar();
	return 0;
}