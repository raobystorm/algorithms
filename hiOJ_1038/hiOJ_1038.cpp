/*
  A 01 backsnack problem
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, value, need;
  int* mm = NULL;

  scanf("%d%d", &n, &m);

  mm = (int*)malloc(sizeof(int)*n*m);
  
  assert(mm);
  memset(mm, 0, m*sizeof(int));
  
  scanf("%d%d", &need, &value);

  for(int j = need; j < m; j++)
    mm[j] = value;
  
  for(int i = 1; i < n; i++)
  {
    scanf("%d%d", &need, &value);
    
    for(int j = 1; j < m; j++)
    {
      if(j<need) mm[i*m+j] = mm[(i-1)*m+j];
      else mm[i*m+j] = mm[(i-1)*m+j] > (mm[(i-1)*m+j-need]+value) ?
             mm[(i-1)*m+j] : (mm[(i-1)*m+j-need]+value);
    }
  }

  printf("%d\n", mm[(n-1)*m+m-1]);
  return 0;
}

        
  
  
