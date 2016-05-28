#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef int DataType;
struct BinaryTreeNode
{
	DataType _data;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
	BinaryTreeNode(DataType data = DataType()) 
		:_data(data),_left(NULL), _right(NULL)
	{}
};
class BinaryTree
{
private:
	BinaryTreeNode *_root;
public:
	BinaryTree() :_root(NULL)
	{}
	BinaryTree(const DataType *arr,size_t size, DataType invalid)
	{
		size_t index = 0;
		_root = _Create(arr,size,index,invalid);
	}
	BinaryTree(const BinaryTree& btree)
	{
		_root = _Copy(btree._root);
	}
	BinaryTree& operator=(BinaryTree btree)
	{
		swap(_root, btree._root);
	}
	~BinaryTree()
	{
		_Destroy(_root);
	}
public:
	void PrevOrder()
	{
		BinaryTreeNode *cur = _root;
		_PrevOrder(cur);
		cout << endl;
	}
	void PostOrder()
	{
		BinaryTreeNode *cur = _root;
		_PostOrder(cur);
		cout << endl;
	}
	void InOrder()
	{
		BinaryTreeNode *cur = _root;
		_InOrder(cur);
		cout << endl;
	}
	void LevelOrder()
	{
		cout << "LevelOrder :";
		_LevelOrder();
		cout << endl;
	}
	size_t Size()
	{
		size_t size = 0;
		_Size(_root,size);
		return size;
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	size_t LeafSize()
	{
		size_t leaves=0;
		return _LeafSize(_root,leaves);
	}
	void PrevOrderNoInDegrees()
	{
		stack< BinaryTreeNode* > s;
		if (_root)
		{
			cout << "PrevOrderNoInDegrees:";
			s.push(_root);
		}
		while (!s.empty())
		{
			BinaryTreeNode* top = s.top();
			s.pop();
			cout << top->_data << " -> ";
			if (top->_right)
				s.push(top->_right);
			if (top->_left)
				s.push(top->_left);
		}
		cout << "Over" << endl;
	}
	void InOrderNoInDegrees()
	{
		stack<BinaryTreeNode *> s;
		BinaryTreeNode *cur = _root;
		cout << "InOrderNoInDegrees:";
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			BinaryTreeNode*top = s.top();
			s.pop();
			cout << top->_data << "->";
			cur = top->_right;
		}
		cout << "Over" << endl;
	}

	void PostOrderNoInDegrees()
	{

		stack<BinaryTreeNode *> s;
		BinaryTreeNode *prev = NULL;
		BinaryTreeNode *cur = _root;
		cout << "PostOrderNoInDegrees:";

		while (cur || !s.empty())
		{
			
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			BinaryTreeNode *top = s.top();
			if (top->_right && top->_right != prev)
			{
				cur = top->_right;
			}
			else 
			{
				cout << top->_data << "->";
				prev = top;
				s.pop();
			}
		}
		cout << "Over"<<endl;
	}
	size_t NodeInklevel(size_t k)
	{
		size_t ret = _GetNodeInK(_root, k);
		return ret;
	}
	BinaryTreeNode *Find(const DataType& key)
	{
		BinaryTreeNode *ret = _Find(_root, key);
		return ret;
	}
	void FindIt(const int key)
	{
		vector<BinaryTreeNode* > v;
		int sum = 0;
		_FindRoadInSomeSize(v, key, _root, sum);
	}
	void _FindRoadInSomeSize(vector<BinaryTreeNode *>& v,const int key,BinaryTreeNode*root,int & sum)
	{
		//如果已经到了叶子节点并且路径长度不等于规定长度
		if (root == NULL && sum < key)
		{
			return;
		}
		if (root != NULL)
		{
			sum += root->_data;
			v.push_back(root);
		}
		if (sum == key)
		{
			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i]->_data << " ";
			}
			cout << endl;
			v.pop_back();
			sum -= root->_data;
			return;
		}
		else if (sum < key)
		{
			_FindRoadInSomeSize(v,key, root->_left, sum);
			_FindRoadInSomeSize(v, key, root->_right, sum);
		}
		v.pop_back();
		sum -= root->_data;
		return;
	}
	void Change()
	{
		BinaryTreeNode *prev = NULL;
		_ChangeToList(_root, prev);
	}
private:	
	void _ChangeToList(BinaryTreeNode *root, BinaryTreeNode *& prev)
	{
	
		if (!root)
			return;
		_ChangeToList(root->_left,prev);
		if (prev)
		{
			root->_left = prev;
			prev->_right= root;
		}
		prev = root;
		_ChangeToList(root->_right, prev);
	}
	BinaryTreeNode * _Find(BinaryTreeNode *root, const DataType & key)
	{
		if (!root)
			return NULL;
		if (root->_data == key)
			return root;
		else
		{
			BinaryTreeNode *ret = _Find(root->_left, key);
			if (ret)
				return ret;
			else
				return _Find(root->_right, key);
		}
	}
	size_t _GetNodeInK(BinaryTreeNode *root, size_t k)
	{
		if (!root)
			return 0;
		if (k == 1)
			return 1;
		return _GetNodeInK(root->_left,k-1)+_GetNodeInK(root->_right,k-1);
	}
	void _Destory(BinaryTreeNode * root)
	{
		if (root)
		{
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}
	}
	BinaryTreeNode* _Create(const DataType *arr,size_t size,size_t& index,DataType invalid)
	{
		BinaryTreeNode *Root = NULL;
		if (arr[index] != invalid && index < size )
		{
			Root = new BinaryTreeNode(arr[index]);
			Root->_left = _Create(arr,size,++index, invalid);
			Root->_right = _Create(arr,size,++index, invalid);
		}
		return Root;
	}
	BinaryTreeNode* _Copy(BinaryTreeNode * Root)
	{
		BinaryTreeNode *root = NULL;
		if (Root)
		{
			root = new BinaryTreeNode(Root->_data);
			root->_left = _Copy(Root->_left);
			root->_right = _Copy(Root->_right);
		}
		return root;
	}
	void _PrevOrder(BinaryTreeNode* root)
	{
		if (root)
		{
			cout << root->_data<<" ";
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
		return;
	}
	void _PostOrder(BinaryTreeNode* root)
	{
		if (root)
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
		return;
	}
	void _InOrder(BinaryTreeNode* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}
	size_t _Size(BinaryTreeNode * root,size_t& size)
	{
		if (root)
		{
			size++;
			_Size(root->_left,size);
			_Size(root->_right, size);
		}
		return size;
	}
	size_t _Depth(BinaryTreeNode * root)
	{
		if (!root)
		{
			return 0;
		}
		int left = _Depth(root->_left) + 1;
		int right = _Depth(root->_right) + 1;
		return left > right ? left : right;

	}
	size_t _LeafSize(BinaryTreeNode * root,size_t& leaves)
	{
		if (root&&!(root->_left)&&!(root->_right))
		{
			leaves++;
		}
		else if (root)
		{
			_LeafSize(root->_left,leaves);
			_LeafSize(root->_right,leaves);
		}
		return leaves;
	}
	void _LevelOrder()
	{
		queue<BinaryTreeNode *> q;
		BinaryTreeNode *cur = _root;
		if (cur)
		{
			q.push(cur);
		}
		while (!q.empty())
		{
			BinaryTreeNode* top = q.front();
			if (top->_left)
				q.push(top->_left);
			if (top->_right)
				q.push(top->_right);
			q.pop();
			cout << top->_data << " ";
		}
	}
};
