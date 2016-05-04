#include<iostream>
using namespace std;
enum PointerTag
{
	LINK,
	THREAD
};

template<class T>
struct TreadBinaryTreeNode
{
	T _data;
	TreadBinaryTreeNode<T> *_left;
	TreadBinaryTreeNode<T> *_right;
	PointerTag _leftTag;
	PointerTag _rightTag;

	TreadBinaryTreeNode(const T&x)
		:_data(x),
		_left(NULL), _right(NULL),
		_rightTag(LINK), _leftTag(LINK)
	{}
};

template<class T>
class TreadingBinaryTree
{
private:
	TreadBinaryTreeNode<T> * _root;
public:
	TreadingBinaryTree()
		:_root(NULL)
	{}
	TreadingBinaryTree(const T *str,size_t size, T invalid)
	{
		size_t index = 0;
		_root = _CreateTree(str,size,invalid,index);
	}
	void PrevOrderTh()
	{
		TreadBinaryTreeNode<T> *prev = NULL;
		_PrevOrderTh(_root,prev);
	}
	void InOrderTh()
	{
		TreadBinaryTreeNode<T> * prev = NULL;
		_InOrderTh(_root,prev);
	}
	void PostOrderTh()
	{
		TreadBinaryTreeNode<T> * prev = NULL;
		_PostOrderTh(_root,prev);
	}
	//前序线索化遍历
	void PreOrderThd()
	{
		TreadBinaryTreeNode<T> *cur = _root;
		while (cur)
		{
			cout << cur->_data << " ";
			while (cur->_leftTag == LINK)
			{
				
				cur = cur->_left;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}
	void InOrderThd()
	{
		TreadBinaryTreeNode<T> *cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
	}
protected:
	//后序线索化
	void _PostOrderTh(TreadBinaryTreeNode<T>* root,
		TreadBinaryTreeNode<T> *& prev)
	{
		if (!root)
			return;
		TreadBinaryTreeNode<T>* cur = root;
		_PostOrderTh(root->_left,prev);
		root->_leftTag = THREAD;
		root->_left = prev;
		if (cur->_right != prev)
			_PostOrderTh(root->_right,prev);
		if (prev && !prev->_right)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
			prev = cur;
	}
	//中序线索化二叉树
	void _InOrderTh(TreadBinaryTreeNode<T>* root, 
		            TreadBinaryTreeNode<T> *& prev)
	{
		if (root == NULL)
			return;
		
		_InOrderTh(root->_left, prev);
		TreadBinaryTreeNode<T> *cur = root;
		if (root->_left == NULL)
		{
			root->_leftTag = THREAD;
			root->_left = prev;
		}
		if (prev && !prev->_right)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		_InOrderTh(root->_right,prev);
	}
	//前序线索化二叉树
	void _PrevOrderTh(TreadBinaryTreeNode<T> *root, 
					  TreadBinaryTreeNode<T> *& prev)
	{
		if (!root)
			return;
		TreadBinaryTreeNode<T>* cur = root;
		if (prev && !prev->_right)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		if (root->_left)
			prev = cur;
		_PrevOrderTh(root->_left,prev);
		if (!cur->_left && cur->_leftTag != THREAD)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
			prev = cur;
		}
		if (root->_right && root->_rightTag != THREAD)
			_PrevOrderTh(root->_right,prev);
		
	}
	//构建二叉树
	TreadBinaryTreeNode<T> *_CreateTree(const T *str,size_t size, T invalid,size_t & index)
	{
		TreadBinaryTreeNode<T> *Root = NULL;
		if ((str[index] != invalid) && (index < size))
		{
			Root = new TreadBinaryTreeNode<T>(str[index]);
			Root->_left = _CreateTree(str, size, invalid, ++index);
			Root->_right = _CreateTree(str, size, invalid, ++index);
		}
		return Root;
	}
};