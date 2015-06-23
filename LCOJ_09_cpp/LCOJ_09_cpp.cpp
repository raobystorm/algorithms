// LCOJ_09_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:

	bool isPalindrome(int x) {

		stringstream ss;
		string s;

		ss << x;
		ss >> s;
		for (int i = 0; i < s.size() / 2; i++)
			if (s[i] != s[s.size() - i - 1]) return false;
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 123;
	bool res = Solution().isPalindrome(x);
	return 0;
}

