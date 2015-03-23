// TestData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

int max(int& a, int& b){

	return a > b ? a : b;
}

int findSubarray(string *s){

	int res = (*s)[0] - '0', fuck = 0;
	for (int i = 1; i < (*s).size(); i++){

		fuck = ((*s)[i] - '0') && ((*s)[i - 1] - '0');
		res += fuck;
	}
	return res;
}

int main()
{
	
	string s = "10111110001100101011111100110100010101010";

	int res = findSubarray(&s);

	return 0;
}

