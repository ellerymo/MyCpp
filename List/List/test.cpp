#include "List.h"
int main()
{
	List<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	List<int>::_Iterator _it = list.Begin();
	while (_it != list.End())
	{
		cout << *_it << " " ;
		++_it;
	}
	cout << endl;
	getchar();
}