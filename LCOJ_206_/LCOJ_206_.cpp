// LCOJ_206_.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {

	if (head == NULL) return head;
	struct ListNode* next = head->next, *nnext;
	struct ListNode* curr = head;
	while (next != NULL){

		nnext = next->next;
		next->next = curr;
		if (curr == head) curr->next = NULL;
		curr = next;
		next = nnext;
	}
	return curr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct ListNode n1, n2, n3, n4, n5;
	n1.val = 1; n1.next = &n2;
	n2.val = 2; n2.next = &n3;
	n3.val = 3; n3.next = &n4;
	n4.val = 4; n4.next = &n5;
	n5.val = 5; n5.next = NULL;

	struct ListNode* res = reverseList(&n1);
	while (res != NULL){

		printf("%d ", res->val);
		res = res->next;
	}
	return 0;
}

