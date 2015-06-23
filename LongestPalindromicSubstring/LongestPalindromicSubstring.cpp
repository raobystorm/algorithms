// LongestPalindromicSubstring.cpp : Defines the entry point for the console application.
// Several solutions to the longest palindrom substring problems

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int min(const int& a, const int& b){
	return a > b ? b : a;
}

inline bool isPalindrom(string& s){
	for (int i = 0; i < s.size()/2; i++){
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int BruteSearch(string& s){
	// O(n^3) brute search
	int res = 0;
	for (int i = 2; i <= s.size(); i++){
		// i is the length of the substr
		for (int j = 0; j <= s.size() - i; j++){
			// j is the start location of the substr
			if (isPalindrom(s.substr(j, i))){
				res = i>res ? i : res;
			}
		}
	}
	return res;
}

int DynamicProgramming(string& s){

	// dp[j][i] is whether substr[j...i] a palindrom substr
	// O(n^2) time & space
	vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), true));
	int count = 0;
	for (int i = 0; i < s.size(); i++)
		for (int j = i; j >= 0; j--){
			// state transfer of dp
			if (j == i) dp[j][i] = true;
			else if (j == i - 1) dp[j][i] = (s[j] == s[i]);
			else if (i) dp[j][i] = (dp[j + 1][i - 1] && (s[j] == s[i]));
		}

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < i; j++)
			if (dp[j][i]) count = i - j + 1 > count ? i - j + 1 : count;

	return count;
}

int Stretch(string& s){
	// O(n^2) time
	int left, right, count = 0, tmp = 0;
	for (int i = 1; i < s.size(); i++){
		// for every elem, assume they are center of the palidrom substr
		// try to search their neighbours if this assumption is true
		left = i - 1;
		right = i;
		tmp = 0;
		// the situation of even length
		while (left >= 0 && right < s.size() && s[left] == s[right]){

			tmp = right - left + 1;
			right++;
			left--;
		}
		count = count > tmp ? count : tmp;

		left = i - 1;
		right = i + 1;
		tmp = 0;
		// the length is odd
		while (left >= 0 && right < s.size() && s[left] == s[right]){

			tmp = right - left + 1;
			right++;
			left--;
		}
		count = count > tmp ? count : tmp;
	}
	return count;
}

int Manacher(string& s){
	// Most mysterous algo for this problem. O(n)
	// Add padding chars to unify the even and odd strs
	string ss(s.size()*2+2, '#');
	ss[0] = '$';
	int i = 0, j = 2;
	for (; i < s.size(); i++, j += 2)
		ss[j] = s[i];

	int mx = 0, id = 0, max = 0;
	vector<int> p(ss.size()+1, 0);
	// p[i]: length of the longest palindrom substrs that centered at ss[i].
	// id : center location of the longest palindrom substr
	// mx : border of the longest palindrom substr i.e. mx = id + p[id]
	// 2 * id - i: the symmetry pos of i centering id.
	// if mx > i, then p[i] = min(p[2 * id -i ], mx - i)
	for (int i = 1; i <= ss.size(); i++) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (i+p[i] < ss.size() && i-p[i] >=0 && ss[i + p[i]] == ss[i - p[i]]) p[i]++;
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
	}

	for (auto i : p) if (i > max) max = i;
	return max-1;
}

int main()
{
	int n = 0, ans = 0; 
	cin >> n;
	string s;
	while (n--){
		cin >> s;
		cout << Manacher(s) << endl;
	}
	return 0;
}

