// LCOJ_226_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct TreeNode* invertTree(struct TreeNode* root) {

	if (root == NULL) return NULL;

	if (root->left != NULL) invertTree(root->left);
	if (root->right != NULL) invertTree(root->right);

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	return root;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

