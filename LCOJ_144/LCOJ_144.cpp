// LCOJ_144.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<int> preorderTraversal(TreeNode *root) {

		stack<TreeNode*> nodes;
		vector<int> res;

		if (!root) return res;
		nodes.push(root);

		while (nodes.size()){

			TreeNode* node = nodes.top();
			nodes.pop();

			res.push_back(node->val);

			if (node->left != NULL){

				if (node->right != NULL) nodes.push(node->right);
				nodes.push(node->left);
			}
			else if (node->right != NULL){

				nodes.push(node->right);
			}
		}
		return res;
	}
};

int main()
{
	ifstream input("in.txt");
	ofstream ouput("out.txt");

	return 0;
}

