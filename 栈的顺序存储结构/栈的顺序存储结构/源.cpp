#include<iostream>
#include<string>
using namespace std;
typedef string Elem;
#define INIT 10
#define INC 10
struct stack
{
	Elem *_base;
	Elem *_top;
	int _size;
	stack() :_base(NULL), _top(NULL), _size(0)
	{}
};
void Checkcap(stack *st)
{
	if ((st->_top) - (st->_base) == st->_size)
	{
		//可注意如果是string类型的情况我们不能使用memcpy
		Elem *del = st->_base;
		st->_base = new Elem[st->_size + INC];
		for (int i = 0; i < st->_size; i++)
		{
			*(st->_top) = del[i];
			(st->_top)++;
		}
		st->_size += INC;
	}
}
void init(stack * st)
{
	st->_base = new Elem[INIT];
	st->_size = INIT;
	if (st->_base == NULL)
		exit(0);
	st->_top = st->_base;
}
void push(stack *st,Elem data)
//注意：数据先进再移动top
{
	Checkcap(st);
	*(st->_top) = data;
	st->_top++;
}
Elem pop(stack *st)
{
//注意：先移动top再出栈
	if (st->_top - st->_base == 0)
		return "error";
	st->_top--;
	Elem re = *(st->_top);
	return re;
}
void Print( stack  *st)
{
	cout << "Stack base:";
	Elem *cur = st->_base;
	while (cur != st->_top)
	{
		cout << *cur << "->";
		cur++;
	}
	cout <<"Stack Top"<< endl;
}
void Clean(stack *st)
{
	//清空非销毁！
	st->_top = st->_base;
}
void Destory(stack *st)
{
	//销毁即释放整个栈空间
	/*
		因为此次使用new开辟数据数组空间我们可以直接delete[]
		如果使用C的malloc那么我们必须要一个一个的释放
	*/
	delete[] st->_base;
}
int Getlen(stack *st)
{
	return (st->_top - st->_top);
}

int main()
{
	stack st;
	stack *st1 = &st;
	init(st1);
	push(st1, "1");
	push(st1, "2");
	Print(st1);
	Elem re = pop(st1);
	Print(st1);
	cout << re << endl;
	Clean(st1);
	Print(st1);
	Destory(st1);
	getchar();
	return 0;
}