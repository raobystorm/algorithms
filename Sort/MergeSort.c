/**
 *
 * This is a C implemented version of merge sort.
 * Based on a self defined list structure described below
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

// Assume no repeat values in the list
struct ListNode
{
  int val;
  struct ListNode *next;
};

// Merge two sorted-list into one, update the head of list
struct ListNode* merge(struct ListNode* left, struct ListNode* right)
{
  // Keep head of the list
  struct ListNode* l = NULL; 
  if(left == NULL && right) return right;
  if(right == NULL && left) return left;
  // Use this point to link the elements again
  struct ListNode* curr = NULL;
  // Initialize the head part
  if(left->val < right->val)
  {
    l = left;
    left = left->next;
  }
  else
  {
    l = right;
    right = right->next;
  }
  curr = l;
  // Sort while merge
  while(left && right)
  {
    if(left->val < right->val)
    {
      curr->next = left;
      curr = curr->next;
      left = left->next;
    }
    else
    {
      curr->next = right;
      curr = curr->next;
      right = right->next;
    }
  }
  // Link the tail together
  if(left != NULL) curr->next = left;
  else if(right != NULL) curr->next = right;
  else curr->next = NULL;
  return l;
}

// Recursive part, divide the list into elements, then sort them up
struct ListNode* mergeSortRecur(struct ListNode* head, int len)
{
  if(head->next == NULL) return head;
  int half = (len / 2);
  if(half < 1) return head;
  
  struct ListNode* left = head;
  struct ListNode* right = head->next;
  struct ListNode* tmp = head;
  
  for(int i = 0; i < half - 1; i++)
  {
    right = right->next;
    tmp = tmp->next;
  }
  // Cut down the link
  tmp->next = NULL;

  if(left != NULL) left = mergeSortRecur(left, half);
  if(right != NULL) right = mergeSortRecur(right, len - half);
  return merge(left, right);
}

// Start-up func
struct ListNode *sortList(struct ListNode *head) {

  if(head == NULL) return NULL;
  int len = 1;
  struct ListNode* tmp = head;
  // Check the length
  while(tmp->next != NULL) {

    len++;
    tmp = tmp->next;
  }
    
  head = mergeSortRecur(head, len);
  return head; 
}

inline void swap(int* array, int* i, int* j)
{
  int tmp = array[*i];
  array[*i] = array[*j];
  array[*j] = tmp;
}

inline int Rand(int a, int b)
{
  float f = rand() * 1.0f / RAND_MAX;
  return a + (b-a)*f;
}

// Generate random array of size n without duplicates, range 0~n
void RandomArray(int size, int* array)
{
  int j;
  
  for(int i = 0; i < size; i++)
    array[i] = i;

  for(int i = 0; i < size - 1; i++)
  {
    j = Rand(i, size);
    swap(array, &i, &j);
  }
}

int main()
{

  int size;
  int* dataArray;

  struct ListNode* dataList;

  FILE* fp1 = fopen("UnsortedData", "w+");
  FILE* fp2 = fopen("SortedData", "w+");

  clock_t start, finish;
  double duration;
  
  printf("Please input the size of test data:\n");
  
  scanf("%d",&size);
  srand(time(NULL));

  dataArray = (int*)malloc(sizeof(int) * size);
  assert(dataArray);
  // Generate random data to sort
  RandomArray(size, dataArray);

  dataList = (ListNode*)malloc(sizeof(ListNode) * size);
  assert(dataList);

  for(int i = 0; i < size; i++)
  {
    fprintf(fp1, "%d ", dataArray[i]);
    dataList[i].val = dataArray[i];
    if(i<size-1)dataList[i].next = &(dataList[i+1]);
    else dataList[i].next = NULL;
  }

  start = clock();
  
  struct ListNode* head = sortList(&(dataList[0]));

  finish = clock();

  duration = (double)(finish - start) / CLOCKS_PER_SEC;

  printf("Merge sorted in %f secs.\n", duration);

  start = clock();

  std::sort(dataArray, dataArray + size);

  finish = clock();

  duration = (double)(finish - start) / CLOCKS_PER_SEC;

  printf("STL sorted in %f secs.\n", duration);
  printf("Writting sorted data into file.\n");
                            
  while(head)
  {
    fprintf(fp2, "%d ", head->val);
    head = head->next;
  }

  printf("Finish!\n");

  if(fp1) fclose(fp1);
  if(fp2) fclose(fp2);

  if(dataArray != NULL) free(dataArray);
  if(dataList != NULL) free(dataList);
  
  return 0;
}

           
  
  
