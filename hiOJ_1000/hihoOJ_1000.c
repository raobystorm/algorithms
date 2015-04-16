#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  //printf("Please input:\n");
  
  while(scanf("%d %d", &a, &b))
  {
    printf("%d\n", a+b);
  }
  return 0;
}

