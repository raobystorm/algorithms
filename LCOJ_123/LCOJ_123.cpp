// LCOJ_123.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int maxProfit(int prices[], int n, int k) {

	int hold1 = -13203465, hold2 = -2516545;
	int release1 = 0, release2 = 0;
	for (int i = 0; i < n; i++){													// Assume we only have 0 money at first
		release2 = release2 > hold2 + prices[i] ? release2 : hold2 + prices[i];		// The maximum if we've just sold 2nd stock so far.
		hold2 = hold2 > release1 - prices[i] ? hold2 : release1 - prices[i];		// The maximum if we've just buy  2nd stock so far.
		release1 = release1> hold1 + prices[i] ? release1 : hold1 + prices[i];		// The maximum if we've just sold 1nd stock so far.
		hold1 = hold1 > -prices[i] ? hold1 : -prices[i];							// The maximum if we've just buy  1st stock so far. 
	}                                     
	return release2;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int prices[15] = {2, 4, 1, 6, 3, 4, 8, 10, 2, 7, 10, 11, 2, 6, 11};
	int res = maxProfit(prices, 15);
	return 0;
}

