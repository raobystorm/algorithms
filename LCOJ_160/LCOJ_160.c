
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct LsitNode 
{
  int val;
  struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

  if( headA == NULL || headB ==NULL) return NULL;
  
  struct ListNode* l1 = headA;
  struct ListNode* l2 = headB;

  while( l1 != NULL || l2 != NULL)
  {
    if( l1->val == l2->val) return l1;
    
    l1 = l1->next;
    l2 = l2->next;

    if( l1 == NULL && l2 != NULL) l1 = headB;
    if( l2 == NULL && l1 != NULL) l2 = headA;
  }

  return l1;
}
