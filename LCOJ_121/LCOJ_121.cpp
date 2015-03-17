// LCOJ_121.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int maxProfit(int prices[], int n){

	if (n<=1) return 0;
	int max = 0, min = prices[0];
	for (int i = 1; i < n; i++){
	
		if (prices[i] < min) { min = prices[i]; continue; }
		if (prices[i] - prices[i - 1] < 0) continue;
		if (prices[i] - min > max) max = prices[i] - min;
	}
	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

