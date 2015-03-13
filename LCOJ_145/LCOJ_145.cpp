// LCOJ_145.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {

		stack<TreeNode*> nodes;
		vector<int> res;

		if (!root) return res;
		nodes.push(root);

		while (nodes.size()){

			TreeNode* node = nodes.top();                                                                 
			nodes.pop();

			res.push_back(node->val);

			if (node->right != NULL){
			
				if (node->left != NULL) nodes.push(node->left);
				nodes.push(node->right);
			}
			else if (node->left != NULL) nodes.push(node->left);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	TreeNode t1(3),t2(1),t3(2);

	t1.left = &t2;
	t1.right = &t3;
	Solution s;

	vector<int> res = s.postorderTraversal(&t1);

	return 0;
}

