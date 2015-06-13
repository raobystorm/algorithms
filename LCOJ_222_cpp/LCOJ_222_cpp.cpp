// LCOJ_222_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int calcExp(int n){
		if (n == 1) return 2;
		if (n == 0) return 1;
		return calcExp(n - 1) * 2;
	}
	
	void Count(TreeNode* node, int& leftCount, int& rightCount){

		if (node == nullptr) { leftCount = 0; rightCount = 0; return; }
		leftCount = 1; rightCount = 1;
		TreeNode* left = node->left;
		TreeNode* right = node->right;

		while (left != nullptr){
			leftCount++;
			left = left->left;
		}
		while (right != nullptr){
			rightCount++;
			right = right->right;
		}
	}
	// Recursively track the unblanced node and calculate the height of that node
	int trackUnbalanced(TreeNode* node, int& leftCount, int& rightCount){
		if (leftCount == rightCount){
			return calcExp(leftCount) - 1;
		}

		int leftleft = 0, leftright = 0, rightleft = 0, rightright = 0;
		Count(node->left, leftleft, leftright);
		Count(node->right, rightleft, rightright);

		if (leftleft != leftright && rightleft == rightright){
			return trackUnbalanced(node->left, leftleft, leftright) + calcExp(rightleft);
		}
		if (rightleft != rightright && leftleft == leftright){
			return trackUnbalanced(node->right, rightleft, rightright) + calcExp(leftleft);
		}
		return calcExp(leftleft) - 1 + calcExp(rightleft);
	}

	int countNodes(TreeNode* root) {

		if (root == nullptr) return 0;
		TreeNode* ptr = root;
		int leftCount = 0, rightCount = 0;
		Count(ptr, leftCount, rightCount);
		if (leftCount == rightCount)
			return calcExp(leftCount)-1;
		int res = trackUnbalanced(ptr, leftCount, rightCount);
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7), t8(8), t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;

	int res = Solution().countNodes(&t1);
	return 0;
}

