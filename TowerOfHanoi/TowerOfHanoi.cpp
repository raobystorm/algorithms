// TowerOfHanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>

inline int moveRecur(int n){

	if (n == 1) return 1;
	return 2 * moveRecur(n - 1) + 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n, res;
	clock_t start, end;
	while (1){
		
		scanf_s("%d", &n);
		start = clock();
		res = moveRecur(n);
		end = clock();
		printf_s("The result is:%d, using %f secs.\n", res, (double)end - start);
	}
	return 0;
}

