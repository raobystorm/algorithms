// LCOJ_191.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = n&1;
		while (n) res += ((n >>= 1) & 1);
		return res;
	}
};

int main()
{
	Solution s;
	int res = s.hammingWeight(11);
	return 0;
}

