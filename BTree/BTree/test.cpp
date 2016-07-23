#pragma once
#include<iostream>
using namespace std;

template <class K,int M>
struct BTreeNode
{
	K  _key[M];
	BTreeNode<K, M> *_subs[M + 1];
	BTreeNode<K, M> *_parent;
	size_t _size;
	BTreeNode()
		:_parent(NULL), 
		_subs(NULL), 
		_size(0)
	{}
};
template <class K , int M=3>
class BTree
{
	typedef BTreeNode<K, M> Node;
	public:
		BTree() :_root(NULL)
		{}
	private:
		Node* _root;

}
