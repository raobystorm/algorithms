// LCOJ_168.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:

	void reverseStr(string& s){
	
		if (!s.size()) return;
		char tmp;
		for (int i = s.size() - 1; i > (s.size() - 1) / 2 ; i--){
		
			tmp = s[s.size() - 1 - i];
			s[s.size() - 1 - i] = s[i];
			s[i] = tmp;
		}
	}

	string convertToTitle(int n) {

		int num = n;
		string res = "";
		for (; num > 0; num /= 26){
		
			res += ((--num) % 26 + 'A');
		}
		
		reverseStr(res);

		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string res = Solution().convertToTitle(27);
	return 0;
}

