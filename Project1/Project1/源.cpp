#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

#if 0
//String��ĸ������������
class CMyString{
public:
	//���ǵ�һ���İ�ȫ����ѡ��ʹ���ִ�д��
	CMyString& operator=(CMyString str)
	{
		if (&str != this)
			swap(_pData, str._pData);
		return *this;
	}
private:
	char *_pData;
};
#endif

#if 0
//���ַ�����Ŀո��滻��20%
char* Inst(char *str)
{
	char *cur = str;
	size_t Blank = 0;
	while (*cur != '\0')
	{
		if (*cur == ' ')
			Blank++;
		cur++;
	}
	char *newPtr = cur + (Blank * 2);
	while (1)
	{
		if (*cur == ' ')
		{
			*newPtr-- = '0';
			*newPtr-- = '2';
			*newPtr = '%';
		}
		else
			*newPtr = *cur;
		if (cur == str)
			return str;
		newPtr--;
		cur--;
	}
}
int main()
{
	char str[25] = { "We are bits!" };
	cout << Inst(str) << endl;
	getchar();
	return 0;

}
#endif
#if 0
//����ջʵ�ֶ���
template<class T>
class Myqueque
{
private:
	stack<T> s1;
	stack<T> s2;
public:
	Myqueque()
	{}
	~Myqueque()
	{
		while (!s1.empty())
		{
			while (!s2.empty())
			{
				s2.pop();
			}
			s1.pop();
		}
	}
	void Push(const T& data)
	{
		s1.push(data);
	}
	void Pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		s2.pop();
	}
};
int main()
{
	Myqueque<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Pop();
	q1.Pop();
	getchar();
	return 0;
}
#endif
#if 0
int findInYangs(int * arr, size_t Row, size_t Col,int key)
{
	size_t MyRow = 0;
	size_t MyCol = Col - 1;
	while (MyCol <= Col-1 && MyRow <= Row-1)
	{
		if (arr[MyRow*Col + MyCol] == key)
			return arr[MyRow*Col + MyCol];
		else if (arr[MyRow*Col + MyCol] > key)
			MyCol--;
		else if (arr[MyRow*Col + MyCol] < key)
			MyRow++;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 2, 4, 5, 3, 5, 7 };
	cout << findInYangs(arr, 3, 3, 8) << endl;
	getchar();
	return 0;
}
#endif

#if 0
//����ģʽ
class CSingleton
{
private:
	CSingleton() 
	//���캯��˽�в������ⲿʵ����
	{
	}
public:
	static CSingleton * GetInstance()
	{
		//������̬��ָ�� ָ��Ψһʵ��
		static CSingleton *m_pInstance;
		if (m_pInstance == NULL) 
			m_pInstance = new CSingleton();
		return m_pInstance;
	}
};

int main()
{
	CSingleton::GetInstance();
	getchar();
	return 0;
}
#endif
#if 0
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
	BinaryTreeNode(const int& x = 0) :_value(x), _left(NULL), _right(NULL)
	{}
};
class BinaryTree
{
private:
	BinaryTreeNode *_root;
public:
	BinaryTree()
	{}
	BinaryTree(int *PreOrder, int *InOrder,int size)
	{
		if (!PreOrder || !InOrder || size <= 0)
			return;
		_root = _CreateTree(PreOrder, PreOrder + size - 1, InOrder, InOrder + size - 1);
	}
private:
	BinaryTreeNode* _CreateTree(int *Pre,int *endPre,int *In,int *endIn)
	{
		//���쵱ǰ���ڵ�root 
		int RootValue = Pre[0];
		BinaryTreeNode *root = new BinaryTreeNode(RootValue);
		
		//���ߵ����һ��Ԫ��
		if (Pre == endPre)
		{
			//�������Ҳ�ߵ������һ���ڵ�
			//���һ���ڵ����˵�����һ���ڵ���һ���ҷ�֧
			if (In == endIn && *Pre == *In)
				return root;
		}

		//������������ҵ����ڵ�
		int *rootIn = In;
		while (rootIn <= endIn && *rootIn != RootValue)
		{
			//��������ǰ����Ԫ��ʱ��ʾΪ����ĸ��ڵ�
			++rootIn;
		}
		//�ҵ�֮�������������Ľڵ���
		int leftLen = rootIn - In;

		//�ҳ�ǰ�����������Ĺ�������
		int *PreLeftEnd = Pre + leftLen;
		if (leftLen > 0)
		{
			//����������
			root->_left = _CreateTree(Pre + 1, PreLeftEnd  , In, rootIn - 1);
		}

		if (leftLen < endPre - Pre)
		{
			//����������
			root->_right = _CreateTree(PreLeftEnd + 1, endPre, rootIn + 1, endIn);
		}
		return root;

	}
};
int main()
{
	int Pre[] = { 1, 2, 4, 5, 3, 6 };
	int In[] = { 4, 2, 5, 1, 6, 3};
	BinaryTree tree(Pre, In, sizeof(Pre) / sizeof(Pre[0]));
	getchar();
	return 0;
}
#endif

#if 0
//��ת�ַ���
#include<string.h>
void Reverse(char *str,size_t size)
{
	size_t left = 0;
	size_t right = size - 1;
	while (left < right)
	{
		if (str[left] != str[right])
		{
			swap(str[left], str[right]);
			
		}
		left++;
		right--;
	}
}
void ReverseStr(char *str,size_t size)
{
	 Reverse(str, size);
	char *cur = str;
	size_t len = 0;
	char *post = cur;
	while (*post != '\0')
	{
		len = 0;
		cur = post;
		while (*post != ' '&& *post!= '\0')
		{
			post++;
			len++;
		}
		post++;
		Reverse(cur, len);
	}
}
int main()
{
	char str[] = "This is a test";
	ReverseStr(str, strlen(str));
	cout << str << endl;
	getchar();
	return 0;
}
#endif
#if 0
//��������
void MySort(int *ary,int size)
{
	if (ary == NULL||size <= 0 )
		return;
	int *key = ary ;
	int *left = ary;
	int *right = ary + size - 1;
	while (key != ary + size)
	{	
		while (*right >= *key && left < right)
		{
			right--;
		}
		
		while (*left <= *key && left < right)
		{
			left++;
		}
	
		if (left < right)
			swap(*left, *right);
		else
		{
			swap(*key, *left);
			key++;
			left = key;
			right = ary + size - 1;
		}
	
	}
	
}

int main()
{
	int arr[] = { 5, 6, 2, 1, 3, 7, 9 };
	MySort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	getchar();
	return 0;

}

#endif
#if 1
int main()
{
	char *a[] = { "abc", "def", "ghi" };
	char **p = a;
	p++;
	cout << *p << endl;
	getchar();
	return 0;
}
#endif