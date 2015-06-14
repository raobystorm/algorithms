// LCOJ_221_c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <vector>

using namespace std;

#define hei 9
#define wid 11
#define MAX 102

class Solution {
public:
	int max(char a, char b){
		return a > b ? a : b;
	}
	int min(char a, char b){
		return a < b ? a : b;
	}

	int maximalSquare(vector<vector<char>>& matrix) {

		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

		vector<vector<char>> col = vector<vector<char>>(matrix.size() + 1, vector<char>(matrix[0].size() + 1, 0));
		vector<vector<char>> row = vector<vector<char>>(matrix.size() + 1, vector<char>(matrix[0].size() + 1, 0));
		vector<vector<char>> dp = vector<vector<char>>(matrix.size() + 1, vector<char>(matrix[0].size() + 1, 0));
		int res = 0;

		for (int i = 1; i <= matrix.size(); i++){
			for (int j = 1; j <= matrix[0].size(); j++){

				if (matrix[i - 1][j - 1] == '0'){
					col[i][j] = 0; row[i][j] = 0; dp[i][j] = 0;
				}
				else{
					if (i > 0) col[i][j] = col[i - 1][j] + 1;
					row[i][j] = row[i][j - 1] + 1;
					if (i > 1 && j > 1 && matrix[i - 2][j - 2] == '1' && (min(col[i][j], row[i][j]) >= dp[i - 1][j - 1] + 1))
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else if (dp[i - 1][j - 1] != 0) dp[i][j] = min(col[i][j], row[i][j]);
					else dp[i][j] = 1;
				}
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	/*char matrix[hei][wid] = {
		{ '1', '0', '1', '1', '1' },
		{ '0', '1', '0', '1', '0' },
		{ '1', '1', '0', '1', '1' },
		{ '1', '1', '0', '1', '1' },
		{ '0', '1', '1', '1', '1' }
	};*/

	/*char matrix[hei][wid] = {
		{ '1', '0', '1', '0', '0' },
		{ '1', '0', '1', '1', '1' },
		{ '1', '1', '1', '1', '1' },
		{ '1', '0', '1', '1', '1' },
		{ '0', '0', '0', '0', '0' }
	};*/

	char matrix[hei][wid] = { "0110010101", "0010101010", "1000010110", "0111111010", "0011111110", "1101011110", "0001100010", "1101100111", "0101101011" };

	vector<vector<char>> mm = vector<vector<char>>(hei, vector<char>(wid-1));

	for (int i = 0; i < hei; i++)
		for (int j = 0; j < wid-1; j++)
			mm[i][j] = matrix[i][j];

	int res = Solution().maximalSquare(mm);
	return 0;
}

