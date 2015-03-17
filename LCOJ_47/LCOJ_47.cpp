// LCOJ_47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:

	void checkPush(vector<vector<int>>& res, vector<int>& num){

		bool next = false;
	
		for (int i = res.size()-1; i >= 0; i--){
		
			next = false;
			for (int j = res[i].size()-1; j >= 0; j--){
			
				if (res[i][j] != num[j]) { 

					next = true;
					break; 
				}
			}

			if (next) continue;
			return;
		}

		res.push_back(vector<int>(num));
	}
	
	void PermuteRecur(vector<vector<int>>& res, vector<int>& num, int i){

		int j = i;

		if (j == num.size() - 1){

			res.push_back(num);
		}

		for (; j <= num.size() - 1; j++){

			if(num[i] != num[j]) swap(num[i], num[j]);
			PermuteRecur(res, num, i + 1);
			swap(num[i], num[j]);
		}
	}

	vector<vector<int>> permuteUnique(vector<int> &num) {

		if (!num.size()) return vector<vector<int>>();

		vector<vector<int>> res;

		PermuteRecur(res, num, 0);

		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1, 1, 2 };
	Solution s;

	vector<vector<int>> res = s.permuteUnique(nums);
	return 0;
}

