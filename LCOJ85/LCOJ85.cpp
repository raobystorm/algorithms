// LCOJ85.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n, 0);
		vector<int> right(n, n);
		vector<int> height(n, 0);
		int res = 0;
		for (int i = 0; i < m; i++){
			int curr_left = 0, curr_right = n;
			for (int j = 0; j < n; j++){
				if (matrix[i][j] == '1'){
					height[j]++;
					left[j] = max(left[j], curr_left);
				}
				else{
					height[j] = 0;
					left[j] = 0;
					curr_left = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; j--){
				if (matrix[i][j] == '1') right[j] = min(right[j], curr_right);
				else{
					right[j] = n;
					curr_right = j;
				}
			}
			for (int j = 0; j < n; j++){

				res = max(res, (right[j] - left[j]) * height[j]);
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> matrix = { "1010", "1011", "1011", "1111"};

	int res = Solution().maximalRectangle(matrix);

	return 0;
}