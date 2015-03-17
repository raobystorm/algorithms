
#include "stdafx.h"
#include "RBTree.h"

template<typename T>
RBNode<T>::RBNode():color(false), parent(NULL), left(NULL), right(NULL){}

template<typename T>
RBNode<T>::RBNode(T val){

	RBNode<T>();
	value = val;
}

// note this destructor is recursive
template<typename T>
RBNode<T>::~RBNode(){

	if (left != NULL) left->~RBNode<T>();
	if (right != NULL) right->~RBNode<T>();

	left = NULL;
	right = NULL;
	parent = NULL;
	color = false;
}

template<typename T>
RBNode<T>* RBNode<T>::grandparent(){

	if (parent == NULL) return NULL;
	return parent->parent;
}

template<typename T>
RBNode<T>* RBNode<T>::uncle(){

	if (!grandparent()) return NULL;
	if (grandparent()->left == parent) return grandparent()->right;
	else return grandparent()->left;
}

template<typename T>
RBTree<T>::RBTree():root(NULL){}

template<typename T>
RBTree<T>::RBTree(RBNode<T>* rt){ root = rt;}

template<typename T>
RBTree<T>::RBTree(T val){ root = new RBNode<T>(val); }

template<typename T>
RBTree<T>::~RBTree(){ 

	if (!root) return;
	root->~RBNode<T>();
}

template<typename T>
RBNode<T>* RBTree<T>::find(RBNode<T>* node){

	if (!node) return NULL;

	RBNode<T>* curr = root;

	while (curr != NULL){
	
		if (curr->value == node->value) return curr;

		if (node->value < curr->value) curr = curr->left;
		if (node->value > curr->value) curr = curr->right;
	}
	return NULL;
}

template<typename T>
RBNode<T>* RBTree<T>::find(T val){

	RBNode<T> node(T);

	return find(node);
}

template<typename T>
RBNode<T>* RBTree<T>::leftRotate(RBNode<T>* node){

	RBNode<T>* rotNode = find(node), rightNode;
	if (rotNode == NULL || rotNode->right == NULL) return;

	rightNode = rotNode->right;
	rightNode->parent = rotNode->parent;
	rotNode->parent = rightNode;

	rotNode->right = rightNode->left;
	rightNode->left = rotNode;

	return rightNode;
}

template<typename T>
RBNode<T>* RBTree<T>::leftRotate(T value){

	RBNode<T>* rotNode = find(value);
	return leftRotate(rotNode);
}


template<typename T>
RBNode<T>* RBTree<T>::rightRotate(RBNode<T>* node){

	RBNode<T>* rotNode = find(node), leftNode;
	if (rotNode == NULL || rotNode->left == NULL) return;

	leftNode = rotNode->left;
	leftNode->parent = rotNode->parent;
	rotNode->parent = leftNode;

	rotNode->left = leftNode->right;
	leftNode->rightNode = rotNode;
	return leftNode;
}

template<typename T>
RBNode<T>* RBTree<T>::rightRotate(T value){

	RBNode<T>* rotNode = find(value);
	return rightRotate(rotNode);
}

// insert the node into RBT just as in BST
template<typename T>
RBNode<T>* RBTree<T>::insert(RBNode<T>* node){

	if (node == NULL || root == NULL) return;
	RBNode<T>* curr = root;
	node->color = true;
	while (curr){
	
		if (node->value > curr->value){
		
			if (curr->right != NULL) curr = curr->right;
			else{
			
				curr->right = node;
				node->parent = curr;
				return node;
			}
		}
		else if (node->value < curr->value){
		
			if (curr->left != NULL) curr = curr->left;
			else{

				curr->left = node;
				node->parent = curr;
				return node;
			}
		}
		else return curr;
	}
	// TODO: finish the insertion of RBT
}