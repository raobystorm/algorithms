// LCOJ_222_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	int countNodes(TreeNode* root) {

		if (root == nullptr) return 0;

		stack<TreeNode*> nodes;
		TreeNode* ptr = nullptr;
		int count = 0;
		nodes.push(root);

		while (!nodes.empty()){

			ptr = nodes.top();
			nodes.pop();
			if (ptr == nullptr) break;
			count++;
			if(ptr->right != nullptr) nodes.push(ptr->right);
			if(ptr->left != nullptr) nodes.push(ptr->left);
		}
		return count;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode t1(1), t2(2), t3(3);
	t2.left = &t1;

	int res = Solution().countNodes(&t2);
	return 0;
}

