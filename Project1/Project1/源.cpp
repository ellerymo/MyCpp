#include<iostream>
#include<cassert>
#include<stack>
using namespace std;

#if 0
//String类的复制运算符重载
class CMyString{
public:
	//考虑到一场的安全性我选择使用现代写法
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
//将字符串里的空格替换成20%
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
//两个栈实现队列
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
//单例模式
class CSingleton
{
private:
	CSingleton() 
	//构造函数私有不允许外部实例化
	{
	}
public:
	static CSingleton * GetInstance()
	{
		//创建静态类指针 指向唯一实例
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
		//构造当前根节点root 
		int RootValue = Pre[0];
		BinaryTreeNode *root = new BinaryTreeNode(RootValue);
		
		//当走到最后一个元素
		if (Pre == endPre)
		{
			//如果中序也走到了最后一个节点
			//最后一个节点相等说明最后一个节点是一个右分支
			if (In == endIn && *Pre == *In)
				return root;
		}

		//在中序遍历中找到根节点
		int *rootIn = In;
		while (rootIn <= endIn && *rootIn != RootValue)
		{
			//当它等于前序首元素时表示为中序的根节点
			++rootIn;
		}
		//找到之后计算出左子树的节点数
		int leftLen = rootIn - In;

		//找出前序里左子树的构造区间
		int *PreLeftEnd = Pre + leftLen;
		if (leftLen > 0)
		{
			//构造左子树
			root->_left = _CreateTree(Pre + 1, PreLeftEnd  , In, rootIn - 1);
		}

		if (leftLen < endPre - Pre)
		{
			//构造右子树
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
//翻转字符串
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
//快速排序
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
	题目：找出旋转数组的最小数字
	旋转数组：{3,4,5,1,2}是数组{1,2,3,4,5}的旋转
	
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
	//检查输入参数的合法性
	if (!arr || size <= 0)
		return -1;

	int index1 = 0;
	int index2 = size - 1;
	int indexMid = 0;
	//利用二分查找，每次比较中间值和边界值，缩小查找范围
	while (arr[index1] >= arr[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
       		indexMid = ((index1&index2) + ((index1^index2) >> 1));
		/*
			此类情况不能缩小范围：{1,1,1,1,0}旋转为{1,1,1,0,1}
			此时中间值和边界值相等只能采用顺序查找
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
/*方法一：利用二分法找到边界值再利用二分法查找*/
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
/*方法2：直接利用二分法确定有序区间的递归算法*/
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

		//确定有序的区间并确定查找数据是否在里面
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
//调整数组寄偶数字位置
/*
	方法一：指针移动
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
//扩展：解决同类问题我们可以使用函数指针解决！
 
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
//数值中1的位数
int OneInNum(int data)
{
	int Count = 0;
	while (data)
	{
		//将数字二进制表示形式中最右边的一个1置0
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
//打印1到n位的最大数
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
//查找树的子结构
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
//矩阵的顺时针输出
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
//输入一个整数数组，判断该数组是不是某个二叉搜索树的后序遍历结果
bool IsBinarySearchPostOrder(int *arr,int size)
{
	if (arr == NULL)
		return false;
	int root = arr[size - 1];
	//确定左子树的位置
	int i = 0;
	for (; i < size; i++)
	{
		//左子树一直小于根节点
		if (arr[i] > root)
			break;
	}
	int j = i;
	for (; j < size; j++)
	{
		//如果已经进入右子树的界定范围那么出现了右子树小于根节点则视为错误情况
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
		left = IsBinarySearchPostOrder(arr, i);
	bool right = true;
	if (j < size - 1)
		right = IsBinarySearchPostOrder(arr + i, size - 1 - i);
	
	//左子树及右子树都是搜索树的后续遍历则正确
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
//找到数组里最小几位数
//方法1
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
//方法2
//利用STL红黑树
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
	解法一：利用保存最大值计算
			在本次进入循环的sum小于0时一定表示下一次加时会减小之后的和——>摒弃之前的数字从当前值开始计算
			否则直接将当前值加给sum 
			如果本次加的sum大于max则一定更新max
			如果并没有的话则保持该max不变
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
//计算从0到n的过程里数字1出现的次数
int NumOfOne(const char * str)
{
	if ( !str || *str > '9' || *str < '0')
		return 0;
	//first用于标记最高位的数字
	int first = *str - '0';
	int lenth = strlen(str);
	/*
		当最后一次递归进来时个位出现的1个个数只有两种情况:
		1.个位是0，则1出现的次数是0
		2.个位大于0，则1出现的次数是1
	*/
	if (lenth == 1 && *str == '0')
		return 0;
	if (lenth == 1 && *str > '0')
		return 1;

	/*
		OneInFirst标记了最高位的1出现了多少次
		此处分为两种情况：
		1.最高位为1，则出现了剩余的位数的数字+1次，比如132，则最高位出现的1的次数为100到132共33次
		2.最高位大于1,则1一定出现了100次，比如232,最高位出现的1的次数是100到199共100次
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
		//用highest表示最高位的数字
		long highest = n;
		int bit = 0;
		while (highest >= 10)
		{
				highest = highest / 10;
				bit++;
		}
		//最高位的权重
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
//水仙花数
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
