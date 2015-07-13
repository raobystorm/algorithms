// hihoOJ_1138.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define MAX 100002
#define INF 0x7f

int x[MAX], y[MAX], d[MAX];

int main()
{
	int n;
	cin >> n;
	memset(x, INF, sizeof(x));
	memset(y, INF, sizeof(y));
	memset(d, INF, sizeof(d));
	for (int i = 0; i < n; i++){
		scanf_s("%d%d", &x[i], &y[i]);
	}

	return 0;
}