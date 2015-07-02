// LCOJ_164.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {

		int sSize = nums.size(), minV, maxV, i, bucket_size, bucket_num, bucket_id, last_max, maxGap;
		if (sSize>1)
		{
			minV = maxV = nums[0];
			for (i = 1; i<sSize; i++)
			{
				if (minV > nums[i]) minV = nums[i];
				else if (maxV < nums[i]) maxV = nums[i];
			}

			bucket_size = max(1, (maxV - minV) / (sSize - 1));
			bucket_num = (maxV - minV) / bucket_size + 1;

			if (bucket_num <= 1) return (maxV - minV);
			vector<int> bucket_max(bucket_num, INT_MIN);
			vector<int> bucket_min(bucket_num, INT_MAX);
			vector<int> bucket_count(bucket_num, 0);

			for (i = 0; i<sSize; i++)
			{
				bucket_id = (nums[i] - minV) / bucket_size;
				bucket_count[bucket_id]++;
				bucket_min[bucket_id] = bucket_min[bucket_id] > nums[i] ? nums[i] : bucket_min[bucket_id];
				bucket_max[bucket_id] = bucket_max[bucket_id] < nums[i] ? nums[i] : bucket_max[bucket_id];
			}

			last_max = minV;
			for (i = 0; i<bucket_num; i++)
			{
				if (bucket_count[i]>0)
				{
					maxGap = max(maxGap, bucket_min[i] - last_max);
					last_max = bucket_max[i];
				}
			}
			return maxGap;
		}
		return 0;
	}
};

int main(int argc, char *argv[])
{
	vector<int> nums(2, 0);
	nums[0] = 1; 
	nums[1] = 10000000;
	int res = Solution().maximumGap(nums);

	return 0;
}

