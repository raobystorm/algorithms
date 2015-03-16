// LCOJ_100.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {

	if (p == NULL && q == NULL) return true;
	else if ((p == NULL) || (q == NULL)) return false;
	if (p->val != q->val) return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

