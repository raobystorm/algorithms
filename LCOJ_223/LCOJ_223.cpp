// LCOJ_223.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		if (E >= C || G <= A || B >= H || F >= D)
			return (C - A)*(D - B) + (G - E)*(H - F);
		else
			return (C - A)*(D - B) + (G - E)*(H - F) - abs(max(A, E) - min(C, G))*abs(max(B, F) - min(D, H));
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

