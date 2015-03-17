// LCOJ_69.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define MAX		65536

int binarySearch(int* n, int i, int j){

	if (j <= i + 1) return i;

	int tmp = ((j - i) / 2 + i)*((j - i) / 2 + i) - *n;

	if (tmp > 0){

		j = (j - i) / 2 + i;
		return binarySearch(n, i, j);
	}
	else if (tmp < 0){

		i = (j - i) / 2 + i;
		return binarySearch(n, i, j);
	}
	else return (j - i) / 2 + i;
}

int mySqrt(int x) {

	if (!x) return 0;
	int ans = binarySearch(&x, 0, MAX - 1);
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

