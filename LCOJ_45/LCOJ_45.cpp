// LCOJ_45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

int jump(int A[], int n) {

	if (n == 0) return 0;

	int preMax = A[0], max = A[0], step = 1;
	for (int i = 1; i <= n - 1 && i <= preMax; i++){
		
		max = A[i] + i > max ? A[i] + i : max;
		if (i == n - 1)return step;
		if (i == preMax){
		
			preMax = max;
			step++;
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[5] = { 1, 2, 3, 4, 5};
	int res = jump(A, 5);

	return 0;
}

