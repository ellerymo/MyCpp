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
#if 0
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
#if 0
/*
	��Ŀ���ҳ���ת�������С����
	��ת���飺{3,4,5,1,2}������{1,2,3,4,5}����ת
	
*/
int MinInOrder(int *arr, int index1, int index2)
{
	int resualt = arr[index1];
	for (int i = index1; i <= index2; ++i)
	{
		if (resualt > arr[i])
			resualt = arr[i];
	}
	return resualt;
}
int FindMinNunInArr(int *arr,int size)
{
	//�����������ĺϷ���
	if (!arr || size <= 0)
		return -1;

	int index1 = 0;
	int index2 = size - 1;
	int indexMid = 0;
	//���ö��ֲ��ң�ÿ�αȽ��м�ֵ�ͱ߽�ֵ����С���ҷ�Χ
	while (arr[index1] >= arr[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
       		indexMid = ((index1&index2) + ((index1^index2) >> 1));
		/*
			�������������С��Χ��{1,1,1,1,0}��תΪ{1,1,1,0,1}
			��ʱ�м�ֵ�ͱ߽�ֵ���ֻ�ܲ���˳�����
		*/
		if (arr[index1] == arr[index2] && arr[index2] == arr[indexMid])
			return MinInOrder(arr, index1, index2);
		if (arr[indexMid] >= arr[index1])
			index1 = indexMid;
		else if (arr[indexMid] <= arr[index2])
			index2 = indexMid;
	}
	return indexMid;
}

int main()
{
	int arr[] = { 3, 4, 5, 1, 2 };
	cout<<FindMinNunInArr(arr, 5)<<endl;
	getchar();
	return 0;	
}

#endif
#if 1
/*����һ�����ö��ַ��ҵ��߽�ֵ�����ö��ַ�����*/
int Search(int *arr, int n, int x)
{
	int start = 0;
	int end = n - 1;
	int mid = (start & end) + ((start^end) >> 1);
	int min = 0;
	int max = 0;
	while (start < end)
	{
		if (arr[start] < arr[mid])
			start = mid;
		else if (arr[mid] < arr[end])
			end = mid;
		if (end - start == 1)
		{
			min = end;
			max = start;
			break;
		}
		mid = (start & end) + ((start^end) >> 1);
	}
	if (x < arr[min] || x > arr[max])
		return -1;
	else if (x <= *(arr + n - 1))
	{
		if (x == arr[n - 1])
			return n - 1;
		start = min;
		end = arr[n - 1];
	}
	else if (x >= arr[0])
	{
		return 0;
		start = arr[0];
		end = arr[max];
	}
	mid = (start & end) + ((start^end) >> 1);
	while (start < mid)
	{
		if (arr[mid] < x)
			start = mid + 1;
		else if (arr[mid] > x)
			end = mid - 1;
		else
			return mid;
		mid = (start & end) + ((start^end) >> 1);
	}
}
#endif
#if 1
/*����2��ֱ�����ö��ַ�ȷ����������ĵݹ��㷨*/
int FindInARoundAr(int *arr,int size,int key)
{
	int left = 0;
	int right = size - 1;
	int mid = (left&right) + ((left^right) >> 1);

	while (left < right)
	{
		
		if (arr[left] == key)
			return left;
		if (arr[right] == key)
			return right;
		if (arr[mid] == key)
			return mid;

		//ȷ����������䲢ȷ�����������Ƿ�������
		else if (arr[left] < arr[mid])
		{
			if (key >= arr[left] && key <= arr[mid])
				FindInARoundAr(arr, mid - left + 1, key);
			else
				left = mid + 1;
		}

		else if (arr[mid] < arr[right])
		{
			if (key >= arr[mid] && key <= arr[right])
				FindInARoundAr(arr +mid, right-mid + 1, key);
			else
				right = mid - 1;
		}
		mid = (left&right) + ((left^right) >> 1);
	}

}
int main()
{
	int arr[] = { 5, 6, 1, 2, 3 };
	cout<<FindInARoundAr(arr, 5, 6)<<endl;
	getchar();
	return 0;
}
#endif
