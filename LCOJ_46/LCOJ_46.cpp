// LCOJ_46.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;



class Solution {
public:

	void PermuteRecur(vector<vector<int>>& res, vector<int>& num, int i){

		int j = i;

		if (j == num.size() - 1){

			res.push_back(vector<int>(num));
		}

		for (; j <= num.size() - 1; j++){

			swap(num[i], num[j]);
			PermuteRecur(res, num, i + 1);
			swap(num[i], num[j]);
		}
	}

	vector<vector<int> > permute(vector<int> &num) {

		if (!num.size()) return vector<vector<int>>();

		vector<vector<int>> res;

		PermuteRecur(res, num, 0);

		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}