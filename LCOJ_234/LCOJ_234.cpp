// LCOJ_234.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std; 

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		int n = 0;
		ListNode* curr = head, *prev = nullptr, *nxt, *tail = nullptr;
		bool res = true;
		while (curr != nullptr){ n++; tail = curr; curr = curr->next; }
		if (n <= 1) return true;
		int half = n - (n / 2);
		curr = head;
		for (int i = 0; i < half; i++){
			prev = curr;
			curr = curr->next;
		}
		nxt = curr->next;
		while (nxt != nullptr){
			curr->next = prev;
			prev = curr;
			curr = nxt;
			nxt = nxt->next;
		}
		curr->next = prev;
		prev = head;
		nxt = tail;
		for (int i = 0; i < half; i++){
			if (prev->val != nxt->val) { res = false; break; }
			prev = prev->next;
			nxt = nxt->next;
		}
		curr = tail->next;
		prev = tail;
		nxt = curr->next;
		while (nxt->next != curr){
			curr->next = prev;
			prev = curr;
			curr = nxt;
			nxt = nxt->next;
		}
		curr->next = prev;
		tail->next = nullptr;
		return res;
	}
};

int main()
{
	ListNode nodes[5];
	nodes[0].val = 1; nodes[0].next = &nodes[1];
	nodes[1].val = 1; nodes[1].next = &nodes[2];
	nodes[2].val = 2; nodes[2].next = &nodes[3];
	nodes[3].val = 1; nodes[3].next = &nodes[4];
	nodes[4].val = 1; nodes[4].next = nullptr;

	cout << Solution().isPalindrome(nodes) << endl;

	return 0;
}

