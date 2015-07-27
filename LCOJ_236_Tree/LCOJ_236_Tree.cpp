#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void bfs(TreeNode* t, unordered_map<int, int>& chain, unordered_map<int, TreeNode*>& ptrs){
		if(t->left != nullptr){
			chain[t->left->val] = t->val;
			ptrs[t->left->val] = t->left; 
			bfs(t->left, chain);
		}
		if(t->right != nullptr){
			chain[t->right->val] = t->val;
			ptrs[t->right->val] = t->right; 
			bfs(t->right, chain);
		}
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root = nullptr) return nullptr;
        unordered_map<int, int> chain;
        unordered_map<int, TreeNode*> ptrs;
        TreeNode* res;
        unordered_set<int> list;

        ptrs[toor->val] = root;
        bfs(root, chain, ptrs);
        int curr = p->val;
        while(chain.find(curr) != chain.end()){
        	list.insert(curr);
        	curr = chain[curr];
        }
        res = q;
        while(list.find(res->val) == list.end()){
        	res = chain[res];
        }
        return ptrs[res];
    }	
};

int main(){

}