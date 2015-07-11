// test5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int countHear(vector<vector<int>>& pos, int x, int y, int d){
	double tmpd;
	int res = 0;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++){
			tmpd = sqrt((x - i)*(x - i) + (y - j)*(y - j));
			if (tmpd > d*1.0) continue;
			res += pos[i][j];
		}
	return res;
}

int set(vector<vector<int>>& pos, int x, int y, int d){
	double tmpd;
	int res = 0;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++){
			tmpd = sqrt((x - i)*(x - i) + (y - j)*(y - j));
			if (tmpd > d*1.0) continue;
			res += pos[i][j];
			pos[i][j] = 0;
		}
	return res;
}

int main()
{
	int n, x, y, d[3] = {0};
	cin >> d[0] >> d[1] >> d[2];
	sort(d[0], d[2]);
	cin >> n;
	vector<vector<int>> pos(9, vector<int>(9, 0));
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		pos[x][y]++;
	}

	int res = 0;

	for (int i = 0; i < 3; i++){
		int tmpmax = 0, tmp, jm, km;
		for (int j = 1; j <= 8; j++)
			for (int k = 1; k <= 8; k++){
				tmp = countHear(pos, j, k, d[i]);
				if (tmpmax < tmp) {
					tmpmax = tmp;
					jm = j; km = k;
				}
			}

		res += set(pos, jm, km, d[i]);
	}
	cout << res << endl;
	return 0;
}

