// ACOJ_Indeed_nau_A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>

#define MAX 1000000

using namespace std;

bool comp(int a, int b){
	return a > b;
}

int main()
{
	int n, q, counter, vol, border, tmp, nn;
	int *score;
	bool allO = true;

	cin >> n;
	nn = n;
	score = (int*)malloc(sizeof(int)*n);
	memset(score, 0, sizeof(int)*n);

	for (int i = 0; i < n; i++){

		scanf_s("%d", &tmp);
		if (tmp) score[i] = tmp;
		else nn--;
		if (score[i]) allO = false;
	}

	if (allO){
		cin >> q;
		while (q--){
			cin >> tmp;
			cout << 0 << endl;
		}
		
		return 0;
	}

	sort(score, score + n, comp);
	cin >> q;

	for (int i = 0; i < q; i++){

		scanf_s("%d", &vol);
		if (vol >= nn) printf("0\n");
		else printf("%d\n", score[vol] + 1);
	}

	return 0;
}

