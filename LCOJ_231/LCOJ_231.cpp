// LCOJ_231.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include "math.h"

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		vector<int> pow2 = { 1, 2, 4, 8, 16, 32,
			64, 128, 256, 512, 1024, 2048,
			4096, 8192, 16384, 32768, 65536,
			131072, 262144, 524288, 1048576, 2097152,
			4194304, 8388608, 16777216, 33554432, 67108864,
			134217728, 268435456, 536870912, 1073741824 };
		unordered_set<int> hash;
		for (auto i : pow2)
			if (i == n) return true;
		return false;
	}
};

int main()
{
	ofstream out("out.txt");
	for (int i = 0; i <= log2(INT_MAX); i++){
		out << int(pow(2, i)) << " ";
	}
	out << endl;
	return 0;
}

