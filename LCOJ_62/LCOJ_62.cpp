// LCOJ_62.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX 101

int uniquePaths(int m, int n) {

	int map[MAX][MAX] = { 0 };
	for (int i = 0; i < m; i++){

		for (int j = 0; j < n; j++){

			if (i == 0 || j == 0) { map[i][j] = 1; continue; }

			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}

	map[0][0] = 1;

	return map[m - 1][n - 1];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = uniquePaths(3, 3);
	return 0;
}

