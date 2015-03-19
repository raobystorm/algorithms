// LCOJ_122.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int maxProfit(int prices[], int n){

	int prof = 0;
	for (int i = 1; i < n; i++){
	
		if (prices[i] - prices[i - 1] > 0) prof += prices[i] - prices[i - 1];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

