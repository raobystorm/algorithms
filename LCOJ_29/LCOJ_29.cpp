// LCOJ_29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#define MAX_INT				1<<30

using namespace std;

int divide(int dividend, int divisor) {
		
	long a = labs(dividend);
	long b = labs(divisor);
	long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	if (b == 0 || dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
	else if (b == 1) {
		return sign * a;
	}

	long result = 0;
	int i = 0;
	while (a >= b) {
		i = 0;
		while (a >= b << i) {
			a -= b << i;
			result += 1 << i;
			i++;
		}
	}
	return (sign * result);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int res = divide((int)(0 - 2147483648), (int)(2));
	return 0;
}

