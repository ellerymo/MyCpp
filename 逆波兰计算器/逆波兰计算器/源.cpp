#include<iostream>
using namespace std;
typedef char Element;
struct Node
{
	Element data;
	Node *next;
	Node(Element d) :data(d), next(NULL)
	{}
};
class  DStack
{
private:
	Node *top;
	int size;
public:
	DStack() : top(NULL)
	{
	}
	~DStack()
	{
		if (top != NULL)
		{
			Node *del = top;
			top = top->next;
			delete del;
			del = NULL;
		}
	}
public:
	void Push(Element d)
	{
		Node *newNode = new Node(d);
		newNode->next = top;
		top = newNode;
		size++;
	}
	Element Pop()
	{
		Element re = top->data;
		top = top->next;
		size--;
		return re;
	}
};

int RPN()
{
	DStack s1;
	char tmp = 0;
	int a = 0, b = 0, c = 0;
	cout << "please enter a RPN :" << endl;
	while (1)
	{
		cin >> tmp;
		if (tmp == '#')
			break;
		switch (tmp)
		{	
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			s1.Push(tmp);
			break;
		case'+':
			 a = s1.Pop()-'0';
			 b = s1.Pop() - '0';
			 c = a + b;
			s1.Push(c + '0');
			break;
		case'-':
			 a = s1.Pop() - '0';
			 b = s1.Pop() - '0';
			 c = a - b;
			s1.Push(c + '0');
			break;
		case'*':
			 a = s1.Pop() - '0';
			 b = s1.Pop() - '0';
			 c = a * b;
			s1.Push(c + '0');
			break;
		case'/':
			 a = s1.Pop() - '0';
			 b = s1.Pop() - '0';
			 c = a / b;
			s1.Push(c + '0');
			break;
		default:
			exit(0);
			break;
		}
	}
	int re = s1.Pop() - '0';
	return re;
}
int main()
{
	int a = RPN();
	cout << "计算结果是：" << a << endl;
	getchar();
	getchar();
	return 0;
}