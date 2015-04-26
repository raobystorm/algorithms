#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

#define MAX 100000

struct module
{
  int input;
  int count;
  list<int> outputs;
  // Use hash to map the signal into the output list of modules
  unordered_map< int, list<module*> >* modules;
  module(): input(0), count(0), outputs(NULL){};
  // DFS search on the modules when get inputs
  void activate()
  {
    if(outputs.size() == 0) return;

    list<int>::iterator itr = outputs.begin();

    while (itr != outputs.end()) {

      if(modules->find(*itr) != modules->end())
      {
        list<module*>::iterator litr = (*modules)[*itr].begin();
        while(litr != (*modules)[*itr].end())
        {
          (*litr)->count += 1;
          (*litr)->activate();
        }
      }
        
      itr++;
    }
  }
};

int main() {

  int t, m, n, tmpin, s;
  queue<int> signals;
  unordered_map<int, list<module*>> modules;
  unordered_map<int, list<module*>>::iterator mitr;
  
  
  scanf("%d", &t);
  // Loop for the cases
  for( int i = 0; i < t; i++)
  {
    scanf("%d%d", &n, &m);

    signals = queue<int>();
    modules = unordered_map<int, list<module*>>();
    mitr = modules.begin();
    // Loop for reading initial signals
    for( int j = 0; j < m; j++)
    {
      scanf("%d", &tmpin);
      signals.push(tmpin);
    }
    // Loop for setting up modules
    for( int j = 0; j < n; j++)
    {
      scanf("%d", &tmpin);
      if(modules.find(tmpin) == modules.end())
      {
        // This module has not been added into the map
        module tmpModule;
        tmpModule.input = tmpin;
        tmpModule.count = 0;
        tmpModule.activate();
        
        list<module*> newList;
        
        
      modules[j].count = 0;
      modules[j].input = tmpin;
      scanf("%d", &tmpin);
      modules[j].outputs = list<module*>();
      
      for( int k = 0; k < tmpin; k++)
      {
        if(mitr = modules.find(tmpin) == modules.end())
        {
          list<module*> tmplist;
          tmplist.insert(modules
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

















