
#include "stdafx.h"

template<typename T>
struct RBNode{
public:
	bool color;			// black = false; red = true;
	T value;

	RBNode<T>* parent;
	RBNode<T>* left;
	RBNode<T>* right;

	RBNode<T>();
	~RBNode<T>();
	RBNode<T>(T);

	RBNode<T>* grandparent();
	RBNode<T>* uncle();
};

template<typename T>
struct RBTree{
public:
	RBNode<T>* root;

	RBNode<T>* leftRotate(T);
	RBNode<T>* leftRotate(RBNode<T>*);

	RBNode<T>* rightRotate(T);
	RBNode<T>* rightRotate(RBNode<T>*);

	RBNode<T>* insert(T);
	RBNode<T>* insert(RBNode<T>*);

	RBNode<T>* find(T);
	RBNode<T>* find(RBNode<T>*);

	RBNode<T>* deleteNode(T);
	RBNode<T>* deleteNode(RBNode<T>*);

	void traversal(int order);	// 1 = preorder, 0 = inorder, -1 = postorder

	RBTree<T>();
	RBTree<T>(RBNode<T>*);
	RBTree<T>(T);
	~RBTree<T>();
};