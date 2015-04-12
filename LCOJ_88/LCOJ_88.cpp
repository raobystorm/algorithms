// LCOJ_88.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

void merge(int A[], int m, int B[], int n) {
	for (int idx = m + n - 1; idx >= 0; idx--) {
		if (m <= 0) {
			A[idx] = B[--n];
		}
		else if (n <= 0) {
			break;
		}
		else if (A[m - 1] < B[n - 1]) {
			A[idx] = B[--n];
		}
		else {
			A[idx] = A[--m];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int m = 5, n = 1;
	int *A, B[1] = { 3 };
	A = (int*)malloc(sizeof(int) * (m + n));
	A[0] = 1;
	A[1] = 2;
	A[2] = 4;
	A[3] = 5;
	A[4] = 6;

	merge(A, m, B, n);

	for (int i = 0; i < m + n; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}

