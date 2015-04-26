
/**
 * Definition for singly-linked list.
 * 
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    
  if(head == NULL) return head;
  
  while(heada->val == val)
  {
    if(head->next == NULL) return NULL;
    head = head->next;
  }
  
  if(head->next == NULL)
  {
    if(head->val == val) return NULL;
    else return head;
  }

  struct ListNode* p1 = head->next;
  struct ListNode* p2 = head;
  struct ListNode* del = NULL;
  
  while(p1 != NULL)
  {
    if(p1->val == val) 
    {
      del = p1;
    }
    
    p1 = p1->next;

    if(del != NULL)
    {
      //free(del);
      p2->next = p1;
      del = NULL;
    }
    else
    {
      p2 = p2->next;
    }
  }
  return head;
}

int main()
{ 
  struct ListNode n1, n2, n3, n4, n5, n6, n7;
  n1.val = 1; n1.next = &n2;
  n2.val = 2; n2.next = &n3;
  n3.val = 6; n3.next = &n4;
  n4.val = 3; n4.next = &n5;
  n5.val = 4; n5.next = &n6;
  n6.val = 5; n6.next = &n7;
  n7.val = 6; n7.next = NULL;

  struct ListNode* head = removeElements(NULL, 6);
  
  while(head)
  {
    printf("%d\n", head->val);
    head = head->next;
  }
  return 0;
}
