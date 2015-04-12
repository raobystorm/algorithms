/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
  int val;
  struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {

  if(head == NULL || head->next == NULL) return false;

  struct ListNode * n1, * n2;
  n1 = head; n2 = head->next;
  while(n1 != NULL && n2 != NULL)
  {
    if(n1 == n2) return true;
    if(n1->next) n1 = n1->next;
    if(n2->next) n2 = n2->next;
    else return false;
    if(n1 == n2) return true;
    if(n2->next) n2 = n2->next;
    else return false;    
  }
  return false;
}

int main()
{
  struct ListNode n1, n2;
  n1.val = 1;
  n2.val = 2;
  n1.next = &n2;
  n2.next = &n1;
  printf("%d\n", hasCycle(&n1));
  return 0;
  
}
