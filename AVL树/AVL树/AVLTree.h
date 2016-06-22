#include<iostream>
using namespace std;
 template<class K,class V>
 struct AVLTreeNode
 {
	 AVLTreeNode<K, V>*	_left;
	 AVLTreeNode<K, V>*	_right;
	 AVLTreeNode<K, V>*	_parent;

	 int _bf;
	 K _key;
	 V _value;
	 AVLTreeNode(const K key, const V value)
		 :_key(key), _value(value),
		 _left(NULL), _right(NULL), _bf(0)
	 {}
 };
 template<class K, class V>
 class AVLTree
 {
	 typedef AVLTreeNode<K, V> Node;
 protected:
	 Node* _root;
 public:
	 AVLTree() :_root(NULL)
	 {}
 public:
	 bool Insert(const K key,const V value)
	 {
		 //插入
		 Node *cur = _root;
		 Node *parent = NULL;
		 if (_root == NULL)
		 {
			 _root = new Node(key, value);
			 return true;
		 }
		 while (cur)
		 {
			 if (cur->_key < key)
			 {
				 cur->_parent = parent;
				 parent = cur;
				 cur = cur->_right;
			 }
			 else if (cur->_key > key)
			 {
				 cur->_parent = parent;
				 parent = cur;
				 cur = cur->_left;
			 }
			 else if (cur->_key == cur->_value)
				 return false;
		 }
		 if (parent->_key > key)
		 { 
			 cur = new Node(key, value);
			 (cur)->_parent = parent;
			 parent->_left = cur;
		 }
			
		 else
		 {
			 cur = new Node(key, value);
			 (cur)->_parent = parent;
			 parent->_right = cur;
		 }
		 //调整平衡因子
		 while (cur)
		 { 
			 if (  cur == _root )
				 break;
			 if (cur == (cur->_parent)->_left)
			 {
				 (cur->_parent)->_bf--;
			 }
			 else if (cur == (cur->_parent)->_right)
			 {
				 (cur->_parent)->_bf++;
			 }
			 if ((cur->_parent)->_bf == 0)
				 break;
			 cur = cur->_parent;
			 //左单旋
			 if ((cur->_parent)->_bf == -2 && cur->_bf == -1)
				 LeftR(parent);
			//右单选
			 else if ((cur->_parent)->_bf == 2 && cur->_bf == 1)
				 RightR(parent);
			//左右双旋
			 else if ((cur->_parent)->_bf == 2 && cur->_bf == -1)
				 LeftRightR(parent);
			//右左双旋
			 else if ((cur->_parent)->_bf == -2 && cur->_bf == 1)
				 RightLeftR(parent);
		 }
	 }
 private:
	 void LeftR(Node *& parent)
	 {
		 Node* SubR = parent->_right;
		 Node* SubRL = SubR->_left;
		 Node*ppNode = parent->_parent;
		 
		 parent->_right = SubRL;
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
		 //更新平衡因子
		 parent->_bf = 0;
		 SubR->_bf = 0;
	 }
	 void RightR(Node*& parent)
	 {
		 Node* SubL = parent->_left;
		 Node *SubLR = SubL->_right;
		 Node *ppNode = parent->_parent;

		 parent->_left = SubLR;
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
		 if (parent == _root)
				 _root = SubL;
		 //更新平衡因子
		 parent->_bf = 0;
		 SubL->_bf = 0;
	 }
	 void LeftRightR(Node*& parent)
	 {
		 LeftR(parent->_left);
		 RightR(parent);
		 //纠正平衡因子
	 }
	 void RightLeftR(Node*& parent)
	 {
		 RightR(parent->_right);
		 RightR(parent);
		 //纠正平衡因子
	 }
 };