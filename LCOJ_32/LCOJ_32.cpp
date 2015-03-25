// LCOJ_32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#define MAX		15000

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {

		int max = 0, left = 0, dp[MAX] = {0};
		dp[0] = 0;

		for (int i = 2; i < s.size() + 2; i++){

			if (s[i-2] == '('){

				left++;
			}
			else{

				if (left){

					dp[i] = dp[i - 1] + 2;
					dp[i] += dp[i - dp[i]];
					max = dp[i] > max ? dp[i] : max;
					left--;
				}
				else{

					max = dp[i - 1] > max ? dp[i - 1] : max;
					dp[i] = 0;
					left = 0;
				}
			}
		}
		return max;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int res = Solution().longestValidParentheses("(((())()");
	return 0;
}

