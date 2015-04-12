
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int minimumTotal(int **triangle, int numRows) {

  int * res;
  res = (int*)malloc(sizeof(int) * numRows);
  memcpy(res, triangle[numRows-1], sizeof(int) * numRows);

  if(numRows == 1) return triangle[0][0];
  
  // from bottom to the top, DP
  for(int i = 1; i < numRows; i++)
  {
    for(int j = 0; j < numRows-i; j++)
    {
      res[j] = triangle[numRows-i-1][j] + (res[j] > res[j+1] ? res[j+1] : res[j]);      
    } 
  }
  return res[0];
}

int main()
{
  int ** tri; int numRows = 4;
  int triangle[4][4] = 
    {
      {2,0,0,0},
      {3,4,0,0},
      {6,5,7,0},
      {4,1,8,3}      
    };

  tri = (int**)malloc(sizeof(int*)*numRows);
  for(int i = 0; i < numRows; i++)
  {
    tri[i] = (int*)malloc(sizeof(int)*(i+1));
    for(int j = 0; j <= i; j++)
    {
      tri[i][j] = triangle[i][j];
      printf("%d ", tri[i][j]);
    }
    printf("\n");    
  } 

  int res = minimumTotal(tri, numRows);
  printf("%d\n", res);
  
  return 0;
}
