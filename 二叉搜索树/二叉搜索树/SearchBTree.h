#include<iostream>
using namespace std;
template<class K,class V>
struct SrBTreeNode
{
	SrBTreeNode* _left;
	SrBTreeNode* _right;
	K _key;
	V _value;
	SrBTreeNode(const K key, const V value)
		:_key(key), _value(value), _left(NULL), _right(NULL)
	{}
};
template<class K,class V>
class SrBTree
{
	typedef SrBTreeNode<K, V>  Node;
protected:
	Node* _root;
public:
	SrBTree() :_root(NULL)
	{}
	~SrBTree()
	{}
public:
	bool Insert(const K key, const V value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
		}
		Node *cur = _root;
		Node *parent = NULL;
		while (cur)
		{
			parent = cur;
			if (key > cur->_key)
				cur = cur->_right;
			else  if (key < cur->_key)
				cur = cur->_left;
			else
				return false;
		}
		if (parent->_key >key)
			parent->_left = new Node(key, value);
		else
			parent->_right = new Node(key, value);
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	Node* Find(const K key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				return cur;
		}
		return NULL;
	}
	bool Remove(const K key)
	{
		if (_root == NULL)
			return false;
		Node *cur = _root;
		Node *parent = NULL;
		Node *del = NULL;
		while (cur)
		{
			parent = cur;
			if (key > cur->_key)
				cur = cur->_right;
			else if (key < cur->_key)
				cur = cur->_left;
			else
			{
				if (cur == _root)
				{
					if (!cur->_left)
						_root = cur->_right;
					else if (!cur->_right)
						_root = cur->_left;
				}
				if (!cur->_left)
				{
					del = cur;
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				if (!cur->_right)
				{
					del = cur;
					if (parent->_left == cur)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				else
				{
					parent = cur;
					Node *left = cur->_right;
					while (left->_left)
					{
						parent = left;
						left = left->_left;
					}
					del = left;
					swap(left->_key, cur->_key);
					swap(left->_value, cur->_value);
					if (left = cur->_right)
						cur->_right = left->_right;
					else
						parent->_left = left->_right;
				}
				delete del;
				break;
			}
		}
		return true;
	}
private:
	void _InOrder(Node *root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
};