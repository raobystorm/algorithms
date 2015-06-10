// LCOJ_27_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int> ex;
		for (auto i : nums){
			if (i != val) ex.push_back(i);
		}
		nums = ex;
		return ex.size();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

