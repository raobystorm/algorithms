// LCOJ_172.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// The answer is the same as how many times n could be divided by 5
int trailingZeroes(int n) {
	if (n / 5 == 0) return 0;
	return n / 5 + trailingZeroes(n / 5);
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

