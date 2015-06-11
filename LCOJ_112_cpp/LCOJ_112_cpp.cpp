// LCOJ_112_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	bool dfs(TreeNode* node, int sum){
	
		if (node == nullptr) return false;
		if (node->val == sum && node->left == nullptr && node->right == nullptr) return true;
		
		return dfs(node->left, sum - node->val) || dfs(node->right, sum - node->val);
	}

	bool hasPathSum(TreeNode* root, int sum) {

		return dfs(root, sum);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

