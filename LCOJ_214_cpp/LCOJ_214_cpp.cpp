// LCOJ_214_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int min(const int& a, const int& b){ return a > b ? b : a; }
	int max(const int& a, const int& b){ return a < b ? b : a; }
	// Using manacher to guarantee the performance
	string manacher(string& s, vector<int>& p){
	
		string ss(s.size() * 2 + 2, '#');
		ss[0] = '$';
		int i = 0, j = 2, mx = 0, id = 0;
		for (; i < s.size(); i++, j += 2)
			ss[j] = s[i];

		for (int i = 1; i <= ss.size(); i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (i + p[i] < ss.size() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		return ss;
	}
	
	string shortestPalindrome(string s) {

		if (s.size() < 2) return s;
		vector<int> p(s.size()*2+3, 1);
		string ss = manacher(s, p);

		string res, tmps;
		int idx = 0, end = 0, len = 0, tmp, start;
		bool even = false;
		for (int i = 2; i < p.size()-1; i++){

			if (p[i] - 1 > len){

				end = i > (p.size() - 2)/2;
				// check if this palindrome substr could reach the head or tail
				if (end && (i-2)/2+(p[i]-1)/2 >= s.size()-1){

					len = p[i] - 1;
					idx = (i - 2) / 2;
					even = ss[i] == '#';
				}
				else if (!end && (p[i]-1)/2 >= (i-1)/2){

					len = p[i] - 1;
					idx = (i - 2) / 2;
					even = ss[i] == '#';
				}
			}
		}

		end = idx >= s.size() / 2;
		// consider the situation seprately
		if (even){
			if (end) { tmps = s.substr(0, 2 * idx - s.size() + 2); reverse(tmps.begin(), tmps.end()); res = s + tmps; }
			else { tmps = s.substr(2 * idx + 2); reverse(tmps.begin(), tmps.end()); res = tmps + s; }
		}
		else{

			if (end){ tmps = s.substr(0, 2 * idx - s.size() + 1); reverse(tmps.begin(), tmps.end()); res = s + tmps; }
			else{ tmps = s.substr(idx * 2 + 1); reverse(tmps.begin(), tmps.end()); res = tmps + s; }
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = Solution().shortestPalindrome("nllynrwlxijbpxtrtwnxxaetdtwzcbljckitulbfurcxlcnlpbp");
	return 0;
}

