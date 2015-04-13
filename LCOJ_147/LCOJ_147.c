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

struct ListNode *insert(struct ListNode *head, struct ListNode *node)
{
  if( node == NULL) return head;
  
  struct ListNode *curr = head, *tmp = NULL;
  
  while( curr->next && curr->next->val < node->val)
    curr = curr->next;

  if(curr == head && node->val < curr->val)
  {
    head = node;
    node->next = curr;
    return head;
  }
  
  if(curr->next) tmp = curr->next;
  curr->next = node;
  node->next = tmp;
  return head;
}

struct ListNode *insertionSortList(struct ListNode *head) {

  if(head == NULL || head->next == NULL) return head;
  
  struct ListNode *curr = head->next, *next = curr;
  head->next = NULL;
  
  while(next != NULL)// || curr != NULL)
  {
    // Make sure break the linked list first
    if(next == curr) next = curr->next;
    curr->next = NULL;
    head = insert(head, curr);
    curr = next;
    if(next) next = next->next;
  }
  if(curr) head = insert(head, curr);
  
  return head;
}

int main()
{
  struct ListNode list[7];
  list[0].val = 6; list[0].next = &list[1];
  list[1].val = 3; list[1].next = &list[2];
  list[2].val = 5; list[2].next = &list[3];
  list[3].val = 2; list[3].next = &list[4];
  list[4].val = 1; list[4].next = &list[5];
  list[5].val = 4; list[5].next = &list[6];
  list[6].val = 7; list[6].next = NULL;

  struct ListNode *head = insertionSortList(&(list[0]));

  while(head != NULL)
  {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
  return 0;
  
}

