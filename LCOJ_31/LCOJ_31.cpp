// LCOJ_31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void reverse(vector<int>& v, int i, int j){
		while (i < j){ swap(v[i++], v[j--]); }
	}
	void nextPermutation(vector<int>& nums) {

		if (nums.empty() || nums.size() == 1) return;
		int i, j;
		for (i = nums.size() - 2; i >= 0; i--){
			if (nums[i] < nums[i + 1]) break;
			else if (i == 0) {
				sort(nums.begin(), nums.end());
				return;
			}
		}
		for (j = nums.size() - 1; j > i; j--){
			if (nums[j] > nums[i]) break;
		}
		swap(nums[j], nums[i]);
		reverse(nums, i + 1, nums.size() - 1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums = { 1,3,2 };
	Solution().nextPermutation(nums);
	return 0;
}

