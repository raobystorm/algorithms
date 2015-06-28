// LCOJ_47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	void reverse(vector<int>& v, int i, int j){
		while (i < j){ swap(v[i++], v[j--]); }
	}

	vector<vector<int>> permuteUnique(vector<int> &a) {

		if (a.size() <= 1) return vector<vector<int>>(1, a);

		vector<vector<int>> res;

		sort(a.begin(), a.end());
		while (true){

			res.push_back(a);
		
			int i, j;
			for (i = a.size() - 2; i >= 0; i--){
				if (a[i] < a[i + 1]) break;
				else if (i == 0) return res;
			}

			for (j = a.size() - 1; j > i; j--){
				if (a[j] > a[i]) break;
			}
			swap(a[i], a[j]);
			reverse(a, i + 1, a.size() - 1);
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1, 2, 3 };
	Solution s;

	vector<vector<int>> res = s.permuteUnique(nums);
	return 0;
}

