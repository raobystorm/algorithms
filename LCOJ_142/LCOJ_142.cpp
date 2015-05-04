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
  ListNode* next;
};

ListNode *detectCycle(ListNode *head) {
  
  if(head == NULL) return NULL;
  ListNode* fast = head;
  ListNode* slow = head;
  
  while(fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow) break;
  }
  if(fast == NULL || fast->next == NULL)
    return NULL;
  
  slow = head;
  while(slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

int main(int argc, char *argv[])
{
  ListNode* res = detectCycle(NULL);
  
  return 0;
}
