// COJ_Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
using namespace std;

int solution(vector<int> &A) {
	// write your code in C++11

	if (A.size() == 0) return -1;
	if (A.size() == 1) return 0;

	long long left, right;
	left = 0, right = 0;
	for (int i = 1; i < A.size(); i++){
		right += A[i];
	}

	int i = 0;
	while (left != right && i < A.size() - 1){
		left += A[i];
		right -= A[i + 1];
		i++;
	}

	if (i != A.size() - 1) return i;
	else if (left == 0) return A.size() - 1;
	else return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

