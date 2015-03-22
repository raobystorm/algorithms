// LCOJ_55.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool canJump(int A[], int n) {

	int max = 0;
	for (int i = 0; i<n; i++){
		if (i>max) { return false; }
		max = A[i] + i> max ? A[i] + i:max;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[2] = { 2, 0};
	bool b = canJump(A, 2);
	return 0;
}

