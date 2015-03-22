// LCOJ_188.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX 10000

int greedy(int prices[], int n){

	if (!n) return 0;
	int prof = 0;
	for (int i = 1; i < n; i++){

		if (prices[i] - prices[i - 1] > 0) prof += prices[i] - prices[i - 1];
	}
	return prof;
}

int maxProfit(int k, int prices[], int n) {

	int stocks[MAX];

	if (!k) return 0;
	if (k > n) return greedy(prices, n);

	for (int j = 0; j < k * 2; j++){

		if (j % 2 == 0) stocks[j] = -56565465;
		else stocks[j] = 0;
	}

	for (int i = 0; i < n; i++){

		stocks[0] = stocks[0] > -prices[i] ? stocks[0] : -prices[i];
		for (int j = 1; j < k * 2; j++){

			if (j % 2) stocks[j] = stocks[j] > stocks[j - 1] + prices[i] ? stocks[j] : stocks[j - 1] + prices[i];
			else stocks[j] = stocks[j] > stocks[j - 1] - prices[i] ? stocks[j] : stocks[j - 1] - prices[i];
		}
	}

	return stocks[2 * k - 1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

