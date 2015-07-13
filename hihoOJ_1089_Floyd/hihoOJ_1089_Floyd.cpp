// hihoOJ_1089_Floyd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 105
using namespace std;

void floyd(vector<vector<short>>& map, int n){
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
}

int main()
{
	int n, m, j, k, w;
	cin >> n >> m;
	vector<vector<short>> map(n + 1, vector<short>(n + 1, SHRT_MAX));
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	while (m--){
		scanf_s("%d%d%d", &j, &k, &w);
		if(map[j][k] > w) map[j][k] = map[k][j] = w;
	}
	floyd(map, n);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	return 0;
}

