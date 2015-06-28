// LCOJ_204.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <bitset>

#define MAX INT_MAX

using namespace std;

int countPrimes(int n) {

	if (n == 0) return 0;

	char* bset = (char*)malloc(n - 1);
	memset(bset, 0, n - 1);
	int res = 0;
	for (int i = 2; i <= n-1; i++){
		if (bset[i] == 1) continue;
		res++;
		for (int j = 2; j <= (n - 1) / i; j++)
			bset[i*j] = 1;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = countPrimes(6);
	return 0;
}