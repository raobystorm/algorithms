#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000

struct module
{
  int input;
  int count;

  vec
  
  module(): input(0), count(0), outputs(vector<module*>()){};
  
}modules[MAX];

int main() {

  int t, m, n, tmpin, s;
  queue<int> signals;
  
  scanf("%d", &t);

  for( int i = 0; i < t; i++)
  {
    scanf("%d%d", &n, &m);

    signals = queue<int>();

    for( int j = 0; j < m; j++)
    {
      scanf("%d", &tmpin);
      signals.push(tmpin);
    }

    for( int j = 0; j < n; j++)
    {
      scanf("%d", &tmpin);
      modules[j].count = 0;
      modules[j].input = tmpin;
      scanf("%d", &tmpin);
      modules[j].outputs = vector<int>(tmpin);
      for( int k = 0; k < modules[j].outputs.size(); k++)
      {
        scanf("%d", &tmpin);
        modules[j].outputs[k] = tmpin;
      }
    }

    

    while (!signals.empty()) 
    {
      tmpin = signals.front();
      signals.pop();
      
      for (int j = 0; j < n; j++)
        if(modules[j].input == tmpin)
        {
          modules[j].count++;
          for (int k = 0; k < modules[j].outputs.size(); k++) {
            signals.push(modules[j].outputs[k]);
          }
        }
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

















