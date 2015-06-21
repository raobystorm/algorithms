// KMP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void countPrefix(string& s, vector<int>& prefix){

	int i = 1, j = 0, count = 0;
	for (; i < s.size(); i++){
		j = i;
		while (j > 0){
			j = prefix[j];
			if (s[i] == s[j]){
				prefix[i + 1] = j + 1;
				break;
			}
		}
	}
}

int KMPSearch(string& str, string& patt){
	
	vector<int> prefix(patt.size()+1, 0);

	countPrefix(patt, prefix);

	int count = 0;
	bool match;

	for (int i = 0, j = 0; i < str.size(); i++){
		if (j < str.size() && str[i] == patt[j]) j++;
		else{
			while (j > 0){
				j = prefix[j];
				if (str[i] == patt[j]){
					j++;
					break;
				}
			}
		}
		if (j == patt.size()) count++;
	}

	return count;
}

int main()
{
	string s, patt;
	int n;
	cin >> n;

	while (n--){

		cin >> patt >> s;

		cout << KMPSearch(s, patt) << endl; 
	}

	return 0;
}