#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
      vector<vector<int> > res;
      if(!numRows) return res;
      res = vector<vector<int> >(numRows);
      for(int i = 0; i < numRows; i++){
	
	vector<int> line(i+1);
	for(int j = 0; j <= i; j++){
	  
	  if( j == i)
	    line[j] = 1;
	  
	  else
	    line[j] = res[i-1][j-1] + res[i-1][j];
	}
	res[i] = line;
      }
      
      return res;
    }
};
