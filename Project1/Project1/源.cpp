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
#if 0
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
#if 0
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
#if 0
//���������ż����λ��
/*
	����һ��ָ���ƶ�
*/
void ReOrder(int *arr,int size)
{
	int left = 0;
	int right = size - 1;
	while (right > left)
	{
		if (arr[left] % 2 == 0 && arr[right] % 2 == 1)
		{
				swap(arr[left], arr[right]);
		}
		while (arr[left] % 2 == 1)
			++left;
		while(arr[right] % 2 == 0)
			--right;
	}
}
//��չ�����ͬ���������ǿ���ʹ�ú���ָ������
 
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ReOrder(arr, sizeof(arr) / sizeof(arr[0]));
  	getchar();
	return 0;
}
#endif
#if 0
long long Fibonaqucci(int n)
{
	long long first = 0;
	long long second = 1;
	long long fi = 0;
	if (n < 2)
		return n; 
	for ( unsigned int i = 2; i <=n; i++)
	{ 
		fi = first + second;
		first = second;
		second = fi;
	}
	return fi;
}
int main()
{
	cout<<Fibonaqucci(5000)<<endl;
	getchar();
	return 0;
}
#endif
#if 0
//��ֵ��1��λ��
int OneInNum(int data)
{
	int Count = 0;
	while (data)
	{
		//�����ֶ����Ʊ�ʾ��ʽ�����ұߵ�һ��1��0
		data = data&(data - 1);
		Count++;
	}
	return Count;

}
int main()
{
	cout << OneInNum(7) << endl;
	getchar();
	return 0;
}
#endif
#if 0
//��ӡ1��nλ�������
bool Increase(char *num)
{
	int lenth = strlen(num);
	bool OverFlow = false;
	int Step = 0;
	for (int i = lenth - 1; i >= 0; i--)
	{
		int sum = Step + (num[i] - '0');
		if (i == lenth - 1)
			sum++;
		if (sum >= 10)
		{
			if (i == 0)
				OverFlow = true;
			else
			{
				Step = sum / 10;
				sum = sum % 10;
				num[i] = sum + '0';
			}
		}
		else
		{
			num[i] = sum + '0';
			break;
		}
	}
	return OverFlow;
}
void Print(char *num)
{
	bool isBegin0 = true;
	int lenth = strlen(num);
	for (int i = 0; i < lenth; i++)
	{
		if (isBegin0 && num[i] != '0')
			isBegin0 = false;
		if (!isBegin0)
		{
			cout << num[i];
		}
	}
	cout << " ";
}
void OneToMix(int n)
{
	if (n <= 0)
		return;

	char *num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	while (!Increase(num))
	{
		Print(num);
	}
	delete[] num;
}
int main()
{
	OneToMix(3);
	getchar();
	return 0;
}
#endif
#if 0
//���������ӽṹ
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
	BinaryTreeNode(const int& x = 0) :_value(x), _left(NULL), _right(NULL)
	{}
};
bool IsCh(BinaryTreeNode * pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->_value != pRoot2->_value)
		return false;

	return IsCh(pRoot1->_left, pRoot2->_left) && IsCh(pRoot1->_right, pRoot2->_right);
}
bool IsContain(BinaryTreeNode * pRoot1, BinaryTreeNode* pRoot2)
{
	bool resualt = false;
	if (pRoot1 && pRoot2)
	{
		if (pRoot1->_value == pRoot2->_value)
			resualt = IsCh(pRoot1, pRoot2);
		if (!resualt)
			resualt = IsContain(pRoot1->_left, pRoot2);
		if (!resualt)
			resualt = IsContain(pRoot1->_right, pRoot2);
	}
	return resualt;
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
void Mirror(BinaryTreeNode* root)
{
	if (root == NULL)
		return;
	_Mirror(root->_left,root->_right);
}
void _Mirror(BinaryTreeNode * left, BinaryTreeNode *right)
{
	if (left == NULL || right == NULL)
		return;
	swap(left->_value, right->_value);
	_Mirror(left->_left, left->_right);
	_Mirror(right->_left, right->_right);
}

#endif
#if 0
//�����˳ʱ�����
int Mixtr[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
void PrintMix(int Mixtr[4][4], int Start, int col, int row)
{
	int i = Start;
	int j = Start;
	while (j < col)
	{	
		cout << Mixtr[i][j] << " ";
		j++;
	}
	j--;
	i++;
	while (i < row)
	{	
		cout << Mixtr[i][j] << " ";
		i++;
	}
	i--;
	j--;
	while (j >= Start)
	{
		cout << Mixtr[i][j] << " ";
		j--;
	}
	j++;
	i--;
	while (i > Start)
	{
		cout << Mixtr[i][j] << " ";
		i--;
	}
	
}
void PrintMixtrInClock(int Mixtr[4][4],int col,int row)
{
	if (Mixtr == NULL || col == 0 || row == 0)
		return;
	int Start = 0;
	while (col > Start*2 && row > Start *2)
	{
		PrintMix(Mixtr,Start, col, row);
		col--;
		row--;
		Start++;
	}
}
int main()
{
	PrintMixtrInClock(Mixtr, 4, 4);
	getchar();
}
#endif

#if 0

#include<stack>
using namespace std;

bool CheckOrderOfOutStack(int *in, int *out, int size)
{
	stack<int> s1;
	
	int index = 0;
	s1.push(in[0]);
	for (int i = 0; i < size; i++)
	{
		while (s1.top() != out[i])
		{
			s1.push(in[++index]);
		}
		if (s1.top() == out[i])
		{
			s1.pop();
		}
	}
	if (!s1.empty())
		return false;
	else
		return true;
}

int main()
{
	int in[] = { 1, 2, 3, 4, 5 };
	int out[] = { 5, 4, 2, 3, 1 };
	cout << CheckOrderOfOutStack(in, out, sizeof(in) / sizeof(in[0])) << endl;
	getchar();
	return 0;
}
#endif

#if 0
//����һ���������飬�жϸ������ǲ���ĳ�������������ĺ���������
bool IsBinarySearchPostOrder(int *arr,int size)
{
	if (arr == NULL)
		return false;
	int root = arr[size - 1];
	//ȷ����������λ��
	int i = 0;
	for (; i < size; i++)
	{
		//������һֱС�ڸ��ڵ�
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < size; j++)
	{
		//����Ѿ������������Ľ綨��Χ��ô������������С�ڸ��ڵ�����Ϊ�������
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
		left = IsBinarySearchPostOrder(arr, i);
	bool right = true;
	if (j < size - 1)
		right = IsBinarySearchPostOrder(arr + i, size - 1 - i);
	
	//�������������������������ĺ�����������ȷ
	return (left && right);
}
int main()
{
	int arr[] = { 2, 3, 1, 5, 6, 3, 5 };
	cout << IsBinarySearchPostOrder(arr, sizeof(arr) / sizeof(arr[0]))<<endl;
	getchar();
	return 0;
}
#endif
#if 0
struct ComlistNode
{
	int _data;
	ComlistNode* _next;
	ComlistNode* _random;
	ComlistNode(const int& data) :
		_data(data), _next(NULL), _random(NULL)
	{}
};
class Comlist
{
	typedef ComlistNode Node;
private:
	Node* _head;
public:
	Comlist() :_head(NULL)
	{
		_create();
	}
	void pushback(const int i)
	{
		if (_head == NULL)
		{
			
			_head = new Node(i);
			return;
		}
		Node*cur = _head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = new Node(i);
	}
 
	void _create()
	{
		pushback(1);
		pushback(2);
		pushback(3);
		pushback(4);
		pushback(5);
		Node *cur = _head;
		while (cur != NULL)
		{
			Node *now = cur;                                                                                                                                                          
			int index = 3;
			while (--index && cur)
			{
				cur = cur->_next;
			}
			now->_random = cur;
			cur = now;
			cur = cur->_next;
		}
	}
};
int main()
{
	Comlist cm;
	Comlist cc(cm);
	getchar();
	return 0;
}

#endif

#if 0

void _Porder(char *str, char *ptr)
{
	if (*ptr == '\0')
		cout << str << endl;
	else
	{
		for (char *pch = ptr; *pch != '\0'; pch++)
		{
			swap(*pch, *ptr);
			_Porder(str, ptr + 1);
			swap(*pch, *ptr);
		}
	}
}

void Order(char *str)
{
	if (*str == '\0')
		return;
	_Porder(str, str);
}
int  main()
{
	char str[] = "abc";
	Order(str);
	getchar();
	return 0;
}
#endif
#if 0
int main()
{
	printf("hello world");
	_exit(0);
}
#endif

#if 0
int FindNumber(int *arr,int lenth)
{
	int resualt = arr[0];
	int time = 1;
	for (int i = 1; i < lenth; i++)
	{
		if (resualt == arr[i])
			time++;
		else if (time == 0)
			resualt = arr[i];
		else
			time--;
	}
	return resualt;
}

int main()
{
	int arr[] = { 2, 2, 2, 2, 2, 4, 4, 5, 3};
	cout << FindNumber(arr, sizeof(arr) / sizeof(arr[0]));
	getchar();
	return 0;

}
#endif
#if 0
//�ҵ���������С��λ��
//����1
void FindMinKInArr(int *arr,int k, size_t size)
{
	int key = arr[k - 1];
	while (1)
	{
		int index1 = size - 1;
		while (index1 > k - 1 && arr[index1] > arr[k - 1])
		{
			index1--;
		}
		int index2 = 0;
		while (index2 < k - 1 && arr[index2] < arr[k - 1])
		{
			index2++;
		}
		swap(arr[index1], arr[index2]);
		if (index1 == index2)
			break;
	}
	int Count = 0;
	while (Count<k)
	{
		cout << arr[Count]<<" ";
		Count++;
	}
	cout << endl;

}
//����2
//����STL�����
int main()
{
	int arr[] = { 1, 3, 5, 4, 2, 0, 9 };
	FindMinKInArr(arr, 3, sizeof(arr) / sizeof(arr[0]));
	getchar();
	return 0;
}
#endif

#if 0
/*
	�ⷨһ�����ñ������ֵ����
			�ڱ��ν���ѭ����sumС��0ʱһ����ʾ��һ�μ�ʱ���С֮��ĺ͡���>����֮ǰ�����ִӵ�ǰֵ��ʼ����
			����ֱ�ӽ���ǰֵ�Ӹ�sum 
			������μӵ�sum����max��һ������max
			�����û�еĻ��򱣳ָ�max����
*/
int MaxSumInArr(int *arr, int size)
{
	if (arr == NULL)
		return 0;
	int sum = 0;
	int Max = 0;
	for (int i = 0; i < size; i++)
	{
		if (sum <= 0)
			sum = arr[i];
		else
			sum += arr[i];
		if (sum > Max)
			Max = sum;

	}
	return Max;
}
int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << MaxSumInArr(arr, sizeof(arr) / sizeof(arr[0]));
	cout << endl;
	getchar();
	return 0;
}

#endif

#if 0
int NumBase10(int n)
{
	int sum = 1;
	for (int i = 0; i < n; i++)
	{
		sum *= 10;
	}
	return sum;
}
//�����0��n�Ĺ���������1���ֵĴ���
int NumOfOne(const char * str)
{
	if ( !str || *str > '9' || *str < '0')
		return 0;
	//first���ڱ�����λ������
	int first = *str - '0';
	int lenth = strlen(str);
	/*
		�����һ�εݹ����ʱ��λ���ֵ�1������ֻ���������:
		1.��λ��0����1���ֵĴ�����0
		2.��λ����0����1���ֵĴ�����1
	*/
	if (lenth == 1 && *str == '0')
		return 0;
	if (lenth == 1 && *str > '0')
		return 1;

	/*
		OneInFirst��������λ��1�����˶��ٴ�
		�˴���Ϊ���������
		1.���λΪ1���������ʣ���λ��������+1�Σ�����132�������λ���ֵ�1�Ĵ���Ϊ100��132��33��
		2.���λ����1,��1һ��������100�Σ�����232,���λ���ֵ�1�Ĵ�����100��199��100��
	*/
	int  OneInFirst = 0;
	if (first == 1)
		OneInFirst = atoi(str + 1) + 1;
	if (first > 1)
		OneInFirst = NumBase10(lenth - 1);
	//?
	int OneInOther = first *(lenth-1)*NumBase10(lenth-2);

	int Remainder = NumOfOne(str + 1);

	return OneInFirst+OneInOther+Remainder;
}
long CountOne(long n)
{
	long count = 0;
	if (n == 0)
		count = 0;
	else if (n > 1 && n < 10)
	count = 1;
	else
	{
		//��highest��ʾ���λ������
		long highest = n;
		int bit = 0;
		while (highest >= 10)
		{
				highest = highest / 10;
				bit++;
		}
		//���λ��Ȩ��
		int weight = (int)pow(10, bit);
		if (highest == 1)
		{
				//eg: f(132) = f(100-1) + f(132-100) + (32+1);
				count = CountOne(weight - 1)+ CountOne(n - weight)+ n - weight + 1;
		}
		else
		{		
			//  eg: f(232) = 2*f(100-1) + f(32) + 100
				count = highest * CountOne(weight - 1)+ CountOne(n - highest * weight)+ weight;			
		}		
	}	
	return count;
}


int main()
{
	cout << NumOfOne("1000") << endl;
	cout << CountOne(1000) << endl;
	getchar();
	return 0;
}
#endif

#if 0
//ˮ�ɻ���
void DafNum(int m,int n)
{
	int num = 0;
	int sum = 0;
	for (int i = m;i <= n; i++)
	{
		num = i;
		sum = 0;
 		while (num)
		{
			sum += (num % 10)*(num%10)*(num % 10);
			num = num /10;
		}
		if (sum == i)
			cout << i << " ";
	}
	cout << endl;
}
int main()
{
	DafNum(100,1000);
	getchar();
	return 0;
}
#endif

#if 0
int Sum(int a, int n)
{
	int num = a;
	int sum = a;
	for (int i = 1; i < n; i++)
	{
		num = num * 10;
		sum += num + a;
		num = num + a;
	}
	return sum;
}
int main()
{
	cout << Sum(2, 3) << endl;
	
	getchar();
	return 0;
}
#endif

#if 0
void Reverse(char *left,char *right)
{
	while (left < right)
	{
		swap(*left, *right);
		left++;
		right--;
	}
}
void ReverseStr(char *str,int size)
{
	char *end = str + (size - 2);
	Reverse(str, end);
	end = str;
	char *start = str;
	while (end != '\0')
	{
		while (*end != ' ' && *end != '\0')
			end++;
		Reverse(start, end - 1);
		if (*end == '\0')
			return;
		start = end + 1;
		end++;
	}
}
int main()
{
	char str[] = "abcde";
	Reverse(str, str + 4);
	cout << str << endl;
	char arr[] = "This is a test";
	ReverseStr(arr, sizeof(arr) / sizeof(arr[0]));
	cout << arr << endl;
	getchar();
	return 0;
}
#endif
