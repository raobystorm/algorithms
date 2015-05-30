// LCOJ_219.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		unordered_set<int> counted;
		for (int i = 0,j = 0; i < nums.size(); i++){
			if (counted.find(nums[i]) != counted.end()) return true;
			counted.insert(nums[i]);
			if (i >= k){

				counted.erase(nums[j]);
				j++;
			}
		}

		return false;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums(2);
	nums[0] = -1;
	nums[1] = -1;

	bool res = Solution().containsNearbyDuplicate(nums, 1);
	return 0;
}

