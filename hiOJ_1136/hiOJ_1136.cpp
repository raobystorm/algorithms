#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

#define MAX 100000

int main() {

  int t, m, n, tmpin, s;
  queue<int> signals;
  int count[MAX] = {0};
  unordered_map<int, list<int>*> modules;

  scanf("%d", &t);
  // Loop for the cases
  for( int i = 0; i < t; i++)
  {
    scanf("%d%d", &n, &m);

    signals = queue<int>();
    // Loop for reading initial signals
    for( int j = 0; j < m; j++)
    {
      scanf("%d", &tmpin);
      signals.push(tmpin);
    }
    // Loop for setting up modules
    for( int j = 0; j < n; j++)
    {
      count[j] = 0;
      scanf("%d", &tmpin);
      list<int> outputs;
      int k;
      scanf("%d", &k);
      for (int l = 0; l < k ; l++) {
        
        int tmp;
        scanf("%d",&tmp);
        outputs.insert(tmp);
      }

      modules[tmpin] =  &outputs;
    }    
    
    while (!signals.empty()) 
    {
      tmpin = signals.front();
      signals.pop();
      
      if(modulus.find(tmpin) != modules.end())
      {
        
    }

    for( int j = 0; j < n; j++)
    {
      modules[j].count %= 142857;
      printf("%d ", modules[j].count);
    }

    printf("\n");
  }
  return 0;
}

















