// LCOJ_5_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int min(const int& a, const int& b){ return a > b ? b : a; }
	string longestPalindrome(string s) {

		string ss(s.size() * 2 + 2, '#'), res;
		ss[0] = '$';
		int i = 0, j = 2;
		for (; i < s.size(); i++, j += 2)
			ss[j] = s[i];

		int mx = 0, id = 0, max = 0, idx = 0;
		vector<int> p(ss.size() + 1, 0);
		for (int i = 1; i <= ss.size(); i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (i + p[i] < ss.size() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		
		for (int i = 0; i < p.size(); i++)
			if (p[i] > max) { max = p[i]; idx = i; }

		res = string(--max, '0'); j = 0;
		for (int i = idx - max; i < idx + max; i++)
			if (ss[i] != '$' && ss[i] != '#') {
				res[j] = ss[i];
				j++;
			}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = Solution().longestPalindrome("aaaabaa");
	return 0;
}

