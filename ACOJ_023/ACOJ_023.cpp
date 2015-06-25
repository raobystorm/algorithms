// ACOJ_023.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void task1(){

	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.size(); i++){
		res += s[i] - '0';
	}
	cout << res << endl;
}

int main()
{
	task1();
	return 0;
}

