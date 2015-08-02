// LCOJ_242_anagram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {

		if (s.size() != t.size()) return false;
		vector<char> alp(26, 0);
		for (int i = 0; i < s.size(); i++)
			alp[s[i] - 'a']++;

		for (int i = 0; i < t.size(); i++)
			alp[t[i] - 'a']--;

		for (int i = 0; i < alp.size(); i++)
			if (alp[i] != 0) return false;

		return true;
	}
};

int main()
{
	string s = "rat", t = "car";
	bool res = Solution().isAnagram(s, t);
	return 0;
}

