// LCOJ85.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

#define MAX 		10000

class Solution {
public:
	int maximalRectangle(vector<string> &matrix) {

		int numRows = matrix.size();
		int numColumns = matrix[0].size();

		int maxRect = 0, left = 0, curr = 0;
		bool leftUpZero = false, skip = false;
		int prev[MAX] = { 0 };

		for (int i = 0; i < numRows; i++){

			left = 1;
			for (int j = 0; j < numColumns; j++, left = 1){

				/*if (i == 0){
				
					if (matrix[i][j] == '0') { 
						prev[j] = j > 0 ? prev[j - 1] : 0;
						left = 1; 
					}
					else { prev[j] += left; left++; }
					continue;
				}

				if (j == 0){
				
					if (matrix[i][j] == '1') {
					
						prev[j]++;
						continue;
					}
					if (matrix[i - 1][j] == '0') break;
				}

				if (matrix[i][j] == '0'){
				
					if (i > 0 && matrix[i - 1][j] == '1') break;
					if (matrix[i - 1][j - 1] == '0') { prev[j] = prev[j - 1] > prev[j] ? prev[j - 1] : prev[j]; }
					if (matrix[i - 1][j] == '0' && matrix[i][j - 1] != '0') { prev[j] = prev[j - 1]; }
					if (matrix[i][j - 1] == '0' && matrix[i - 1][j] != '0') { prev[j] = prev[j]; }
					left = 1;
					maxRect = maxRect > prev[j] ? maxRect : prev[j];
				}
				else{
				
					if (matrix[i - 1][j] == '0' && matrix[i][j - 1] != '0') { prev[j] = prev[j - 1] + 1; continue; }
					if (matrix[i][j - 1] == '0' && matrix[i - 1][j] != '0') { prev[j] = prev[j] + 1; continue; }
					if (matrix[i - 1][j - 1] == '0') { prev[j] = prev[j] > prev[j - 1] ? prev[j] + 1 : prev[j - 1] + 1; continue; }
					prev[j] += left;
					left++;
					maxRect = maxRect > prev[j] ? maxRect : prev[j];
				}*/
				
				if (matrix[i][j] == '0') {

					left = 0;
					curr = 0;
					prev[j] = prev[j] > prev[j - 1] ? prev[j] : prev[j - 1];
					if (i > 0 && matrix[i - 1][j] == '1') break;
				}
				else if (!leftUpZero){
					// if this is not a 0
					if (!prev[j] && i > 0) leftUpZero = true;
					prev[j] = prev[j] + left;
					maxRect = maxRect > prev[j] ? maxRect : prev[j];
					left++;
				}
				else{
					// a situation that not a 0, but the left up cornor is 0
					left = 1;
					leftUpZero = false;
					if (!prev[j] && i > 0) leftUpZero = true;
					prev[j] = (prev[j - 1] + 1 > prev[j] + 1) ? prev[j - 1] + 1 : prev[j] + 1;
					maxRect = maxRect > prev[j] ? maxRect : prev[j];
				}
			}
		}
		return maxRect;
	}
};

int maximalRectangle(char **matrix, int numRows, int numColumns) {

	int maxRect = 0, left = 0, curr = 0;
	bool leftUpZero = true;
	int prev[MAX] = { 0 };

	for (int i = 0; i < numRows; i++){

		left = 0;
		for (int j = 0; j < numColumns; j++){

			if (matrix[i][j] == '0') {

				left = 0;
				curr = 0;
				prev[j] = 0;
			}
			else if (!leftUpZero){
				// if this is not a 0
				left++;
				if (!prev[j]) leftUpZero = true;
				prev[j] = prev[j] + left;
				maxRect = maxRect > prev[j] ? maxRect : prev[j];
			}
			else{
				// a situation that not a 0, but the left up cornor is 0
				left = 1;
				leftUpZero = false;
				if (!prev[j]) leftUpZero = true;
				prev[j] = (prev[j - 1] + 1 > prev[j] + 1) ? prev[j - 1] + 1 : prev[j] + 1;
				maxRect = maxRect > prev[j] ? maxRect : prev[j];
			}
		}
	}
	return maxRect;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> matrix = { "1010", "1011", "1011", "1111"};

	int res = Solution().maximalRectangle(matrix);

	return 0;
}