// LCOJ_209.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>

int minSubArrayLen(int s, int* nums, int numsSize) {

	if (numsSize == 0) return 0;
	if (nums[0] > s) return 1;

	int *sum = (int*)malloc(sizeof(int)*numsSize);
	int min = numsSize;

	sum[0] = nums[0];
	for (int i = 1, j = -1; i < numsSize; i++){

		sum[i] = sum[i - 1] + nums[i];
		if (sum[i] < s) continue;
		while (sum[i] - sum[j] >= s) j++;
		j--;
		min = min < i - j ? min : i - j;
	}

	if (sum[numsSize-1] < s) return 0;
	else return min;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int A[3] = { 10, 2, 3};
	int res = minSubArrayLen(6, A, 3);
	return 0;
}

