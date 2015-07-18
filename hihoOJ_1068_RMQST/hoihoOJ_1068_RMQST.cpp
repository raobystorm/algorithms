#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "math.h"

#define INT_MAX		2147483647

using namespace std;

int main()
{
	int n, m;
	ifstream in("in.txt");
	cin >> n;
	//in >> n;
	int lg = log2(n) + (double(n) > pow(2, log2(n)));

	// dp[i][j] stores the minimum element in the interval starts at num[i],
	// with the length 2^(j-1), i.e. for num = {9, 5, 6, 8} dp[0][2] = dp[0][1] = 5
	vector<vector<int> > dp(n + 1, vector<int>(lg, INT_MAX));
	for (int i = 1; i <= n; i++)
		scanf("%d", &dp[i][0]); // dp[i][0] = num[i]
		//in >> dp[i][0];

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 < n; i++) {
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}

	in >> m;
	while (m--) {
		int l, r;
		//in >> l >> r;
		scanf("%d%d", &l, &r);
		int k = trunc(log(r - l + 1));
		printf("%d\n", min(dp[l][k], dp[r - (1 << k) + 1][k]));
	}

	return 0;
}