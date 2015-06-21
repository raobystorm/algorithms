// ACOJ_40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>

#define MAX 100000

using namespace std;

void task1(){
	int r = 0, b = 0;
	char c;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){

			cin >> c;
			if (c == 'R') r++;
			if (c == 'B') b++;
		}

	if (r == b) cout << "DRAW" << endl;
	else if (r>b) cout << "TAKAHASHI" << endl;
	else cout << "AOKI" << endl;
}

double exp(int x){

	if (x == 1 || x == 2) return 1.0;
	if (x == 3) return 5.0 / 3.0;

	return (1.0 + exp(x - 2))/2.0 + (1.0 + exp(x-3))/2.0;
}

int main()
{
	int n;
	double d = 0;
	double dp[MAX];
	dp[0] = 0.0;
	dp[1] = 1.0;
	dp[2] = 1.0;
	dp[3] = 5.0 / 3.0;

	for (int i = 4; i < MAX; i++)
		dp[i] = (1.0 + dp[i - 2]) / 2.0 + (1.0 + dp[i - 3]) / 2.0;

	while (true){
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}

