// POJ_3624.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#define MAX		15000

int main(){

	int n, m, w, d, ans = 0;
	int max[MAX] = { 0 };

	scanf_s("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){

		scanf_s("%d %d", &w, &d);
		for (int j = MAX - 1; j >= 0; j--){

			if (w > j) break;
			else{

				max[j] = max[j] > d + max[j - w] ? max[j] : d + max[j - w];
			}
		}
	}

	printf_s("%d\n", max[m]);

	return 0;
}
