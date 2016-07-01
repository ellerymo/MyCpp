#include<stdio.h>
#include<iostream>
#include"Heap.h"

using namespace std;
template<class T>
struct HuffmanTreeNode
{
	HuffmanTreeNode<T>* _left;
	HuffmanTreeNode<T>* _right;
	T _weight;
	HuffmanTreeNode(const T data = 0)
		:_weight(data), _left(NULL), _right(NULL)
	{}
};

template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T>  Node;
public:
	Node * _root;
public:
	HuffmanTree(const T *arr, int n, T invalid)
	{
			struct Comp
			{
				bool operator() (const Node* node1, const Node* node2)
				{
					return node1->_weight < node2->_weight;
				}
			};
			/*
				��������Чֵnew�ɽڵ㱣����node��������
			*/
			Node **node = new Node*[n];
			int j = 0;
			for (int i = 0; i < n; j++, i++)
			{
				//��ֵ�Ƿ�ʱ������new�ڵ㲻����������ǹ����С����
				while (i < n && arr[i] == invalid)
					i++;
				if (i != n)
					node[j] = new Node(arr[i]);
			}
			int  n1 = j-1;
			Heap<Node*, Comp> hp(node, n1);
			while (hp.size() > 1)  
			{
				Node*left = hp.top();
				hp.pop();
				Node *right = hp.top();
				hp.pop();
				Node *parent = new Node((left->_weight) + (right->_weight));
				parent->_left = left;
				parent->_right = right;
				hp.push(parent);
			}
			_root = hp.top();
	}
	Node * GetRoot()
	{
		return  _root;
	}
};