// LCOJ_214_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int min(const int& a, const int& b){ return a > b ? b : a; }
	int max(const int& a, const int& b){ return a < b ? b : a; }
	bool repeated(string& s){
		unordered_set<char> set;
		for (auto c : s){
			if (set.find(c) == set.end()) set.insert(c);
			else return true;
		}
		return false;
	}
	string shortestPalindrome(string s) {

		if (!repeated(s)){
			string res = s;
			reverse(res.begin(), res.end());
			res = res.substr(0, res.size() - 1);
			res += s;
			return res;
		}

		string ss(s.size() * 2 + 2, '#'), res;
		ss[0] = '$';
		int i = 0, j = 2, len;
		for (; i < s.size(); i++, j += 2)
			ss[j] = s[i];
		// Search every pos for maximum palindrome already exists
		int mx = 0, id = 0, minLength = 999999, idx = 0;
		vector<int> p(ss.size() + 1, 0);
		for (int i = 1; i <= ss.size(); i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (i + p[i] < ss.size() && i - p[i] >= 0 && ss[i + p[i]] == ss[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
		}
		// minLength is the minimum length for adding chars to become a palindrome
		for (int i = 0; i < p.size(); i++){
			if (minLength > (max(i, p.size() - 1 - i) - p[i])){
				minLength = (max(i, p.size() - 1 - i) - p[i]);
				idx = i;
			}
		}
		// calc the size of the result string
		len = idx > (p.size() / 2) ? idx : p.size() - idx;
		len /= 2;

		if (idx < p.size() / 2){
			res = string(len, '#');
			j = 0;
			for (int i = idx; i < p.size(); i++){
				if (ss[i] != '#' && ss[i] != '$') {
					res[j] = ss[i];
					j++;
				}
			}

			string ans = res;
			if (ans[ans.size() - 1] == '\0') ans = ans.substr(0, ans.size() - 1);
			reverse(ans.begin(), ans.end());
			if (ss[idx] != '#') ans = ans.substr(0, ans.size()-1);
			ans += res;
			return ans;
		}
		else{
			res = string(len, '#');
			j = 0;
			for (int i = 0; i <= idx; i++){
				if (ss[i] != '#' && ss[i] != '$') {
					res[j] = ss[i];
					j++;
				}
			}
			string ans = res;
			if (ans[ans.size() - 1] == '\0') ans = ans.substr(0, ans.size() - 1);
			reverse(ans.begin(), ans.end());
			if (ss[idx] != '#') ans = ans.substr(1, ans.size() - 1);
			res += ans;
			return res;
		}
		return "";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = Solution().shortestPalindrome("cdabbadc");
	return 0;
}

