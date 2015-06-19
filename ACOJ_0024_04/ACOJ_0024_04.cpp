// ACOJ_0024_04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#define MAX 400000

using namespace std;

int main()
{
	int a, b, c, row = 1, col = 1, ceil = 1000000007;
	cin >> a >> b >> c;
	int *left, *right, *tmp;
	bool loop = true;

	left = (int*)malloc(sizeof(int)*MAX);
	right = (int*)malloc(sizeof(int)*MAX);

	left[0] = 1; right[0] = 1;

	for (int i = 1; i < MAX; i++) left[i] = i + 1;
	while (loop){

		if (row != 1) {
			tmp = left;
			left = right;
			right = tmp;
		}
		row++;
		right[0] = 1;
		for (int i = 1; i < MAX; i++){
			right[i] = (left[i] + right[i - 1]) % ceil;

			if (right[i] > b * 2) break;

			if (left[i] == b && left[i - 1] == a && right[i - 1] == c){

				loop = false;
				col = i - 1;
				break;
			}
		}

		if (row >= MAX)
			return 0;
	}

	printf("%d %d\n", row - 1, col);

	return 0;
}

