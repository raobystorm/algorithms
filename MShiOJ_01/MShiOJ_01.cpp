// MShiOJ_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
#include <iostream>
#include <string>
using namespace std;

// check if we can print b after print a
bool canPrint(char c1, char c2){

	int a = c1 - '0', b = c2 - '0';

	if (a == b) return true;
	if (a == 1) return true;
	if (a == 2) {
	
		if (b == 1 || b == 4 || b == 7) return false;
		else return true;
	}
	if (a == 3){
		if (b == 3 || b == 6 || b == 9) return true;
		else return false;
	}
	if (a == 4){
		if (b == 1 || b == 2 || b == 3) return false;
		else return true;
	}
	if (a == 5){
		if (b == 5 || b == 6 || b == 8 || b == 9 || b == 0)return true;
		else return false;
	}
	if (a == 6){
		if (b == 6 || b == 9)return true;
		else return false;
	}
	if (a == 7){
		if (b == 7 || b == 8 || b == 9 || b == 0) return true;
		else return false;
	}
	if (a == 8){
		if (b == 8 || b == 9 || b == 0)return true;
		else return false;
	}
	if (a == 9){
		return (b == 9);
	}
	if (a == 0){
		return (b == 0);
	}
}

bool numCanPrint(string* s){

	if (s->size() < 2) return true;
	for (int i = 1; i < s->size(); i++){

		if (!canPrint((*s)[i - 1], (*s)[i])) return false;
	}
	return true;
}

int main(){

	int a[1000] = { 0 };
	string s;
	for (int i = 0; i < 1000; i++){
		s = "";
 		s = std::to_string(i);
		if (numCanPrint(&s)) a[i] = 1;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++){

		int k;
		cin >> k;
		if (a[k]) cout << k << endl;
		else{
			int j = k;
			while (j >= 0){
				if (a[j]) { cout << j << endl; break; }
				j--;
			}
		}
	}

}*/


#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

int Fib[7] = { 1, 2, 3, 5, 8, 13, 21};
// a function to check if input n is in Fib
bool isFib(int n){
	for (int i = 0; i < 7; i++)
		if (n == Fib[i]) return true;
	return false;
}

// a function to check a list of character contains non-lucky number or not
bool isLucky(int a[]){

	int sum = 0;
	for (int i = 0; i < 26; i++){
		if (a[i]) sum++;
	}
	return (isFib(sum));
}

// a function to count nums of chars in a string
void countStr(string s, int a[]){

	for (int i = 0; i < s.length(); i++){

		a[s[i] - 'a']++;
	}
}

void reset(int a[]){

	for (int i = 0; i < 26; i++)
		a[i] = 0;
}

int main()
{
	string s, ss;
	cin >> s;
	if (s.size() == 1) { cout << s << endl; }
	if (s.size() == 0) { return 0; }

	int a[26];
	unordered_set<string> uset;
	vector<string> vv;
	for (int i = 0; i < s.length(); i++){
		for (int j = i; j < s.length(); j++){
			if (i == 0 && j == s.length() - 1) continue;
			reset(a);
			string ss = s.substr(i, j-i+1);
			countStr(ss, a);
			if (!isLucky(a)) continue;
			if (uset.find(ss) == uset.end()){
				uset.insert(ss);
				vv.push_back(ss);
			}
		}
	}

	sort(vv.begin(), vv.end());

	for (int i = 0; i < vv.size(); i++){
		cout << vv[i] << endl;
	}

	system("pause");
	return 0;
}