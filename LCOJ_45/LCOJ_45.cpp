// LCOJ_45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

int jump(int A[], int n) {

	if (n <= 1) return 0;
	int idx = 0;
	int max[1000] = {0}, maxidx; // max distance of the i+1 steps could reach
	bool noloop = true;
	max[0] = A[0]> 1 ? A[0]: 1;
	if (max[0] >= n - 1) return 1;

	for (int i = 1; i < n; i++){
		int j = 0; // how many steps need to be here
		for (; j < 1000 && max[j] < i; j++);

		if (!j) j++;

		if (A[i] + j >= n - 1) return j + 1;

		if (A[i] + j > max[j]) { 
			
			max[j] = A[i] + j; 
		}
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[4] = { 1, 1, 1, 1};
	int res = jump(A, 4);
	return 0;
}

