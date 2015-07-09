// hihoOJ_1081.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#define INF 0x7f7f7f7f  
using namespace std;

const int MAX = 1005;
int n, m, s, t;
int map[MAX][MAX], dis[MAX], vis[MAX] = { 0 };

void dijk(int s)
{
	for (int i = 1; i <= n; i++) dis[i] = map[s][i];
	vis[s] = 1; dis[s] = 0;
	for (int i = 1; i<n; i++)
	{
		int min = INF, pos;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < min)
				min = dis[pos = j];
		if (min == INF) break;
		vis[pos] = 1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[pos] + map[pos][j] < dis[j])
				dis[j] = dis[pos] + map[pos][j];
	}
}

int main()
{
	scanf_s("%d %d %d %d", &n, &m, &s, &t);
	memset(map, 0x7f, sizeof(map));
	while (m--)
	{
		int x, y, w;
		scanf_s("%d %d %d", &x, &y, &w);
		map[x][y] = map[y][x] = min(map[x][y], w);
	}
	dijk(s);
	printf("%d\n", dis[t]);
	return 0;
}
