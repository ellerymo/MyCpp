#pragma once
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node
{
	Node* _left;
	Node* _right;
	int _value;
	Node(const int & data)
		:_value(data),
		_right(NULL),
		_left(NULL)
	{}
};
class Tree
{
private:
	Node* _root;
public:
	Tree(const int*str, size_t size, int invalid)
	{
		int index = 0;
		_root = _Create(str, size, invalid, index);
	}
	Tree(const Tree& tree)
	{
		_root = _Copy(tree._root);
	}
	Tree& operator= (Tree tr)
	{
		swap(_root, tr._root);
		return *this;
	}
	~Tree()
	{
		_Del(_root);
	}
	void PreOrder()
	{
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout << endl;
	}

	//非递归遍历
	void Pre()
	{
		stack<Node*> st;
		if (_root)
			st.push(_root);
		else
			return;
		while (!st.empty())
		{
			Node* top = st.top();
			st.pop();
			//注意此处因为栈的顺序问题必须先压右边再压左边
			cout << top->_value << " ";
			if (top->_right)
				st.push(top->_right);
			if (top->_left)
				st.push(top->_left);
		}
		cout << endl;

	}
	void In()
	{
		stack<Node *> st;
		Node * cur = _root;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->_left;
			}
			Node*top = st.top();
			cout << top->_value << " ";
			cur = top->_right;
			st.pop();

		}
		cout << endl;
			
	}
	void Post()
	{
		Node *cur = _root;
		Node *prev = NULL;
		stack<Node *> st;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->_left;
			}
			Node*top = st.top();
			//此时cur为NULL,检查的是top即最后一个压入的元素,如果右边没有被访问过就push
			if (top->_right  && prev != top->_right)
			{
				cur = top->_right;
			}
			else
			{
				cout << top->_value << " ";
				prev = top;
				st.pop();
			}
		}
		cout << endl;
	}

private:
	//构造二叉树
	Node* _Create(const int*str, size_t size, int invalid, int &index)
	{
		Node *root = NULL;
		if (index < size&&str[index] != invalid)
		{
			root = new Node(str[index]);
			root->_left = _Create(str, size, invalid, ++index);
			root->_right = _Create(str, size, invalid, ++index);
		}
		return root;
	}

	//拷贝构造二叉树
	Node* _Copy(Node *root)
	{
		Node*Root = NULL;
		if (root)
		{
			Root = new Node(root->_value);
			Root->_left = _Copy(root->_left);
			Root->_right = _Copy(root->_right);
		}
		return Root;
	}

	//析构
	void _Del(Node *root)
	{
		if (!root)
			return;
		Node*del = root;
		_Del(root->_left);
		_Del(root->_right);
		delete root;
	}
	
	//前序遍历
	void _PreOrder(Node* root)
	{
		if (!root)
			return;
		cout << root->_value << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}
	//中序遍历
	void _InOrder(Node* root)
	{
		if (!root)
			return;
		_InOrder(root->_left);
		cout << root->_value << " ";
		_InOrder(root->_right);
	}
	//后序遍历
	void _PostOrder(Node* root)
	{
		if (!root)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_value << " ";

	}
};
