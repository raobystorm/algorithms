// LCOJ_239_Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	// implementation of data structure monotonic queue
	// all the elements in the queue is always sorted
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			// if the maximum is the element going out
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			// pop all the elements smaller than the coming number
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			// push the coming one into the queue
			dq.push_back(i);
			// build up the answer vector for this problem
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = { -95, 92, -85, 59, -59, -14, 88, -39, 2, 92, 94, 79, 78, -58, 37, 48, 63, -91, 91, 74, -28, 39, 90, -9, -72, -88, -72, 93, 38, 14, -83, -2, 21, 4, -75, -65, 3, 63, 100, 59, -48, 43, 35, -49, 48, -36, -64, -13, -7, -29, 87, 34, 56, -39, -5, -27, -28, 10, -57, 100, -43, -98, 19, -59, 78, -28, -91, 67, 41, -64, 76, 5, -58, -89, 83, 26, -7, -82, -32, -76, 86, 52, -6, 84, 20, 51, -86, 26, 46, 35, -23, 30, -51, 54, 19, 30, 27, 80, 45, 22 };
	vector<int> res = Solution().maxSlidingWindow(nums, 10);
	return 0;
}

