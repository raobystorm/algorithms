/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * Fill out 'n' to indicate how many elements return.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {

  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(){val = 0; left = NULL; right = NULL;}
};

#define MAX 10000

int *rightSideView(struct TreeNode *root, int *n) {
 
  TreeNode *prevList[MAX] = {0};
  TreeNode *currList[MAX] = {0};

  int *res = NULL, prevCount = 0, currCount;
  *n = 0;
  if(root == NULL) return res;
  
  currList[0] = root;
  prevCount = 1;
  res = (int*)malloc(sizeof(int) * MAX);
  res[0] = root->val;
  
  while(prevCount){

    (*n)++;
    currCount = 0;
    memcpy(prevList, currList, prevCount * sizeof(TreeNode*));
    memset(currList, prevCount, sizeof(TreeNode*));
    
    for(int i = 0; i < prevCount; i++){

      if(prevList[i]->left) currList[currCount++] = prevList[i]->left;
      if(prevList[i]->right) currList[currCount++] = prevList[i]->right;

      if(currCount) res[*n] = currList[currCount-1]->val;
            
    }

    prevCount = currCount;
  }
  return res;
  
}

int main(){
  
  TreeNode t1 , t2, t3 , t4, t5, t6, t7;
  t1.val = 1; t2.val = 2; t3.val = 3; t4.val = 4; t5.val = 5; t6.val = 6; t7.val = 7;
  
  t1.left = &t2; t1.right = &t3; t2.right = &t5; t3.right = &t4; t5.left = &t6;
  t5.right = &t7;

  int *res, *n;
  n = (int*)malloc(sizeof(int));
  res = rightSideView(&t1, n);

  printf("%d\n", *n);
  for(int i = 0; i < *n; i++)
    printf("%d\n", res[i]);
  printf("\n");
  
}




