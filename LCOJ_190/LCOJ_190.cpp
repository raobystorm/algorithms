// LCOJ_190.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int res = n&1, i = 31;
		while (i--) res = (n >>= 1) & 1 ? (res << 1) + 1 : res << 1;
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	uint32_t res = s.reverseBits(0);
	return 0;
}

