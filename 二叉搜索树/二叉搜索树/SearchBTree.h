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
	{
		_Delete(_root);
	}

public:	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
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
			
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				del = _root;
				if (cur == _root)
				{
					if (!cur->_left)
						_root = cur->_right;
					else if (!cur->_right)
						_root = cur->_left;
				}
				else if (!cur->_left)
				{
					del = cur;
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				else if (!cur->_right)
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
					if (left == parent->_right)
						parent->_right = left->_right;
					else
						parent->_left = left->_right;
				}
				delete del;
				break;
			}
		}
		return true;
	}
	bool InsertR(const K key, const V value)
	{
		return _InsertR(_root, key,value);
	}
	Node* FindR(const K key)
	{
		return _FindR(_root, key);
	}
	bool RemoveR(const K key)
	{
		return _RemoveR(_root, key);
	}
private:
	void _Delete(Node *root)
	{
		if (root == NULL)
			return;
		Node *cur = root;
		_Delete(root->_left);
		_Delete(root->_right);
		delete cur;
	}
	bool _RemoveR(Node *& root, const K key)
	{
		if (root == NULL)
			return false;
		if (root->_key == key)
		{
			Node *del = root;
			if (!root->_left)
				root = root->_right;
			else if (root->_right)
				root = root->_left;
			else
			{
				Node *& cur = root->_right;
				Node *& left = cur;
				while (left->_left)
					left = left->_left;
				del = left;
				swap(root->_key, left->_key);
				swap(root->_value, left->_value);
				left = left->_right;

			}
			delete del;
			return true;
		}
		else if (root->_key > key)
			_RemoveR(root->_left, key);
		else
			_RemoveR(root->_right, key);

	}
	Node *_FindR(Node *& root, const K key)
	{
		if (root == NULL)
			return NULL;
		if (root->_key == key)
			return root;
		if (root->_key < key)
			_FindR(root->_right,  key);
		else if (root->_key > key)
			_FindR(root->_left, key);

	}
	bool _InsertR(Node *& root, const K key, const V value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		if (root->_key > key)
			_InsertR(root->_left, key, value);
		else if (root->_key < key)
			_InsertR(root->_right, key, value);
		else
			return false;
	}
	void _InOrder(Node *root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
};