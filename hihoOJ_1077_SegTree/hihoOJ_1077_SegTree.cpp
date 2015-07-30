// hihoOJ_1077_SegTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node{
	int l, r;
	short min;
	node* left,* right;
	node* parent;
	// Create segment tree recursively
	node(vector<short>& nums, int ll = 0, int rr = 0, node* p = nullptr){
		parent = p;
		if (ll == rr) {
			l = r = ll = rr;
			min = nums[l];
			left = right = nullptr;
			return;
		}
		l = ll; r = rr;
		int piv = l + (r - l) / 2;
		left = new node(nums, l, piv, this);
		right = new node(nums, piv + 1, r, this);
		min = std::min(left->min, right->min);
	}
	int query(int ll, int rr){
		if (l == r) return min;
		if (ll == l && rr == r) return min;
		// check if we need to query from both child segments or just one of them
		if (rr <= left->r) {
			return left->query(ll, rr);
		}
		else if (ll >= right->l){
			return right->query(ll, rr);
		}else{
			return std::min(left->query(ll, left->r), right->query(right->l, rr));
		}
	}
	void insert(int idx, short val){
		if (l == r && l == idx) { 
			node* curr = this;
			short tmp = min;
			min = val;
			// when we changed the value of one leaf
			// we should check all its ancestors, update the minimum values
			while (curr->parent != nullptr && curr->parent->min != std::min(curr->parent->left->min, curr->parent->right->min)){
				curr->parent->min = std::min(curr->parent->left->min, curr->parent->right->min);
				curr = curr->parent;
			}
			return;
		}
		if (idx <= left->r) left->insert(idx, val);
		else right->insert(idx, val);
	}
};

int main()
{
	int n, m, o, l, r; 
	cin >> n;
	vector<short> vec(n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &vec[i]);

	node* root = new node(vec, 0, vec.size() - 1);

	cin >> m;
	for (int i = 0; i < m; i++){
		scanf_s("%d%d%d", &o, &l, &r);
		if (o == 0){
			l--; r--;
			printf("%d\n", root->query(l, r));
		}
		else{
			l--;
			root->insert(l, r);
		}
	}
	return 0;
}

