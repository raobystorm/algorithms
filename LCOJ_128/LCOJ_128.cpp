
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		int maxx = 0;
		for (int i = 0; i < nums.size(); i++)
			maxx = max(nums[i], maxx);
		bool* map = (bool*)malloc(maxx);
		for (int i = 0; i < )
	}
};

int main(){

	return 0;
}