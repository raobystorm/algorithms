// LCOJ_63.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#define MAX		102

int uniquePathsWithObstacles(int** obstacleGrid, int m, int n){

	int map[MAX][MAX] = { 0 };
	map[0][1] = 1;
	for (int i = 1; i <= m; i++){

		for (int j = 1; j <= n; j++){

			if (!obstacleGrid[i - 1][j - 1]) map[i][j] = map[i - 1][j] + map[i][j-1];
		}
	}

	return map[m][n];
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

