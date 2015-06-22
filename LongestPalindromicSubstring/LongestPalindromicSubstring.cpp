// LongestPalindromicSubstring.cpp : Defines the entry point for the console application.
// Several solutions to the longest palindrom substring problems

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool isPalindrom(string& s){
	for (int i = 0; i < s.size()/2; i++){
		if (s[i] != s[s.size() - 1 - i]) return false;
	}
	return true;
}

int BruteSearch(string& s){

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

int main()
{
	int n = 0, ans = 0; 
	cin >> n;
	string s;
	while (n--){
		cin >> s;
		cout << DynamicProgramming(s) << endl;
	}
	return 0;
}

