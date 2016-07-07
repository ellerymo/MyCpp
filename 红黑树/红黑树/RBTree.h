#include<iostream>
using namespace std;
enum Color
{
	RED,
	BLACK,
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	Color _col;
	K _key;
	V _value;
	RBTreeNode(const K key, const V value)
		:_key(key), _value(value), 
		_left(NULL), _right(NULL), _parent(NULL),
		_col(RED)
	{}
};
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V>  Node;
protected:
	Node* _root;
public:
	RBTree() :_root(NULL)
	{}
public:
	bool Insert(const K key, const V value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node *parent = NULL;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key >key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key > parent->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//颜色的调整
		while (cur != _root && (cur->_parent)->_col == RED)
		{
			Node*parent = cur->_parent;
			Node*grandpa = parent->_parent;
			//叔叔在右边
 			if (parent == grandpa->_left)
			{
				Node*uncle = grandpa->_right;
				//情况1 ：uncle存在且为红色
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandpa->_col = RED;
					cur = grandpa;
					_root->_col = BLACK;
					continue;
				}
				//单旋
				else if (cur == parent->_left)
				{
					parent->_col = BLACK;
					grandpa->_col = RED;
					RightR(grandpa);
				}
				//双旋
				else if (cur == parent->_right)
				{

					LeftR(parent);
					RightR(grandpa);
					swap(cur, parent);
					parent->_col = BLACK;
					grandpa->_col = RED;
				}
				cur = grandpa;
			}
			else
			{
				Node*uncle = grandpa->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandpa->_col = RED;
					cur = grandpa;
					_root->_col = BLACK;
					continue;
				}
				//单旋
				else if (cur == parent->_right)
				{
					parent->_col = BLACK;
					grandpa->_col = RED;
					LeftR(grandpa);
				}
				//双旋
				else if (cur == parent->_left)
				{
					RightR(parent);
					LeftR(grandpa);
					swap(cur, parent);
					parent->_col = BLACK;
					grandpa->_col = RED;
				}
				cur = grandpa;
			}
			_root->_col = BLACK;
		}

	}
	void LeftR(Node *& parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		Node*ppNode = parent->_parent;

		parent->_right = SubRL;
		if (SubRL)
			SubRL->_parent = parent;

		SubR->_left = parent;
		parent->_parent = SubR;

		if (ppNode)
		{
			if (ppNode->_left == parent)
				ppNode->_left = SubR;
			else
				ppNode->_right = SubR;
		}
		SubR->_parent = ppNode;
		if (parent == _root)
			_root = SubR;
	}
	void RightR(Node*& parent)
	{
		Node* SubL = parent->_left;
		Node *SubLR = SubL->_right;
		Node *ppNode = parent->_parent;

		parent->_left = SubLR;
		if (SubLR	)
			SubLR->_parent = parent;
		
		
		SubL->_right = parent;
		parent->_parent = SubL;

		if (ppNode)
		{
			if (ppNode->_left == parent)
				ppNode->_left = SubL;
			else
				ppNode->_right = SubL;
		}
		SubL->_parent = ppNode;
		if (parent == _root)
			_root = SubL;
	}
};