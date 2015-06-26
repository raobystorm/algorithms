// LCOJ_228_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		string tmp;
		if (&nums == nullptr) return res;
		for (int i = 0;i < nums.size();i++)
		{
			int s = i, e = s;
			for (; e < nums.size() - 1; e++){
				if (nums[e + 1] != nums[e] + 1) break;
			}
			if (s == e){
				tmp = to_string(nums[s]);
			}
			else{
				tmp = to_string(nums[s]) + "->" + to_string(nums[e]);
			}
			res.push_back(tmp);
			i = e;
		}
		return res;
	}
};

int main()
{
	int n[1] = {0};
	vector<int> nums;
	for (auto i : n) nums.push_back(i);
	vector<string> res;
	res = Solution().summaryRanges(nullptr);
	return 0;
}

