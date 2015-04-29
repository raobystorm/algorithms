
#include <stdlib.h>
#include <stdio.h>
#include <vector>

bool isHappy(int n) {
  std::vector<int> vec;
  while (n != 1){
    int temp = 0;
    while(n){
      temp += pow(n % 10, 2);
      n /= 10;
    }
    if (find(vec.begin(), vec.end(), temp) != vec.end()) return false;
    else vec.push_back(n = temp);
  }
  return true;
}

int int main(int argc, char *argv[])
{
  
  return 0;
}
