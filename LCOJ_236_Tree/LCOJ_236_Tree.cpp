// LCOJ_236_Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*stack<TreeNode*> bfs(TreeNode* root, TreeNode* obj){
		stack<TreeNode*> stk;
		queue<TreeNode*> q;
		unordered_set<TreeNode*> vis;
		TreeNode* curr = root;
		stk.push(curr);
		vis.insert(curr);

		while (curr != obj){
			if (curr->left != nullptr && vis.find(curr->left) == vis.end()){
				stk.push(curr->left);
				vis.insert(curr->left);
				curr = curr->left;
			}
			else if (curr->right != nullptr && vis.find(curr->right) == vis.end()){
				stk.push(curr->right);
				vis.insert(curr->right);
				curr = curr->right;
			}
			else{
				stk.pop();
				curr = stk.top();
			}
		}
		return stk;
	}*/

	bool dfs(stack<TreeNode*>& stk, TreeNode* curr, TreeNode* obj){
		stk.push(curr);
		if (curr == obj) return true;
		if (curr->left != nullptr && dfs(stk, curr->left, obj)) return true;
		if (curr->right != nullptr && dfs(stk, curr->right, obj)) return true;
		stk.pop();
		return false;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;

		stack<TreeNode*> pstk;
		dfs(pstk, root, p);
		stack<TreeNode*> qstk;
		dfs(qstk, root, q);
		unordered_set<TreeNode*> vis;
		TreeNode* res;

		while (!pstk.empty()){
			vis.insert(pstk.top());
			pstk.pop();
		}
		res = qstk.top();
		qstk.pop();
		while (vis.find(res) == vis.end()){
			res = qstk.top();
			qstk.pop();
		}
		return res;
	}
};

int main()
{
	TreeNode nodes[3];
	nodes[0].val = 1; nodes[0].right = &nodes[2]; nodes[0].left = &nodes[1];
	nodes[1].val = 2; nodes[2].val = 3;
	
	TreeNode* res = Solution().lowestCommonAncestor(&nodes[0], &nodes[1], &nodes[2]);
	return 0;
}

