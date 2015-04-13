#include <fstream>
#include <iostream>
#include <time.h>

#using namespace std;

inline int Rand(int a, int b)
{
  float f = rand()/RAND_MAX;
  return a + (b-a)*f;
}

int main()
{
  ofstream fout("test_data");
  srand(time(NULL));

  int n;

  cout<<"Please input the size of data"<<endle;
  cin>>n;

  for(int 

  
